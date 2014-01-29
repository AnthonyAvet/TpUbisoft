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
	*ser << 'C';

	char testChar;
	int	 testint;
	char testChar1;

	ser->resetIndex();

	*ser >> testChar;
	*ser >> (int)testint;
	*ser >> testChar1;

	printf ("Characters: %c %d %c \n", testChar, testint, testChar1);

	system("PAUSE");

	return 0;
}