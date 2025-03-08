#include <stdio.h>

#include "CTcpListenerObj.h"
#include "CUdpListenerObj.h"

int main(void)
{
	CTcpListenerObj tcpServer;

	tcpServer.Start();

	CUdpListenerObj udpServer;

	udpServer.Start();

	// 模拟发送数据
	while (true)
	{
		//模拟发送数据
		tcpServer.SendToClientAll();

		Sleep(5000);
	}

	getchar();

	return 0;
}