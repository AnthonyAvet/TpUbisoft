//**********************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>

#include "Broker.h"
#include "NetPeer.h"
#include "Serializer.h"

int main(void)
{
	//Shared::NetPeer();

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

	system("PAUSE");

	return 0;
}