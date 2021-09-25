//#include <iostream>
//#include <string>
//#include <stdlib.h>
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
//#include "PARCIAL_ARY_DEGTIAR.hpp"
//using namespace std;
//
///*       ARY DEGTIAR
// *    curso:   K1041
// *    legajo:  1754210
// *    fecha:   21/8/2020
// */
//
////Estructuras usadas
//      //struct Gasto
//      //{
//      //   int idCons;
//      //   int fecha; // TAD
//      //   double importe;
//      //   char categoria[20];
//      //};
//      //struct Consorcio
//      //{
//      //   int idCons;
//      //   char direccion[50];
//      //   int cantPisos;
//      //};
//      //struct RDepto
//      //{
//      //   int numDepto;
//      //   int piso;
//      //   double porcentaje;
//      //};
//      //struct RConsorcio
//      //{
//      //   Consorcio c;
//      //   double gastosTotales;
//      //   Coll<RDepto> deptos;
//      //};
//
////Funciones
//   // funciones dadas por el profe
//int dtosPorPiso(int idCons,int piso){return 0;}
//double mtsPorcencuales(int idCons,int piso,int depto){return 0;}
//   ////////////
//void subirRDeptos(RConsorcio& consorcio){       //NOTA: p = numero de piso , d = numero de depto
//   //recorro los pisos
//   for(int p=1; p <= consorcio.c.cantPisos; p++){
//      //obtengo cuantos deptos por pisos hay
//      //int deptosXPiso = dtosPorPiso(consorcio.c.idCons, consorcio.c.cantPisos); //error encontrado
//      int deptosXPiso = dtosPorPiso(consorcio.c.idCons, p); //asi se pone bien
//      //recorro los deptos
//      for(int d=1; d <= deptosXPiso; d++){
//         //obtengo porcentaje del depto
//         double porcentajeXDepto = mtsPorcencuales(consorcio.c.idCons, p, d);
//         RDepto depto = {d, p, porcentajeXDepto};
//         //agrego el depto
//         collAdd<RDepto>(consorcio.deptos,depto, rDeptoToString);
//      }
//   }
//}
//Coll<RConsorcio> subirConsorcios(){             //NOTA: cada RConsorcio tiene una collecion de deptos con (numDepto, piso, porcemtaje)
//   Coll<RConsorcio> c = collCreate<RConsorcio>();
//   //recorro consorcios
//   FILE* consorciosR = fopen("CONSORCIOS.dat","r+b");
//   Consorcio cons = read<Consorcio>(consorciosR);
//   while( !feof(consorciosR) )
//   {
//      //lleno la estructura de RConsorcio
//      RConsorcio consorcio;
//      consorcio.c = cons;
//      consorcio.gastosTotales = 0;
//      consorcio.deptos = collCreate<RDepto>();
//
//      //subo los deptos a la collecion de RDepto (que esta dentro de cada consorcio)
//      subirRDeptos(consorcio);
//
//      collAdd<RConsorcio>(c,consorcio,rConsorcioToString);
//      cons = read<Consorcio>(consorciosR);
//   }
//   fclose(consorciosR);
//   return c;
//}
//int cmpRConsorcioId(RConsorcio consorcio, int idCons){
//   return consorcio.c.idCons - idCons;
//}
//void sumarGastoARConsorcio(Coll<RConsorcio>& c, Gasto gasto){
//   //busco el consorcio
//   int pos = collFind<RConsorcio, int>(c,gasto.idCons,cmpRConsorcioId,rConsorcioFromString);
//   RConsorcio cons = collGetAt<RConsorcio>(c,pos,rConsorcioFromString);
//   //le sumo el gasto
//   cons.gastosTotales += gasto.importe;
//   collSetAt<RConsorcio>(c,cons,pos,rConsorcioToString);
//}
//int cmpRDeptoX2(RDepto a,RDepto b){
//   return a.piso - b.piso;
//}
//void mostrarListado(Coll<RConsorcio> c){
//   //recorro la coleccion de RConsorcios para mostrar una lista por cada Rconsorcio
//   collReset(c);
//   while( collHasNext<RConsorcio>(c) ){
//      //obtengo consorcio
//      RConsorcio cons = collNext<RConsorcio>(c,rConsorcioFromString);
//      //muestro datos consorcio
//      cout<<"Consorcio Calle ["<<stringToString(cons.c.direccion)<<"]"<<endl; //uso stringToString ya que no quiero declarar una variable mas por el charArray
//      cout<<"Total, Gastos: $"<<cons.gastosTotales<<endl;
//
//      //ordeno la lista por piso (del menor al mayor)
//      collSort<RDepto>(cons.deptos, cmpRDeptoX2, rDeptoFromString, rDeptoToString);
//
//      //recorro Rdeptos
//      collReset(cons.deptos);
//      while(collHasNext<RDepto>(cons.deptos)){
//         //obtengo depto
//         RDepto dep = collNext<RDepto>(cons.deptos,rDeptoFromString);
//
//         //muestro datos del depto ordenado por piso (piso, depto, porcentajeTotal, total a pagar)
//         double porcentaje  = dep.porcentaje*100;  //es solo visual y use double para ser mas aproximado
//         double totalAPagar = cons.gastosTotales * dep.porcentaje;
//         cout<<"Piso: "<<dep.piso<<" Depto: "<<dep.numDepto<<" Mts: "<<porcentaje<<"% "<<" Total a pagar: ($)"<<totalAPagar<<endl;
//      }
//   }
//}
//
//int main()
//{
//   //subo consorcios a coleccion;
//   Coll<RConsorcio> consorcios = subirConsorcios();
//
//   //recorro el archivo de gastos
//   FILE* gastosR = fopen("GASTOS.dat","r+b");
//   Gasto gasto = read<Gasto>(gastosR);
//   while(!feof(gastosR))
//   {
//      //sumo el gasto al consorcio
//      sumarGastoARConsorcio(consorcios, gasto);
//
//      gasto = read<Gasto>(gastosR);
//   }
//   fclose(gastosR);
//
//   //muestro listado
//   mostrarListado(consorcios);
//
//   return 0;
//}
