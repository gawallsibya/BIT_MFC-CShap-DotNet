
// Copyright (C) 2006 by Nikola Paljetak

namespace NikeSoftChat
{
    partial class NickDialog
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
          this.txtNick = new System.Windows.Forms.TextBox();
          this.label1 = new System.Windows.Forms.Label();
          this.btnOK = new System.Windows.Forms.Button();
          this.SuspendLayout();
          // 
          // txtNick
          // 
          this.txtNick.Location = new System.Drawing.Point(92, 40);
          this.txtNick.Name = "txtNick";
          this.txtNick.Size = new System.Drawing.Size(130, 21);
          this.txtNick.TabIndex = 0;
          this.txtNick.TextChanged += new System.EventHandler(this.txtNick_TextChanged);
          // 
          // label1
          // 
          this.label1.AutoSize = true;
          this.label1.Location = new System.Drawing.Point(14, 42);
          this.label1.Name = "label1";
          this.label1.Size = new System.Drawing.Size(73, 12);
          this.label1.TabIndex = 1;
          this.label1.Text = "����� �̸�:";
          // 
          // btnOK
          // 
          this.btnOK.DialogResult = System.Windows.Forms.DialogResult.OK;
          this.btnOK.Enabled = false;
          this.btnOK.Location = new System.Drawing.Point(230, 40);
          this.btnOK.Name = "btnOK";
          this.btnOK.Size = new System.Drawing.Size(87, 21);
          this.btnOK.TabIndex = 2;
          this.btnOK.Text = "����";
          this.btnOK.UseVisualStyleBackColor = true;
          // 
          // NickDialog
          // 
          this.AcceptButton = this.btnOK;
          this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(365, 102);
          this.ControlBox = false;
          this.Controls.Add(this.btnOK);
          this.Controls.Add(this.label1);
          this.Controls.Add(this.txtNick);
          this.MinimizeBox = false;
          this.Name = "NickDialog";
          this.ShowIcon = false;
          this.ShowInTaskbar = false;
          this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
          this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
          this.Text = "����� �����Է�";
          this.ResumeLayout(false);
          this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.TextBox txtNick;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnOK;
    }
}