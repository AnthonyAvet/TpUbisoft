//**********************************************************************************************************************
#pragma once

namespace Shared
{
	//**********************************************************************************************************************
	class  Serializer
	{
	public:

		typedef signed char netS8; 
		typedef unsigned char netU8; 
		typedef unsigned short netU16; 
		typedef signed short netS16; 
		typedef unsigned int netU32; 
		typedef signed int netS32; 
		typedef unsigned long netU64; 
		typedef signed long netS64; 


		// Passing pbuffer_in  will cause a dynamic allocation strategy
		Serializer(const char* pbuffer_in = 0, size_t buffer_size_in = 0);
	
		// Pre-allocate a dynamic buffer
		Serializer(size_t buffer_size_in);

		virtual ~Serializer();
		
		void resetIndex();

		// C Fundamental  types operations
		void operator << (char val_in);
		void operator << (netS8 val_in);
		void operator << (netU8 val_in);
		void operator << (netS16 val_in);
		void operator << (netU16 val_in);
		void operator << (netS32 val_in);
		void operator << (netU32 val_in);
		void operator << (netS64 val_in);
		void operator << (netU64 val_in);
		void operator << (const Serializer& val_in);

		void operator >> (char &val_out);
		void operator >> (netS8 &val_out);
		void operator >> (netU8 &val_out);
		void operator >> (netS16 &val_out);
		void operator >> (netU16 &val_out);
		void operator >> (netS32 &val_out);
		void operator >> (netU32 &val_out);
		void operator >> (netS64 val_in);
		void operator >> (netU64 val_in);
		void operator >> (Serializer & val_out);

		int getBufferSize() {return _cursor;} ;

	protected:
		char* _buffer;
		size_t _bufferSize;
		int _cursor;
	private:
		bool isBigIndian();
	};

} //namespace Shared
