#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../biblioteca/funciones/strings.hpp"
#include "../biblioteca/funciones/tokens.hpp"
#include "../biblioteca/tads/Coll.hpp"
using namespace std;

struct Resumen
{
   int fecha;
   int idComercio;
   double importe;
};

struct RCategiria
{
   string categoria;
   Coll<double> totalGastado;
};

string resumenToString(Resumen x)
{
   char sep = 1;
   string sFecha=to_string(x.fecha);
   string sIdComercio=to_string(x.idComercio);
   string sImporte=to_string(x.importe);
   return sFecha+sep+sIdComercio+sep+sImporte;
}

Resumen resumenFromString(string s)
{
   char sep = 1;
   Resumen x;
   string t0 = getTokenAt(s,sep,0);
   x.fecha=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.idComercio=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.importe=stod(t2);
   return x;
}

string resumenToDebug(Resumen x)
{
   stringstream sout;
   sout<< "[";
   sout << x.fecha;
   sout << ",";
   sout << x.idComercio;
   sout << ",";
   sout << x.importe;
   sout<< "]";
   return sout.str();
}

Resumen resumen(int fecha,int idComercio,double importe)
{
   Resumen a;
   a.fecha = fecha;
   a.idComercio = idComercio;
   a.importe = importe;
   return a;
}

bool resumenEquals(Resumen a,Resumen b)
{
   if(a.fecha!=b.fecha) return false;
   if(a.idComercio!=b.idComercio) return false;
   if(a.importe!=b.importe) return false;
   return true;
}

string rCategiriaToString(RCategiria x)
{
   char sep = 2;
   string sCategoria=x.categoria;
   string sTotalGastado=collToString<double>(x.totalGastado);
   return sCategoria+sep+sTotalGastado;
}

RCategiria rCategiriaFromString(string s)
{
   char sep = 2;
   RCategiria x;
   string t0 = getTokenAt(s,sep,0);
   x.categoria=t0;
   string t1 = getTokenAt(s,sep,1);
   x.totalGastado=collFromString<double>(t1);
   return x;
}

string rCategiriaToDebug(RCategiria x)
{
   stringstream sout;
   sout<< "[";
   sout << x.categoria;
   sout << ",";
   collReset<double>(x.totalGastado);
   while(collHasNext<double>(x.totalGastado))
   {
      double q = collNext<double>(x.totalGastado,stringToDouble);
      sout << doubleToString(q);
   }
   sout<< "]";
   return sout.str();
}

RCategiria rCategiria(string categoria,Coll<double> totalGastado)
{
   RCategiria a;
   a.categoria = categoria;
   a.totalGastado = totalGastado;
   return a;
}

bool rCategiriaEquals(RCategiria a,RCategiria b)
{
   if(a.categoria!=b.categoria) return false;
   if(collToString<double>(a.totalGastado)!=collToString<double>(b.totalGastado)) return false;
   return true;
}

