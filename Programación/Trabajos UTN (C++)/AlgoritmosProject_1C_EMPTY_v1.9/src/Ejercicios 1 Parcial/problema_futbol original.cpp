//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
//using namespace std;
//
//// Estructuras
//struct Equipo
//{
//   int idEq;
//   char nombre[20];
//   int puntos;
//};
//struct REquipo
//{
//   Equipo e;
//   int puntosNew;
//};
//struct REstadio
//{
//   string estadio;
//   int partidosJug;
//   int partidosEmp;
//};
//struct Resultado
//{
//   int idEq1;
//   int idEq2;
//   int codRes;
//   char estadio[20];
//};
//
////Funciones
//string requipoToString(REquipo r){     // idEq, nombre, puntos, puntosNew
//   string idEq = intToString(r.e.idEq);
//   string nom = r.e.nombre;
//   string puntos = intToString(r.e.puntos);
//   string puntosNew = intToString(r.puntosNew);
//   return idEq + "," + nom + "," + puntos + "," + puntosNew;
//}
//string restadioToString(REstadio r){      // est, partidos, partidosEmp
//   string est = r.estadio;
//   string partidos = intToString(r.partidosJug);
//   string partidosEmp = intToString(r.partidosEmp);
//   return est + "," + partidos + "," + partidosEmp;
//}
//REquipo stringToREquipo(string s){
//   REquipo res;
//   char sep = ',';
//   res.e.idEq = stringToInt(getTokenAt(s,sep,0));
//   strcpy(res.e.nombre,getTokenAt(s,sep,1).c_str());
//   res.e.puntos = stringToInt(getTokenAt(s,sep,2));
//   res.puntosNew = stringToInt(getTokenAt(s,sep,3));
//   return res;
//}
//REstadio stringToREstadio(string s){
//   REstadio r;
//   char sep = ',';
//   r.estadio = getTokenAt(s, sep, 0);
//   r.partidosJug = stringToInt(getTokenAt(s, sep, 1));
//   r.partidosEmp = stringToInt(getTokenAt(s, sep, 2));
//   return r;
//}
//Coll<REquipo> subirEquipos(){
//   Coll<REquipo> res = collCreate<REquipo>();
//   FILE* f = fopen("EQUIPOS.dat","r+b");
//   Equipo e = read<Equipo>(f);
//   while(!feof(f)){
//      REquipo equipo = {e,0};
//      collAdd<REquipo>(res,equipo,requipoToString);
//      e = read<Equipo>(f);
//   }
//   return res;
//}
//int cmpREquipoIdEq(REquipo r, int idEq){
//   return r.e.idEq - idEq;
//}
//int cmpREquipox2(REquipo a, REquipo b){
//   int ptsE1 = a.puntosNew + a.e.puntos ;
//   int ptsE2 = b.puntosNew + b.e.puntos ;
//   return ptsE2 - ptsE1;
//}
//int cmpREstadioNom(REstadio r, string nom){
//   return r.estadio==nom?0:-1;
//}
//void actualizarPuntos(Coll<REquipo>& c,int idEq,int pts){
//   int pos = collFind<REquipo,int>(c, idEq, cmpREquipoIdEq, stringToREquipo);
//   REquipo r = collGetAt(c, pos, stringToREquipo);
//   r.puntosNew += pts;
//   collSetAt<REquipo>(c, r, pos, requipoToString);
//}
//void actualizarContEstadio(Coll<REstadio>& c,string est,int contEmp){
//   int pos = collFind<REstadio,string>(c, est, cmpREstadioNom,stringToREstadio);
//   if (pos<0){
//      REstadio e = {est,1,contEmp};
//      collAdd<REstadio>(c, e, restadioToString);
//   }else{
//      REstadio e = collGetAt(c, pos, stringToREstadio);
//      e.partidosJug++;
//      e.partidosEmp += contEmp;
//      collSetAt<REstadio>(c, e, pos, restadioToString);
//   }
//}
//void actualizarArchivoEquipos(Coll<REquipo> c){
//   FILE* f = fopen("EQUIPOS.dat","r+b");
//   Equipo equi = read<Equipo>(f);
//   while( !feof(f) )
//   {
//      int idEq = equi.idEq;
//      int pos = collFind<REquipo,int>(c, idEq, cmpREquipoIdEq, stringToREquipo);
//      REquipo r = collGetAt(c, pos, stringToREquipo);
//      equi.puntos = r.puntosNew + equi.puntos;
//      //seek<Equipo>(f,filePos<Equipo>(f)-1);      // modificacion echa en clase (compila pero no me muestra nada)
//      write<Equipo>(f,equi);
//      equi = read<Equipo>(f);
//   }
//   fclose(f);
//   // preguntas: porq el mio no funca?
//   //by prof   funciona
////   FILE* f = fopen("EQUIPOS.dat","r+b");
////   for(int i=0; i<collSize<REquipo>(c);i++)
////   {
////      REquipo a= collGetAt<REquipo>(c, i, stringToREquipo);
////      Equipo x = a.e;
////      x.puntos+=a.puntosNew;
////      write<Equipo>(f,x);
////   }
////   fclose(f);
//}
//void mostrarPunto1(Coll<REquipo> c){
//   cout<<"-------------------"<<endl;
//   cout<<"Punto 1"<<endl;
//   collSort<REquipo>(c,cmpREquipox2,stringToREquipo,requipoToString);
//   for(int i=0;i<collSize<REquipo>(c);i++){
//      REquipo e = collGetAt<REquipo>(c, i, stringToREquipo);
//      string nom = e.e.nombre;
//      cout<<nom<<"   "<<e.puntosNew+e.e.puntos<<" pts"<<endl;
//   }
//   cout<<"-------------------"<<endl;
//}
//void mostrarPunto2(Coll<REstadio> c){
//   cout<<"-------------------"<<endl;
//   cout<<"Punto 2"<<endl;
//   for(int i=0;i<collSize<REstadio>(c);i++){
//      REstadio e = collGetAt<REstadio>(c, i, stringToREstadio);
//      cout<<"Estadio: "<<e.estadio<<endl;
//      cout<<"Partidos jugados: "<<e.partidosJug<<endl;
//      cout<<"Partidos empatados: "<<e.partidosEmp<<endl;
//      cout<<"-------------------"<<endl;
//   }
//}
//void mostrarPunto3(){
//   cout<<"-------------------"<<endl;
//   cout<<"Punto 3"<<endl;
//   FILE* equipoR = fopen("EQUIPOS.dat","r+b");
//   Equipo equi = read<Equipo>(equipoR);
//   while( !feof(equipoR) )
//   {
//      cout<<"EQUIPO"<<endl;
//      cout<<"Id: "<<equi.idEq<<"   ";
//      cout<<"nombre: "<<equi.nombre<<"   ";
//      cout<<"puntos: "<<equi.puntos<<endl;
//      equi = read<Equipo>(equipoR);
//   }
//   fclose(equipoR);
//   cout<<"-------------------"<<endl;
//}
//void crearArchivos()
//{
//   //--------------------------Creo todos los archivos----------------------------------
//   // Equipo
//   FILE* equipos = fopen("EQUIPOS.dat","w+b");
//   Equipo e1 = { 1, "FERRO", 10 };
//   Equipo e2 = { 2, "LANUS", 0 };
//   Equipo e3 = { 3, "BOCA", 0 };
//   Equipo e4 = { 4, "RIVER", 1 };
//   write<Equipo>(equipos,e1);
//   write<Equipo>(equipos,e2);
//   write<Equipo>(equipos,e3);
//   write<Equipo>(equipos,e4);
//   fclose(equipos);
//   // Resultado
//   FILE* res = fopen("RESULTADOS.dat","w+b");
//   Resultado r1 = { 1, 2, -1, "Vicente Lopez" };
//   Resultado r2 = { 3, 4, 0, "Usuahia" };
//   write<Resultado>(res,r1);
//   write<Resultado>(res,r2);
//   fclose(res);
//
////   //*COMPROVACION* de archivos creados
////   // Equipo
////   FILE* equipoR = fopen("EQUIPOS.dat","r+b");
////   Equipo equi = read<Equipo>(equipoR);
////   while( !feof(equipoR) )
////   {
////      cout<<"EQUIPO"<<endl;
////      cout<<"Id: "<<equi.idEq<<"   ";
////      cout<<"nombre: "<<equi.nombre<<"   ";
////      cout<<"puntos: "<<equi.puntos<<endl;
////      equi = read<Equipo>(equipoR);
////   }
////   fclose(equipoR);
////   cout<<endl;
////   // Resultado
////   FILE* resultadoR = fopen("RESULTADOS.dat","r+b");
////   Resultado re = read<Resultado>(resultadoR);
////   while( !feof(resultadoR) )
////   {
////      cout<<"Resultado"<<endl;
////      cout<<"equipo 1: "<<re.idEq1<<"   ";
////      cout<<"equipo 2: "<<re.idEq2<<"   ";
////      cout<<"codigo res: "<<re.codRes<<"   ";
////      string est = re.estadio;
////      cout<<"estadio: "<<est<<endl;
////      re = read<Resultado>(resultadoR);
////   }
////   fclose(resultadoR);
////   cout<<endl;
////   //--------------------Fin Creacion de archivos--------------------------
//}
//int main()
//{
//   crearArchivos();
//
//   Coll<REquipo> equipo = subirEquipos();
//   Coll<REstadio> estadio = collCreate<REstadio>();
//
//   FILE* f = fopen("RESULTADOS.dat","r+b");
//   Resultado r = read<Resultado>(f);
//   while(!feof(f)){
//      // Punto 1
//      int ptsEq1 = r.codRes<0?3:r.codRes==0?1:0;
//      int ptsEq2 = r.codRes>0?3:r.codRes==0?1:0;
//      actualizarPuntos(equipo,r.idEq1,ptsEq1);
//      actualizarPuntos(equipo,r.idEq2,ptsEq2);
//      // Punto 2
//      int contEmp = ptsEq1==1?1:0;
//      string est=r.estadio;
//      actualizarContEstadio(estadio,est,contEmp);
//
//      r = read<Resultado>(f);
//   }
//   mostrarPunto1(equipo);
//   mostrarPunto2(estadio);
//   // Punto 3
//   actualizarArchivoEquipos(equipo);
//   mostrarPunto3();
//   return 0;
//}
