#pragma once

#include "HPSocket/HPSocket.h"
#include "HPSocket/SocketInterface.h"

class CUdpListenerObj : public CUdpServerListener
{
public:
    CUdpListenerObj();

    void PrintClientMessage(IUdpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength);

    void Start();

private:
    virtual EnHandleResult OnReceive(IUdpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength) override;
    virtual EnHandleResult OnClose(IUdpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode) override;

private:
    CUdpServerPtr ServerPtr;
};

