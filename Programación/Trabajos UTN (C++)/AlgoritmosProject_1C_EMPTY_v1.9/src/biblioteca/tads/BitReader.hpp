#ifndef _TBITREADER_T_
#define _TBITREADER_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

struct BitReader
{
   FILE* file;
   unsigned char charActual;
   int nextBit;
};

BitReader bitReaderCreate(FILE* f){
   BitReader res;
   res.file=f;
   res.charActual='0';
   res.nextBit=0;
   return res;
}

//agrege &
int bitReaderRead(BitReader& bw)
{
   if(bw.nextBit==0){
      bw.charActual = read<unsigned char>(bw.file);
   }
   if(bw.nextBit>7){
      bw.charActual = read<unsigned char>(bw.file);
      bw.nextBit=0;
   }
   unsigned char c = bw.charActual;
   c = c << bw.nextBit;
   c = c >> 7;

   bw.nextBit++;
   int res = c;
   return res;
}

#endif
