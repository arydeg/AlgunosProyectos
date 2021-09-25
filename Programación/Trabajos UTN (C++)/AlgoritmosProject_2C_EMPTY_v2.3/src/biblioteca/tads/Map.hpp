
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Arr.hpp"

using namespace std;

template<typename K,typename T>
struct Map
{
   Arr<K> key;
   Arr<T> value;
   int nextKey;
};

template<typename K>
int cmpKK(K k1, K k2){
   return k1==k2?0:k1>k2?1:-1;
}

template<typename K,typename T>
Map<K,T> map()
{
   Map<K,T> m = {arr<K>(),arr<T>(),0};
   return m;
}

template<typename K,typename T>
T* mapGet(Map<K,T>& m,K k)
{
   int posKey = arrFind<K,K>(m.key, k, cmpKK);
   if(posKey >= 0){
      return arrGet<T>(m.value, posKey);
   }else{
      return NULL;
   }
}

template<typename K,typename T>
T* mapPut(Map<K,T>& m,K k,T v)
{
   int posKey = arrFind<K,K>(m.key, k, cmpKK);
   if(posKey >= 0){
      arrSet<T>(m.value, posKey, v);
   }else{
      arrAdd<K>(m.key, k);
      arrAdd<T>(m.value, v);
   }
   return arrGet<T>(m.value, posKey);
}

template<typename K,typename T>
bool mapContains(Map<K,T>& m,K k)
{
   int posKey = arrFind<K,K>(m.key, k, cmpKK);
   return posKey>=0?true:false;
}

template<typename K,typename T>
T mapRemove(Map<K,T>& m,K k)
{
   int posKey = arrFind<K,K>(m.key, k, cmpKK);
   T res = arrRemove<T>(m.value,posKey);
   arrRemove<K>(m.key,posKey); //tira error
   return res;
}

template<typename K,typename T>
void mapRemoveAll(Map<K,T>& m)
{
   arrRemoveAll<K>(m.key);
   arrRemoveAll<T>(m.value);
}

template<typename K,typename T>
int mapSize(Map<K,T> m)
{
   return arrSize(m.keys);
}

template<typename K,typename T> bool mapHasNext(Map<K,T>& m)
{
   return m.nextKey<(arrSize<K>(m.key));
}

template<typename K,typename T> K mapNextKey(Map<K,T>& m)
{
   K* res = arrGet<K>(m.key,m.nextKey);
   m.nextKey++;
   return *res;
}

template<typename K,typename T> T* mapNextValue(Map<K,T>& m)
{
   T* res = arrGet<T>(m.value,m.nextKey);
   m.nextKey++;
   return res;
}


template<typename K,typename T> void mapReset(Map<K,T>& m)
{
   m.nextKey = 0;
}

template<typename K,typename T> void mapSortByKeys(Map<K,T>& m,int cmpKK(K,K))
{
   arrSort<K>(m.key, cmpKK);
}

template<typename K,typename T> void mapSortByValues(Map<K,T>& m,int cmpTT(T,T))
{
   arrSort<T>(m.value, cmpTT);
}

#endif
