//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include "../biblioteca/funciones/strings.hpp"
//#include "../biblioteca/funciones/tokens.hpp"
//#include "../biblioteca/funciones/files.hpp"
//#include "../biblioteca/tads/Coll.hpp"
//#include "problema_futbol.hpp"
//using namespace std;
//
//// Estructuras Usadas
//      //struct Resultado
//      //{
//      //   int idEq1;
//      //   int idEq2;
//      //   int idCR; // codigo de resultado
//      //   string estadio;
//      //};
//      //struct Equipo
//      //{
//      //   int idEq;
//      //   string nombre;
//      //   int puntos;
//      //};
//      //struct REstadio
//      //{
//      //   string nombre;
//      //   int partidos;
//      //   int partidosEmp;
//      //};
//
////Funciones
//Coll<Equipo> subirEquipos(){
//   Coll<Equipo> c = collCreate<Equipo>();
//   FILE* equiposR = fopen("EQUIPOS.txt","r+b");
//   Equipo equi = read<Equipo>(equiposR);
//   while( !feof(equiposR) )
//   {
//      collAdd<Equipo>(c,equi,equipoToString);
//      equi = read<Equipo>(equiposR);
//   }
//   fclose(equiposR);
//   return c;
//}
//int cmpEquipoId(Equipo e, int id){
//   return e.idEq - id;
//}
//Equipo obtenerEquipo(Coll<Equipo> c, int idEq){
//   int pos = collFind<Equipo, int>(c,idEq,cmpEquipoId,equipoFromString);
//   Equipo e = collGetAt<Equipo>(c,pos,equipoFromString);
//   return e;
//}
//void actualizarPuntosEquipo(Coll<Equipo>& c, Equipo equipo){
//   int posEq = collFind<Equipo,int>(c, equipo.idEq, cmpEquipoId, equipoFromString);
//   collSetAt<Equipo>(c,equipo, posEq, equipoToString);
//}
//int cmpEquipoX2(Equipo e1, Equipo e2){
//   return e2.puntos - e1.puntos;
//}
//void mostrarTablaPosiciones(Coll<Equipo> c){
//   collSort<Equipo>(c,cmpEquipoX2,equipoFromString,equipoToString);
//   for(int i=0; i<collSize(c); i++){
//      Equipo e = collGetAt<Equipo>(c, i, equipoFromString);
//      cout<<e.nombre<<"  Puntos: "<<e.puntos<<endl;
//   }
//}
//int cmpEstadioNom(REstadio e, string nom){
//   return e.nombre == nom?0:-1;
//}
//void actualizarPuntosEstadio(Coll<REstadio>& c, string est, int contPJ, int contPE){
//   int pos = collFind<REstadio,string>(c, est, cmpEstadioNom, rEstadioFromString);
//   if(pos >= 0){  //Si el estadio esta en mi colección se acutaliza
//      REstadio estadio = collGetAt<REstadio>(c, pos, rEstadioFromString);
//      estadio.partidos = contPJ;
//      estadio.partidosEmp = contPE;
//      collSetAt<REstadio>(c, estadio, pos, rEstadioToString);
//   }else{         //Si el estadio no esta en mi colección se crea
//      REstadio estadio = {est, contPJ, contPE};
//      collAdd<REstadio>(c, estadio, rEstadioToString);
//   }
//}
//void mostrarPatidosJugYEmp(Coll<REstadio> c){
//   for(int i=0; i<collSize(c); i++){
//      REstadio e = collGetAt<REstadio>(c, i, rEstadioFromString);
//      cout<<"ESTADIO: "<< e.nombre <<endl;
//      cout<<"Partidos jugados "<< e.partidos <<endl;
//      cout<<"Partidos empatados "<< e.partidosEmp <<endl;
//   }
//}
//
//int main()
//{
//   Coll<Equipo> equipos = subirEquipos();
//   Coll<REstadio> estadios = collCreate<REstadio>();
//
//   FILE* resultadosR = fopen("RESULTADOS.txt","r+b");
//   Resultado r = read<Resultado>(resultadosR);
//   while( !feof(resultadosR) )
//   {
//      //Obtengo equipos del partido
//      Equipo equipo1 = obtenerEquipo(equipos, r.idEq1);
//      Equipo equipo2 = obtenerEquipo(equipos, r.idEq2);
//
//      int contPartidosJugados = 0, contPartidosEmpatados = 0;
//
//      //Sumo los puntajes obtenidos a los equipos
//      if(r.idCR < 0){
//         equipo1.puntos += 3;
//      }else if(r.idCR > 0){
//         equipo2.puntos += 3;
//      }else{
//         equipo1.puntos += 1;
//         equipo2.puntos += 1;
//         //Cuento los partidos empatados (punto 2)
//         contPartidosEmpatados ++;
//      }
//      actualizarPuntosEquipo(equipos, equipo1);
//      actualizarPuntosEquipo(equipos, equipo2);
//
//      //Cuento los partidos jugados (punto 2)
//      contPartidosJugados ++;
//      actualizarPuntosEstadio(estadios, r.estadio, contPartidosJugados, contPartidosEmpatados);
//
//      r = read<Resultado>(resultadosR);
//   }
//   fclose(resultadosR);
//   //Muestro punto 1
//   mostrarTablaPosiciones(equipos);
//
//   //Muestro punto 2
//   mostrarPatidosJugYEmp(estadios);
//
//   return 0;
//}
