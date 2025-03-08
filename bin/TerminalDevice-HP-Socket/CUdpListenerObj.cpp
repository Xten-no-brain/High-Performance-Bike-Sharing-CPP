#include "CUdpListenerObj.h"

#include <string>
#include <iostream>
#include <map>

static const char* utf8ToGbkString(char* utf8)
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

CUdpListenerObj::CUdpListenerObj()
	: ServerPtr(this)
{
}


void CUdpListenerObj::PrintClientMessage(IUdpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
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

	std::wcout << "\033[" << terminalColor[usPort] << "mUDP Client address:[" << lpszAddress
		<< "] port:[" << usPort
		<< "] Message:" << gbkString << "\033[0m\n";

	pSender->Send(dwConnID, pData, iLength);

	delete[] gbkString;
}

void CUdpListenerObj::Start()
{
	if (!ServerPtr->Start("0.0.0.0", 6048))
	{
		std::cout << "\033[31m" << "Failed to start UDP server:" << GetLastError()
			<< "\033[0m\n";
	}
}

EnHandleResult CUdpListenerObj::OnReceive(IUdpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
	PrintClientMessage(pSender, dwConnID, pData, iLength);

	return EnHandleResult();
}

EnHandleResult CUdpListenerObj::OnClose(IUdpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	return EnHandleResult();
}
