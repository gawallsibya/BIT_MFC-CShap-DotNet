namespace NikeSoftChat
{
    partial class PleaseWaitDialog
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
          this.progressBar1 = new System.Windows.Forms.ProgressBar();
          this.label1 = new System.Windows.Forms.Label();
          this.pnlConnecting = new System.Windows.Forms.Panel();
          this.pnlError = new System.Windows.Forms.Panel();
          this.btnOK = new System.Windows.Forms.Button();
          this.lblErrorMessage = new System.Windows.Forms.Label();
          this.pnlConnecting.SuspendLayout();
          this.pnlError.SuspendLayout();
          this.SuspendLayout();
          // 
          // progressBar1
          // 
          this.progressBar1.Location = new System.Drawing.Point(35, 38);
          this.progressBar1.Name = "progressBar1";
          this.progressBar1.Size = new System.Drawing.Size(231, 18);
          this.progressBar1.Style = System.Windows.Forms.ProgressBarStyle.Marquee;
          this.progressBar1.TabIndex = 0;
          // 
          // label1
          // 
          this.label1.AutoSize = true;
          this.label1.Location = new System.Drawing.Point(31, 11);
          this.label1.Name = "label1";
          this.label1.Size = new System.Drawing.Size(133, 12);
          this.label1.TabIndex = 1;
          this.label1.Text = "서버로 연결중입니다... ";
          // 
          // pnlConnecting
          // 
          this.pnlConnecting.Controls.Add(this.label1);
          this.pnlConnecting.Controls.Add(this.progressBar1);
          this.pnlConnecting.Location = new System.Drawing.Point(0, 0);
          this.pnlConnecting.Name = "pnlConnecting";
          this.pnlConnecting.Size = new System.Drawing.Size(314, 87);
          this.pnlConnecting.TabIndex = 3;
          // 
          // pnlError
          // 
          this.pnlError.Controls.Add(this.pnlConnecting);
          this.pnlError.Controls.Add(this.btnOK);
          this.pnlError.Controls.Add(this.lblErrorMessage);
          this.pnlError.Location = new System.Drawing.Point(13, 10);
          this.pnlError.Name = "pnlError";
          this.pnlError.Size = new System.Drawing.Size(314, 87);
          this.pnlError.TabIndex = 4;
          // 
          // btnOK
          // 
          this.btnOK.Location = new System.Drawing.Point(208, 54);
          this.btnOK.Name = "btnOK";
          this.btnOK.Size = new System.Drawing.Size(87, 21);
          this.btnOK.TabIndex = 1;
          this.btnOK.Text = "OK";
          this.btnOK.UseVisualStyleBackColor = true;
          this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
          // 
          // lblErrorMessage
          // 
          this.lblErrorMessage.AutoSize = true;
          this.lblErrorMessage.Location = new System.Drawing.Point(31, 13);
          this.lblErrorMessage.Name = "lblErrorMessage";
          this.lblErrorMessage.Size = new System.Drawing.Size(175, 12);
          this.lblErrorMessage.TabIndex = 0;
          this.lblErrorMessage.Text = "Error: Cannot connect to chat!";
          // 
          // PleaseWaitDialog
          // 
          this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(341, 99);
          this.ControlBox = false;
          this.Controls.Add(this.pnlError);
          this.MaximizeBox = false;
          this.MinimizeBox = false;
          this.Name = "PleaseWaitDialog";
          this.ShowInTaskbar = false;
          this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
          this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
          this.Text = "접속중...";
          this.pnlConnecting.ResumeLayout(false);
          this.pnlConnecting.PerformLayout();
          this.pnlError.ResumeLayout(false);
          this.pnlError.PerformLayout();
          this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel pnlConnecting;
        private System.Windows.Forms.Panel pnlError;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Label lblErrorMessage;
    }
}