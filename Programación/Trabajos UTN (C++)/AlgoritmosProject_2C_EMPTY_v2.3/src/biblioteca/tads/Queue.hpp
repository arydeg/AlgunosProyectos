#ifndef _TQUEUETAD
#define _TQUEUETAD
#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
   Node<T>* qn;
   int size;
};

template<typename T>
Queue<T> queue()
{
   Queue<T> q;
   Node<T>* r = NULL;
   q.qn = r;
   q.size=0;
   return q;
}

template<typename T>
T* queueEnqueue(Queue<T>& q,T v)
{
   Node<T>* r = enqueue(q.qn,v);
   T* res = &(r->info);
   q.size++;
   return res;
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
   T res = removeFirst<T>(q.qn);
  q.size--;
   return res;
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
   return q.size!=0?false:true;
}

// no esta en la guia
//template<typename T>
//void queueUndequeue(Queue<T> q)
//{
//}

template<typename T>
int queueSize(Queue<T> q)
{
   return q.size;
}

#endif
