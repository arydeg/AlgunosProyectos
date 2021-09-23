//#include <iostream>
//#include <stdio.h>
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
//using namespace std;
//
//int main()
//{
//               //CREO ARCHIVO
////   FILE* f = fopen("eje1mod3.txt","w+b");
////   fclose(f);
//
//   FILE* f = fopen("eje3mod3.txt","r+b");
//   Coll<string> poss = collCreate<string>();
//   char x = read<char>(f);
//   int max=0,cont=0;
//   while(!feof(f)){
//      string n = charToString(x);
//      x = read<char>(f);
//      while(!feof(f) && x!='\\'){
//         n = n + charToString(x);
//         x = read<char>(f);
//      }
//
//      x = read<char>(f);
//      int z = length(n);
//
//      if(max<z){
//         max = z;
//         collRemoveAll<string>(poss);
//         collAdd<string>(poss,n,stringToString);
//      }else if(max==z){
//         collAdd<string>(poss,n,stringToString);
//      }
//      x = read<char>(f);
//      cont++;
//   }
//   fclose(f);
//
//   cout<<"num max: "<<max<<endl;
//   cout<<"Posiciones: ";
//
//   for(int i=0;i<collSize<string>(poss);i++){
//      cout<<collGetAt<string>(poss,i,stringToString)<<" ";
//   }
//
//   return 0;
//}
