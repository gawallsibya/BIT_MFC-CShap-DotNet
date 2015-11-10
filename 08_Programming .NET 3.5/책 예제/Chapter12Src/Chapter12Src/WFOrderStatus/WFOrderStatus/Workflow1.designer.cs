using System;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Collections;
using System.Drawing;
using System.Reflection;
using System.Workflow.ComponentModel.Compiler;
using System.Workflow.ComponentModel.Serialization;
using System.Workflow.ComponentModel;
using System.Workflow.ComponentModel.Design;
using System.Workflow.Runtime;
using System.Workflow.Activities;
using System.Workflow.Activities.Rules;

namespace WFOrderStatus
{
	partial class Workflow1
	{
		#region Designer generated code
		
		/// <summary> 
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor.
		/// </summary>
        [System.Diagnostics.DebuggerNonUserCode]
		private void InitializeComponent()
		{
            this.CanModifyActivities = true;
            System.Workflow.Activities.Rules.RuleConditionReference ruleconditionreference1 = new System.Workflow.Activities.Rules.RuleConditionReference();
            System.Workflow.Activities.Rules.RuleConditionReference ruleconditionreference2 = new System.Workflow.Activities.Rules.RuleConditionReference();
            this.codeActivity3 = new System.Workflow.Activities.CodeActivity();
            this.codeActivity2 = new System.Workflow.Activities.CodeActivity();
            this.ifElseBranchActivity2 = new System.Workflow.Activities.IfElseBranchActivity();
            this.ifElseBranchActivity1 = new System.Workflow.Activities.IfElseBranchActivity();
            this.ifElseActivity1 = new System.Workflow.Activities.IfElseActivity();
            this.delayActivity1 = new System.Workflow.Activities.DelayActivity();
            this.whileActivity1 = new System.Workflow.Activities.WhileActivity();
            this.codeActivity1 = new System.Workflow.Activities.CodeActivity();
            // 
            // codeActivity3
            // 
            this.codeActivity3.Name = "codeActivity3";
            this.codeActivity3.ExecuteCode += new System.EventHandler(this.codeActivity3_ExecuteCode);
            // 
            // codeActivity2
            // 
            this.codeActivity2.Name = "codeActivity2";
            this.codeActivity2.ExecuteCode += new System.EventHandler(this.codeActivity2_ExecuteCode);
            // 
            // ifElseBranchActivity2
            // 
            this.ifElseBranchActivity2.Activities.Add(this.codeActivity3);
            this.ifElseBranchActivity2.Name = "ifElseBranchActivity2";
            // 
            // ifElseBranchActivity1
            // 
            this.ifElseBranchActivity1.Activities.Add(this.codeActivity2);
            ruleconditionreference1.ConditionName = "Condition1";
            this.ifElseBranchActivity1.Condition = ruleconditionreference1;
            this.ifElseBranchActivity1.Name = "ifElseBranchActivity1";
            // 
            // ifElseActivity1
            // 
            this.ifElseActivity1.Activities.Add(this.ifElseBranchActivity1);
            this.ifElseActivity1.Activities.Add(this.ifElseBranchActivity2);
            this.ifElseActivity1.Name = "ifElseActivity1";
            // 
            // delayActivity1
            // 
            this.delayActivity1.Name = "delayActivity1";
            this.delayActivity1.TimeoutDuration = System.TimeSpan.Parse("00:00:05");
            // 
            // whileActivity1
            // 
            this.whileActivity1.Activities.Add(this.ifElseActivity1);
            ruleconditionreference2.ConditionName = "Condition2";
            this.whileActivity1.Condition = ruleconditionreference2;
            this.whileActivity1.Name = "whileActivity1";
            // 
            // codeActivity1
            // 
            this.codeActivity1.Name = "codeActivity1";
            this.codeActivity1.ExecuteCode += new System.EventHandler(this.codeActivity1_ExecuteCode);
            // 
            // Workflow1
            // 
            this.Activities.Add(this.codeActivity1);
            this.Activities.Add(this.whileActivity1);
            this.Activities.Add(this.delayActivity1);
            this.Name = "Workflow1";
            this.CanModifyActivities = false;

		}

		#endregion

        private DelayActivity delayActivity1;
        private CodeActivity codeActivity3;
        private CodeActivity codeActivity2;
        private IfElseBranchActivity ifElseBranchActivity2;
        private IfElseBranchActivity ifElseBranchActivity1;
        private IfElseActivity ifElseActivity1;
        private WhileActivity whileActivity1;
        private CodeActivity codeActivity1;










    }
}
