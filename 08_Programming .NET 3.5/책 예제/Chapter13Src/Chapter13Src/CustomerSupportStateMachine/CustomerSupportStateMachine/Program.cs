using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Workflow.Runtime;
using System.Workflow.Runtime.Hosting;
using System.Workflow.Activities;
using System.Workflow.Runtime.Tracking;
using System.Workflow.Runtime.Configuration;
using System.Configuration;

namespace CustomerSupportStateMachine
{
    class Program
    {
        static void Main(string[] args)
        {
            using (WorkflowRuntime workflowRuntime = new WorkflowRuntime())
            {
                AutoResetEvent waitHandle = new AutoResetEvent(false);
                workflowRuntime.WorkflowCompleted += delegate(object sender, WorkflowCompletedEventArgs e) { waitHandle.Set(); };
                workflowRuntime.WorkflowTerminated += delegate(object sender, WorkflowTerminatedEventArgs e)
                {
                    Console.WriteLine(e.Exception.Message);
                    waitHandle.Set();
                };

                // Add Persistence and Tracking
                SqlWorkflowPersistenceService persistenceService;
                persistenceService = new SqlWorkflowPersistenceService(
                            ConfigurationManager.
                            ConnectionStrings["PersistentDataStore"].
                            ConnectionString, true, TimeSpan.MaxValue, TimeSpan.MinValue);
                workflowRuntime.AddService(persistenceService);

                SqlTrackingService trackingService;
                trackingService = new SqlTrackingService(
                            ConfigurationManager.
                            ConnectionStrings["PersistentDataStore"].
                            ConnectionString);
                trackingService.UseDefaultProfile = true;
                workflowRuntime.AddService(trackingService);

                // Set up the data exchange
                ExternalDataExchangeService dataExchange;
                dataExchange = new ExternalDataExchangeService();
                workflowRuntime.AddService(dataExchange);

                // Instatiate the local communication service
                CustomerCallService customerCallService = new CustomerCallService();
                dataExchange.AddService(customerCallService);

                // Create a new workflow instance
                WorkflowInstance instance = workflowRuntime.CreateWorkflow(typeof(CustomerService));
                instance.Start();

                // Create a new Call
                Call newCall = new Call();
                newCall.CallersFirstName = "Alex";
                newCall.Product = "Widget Number Nine";

                // Change the state using the service and events
                customerCallService.ReceiveCall(instance.InstanceId, newCall);
                customerCallService.SendCallToPhoneResolution(instance.InstanceId, newCall);
                customerCallService.AssignCallToSupportPerson(instance.InstanceId, newCall);
                
                //Get a look at where we have wound up
                PrintStateMachineState(workflowRuntime, instance.InstanceId);

                // Change the state one last time
                customerCallService.ResolveCall(instance.InstanceId, newCall);

                // Print the history of our instance
                PrintHistory(workflowRuntime, instance.InstanceId);


                waitHandle.WaitOne();

                // Keep the console open until key strokes are entered so that you can see what we did...
                Console.ReadLine();
            }
        }


        private static void PrintStateMachineState(WorkflowRuntime runtime, Guid instanceID)
        {
            StateMachineWorkflowInstance myInstance =
               new StateMachineWorkflowInstance(runtime, instanceID);

            Console.WriteLine("Workflow GUID: {0}", instanceID);
            Console.WriteLine("Current State: {0}", myInstance.CurrentStateName);
            Console.WriteLine("Transition States Available: {0}",
               myInstance.PossibleStateTransitions.Count);
            foreach (string transition in myInstance.PossibleStateTransitions)
            {
                Console.WriteLine("Transition to -> {0}", transition);
            }
            Console.WriteLine("\n\n------------------\n");
        }

        private static void PrintHistory(WorkflowRuntime runtime,Guid instanceID)
        {
            StateMachineWorkflowInstance instance = new StateMachineWorkflowInstance(runtime, instanceID);
            Console.WriteLine("History of State Machine instance's workflow: (From Last to First)");
            foreach (string history in instance.StateHistory)
            {
                Console.WriteLine("\t{0}", history);
            }
            Console.WriteLine("\n\n------------------\n");
        }

    }
}
