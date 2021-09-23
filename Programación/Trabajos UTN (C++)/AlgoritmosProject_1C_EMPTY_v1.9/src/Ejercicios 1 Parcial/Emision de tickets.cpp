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
//struct Producto
//{
//   int idProd;
//   char descr[20];
//   double precio;
//   int idRub;
//};
//struct Rubro
//{
//   int idRub;
//   char descr[20];
//   double promo;
//};
//struct RRubro{
//   Rubro rub;
//   int ahorro;
//};
//struct Venta
//{
//   Producto p;
//   RRubro r;
//   int ticket;
//   int cant;
//   int descuento;
//   int total;
//};
//
////Funciones
//string productoToString(Producto p){   //idProd, descr, precio, idRub
//   string id = intToString(p.idProd);
//   string des = p.descr;
//   string pre = intToString(p.precio);
//   string idR = intToString(p.idRub);
//   return id +","+ des +","+ pre +","+ idR;
//}
//string rrubroToString(RRubro r){     // idRub, descr, promo, ahorro
//   string id = intToString(r.rub.idRub);
//   string des = r.rub.descr;
////   string prom = doubleToString(r.rub.promo);       //me tira error--------------------------------------------
//   string prom = to_string(r.rub.promo);
////   string prom = "0.95";
//   string ahrr = intToString(r.ahorro);
//   return id +","+ des +","+ prom +","+ ahrr;
//}
//string ventaToString(Venta v){      //ticket, descuento, cant, total, Producto, RRubro
//   string sep = ",";
//   string ticket = intToString(v.ticket);
//   string descu = intToString(v.descuento);
//   string cant = intToString(v.cant);
//   string total = intToString(v.total);
//   return ticket + sep + descu + sep + cant + sep + total + sep + productoToString(v.p) + sep + rrubroToString(v.r);
//}
//Producto stringToProducto(string s){
//   Producto res;
//   char sep = ',';
//   res.idProd = stringToInt(getTokenAt(s,sep,0));
//   strcpy(res.descr,getTokenAt(s,sep,1).c_str());
//   res.precio = stringToInt(getTokenAt(s,sep,2));
//   res.idRub = stringToInt(getTokenAt(s,sep,3));
//   return res;
//}
//RRubro stringToRRubro(string s){
//   RRubro res;
//   char sep = ',';
//   res.rub.idRub = stringToInt(getTokenAt(s,sep,0));
//   strcpy(res.rub.descr,getTokenAt(s,sep,1).c_str());
//   res.rub.promo = stringToDouble(getTokenAt(s,sep,2));
//   res.ahorro = stringToInt(getTokenAt(s,sep,3));
//   return res;
//}
//Venta stringToVenta(string s){
//   Venta v;
//   char sep = ',';
//   v.ticket = stringToInt(getTokenAt(s,sep,0));
//   v.descuento = stringToInt(getTokenAt(s,sep,1));
//   v.cant = stringToInt(getTokenAt(s,sep,2));
//   v.total = stringToInt(getTokenAt(s,sep,3));
//   v.p = stringToProducto(getTokenAt(s,sep,4));
//   v.r = stringToRRubro(getTokenAt(s,sep,5));
//   return v;
//}
//int cmpVentaId(Venta v, int id){
//   return v.p.idProd - id;
//}
//int cmpProductoId(Producto p,int id){
//   return p.idProd - id;
//}
//int cmpRRubroId(RRubro r, int id){
//   return r.rub.idRub - id;
//}
//Coll<Producto> subirProductos(){
//   Coll<Producto> c = collCreate<Producto>();
//   FILE* prodR = fopen("PRODUCTOS.dat","r+b");
//   Producto p = read<Producto>(prodR);
//   while( !feof(prodR) )
//   {
//      collAdd<Producto>(c,p,productoToString);
//      p = read<Producto>(prodR);
//   }
//   fclose (prodR);
//   return c;
//}
//Coll<RRubro> subirRubros(){
//   Coll<RRubro> c = collCreate<RRubro>();
//   FILE* rubR = fopen("RUBROS.dat","r+b");
//   Rubro r = read<Rubro>(rubR);
//   while( !feof(rubR) )
//   {
//      RRubro rr = {r,0};
//      collAdd<RRubro>(c,rr,rrubroToString);
//      r = read<Rubro>(rubR);
//   }
//   fclose (rubR);
//   return c;
//}
//Producto buscarProducto(Coll<Producto> c, int idProd){
//   int pos = collFind<Producto, int>(c,idProd,cmpProductoId,stringToProducto);
//   Producto res = collGetAt<Producto>(c,pos,stringToProducto);
//   return res;
//}
//RRubro buscarRubro(Coll<RRubro> c, int idRub){
//   int pos = collFind<RRubro, int>(c,idRub,cmpRRubroId,stringToRRubro);
//   RRubro res = collGetAt<RRubro>(c,pos,stringToRRubro);
//   return res;
//}
//void actualizarVenta(Coll<Venta>& c, Venta v){
//   int pos = collFind<Venta, int>(c,v.p.idProd,cmpVentaId,stringToVenta);
//   if(pos >= 0){
//      collSetAt<Venta>(c,v,pos,ventaToString);
//   }else{
//      collAdd(c,v,ventaToString);
//   }
//}
//void crearArchivos()
//{
//   //--------------------------Creo todos los archivos----------------------------------
//   // Prod
//   FILE* prodW = fopen("PRODUCTOS.dat","w+b");
//   Producto p1 = {1,"Manteca",100,1};
//   Producto p2 = {2,"Leche",80,1,};
//   Producto p3 = {4,"Escoba",250,2,};
//   Producto p4 = {7,"Galletitas",100,3};
//   Producto p5 = {8,"Aceite",180,3};
//   write<Producto>(prodW,p1);
//   write<Producto>(prodW,p2);
//   write<Producto>(prodW,p3);
//   write<Producto>(prodW,p4);
//   write<Producto>(prodW,p5);
//   fclose(prodW);
//   // Rubro
//   FILE* rubW = fopen("RUBROS.dat","w+b");
//   Rubro r1 = {1,"Lacteo",1};
//   Rubro r2 = {2,"Limpieza",0.95};
//   Rubro r3 = {3,"Almacen",1};
//   write<Rubro>(rubW,r1);
//   write<Rubro>(rubW,r2);
//   write<Rubro>(rubW,r3);
//   fclose(rubW);
//
////   //*COMPROVACION* de archivos creados
////   // Prod
////   FILE* prodR = fopen("PRODUCTOS.dat","r+b");
////   Producto p = read<Producto>(prodR);
////   while( !feof(prodR) )
////   {
////      cout<<"Producto"<<endl;
////      cout<<"IdProd: "<<p.idProd<<"   ";
////      cout<<"descr: "<<p.descr<<"   ";
////      cout<<"precio: "<<p.precio<<"   ";
////      cout<<"idRub: "<<p.idRub<<endl;;
////      p = read<Producto>(prodR);
////   }
////   fclose(prodW);
////   cout<<endl;
////   // Rub
////   FILE* rubR = fopen("RUBROS.dat","r+b");
////   Rubro r = read<Rubro>(rubR);
////   while( !feof(rubR) )
////   {
////      cout<<"Rubro"<<endl;
////      cout<<"idRub: "<<r.idRub<<"   ";
////      cout<<"descr: "<<r.descr<<"   ";
////      cout<<"promo: "<<r.promo<<endl;;
////      r = read<Rubro>(rubR);
////   }
////   fclose(rubR);
////   cout<<endl;
////   //--------------------Fin Creacion de archivos--------------------------
//}
//int main()
//{
//   crearArchivos();
//
//   Coll<Producto> collProd = subirProductos();
//   Coll<RRubro> collRub = subirRubros();
//
//   int ticket;
//   cout<<"Ultimo ticket: ";
//   cin>>ticket;
//
//   int idCli;
//   cout<<"ID_Cliente: ";
//   cin>>idCli;
//   while( idCli>=0 )
//   {
//      Coll<Venta> collVent = collCreate<Venta>();
//
//      int idProd,cantProd;
//      cout<<"Producto: ";
//      cin>>idProd;
//      while( idProd>=0 )
//      {
//         cout<<"Cantidad: ";
//         cin>>cantProd;
//         ticket++;
//
//         // ---------- Punto 1 -----------
//         Venta v;
//         //parte 1   //info productos comprados
//         v.ticket = ticket;
//         v.p = buscarProducto(collProd,idProd);
//         v.cant = cantProd;
//         v.r = buscarRubro(collRub,v.p.idRub);
//         v.descuento = v.p.precio-(v.p.precio*v.r.rub.promo);
//         v.total = (v.p.precio * v.cant)-(v.descuento * v.cant);
//         //parte 2   //info ahorro por rub
//         v.r.ahorro += v.descuento*v.cant;
//         actualizarVenta(collVent,v);
//
//         cout<<"Producto: ";
//         cin>>idProd;
//      }
//      cout<<collVent.s<<endl;
//      cout<<"ID_Cliente: ";
//      cin>>idCli;
//   }
//
//   return 0;
//}
