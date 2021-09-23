#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T> struct Node
{
   T info;
   Node<T>* sig;
};

template <typename T> Node<T>* add(Node<T>*& p, T x)
{
   // creo un nuevo nodo
   Node<T>* nuevo = new Node<T>();
   nuevo->info = x;
   nuevo->sig = NULL;
   // la lista ya existe?
   if( p!=NULL )
   {
      // busco el ultimo
      Node<T>* aux = p;
      while( aux->sig!=NULL )
      {
         aux = aux->sig;
      }
      // enlazo el nuevo nodo
      aux->sig = nuevo;
   }
   else
   {
      // nuevo es el primero
      p = nuevo;
   }
   return nuevo;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p, K v, int cmpTK(T,K) )
{
   Node<T>* aux = p;
   while( aux!=NULL && cmpTK(aux->info,v)!=0 ){
      aux = aux->sig;
   }
   if( aux==NULL ){
      return NULL;
   }else{
      return aux;
   }
   return NULL;
}

//modificado el void
template <typename T, typename K>
T remove(Node<T>*& p, K v, int cmpTK(T,K))
{
   Node<T>* aux = p;
   Node<T>* ant = NULL;
   while( aux!=NULL && cmpTK(aux->info,v)!=0 ){
      ant = aux;
      aux = aux->sig;
   }
   if( ant==NULL ){
      p = aux->sig;
   }else{
      ant->sig = aux->sig;
   }
   T res = aux->info;
   delete aux;
   return res;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   //modo sin verificar si la list esta vacia
   Node<T>* aux = p->sig;
   T res = p->info;
   delete p;
   p = aux;
   return res;

//   //si la lista esta vacia
//      Node<T>* aux = p->sig;
//   if(p!=NULL){
//      delete p;
//      p = aux;
//      T res = p->info;
//      return res;
//   }
//   else{
//      return NULL;   //error no puedo devolver null
//   }
}

template <typename T> void free(Node<T>*& p)
{
   Node<T>* aux = NULL;
   while(p!=NULL){
      aux = p->sig;
      delete p;
      p = aux;
   }
}

template <typename T>
void insertFirst(Node<T>*& p, T v)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = v;
   nuevo->sig = NULL;

   if(p != NULL){
      nuevo->sig = p;
   }

   p = nuevo;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T v, int cmpTT(T,T) )
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = v;
   Node<T>* ant=NULL;
   Node<T>* aux=p;
   while( aux!=NULL && cmpTT(p->info,v)<0){
      ant = aux;
      aux = aux->sig;
   }
   if( ant==NULL ){
      nuevo->sig = p;
      p = nuevo;
   }else{
      ant->sig = nuevo;
      if( aux==NULL ){
         nuevo->sig = NULL;
      }else{
         nuevo->sig = aux;
      }
   }
   return nuevo;
}

//creo funcion
template <typename T>
Node<T>* searchAndInsert(Node<T>*& p ,T e ,bool& enc ,int cmpTT(T,T)){
   Node<T>* f = find<T,T>(p,e,cmpTT);
   if(f == NULL){
      Node<T>* r = orderedInsert<T>(p,e,cmpTT);
      enc = false;
      return r;
   }else{
      enc = true;
      return f;
   }
}

template <typename T>
void sort(Node<T>*& p, int cmpTT(T,T)) // funca pero hay q eliminar
{
   Node<T>* aux = p;
   Node<T>* ord = NULL;
   while(aux!=NULL){
      orderedInsert<T>(ord,aux->info,cmpTT);
      aux = aux->sig;
   }
   free<T>(p);
   p = ord;
}

template <typename T> bool isEmpty(Node<T>* p)
{
   if(p!=NULL){
      return false;
   }else{
      return true;
   }
}

template <typename T> void push(Node<T>*& p, T v)
{
   Node<T>* nuevo = new Node<T>;
   nuevo->info = v;
   nuevo->sig = p;
   p = nuevo;
}

template <typename T> T pop(Node<T>*& p)
{
   T res = removeFirst<T>(p);
   return res;
}

//modificado el retorno
template <typename T>
Node<T>* enqueue(Node<T>*& p, Node<T>*& q, T v)
{
   Node<T>* nue = new Node<T>;
   nue->info = v;
   nue->sig = NULL;
   if(!isEmpty(p)){
      q->sig = nue;
   }else{
      p = nue;
   }
   q = nue;
   return q;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e){
   Node<T>* nue = new Node<T>;
   nue->info = e;
   nue->sig = NULL;
   Node<T>* res = add<T>(q, e);
   return res;
}

//template <typename T>
//void enqueue(Node<T>*& p, Node<T>*& q, T v)
//{
//   Node<T>* nue = new Node<T>;
//   nue->info = v;
//   nue->sig = NULL;
//   if(!isEmpty(p)){
//      Node<T>* aux = p;
//      while( aux!=NULL ){
//         aux = aux->sig;
//      }
//      aux->sig = nue;
//   }else{
//      p = nue;
//   }
//}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T res = pop<T>(p);
   return res;
}

template <typename T>
T dequeue(Node<T>*& q){
   Node<T>* aux = q->sig;
   q->sig = aux->sig;
   T ret = aux->info;
   if( aux==q ){
   q = NULL;
   }
   delete aux;
   return ret;
}


#endif
