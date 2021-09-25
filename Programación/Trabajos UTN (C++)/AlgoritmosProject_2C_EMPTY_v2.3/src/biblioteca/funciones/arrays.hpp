#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T> int add(T arr[], int& len, T v)
{
   arr[len] = v;
   len++;
   return len-1;
}

template <typename T>
void insert(T arr[], int& len, T v, int pos)
{
   for(int i=len; i>pos; i--){
      arr[i] = arr[i-1];
   }
   arr[pos] = v;
   len++;
   return;
}

template <typename T>
T remove(T arr[], int& len, int pos)
{
   T res = arr[pos];
   for( int i = pos; i<len-1; i++ ){
      arr[i] = arr[i+1];
   }
   len--;
   return res;
}

template <typename T, typename K>
int find(T arr[], int len, K v, int cmpTK(T,K))
{
   int i=0;
    while( i<len && cmpTK(arr[i],v)!=0 ){
       i++;
    }
    return i==len?-1:i;
}

template <typename T>
int orderedInsert(T arr[], int& len, T v, int cmpTT(T,T))
{
   int pos = 0;
   while( pos<len && cmpTT(arr[pos],v)<0 ){
      pos++;
   }
   insert<T>(arr, len, v, pos);
   return pos;
}
template <typename T>
void sort(T arr[], int len, int cmpTT(T,T)){
   T a[len];
   int len2 = 0;
   for( int i = 0; i<len; i++ ){
      orderedInsert<T>(a, len2, arr[i], cmpTT);
   }
   for( int i = 0; i<len2; i++ ){
      arr[i] = a[i];
   }
}


#endif
