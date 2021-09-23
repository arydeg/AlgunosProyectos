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
//   FILE* f = fopen("eje1mod3.txt","r+b");
//   Coll<int> poss = collCreate<int>();
//   char x = read<char>(f);
//   int max=0;
//   while(!feof(f)){
//      int n = charToInt(x);
//      if(max<n){
//         max = charToInt(x);
//         collRemoveAll<int>(poss);
//         collAdd<int>(poss,filePos<char>(f)-1,intToString);
//      }else if(max==n){
//         collAdd<int>(poss,filePos<char>(f)-1,intToString);
//      }
//      x = read<char>(f);
//   }
//   fclose(f);
//
//   cout<<"num max: "<<max<<endl;
//   cout<<"Posiciones: ";
//
//   for(int i=0;i<collSize<int>(poss);i++){
//      cout<<collGetAt<int>(poss,i,stringToInt)<<" ";
//   }
//
//   return 0;
//}
