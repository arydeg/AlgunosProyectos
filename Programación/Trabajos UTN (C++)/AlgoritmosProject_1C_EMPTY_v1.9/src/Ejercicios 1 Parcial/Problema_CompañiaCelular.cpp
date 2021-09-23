//#include <iostream>
//#include <string>
//#include <stdlib.h>
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
////#include "Problema_CompañiaCelular.hpp"
//using namespace std;
//
////Estructuras usadas
//struct Abonado
//{
//   int idAb;
//   char nombre[20];
//   char direccion[20];
//   int fechaAlta;
//   int idPlan;
//};
////Alpedo
////struct RAbonadoIdx
////{
////   int idAb;
////   int posicion;
////   int minConsumidos;
////   int kbConsmidos;
////};
//struct ConsumoXAbonado  //reemplazo de indexado
//{
//   int idAb;
//   int minConsumidos;
//   double kbConsmidos;
//};
//struct Plan
//{
//   int idPlan;
//   char descr[20];
//   int minutos;
//   int gigas;
//   double precio;
//   double minExced; // precio x min exced
//   double gbExced; // precio x gb exced
//};
//struct RPlan
//{
//   Plan p;
//   double totalFacturado;
//};
//struct Consumo
//{
//   int idAb;
//   int fecha;
//   int tipoCons;  // 1=Llamada, 2=internet
//   int cons;   // tipo=1?minutos:kbytes
//};
//
////Funciones
////toString y fromToString
//string rPlanToString(RPlan c){return "";}
//string rAbonadoIdxToString(ConsumoXAbonado a){return "";}
//ConsumoXAbonado consumoXAbonadoFromString(string s){return {};}
//RPlan rPlanFromString (string s){return {};}
///////////////////////////
//Coll<RPlan> subirPlanes(){
//   Coll<RPlan> coll = collCreate<RPlan>();
//   FILE* f = fopen("PLANES.dat","r+b");
//   Plan plan = read<Plan>(f);
//   while( !feof(f) )
//   {
//      RPlan p = {plan,0};
//      collAdd<RPlan>(coll,p,rPlanToString);
//      plan = read<Plan>(f);
//   }
//   fclose(f);
//   return coll;
//}
//Coll<ConsumoXAbonado> indexarAbonados(FILE* f){
//   Coll<ConsumoXAbonado> coll = collCreate<ConsumoXAbonado>();
//   seek<Abonado>(f,0);
//   Abonado a = read<Abonado>(f);
//   while( !feof(f) )
//   {
//      // creo el elemento con el id , la posicion y algunas variables necesarias
//      //ConsumoXAbonado abonado = { a.idAb, filePos<Abonado>(f)-1, 0, 0 }; no se necesita indexar
//      ConsumoXAbonado abonado = { a.idAb,0, 0 };
//      collAdd<ConsumoXAbonado>(coll,abonado,rAbonadoIdxToString);
//      a = read<Abonado>(f);
//   }
//   return coll;
//}
//int cmpConsumoXAbonadoId(ConsumoXAbonado a, int idAb){
//   return a.idAb - idAb;
//}
//ConsumoXAbonado buscarConsumoAbonado(Coll<ConsumoXAbonado> c,int idAb){
//   int pos = collFind<ConsumoXAbonado,int>(c,idAb,cmpConsumoXAbonadoId,consumoXAbonadoFromString);
//   ConsumoXAbonado a = collGetAt<ConsumoXAbonado>(c, pos, consumoXAbonadoFromString);
//   return a;
//}
////al pedo
////Abonado buscarAbonado(FILE* abonadosR, ConsumoXAbonado idxAbonado){
////   //obtengo el abonado buscando en el archivo ABONADOS atravez del indexado
////   seek<Abonado>(abonadosR,idxAbonado.posicion);
////   Abonado a = read<Abonado>(abonadosR);
////   return a;
////}
//int cmpRPlanId (RPlan plan, int id){
//   return plan.p.idPlan - id;
//}
//RPlan buscarRPlan(Coll<RPlan> c, int idPlan){
//   int pos = collFind<RPlan,int>(c,idPlan,cmpRPlanId,rPlanFromString);
//   RPlan r = collGetAt<RPlan>(c,pos,rPlanFromString);
//   return r;
//}
//void sumarConsumoAbonado(ConsumoXAbonado& a, Consumo cons){
//   if(cons.tipoCons == 1){ //si el consumo es llmadas
//      a.minConsumidos += cons.cons;
//   }else{                  //si el consumo es internet
//      a.kbConsmidos += cons.cons;
//   }
//}
//int calcularMinExtcedidos(int minPlan, int minCons){
//   int res = minCons - minPlan;
//   if(res > 0){      //si existe min excedidos
//      return res;
//   }else{            //si no existe min excedidos
//      return 0;
//   }
//}
//int calcularKBExtcedidos(int gbPlan, int kbCons){
//   int res = kbCons - (gbPlan*1000000);
//   if(res > 0){      //si existe min excedidos
//      return res;
//   }else{            //si no existe min excedidos
//      return 0;
//   }
//}
//double calculPrecioExcedidoGB(double kbExcedidos, double precioGBExt){
//   double cont = 0;
//   while(kbExcedidos >= 0){
//      cont += precioGBExt;
//      kbExcedidos = kbExcedidos/1000000;
//   }
//   return cont;
//}
//void mostrarPunto1(Abonado abonado,ConsumoXAbonado consumoAbonado, RPlan& planAbonado){
//   int minExcedidos = calcularMinExtcedidos(planAbonado.p.minutos,consumoAbonado.minConsumidos);
//   double kbExcedidos = calcularKBExtcedidos(planAbonado.p.gigas,consumoAbonado.kbConsmidos);
//   double precioExcedidoGB = calculPrecioExcedidoGB(kbExcedidos, planAbonado.p.gbExced);
//   double totalExcedido = minExcedidos*planAbonado.p.minExced + precioExcedidoGB;
//   double totalAPagar = planAbonado.p.precio + totalExcedido;
//
//   cout<<endl;
//   cout<<"ID: "<<abonado.idAb<<" nombre: "<<stringToString(abonado.nombre)<<" plan: "<<stringToString(planAbonado.p.descr)<<endl;
//   cout<<"Min consumidos: "<<consumoAbonado.minConsumidos<<" Min Excedidios: "<<minExcedidos<<endl;
//   cout<<"KB Consumidos: "<<consumoAbonado.kbConsmidos<<" KB Excedidios: "<<kbExcedidos<<endl;
//   cout<<"Total plan: "<<planAbonado.p.precio<<" total excedido: "<<totalExcedido<<" total a pagar "<<totalAPagar<<endl;
//   cout<<endl;
//
//   //punto2
//   planAbonado.totalFacturado += totalAPagar;
//}
//void mostrarPunto2(Coll<RPlan> c){
//   collReset(c);
//   while(collHasNext(c)){
//      RPlan cons = collNext(c, rPlanFromString);
//      cout<<"Plan: "<<stringToString(cons.p.descr)<<" total facturado: "<<cons.totalFacturado<<endl;
//   }
//}
//
//int main()
//{
//   Coll<RPlan> planes = subirPlanes();
//   Coll<ConsumoXAbonado> consumosDeAbonados =  collCreate<ConsumoXAbonado>();
//
//   //abro archivo consumosDeAbonados
//   FILE* abonadosR = fopen("ABONADOS.dat","a+b");
//   indexarAbonados(abonadosR);
//
//   //abro archivo consumos
//   FILE* consumosR = fopen("CONSUMOS.dat","cons+b");
//   Consumo cons = read<Consumo>(consumosR);
//   while( !feof(consumosR) )
//   {
//      //obtengo indexado del idxAbonado (en el idx tengo los contadores faltantes de abonado)
//      ConsumoXAbonado consumoAbonado = buscarConsumoAbonado(consumosDeAbonados,cons.idAb);
//
////      //obtengo abonado  al pedo
////      Abonado abonado = buscarAbonado(abonadosR, idxAbonado);
//
//      //sumo consumos en el indexado del consumoAbonado
//      sumarConsumoAbonado(consumoAbonado, cons);
//
//      cons = read<Consumo>(consumosR);
//   }
//   fclose(consumosR);
//
//   //recorro cada abonado para mostrar punto 1
//   seek<Abonado>(abonadosR,0);
//   Abonado abonado = read<Abonado>(abonadosR);
//   while(!feof(abonadosR))
//   {
//      //obtengo rplan del abonado
//      RPlan planAbonado = buscarRPlan(planes, abonado.idPlan);
//      //obstengo idxAbonado
//      ConsumoXAbonado consumoAbonado = buscarConsumoAbonado(consumosDeAbonados,abonado.idAb);
//
//      mostrarPunto1(abonado, consumoAbonado, planAbonado);  //aca dentro se suma lo totalfacturado de cada plan (punto 2)
//
//      abonado = read<Abonado>(abonadosR);
//   }
//   fclose(abonadosR);
//
//   mostrarPunto2(planes);
//
//   return 0;
//}
