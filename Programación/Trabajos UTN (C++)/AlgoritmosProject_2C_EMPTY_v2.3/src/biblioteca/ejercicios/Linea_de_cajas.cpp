//#ifndef _MAIN
//#define _MAIN
//#include <iostream>
//#include "../biblioteca/tads/Arr.hpp"
//#include "../biblioteca/tads/Map.hpp"
//#include "../biblioteca/tads/List.hpp"
//#include "../biblioteca/tads/Stack.hpp"
//#include "../biblioteca/tads/Queue.hpp"
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/lists.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//using namespace std;
//
////TAD
//struct Hora{};
//int horaDif(Hora h1, Hora h2){return 0;}
//
////Estructuras
//struct Mov
//{
//   int caja;
//   char mov; // 'E' => Entra, 'S' => Sale Hora hora; // TAD };
//   Hora hora; // TAD
//};
//struct Caja
//{
//   Queue<Hora> q = queue<Hora>();
//   int longMax;
//   int tiempPromEspera;
//   int tiempOcioso;
//   int clientes;
//   Hora contOcioso;
//};
////Funciones
//Caja* buscarCaja(Map<int,Caja> mapCajas,Mov m){
//   bool contiene = false;
//   while(mapHasNext<int,Caja>(mapCajas)){
//      if(mapContains<int,Caja>(mapCajas,m.caja)){
//         contiene = true;
//      }
//   }
//   if(!contiene){
//      Caja c;
//      c.longMax = 0;
//      c.tiempOcioso = 0;
//      c.tiempPromEspera = 0;
//      c.clientes = 0;
//      mapPut<int, Caja>(mapCajas,m.caja,c);
//   }
//   Caja* res = mapGet<int,Caja>(mapCajas,m.caja);
//   return res;
//}
//void procesarMovimientoEntrada(Mov m,Caja* c){
//   if(queueIsEmpty(c->q)){
//      c->tiempOcioso += horaDif(c->contOcioso,m.hora);
//   }
//   queueEnqueue(c->q,m.hora);
//}
//void procesarMovimientoSalida(Mov m,Caja* c){
//   int dif;
//   Hora hraEntrada = queueDequeue(c->q);
//   dif = horaDif(hraEntrada,m.hora);
//   c->clientes++;
//   c->tiempPromEspera += dif;
//
//   if(queueIsEmpty(c->q)){
//      c->contOcioso = m.hora;
//      //verifico la longitud maxima
//      if(c->clientes>c->longMax){
//         c->longMax = c->clientes;
//         c->clientes = 0;
//      }
//   }
//}
//void mostrarPuntos(Map<int,Caja> map){
//   while(mapHasNext<int,Caja>(map)){
//      int idCaja = mapNextKey<int,Caja>(map);
//      Caja* c = mapGet<int,Caja>(map,idCaja);
//      //punto 1
//      c->tiempPromEspera = c->tiempPromEspera/c->clientes;
//      cout<<"Tiempo promedio de espera de la caja: "<<idCaja<<" es de: "<< c->tiempPromEspera <<endl;
//      //punto 2
//      cout<<"la sumatoria del tiempo ocioso es de: "<< c->tiempOcioso <<endl;
//      //punto 3
//      cout<<"la Longitud máxima es de: "<< c->longMax <<endl;
//
//      cout<<"--------------"<<endl;
//   }
//}
////Main
//int main()
//{
//   //declaro map de cajas
//   Map<int,Caja> mapCajas = map<int,Caja>();
//
//   FILE* movR = fopen("MOVIMIENTOS.dat","r+b");
//   Mov m = read<Mov>(movR);
//   while( !feof(movR) )
//   {
//      Caja* c = buscarCaja(mapCajas,m);
//
//      if( m.mov=='E' ){
//         procesarMovimientoEntrada(m,c);
//      }else{
//         procesarMovimientoSalida(m,c);
//      }
//
//      m = read<Mov>(movR);
//   }
//   fclose(movR);
//
//   mostrarPuntos(mapCajas);//dividir para mostrar el promedio
//
//   return 0;
//}
//
//#endif

