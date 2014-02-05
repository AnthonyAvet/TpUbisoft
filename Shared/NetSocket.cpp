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

		bind(m_socket,(sockaddr*) &addr, 0);
		return false;
	}
	bool	NetSocket::Close()
	{
		closesocket(m_socket);

		return false;
	}
	bool	NetSocket::IsReadable(long time_msec_in)
	{
		return false;
	}
	bool	NetSocket::IsWritable(long time_msec_in)
	{
		return false;
	}

	bool	NetSocket::Read(NetPeer &peerFrom_out, Msg& msg_out)
	{
		sockaddr_in addr;
		int fromlen = sizeof addr;
		recvfrom(m_socket,msg_out.GetBuffer(), (int) msg_out.GetBufferCapacity(), 0, (sockaddr*) &addr, &fromlen);

		peerFrom_out.SetIPAddress(addr.sin_addr.s_addr);
		peerFrom_out.SetPortNumber(addr.sin_port);
		return false;
	}
	bool	NetSocket::Send(const NetPeer& peerTo_in, const Msg& msg_in)
	{
		_SendTo(peerTo_in.GetIPAddress(), peerTo_in.GetPortNumber(), msg_in.GetBuffer(), msg_in.GetBufferSize());
		
		return false;
	}
	
	int		NetSocket::_SendTo (unsigned int ip_addr_in, unsigned short port_in,const char* buffer_in, size_t buffer_size_in)
	{
			sockaddr_in addr;
			addr.sin_addr.s_addr = ip_addr_in;
			addr.sin_family = AF_INET;
			addr.sin_port = htons(port_in);

			return sendto(m_socket,  buffer_in, buffer_size_in, 0, (sockaddr*) &addr, sizeof addr);
	}
} //namespace Shared
