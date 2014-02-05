//**********************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>

#include "Broker.h"
#include "NetPeer.h"
#include "NetSocket.h"
#include "Msg.h"
#include "Serializer.h"

int main(void)
{
	//Shared::NetPeer();
	/*
	Shared::Serializer* ser = new Shared::Serializer(56);

	*ser << 'A';
	*ser << (int)16;
	*ser << (short)160;
	*ser << 'C';

	char testChar;
	int	 testint;
	short testshort;
	char testChar1;

	ser->resetIndex();

	*ser >> testChar;
	*ser >> (int)testint;
	*ser >> (short)testshort;
	*ser >> testChar1;

	printf ("Characters: %c %d %c %d\n", testChar, testint, testChar1, testshort);

	system("PAUSE");*/
	Shared::NetSocket* sock = new Shared::NetSocket();
	sock->Bind(4242);
	Shared::NetPeer* net = new Shared::NetPeer("10.7.244.201", 21);
	Shared::Msg* msg = new Shared::Msg();
	sock->Send(*net, *msg);

	//sock->Read(*net, *msg);

	system("PAUSE");

	return 0;
}