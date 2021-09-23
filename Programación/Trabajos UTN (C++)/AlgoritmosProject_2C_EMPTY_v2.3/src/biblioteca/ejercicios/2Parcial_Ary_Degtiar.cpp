//#ifndef _MAIN
//#define _MAIN
//
//#include <iostream>
//#include "biblioteca/tads/Arr.hpp"
//#include "biblioteca/tads/Map.hpp"
//#include "biblioteca/tads/List.hpp"
//#include "biblioteca/tads/Stack.hpp"
//#include "biblioteca/tads/Queue.hpp"
//#include "biblioteca/funciones/strings.hpp"
//#include "biblioteca/funciones/lists.hpp"
//#include "biblioteca/funciones/tokens.hpp"
//#include "biblioteca/funciones/files.hpp"
//using namespace std;
///*
// *           2do Parcial
// *       Alumno: Ary Degtiar
// *       Legajo: 1754210
// *       Fecha: 13/11/2020
// */
//
////TAD
//struct Fecha
//{
// int d;
// int m;
// int a;
//};
//struct Hora
//{
// int h;
// int m;
// int s;
//};
//struct Obra
//{
// int idObra;
// char titulo[100];
// Fecha fEstreno; // TAD
// int idTeatro;
//};
//struct Teatro
//{
// int idTeatro;
// char nombre[50];
// int capacidad;
// int sectores;
//};
//struct Funcion
//{
// int idFuncion;
// int diaSem; // 1=>Lunes, 2=>Martes, ...
// Hora hora; // TAD
//};
//struct Reserva
//{
// int idCliente;
// int idObra;
// int idFuncion;
// int sector; // sector de la sala; ej: Pullman,Platea...
// int cant;
//};
//struct Sector{
// int id;
// int cap;
// int resA;
//// int resR;
//};
//struct Rechazos{
// int idSector;
// int cont;
//};
//struct RObra
//{
// Obra o;
// List<Funcion> lf;
// Map<int,Arr<Sector>> mapFS; // map de key id funcion y value array Sectores
//};
//struct RTeatro
//{
// Teatro t;
// Arr<Sector> s;
// Map<int,Arr<Rechazos>> mapDR; //map de key dias y value array de Rechazos
//};
////Funciones
//List<Funcion> funcionesProgramadas(int idObra){List<Funcion> l; return l;}
//Reserva leerReserva(){Reserva r; return r;}
//bool continuarOperando(){return true;}
//int capacidadSector(int idTeatro,int sector){return 0;}
//
//Arr<RTeatro> cargarRTeatro(){
//   Arr<RTeatro> arrRT = Arr<RTeatro>();
//   FILE* f = fopen("TEATRO.dat","r+b");
//   Teatro t = read<Teatro>(f);
//   while(!feof(f))
//   {
//      RTeatro rt;
//      rt.t = t;
//
//      rt.mapDR = Map<int,Arr<Rechazos>>();
//      for(int z=1;z<=7;z++){
//         Arr<Rechazos> arrR = Arr<Rechazos>();
//         mapPut<int,Arr<Rechazos>>(rt.mapDR,z,arrR);
//      }
//
//      Arr<Sector> arrS = Arr<Sector>();
//      for(int i=1;i<rt.t.sectores;i++){ //por cada sector obtiene su capacidad
//         Sector s;
//         s.id = i;
//         s.cap = capacidadSector(rt.t.idTeatro,s.id);
//         s.resA = 0;
//         arrAdd<Sector>(arrS,s);
//      }
//
//      arrAdd<RTeatro>(arrRT,rt);
//
//      t = read<Teatro>(f);
//   }
//   fclose(f);
//   return arrRT;
//}
//int cmpRTeatroId(RTeatro a, int b){return a.t.idTeatro-b;}
//Arr<RObra> cargarRObra(Arr<RTeatro> arrRT){
//   Arr<RObra> arrRO = Arr<RObra>();
//   FILE* f = fopen("OBRA.dat","r+b");
//   Obra o = read<Obra>(f);
//   while( !feof(f) )
//   {
//      RObra ro;
//      ro.o = o;
//      ro.lf = funcionesProgramadas(ro.o.idObra);
//      ro.mapFS = Map<int,Arr<Sector>>();
//
//      //cargo map
//      while(listHasNext(ro.lf)){
//         Funcion* f = listNext<Funcion>(ro.lf);
//         int posRTeatro = arrFind<RTeatro>(arrRT,ro.o.idTeatro,cmpRTeatroId);
//         RTeatro* rt = arrGet<RTeatro>(arrRT,posRTeatro);
//         Arr<Sector> arrS = rt->s;
//         mapPut<int,Arr<Sector>>(ro.mapFS,f->idFuncion,arrS);
//      }
//
//      arrAdd<RObra>(arrRO,ro);
//
//      o = read<Obra>(f);
//   }
//   fclose(f);
//   return arrRO;
//}
//int cmpRObraId(RObra a, int b){return a.o.idObra-b;}
//int cmpSectorId(Sector s,int b){return s.id-b;}
//int cmpFuncionId(Funcion a, int b){return a.idFuncion-b;};
//void procesarReserva(Reserva r,Arr<RTeatro> arrRT, Arr<RObra> arrRO){
//   int posRObra = arrFind<RObra>(arrRO,r.idObra, cmpRObraId);
//   RObra* ro = arrGet<RObra>(arrRO,posRObra);
//
//   Funcion* f = listFind<Funcion>(ro->lf, r.idFuncion, cmpFuncionId);
//
//   int posRTeatro = arrFind<RTeatro>(arrRT,ro->o.idTeatro, cmpRTeatroId);
//   RTeatro* rt = arrGet<RTeatro>(arrRT,posRTeatro);
//
//   Arr<Sector>* arrS = mapGet<int,Arr<Sector>>(ro->mapFS,r.idFuncion);
//   int posSector = arrFind<Sector>(*arrS,r.sector,cmpSectorId);
//   Sector* s = arrGet<Sector>(*arrS,posSector);
//
//   //se fija si la acepta o la rechaza
//   if((r.cant + s->resA) <= s->cap){
//      s->resA += r.cant;
//   }else{
//      Rechazos rz;
//      rz.cont += r.cant;
//      rz.idSector = s->id;
//
//      Arr<Rechazos>* arrR = mapGet<int,Arr<Rechazos>>(rt->mapDR,f->diaSem);
//      arrAdd<Rechazos>(*arrR,rz);
//   }
//}
//void mostrarRechazos(Arr<Rechazos> arrR){
//   for(int i=0; i < (arrSize<Rechazos>(arrR)); i++){
//      Rechazos* r = arrGet<Rechazos>(arrR,i);
//      cout<<"Sector: "<<r->idSector<<" Rechazos: "<<r->cont<<endl;
//   }
//}
//void mostrarListado(Arr<RTeatro> arrRT){
//   for(int i=0; i < (arrSize<RTeatro>(arrRT)) ;i++){
//      RTeatro* rt = arrGet<RTeatro>(arrRT,i);
//      string nomT = rt->t.nombre;
//      cout<<"Teatro: "<<nomT<<endl;
//
//      while(mapHasNext(rt->mapDR)){
//         int diaSem = mapNextKey<int,Arr<Rechazos>>(rt->mapDR);
//         cout<<"Dia semana: "<<diaSem<<endl;
//
//         Arr<Rechazos>* arrR = mapGet<int,Arr<Rechazos>>(rt->mapDR,diaSem);
//         mostrarRechazos(*arrR);
//
//      }
//
//   }
//}
////Main
//int main()
//{
//   Arr<RTeatro> arrRT = cargarRTeatro();
//   Arr<RObra> arrRO = cargarRObra(arrRT);
//
//   while(continuarOperando()){
//      Reserva r = leerReserva();
//
//      procesarReserva(r,arrRT,arrRO);
//
//   }
//
//   mostrarListado(arrRT);
//
//   return 0;
//}
//
//#endif
