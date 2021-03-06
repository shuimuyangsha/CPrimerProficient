#include<stdio.h>
#include<winsock.h>							/*引入winsock头文件*/

int  main()
{
	/*------------------------------------------------------------------*/
	/*----------------------定义变量--------------------------------*/
	/*------------------------------------------------------------------*/
	SOCKET socket_client;				/*定义套接字*/
	SOCKADDR_IN Server_add;				/*服务器地址信息结构*/

	WORD wVersionRequested;				/*字（word）：unsigned short*/
	WSADATA wsaData;					/*库版本信息结构*/
	int error;							/*表示错误*/

	/*------------------------------------------------------------------*/
	/*-------------------------初始化套接字库---------------------------*/
	/*------------------------------------------------------------------*/
				/*定义版本类型。将两个字节组合成一个字，前面是第字节，后面是高字节*/
	wVersionRequested = MAKEWORD( 2, 2 );	
				/*加载套接字库，初始化Ws2_32.dll动态链接库*/
	error = WSAStartup( wVersionRequested, &wsaData);	
	if(error!=0)
	{
		printf("加载套接字失败！");
		return 0;							/*程序结束*/
	}
				/*判断请求加载的版本号是否符合要求*/
	if ( LOBYTE( wsaData.wVersion ) != 2 ||
		   HIBYTE( wsaData.wVersion ) != 2 ) 
	{	
		WSACleanup( );					/*不符合，关闭套接字库*/
		return 0;							/*程序结束*/
	}

	/*创建套接字*/
	socket_client=socket(AF_INET,SOCK_DGRAM,0);

	/*----------------------设置服务器地址-----------------------*/
	Server_add.sin_family=AF_INET;/*地址家族，对于必须是AF_INET，注意只有它不是网络网络字节顺序*/
	Server_add.sin_addr.S_un.S_addr = inet_addr("192.168.1.238");
	Server_add.sin_port=htons(5000);/*端口号*/

	sendto(socket_client,"ILoveChina",strlen("ILoveChina")+1,0,(SOCKADDR*)&Server_add,sizeof(SOCKADDR));
	/*------------------------------------------------------------------*/
	/*-----------------------释放套接字，关闭动态库----------*/
	/*------------------------------------------------------------------*/
	closesocket(socket_client);				/*释放套接字资源*/
	WSACleanup();							/*关闭动态链接库*/
	return 0;
}
