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
using _0502_UseCal.ServiceReference1;

//비동기 웹서비스 생성 방법
//웹서비스 참조 구성에서 비동기 장업 허용 체크

namespace _0502_UseCal
{
    public partial class Form1 : Form, ICalCallback
    {
        CalClient client;

        public Form1()
        {
            InitializeComponent();

            //서비스 정보를 기반으로 클라이언트 생성
            InstanceContext site = new InstanceContext(this);
            client = new CalClient(site);
        }

        //서버에서 받은 인터페이스 메서드 구현
        public void Result(float result)
        {
            textBox3.Text = result.ToString();
        }
        #region 더미
        //오류 해결을 위한 더미 메서드=============================================================
        public IAsyncResult BeginResult(float result, AsyncCallback callback, object asyncState)
        {
            throw new NotImplementedException();
        }

        public void EndResult(IAsyncResult result)
        {
        }
        //=========================================================================================
        #endregion

        //동기 방식
        private void button1_Click(object sender, EventArgs e)
        {
        

            switch (comboBox1.Text)
            {
                case "+": client.Add(int.Parse(textBox1.Text), int.Parse(textBox2.Text)); break;
                case "-": client.Sub(int.Parse(textBox1.Text), int.Parse(textBox2.Text)); break;
                case "*": client.Mul(int.Parse(textBox1.Text), int.Parse(textBox2.Text)); break;
                case "/": client.Div(int.Parse(textBox1.Text), int.Parse(textBox2.Text)); break;
            }

            //ICahtCallback 함수 메서드 호출
            client.Clear();
           
        }

        //비동기 방식
        string op;
        private void button2_Click(object sender, EventArgs e)
        {
            
            op = comboBox1.Text;

            switch (op)
            {
                case "+": client.BeginAdd(int.Parse(textBox1.Text), int.Parse(textBox2.Text), new AsyncCallback(CallBack), client); break;
                case "-": client.BeginSub(int.Parse(textBox1.Text), int.Parse(textBox2.Text), new AsyncCallback(CallBack), client); break;
                case "*": client.BeginMul(int.Parse(textBox1.Text), int.Parse(textBox2.Text), new AsyncCallback(CallBack), client); break;
                case "/": client.BeginDiv(int.Parse(textBox1.Text), int.Parse(textBox2.Text), new AsyncCallback(CallBack), client); break;
            }
            client.Clear();
            
        }

        //비동기 콜백 함수
        //여기에서 begin에 대한 end 호출
        public void CallBack(IAsyncResult ar)
        {
            switch (op)
            {
                case "+": ((CalClient)ar.AsyncState).EndAdd(ar); break;
                case "-": ((CalClient)ar.AsyncState).EndSub(ar); break;
                case "*": ((CalClient)ar.AsyncState).EndMul(ar); break;
                case "/": ((CalClient)ar.AsyncState).EndDiv(ar); break;
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            client.Close();
        }
    }
}
