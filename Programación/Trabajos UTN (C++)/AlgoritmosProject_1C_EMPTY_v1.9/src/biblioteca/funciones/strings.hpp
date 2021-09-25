#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// --[ Funciones Basicas ]--

// Descripcion: Retorna la longitud de la cadena s
// Paramerto:
//    s - La cadena cuya longitud se desea conocer
// Retorna: la longitud de la cadena s
// Ejemplo: l
int length(string s)
{
   int i=0;
   while(s[i]!='\0'){
      i++;
   }
   return i;
}

// Retorna la cantidad de veces que la cadena s contiene a c
int charCount(string s,char c)
{
   int cont=0;
   for(int i=0;i<length(s);i++){
      if(s[i]==c){
         cont++;
      }
   }
   return cont;
}

// Retorna la subcadena de s comprendida entre d (inclusive) y h (no inclusive)
string substring(string s,int d,int h)
{
   string res="";
   for(int i=d;i<h;i++){
      res+=s[i];
   }
   return res;
}

// Retorna la subcadena de s que va desde d (inclusive) hasta el final
string substring(string s,int d) // ok
{
   string res="";
   for(int i=d;i<length(s);i++){
      res+=s[i];
   }
   return res;
}

// Retorna la posicion de la primer ocurrencia
// de c dentro s, o -1 si s no contiene a c
int indexOf(string s,char c) // ok
{
   int i=0;
   while(s[i]!=c){
      i++;
   }
   return i>length(s)?-1:i;
}

// Retorna la posicion de la primer ocurrencia de c dentro de s
// considerando la subcadena de s que va desde offset hasta el final.
// Ejemplo: indexOf("ALGORITMOS",'O',7) retorna: 1
int indexOf(string s,char c,int offSet) // ok
{
   int i=offSet;
   while(s[i]!=c){
      i++;
   }
   return i>length(s)?-1:i;
}

// Retorna la posicion de la ultima ocurrencia de c dentro de s
// o -1 si s no contiene a c
int lastIndexOf(string s,char c)
{
   int i=length(s)-1;
   while(s[i]!=c){
      i--;
   }
   return i<0?-1:i;
}

// Retorna la posicion de la n-esima ocurrencia de c dentro de s.
// Por ejemplo: indexOfN("pedro|pablo|juan|rolo",'|',2) retorna 11.
int indexOfN(string s,char c,int n)
{  int res=0;
   for(int i=0;i<n;i++){
      if(i==0){
         res=indexOf(s,c,res);
      }else{
         res=indexOf(s,c,res+1);
      }
   }
   return res;
}

// Retorna el valor numerico de ch.
// Ejemplo: charToInt('4') retorna: 4.
int charToInt(char ch)
{
   int res=ch-48;
   // por si lo quiere q lo haga de otra forma el de abajo sirve y solo toma hasta 9
//   int res;
//   for(int i=48; i<=ch;i++){
//      res=i-48;
//   }
   return res;
}

// Retorna el valor char de i.
// Ejemplo: intToChar(4) retorna: '4'.
char intToChar(int i)
{
   char res=i+48; // charToInt si hay problema con que lo haga asi puedo usar el codigo modificandolo del charToInt
   return res;
}

// retorna el i-esimo digito de n contando desde la derecha
int getDigit(int n,int i) // ok
{
   int res;
   for(int a=0;a<=i;a++){
      res = n%10;
      n=n/10;
   }
   return res;
}

int digitCount(int i) // ok
{

   int num=i,res=0;
     while (num!=0){
        res++;
        num/=10;
     }
     return res==0?res+1:res;
}

string intToString(int num) // ok
{
   string res="";
   for(int i=digitCount(num)-1;i>=0;i--){
      char z = intToChar(getDigit(num,i));
      if(z==48){
         res+="0";
      }else if(z==49){
         res+="1";
      }else if(z==50){
         res+="2";
      }else if(z==51){
         res+="3";
      }else if(z==52){
         res+="4";
      }else if(z==53){
         res+="5";
      }else if(z==54){
         res+="6";
      }else if(z==55){
         res+="7";
      }else if(z==56){
         res+="8";
      }else if(z==57){
         res+="9";
      }
   }
   return res;
}

int stringToInt(string s) // ok
{
   int res=0;
   int multiplicador = 0;
   for(int i=length(s)-1;i>=0;i--){
      if(i==length(s)-1){
         multiplicador = 1;
      }else if(i==length(s)-2){
         multiplicador = 10;
      }else{
         multiplicador *= 10;
      }
      if(s[i]=='0'){
         res+=0 * multiplicador;
      }else if(s[i]=='1'){
         res+=1 * multiplicador;
      }else if(s[i]=='2'){
         res+=2 * multiplicador;
      }else if(s[i]=='3'){
         res+=3 * multiplicador;
      }else if(s[i]=='4'){
         res+=4 * multiplicador;
      }else if(s[i]=='5'){
         res+=5 * multiplicador;
      }else if(s[i]=='6'){
         res+=6 * multiplicador;
      }else if(s[i]=='7'){
         res+=7 * multiplicador;
      }else if(s[i]=='8'){
         res+=8 * multiplicador;
      }else if(s[i]=='9'){
         res+=9 * multiplicador;
      }
      if(i==length(s)-1){
         multiplicador = 0;
      }
   }
   return res;
}

int stringToInt(string s,int b) // ok
{
   int res=0;
   int multiplicador = 0;
   for(int i=length(s)-1;i>=0;i--){
      if(i==length(s)-1){
         multiplicador = 1;
      }else if(i==length(s)-2){
         multiplicador = b;
      }else{
         multiplicador *= b;
      }
      if(s[i]=='0'){
         res+=0 * multiplicador;
      }else if(s[i]=='1'){
         res+=1 * multiplicador;
      }else if(s[i]=='2'){
         res+=2 * multiplicador;
      }else if(s[i]=='3'){
         res+=3 * multiplicador;
      }else if(s[i]=='4'){
         res+=4 * multiplicador;
      }else if(s[i]=='5'){
         res+=5 * multiplicador;
      }else if(s[i]=='6'){
         res+=6 * multiplicador;
      }else if(s[i]=='7'){
         res+=7 * multiplicador;
      }else if(s[i]=='8'){
         res+=8 * multiplicador;
      }else if(s[i]=='9'){
         res+=9 * multiplicador;
      }
      if(b==16){        // excepcion del hexadecimal
         if(s[i]=='A'){
            res+=10 * multiplicador;
         }else if(s[i]=='B'){
            res+=11 * multiplicador;
         }else if(s[i]=='C'){
            res+=12 * multiplicador;
         }else if(s[i]=='D'){
            res+=13 * multiplicador;
         }else if(s[i]=='E'){
            res+=14 * multiplicador;
         }else if(s[i]=='F'){
            res+=15 * multiplicador;
         }
      }
      if(i==length(s)-1){
         multiplicador = 0;
      }
   }
   return res;
}

string charToString(char c)
{
   string res=" ";
   res[0]=c;
   return res;
}

char stringToChar(string s)
{
   char res = s[0];
   return res;
}

string stringToString(string s){
   return s;
}

string doubleToString(double d)
{
   string res;                            // limitacion: funciona igual que si declaras un double
   int x=d,resto=0,cont=0;                // y lo mostras en la consola solo q obvio esta convertido en string
   resto=(d-x)*100000000+1;               // es decir esta programado para aproximar igual que como se muestra en consola
   if(x==0){                              // y con la misma cantidad de caracteres
      res = "0";                          // (varia la exactitud a medida que el numero antes de la coma crece (igual que en la consola))
      res= res + ".";
   }else{
      res = intToString(x) + ".";
   }
   for(int i=digitCount(resto);i<8;i++){
      res+="0";
      cont++;
   }
   while(digitCount(resto)+cont>6-digitCount(x)){
      if((digitCount(resto)+cont == 6-digitCount(x) + 1) && (getDigit(resto,0) >= 5)){
         resto+=10;
      }
      resto=resto/10;
   }
   while(resto%10==0){
      resto=resto/10;
   }
   res+=intToString(resto);
   return res;
}

double stringToDouble(string s)
{
   double res=0;                                            //con aproximacion
   string a="",b="";
   int x=indexOf(s,'.');
   for(int i=0;i<x;i++){
      a += s[i];
   }
   for(int i=x;s[i]!='\0';i++){
      b += s[i];
   }
   res=stringToInt(b);
   int ceros = length(b)-1-digitCount(stringToInt(b));
   for(int i=digitCount(stringToInt(b))+ceros; i > 0 ;i--){
      res = res/10;
   }
   res += stringToInt(a);
   return res;
}

bool isEmpty(string s)
{
   return s[0]=='\0'?true:false;
}

bool contains(string s, char c)
{
   int res = indexOf(s,c);
   return res>=0?true:false;
}

string replace(string s, char oldChar, char newChar)
{
   string res=s;
   for(int i=1;i<=charCount(s,oldChar);i++){
      res[indexOfN(s,oldChar,i)] = newChar;
   }
   return res;
}

string insertAt(string s,int pos,char c)
{
   string res="";
   for(int i=0;i<pos;i++){
      res+=s[i];
   }
   res+=charToString(c);
   for(int i=pos;i<length(s);i++){
      res+=s[i];
   }
   return res;
}

string removeAt(string s,int pos)
{
   string res="";
   for(int i=0;i<pos;i++){
      res+=s[i];
   }
   for(int i=pos+1;i<length(s);i++){
      res+=s[i];
   }
   return res;
}

string ltrim(string s)
{
   string res=s;
   int i = 0;
   while(res[i]==' '){
      res = removeAt(res,i);
   }
   return res;
}

string rtrim(string s)
{
   string res=s;
   while(res[length(res)-1]==' '){
      res = removeAt(res,length(res)-1);
   }
   return res;
}

string trim(string s)
{
   string res = ltrim(rtrim (s));
   return res;
}

string replicate(char c,int n)
{
   string res="";
   for(int i=0;i<n;i++){
      res = insertAt(res,0,c);
   }
   return res;
}

string spaces(int n)
{
   string res = replicate(' ',n);
   return res;
}

string lpad(string s,int n,char c)
{
   string res=s;
   while(length(res)<n){
      res = insertAt(res,0,c);
   }
   return res;
}

string rpad(string s,int n,char c)
{
   string res=s;
   while(length(res)<n){
      res = insertAt(res,length(res),c);
   }
   return res;
}

string cpad(string s,int n,char c)
{
   string res=s;
   while(length(res)<n){
      res = insertAt(res,0,c);
      if(length(res)!=n){                  // por si llega el string a la cantidad n no  me distribuya equitativamente el char
         res = insertAt(res,length(res),c);
      }
   }
   return res;
}

bool isDigit(char c)
{
   bool res=false;
   if((c>=48)&&(c<=57)){
      res=true;
   }
   return res;
}

bool isLetter(char c)
{
   bool res=false;
   if(((c>=65)&&(c<=90))||((c>=97)&&(c<=122))){
      res=true;
   }
   return res;
}

bool isUpperCase(char c)
{
   bool res=false;
   if((c>=65)&&(c<=90)){
      res=true;
   }
   return res;
}

bool isLowerCase(char c)
{
   bool res=false;
   if((c>=97)&&(c<=122)){
      res=true;
   }
   return res;
}

char toUpperCase(char c)
{
   char res=c;
   if(isLetter(res) && isLowerCase(res)){
      res = res - 32;
   }
   return res;
}

char toLowerCase(char c)
{
   char res=c;
   if(isLetter(res) && isUpperCase(res)){
      res = res + 32;
   }
   return res;
}








#endif
