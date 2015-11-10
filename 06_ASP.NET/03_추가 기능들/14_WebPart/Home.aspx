<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" Title="Untitled Page" %>
<%@ Register Src="WebUserControl1.ascx" TagName="WebUserControl1" TagPrefix="uc1" %>

<script runat="server">
    //protected void Page_Init(object sender, EventArgs e)
    //{
    //    foreach (WebPartDisplayMode mode in WebPartManager1.SupportedDisplayModes)
    //    {
    //        string modeName = mode.Name;
    //        if (mode.IsEnabled(WebPartManager1))
    //        {
    //            ListItem li = new ListItem(modeName, modeName);
    //            DropDownList1.Items.Add(li);
    //        }
    //    }
    //}

    //protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    //{
    //    string selectedMode = DropDownList1.SelectedValue;
    //    WebPartDisplayMode mode = WebPartManager1.SupportedDisplayModes[selectedMode];
    //    if (mode != null)
    //        WebPartManager1.DisplayMode = mode;
    //}

    //protected void Page_Load(object sender, EventArgs e)
    //{
    //    if (WebPartManager1.Personalization.Scope == PersonalizationScope.User && WebPartManager1.Personalization.CanEnterSharedScope)
    //    {
    //        WebPartManager1.Personalization.ToggleScope();
    //    }

    //    Label1.Text = WebPartManager1.Personalization.Scope.ToString();
    //}
</script>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <asp:WebPartManager ID="WebPartManager1" runat="server">
    </asp:WebPartManager>
    <%--<asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="true" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged">
    </asp:DropDownList>
    <asp:Label ID="Label1" runat="server"></asp:Label>--%>
    <table width="100%">
        <tr>
            <td valign="top">
                <asp:WebPartZone ID="WebPartZone1" runat="server">
                    <ZoneTemplate>
                        <asp:Panel ID="Panel1" runat="server" Height="50px" Width="125px" title="공지사항">
                            * 3월 MSDN세미나에서 여러분을...<br />
                            * 2월 MSDN세미나에서 여러분을...
                        </asp:Panel>
                    </ZoneTemplate>
                </asp:WebPartZone>
            </td>
            <td valign="top">
                <asp:WebPartZone ID="WebPartZone2" runat="server">
                    <ZoneTemplate>
                        <uc1:WebUserControl1 ID="WebUserControl1_1" runat="server" title="사이트 검색" />
                    </ZoneTemplate>
                </asp:WebPartZone>
            </td>
            <td valign="top">
                <%--<asp:CatalogZone ID="CatalogZone1" runat="server">
                    <ZoneTemplate>
                        <asp:PageCatalogPart ID="PageCatalogPart1" runat="server" />
                        <asp:DeclarativeCatalogPart ID="DeclarativeCatalogPart1" runat="server">
                            <WebPartsTemplate>
                                <asp:FileUpload ID="FileUpload1" runat="server" title="선언된 웹 파트1" />
                            </WebPartsTemplate>
                        </asp:DeclarativeCatalogPart>
                        <asp:ImportCatalogPart ID="ImportCatalogPart1" runat="server" />
                    </ZoneTemplate>
                </asp:CatalogZone>--%>
            </td>
        </tr>
        <tr>
            <td valign="top">
                <asp:WebPartZone ID="WebPartZone3" runat="server">
                    <ZoneTemplate>
                        <asp:Panel ID="Panel2" runat="server" Height="50px" Width="125px" title="오늘의 뉴스">
                            * 국산 지상파 DMB폰 중국 간다.<br />
                            * 화장지 길이 속여 수억 이득...
                        </asp:Panel>
                    </ZoneTemplate>
                </asp:WebPartZone>
            </td>
            <td valign="top">
                <asp:WebPartZone ID="WebPartZone4" runat="server">
                    <ZoneTemplate>
                        <asp:Calendar ID="Calendar1" runat="server" title="세미나 일정"></asp:Calendar>
                    </ZoneTemplate>
                </asp:WebPartZone>
            </td>
            <td valign="top">
                 <%--<asp:EditorZone ID="EditorZone1" runat="server">
                    <ZoneTemplate>
                        <asp:AppearanceEditorPart ID="AppearanceEditorPart1" runat="server" />
                        <asp:LayoutEditorPart ID="LayoutEditorPart1" runat="server" />
                        <asp:BehaviorEditorPart ID="BehaviorEditorPart1" runat="server" />
                    </ZoneTemplate>
                </asp:EditorZone>--%>
            </td>
        </tr>
    </table>
</asp:Content>