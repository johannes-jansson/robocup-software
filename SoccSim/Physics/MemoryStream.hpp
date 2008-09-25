#ifndef _MEMORYSTREAM_HPP_
#define _MEMORYSTREAM_HPP_

#include <NxPhysics.h>
#include <NxStream.h>

#include <vector>
#include <stdint.h>

class MemoryStream : public NxStream
{
    public:
        MemoryStream();
        virtual ~MemoryStream();

        virtual NxU8 readByte() const;
        virtual NxU16 readWord() const;
        virtual NxU32 readDword() const;
        virtual float readFloat() const;
        virtual double readDouble() const;
        virtual void readBuffer(void* buffer, NxU32 size) const;

        virtual NxStream& storeByte(NxU8 b);
        virtual NxStream& storeWord(NxU16 w);
        virtual NxStream& storeDword(NxU32 d);
        virtual NxStream& storeFloat(NxReal f);
        virtual NxStream& storeDouble(NxF64 f);
        virtual NxStream& storeBuffer(const void* buffer, NxU32 size);
        
    private:
        template <typename T>
        T read() const
        {
            T res = 0;
            memcpy(&res, &_data[_readLoc], sizeof(T));
            _readLoc += sizeof(T);
            
            return res;
        }
        
    private:
        mutable std::vector<uint8_t> _data;
        mutable unsigned int _readLoc;
};

#endif /* _MEMORYSTREAM_HPP_ */