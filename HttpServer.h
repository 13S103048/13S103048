
#pragma once

#include "HttpProtocol.h"

#define HTTPROOTDIR "D://xhy/"
UINT HttpServerThread(LPVOID param); //�߳��к����������ȫ�ֱ���
class HttpServer
{

public:
	HttpServer(void);
	~HttpServer(void);
};
