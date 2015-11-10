namespace WCFClient_WinForm
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnCallHTTP = new System.Windows.Forms.Button();
            this.txtStatus = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnCallTCP = new System.Windows.Forms.Button();
            this.btnCallNAMEDPIPE = new System.Windows.Forms.Button();
            this.btnCallManual = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.btnCallHttpDual = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnCallHTTP
            // 
            this.btnCallHTTP.Enabled = false;
            this.btnCallHTTP.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
            this.btnCallHTTP.ForeColor = System.Drawing.Color.Blue;
            this.btnCallHTTP.Location = new System.Drawing.Point(15, 12);
            this.btnCallHTTP.Name = "btnCallHTTP";
            this.btnCallHTTP.Size = new System.Drawing.Size(226, 23);
            this.btnCallHTTP.TabIndex = 0;
            this.btnCallHTTP.Text = "wsHttpBinding 으로 호출";
            this.btnCallHTTP.UseVisualStyleBackColor = true;
            this.btnCallHTTP.Click += new System.EventHandler(this.btnCallHTTP_Click);
            // 
            // txtStatus
            // 
            this.txtStatus.Font = new System.Drawing.Font("Tahoma", 8.25F);
            this.txtStatus.Location = new System.Drawing.Point(12, 160);
            this.txtStatus.Multiline = true;
            this.txtStatus.Name = "txtStatus";
            this.txtStatus.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtStatus.Size = new System.Drawing.Size(438, 282);
            this.txtStatus.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Tahoma", 8.25F);
            this.label1.Location = new System.Drawing.Point(12, 144);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "WCF Call Status";
            // 
            // btnCallTCP
            // 
            this.btnCallTCP.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
            this.btnCallTCP.ForeColor = System.Drawing.Color.Red;
            this.btnCallTCP.Location = new System.Drawing.Point(15, 70);
            this.btnCallTCP.Name = "btnCallTCP";
            this.btnCallTCP.Size = new System.Drawing.Size(226, 23);
            this.btnCallTCP.TabIndex = 4;
            this.btnCallTCP.Text = "netTcpBinding 으로 호출";
            this.btnCallTCP.UseVisualStyleBackColor = true;
            this.btnCallTCP.Click += new System.EventHandler(this.btnCallTCP_Click);
            // 
            // btnCallNAMEDPIPE
            // 
            this.btnCallNAMEDPIPE.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
            this.btnCallNAMEDPIPE.ForeColor = System.Drawing.Color.Green;
            this.btnCallNAMEDPIPE.Location = new System.Drawing.Point(15, 99);
            this.btnCallNAMEDPIPE.Name = "btnCallNAMEDPIPE";
            this.btnCallNAMEDPIPE.Size = new System.Drawing.Size(226, 23);
            this.btnCallNAMEDPIPE.TabIndex = 5;
            this.btnCallNAMEDPIPE.Text = "netNamedPipeBinding  으로 호출";
            this.btnCallNAMEDPIPE.UseVisualStyleBackColor = true;
            this.btnCallNAMEDPIPE.Click += new System.EventHandler(this.btnCallNAMEDPIPE_Click);
            // 
            // btnCallManual
            // 
            this.btnCallManual.Enabled = false;
            this.btnCallManual.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
            this.btnCallManual.ForeColor = System.Drawing.Color.Black;
            this.btnCallManual.Location = new System.Drawing.Point(265, 41);
            this.btnCallManual.Name = "btnCallManual";
            this.btnCallManual.Size = new System.Drawing.Size(185, 23);
            this.btnCallManual.TabIndex = 6;
            this.btnCallManual.Text = "구성없이 코드로만 호출";
            this.btnCallManual.UseVisualStyleBackColor = true;
            this.btnCallManual.Click += new System.EventHandler(this.btnCallManual_Click);
            // 
            // label2
            // 
            this.label2.Font = new System.Drawing.Font("Tahoma", 8.25F);
            this.label2.Location = new System.Drawing.Point(262, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(190, 26);
            this.label2.TabIndex = 7;
            this.label2.Text = "구성파일에서 ServiceModel 섹션을 주석처리한 후 실행";
            // 
            // btnCallHttpDual
            // 
            this.btnCallHttpDual.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
            this.btnCallHttpDual.ForeColor = System.Drawing.Color.Blue;
            this.btnCallHttpDual.Location = new System.Drawing.Point(15, 41);
            this.btnCallHttpDual.Name = "btnCallHttpDual";
            this.btnCallHttpDual.Size = new System.Drawing.Size(226, 23);
            this.btnCallHttpDual.TabIndex = 8;
            this.btnCallHttpDual.Text = "wsDualHttpBinding(Async)로 호출";
            this.btnCallHttpDual.UseVisualStyleBackColor = true;
            this.btnCallHttpDual.Click += new System.EventHandler(this.btnCallHttpDual_Click);
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
            this.button1.ForeColor = System.Drawing.Color.Black;
            this.button1.Location = new System.Drawing.Point(265, 131);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(185, 23);
            this.button1.TabIndex = 9;
            this.button1.Text = "Clear!";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(462, 454);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnCallHttpDual);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btnCallManual);
            this.Controls.Add(this.btnCallNAMEDPIPE);
            this.Controls.Add(this.btnCallTCP);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtStatus);
            this.Controls.Add(this.btnCallHTTP);
            this.Name = "Form1";
            this.Text = "WCF Client Windows Form";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnCallHTTP;
        internal System.Windows.Forms.TextBox txtStatus;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnCallTCP;
        private System.Windows.Forms.Button btnCallNAMEDPIPE;
        private System.Windows.Forms.Button btnCallManual;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnCallHttpDual;
        private System.Windows.Forms.Button button1;
    }
}

