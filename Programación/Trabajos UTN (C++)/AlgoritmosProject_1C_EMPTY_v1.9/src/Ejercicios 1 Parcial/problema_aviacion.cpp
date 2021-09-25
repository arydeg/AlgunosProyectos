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
//// Esctructuras
//struct Ciudad
//{
//   int idCiu;
//   char descr[15];
//   int millas;
//};
//struct RCiudad
//{
//   Ciudad ciu;
//   int cont = 0;
//};
//struct Vuelo
//{
//   int idVue;
//   int cap;
//   int idOri; // idCiu origen
//   int idDes; // idCiu des
//};
//struct RVuelo
//{
//   Vuelo vue;
//   int plazasR = 0;
//   int plazasA = 0;
//};
//struct Reserva
//{
//   int idCli;
//   int idVue;
//   int cant;
//};
//struct RCliente
//{
//   int idCli;
//   int millas;
//};
//
//// Funciones
//string charArrToString(char arr[]){       // al final no lo use por q es al pedo. direcamente lo iguales string = char[]
//   string res;
//   for(int i=0; arr[i]!='\0'; i++){
//         res+=charToString(arr[i]);
//   }
//   return res;
//}
//int cmpRVueloId(RVuelo v,int id){
//   return v.vue.idVue - id;
//}
//int cmpRCiudadId(RCiudad c,int idDes){
//   return c.ciu.idCiu - idDes;
//}
//int cmpRClienteId(RCliente c,int idCli){
//   return c.idCli - idCli;
//}
//string rciudadToString(RCiudad x){                 // idciu,descr,millas,cont
//   string idciu = intToString(x.ciu.idCiu);
//   //string descr;
//   //strcpy(x.ciu.descr,descr.c_str()); NO ME FUNCA, ya que es para pasar de string a char[]
//   string descr = x.ciu.descr;
//   //string descr = charArrToString(x.ciu.descr); // funcion by ary. aclarado mas arriba (al pedo)
//   string millas = intToString(x.ciu.millas);
//   string cont = intToString(x.cont);
//   string s = idciu + "," + descr + "," + millas + "," + cont;
//   return s;
//}
//string rvueloToString(RVuelo x){      //idVue, cap, idOri, idDes, plazasR, plazasA
//   string idVue = intToString(x.vue.idVue);
//   string cap = intToString(x.vue.cap);
//   string idOri = intToString(x.vue.idOri);
//   string idDes = intToString(x.vue.idDes);
//   string plazasR = intToString(x.plazasR);
//   string plazasA = intToString(x.plazasA);
//   string s = idVue + "," + cap + "," + idOri + "," + idDes + "," + plazasR + "," + plazasA;
//   return s;
//}
//string rclienteToString(RCliente x){         //idCli, millas
//   string idCli = intToString(x.idCli);
//   string millas = intToString(x.millas);
//   string s = idCli + "," + millas;
//   return s;
//}
//RVuelo stringToRVuelo(string s){
//   RVuelo v;
//   char sep = ',';
//   v.vue.idVue = stringToInt(getTokenAt(s,sep,0));
//   v.vue.cap = stringToInt(getTokenAt(s,sep,1));
//   v.vue.idOri = stringToInt(getTokenAt(s,sep,2));
//   v.vue.idDes = stringToInt(getTokenAt(s,sep,3));
//   v.plazasR = stringToInt(getTokenAt(s,sep,4));
//   v.plazasA = stringToInt(getTokenAt(s,sep,5));
//   return v;
//}
//RCiudad stringToRCiudad(string s){
//   RCiudad c;
//   char sep = ',';
//   c.ciu.idCiu = stringToInt(getTokenAt(s,sep,0));
//   strcpy(c.ciu.descr,getTokenAt(s,sep,1).c_str());
//   c.ciu.millas = stringToInt(getTokenAt(s,sep,2));
//   c.cont = stringToInt(getTokenAt(s,sep,3));
//   return c;
//}
//RCliente stringToRCliente(string s){
//   RCliente c;
//   char sep = ',';
//   c.idCli = stringToInt(getTokenAt(s,sep,0));
//   c.millas = stringToInt(getTokenAt(s,sep,1));
//   return c;
//}
//Coll<RCiudad> subirCiudades()
//{
//   Coll<RCiudad> res = collCreate<RCiudad>();
//   FILE* ciudadR = fopen("Ciudad.txt","r+b");
//   Ciudad ciu = read<Ciudad>(ciudadR);
//   while( !feof(ciudadR) )
//   {
//      RCiudad c = {ciu,0};
//      collAdd<RCiudad>(res,c,rciudadToString);
//      ciu = read<Ciudad>(ciudadR);
//   }
//   fclose(ciudadR);
//   return res;
//}
//Coll<RVuelo> subirVuelos()
//{
//   Coll<RVuelo> res = collCreate<RVuelo>();
//   FILE* vueloR = fopen("Vuelo.txt","r+b");
//   Vuelo vue = read<Vuelo>(vueloR);
//   while( !feof(vueloR) )
//   {
//      RVuelo c = {vue,0,0};
//      collAdd<RVuelo>(res,c,rvueloToString);
//      vue = read<Vuelo>(vueloR);
//   }
//   fclose(vueloR);
//   return res;
//}
//RVuelo buscarVuelo(Coll<RVuelo> c,int idVue){
//   int pos = collFind<RVuelo,int>(c,idVue,cmpRVueloId,stringToRVuelo);
//   RVuelo res = collGetAt<RVuelo>(c,pos,stringToRVuelo);
//   return res;
//}
//RCiudad buscarCiudad(Coll<RCiudad> c,int idCiu){
//   int pos = collFind<RCiudad,int>(c, idCiu, cmpRCiudadId, stringToRCiudad);
//   RCiudad res = collGetAt<RCiudad>(c, pos, stringToRCiudad);
//   return res;
//}
//RCliente buscarCliente(Coll<RCliente> c, int idCli){
//   int pos = collFind<RCliente,int>(c,idCli,cmpRClienteId,stringToRCliente);
//   RCliente res = collGetAt<RCliente>(c,pos,stringToRCliente);
//   return res;
//}
//void actualizarVuelo(Coll<RVuelo>& c,RVuelo v){
//   int pos = collFind<RVuelo,int>(c, v.vue.idVue, cmpRVueloId, stringToRVuelo);
//   collSetAt<RVuelo>(c,v,pos,rvueloToString);
//}
//void actualizarCiudad(Coll<RCiudad>& c, RCiudad ciu){
//   int pos = collFind<RCiudad,int>(c, ciu.ciu.idCiu, cmpRCiudadId, stringToRCiudad);
//   collSetAt<RCiudad>(c,ciu,pos,rciudadToString);
//}
//void actualizarRCliente(Coll<RCliente>& c, RCliente cli){
//   int pos = collFind<RCliente,int>(c, cli.idCli, cmpRClienteId, stringToRCliente);
//   collSetAt<RCliente>(c,cli,pos,rclienteToString);
//}
//bool existeRCliente(Coll<RCliente> c, int idCli){
//   int z = collFind<RCliente,int>(c,idCli,cmpRClienteId,stringToRCliente);
//   if (z>=0){
//      return true;
//   }else{
//      return false;
//   }
//}
//void anadirCliente(Coll<RCliente>& c, RCliente cli){
//   collAdd<RCliente>(c,cli,rclienteToString);
//}
//void mostrarPunto1(Coll<RCliente> c){
//   cout<<"---------------"<<endl;
//   cout<<"Punto 1"<<endl;
//   for(int i=0; i<collSize(c);i++){
//      RCliente res = collGetAt(c,i,stringToRCliente);
//      cout<<"La cantidad de millas del cliente "<<res.idCli<<" son: "<<res.millas<<endl;
//   }
//   cout<<"---------------"<<endl;
//}
//void mostrarPunto2(Coll<RCiudad> c){
//   cout<<"---------------"<<endl;
//   cout<<"Punto 2"<<endl;
//   for(int i=0; i<collSize(c);i++){
//      RCiudad res = collGetAt(c,i,stringToRCiudad);
//      cout<<"La cantidad de grupos/familias que eligieron la ciuadad "<<res.ciu.idCiu<<" como destino son: "<<res.cont<<endl;
//   }
//   cout<<"---------------"<<endl;
//}
//void mostrarPunto3(Coll<RVuelo> c){
//   cout<<"---------------"<<endl;
//   cout<<"Punto 3"<<endl;
//   for(int i=0; i<collSize(c);i++){
//      RVuelo res = collGetAt(c,i,stringToRVuelo);
//      cout<<"Plazas rechazadas del vuelo id "<<res.vue.idVue<<": "<<res.plazasR<<endl;
//      if(res.plazasA==res.vue.cap){
//         cout<<"Vuelo: COMPLETO"<<endl;
//      }else{
//         cout<<"Vuelo: INCOMPLETO"<<endl;
//      }
//   }
//   cout<<"---------------"<<endl;
//}
//void crearTodosLosFuckingArchivos()
//{
//   //--------------------------Creo todos los archivos----------------------------------
//   // Ciudad
//   FILE* ciudadW = fopen("Ciudad.txt","w+b");
//   Ciudad c1 = { 1, "BSAS", 500 };
//   Ciudad c2 = { 2, "ROSARIO", 1000 };
//   write<Ciudad>(ciudadW,c1);
//   write<Ciudad>(ciudadW,c2);
//   fclose(ciudadW);
//   // Vuelo
//   FILE* vueloW = fopen("Vuelo.txt","w+b");
//   Vuelo v1 = { 1, 100, 1, 2 };
//   Vuelo v2 = { 2, 200, 2, 1 };
//   write<Vuelo>(vueloW,v1);
//   write<Vuelo>(vueloW,v2);
//   fclose(vueloW);
//   // Reserva
//   FILE* reservaW = fopen("Reserva.txt","w+b");
//   Reserva r1 = { 123, 1, 100 };
//   Reserva r2 = { 345, 2, 150 };
//   Reserva r3 = { 444, 2, 60 };
//   Reserva r4 = { 345, 2, 25 };
//   write<Reserva>(reservaW,r1);
//   write<Reserva>(reservaW,r2);
//   write<Reserva>(reservaW,r3);
//   write<Reserva>(reservaW,r4);
//   fclose(reservaW);
//
//   //*COMPROVACION* de archivos creados
////   // Ciudad
////   FILE* ciudadR = fopen("Ciudad.txt","r+b");
////   Ciudad ciu = read<Ciudad>(ciudadR);
////   while( !feof(ciudadR) )
////   {
////      cout<<"Ciudad"<<endl;
////      cout<<"Id: "<<ciu.idCiu<<endl;
////      cout<<"Descripcion: "<<ciu.descr<<endl;
////      cout<<"Millas: "<<ciu.millas<<endl;
////      ciu = read<Ciudad>(ciudadR);
////   }
////   fclose(ciudadR);
////   cout<<endl;
////   // Vuelo
////   FILE* vueloR = fopen("Vuelo.txt","r+b");
////   Vuelo vue = read<Vuelo>(vueloR);
////   while( !feof(vueloR) )
////   {
////      cout<<"Vuelo"<<endl;
////      cout<<"Id: "<<vue.idVue<<endl;
////      cout<<"Capacidad: "<<vue.cap<<endl;
////      cout<<"ID ciudad origen: "<<vue.idOri<<endl;
////      cout<<"ID ciudad origen: "<<vue.idDes<<endl;
////      vue = read<Vuelo>(vueloR);
////   }
////   fclose(vueloR);
////   cout<<endl;
////   // Reserva
////   FILE* reservaR = fopen("Reserva.txt","r+b");
////   Reserva res = read<Reserva>(reservaR);
////   while( !feof(reservaR) )
////   {
////      cout<<"Reserva"<<endl;
////      cout<<"Id Cliente: "<<res.idCli<<endl;
////      cout<<"ID Vuelo: "<<res.idVue<<endl;
////      cout<<"Cant reservas: "<<res.cant<<endl;
////      res = read<Reserva>(reservaR);
////   }
////   fclose(reservaR);
//   //--------------------Fin Creacion de archivos--------------------------
//}
//
//int main()
//{
//   crearTodosLosFuckingArchivos();
//
//   Coll<RCiudad> ciu = subirCiudades();
//   Coll<RVuelo> vue = subirVuelos();
//   Coll<RCliente> cli = collCreate<RCliente>();
//
//   FILE* reservaR = fopen("Reserva.txt","r+b");
//   Reserva res = read<Reserva>(reservaR);
//   while( !feof(reservaR) )
//   {
//      RVuelo vuelo = buscarVuelo(vue,res.idVue);
//      bool plazasAceptadasP1;
//      // ----------------Punto 3 INICIO--------------------
//      int verifPlazasas = vuelo.plazasA + res.cant;
//      if(verifPlazasas <= vuelo.vue.cap){
//         vuelo.plazasA += res.cant;
//         actualizarVuelo(vue,vuelo);
//         plazasAceptadasP1 = true;
//      }else{
//         vuelo.plazasR += res.cant;
//         actualizarVuelo(vue,vuelo);
//         plazasAceptadasP1 = false;
//      }
//      // -----------------Punto 3 FIN---------------------
//      // ----------------Punto 2 INICIO--------------------      //voy a suponer que al refirirse a familias es cada reserva
//      int idDestino = vuelo.vue.idDes;
//      RCiudad ciudad = buscarCiudad(ciu,idDestino);
//      ciudad.cont = ciudad.cont + 1;
//      actualizarCiudad(ciu,ciudad);
//      // -----------------Punto 2 FIN---------------------
//      // ----------------Punto 1 INICIO--------------------
//      int millasCiudadDes = ciudad.ciu.millas;
//      int idOrigen = vuelo.vue.idOri;
//      RCiudad ciudad2 = buscarCiudad(ciu,idOrigen);
//      int millasCiudadOri = ciudad2.ciu.millas;
//      int millasCli = abs(millasCiudadDes - millasCiudadOri)*res.cant;
//      if(plazasAceptadasP1){
//         if (existeRCliente(cli,(int)res.idCli)){
//            RCliente cliente = buscarCliente(cli,res.idCli);
//            cliente.millas = cliente.millas + millasCli;
//            actualizarRCliente(cli,cliente);
//         }else{
//            RCliente cliente = {res.idCli,millasCli};
//            anadirCliente(cli,cliente);
//         }
//      }
//      // -----------------Punto 1 FIN---------------------
//      res = read<Reserva>(reservaR);
//   }
//   mostrarPunto3(vue);
//   mostrarPunto2(ciu);
//   mostrarPunto1(cli);
//   fclose(reservaR);
//
//   return 0;
//}
