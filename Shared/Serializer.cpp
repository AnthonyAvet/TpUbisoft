//**********************************************************************************************************************
#include "Serializer.h"

namespace Shared
{
	
	// Passing pbuffer_in  will cause a dynamic allocation strategy
	Serializer::Serializer(const char* pbuffer_in, size_t buffer_size_in){
		_bufferSize = buffer_size_in;
		_cursor = 0;
		*_buffer = *pbuffer_in;
	}

	// Pre-allocate a dynamic buffer
	Serializer::Serializer(size_t buffer_size_in){
		_bufferSize = buffer_size_in;
		_buffer = new char[_bufferSize];
		_cursor = 0;
	}

	Serializer::~Serializer(){
	
	}

	// C Fundamental  types operations
	void Serializer::operator << (char val_in){
		_buffer[_cursor++] = val_in;
	}
	void Serializer::operator << (netS8 val_in){
		_buffer[_cursor++] = val_in;
	}
	void Serializer::operator << (netU8 val_in){
		_buffer[_cursor++] = val_in;
	}

	void Serializer::operator << (netS16 val_in){
		if(_cursor+2<_bufferSize){
			char* tab = (char*) &val_in;
			if(isBigIndian())
			{
				_buffer[_cursor++] = tab[0];
				_buffer[_cursor++] = tab[1];
			}else{
				_buffer[_cursor++] = tab[1];
				_buffer[_cursor++] = tab[0];
			}
		}

	}
	void Serializer::operator << (netU16 val_in){
		if(_cursor+2<_bufferSize){
			char* tab = (char*) &val_in;
			if(isBigIndian())
			{
				_buffer[_cursor++] = tab[0];
				_buffer[_cursor++] = tab[1];
			}else{
				_buffer[_cursor++] = tab[1];
				_buffer[_cursor++] = tab[0];
			}
		}
	}

	void Serializer::operator << (netS32 val_in){
		if(_cursor+4<_bufferSize){
			char* tab = (char*) &val_in;
			if(isBigIndian())
			{
				_buffer[_cursor++] = tab[0];
				_buffer[_cursor++] = tab[1];
				_buffer[_cursor++] = tab[2];
				_buffer[_cursor++] = tab[3];
			}else{
				_buffer[_cursor++] = tab[3];
				_buffer[_cursor++] = tab[2];
				_buffer[_cursor++] = tab[1];
				_buffer[_cursor++] = tab[0];
			}
		}
	}
	void Serializer::operator << (netU32 val_in){
		if(_cursor+4<_bufferSize){
			char* tab = (char*) &val_in;
			if(isBigIndian())
			{
				_buffer[_cursor++] = tab[0];
				_buffer[_cursor++] = tab[1];
				_buffer[_cursor++] = tab[2];
				_buffer[_cursor++] = tab[3];
			}else{
				_buffer[_cursor++] = tab[3];
				_buffer[_cursor++] = tab[2];
				_buffer[_cursor++] = tab[1];
				_buffer[_cursor++] = tab[0];
			}
		}
	}

	/*void Serializer::operator << (const Serializer& val_in){
		char inter;
		for(int i=0;i<val_in._bufferSize<i++)
		{
			val_in >> inter >> _buffer[_cursor];
			_cursor++;
		}
	}*/

	void Serializer::operator >> (char &val_out){
		if(_cursor <= _bufferSize)
		{
			val_out = _buffer[_cursor++];
			
		}
	}
	void Serializer::operator >> (netS8 & val_out){
		if(_cursor < _bufferSize)
		{
			val_out = _buffer[_cursor++];
		}
	}


	void Serializer::operator >> (netU8 & val_out){
		if(_cursor < _bufferSize)
		{
			val_out = _buffer[_cursor++];
		}
	}

	void Serializer::operator >> (netS16 & val_out){
		if(_cursor+2<= _bufferSize){
			char* tab = (char*) &val_out;
			if(isBigIndian())
			{
				tab[0] = _buffer[_cursor++];
				tab[1] = _buffer[_cursor++];
			}else{
				tab[1] = _buffer[_cursor++];
				tab[0] = _buffer[_cursor++];
			}
		}
	}


	void Serializer::operator >> (netU16 & val_out){
		if(_cursor+2<=_bufferSize){
			char* tab = (char*) &val_out;
			if(isBigIndian())
			{
				tab[0] = _buffer[_cursor++];
				tab[1] = _buffer[_cursor++];
			}else{
				tab[1] = _buffer[_cursor++];
				tab[0] = _buffer[_cursor++];
			}
		}
	}

	void Serializer::operator >> (netS32 & val_out){
		if(_cursor+4<=_bufferSize){
			char* tab = (char*) &val_out;
			if(isBigIndian())
			{
				tab[0] = _buffer[_cursor++];
				tab[1] = _buffer[_cursor++];
				tab[2] = _buffer[_cursor++];
				tab[3] = _buffer[_cursor++];
			}else{
				tab[3] = _buffer[_cursor++];
				tab[2] = _buffer[_cursor++];
				tab[1] = _buffer[_cursor++];
				tab[0] = _buffer[_cursor++];
			}
		}
	}


	void Serializer::operator >> (netU32 & val_out){
		if(_cursor+4<=_bufferSize){

			char* tab = (char*) &val_out;

			if(isBigIndian())
			{
				tab[0] = _buffer[_cursor++];
				tab[1] = _buffer[_cursor++];
				tab[2] = _buffer[_cursor++];
				tab[3] = _buffer[_cursor++];
			}else{
				tab[3] = _buffer[_cursor++];
				tab[2] = _buffer[_cursor++];
				tab[1] = _buffer[_cursor++];
				tab[0] = _buffer[_cursor++];
			}
		}
	}
	
	/*void Serializer::operator >> (Serializer& val_out){
			_cursor--;
			val_out = _buffer[_cursor];
	}*/

	bool Serializer::isBigIndian()
	{
		int test = 0xA1256;
		unsigned char* p = (unsigned char*) &test;
		return p[0] != 0xA1;
	}

	void Serializer::resetIndex()
	{
		_cursor = 0;
	}
} // namespace Shared
