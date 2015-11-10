using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ServiceModel;
using Chat.ServiceReference1;

namespace Chat
{
    public partial class Form1 : Form, IChatCallback
    {
        private IChat Chat;
        private string[] List;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            InstanceContext site = new InstanceContext(this);
            Chat = new ChatClient(site);
        }

        private void Accept_Click(object sender, EventArgs e)
        {
            List = Chat.Join(Text_name.Text);
            if (List != null)
            {
                foreach (string member in List)
                {
                    Client_List.Items.Add(member);
                }
                Accept.Enabled = false;
            }
            else MessageBox.Show("현재 존재하는 이름입니다 다른 이름을 사용하세요");
        }

        private void Send_Click(object sender, EventArgs e)
        {
            Chat.Say(Text_msg.Text);
            Text_msg.Text = "";
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            Chat.Leave();
        }


        private void Text_msg_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.Enter)
            {
                Send_Click(null, null);
            }
        }

        #region 서버에서 온 메세지 (서버->클라이언트)
        public void Receive(string senderName, string message)
        {
            string msg = string.Format("{0} : {1}\r\n",senderName,message);
            Text_Chat.Text += msg;
        }

        public void UserEnter(string name)
        {
            string msg = string.Format(name + "님이 접속했습니다\n");
            Text_Chat.Text += msg;
            Client_List.Items.Add(name);
        }

        public void UserLeave(string name)
        {
            string msg = string.Format(name + "님이 퇴장했습니다\n");
            Text_Chat.Text += msg;
            Client_List.Items.Remove(name);
        }
        #endregion






    }
}
