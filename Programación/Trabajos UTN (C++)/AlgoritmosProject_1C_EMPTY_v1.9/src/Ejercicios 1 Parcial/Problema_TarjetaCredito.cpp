//#include <iostream>
//#include <string>
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
//#include "Problema_TarjetaCredito.hpp"
//
//using namespace std;
//
////Estructuras usadas
//      //struct Resumen
//      //{
//      //   int fecha;
//      //   int idComercio;
//      //   double importe;
//      //};
//      //struct RCategiria
//      //{
//      //   string categoria;
//      //   Coll<double> totalGastado;
//      //};
//
//
////Funciones
//void invokeWS(int idComercio,string& cat){}
//int fechaObtenerMes(int f){return 0;}
//Coll<double> crearColeccionMes(){
//   Coll<double> c;
//   for(int i=0; i<12; i++){
//      collAdd<double>(c, 0, doubleToString);
//   }
//   return c;
//}
//int cmpRCategiriaNom(RCategiria cat, string nom){
//   return cat.categoria == nom?0:-1;
//}
//void actualizarImporteXMes(Coll<RCategiria>& c, string categoria, int mes, double importe){
//   int pos = collFind<RCategiria,string>(c,categoria,cmpRCategiriaNom,rCategiriaFromString);
//   RCategiria r;
//   if (pos<0){   // Verifico si lo encontro y lo modifico o lo creo
//      r.categoria = categoria;
//      r.totalGastado = crearColeccionMes();
//      collSetAt<double>(r.totalGastado, importe, mes-1, doubleToString);
//      collAdd<RCategiria>(c, r, rCategiriaToString);
//   }else{
//     r = collGetAt<RCategiria>(c, pos, rCategiriaFromString);
//     collSetAt<double>(r.totalGastado, importe, mes-1, doubleToString);
//     collSetAt<RCategiria>(c, r, pos, rCategiriaToString);
//   }
//}
//int cmpRCategiriaX2(RCategiria a, RCategiria b){
//   return b.categoria>a.categoria?1:b.categoria==a.categoria?0:-1;
//}
//void mostrarGastoXMes(RCategiria cat){
//   int cont = 1;
//   while( collHasNext<double>(cat.totalGastado) )
//   {
//      double importe = collNext<double>(cat.totalGastado,stringToDouble); //uso stringToDouble ya que el programa no me creo doubleFromString
//      cout<<"Mes: "<<cont<<"Importe: "<<importe<<endl;
//   }
//}
//void mostrarListado(Coll<RCategiria> c){
//   collSort<RCategiria>(c,cmpRCategiriaX2,rCategiriaFromString,rCategiriaToString);
//   collReset<RCategiria>(c);
//   while( collHasNext<RCategiria>(c) )
//   {
//      RCategiria cat = collNext<RCategiria>(c,rCategiriaFromString);
//      cout << "-----------------------------"<< endl;
//      cout << "CATEGORIA: " << cat.categoria << endl;
//      mostrarGastoXMes(cat);
//      cout << "-----------------------------"<< endl;
//   }
//}
//
//int main()
//{
//   Coll<RCategiria> categorias = collCreate<RCategiria>();
//
//   FILE* resumenR = fopen("RESUMEN.dat","r+b");
//   Resumen r = read<Resumen>(resumenR);
//   while(!feof(resumenR))
//   {
//      //obetengo mes
//      int mes = fechaObtenerMes(r.fecha);
//      //obtengo categoria
//      string cat;
//      invokeWS(r.idComercio,cat);
//      //sumo el importe a mi categoria en dicho mes
//      actualizarImporteXMes(categorias, cat, mes, r.importe);
//
//      r = read<Resumen>(resumenR);
//   }
//   fclose(resumenR);
//
//   mostrarListado(categorias);
//
//   return 0;
//}
