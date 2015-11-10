// �����ڷ�: Nikola Paljetak
// ������: �ڰ���(HOONS)
// ��� Ŀ�´�Ƽ : HOONS��� - http://www.hoonsbara.com

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.ServiceModel;


namespace NikeSoftChat
{
  public partial class ChatForm : Form, IChatCallback
  {

    private int lastSelectedIndex = -1;

    private ChatProxy proxy;
    private string myNick;

    private PleaseWaitDialog pwDlg;
    private delegate void HandleDelegate(string[] list);
    private delegate void HandleErrorDelegate();

    public ChatForm()
    {
      InitializeComponent();
      ShowConnectMenuItem(true);
    }



    private void OnEndJoin(IAsyncResult iar)
    {
      try
      {
        string[] list = proxy.EndJoin(iar);
        HandleEndJoin(list);

      }
      catch (Exception e)
      {
        HandleEndJoinError();
      }

    }

    private void HandleEndJoinError()
    {
      if (pwDlg.InvokeRequired)
        pwDlg.Invoke(new HandleErrorDelegate(HandleEndJoinError));
      else
      {
        pwDlg.ShowError("����: ä�ÿ� ������ �� �����ϴ�!");
        ExitChatSession();
      }
    }



    private void HandleEndJoin(string[] list)
    {

      if (pwDlg.InvokeRequired)
        pwDlg.Invoke(new HandleDelegate(HandleEndJoin), new object[] { list });
      else
      {

        if (list == null)
        {
          pwDlg.ShowError("����: ����� �̸��� �̹� �����մϴ�!");
          ExitChatSession();
        }
        else
        {
          pwDlg.Close();
          ShowConnectMenuItem(false);
          foreach (string name in list)
          {
            lstChatters.Items.Add(name);
          }
          AppendText("���ӵƽ��ϴ�. " + DateTime.Now.ToString() + " �����: " + myNick + Environment.NewLine);
        }
      }
    }

    private void SayAndClear(string to, string msg, bool pvt)
    {
      if (msg != "")
      {
        try
        {
          CommunicationState cs = proxy.State;
          if (!pvt)
            proxy.Say(msg);
          else
            proxy.Whisper(to, msg);

          txtMessage.Text = "";
        }
        catch
        {
          AbortProxyAndUpdateUI();
          AppendText("������ ����Ǿ����ϴ�. " + DateTime.Now.ToString() + Environment.NewLine);
          Error("����: ������ �׾����ϴ�.!");
        }
      }
    }


    private void Error(string errMessage)
    {
      MessageBox.Show(errMessage, "Connection error", MessageBoxButtons.OK, MessageBoxIcon.Error);
      ExitChatSession();
    }

    #region ���ø����̼� �̺�Ʈ
    /// <summary>
    /// ���ϱ�
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void btnSay_Click(object sender, EventArgs e)
    {
      SayAndClear("", txtMessage.Text, false);
      txtMessage.Focus();
    }
    /// <summary>
    /// �����ϱ�
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void connectToolStripMenuItem_Click(object sender, EventArgs e)
    {
      InstanceContext site = new InstanceContext(this);
      proxy = new ChatProxy(site);
      lstChatters.Items.Clear();
      NickDialog nickDlg = new NickDialog();
      if (nickDlg.ShowDialog() == DialogResult.OK)
      {
        myNick = nickDlg.txtNick.Text;
        nickDlg.Close();
      }

      txtMessage.Focus();

      IAsyncResult iar = proxy.BeginJoin(myNick, new AsyncCallback(OnEndJoin), null);
      pwDlg = new PleaseWaitDialog();
      pwDlg.ShowDialog();

    }
    /// <summary>
    /// �ӼӸ�
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void btnWhisper_Click(object sender, EventArgs e)
    {
      if (txtMessage.Text == "")
        return;

      object to = lstChatters.SelectedItem;
      if (to != null)
      {
        string receiverName = (string)to;
        AppendText("Whisper to " + receiverName + ": " + txtMessage.Text + Environment.NewLine);
        SayAndClear(receiverName, txtMessage.Text, true);
        txtMessage.Focus();
      }
    }

    /// <summary>
    /// ��������
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void disconnectToolStripMenuItem_Click(object sender, EventArgs e)
    {
      ExitChatSession();
      btnWhisper.Enabled = false;
      AppendText("Disconnected at " + DateTime.Now.ToString() + Environment.NewLine);
    }

    /// <summary>
    /// ���ø����̼� ����
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void exitToolStripMenuItem_Click(object sender, EventArgs e)
    {
      ExitChatSession();
      ExitApplication();
    }

    /// <summary>
    /// ���ø����̼� ����
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void ChatForm_FormClosed(object sender, FormClosedEventArgs e)
    {
      ExitChatSession();
      ExitApplication();
    }

    #endregion



    private void AppendText(string text)
    {
      txtChatText.Text += text;
    }

    //�޴� ���̰� �ϱ�
    private void ShowConnectMenuItem(bool show)
    {
      connectToolStripMenuItem.Enabled = show;
      disconnectToolStripMenuItem.Enabled = btnSay.Enabled = !show;
    }

    //���͸� ��������

    private void txtMessage_KeyPress(object sender, KeyPressEventArgs e)
    {
      if (e.KeyChar == 13)
      {
        e.Handled = true;
      }
    }
    private void txtMessage_KeyDown(object sender, KeyEventArgs e)
    {
      if (e.KeyData == Keys.Enter && btnSay.Enabled)
      {
        SayAndClear("", txtMessage.Text, false);
      }
    }


    //���ǳ�����
    private void ExitChatSession()
    {
      try
      {
        proxy.Leave();
      }
      catch { }
      finally
      {
        AbortProxyAndUpdateUI();
      }
    }

    //���Ͻ� ����
    private void AbortProxyAndUpdateUI()
    {
      if (proxy != null)
      {
        proxy.Abort();
        proxy.Close();
        proxy = null;
      }
      ShowConnectMenuItem(true);
    }

    //���ø����̼� ����
    private void ExitApplication()
    {
      Application.Exit();
    }

    

    //�ӼӸ� ���� ����
    private void lstChatters_SelectedIndexChanged(object sender, EventArgs e)
    {
      AdjustWhisperButton();
    }

    //�ӼӸ����� ����
    private void AdjustWhisperButton()
    {
      if (lstChatters.SelectedIndex == lastSelectedIndex)
      {
        lstChatters.SelectedIndex = -1;
        lastSelectedIndex = -1;
        btnWhisper.Enabled = false;
      }
      else
      {
        btnWhisper.Enabled = true;
        lastSelectedIndex = lstChatters.SelectedIndex;
      }
      txtMessage.Focus();
    }

    #region �������� �� �޼��� (����->Ŭ���̾�Ʈ)

    public void Receive(string senderName, string message)
    {
      AppendText(senderName + ": " + message + Environment.NewLine);
    }

    public void ReceiveWhisper(string senderName, string message)
    {
      AppendText(senderName + " whisper: " + message + Environment.NewLine);
    }

    public void UserEnter(string name)
    {
      AppendText("User " + name + " enter at " + DateTime.Now.ToString() + Environment.NewLine);
      lstChatters.Items.Add(name);
    }

    public void UserLeave(string name)
    {
      AppendText("User " + name + " leave at " + DateTime.Now.ToString() + Environment.NewLine);
      lstChatters.Items.Remove(name);
      AdjustWhisperButton();
    }
    #endregion

  }
}