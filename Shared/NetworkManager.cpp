//**********************************************************************************************************************
#include "NetworkManager.h"

namespace Shared
{
	NetworkManager::NetworkManager(const NetPeer& brokerPeer_in , unsigned short listen_port_in)
	{
		m_broker = brokerPeer_in;
		m_listening_port = listen_port_in;

		this->Init();
	}

	NetworkManager::~NetworkManager()
	{
	}

	NetworkManager::NetworkManager()
	{
	}

	bool	NetworkManager::Init()
	{
		m_message = Shared::Msg();
		m_socket = Shared::NetSocket();
		return m_socket.Bind(m_listening_port);
	}
	
	bool	NetworkManager::Refresh()
	{
		NetPeer	m_sender = NetPeer();

		while(m_socket.IsReadable(100))
		{
			m_socket.Read(m_sender, m_message);

			for(std::list<GenericRPCListener*>::iterator it = m_RPC_ListenerList.begin(); it != m_RPC_ListenerList.end(); ++it)
			{
				if ((*it)->OnIncomingQuery(m_sender, m_message))
				{
					break;
				}
			}
		}

		for (std::list<GenericRPC*>::iterator it = m_RPC_ActifList.begin(); it != m_RPC_ActifList.end(); ++it)
		{
			if ((*it)->OnUpdate())
			{
			}
		}

		return true;
	}
	bool	NetworkManager::Term()
	{
		return m_socket.Close();
	}
	
	unsigned short	NetworkManager::GetListenPort() const
	{
		return m_listening_port;
	}

	const NetPeer&	NetworkManager::GetBroker() const
	{
		return m_broker;
	}

	int	NetworkManager::Send(const NetPeer& peerTo_in, Msg &msg_in)
	{
		return m_socket.Send(peerTo_in,msg_in);
	}

	int	NetworkManager::SendToBroker(Msg &msg_in)
	{
		return m_socket.Send(m_broker,msg_in);
	}

	bool NetworkManager::ADDRPCActiveList(GenericRPC* rpc)
	{
		std::list<GenericRPC*>::iterator it = std::find(m_RPC_ActifList.begin(), m_RPC_ActifList.end(), &rpc);
		if (it != m_RPC_ActifList.end())
		{
			return false;
		}

		m_RPC_ActifList.push_back(rpc);
		return true;
	}
} // namespace Shared
