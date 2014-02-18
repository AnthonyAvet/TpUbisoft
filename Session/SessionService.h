//**********************************************************************************************************************
#pragma once

#include "NetworkManager.h"
#include "NetPeer.h"
#include "Msg.h"
#include "Serializer.h"

namespace Session
{
	//**********************************************************************************************************************
	class SessionService : public Shared::GenericRPCListener
	{
	public:
		SessionService(Shared::NetworkManager* manager);
		~SessionService();

		// GenericRPCListener interface override
		bool OnIncomingQuery(Shared::NetPeer& from, Shared::Msg& message);
		bool OnInit();
		bool OnUpdate();
		bool OnTerm();
	};

} //namespace Session
