//#include <iostream>
//#include <stdio.h>
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
//using namespace std;
//
//int main() // EJERCICIO 2
//{
//   string nom="Pedro,2-oct-1970,Argentino|Juan,9-dic-1985,Chileno|Pablo,14-ene-1992,Argentino";
//   int contCharPipe = charCount(nom,'|');
//   cout<<"Cantidad de personas: "<<contCharPipe+1; cout<<endl;cout<<endl;
//   int comienzoCharPipe=0,finCharPipe;
//   for(int a=0;a<=contCharPipe;a++){                //separo por persona
//      string persona;
//      if(a != contCharPipe){
//         finCharPipe = indexOf(nom,'|',comienzoCharPipe);
//         persona = substring(nom,comienzoCharPipe,finCharPipe);
//      }else{
//         persona = substring(nom,comienzoCharPipe);
//      }
//
//      int contCharComa = charCount(persona,',');        //separo por dato de persona
//      int comienzoCharComa=0,finCharComa;
//      for(int b=0;b<=contCharComa;b++){
//         string res;
//         if(b != contCharComa){
//            finCharComa = indexOf(persona,',',comienzoCharComa);
//            res = substring(persona,comienzoCharComa,finCharComa);
//         }else{
//            res = substring(persona,comienzoCharComa);
//         }
//
//         if(b==0){                                       //muestro datos por persona
//            cout<<"Nombre: "<<res<<endl;
//         }else if(b==1){
//            cout<<"Cumpleaños: "<<res<<endl;
//         }else if(b==2){
//            cout<<"Nacionalidad: "<<res<<endl;
//         }
//         comienzoCharComa = finCharComa + 1;
//      }
//      cout<<endl;
//      comienzoCharPipe = finCharPipe + 1;
//   }
//   return 0;
//}
//
//
