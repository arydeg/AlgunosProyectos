#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> T read(FILE* f)
{
   T res;
   fread(&res,sizeof(T),1,f);
   return res;
}

template<typename T> void write(FILE* f, T v)
{
   fwrite(&v,sizeof(T),1,f);
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,sizeof(T)*n,SEEK_SET);
}

template<typename T> long fileSize(FILE* f)
{
   int actual = ftell(f);
   fseek(f,0,SEEK_END);
   int res = ftell(f)/sizeof(T);
   fseek(f,actual,SEEK_SET);
   return res;
}

template<typename T> long filePos(FILE* f)
{
   long res = ftell(f)/sizeof(T);
   return res;
}

#endif
