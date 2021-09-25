#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../biblioteca/funciones/strings.hpp"
#include "../biblioteca/funciones/tokens.hpp"
#include "../biblioteca/tads/Coll.hpp"
using namespace std;

struct Gasto
{
   int idCons;
   int fecha;
   double importe;
   char categoria[20];
};

struct Consorcio
{
   int idCons;
   char direccion[50];
   int cantPisos;
};

struct RDepto
{
   int numDepto;
   int piso;
   double porcentaje;
};

struct RConsorcio
{
   Consorcio c;
   double gastosTotales;
   Coll<RDepto> deptos;
};

string gastoToString(Gasto x)
{
   char sep = 1;
   string sIdCons=to_string(x.idCons);
   string sFecha=to_string(x.fecha);
   string sImporte=to_string(x.importe);
   string sCategoria=x.categoria;
   return sIdCons+sep+sFecha+sep+sImporte+sep+sCategoria;
}

Gasto gastoFromString(string s)
{
   char sep = 1;
   Gasto x;
   string t0 = getTokenAt(s,sep,0);
   x.idCons=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.fecha=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.importe=stod(t2);
   string t3 = getTokenAt(s,sep,3);
   strcpy(x.categoria,t3.c_str());
   return x;
}

string gastoToDebug(Gasto x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCons;
   sout << ",";
   sout << x.fecha;
   sout << ",";
   sout << x.importe;
   sout << ",";
   sout << x.categoria;
   sout<< "]";
   return sout.str();
}

Gasto gasto(int idCons,int fecha,double importe,string categoria)
{
   Gasto a;
   a.idCons = idCons;
   a.fecha = fecha;
   a.importe = importe;
   strcpy(a.categoria,categoria.c_str());
   return a;
}

bool gastoEquals(Gasto a,Gasto b)
{
   if(a.idCons!=b.idCons) return false;
   if(a.fecha!=b.fecha) return false;
   if(a.importe!=b.importe) return false;
   return true;
}

string consorcioToString(Consorcio x)
{
   char sep = 2;
   string sIdCons=to_string(x.idCons);
   string sDireccion=x.direccion;
   string sCantPisos=to_string(x.cantPisos);
   return sIdCons+sep+sDireccion+sep+sCantPisos;
}

Consorcio consorcioFromString(string s)
{
   char sep = 2;
   Consorcio x;
   string t0 = getTokenAt(s,sep,0);
   x.idCons=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   strcpy(x.direccion,t1.c_str());
   string t2 = getTokenAt(s,sep,2);
   x.cantPisos=stoi(t2);
   return x;
}

string consorcioToDebug(Consorcio x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCons;
   sout << ",";
   sout << x.direccion;
   sout << ",";
   sout << x.cantPisos;
   sout<< "]";
   return sout.str();
}

Consorcio consorcio(int idCons,string direccion,int cantPisos)
{
   Consorcio a;
   a.idCons = idCons;
   strcpy(a.direccion,direccion.c_str());
   a.cantPisos = cantPisos;
   return a;
}

bool consorcioEquals(Consorcio a,Consorcio b)
{
   if(a.idCons!=b.idCons) return false;
   if(a.cantPisos!=b.cantPisos) return false;
   return true;
}

string rDeptoToString(RDepto x)
{
   char sep = 3;
   string sNumDepto=to_string(x.numDepto);
   string sPiso=to_string(x.piso);
   string sPorcentaje=to_string(x.porcentaje);
   return sNumDepto+sep+sPiso+sep+sPorcentaje;
}

RDepto rDeptoFromString(string s)
{
   char sep = 3;
   RDepto x;
   string t0 = getTokenAt(s,sep,0);
   x.numDepto=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.piso=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.porcentaje=stod(t2);
   return x;
}

string rDeptoToDebug(RDepto x)
{
   stringstream sout;
   sout<< "[";
   sout << x.numDepto;
   sout << ",";
   sout << x.piso;
   sout << ",";
   sout << x.porcentaje;
   sout<< "]";
   return sout.str();
}

RDepto rDepto(int numDepto,int piso,double porcentaje)
{
   RDepto a;
   a.numDepto = numDepto;
   a.piso = piso;
   a.porcentaje = porcentaje;
   return a;
}

bool rDeptoEquals(RDepto a,RDepto b)
{
   if(a.numDepto!=b.numDepto) return false;
   if(a.piso!=b.piso) return false;
   if(a.porcentaje!=b.porcentaje) return false;
   return true;
}

string rConsorcioToString(RConsorcio x)
{
   char sep = 4;
   string sC=consorcioToString(x.c);
   string sGastosTotales=to_string(x.gastosTotales);
   string sDeptos=collToString<RDepto>(x.deptos);
   return sC+sep+sGastosTotales+sep+sDeptos;
}

RConsorcio rConsorcioFromString(string s)
{
   char sep = 4;
   RConsorcio x;
   string t0 = getTokenAt(s,sep,0);
   x.c=consorcioFromString(t0);
   string t1 = getTokenAt(s,sep,1);
   x.gastosTotales=stod(t1);
   string t2 = getTokenAt(s,sep,2);
   x.deptos=collFromString<RDepto>(t2);
   return x;
}

string rConsorcioToDebug(RConsorcio x)
{
   stringstream sout;
   sout<< "[";
   sout << consorcioToDebug(x.c);
   sout << ",";
   sout << x.gastosTotales;
   sout << ",";
   collReset<RDepto>(x.deptos);
   while(collHasNext<RDepto>(x.deptos))
   {
      RDepto q = collNext<RDepto>(x.deptos,rDeptoFromString);
      sout << rDeptoToDebug(q);
   }
   sout<< "]";
   return sout.str();
}

RConsorcio rConsorcio(Consorcio c,double gastosTotales,Coll<RDepto> deptos)
{
   RConsorcio a;
   a.c = c;
   a.gastosTotales = gastosTotales;
   a.deptos = deptos;
   return a;
}

bool rConsorcioEquals(RConsorcio a,RConsorcio b)
{
   if(!consorcioEquals(a.c,b.c)) return false;
   if(a.gastosTotales!=b.gastosTotales) return false;
   if(collToString<RDepto>(a.deptos)!=collToString<RDepto>(b.deptos)) return false;
   return true;
}

