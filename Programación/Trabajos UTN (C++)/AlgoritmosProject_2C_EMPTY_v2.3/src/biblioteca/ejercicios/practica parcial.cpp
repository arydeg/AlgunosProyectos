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
//
////TAD
//struct Fecha
//{
//   int m,d,a;
//};
//struct Hora
//{
//   int h,m;
//};
//struct Obra
//{
//   int idObra;
//   char titulo[100];
//   Fecha fEstreno; // TAD
//   int idTeatro;
//};
//struct Teatro
//{
//   int idTeatro;
//   char direccion[50];
//   int capacidad;
//   int sectores;
//};
//struct Funcion
//{
//   int idFuncion;
//   int diaSem; // 1=>Lunes, 2=>Martes, ...
//   Hora hora; // TAD
//};
//struct Reserva
//{
//   int idCliente;
//   int idObra;
//   int idFuncion;
//   int sector; // sector de la sala; ej: Pullman,Platea...
//   int cant;
//};
//struct Sector{
//   int idSector;
//   int capSector;
//   int reservasA;
//};
//struct Excluido{
//   Hora h;
//   int d;
//   int c;
//};
//struct RFuncion
//{
//   Funcion f;
//   Arr<Sector> s;
//   Arr<Excluido> e;
//
//};
//struct RObra
//{
//   Obra o;
//   List<RFuncion> rf;
//   int resA;
//
//};
////Funciones
//List<Funcion> funcionesProgramadas(int idObra){List<Funcion> l; return l;}
//Reserva leerReserva(){return{};}
//bool continuarOperando(){return true;}
//int capacidadSector(int idTeatro,int sector){return 0;}
//Arr<Teatro> cargarTeatros(){
//   Arr<Teatro> arrTeatro = Arr<Teatro>();
//   FILE* f = fopen("TEATRO.dat","r+b");
//   Teatro teatro = read<Teatro>(f);
//   while(!feof(f))
//   {
//      arrAdd<Teatro>(arrTeatro,teatro);
//
//      teatro = read<Teatro>(f);
//   }
//   fclose(f);
//   return arrTeatro;
//}
//Arr<RObra> cargarObras(){
//   Arr<RObra> arrRObra = Arr<RObra>();
//   FILE* f = fopen("OBRA.dat","r+b");
//   Obra obra = read<Obra>(f);
//   while(!feof(f))
//   {
//      RObra rObra;
//      rObra.o = obra;
//      rObra.f = funcionesProgramadas(rObra.o.idObra);
//      rObra.resA = 0;
//      arrAdd<RObra>(arrRObra,rObra);
//
//      obra = read<Obra>(f);
//   }
//   fclose(f);
//   return arrRObra;
//}
//int cmpRObraId(RObra a, int b){return a.o.idObra-b;}
//int cmpFuncionId(Funcion a,int b){return a.idFuncion-b;}
//int cmpRTeatroId(Teatro a, int b){return a.idTeatro-b;}
//void procesarReserva(Reserva r,Arr<Teatro> arrTeatro,Arr<RObra> arrRObra){
//   //verifico que haya lugar en el sector
//   int posRObra = arrFind<RObra,int>(arrRObra,r.idObra,cmpRObraId);
//   RObra* ro = arrGet<RObra>(arrRObra,posRObra);
//
////   int posTeatro = arrFind<Teatro,int>(arrTeatro,ro->o.idTeatro,cmpRTeatroId);
////   Teatro* te = arrGet<Teatro>(arrTeatro,posTeatro);
//
//   Sector* se = arrGet<Sector>(ro->s,r.sector-1);
//   se->capSector = capacidadSector(ro->o.idTeatro,r.sector);
//
//   //si hay lugar en el sector se cuenta la reserva, sino se carga el excluido
//   if((se->reservasA+r.cant) <= se->capSector){
//      se->reservasA += r.cant;
//   }else{
//      List<Funcion> l = ro->f;
//      Funcion* f = listFind<Funcion,int>(l,r.idFuncion,cmpFuncionId);
//      Excluido e = {f->hora,f->diaSem,r.cant};
//      arrAdd<Excluido>(ro->e,e);
//   }
//}
//void mostrarExcluidos(){
//
//}
////Main
//int main()
//{
//   Arr<Teatro> arrTeatro = cargarTeatros();
//   Arr<RObra> arrRObra = cargarObras();
//
//   while(continuarOperando()){
//      Reserva r = leerReserva();
//
//      procesarReserva(r,arrTeatro,arrRObra);
//
//   }
//
//   mostrarExcluidos();
//
//   return 0;
//}
//
//#endif
