#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
   Node<T>* n;
   int size,next;
};

template<typename T>
List<T> listCreate()
{
   List<T> res;
   Node<T>* r = NULL;
   res.n = r;
   res.size =0;
   res.next =0;
   return res;
}

template<typename T>
List<T> listAdd(List<T>& lst,T v)
{
   Node<T>* res = add<T>(lst.n, v);
   List<T> r;
   r.n = res;
   lst.size++;
   return r;
}

template<typename T,typename K>
T listRemove(List<T>& lst,K k, int cmpTK(T,K))
{
   T res = remove<T>(lst.n, k, cmpTK);
   lst.size--;
   return res;
}

template <typename T, typename K>
T* listFind(List<T> lst, K k, int cmpTK(T, K))
{
//   Node<T>* dir = find<T>(lst.p,k,cmpTK);
//   T* ret;
//   if( dir==NULL )
//   {
//      ret = NULL;
//   }
//   else
//   {
//      ret = &(dir->info);
//   }

   T* ret;

   return ret;
}

template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
   Node<T>* res = orderedInsert<T>(lst.n, t,cmpTT);
   lst.size++;
   return res;
}

template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
   sort<T>(lst.n, cmpTT);
}

template<typename T>
bool listHasNext(List<T>& lst)
{
   if(lst.size != lst.next){
      return true;
   }else{
      return false;
   }
}

template<typename T>
bool listIsEmpty(List<T> lst)
{
   return lst.size!=0?false:true;
}

template<typename T>
int listSize(List<T> lst){
   return lst.size;
}

template<typename T>
T* listNext(List<T>& lst)
{
   List<T> res = lst;
   for(int i=0; i<lst.next; i++){
      res.n = res.n->sig;
   }
   T* r = &(res.n->info);
   lst.next++;
   return r;
}

template<typename T>
void listReset(List<T>& lst)
{
   lst.next = 0;
}

template<typename T>
void listFree(List<T>& lst)
{
   free<T>(lst.n);
}

#endif
