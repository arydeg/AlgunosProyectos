//#include <iostream>
//#include <stdio.h>
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
//using namespace std;
//
//int main() // EJERCICIO 1        // se ingresa nombre en mayus sin espacio devuelve un solo digito q es
//{                                // la suma de cada letra con la suma de cada numero hasta llegar a un solo digito
//   string nom;
//   cin>>nom;               // Nombre completo en mayus sin espacio
//   int res=0;
//   for(int i=0; i<length(nom);i++){
//      char letra=nom[i];
//      if(letra<=78){                                           // antes de la Ñ
//         letra = nom[i] - 64;
//      }else if((letra>78) && (letra!=165)){                    // despues de la Ñ
//         letra = nom[i] - 63;
//      }else{
//         letra = nom[i] - 150;                                 //si es Ñ
//      }
//      res += (int)(letra);
//   }
//
//   while(digitCount(res)>1){
//      int sum = getDigit(res,0);
//      res = res/10 + sum;
//   }
//
//   cout<<res;
//   return 0;
//}
//
//


