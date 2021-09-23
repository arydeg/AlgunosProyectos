#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Arr
{
   T* array = NULL;
   int len;
   int cont;
};

template<typename T>
Arr<T> arr(int size) //hasta aca me lo sobrecarga solo wtf
{
   Arr<T> res;
   res.array = new T[size];
   res.len = 0;
   res.cont = size;
   return res;
}

template<typename T>
Arr<T> arr() //no lo entendi
{
   Arr<T> res = {new T[0], 0, 0};
   return res;
}

template<typename T>
int arrAdd(Arr<T>& a,T v)
{
   int pos;
   if(a.len == a.cont){
      Arr<T> b = arr<T>(a.len + 1);
      for( int i = 0; i<a.len; i++ ){
         b.array[i] = a.array[i];
         b.len++;
      }
      pos = add<T>(b.array, b.len, v);
      a = b;
   }else{
      pos = add<T>(a.array, a.len, v);
   }
   return pos;
}

template<typename T>
T* arrGet(Arr<T> a,int p)
{
   T* res = &a.array[p];
   return res;
}

template<typename T>
void arrSet(Arr<T>& a,int p,T t)
{
   a.array[p] = t;
}

template<typename T>
void arrInsert(Arr<T>& a,T v,int p)
{
   // verifico que haya lugar en en array
   if(a.len == a.cont){
      arrAdd(a,v);
      a.len--;
   }
   for(int i=a.len; i>p; i--){
      a.array[i] = a.array[i-1];
   }
   a.array[p] = v;
   a.len++;
}

template<typename T>
int arrSize(Arr<T> a)
{
   return a.len;
}

template<typename T>
T arrRemove(Arr<T>& a,int p)
{
   T res = remove(a.array, a.len, p);
   return res;
}

template<typename T>
void arrRemoveAll(Arr<T>& a)
{
   a.len = 0;
}

template<typename T,typename K>
int arrFind(Arr<T>& a,K k, int cmpTK(T,K))
{
   int res = find<T,K>(a.array, a.len, k, cmpTK);
   return res;
}

template<typename T>
int arrOrderedInsert(Arr<T>& a,T t,int cmpTT(T,T))
{
   int res = orderedInsert<T>(a.array, a.len, t, cmpTT);
   return res;
}

template<typename T>
void arrSort(Arr<T>& a,int cmpTT(T,T))
{
   sort<T>(a.array, a.len, cmpTT);
}

#endif
