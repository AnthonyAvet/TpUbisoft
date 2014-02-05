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

	bool	NetworkManager::Init()
	{
		m_socket = Shared::NetSocket();
		return m_socket.Bind(m_listening_port);
	}
	
	bool	NetworkManager::Refresh()
	{
		return false;
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
} // namespace Shared
