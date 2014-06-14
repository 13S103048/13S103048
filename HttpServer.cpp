#include "stdafx.h"
#include "HttpServer.h"
using namespace std;
#include <string.h>
#include <ws2tcpip.h>
#include <stdlib.h>

HttpServer::HttpServer(void)
{

}

HttpServer::~HttpServer(void)
{
}
UINT HttpServerThread(LPVOID param)
{	
	CHttpProtocol *pHttpProtocol;
	pHttpProtocol = new CHttpProtocol;
	pHttpProtocol->m_strRootDir = HTTPROOTDIR;
	pHttpProtocol->m_nPort = HTTPPORT;
	if(!pHttpProtocol->StartHttpSrv())
	{
		delete pHttpProtocol;
		pHttpProtocol = NULL;
	}
	return 0;
}