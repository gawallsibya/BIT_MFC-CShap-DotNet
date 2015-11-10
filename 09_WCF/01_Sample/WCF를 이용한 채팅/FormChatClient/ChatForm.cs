// 참고자료: Nikola Paljetak
// 만든이: 박경훈(HOONS)
// 닷넷 커뮤니티 : HOONS닷넷 - http://www.hoonsbara.com

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
        pwDlg.ShowError("에러: 채팅에 접속할 수 없습니다!");
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
          pwDlg.ShowError("에러: 사용자 이름이 이미 존재합니다!");
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
          AppendText("접속됐습니다. " + DateTime.Now.ToString() + " 사용자: " + myNick + Environment.NewLine);
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
          AppendText("연결이 종료되었습니다. " + DateTime.Now.ToString() + Environment.NewLine);
          Error("에러: 서버가 죽었습니다.!");
        }
      }
    }


    private void Error(string errMessage)
    {
      MessageBox.Show(errMessage, "Connection error", MessageBoxButtons.OK, MessageBoxIcon.Error);
      ExitChatSession();
    }

    #region 어플리케이션 이벤트
    /// <summary>
    /// 말하기
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void btnSay_Click(object sender, EventArgs e)
    {
      SayAndClear("", txtMessage.Text, false);
      txtMessage.Focus();
    }
    /// <summary>
    /// 접속하기
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
    /// 귓속말
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
    /// 접속해제
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
    /// 어플리케이션 종료
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void exitToolStripMenuItem_Click(object sender, EventArgs e)
    {
      ExitChatSession();
      ExitApplication();
    }

    /// <summary>
    /// 어플리케이션 종료
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

    //메뉴 보이게 하기
    private void ShowConnectMenuItem(bool show)
    {
      connectToolStripMenuItem.Enabled = show;
      disconnectToolStripMenuItem.Enabled = btnSay.Enabled = !show;
    }

    //엔터를 눌렀을때

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


    //세션끝내기
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

    //프록시 설정
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

    //어플리케이션 종료
    private void ExitApplication()
    {
      Application.Exit();
    }

    

    //귓속말 관련 설정
    private void lstChatters_SelectedIndexChanged(object sender, EventArgs e)
    {
      AdjustWhisperButton();
    }

    //귓속말관련 설정
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

    #region 서버에서 온 메세지 (서버->클라이언트)

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