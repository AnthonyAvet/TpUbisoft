//**********************************************************************************************************************
#include "NetSocket.h"

namespace Shared
{
	NetSocket::NetSocket()
	{
		m_socket = socket(AF_INET,SOCK_DGRAM,0);
	}
	NetSocket::~NetSocket(){}

	bool	NetSocket::Bind(unsigned short port_in)
	{
		sockaddr_in addr;
		addr.sin_addr.s_addr = INADDR_ANY;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port_in);

		int retour = bind(m_socket,(sockaddr*) &addr, sizeof(addr));
		if(retour != SOCKET_ERROR)
			return true;
		return false;
	}
	bool	NetSocket::Close()
	{
		int retour = closesocket(m_socket);
		if(retour != SOCKET_ERROR)
			return true;
		return false;
	}

	bool	NetSocket::IsReadable(long time_msec_in)
	{
		fd_set set;
		FD_ZERO(&set);
		FD_SET(m_socket,&set);
		if(select(m_socket,&set,NULL,NULL,(timeval*) time_msec_in) >= 0)
		{
			if(FD_ISSET(m_socket,&set)>0)
			{
				return true;
			}
		}
		return false;
	}

	bool	NetSocket::IsWritable(long time_msec_in)
	{
		fd_set set;
		FD_ZERO(&set);
		FD_SET(m_socket,&set);
		if(select(m_socket,&set,NULL,NULL,(timeval*) time_msec_in) >= 0)
		{
			if(FD_ISSET(m_socket,&set)>0)
			{
				return true;
			}
		}
		return false;
	}

	bool	NetSocket::Read(NetPeer &peerFrom_out, Msg& msg_out)
	{
		sockaddr_in addr;
		int fromlen = sizeof addr;
		int retour = recvfrom(m_socket,msg_out.GetBuffer(), (int) msg_out.GetBufferCapacity(), 0, (sockaddr*) &addr, &fromlen);

		peerFrom_out.SetIPAddress(addr.sin_addr.s_addr);
		peerFrom_out.SetPortNumber(addr.sin_port);
		if(retour >= 0)
			return true;
		return false;
	}
	bool	NetSocket::Send(const NetPeer& peerTo_in, const Msg& msg_in)
	{
		int retour = _SendTo(peerTo_in.GetIPAddress(), peerTo_in.GetPortNumber(), msg_in.GetBuffer(), msg_in.GetBufferSize());
		if(retour >= 0)
			return true;
		return false;
	}
	
	int		NetSocket::_SendTo (unsigned int ip_addr_in, unsigned short port_in,const char* buffer_in, size_t buffer_size_in)
	{
			sockaddr_in addr;
			addr.sin_addr.s_addr = ip_addr_in;
			addr.sin_family = AF_INET;
			addr.sin_port = htons(port_in);

			int retour = sendto(m_socket,  buffer_in, buffer_size_in, 0, (sockaddr*) &addr, sizeof(addr));
			if(retour >= 0)
				return true;
			return false;
	}
} //namespace Shared
