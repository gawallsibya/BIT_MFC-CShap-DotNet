using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Workflow.Activities;

namespace CustomerSupportStateMachine
{

    [ExternalDataExchange]
    public interface ICustomerCallService
    {
        event EventHandler<CallStateChangedEventArgs> CallRecieved;
        event EventHandler<CallStateChangedEventArgs> CallSentToPhoneResolution;
        event EventHandler<CallStateChangedEventArgs> CallAssignedToSupportPerson;
        event EventHandler<CallStateChangedEventArgs> CallEndedMoreInformationRequired;
        event EventHandler<CallStateChangedEventArgs> CallResolved;
    }

    [Serializable]
    public class Call
    {
        public string CallersFirstName { get; set; }
        public string Product { get; set; }
        public string AssignedTo { get; set; }
    }

    [Serializable]
    public class CallStateChangedEventArgs : ExternalDataEventArgs
    {
        public CallStateChangedEventArgs(Guid guid, Call aCall)
            : base(guid)
        {
            _call = aCall;
            WaitForIdle = true;
        }

        private Call _call;

        public Call Call 
        {
            get { return _call; }
            set { _call = value; }
        }



    }

    public class CustomerCallService : ICustomerCallService
    {
        public event EventHandler<CallStateChangedEventArgs> CallRecieved;
        public event EventHandler<CallStateChangedEventArgs> CallSentToPhoneResolution;
        public event EventHandler<CallStateChangedEventArgs> CallAssignedToSupportPerson;
        public event EventHandler<CallStateChangedEventArgs> CallEndedMoreInformationRequired;
        public event EventHandler<CallStateChangedEventArgs> CallResolved;

        public void ReceiveCall(Guid guid, Call aCall)
        {
            if (CallRecieved != null)
                CallRecieved(null, new CallStateChangedEventArgs(guid, aCall));
        }

        public void SendCallToPhoneResolution(Guid guid, Call aCall)
        {
            if (CallSentToPhoneResolution != null)
                CallSentToPhoneResolution(null, new CallStateChangedEventArgs(guid, aCall));
        }

        public void AssignCallToSupportPerson(Guid guid, Call aCall)
        {
            if (CallAssignedToSupportPerson != null)
                CallAssignedToSupportPerson(null, new CallStateChangedEventArgs(guid, aCall));
        }

        public void EndCallMoreInformationRequired(Guid guid, Call aCall)
        {
            if (CallEndedMoreInformationRequired != null)
                CallEndedMoreInformationRequired(null, new CallStateChangedEventArgs(guid, aCall));
        }

        public void ResolveCall(Guid guid, Call aCall)
        {
            if (CallResolved != null)
                CallResolved(null, new CallStateChangedEventArgs(guid, aCall));
        }
    }


}
