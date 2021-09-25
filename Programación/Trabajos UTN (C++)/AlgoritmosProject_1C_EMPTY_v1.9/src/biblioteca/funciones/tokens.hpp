#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

// --[Funciones Token]--

// s = "John|Paul|George|Ringo"
int tokenCount(string s,char sep) // ok
{
   int res = charCount(s,sep)+1;
   return length(s)==0?0:res;
}

// pablo|juan|pedro|carlos
string getTokenAt(string s,char sep, int p)  // ok
{
   string res;
   int token=tokenCount(s,sep);
   if(token==1){
      res=s;
   }else if(p==0){
      int inicio=0;
      int fin=indexOfN(s,sep,p+1);
      res = substring(s,inicio,fin);
   }else if(token>p+1){
      int inicio=indexOfN(s,sep,p)+1;
      int fin = indexOfN(s,sep,p+1);
      res = substring(s,inicio,fin);
   }else{
      int inicio=indexOfN(s,sep,p)+1;
      res = substring(s,inicio);
   }
   return res;
}

void addToken(string& s,char sep,string t) // ok
{
   if(isEmpty(s)){
      s=t;
   }else{
      s = insertAt(s,length(s),sep);
      s += t;
   }
}

void removeTokenAt(string& s,char sep, int p) //  ok
{
   string res="";
   for(int i=0; i<tokenCount(s,sep);i++){
      if(p!=i){
         if(isEmpty(res)){
            res += getTokenAt(s,sep,i);
         }else{
            res += charToString(sep) + getTokenAt(s,sep,i);
         }
      }

   }
   s=res;
}

void setTokenAt(string& s,char sep, string t,int p) // ok
{
   string res="";
   for(int i=0; i<tokenCount(s,sep);i++){
      if(p!=i){
         if(isEmpty(res)){
            res += getTokenAt(s,sep,i);
         }else{
            res += charToString(sep) + getTokenAt(s,sep,i);
         }
      }else{
         addToken(res,sep,t);
      }
   }
   s=res;

}

int findToken(string s,char sep, string t)
{
   int res=0;
   for(int i=0;i<tokenCount(s,sep);i++){
      if(getTokenAt(s,sep,i)==t){
         res=i;
         i=tokenCount(s,sep);
      }
   }
   return res;
}

// --[/Funciones Token]--



#endif
