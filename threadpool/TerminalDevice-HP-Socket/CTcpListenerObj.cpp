#include "CTcpListenerObj.h"

#include <iostream>
#include <codecvt>
#include <map>

static const char * utf8ToGbkString(char *utf8)
{
	std::string str = utf8;

	int utf8Length = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	wchar_t* wideString = new wchar_t[utf8Length];
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wideString, utf8Length);

	int gbkLength = WideCharToMultiByte(CP_ACP, 0, wideString, -1, nullptr, 0, nullptr, nullptr);
	char* gbkString = new char[gbkLength];
	WideCharToMultiByte(CP_ACP, 0, wideString, -1, gbkString, gbkLength, nullptr, nullptr);

	delete[] wideString;

	return gbkString;
}

void CTcpListenerObj::Start()
{
	if (!ServerPtr->Start("0.0.0.0", 1087))
	{
		std::cout << "\033[31m"
			<< "bind address failed: "
			<< ServerPtr->GetLastError()
			<< "\033[0m\n";
		exit(1);
	}
}

void CTcpListenerObj::SendToClientAll()
{
	char str[64] = "notification";

	for (const auto& pair : clientMap) 
	{
		ServerPtr->Send(pair.first, (BYTE*)str, strlen(str));
	}
}


void CTcpListenerObj::PrintClientMessage(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
	const char* gbkString = utf8ToGbkString((char*)pData);

	TCHAR lpszAddress[16];
	int iAddressLen = sizeof(lpszAddress);
	USHORT usPort;
	static short terminalCode = 32;
	static std::map<USHORT, short> terminalColor;

	pSender->GetRemoteAddress(dwConnID, lpszAddress, iAddressLen, usPort);

	if (terminalColor.find(usPort) == terminalColor.end())
	{
		terminalColor.insert(std::make_pair(usPort, terminalCode));
		terminalCode++;
	}

	std::wcout << "\033[:" << terminalColor[usPort] << "mTCP Client address:[" << lpszAddress
		<< "] port:[" << usPort
		<< "] Message:" << gbkString << "\033[0m\n";

	delete[] gbkString;
}

EnHandleResult CTcpListenerObj::OnHandShake(ITcpServer* pSender, CONNID dwConnID)
{
	TCHAR lpszAddress[16];
	int iAddressLen = sizeof(lpszAddress);
	USHORT usPort;

	pSender->GetRemoteAddress(dwConnID, lpszAddress, iAddressLen, usPort);

	std::cout << "\033[32m" 
		<< "¿Í»§¶ËµØÖ·£º" 
		<< lpszAddress 
		<< "\033[0m\n";

	char str[64] = "Hello";

	if (!pSender->Send(dwConnID, (BYTE*)str, strlen(str)))
	{
		std::cout << "\033[31m" << "Failed to send:" << SYS_GetLastError() << "\n";
	}

	return EnHandleResult();
}

EnHandleResult CTcpListenerObj::OnSend(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
	return EnHandleResult();
}

EnHandleResult CTcpListenerObj::OnReceive(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
	PrintClientMessage(pSender, dwConnID, pData, iLength);

	return EnHandleResult();
}

EnHandleResult CTcpListenerObj::OnReceive(ITcpServer* pSender, CONNID dwConnID, int iLength)
{
	return EnHandleResult();
}

EnHandleResult CTcpListenerObj::OnClose(ITcpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	clientMap.erase(dwConnID);

	return EnHandleResult();
}

EnHandleResult CTcpListenerObj::OnShutdown(ITcpServer* pSender)
{
	return EnHandleResult();
}

EnHandleResult CTcpListenerObj::OnPrepareListen(ITcpServer* pSender, SOCKET soListen)
{
	return EnHandleResult();
}

EnHandleResult CTcpListenerObj::OnAccept(ITcpServer* pSender, CONNID dwConnID, UINT_PTR soClient)
{
	static int clientIndex = 0;

	clientMap.insert(std::make_pair(dwConnID, clientIndex++));

	return EnHandleResult();
}
