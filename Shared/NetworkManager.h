#pragma once

#include "NetPeer.h"
#include "NetSocket.h"
#include "GenericRPC.h"
#include "GenericRPCListener.h"
#include "Msg.h"
#include <list>

namespace Shared
{
	//**********************************************************************************************************************
	class NetworkManager
	{
	public:
		NetworkManager();
		NetworkManager(const NetPeer& brokerPeer_in , unsigned short listen_port_in);
		virtual ~NetworkManager();

		bool	Init();
		bool	Refresh();
		bool	Term();

		unsigned short	GetListenPort() const;
		const NetPeer&	GetBroker() const;

		int	Send(const NetPeer& peerTo_in, Msg &msg_in);
		int	SendToBroker(Msg &msg_in);

		bool ADDRPCActiveList(GenericRPC* rpc);

	protected:
		std::list<GenericRPCListener*> m_RPC_ListenerList;
		std::list<GenericRPC*> m_RPC_ActifList;
		unsigned short		m_listening_port;
		NetSocket			m_socket;
		NetPeer				m_broker;
		Msg					m_message;
	};

} //namespace Shared
