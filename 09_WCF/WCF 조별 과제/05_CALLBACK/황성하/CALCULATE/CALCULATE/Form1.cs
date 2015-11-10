using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ServiceModel;
using CALCULATE.ServiceReference1;

namespace CALCULATE
{
    public partial class Form1 : Form, ICalCallback
    {
        private ICal cal;
        private delegate void Dele(int num1, int num2);

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            InstanceContext site = new InstanceContext(this);
            cal = new CalClient(site);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Dele temp = null;
            try
            {
                switch (comboBox1.SelectedItem.ToString())
                {
                    case "+": temp = new Dele(cal.Add); break;
                    case "-": temp = new Dele(cal.Sub); break;
                    case "*": temp = new Dele(cal.Mul); break;
                    case "/": temp = new Dele(cal.Div); break;
                }
            }
            catch
            {
                MessageBox.Show("정상적으로 입력해 주세요");
            }
            if (temp != null && textBox2.Text != "0")
                temp.Invoke(int.Parse(textBox1.Text), int.Parse(textBox2.Text));           
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Dele temp = null;
            try
            {
                switch(comboBox1.SelectedItem.ToString())
                {
                    case "+": temp = new Dele(cal.Add); break;
                    case "-": temp = new Dele(cal.Sub); break;
                    case "*": temp = new Dele(cal.Mul); break;
                    case "/": temp = new Dele(cal.Div); break;
                }
            }
            catch
            {
                MessageBox.Show("정상적으로 입력해 주세요");
            }
            if(temp != null && textBox2.Text != "0")
                temp.BeginInvoke(int.Parse(textBox1.Text), int.Parse(textBox2.Text), Callback, null);
        }

        public void Result(float result)
        {
            textBox3.Text = result.ToString();
        }

        private void Callback(IAsyncResult result)
        {
            var asyncResult = (System.Runtime.Remoting.Messaging.AsyncResult)result;
            var testDelegate = (Dele)asyncResult.AsyncDelegate;
            testDelegate.EndInvoke(result);
        }



    }
}
