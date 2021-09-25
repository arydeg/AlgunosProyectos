#include <iostream>
#include <string>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/tads/BitWriter.hpp"
#include "biblioteca/tads/BitReader.hpp"

int main()
{
   FILE* f = fopen("arch.bin","w+b");
   BitWriter bw = bitWriterCreate(f);
   bitWriterWrite(bw,0);
   bitWriterWrite(bw,1);
   bitWriterWrite(bw,0);
   bitWriterWrite(bw,0);
   bitWriterWrite(bw,0);
   bitWriterWrite(bw,0);
   bitWriterWrite(bw,0);
   bitWriterWrite(bw,1);

   bitWriterWrite(bw,1);
   bitWriterWrite(bw,0);
   bitWriterWrite(bw,1);
   bitWriterFlush(bw);
   fclose(f);

   FILE* f1 = fopen("arch.bin","r+b");
   BitReader br = bitReaderCreate(f1);
   int bit = bitReaderRead(br);
   while( !feof(f1) )
   {
    cout << bit;
    bit = bitReaderRead(br);
   }
   fclose(f1);

   return 0;
}
