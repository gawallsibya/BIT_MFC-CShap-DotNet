<%@ Application Language="C#" %>

<script runat="server">

    void Application_Start(object sender, EventArgs e) 
    {
        // 응용 프로그램이 시작될 때 실행되는 코드입니다.

    }
    
    void Application_End(object sender, EventArgs e) 
    {
        //  응용 프로그램이 종료될 때 실행되는 코드입니다.

    }
        
    void Application_Error(object sender, EventArgs e) 
    { 
        // 처리되지 않은 오류가 발생할 때 실행되는 코드입니다.

    }

    void Session_Start(object sender, EventArgs e) 
    {
        // 새 세션이 시작할 때 실행되는 코드입니다.        

    }

    void Session_End(object sender, EventArgs e) 
    {
        // 새 세션이 끝날 때 실행되는 코드입니다. 
        // 참고: Web.config 파일에서 sessionstate 모드가 InProc로 설정되어 있는 경우에만
        // Session_End 이벤트가 발생합니다. 세션 모드가 StateServer 또는 SQLServer로 
        // 설정되어 있는 경우에는 이 이벤트가 발생하지 않습니다.

    }

    //void Profile_MigrateAnonymous(object sender, ProfileMigrateEventArgs e)
    //{
    //    // 익명 사용자 프로필을 가져온다.
    //    ProfileCommon anonProfile = Profile.GetProfile(e.AnonymousID);

    //    // 익명 사용자 프로필을 인증된 사용자 프로필에 저장한다.
    //    Profile.MainBackColor = anonProfile.MainBackColor;
    //    Profile.EnableCalendar = anonProfile.EnableCalendar;

    //    // 익명 사용자 프로필 및 익명 사용자 ID를 삭제한다.
    //    ProfileManager.DeleteProfile(e.AnonymousID);
    //    AnonymousIdentificationModule.ClearAnonymousIdentifier();
    //} 
    
       
</script>
