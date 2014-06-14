
#pragma once
#define WSA_RECV         0
#define WSA_SEND         1
#define DATA_BUFSIZE    8192
#define MAX_NAME_LEN    128
#define MAX_PWD_LEN     128
#define MAX_RESP_LEN    1024
#define MAX_REQ_LEN     256
#define MAX_ADDR_LEN    80
#define FTP_PORT        21     // FTP TCP控制端口
#define DATA_FTP_PORT   22     // FTP TCP数据端口
#define UDP_FTP_PORT    20     // UDP 端口

#define USER_OK         331
#define LOGGED_IN       230
#define LOGIN_FAILED    530
#define CMD_OK          200
#define OPENING_AMODE   150
#define TRANS_COMPLETE  226
#define CANNOT_FIND     550
#define FTP_QUIT        221
#define CURR_DIR        257
#define DIR_CHANGED     250
#define OS_TYPE         215
#define REPLY_MARKER    504
#define PASSIVE_MODE    227

#define FTP_USER		"xhy"
#define FTP_PASS		"xhy"
#define DEFAULT_HOME_DIR    "D://xhy/"

#define MAX_FILE_NUM        1024

#define MODE_PORT       0
#define MODE_PASV       1

#define PORT_BIND   1821

typedef struct {
   CHAR   buffRecv[DATA_BUFSIZE];
   CHAR   buffSend[DATA_BUFSIZE];
   WSABUF wsaBuf;
   SOCKET s;
   WSAOVERLAPPED o;
   DWORD dwBytesSend;
   DWORD dwBytesRecv;
   int   nStatus;
} SOCKET_INF, *LPSOCKET_INF;

typedef struct {
	TCHAR    szFileName[MAX_PATH];
	DWORD    dwFileAttributes; 
    FILETIME ftCreationTime; 
    FILETIME ftLastAccessTime; 
    FILETIME ftLastWriteTime; 
    DWORD    nFileSizeHigh; 
    DWORD    nFileSizeLow; 
} FILE_INF, *LPFILE_INF;


class FtpServer
{
	
public:
	FtpServer(void);
	~FtpServer(void);

};
UINT FtpServerThread(LPVOID param);
DWORD WINAPI ProcessTreadIO( LPVOID lpParam ) ;
BOOL WelcomeInfo( SOCKET s );
int LoginIn( LPSOCKET_INF pSocketInfo  );
int SendRes( LPSOCKET_INF pSI );
int RecvReq( LPSOCKET_INF pSI );
int DealCommand( LPSOCKET_INF pSI );

int GetFileList( LPFILE_INF pFI, UINT nArraySize, const char* szPath  );
char* GetLocalAddress();
char* HostToNet( char* szPath ) ;
char* NetToHost( char* szPath ) ;
char* RelativeDirectory( char* szDir );
char* AbsoluteDirectory( char* szDir );