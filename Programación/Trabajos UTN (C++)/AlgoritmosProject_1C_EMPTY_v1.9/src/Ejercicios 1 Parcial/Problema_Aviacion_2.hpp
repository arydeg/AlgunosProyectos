#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct Ciudad
{
   int idCiu;
   char descr[20];
   int millas;
};

struct Vuelo
{
   int idVue;
   int cap;
   int idOri;
   int idDes;
};

struct Reserva
{
   int idCli;
   int idVue;
   int cant;
};

struct RCliente
{
   int idCli;
   int millas = 0;
};

struct RVuelo
{
   Vuelo v;
   int pRecha = 0;
   int pAcept = 0;
};

struct RCiudad
{
   Ciudad c;
   int familias = 0;
};

string ciudadToString(Ciudad x)
{
   char sep = 1;
   string sIdCiu=to_string(x.idCiu);
   string sDescr=x.descr;
   string sMillas=to_string(x.millas);
   return sIdCiu+sep+sDescr+sep+sMillas;
}

Ciudad ciudadFromString(string s)
{
   char sep = 1;
   Ciudad x;
   string t0 = getTokenAt(s,sep,0);
   x.idCiu=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   strcpy(x.descr,t1.c_str());
   string t2 = getTokenAt(s,sep,2);
   x.millas=stoi(t2);
   return x;
}

string ciudadToDebug(Ciudad x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCiu;
   sout << ",";
   sout << x.descr;
   sout << ",";
   sout << x.millas;
   sout<< "]";
   return sout.str();
}

Ciudad ciudad(int idCiu,string descr,int millas)
{
   Ciudad a;
   a.idCiu = idCiu;
   strcpy(a.descr,descr.c_str());
   a.millas = millas;
   return a;
}

bool ciudadEquals(Ciudad a,Ciudad b)
{
   if(a.idCiu!=b.idCiu) return false;
   if(a.millas!=b.millas) return false;
   return true;
}

string vueloToString(Vuelo x)
{
   char sep = 2;
   string sIdVue=to_string(x.idVue);
   string sCap=to_string(x.cap);
   string sIdOri=to_string(x.idOri);
   string sIdDes=to_string(x.idDes);
   return sIdVue+sep+sCap+sep+sIdOri+sep+sIdDes;
}

Vuelo vueloFromString(string s)
{
   char sep = 2;
   Vuelo x;
   string t0 = getTokenAt(s,sep,0);
   x.idVue=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.cap=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.idOri=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.idDes=stoi(t3);
   return x;
}

string vueloToDebug(Vuelo x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idVue;
   sout << ",";
   sout << x.cap;
   sout << ",";
   sout << x.idOri;
   sout << ",";
   sout << x.idDes;
   sout<< "]";
   return sout.str();
}

Vuelo vuelo(int idVue,int cap,int idOri,int idDes)
{
   Vuelo a;
   a.idVue = idVue;
   a.cap = cap;
   a.idOri = idOri;
   a.idDes = idDes;
   return a;
}

bool vueloEquals(Vuelo a,Vuelo b)
{
   if(a.idVue!=b.idVue) return false;
   if(a.cap!=b.cap) return false;
   if(a.idOri!=b.idOri) return false;
   if(a.idDes!=b.idDes) return false;
   return true;
}
//
string reservaToString(Reserva x)
{
   char sep = 3;
   string sIdCli=to_string(x.idCli);
   string sIdVue=to_string(x.idVue);
   string sCant=to_string(x.cant);
   return sIdCli+sep+sIdVue+sep+sCant;
}

Reserva reservaFromString(string s)
{
   char sep = 3;
   Reserva x;
   string t0 = getTokenAt(s,sep,0);
   x.idCli=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.idVue=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.cant=stoi(t2);
   return x;
}

string reservaToDebug(Reserva x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCli;
   sout << ",";
   sout << x.idVue;
   sout << ",";
   sout << x.cant;
   sout<< "]";
   return sout.str();
}

Reserva reserva(int idCli,int idVue,int cant)
{
   Reserva a;
   a.idCli = idCli;
   a.idVue = idVue;
   a.cant = cant;
   return a;
}

bool reservaEquals(Reserva a,Reserva b)
{
   if(a.idCli!=b.idCli) return false;
   if(a.idVue!=b.idVue) return false;
   if(a.cant!=b.cant) return false;
   return true;
}

string rClienteToString(RCliente x)
{
   char sep = 4;
   string sIdCli=to_string(x.idCli);
   string sMillas = 0=to_string(x.millas = 0);
   return sIdCli+sep+sMillas = 0;
}

RCliente rClienteFromString(string s)
{
   char sep = 4;
   RCliente x;
   string t0 = getTokenAt(s,sep,0);
   x.idCli=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.millas = 0=stoi(t1);
   return x;
}

string rClienteToDebug(RCliente x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCli;
   sout << ",";
   sout << x.millas = 0;
   sout<< "]";
   return sout.str();
}

RCliente rCliente(int idCli,int millas = 0)
{
   RCliente a;
   a.idCli = idCli;
   a.millas = 0 = millas = 0;
   return a;
}

bool rClienteEquals(RCliente a,RCliente b)
{
   if(a.idCli!=b.idCli) return false;
   if(a.millas = 0!=b.millas = 0) return false;
   return true;
}

string rVueloToString(RVuelo x)
{
   char sep = 5;
   string sV=vueloToString(x.v);
   string sPRecha = 0=to_string(x.pRecha = 0);
   string sPAcept = 0=to_string(x.pAcept = 0);
   return sV+sep+sPRecha = 0+sep+sPAcept = 0;
}

RVuelo rVueloFromString(string s)
{
   char sep = 5;
   RVuelo x;
   string t0 = getTokenAt(s,sep,0);
   x.v=vueloFromString(t0);
   string t1 = getTokenAt(s,sep,1);
   x.pRecha = 0=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.pAcept = 0=stoi(t2);
   return x;
}

string rVueloToDebug(RVuelo x)
{
   stringstream sout;
   sout<< "[";
   sout << vueloToDebug(x.v);
   sout << ",";
   sout << x.pRecha = 0;
   sout << ",";
   sout << x.pAcept = 0;
   sout<< "]";
   return sout.str();
}

RVuelo rVuelo(Vuelo v,int pRecha = 0,int pAcept = 0)
{
   RVuelo a;
   a.v = v;
   a.pRecha = 0 = pRecha = 0;
   a.pAcept = 0 = pAcept = 0;
   return a;
}

bool rVueloEquals(RVuelo a,RVuelo b)
{
   if(!vueloEquals(a.v,b.v)) return false;
   if(a.pRecha = 0!=b.pRecha = 0) return false;
   if(a.pAcept = 0!=b.pAcept = 0) return false;
   return true;
}

string rCiudadToString(RCiudad x)
{
   char sep = 6;
   string sC=ciudadToString(x.c);
   string sFamilias = 0=to_string(x.familias = 0);
   return sC+sep+sFamilias = 0;
}

RCiudad rCiudadFromString(string s)
{
   char sep = 6;
   RCiudad x;
   string t0 = getTokenAt(s,sep,0);
   x.c=ciudadFromString(t0);
   string t1 = getTokenAt(s,sep,1);
   x.familias = 0=stoi(t1);
   return x;
}

string rCiudadToDebug(RCiudad x)
{
   stringstream sout;
   sout<< "[";
   sout << ciudadToDebug(x.c);
   sout << ",";
   sout << x.familias = 0;
   sout<< "]";
   return sout.str();
}

RCiudad rCiudad(Ciudad c,int familias = 0)
{
   RCiudad a;
   a.c = c;
   a.familias = 0 = familias = 0;
   return a;
}

bool rCiudadEquals(RCiudad a,RCiudad b)
{
   if(!ciudadEquals(a.c,b.c)) return false;
   if(a.familias = 0!=b.familias = 0) return false;
   return true;
}

