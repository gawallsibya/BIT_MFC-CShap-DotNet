namespace Chat
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
            this.Text_msg = new System.Windows.Forms.TextBox();
            this.Send = new System.Windows.Forms.Button();
            this.Text_Chat = new System.Windows.Forms.TextBox();
            this.Text_name = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.Accept = new System.Windows.Forms.Button();
            this.Client_List = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // Text_msg
            // 
            this.Text_msg.Location = new System.Drawing.Point(235, 305);
            this.Text_msg.Name = "Text_msg";
            this.Text_msg.Size = new System.Drawing.Size(308, 21);
            this.Text_msg.TabIndex = 1;
            this.Text_msg.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Text_msg_KeyDown);
            // 
            // Send
            // 
            this.Send.Location = new System.Drawing.Point(559, 305);
            this.Send.Name = "Send";
            this.Send.Size = new System.Drawing.Size(75, 23);
            this.Send.TabIndex = 2;
            this.Send.Text = "입력";
            this.Send.UseVisualStyleBackColor = true;
            this.Send.Click += new System.EventHandler(this.Send_Click);
            // 
            // Text_Chat
            // 
            this.Text_Chat.Location = new System.Drawing.Point(150, 12);
            this.Text_Chat.Multiline = true;
            this.Text_Chat.Name = "Text_Chat";
            this.Text_Chat.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.Text_Chat.Size = new System.Drawing.Size(479, 270);
            this.Text_Chat.TabIndex = 3;
            // 
            // Text_name
            // 
            this.Text_name.Location = new System.Drawing.Point(45, 305);
            this.Text_name.Name = "Text_name";
            this.Text_name.Size = new System.Drawing.Size(99, 21);
            this.Text_name.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(10, 308);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 12);
            this.label1.TabIndex = 5;
            this.label1.Text = "이름";
            // 
            // Accept
            // 
            this.Accept.Location = new System.Drawing.Point(150, 306);
            this.Accept.Name = "Accept";
            this.Accept.Size = new System.Drawing.Size(43, 20);
            this.Accept.TabIndex = 6;
            this.Accept.Text = "접속";
            this.Accept.UseVisualStyleBackColor = true;
            this.Accept.Click += new System.EventHandler(this.Accept_Click);
            // 
            // Client_List
            // 
            this.Client_List.FormattingEnabled = true;
            this.Client_List.ItemHeight = 12;
            this.Client_List.Location = new System.Drawing.Point(13, 11);
            this.Client_List.Name = "Client_List";
            this.Client_List.Size = new System.Drawing.Size(121, 268);
            this.Client_List.TabIndex = 7;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(641, 340);
            this.Controls.Add(this.Client_List);
            this.Controls.Add(this.Accept);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Text_name);
            this.Controls.Add(this.Text_Chat);
            this.Controls.Add(this.Send);
            this.Controls.Add(this.Text_msg);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox Text_msg;
        private System.Windows.Forms.Button Send;
        private System.Windows.Forms.TextBox Text_Chat;
        private System.Windows.Forms.TextBox Text_name;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Accept;
        private System.Windows.Forms.ListBox Client_List;
    }
}

