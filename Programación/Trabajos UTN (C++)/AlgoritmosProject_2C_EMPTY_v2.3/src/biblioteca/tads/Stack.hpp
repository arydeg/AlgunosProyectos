#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
   Node<T>* s;
   int size;
};

template<typename T>
Stack<T> stack()
{
   Stack<T> st;
   Node<T>* r = NULL;
   st.s = r;
   st.size=0;
   return st;
}

template<typename T>
T* stackPush(Stack<T>& st,T v)
{
   push<T>(st.s, v);
   T* res = &(st.s->info);
   st.size++;
   return res;
}

template<typename T>
T stackPop(Stack<T>& st)
{
   T res = pop<T>(st.s);
   st.size--;
   return res;
}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return st.size!=0?false:true;
}

template<typename T>
int stackSize(Stack<T> st)
{
   return st.size;
}

#endif
