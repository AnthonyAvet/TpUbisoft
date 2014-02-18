#pragma once

#include "NetPeer.h"
#include "NetworkManager.h"
#include "Msg.h"

namespace Shared
{
	//**********************************************************************************************************************
	class IncomingQuery
	{
	public:
		IncomingQuery();
		NetPeer& GetFrom();

		bool Reply(Msg &content_in);

	protected:
		NetPeer 			m_peerFrom;

	};

	//**********************************************************************************************************************
	class GenericRPCListener
	{
	public:
		GenericRPCListener(NetworkManager* manager);
		virtual bool OnIncomingQuery(NetPeer& from, Msg& message);
		virtual bool OnInit();
		virtual bool OnUpdate();
		virtual bool OnTerm();

	protected:
		NetworkManager* m_NManager;
	};

} //namespace Shared