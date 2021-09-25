#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll
{
   string s;
   char sep;
   int next;
};

template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep=s[0];
   c.s=substring(s,1);
   return c;
}

int cmpIntInt(int t,int k){
   return t-k;
}
int cmpIntString(int t,string k){
   return t-stringToInt(k);
}
int cmpStringInt(string t,int k){
   return stringToInt(t)-k;
}
int cmpStringString(string t,string k){
   return t==k?0:-1;
}

// collCreate
template<typename T>
Coll<T> collCreate()
{
   Coll<T> x;
   x.sep = '|';
   x.next=0;
   return x;
}

template<typename T>
Coll<T> collCreate(char c)
{
   Coll<T> x;
   x.sep = c;
   x.next=0;
   return x;
}


template<typename T>
int collSize(Coll<T> c)
{
   return tokenCount(c.s,c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s="";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.s,c.sep,p);
}


// -- [GENERICAS] --

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   addToken(c.s,c.sep,tToString(t));
   return collSize(c);
}

template <typename T>
void collSetAt(Coll<T>& c,T t, int p, string tToString(T))
{
   setTokenAt(c.s,c.sep,tToString(t),p);
}


template <typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string))
{
   T res = tFromString(getTokenAt(c.s,c.sep,p));
   return res;
}

template <typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T,K), T tFromString(string))
{
   int n = c.next;
   collReset(c);
   int res,posicion=-1;
   while(collHasNext(c) && posicion<0){
      T a = collNext(c,tFromString);
      res = cmpTK(a,k);                      //nose si qiere q si T es int y K es string si es valido o no supongo q si
      if(res==0){
         posicion=c.next-1;
      }
   }
   c.next=n;
   return posicion;
}

//template <typename T>          //Segun lo q entendi de la guia
//void collSort(Coll<T>& c, int cmpTT(T,T),T tFromString(string),string tToString(T)) //cmpIntIntMenAMay cmpIntIntMayAMen
//{                                                                                   //cmpStringStringAlf cmpStringStringAlfI
//   int cont=0,cont2;                                                                //cmpStringStringLongMenAMay cmpStringStringLonMayAMen
//   for(int x=cont;x<collSize(c);x++){
//      T t1 = collGetAt(c,x,tFromString);
//      bool predominante=true;
//      for(int z=cont;z<collSize(c) && predominante;z++){
//         cont2=collFind(c,t1,cmpTT,tFromString);
//         T t2 = collGetAt(c,z,tFromString);
//         int res = cmpTT(t1,t2);
//         if(res<0){
//            predominante = false;
//         }
//      }
//      if(predominante){
//         if(cont!=cont2){
//            collAdd(c,collGetAt(c,cont,tFromString),tToString);
//            collSetAt(c,t1,cont,tToString);
//            collRemoveAt(c,cont2);
//         }
//         cont++;
//         x=cont-1;
//      }
//   }
//   collReset(c);
//}
template <typename T>          //Segun el prof
void collSort(Coll<T>& c, int cmpTT(T,T),T tFromString(string),string tToString(T)) //cmpIntIntMenAMay cmpIntIntMayAMen
{                                                                                   //cmpStringStringAlf cmpStringStringAlfI
   int cont=0,cont2;                                                                //cmpStringStringLongMenAMay cmpStringStringLonMayAMen
   for(int x=cont;x<collSize(c);x++){
      T t1 = collGetAt(c,x,tFromString);
      bool predominante=true;
      for(int z=cont;z<collSize(c) && predominante;z++){
         cont2=collFind(c,t1,cmpTT,tFromString);
         T t2 = collGetAt(c,z,tFromString);
         int res = cmpTT(t1,t2);
         if(res>0){
            predominante = false;
         }
      }
      if(predominante){
         if(cont!=cont2){
            collAdd(c,collGetAt(c,cont,tFromString),tToString);
            collSetAt(c,t1,cont,tToString);
            collRemoveAt(c,cont2);
         }
         cont++;
         x=cont-1;
      }
   }
   collReset(c);
}
//int cmpIntIntMenAMay(int t,int k){
//   return k-t;
//}
int cmpIntIntMayAMen(int t,int k){
   return cmpIntInt(t,k);
}
int cmpStringStringAlf(string t,string k){
   return t>k?-1:t==k?0:1;
}
int cmpStringStringAlfI(string t,string k){
   return t>k?1:t==k?0:-1;
}
int cmpStringStringLongMenAMay(string t, string k){
   return length(t)>length(k)?-1:length(t)==length(k)?0:1;
}
int cmpStringStringLongMayAMen(string t, string k){
   return length(t)>length(k)?1:length(t)==length(k)?0:-1;
}

template<typename T>
bool collHasNext(Coll<T> c)
{
   return c.next<collSize(c)?true:false;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   string a = getTokenAt(c.s,c.sep,c.next);
   T t = tFromString(a);
   c.next++;
   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.next=0;
}

#endif
