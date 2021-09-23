//
//#include <iostream>
//#include <stdio.h>
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
//using namespace std;
//
//struct BigInt
//{
// string s;
//};
//
//BigInt bigIntCreate(string n){
//  BigInt res={n};
//  return res;
//}
//
//BigInt bigIntSumar(BigInt a,BigInt b){
//   BigInt x=a;
//   BigInt y=b;
//   int signoX=1;
//   if (x.s[0]=='-'){           //se fija si mayor numero A es negativo
//      signoX = -1;
//      x.s = removeAt(x.s,0);   //remueve el signo
//   }
//   int signoY=1;
//   if (y.s[0]=='-'){           //se fija si menor numero B es negativo
//      signoY = -1;
//      y.s = removeAt(y.s,0);   //remueve el signo
//   }
//
//   bool boolMayor = length(x.s)>length(y.s);
//   string mayor,menor;
//   int signoMay,signoMen;
//   if(boolMayor){                //ve cual es mayor y cual menor en longitud
//      mayor = x.s;
//      menor = y.s;
//      signoMay=signoX;
//      signoMen=signoY;
//   }else{
//      mayor = y.s;
//      menor = x.s;
//      signoMay=signoY;
//      signoMen=signoX;
//   }
//
//   string res=mayor;
//   int contMayor=length(mayor),contMenor=length(menor);
//   int carry=0;
//   for(int i=0;contMenor>=0;i++){                                //busco las posiciones a sumar
//      int suma;
//      if(contMenor!=0){
//         suma = charToInt(menor[contMenor-1])*signoMen + charToInt(mayor[contMayor-1])*signoMay + carry;    //convierto de char a int hago la suma}
//      }else{
//         suma = charToInt(mayor[contMayor-1])*signoMay + carry;
//      }
//      if(suma>9){
//         carry=suma/10;
//         suma = suma%10;
//      }else{
//         carry=0;
//      }
//      res[length(res)-1-i] = intToChar(suma);                     // convierto de int a char y lo guardo en el string res
//      removeAt(mayor,contMayor);
//      removeAt(menor,contMenor);
//      contMenor--;
//      contMayor--;
//   }
//
//   BigInt z={res};
//   return z;
//}
//
//int main()
//{
//   BigInt a = bigIntCreate("123");
//   BigInt b = bigIntCreate("8");
//   BigInt suma = bigIntSumar(a,b);
//
//   cout<<suma.s;
//
//   return 0;
//}
//
//
//
//
