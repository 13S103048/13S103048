
#pragma once

#include "HttpProtocol.h"

#define HTTPROOTDIR "D://xhy/"
UINT HttpServerThread(LPVOID param); //线程中函数类必须是全局变量
class HttpServer
{

public:
	HttpServer(void);
	~HttpServer(void);
};
