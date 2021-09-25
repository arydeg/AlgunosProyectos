#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../biblioteca/funciones/strings.hpp"
#include "../biblioteca/funciones/tokens.hpp"
#include "../biblioteca/tads/Coll.hpp"
using namespace std;

struct Abonado
{
   int idAb;
   char nombre[20];
   char direccion[20];
   int fechaAlta;
   int idPlan;
};

struct ConsumoXAbonado
{
   int idAb;
   int minConsumidos;
   double kbConsmidos;
};

struct Plan
{
   int idPlan;
   char descr[20];
   int minutos;
   int gigas;
   double precio;
   double minExced;
   double gbExced;
};

struct RPlan
{
   Plan p;
   double totalFacturado;
};

struct Consumo
{
   int idAb;
   int fecha;
   int tipoCons;
   int cons;
};

string abonadoToString(Abonado x)
{
   char sep = 1;
   string sIdAb=to_string(x.idAb);
   string sNombre=x.nombre;
   string sDireccion=x.direccion;
   string sFechaAlta=to_string(x.fechaAlta);
   string sIdPlan=to_string(x.idPlan);
   return sIdAb+sep+sNombre+sep+sDireccion+sep+sFechaAlta+sep+sIdPlan;
}

Abonado abonadoFromString(string s)
{
   char sep = 1;
   Abonado x;
   string t0 = getTokenAt(s,sep,0);
   x.idAb=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   strcpy(x.nombre,t1.c_str());
   string t2 = getTokenAt(s,sep,2);
   strcpy(x.direccion,t2.c_str());
   string t3 = getTokenAt(s,sep,3);
   x.fechaAlta=stoi(t3);
   string t4 = getTokenAt(s,sep,4);
   x.idPlan=stoi(t4);
   return x;
}

string abonadoToDebug(Abonado x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idAb;
   sout << ",";
   sout << x.nombre;
   sout << ",";
   sout << x.direccion;
   sout << ",";
   sout << x.fechaAlta;
   sout << ",";
   sout << x.idPlan;
   sout<< "]";
   return sout.str();
}

Abonado abonado(int idAb,string nombre,string direccion,int fechaAlta,int idPlan)
{
   Abonado a;
   a.idAb = idAb;
   strcpy(a.nombre,nombre.c_str());
   strcpy(a.direccion,direccion.c_str());
   a.fechaAlta = fechaAlta;
   a.idPlan = idPlan;
   return a;
}

bool abonadoEquals(Abonado a,Abonado b)
{
   if(a.idAb!=b.idAb) return false;
   if(a.fechaAlta!=b.fechaAlta) return false;
   if(a.idPlan!=b.idPlan) return false;
   return true;
}

string consumoXAbonadoToString(ConsumoXAbonado x)
{
   char sep = 2;
   string sIdAb=to_string(x.idAb);
   string sMinConsumidos=to_string(x.minConsumidos);
   string sKbConsmidos=to_string(x.kbConsmidos);
   return sIdAb+sep+sMinConsumidos+sep+sKbConsmidos;
}

ConsumoXAbonado consumoXAbonadoFromString(string s)
{
   char sep = 2;
   ConsumoXAbonado x;
   string t0 = getTokenAt(s,sep,0);
   x.idAb=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.minConsumidos=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.kbConsmidos=stod(t2);
   return x;
}

string consumoXAbonadoToDebug(ConsumoXAbonado x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idAb;
   sout << ",";
   sout << x.minConsumidos;
   sout << ",";
   sout << x.kbConsmidos;
   sout<< "]";
   return sout.str();
}

ConsumoXAbonado consumoXAbonado(int idAb,int minConsumidos,double kbConsmidos)
{
   ConsumoXAbonado a;
   a.idAb = idAb;
   a.minConsumidos = minConsumidos;
   a.kbConsmidos = kbConsmidos;
   return a;
}

bool consumoXAbonadoEquals(ConsumoXAbonado a,ConsumoXAbonado b)
{
   if(a.idAb!=b.idAb) return false;
   if(a.minConsumidos!=b.minConsumidos) return false;
   if(a.kbConsmidos!=b.kbConsmidos) return false;
   return true;
}

string planToString(Plan x)
{
   char sep = 3;
   string sIdPlan=to_string(x.idPlan);
   string sDescr=x.descr;
   string sMinutos=to_string(x.minutos);
   string sGigas=to_string(x.gigas);
   string sPrecio=to_string(x.precio);
   string sMinExced=to_string(x.minExced);
   string sGbExced=to_string(x.gbExced);
   return sIdPlan+sep+sDescr+sep+sMinutos+sep+sGigas+sep+sPrecio+sep+sMinExced+sep+sGbExced;
}

Plan planFromString(string s)
{
   char sep = 3;
   Plan x;
   string t0 = getTokenAt(s,sep,0);
   x.idPlan=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   strcpy(x.descr,t1.c_str());
   string t2 = getTokenAt(s,sep,2);
   x.minutos=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.gigas=stoi(t3);
   string t4 = getTokenAt(s,sep,4);
   x.precio=stod(t4);
   string t5 = getTokenAt(s,sep,5);
   x.minExced=stod(t5);
   string t6 = getTokenAt(s,sep,6);
   x.gbExced=stod(t6);
   return x;
}

string planToDebug(Plan x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idPlan;
   sout << ",";
   sout << x.descr;
   sout << ",";
   sout << x.minutos;
   sout << ",";
   sout << x.gigas;
   sout << ",";
   sout << x.precio;
   sout << ",";
   sout << x.minExced;
   sout << ",";
   sout << x.gbExced;
   sout<< "]";
   return sout.str();
}

Plan plan(int idPlan,string descr,int minutos,int gigas,double precio,double minExced,double gbExced)
{
   Plan a;
   a.idPlan = idPlan;
   strcpy(a.descr,descr.c_str());
   a.minutos = minutos;
   a.gigas = gigas;
   a.precio = precio;
   a.minExced = minExced;
   a.gbExced = gbExced;
   return a;
}

bool planEquals(Plan a,Plan b)
{
   if(a.idPlan!=b.idPlan) return false;
   if(a.minutos!=b.minutos) return false;
   if(a.gigas!=b.gigas) return false;
   if(a.precio!=b.precio) return false;
   if(a.minExced!=b.minExced) return false;
   if(a.gbExced!=b.gbExced) return false;
   return true;
}

string rPlanToString(RPlan x)
{
   char sep = 4;
   string sP=planToString(x.p);
   string sTotalFacturado=to_string(x.totalFacturado);
   return sP+sep+sTotalFacturado;
}

RPlan rPlanFromString(string s)
{
   char sep = 4;
   RPlan x;
   string t0 = getTokenAt(s,sep,0);
   x.p=planFromString(t0);
   string t1 = getTokenAt(s,sep,1);
   x.totalFacturado=stod(t1);
   return x;
}

string rPlanToDebug(RPlan x)
{
   stringstream sout;
   sout<< "[";
   sout << planToDebug(x.p);
   sout << ",";
   sout << x.totalFacturado;
   sout<< "]";
   return sout.str();
}

RPlan rPlan(Plan p,double totalFacturado)
{
   RPlan a;
   a.p = p;
   a.totalFacturado = totalFacturado;
   return a;
}

bool rPlanEquals(RPlan a,RPlan b)
{
   if(!planEquals(a.p,b.p)) return false;
   if(a.totalFacturado!=b.totalFacturado) return false;
   return true;
}

string consumoToString(Consumo x)
{
   char sep = 5;
   string sIdAb=to_string(x.idAb);
   string sFecha=to_string(x.fecha);
   string sTipoCons=to_string(x.tipoCons);
   string sCons=to_string(x.cons);
   return sIdAb+sep+sFecha+sep+sTipoCons+sep+sCons;
}

Consumo consumoFromString(string s)
{
   char sep = 5;
   Consumo x;
   string t0 = getTokenAt(s,sep,0);
   x.idAb=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.fecha=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.tipoCons=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.cons=stoi(t3);
   return x;
}

string consumoToDebug(Consumo x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idAb;
   sout << ",";
   sout << x.fecha;
   sout << ",";
   sout << x.tipoCons;
   sout << ",";
   sout << x.cons;
   sout<< "]";
   return sout.str();
}

Consumo consumo(int idAb,int fecha,int tipoCons,int cons)
{
   Consumo a;
   a.idAb = idAb;
   a.fecha = fecha;
   a.tipoCons = tipoCons;
   a.cons = cons;
   return a;
}

bool consumoEquals(Consumo a,Consumo b)
{
   if(a.idAb!=b.idAb) return false;
   if(a.fecha!=b.fecha) return false;
   if(a.tipoCons!=b.tipoCons) return false;
   if(a.cons!=b.cons) return false;
   return true;
}

