// MFC Library1 : CString, CArray, CList, CMap

#include <afxwin.h> // MFC �⺻���.

#include <afxtempl.h> // MFC template Ŭ������

#include <iostream>

using namespace std;

 

 

void main()

{

        CMap<CString, CString, CString, CString> m;

 

        m["mon"] = "������";

 

        cout << (const char*)m["mon"] << endl;

 

 

 

        CList<int, int> st;

 

        st.AddHead( 10 );

        st.AddHead( 20 );

        st.AddHead( 30 );

 

        // list ��ȸ.

        POSITION pos = st.GetHeadPosition();

 

        while( pos != 0 )

        {

               int n = st.GetNext( pos );

               cout << n << endl;

        }

}

 

//-----------------------------------------------------------------------

 

/*

// CArray�� ���� ���

template<typename _T1, typename _T2>

class CArray

{

public:

        void Add( _T1 a )  {} // ���� a �߰�

        _T2 GetAt( int n ) {} // n��° ��� ����.

};

*/

 

/*

void main()

{

        CArray<int, int> ar;

        ar.SetSize( 5, 5 ); // �ʱ� ũ�� 5, 

                            // �޸� ������ �ʿ��ϸ� 5�� ����.(GROW SIZE)

 

        ar[0] = 10;

 

        ar.Add(20); // ���� �߰�. 6���� ���Ѵ�.

 

        cout << ar.GetSize() << endl;

}

 

//------------------------------------------------------------------------

 

/*

void main()

{

        CString s1 = "hello";

        CString s2 = "world";

        CString s3 = s1 + s2;

 

        s3.GetAt(1);

 

//      cout << (const char*)s3 << endl;

        cout << s3.GetBuffer(0) << endl;

 

        CTime t = CTime::GetCurrentTime();

 

        cout << t.GetHour() << ":" << t.GetMinute() << ":" << t.GetSecond() << endl;

 

        CSize sz;

        sz.cx = 10;

        sz.cy = 10;

 

//      CList<int, int> ar;

//      ar[0] = 10;

//      cout << ar[0] << endl;

 

}

*/
