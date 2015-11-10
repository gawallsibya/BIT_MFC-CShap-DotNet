using System;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Collections;
using System.Drawing;
using System.Linq;
using System.Workflow.ComponentModel.Compiler;
using System.Workflow.ComponentModel.Serialization;
using System.Workflow.ComponentModel;
using System.Workflow.ComponentModel.Design;
using System.Workflow.Runtime;
using System.Workflow.Activities;
using System.Workflow.Activities.Rules;

namespace WFOrderStatus
{
	public sealed partial class Workflow1: SequentialWorkflowActivity
	{
        public String OrderNumber;
        bool keepGoing = true; 

		public Workflow1()
		{
			InitializeComponent();
		}

        private void codeActivity1_ExecuteCode(object sender, EventArgs e)
        {
            Console.WriteLine("Please enter your order tracking number: ");
            OrderNumber = Console.ReadLine();

        }

        private void codeActivity2_ExecuteCode(object sender, EventArgs e)
        {
                Console.WriteLine("Your order: " +OrderNumber + "is being packaged for shipping!");
                keepGoing = false;
        }

        private void codeActivity3_ExecuteCode(object sender, EventArgs e)
        {
            Console.WriteLine("We're Sorry! Your order: " + OrderNumber +" was not found in the system!");
            Console.WriteLine("Please re-enter your order tracking number: ");
            OrderNumber = Console.ReadLine();

        }
	}

}
