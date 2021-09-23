#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct Resultado
{
   int idEq1;
   int idEq2;
   int idCR;
   string estadio;
};

struct Equipo
{
   int idEq;
   string nombre;
   int puntos;
};

struct REstadio
{
   string nombre;
   int partidos;
   int partidosEmp;
};

string resultadoToString(Resultado x)
{
   char sep = 1;
   string sIdEq1=to_string(x.idEq1);
   string sIdEq2=to_string(x.idEq2);
   string sIdCR=to_string(x.idCR);
   string sEstadio=x.estadio;
   return sIdEq1+sep+sIdEq2+sep+sIdCR+sep+sEstadio;
}

Resultado resultadoFromString(string s)
{
   char sep = 1;
   Resultado x;
   string t0 = getTokenAt(s,sep,0);
   x.idEq1=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.idEq2=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.idCR=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.estadio=t3;
   return x;
}

string resultadoToDebug(Resultado x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idEq1;
   sout << ",";
   sout << x.idEq2;
   sout << ",";
   sout << x.idCR;
   sout << ",";
   sout << x.estadio;
   sout<< "]";
   return sout.str();
}

Resultado resultado(int idEq1,int idEq2,int idCR,string estadio)
{
   Resultado a;
   a.idEq1 = idEq1;
   a.idEq2 = idEq2;
   a.idCR = idCR;
   a.estadio = estadio;
   return a;
}

bool resultadoEquals(Resultado a,Resultado b)
{
   if(a.idEq1!=b.idEq1) return false;
   if(a.idEq2!=b.idEq2) return false;
   if(a.idCR!=b.idCR) return false;
   if(a.estadio!=b.estadio) return false;
   return true;
}

string equipoToString(Equipo x)
{
   char sep = 2;
   string sIdEq=to_string(x.idEq);
   string sNombre=x.nombre;
   string sPuntos=to_string(x.puntos);
   return sIdEq+sep+sNombre+sep+sPuntos;
}

Equipo equipoFromString(string s)
{
   char sep = 2;
   Equipo x;
   string t0 = getTokenAt(s,sep,0);
   x.idEq=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.nombre=t1;
   string t2 = getTokenAt(s,sep,2);
   x.puntos=stoi(t2);
   return x;
}

string equipoToDebug(Equipo x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idEq;
   sout << ",";
   sout << x.nombre;
   sout << ",";
   sout << x.puntos;
   sout<< "]";
   return sout.str();
}

Equipo equipo(int idEq,string nombre,int puntos)
{
   Equipo a;
   a.idEq = idEq;
   a.nombre = nombre;
   a.puntos = puntos;
   return a;
}

bool equipoEquals(Equipo a,Equipo b)
{
   if(a.idEq!=b.idEq) return false;
   if(a.nombre!=b.nombre) return false;
   if(a.puntos!=b.puntos) return false;
   return true;
}

string rEstadioToString(REstadio x)
{
   char sep = 3;
   string sNombre=x.nombre;
   string sPartidos=to_string(x.partidos);
   string sPartidosEmp=to_string(x.partidosEmp);
   return sNombre+sep+sPartidos+sep+sPartidosEmp;
}

REstadio rEstadioFromString(string s)
{
   char sep = 3;
   REstadio x;
   string t0 = getTokenAt(s,sep,0);
   x.nombre=t0;
   string t1 = getTokenAt(s,sep,1);
   x.partidos=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.partidosEmp=stoi(t2);
   return x;
}

string rEstadioToDebug(REstadio x)
{
   stringstream sout;
   sout<< "[";
   sout << x.nombre;
   sout << ",";
   sout << x.partidos;
   sout << ",";
   sout << x.partidosEmp;
   sout<< "]";
   return sout.str();
}

REstadio rEstadio(string nombre,int partidos,int partidosEmp)
{
   REstadio a;
   a.nombre = nombre;
   a.partidos = partidos;
   a.partidosEmp = partidosEmp;
   return a;
}

bool rEstadioEquals(REstadio a,REstadio b)
{
   if(a.nombre!=b.nombre) return false;
   if(a.partidos!=b.partidos) return false;
   if(a.partidosEmp!=b.partidosEmp) return false;
   return true;
}


