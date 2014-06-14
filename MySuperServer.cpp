// MySuperServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MySuperServer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

#include <string.h>
#include <ws2tcpip.h>
#include <stdlib.h>

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		m_pServerThread[0] = AfxBeginThread(HttpServerThread,NULL);
		m_pServerThread[1] = AfxBeginThread(FtpServerThread,NULL);
		HANDLE * tmp = new HANDLE[2];
		tmp[0] = m_pServerThread[0]->m_hThread;
		tmp[1] = m_pServerThread[1]->m_hThread;
		WaitForMultipleObjects(2,tmp,true,INFINITE);
	}
	return nRetCode;
}




