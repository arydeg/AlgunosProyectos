//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
//using namespace std;
//
//struct Nom{
//   char s[15];
//};
//
//int main()
//{
//   //leo el archivo eje4mod3 y guardo en coll nomErrores
//   FILE* f = fopen("eje4mod3.txt","r+b");
//   Coll<string> nomErrores = collCreate<string>();
//   string orden="";
//   char x = read<char>(f);
//   while(!feof(f)){
//      string n = charToString(x);
//      x = read<char>(f);
//      while(!feof(f) && x!='\\'){
//         n = n + charToString(x);
//         x = read<char>(f);
//      }
//      x = read<char>(f);
//      if(n>orden){
//         orden=n;
//      }else{
//         collAdd(nomErrores,n,stringToString);
//      }
//      x = read<char>(f);
//   }
//   fclose(f);
//
//   //creo el archivo out
//   FILE* f1 = fopen("out.txt","w+b");
//   Nom nombre;
//   for(int i=0;i<collSize<string>(nomErrores);i++){
//      string p = collGetAt(nomErrores,i,stringToString);
//      strcpy(nombre.s,p.c_str());
//      write<Nom>(f1,nombre);
//   }
//   fclose(f1);
//
//   // leo el archivo out
//   FILE* f3 = fopen("out.txt","r+b");
//   Nom res = read<Nom>(f3);
//   while(!feof(f3)){
//      cout<<res.s<<endl;
//      res=read<Nom>(f3);
//   }
//   fclose(f3);
//
//   return 0;
//}
