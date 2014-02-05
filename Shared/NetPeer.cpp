//**********************************************************************************************************************
#include "NetPeer.h"
#include "winsock.h"

namespace Shared
{
	
	NetPeer::NetPeer()
	{

	}
	NetPeer::NetPeer(unsigned int  ip_in, unsigned short port_in)
	{
		m_IpAddress = ip_in;
		m_PortNumber = port_in;
	}
	NetPeer::NetPeer(const char* hostname_in,  unsigned short port_in)
	{
		m_IpAddress = inet_addr(hostname_in);
		m_PortNumber = port_in;
	}
	NetPeer::NetPeer(const NetPeer &other)
	{
		m_IpAddress = other.m_IpAddress;
		m_PortNumber = other.m_PortNumber;
	}

	unsigned int		NetPeer::GetIPAddress() const
	{
		return m_IpAddress;
	}
	unsigned short		NetPeer::GetPortNumber() const
	{
		return m_PortNumber;
	}
	void				NetPeer::SetIPAddress(unsigned int ipaddress)
	{
		m_IpAddress = ipaddress;
	}
	void				NetPeer::SetPortNumber(unsigned short port)
	{
		m_PortNumber = port;
	}

	bool				NetPeer::IsValid() const
	{
		return false;
	}

	NetPeer &			NetPeer::operator=(const NetPeer& other)
	{
		m_IpAddress = other.m_IpAddress;
		m_PortNumber = other.m_PortNumber;

		return *this;
	}
	bool				NetPeer::operator==(const NetPeer& other)
	{
		if(m_IpAddress == other.m_IpAddress && m_PortNumber == other.m_PortNumber)
			return true;
		return false;
	}
} //namespace Shared
