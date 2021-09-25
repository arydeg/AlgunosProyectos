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
//   FILE* f = fopen("eje2mod3.txt","r+b");
//   Coll<int> poss = collCreate<int>();
//   char x = read<char>(f);
//   int max=0,cont=0;
//   while(!feof(f)){
//      int n = charToInt(x);
//      x = read<char>(f);
//      while(!feof(f) && x!=','){
//         n = n*10 + charToInt(x);
//         x = read<char>(f);
//      }
//      if(max<n){
//         max = n;
//         collRemoveAll<int>(poss);
//         collAdd<int>(poss,cont,intToString);
//      }else if(max==n){
//         collAdd<int>(poss,cont,intToString);
//      }
//      x = read<char>(f);
//      cont++;
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
