#ifndef _TBITWRITER_T_
#define _TBITWRITER_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

struct BitWriter
{
   FILE* file;
   unsigned char charActual;
   int nextBit;
};

BitWriter bitWriterCreate(FILE* f){
   BitWriter res;
   res.file=f;
   res.charActual='0';
   res.nextBit=0;
   return res;
}

//agrege &
void bitWriterWrite(BitWriter& bw,int bit)
{
   char mask = bit;
   if(bw.nextBit<8){
      bw.charActual = bw.charActual<<1;
      bw.charActual = bw.charActual|mask;
      bw.nextBit++;
   }
   if(bw.nextBit==8){
      write<unsigned char>(bw.file,bw.charActual);
      bw.nextBit=0;
      bw.charActual='0';
   }

}

void bitWriterFlush(BitWriter bw){
   if(bw.nextBit<8){
      int flush = 8 - bw.nextBit;
      bw.charActual = bw.charActual<<flush;
   }
   write<unsigned char>(bw.file,bw.charActual);
   bw.nextBit=0;
   bw.charActual='0';
}

#endif
