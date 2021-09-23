//#include <iostream>
//#include <string>
//#include <stdlib.h>  //valor abs
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
//#include "Problema_Aviacion_2.hpp"
//
//using namespace std;
////Estructuras usadas
//   //struct Ciudad
//   //{
//   //   int idCiu;
//   //   char descr[20];
//   //   int millas;
//   //};
//   //struct Vuelo
//   //{
//   //   int idVue;
//   //   int cap;
//   //   int idOri; // idCiu origen
//   //   int idDes; // idCiu origen
//   //};
//   //struct Reserva
//   //{
//   //   int idCli;
//   //   int idVue;
//   //   int cant;
//   //};
//   //struct RCliente
//   //{
//   //   int idCli;
//   //   int millas = 0;
//   //};
//   //struct RVuelo
//   //{
//   //   Vuelo v;
//   //   int pRecha = 0;
//   //   int pAcept = 0;
//   //};
//   //struct RCiudad
//   //{
//   //   Ciudad c;
//   //   int familias = 0;
//   //};
//
////Funciones
//   ////toString y fromToString
//   //string rVueloToString(RVuelo v){
//   //   return "";
//   //}
//   //string rCiudadToString(RCiudad c){
//   //   return "";
//   //}
//   //string rClienteToString(RCliente c){
//   //   return "";
//   //}
//   //RCliente rClienteFromString(string s){
//   //   return {};
//   //}
//   //RVuelo rVueloFromString(string s){
//   //   return {};
//   //}
//   //RCiudad rCiudadFromString(string s){
//   //   return {};
//   //}
//   ///////////////////////////
//
//Coll<RCiudad> subirCuidad(){
//   Coll<RCiudad> c = collCreate<RCiudad>();
//   FILE* ciudadR = fopen("CIUDADES.dat","r+b");
//   Ciudad ciudad = read<Ciudad>(ciudadR);
//   while( !feof(ciudadR) )
//   {
//      RCiudad ciu = {ciudad, 0};
//      collAdd<RCiudad>(c,ciu, rCiudadToString);
//      ciudad = read<Ciudad>(ciudadR);
//   }
//   fclose(ciudadR);
//   return c;
//}
//Coll<RVuelo> subirVuelo(){
//   Coll<RVuelo> c = collCreate<RVuelo>();
//   FILE* vueloR = fopen("VUELOS.dat","r+b");
//   Vuelo v = read<Vuelo>(vueloR);
//   while( !feof(vueloR) )
//   {
//      RVuelo vue = {v, 0, 0};
//      collAdd<RVuelo>(c,vue, rVueloToString);
//      v = read<Vuelo>(vueloR);
//   }
//   fclose(vueloR);
//   return c;
//}
//int cmpRVueloIdVue(RVuelo v, int idVue){
//   return v.v.idVue - idVue;
//}
//RVuelo obtenerVuelo(Coll<RVuelo> c, int idVue){
//   int pos = collFind<RVuelo,int>(c, idVue, cmpRVueloIdVue, rVueloFromString);
//   RVuelo r = collGetAt<RVuelo>(c, pos, rVueloFromString);
//   return r;
//}
//int cmpRCiudadIdCiu(RCiudad c, int idCiu){
//   return c.c.idCiu - idCiu;
//}
//RCiudad obtenerCiudad(Coll<RCiudad> c, int idCiu){
//   int pos = collFind<RCiudad, int>(c,idCiu,cmpRCiudadIdCiu,rCiudadFromString);
//   RCiudad ciu = collGetAt<RCiudad>(c,pos,rCiudadFromString);
//   return ciu;
//}
//int cmpRClienteIdCli(RCliente c, int idCli){
//   return c.idCli - idCli;
//}
//RCliente obtenerCliente(Coll<RCliente> c, int idCli){
//   int pos = collFind<RCliente, int>(c,idCli,cmpRClienteIdCli,rClienteFromString);
//   RCliente cli = collGetAt<RCliente>(c,pos,rClienteFromString);
//   return cli;
//}
//int cmpRClienteId(RCliente r, int idCli){
//   return r.idCli - idCli;
//}
//void actualizarCliente(Coll<RCliente>& c, int idCli, int m){
//   int pos = collFind<RCliente,int>(c, idCli, cmpRClienteId, rClienteFromString);   //busca posicion de cliente en la coleccion
//   if (pos<0){     //si no lo encuentra lo crea y lo sube a la coleccion
//      RCliente cli = {idCli,m};
//      collAdd<RCliente>(c, cli, rClienteToString);
//   }else{          //si lo encuetra le suma las millas
//      RCliente cli = collGetAt<RCliente>(c, pos, rClienteFromString);
//      cli.millas += m;
//      collSetAt<RCliente>(c, cli, pos, rClienteToString);
//   }
//}
//int cmpRCiudadX2(RCiudad a, RCiudad b){
//   return a.c.idCiu - b.c.idCiu;
//}
//void actualizarCiudad(Coll<RCiudad>& c, RCiudad ciu){
//   int pos = collFind<RCiudad,RCiudad>(c, ciu, cmpRCiudadX2, rCiudadFromString);   //busca posiscion de ciudad en la coleccion
//   collSetAt<RCiudad>(c, ciu, pos, rCiudadToString);
//}
//
//
//int main()
//{
//   Coll<RCiudad> ciudades = subirCuidad();
//   Coll<RVuelo> vuelos = subirVuelo();
//
//   Coll<RCliente> clientes = collCreate<RCliente>();
//
//   FILE* f = fopen("RESERVAS.dat","r+b");
//   Reserva r = read<Reserva>(f);
//   RVuelo vue = obtenerVuelo(vuelos, r.idVue);  //obtengo el vuelo
//   RCiudad ciuOri = obtenerCiudad(ciudades, vue.v.idOri); //obtengo ciudad origen
//   RCiudad ciuDes = obtenerCiudad(ciudades, vue.v.idDes); //obtengo ciudad destino
//   while(!feof(f))
//   {
//      if((vue.v.cap - vue.pAcept) - r.cant >= 0){  //si la cantidad de plazas es mayor o igual a la cantidad de reservas es aceptada
//         //calculo las millas para acumular al cliente (punto 3)
//         int millas = abs(ciuOri.c.millas - ciuDes.c.millas);
//         millas = millas * r.cant;
//         actualizarCliente(clientes, r.idCli, millas);
//         vue.pAcept += r.cant;   //cantidad de plazas aceptadas (parte del punto 2)
//      }else{
//         //si rechazo la reserva sumo cantidad de plazas rechazadas (punto 2)
//         vue.pRecha += r.cant;
//      }
//
//      //punto 1
//      ciuDes.familias++;
//      actualizarCiudad(ciudades, ciuDes);
//
//      r = read<Reserva>(f);
//   }
//
//   //punto 1
//   string ciudad = ciuDes.c.descr;
//   cout<<"las familias que eligen a la ciudad: "<<ciudad<<" son: "<<ciuDes.familias<<endl;
//
//   //punto 2
//   if((vue.v.cap - vue.pAcept)==0){ //si el vuelo va completo
//      cout<<"el vuelo: "<<vue.v.idVue<<"tiene "<<vue.pRecha<<" plazas rechazadas y va COMPLETO"<<endl;
//   }else{
//      cout<<"el vuelo: "<<vue.v.idVue<<"tiene "<<vue.pRecha<<" plazas rechazadas y va INCOMPLETO"<<endl;
//   }
//
//   //punto 3
//   RCliente cli = obtenerCliente(clientes, r.idCli); //obtengo cliente
//   cout<<"las millas del cliente: "<<cli.idCli<<" son "<<cli.millas<<endl;
//
//
//   return 0;
//}
