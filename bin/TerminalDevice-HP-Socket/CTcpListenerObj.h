#include <HPSocket/HPSocket.h>
#include <iostream>
#include <map>

#pragma once

class CTcpListenerObj : public ITcpServerListener
{
public:
    CTcpListenerObj() : ServerPtr(this)
	{ }

	void Start();

	void SendToClientAll();

    void PrintClientMessage(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength);

private:
	// 处理网络事件
	// 通过 ITcpServerListener 继承
	EnHandleResult OnHandShake(ITcpServer* pSender, CONNID dwConnID) override;

	EnHandleResult OnSend(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength) override;

	EnHandleResult OnReceive(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength) override;

	EnHandleResult OnReceive(ITcpServer* pSender, CONNID dwConnID, int iLength) override;

	EnHandleResult OnClose(ITcpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode) override;

	EnHandleResult OnShutdown(ITcpServer* pSender) override;

	EnHandleResult OnPrepareListen(ITcpServer* pSender, SOCKET soListen) override;

	EnHandleResult OnAccept(ITcpServer* pSender, CONNID dwConnID, UINT_PTR soClient) override;

private:
	CTcpServerPtr ServerPtr;

    bool flagHead, flagTail;
	std::map<CONNID, int> clientMap;
};

