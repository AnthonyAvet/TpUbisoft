//**********************************************************************************************************************
#include "GenericRPC.h"
#include "NetworkManager.h"

namespace Shared
{

	GenericRPC::GenericRPC(NetworkManager& manager_in){
		m_networkManager = manager_in;
	}

	GenericRPC::~GenericRPC(){
	}

	bool GenericRPC::Invoke(const char* servicename_in){
		// send on broker to know service's address
		// call Invoke with Peer which is build with service address
	}

	bool GenericRPC::Invoke(const NetPeer& peerTo_in){
		Msg message;
		Shared::Serializer serialize = Shared::Serializer(message.GetBuffer(),message.GetBufferCapacity());
		m_IN->Serialize(serialize);
		m_networkManager.ADDRPCActiveList(this);
		return m_networkManager.Send(peerTo_in,message);
	}

} //namespace Shared
