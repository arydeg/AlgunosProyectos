#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/tads/Arr.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"

using namespace std;
// Estructuras
struct Hora
{
   int h;
   int m;
};
struct Fecha
{
   int anio;
   int mes;
   int seman;
   int dia;
};

struct Obra
{
   int idObra;
   char titulo[100];
   Fecha fEstreno; // TAD
   int idTeatro;
};
struct Teatro
{
   int idTeatro;
   char nombre[50];
   int capacidad;
   int sectores;
};
struct Funcion
{
   int idFuncion;
   int diaSem; // 1=>Lunes, 2=>Martes, ...
   Hora hora; // TAD
};
struct Reserva
{
   int idCliente;
   int idObra;
   int idFuncion;
   int sector; // sector de la sala; ej: Pullman,Platea...
   int cant;
};

struct Sector
{
   int idSector;
   int cap;
   int reservas;
};

struct Rechazados
{
   int cantR;
   int diaSema;

};
struct RObra
{
   Obra o;
   Teatro t;
   List<Funcion> funciones;
   Map<int, List<Sector> > sectores;
   Map<int, List<Rechazados> > rech;
};


//Funciones

Reserva leerReserva()
{
   Reserva r;
   return r;
}
bool continuarOperando()
{
   return false;
}
int capacidadSector(int idTeatro, int sector)
{
   return 0;
}
List<Funcion> funcionesProgramadas(int idObra);

List<RObra> leerObras()
{
   List<RObra> o = List<RObra>();
   return o;
}
List<Teatro> leerTeatros()
{
   List<Teatro> t = List<Teatro>();
   return t;
}
int cmpObras(RObra a, int id)
{
   return a.o.idObra-id;
}
int cmpListObra(RObra a, int id)
{
   return a.o.idObra-id;
}
int cmpTeatros(Teatro a, int b)
{
   return a.idTeatro-b;
}
int cmpSec(Sector a, int b)
{
   return a.cap-b;
}
int cmpFunc(Funcion a, int b)
{
   return a.idFuncion-b;
}

void procesarReservas(Reserva r, List<RObra> obras, List<Teatro> teatro, Map<int, List<RObra> > t)
{
   RObra* obr = listFind<RObra>(obras,r.idObra,cmpObras);
   int id = obr->o.idTeatro;
   List<RObra>* o = mapGet<int, List<RObra>>(t,id);

   if( listFind<RObra>(*o,obr->o.idObra,cmpListObra)==NULL )
   {
      Map<int, Rechazados> rech = Map<int, Rechazados>();

      Teatro* teatr = listFind<Teatro>(teatro,id,cmpTeatros);

      Map<int, List<Sector> > sectores;
      List<Funcion> func = funcionesProgramadas(obr->o.idObra);

      // Para cada funcion
      for( int i = 0; i<listSize(func); i++ )
      {
         Funcion* f = listNext<Funcion>(func);
         List<Sector> listaSectores = List<Sector>();

         //Para cada Sector
         for( int s = 1; s<=teatr->sectores; s++ )
         {
            Sector a = { s, capacidadSector(id,s), 0 };
            listAdd<Sector>(listaSectores,a);
         }
         mapPut<int, List<Sector> >(sectores,f->idFuncion,listaSectores);
      }

   }
   //Busco el Sector
   RObra* ro = listFind<RObra>(*o,obr->o.idObra,cmpListObra);
   List<Sector>* ss = mapGet<int, List<Sector> >(ro->sectores,r.idFuncion);
   Sector* s = listFind<Sector>(*ss,r.sector,cmpSec);

   //Si tiene Capacidad
   if( s->cap<s->reservas )
   {
      s->reservas += r.cant;
   }
   else
   {
      //Si son las primeras rechazadas
      Funcion* f = listFind<Funcion>(ro->funciones,r.idFuncion,cmpFunc);
      if( !mapContains<int, List<Rechazados>>(ro->rech,f->idFuncion) )
      {

         List<Rechazados> n;
         mapPut<int, List<Rechazados>>(ro->rech,f->idFuncion,n);
      }
      else
      {
         Rechazados* n = mapGet<int, List<Rechazados>>(ro->rech,f->idFuncion);
         n->cantR += r.cant;
      }
   }

}
void mostrarDia(Fecha dia)
{
   cout<<dia.dia;
}

void mostrar(List<RObra> obras)
{
   while( listHasNext<RObra>(obras) )
   {
      RObra* ro = listNext<RObra>(obras);
      string s = ro->t.nombre;
      cout<<"Teatro: "<<s<<endl;
      cout<<"Dia Semana: "<<endl;
      cout<<"Sector: "<< ro->sectores<<endl;
      cout<<"Rechazados: "<<ro->rech<<endl;

      while( mapHasNext<int, List<Rechazados> >(ro->rech) )
      {
         Rechazados* re = mapNextValue<int, List<Rechazados>>(ro->rech);
         mostrarDia(ro->o.fEstreno);
         cout << "--------------" << endl;
//         mostrarSector (ro->sectores);
//         mostrarRechazados (ro->rech);

      }
   }
}

int main()
{
   List<RObra> obras = leerObras();
   List<Teatro> teatro = leerTeatros();

   Map<int, List<RObra> > t = Map<int, List<RObra> >();
   while( continuarOperando )
   {
      Reserva r = leerReserva();
      procesarReservas(r,obras,teatro,t);
   }

   mostrar(obras);
   return 0;
}

#endif
