#pragma once

#include "GenericRPC.h"
#include "NetPeer.h"
#include "Msg.h"

namespace Session
{
	class RegisterService : public Shared::GenericRPC
	{
	public:
		RegisterService(Shared::NetworkManager& manager_in);
		~RegisterService();

		// NetworkManager life call
		virtual bool OnInit();
		virtual bool OnUpdate();
		virtual bool OnTerm();

		virtual bool Serialize(Shared::Serializer& serializer);
		virtual bool Unserialize(Shared::Serializer& serializer);
		
		// specified RPC to implement
		virtual bool OnIncomingAnswer(const Shared::NetPeer& peerFrom_in, const Shared::Msg& answer_in) = 0;
	//private:
	};

} //namespace Session