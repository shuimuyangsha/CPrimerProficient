#include<stdio.h>
#include<winsock.h>		/*����winsockͷ�ļ�*/

int  main()
{
	/*---------------------�������---------------------------------*/
	char Sendbuf[100];						/*�������ݵĻ�����*/
	char Receivebuf[100];					/*�������ݵĻ�����*/
	int SendLen;							/*�������ݵĳ���*/
	int	ReceiveLen;							/*�������ݵĳ���*/
	int Length;								/*��ʾSOCKADDR�Ĵ�С*/

	SOCKET socket_server;					/*����������׽���*/
	SOCKET socket_receive;  				/*�������������׽���*/

	SOCKADDR_IN Server_add;				/*��������ַ��Ϣ�ṹ*/
	SOCKADDR_IN Client_add;				/*�ͻ��˵�ַ��Ϣ�ṹ*/

	WORD wVersionRequested;				/*�֣�word����unsigned short*/
	WSADATA wsaData;					/*��汾��Ϣ�ṹ*/
	int error;								/*��ʾ����*/

	/*--------------------��ʼ���׽��ֿ�-------------------------*/

	/*����汾���͡�*/
	wVersionRequested = MAKEWORD( 2, 2 );	
	/*��ʼ��Ws2_32.dll��̬���ӿ�*/
	error = WSAStartup( wVersionRequested, &wsaData);	
	if(error!=0)
	{
		printf("�����׽���ʧ�ܣ�");
		return 0;							/*�������*/
	}
	/*�ж�������صİ汾���Ƿ����Ҫ��*/
	if ( LOBYTE( wsaData.wVersion ) != 2 ||
		   HIBYTE( wsaData.wVersion ) != 2 ) 
	{	
		WSACleanup( );					/*�����ϣ��ر��׽��ֿ�*/
		return 0;							/*�������*/
	}

	/*-------------------�������ӵ�ַ-----------------------------*/
	Server_add.sin_family=AF_INET;/*��ַ���壬���ڱ�����AF_INET��ע��ֻ�����������������ֽ�˳��*/
	Server_add.sin_addr.S_un.S_addr=htonl(INADDR_ANY);/*������ַ*/
	Server_add.sin_port=htons(5000);/*�˿ں�*/

	/*-------------------�����׽���--------------------------------*/
	/*AF_INET��ʾָ����ַ�壬SOCK_STREAM��ʾ��ʽ�׽���TCP���ض��ĵ�ַ������ص�Э�顣*/
	socket_server=socket(AF_INET,SOCK_STREAM,0);

	/*---���׽��ֵ����ص�ĳ����ַ�Ͷ˿���----*/
			/*socket_serverΪ�׽��֣�(SOCKADDR*)&Server_addΪ��������ַ*/
	if(bind(socket_server,(SOCKADDR*)&Server_add,sizeof(SOCKADDR) )==SOCKET_ERROR)
	{
		printf("��ʧ��\n");
	}

	/*--------------------�����׽���Ϊ����״̬----------------*/
		/*����״̬��Ϊ������׼�������ȴ�����ĿΪ5*/
	if(listen(socket_server,5)<0)
	{
		printf("����ʧ��\n");
	}
	
	/*------------------------------------------------------------------*/
	/*----------------------��������--------------------------------*/
	/*------------------------------------------------------------------*/
	Length=sizeof(SOCKADDR);
	/*���ܿͻ��˵ķ�������,�ȴ��ͻ��˷���connect����*/
	socket_receive=accept(socket_server,(SOCKADDR*)&Client_add,&Length);
	if(socket_receive==SOCKET_ERROR)
	{
		printf("��������ʧ��");
	}


	/*-------------------��������-----------------------------------*/
	ReceiveLen =recv(socket_receive,Receivebuf,100,0);
	if(ReceiveLen<0)
	{
		printf("����ʧ��\n");
		printf("�����˳�\n");
	}
	else
	{
		printf("there is a message: %s\n",Receivebuf);
	}	
	
	/*-------------------���лظ�-----------------------------------*/
	strcpy(Sendbuf,"Welcome!");
	SendLen=send(socket_receive,Sendbuf,100,0);
	if(SendLen<0)
	{
		printf("����ʧ��\n");
	}

	/*------------------------------------------------------------------*/
	/*--------------------�ͷ��׽��֣��رն�̬��-------------*/
	/*------------------------------------------------------------------*/
	closesocket(socket_receive);				/*�ͷſͻ��˵��׽�����Դ*/
	closesocket(socket_server);					/*�ͷ��׽�����Դ*/
	WSACleanup();								/*�رն�̬���ӿ�*/
	return 0;
}