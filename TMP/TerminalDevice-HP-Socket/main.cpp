#include <stdio.h>

#include "CTcpListenerObj.h"
#include "CUdpListenerObj.h"

int main(void)
{
	CTcpListenerObj tcpServer;

	tcpServer.Start();

	CUdpListenerObj udpServer;

	udpServer.Start();

	// ģ�ⷢ������
	while (true)
	{
		//ģ�ⷢ������
		tcpServer.SendToClientAll();

		Sleep(5000);
	}

	getchar();

	return 0;
}