//#ifndef _MAIN
//#define _MAIN
//
//#include <iostream>
//#include "biblioteca/tads/Arr.hpp"
//#include "biblioteca/tads/Map.hpp"
//#include "biblioteca/tads/List.hpp"
//#include "biblioteca/tads/Stack.hpp"
//#include "biblioteca/tads/Queue.hpp"
//#include "biblioteca/funciones/strings.hpp"
//#include "biblioteca/funciones/lists.hpp"
//#include "biblioteca/funciones/tokens.hpp"
//#include "biblioteca/funciones/files.hpp"
//using namespace std;
//
////TAD
//struct Fecha
//{
//   int dia,mes,anio;
//};
//struct Proyecto{
//   int idProyecto;
//   string descripcion;
//   Fecha fechaInicio;
//   int horasAsignadas;
//   int horasImputadas;
//};
//struct Hora{
//   int idEmpleado;
//   int idProyecto;
//   Fecha fecha;
//   int horas;
//   string tareas;
//};
//struct Empleado
//{
//   int idEmpleado;
//   string nombre;
//};
//struct REmpleado
//{
//   Empleado emp;
//   Arr<int> hras;
//   Arr<Fecha> fecha;
//   Arr<string> tareas;
//};
////Funciones
//void cargarProyectos(Arr<Proyecto>& arrProyectos){
//   //leo los proyectos y los guardo
//   FILE* proyectosR = fopen("PROYECTOS.dat","r+b");
//   Proyecto proyecto = read<Proyecto>(proyectosR);
//   while(!feof(proyectosR))
//   {
//      //añado el proyecto a su array
//      arrAdd<Proyecto>(arrProyectos,proyecto);
//
//      proyecto = read<Proyecto>(proyectosR);
//   }
//   fclose(proyectosR);
//}
//void cargarREmpleados(Arr<REmpleado>& arrREmpleado){
//   //leo los REmpleados y los guardo
//   FILE* empleadosR = fopen("EMPLEADOS.dat","r+b");
//   Empleado empleado = read<Empleado>(empleadosR);
//   while( !feof(empleadosR) )
//   {
//      REmpleado rEmpleado;
//      rEmpleado.emp = empleado;
//      //añado el proyecto a su array
//      arrAdd<REmpleado>(arrREmpleado,rEmpleado);
//
//      empleado = read<Empleado>(empleadosR);
//   }
//   fclose(empleadosR);
//}
//void crearMapREmpleadosXProy(Map<int,Arr<int>> mapfilaREmpleadoXProy, Arr<Proyecto> arrProyectos){
//   for(int i=0; i < arrSize<Proyecto>(arrProyectos); i++){
//      Arr<int> a = arr<int>();
//      int idProyecto = (arrGet<Proyecto>(arrProyectos,i))->idProyecto;
//      mapPut<int,Arr<int>>(mapfilaREmpleadoXProy, idProyecto ,a);
//   }
//}
//int cmpREId(REmpleado a, int b){return a.emp.idEmpleado-b;}
//void actualizarREmpleados(Arr<REmpleado> arrREmpleado,Hora h){
//   int pos = arrFind<REmpleado,int>(arrREmpleado,h.idEmpleado, cmpREId);
//   REmpleado re = arrRemove(arrREmpleado,pos);
//   arrAdd(re.fecha,h.fecha);
//   arrAdd(re.hras,h.horas);
//   arrAdd(re.tareas,h.tareas);
//   arrAdd(arrREmpleado,re);
//}
//void actualizarMapREmpleadosXProy(Map<int,Arr<int>> mapREmpleadosXProy,Hora h){ //no estoy seguro si hace falta agregar el & tanto en este como en el array
//   Arr<int> arrIdRE = mapRemove(mapREmpleadosXProy,h.idEmpleado);
//   arrAdd(arrIdRE,h.idEmpleado);
//   mapPut(mapREmpleadosXProy,h.idEmpleado,arrIdRE);
//}
//int cmpId(int a,int b){return a-b;}
//int cmpProyId(Proyecto a,int b){return a.idProyecto-b;}
//void mostrarEmpleadosYactualizarHra(Arr<int> arrIdRE, Arr<REmpleado> arrREmpleado,int idProy, Arr<Proyecto> arrProyectos){
//   for(int i=0; i<arrSize(arrIdRE); i++){
//      int pos = arrFind(arrREmpleado,arrRemove(arrIdRE,i), cmpREId);
//      REmpleado re = arrRemove(arrREmpleado,pos);
//      //muestro empleado
//      cout<<"Empleado id:"<<re.emp.idEmpleado<<" nombre: "<<re.emp.nombre<<endl;
//      int hrasProy=0;
//      for(int i=arrSize(re.fecha); i>0; i--){
//         hrasProy = arrRemove(re.hras,i);
//         int mes = arrGet(re.fecha,i)->mes;
//         int anio = arrGet(re.fecha,i)->anio;
//         int dia = arrGet(re.fecha,i)->dia;
//         cout<<"Fecha: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
//         cout<<"Tarea desarrollada: "<<arrGet(re.tareas,i)<<"Horas: "<<hrasProy;
//         cout<<endl;
//
//         //actualizo hrasImputadas
//         int posP = arrFind(arrProyectos,idProy,cmpProyId);
//         Proyecto p = arrRemove(arrProyectos,posP);
//         p.horasImputadas += hrasProy;
//         arrAdd(arrProyectos,p);
//      }
//   }
//}
//void muestroPunto1(Map<int,Arr<int>> mapREmpleadosXProy, Arr<REmpleado> arrREmpleado,Arr<Proyecto> arrProyectos){
//   //ordenado por proyecto
//   mapSortByKeys(mapREmpleadosXProy,cmpId);
//
//   while(mapHasNext(mapREmpleadosXProy)){
//      int idProy = mapNextKey(mapREmpleadosXProy);
//      Arr<int> arrIdRE = mapRemove(mapREmpleadosXProy,idProy);
//      //ordeno por Empleado
//      arrSort(arrIdRE,cmpId);
//
//      //Muestro punto 1
//      cout<<"Proyecto id: "<<idProy<<endl;
//      mostrarEmpleadosYactualizarHra(arrIdRE,arrREmpleado,idProy, arrProyectos);
//   }
//}
//void emitirPunto2(Arr<Proyecto> arrProyectos){
//   FILE* proyectosR = fopen("PROYECTOS.dat","w+b");
//   for(int i=0;i<arrSize(arrProyectos);i++){
//      Proyecto* p = arrGet(arrProyectos,i);
//      if(p->horasImputadas>p->horasAsignadas){
//        write<Proyecto*>(proyectosR,p);
//      }
//   }
//   fclose(proyectosR);
//}
////Main
//int main()
//{
//   Arr<Proyecto> arrProyectos = arr<Proyecto>();
//   Arr<REmpleado> arrREmpleado = arr<REmpleado>();
//   Map<int,Arr<int>> mapREmpleadosXProy = map<int,Arr<int>>();
//
//   cargarProyectos(arrProyectos);
//   cargarREmpleados(arrREmpleado);
//   crearMapREmpleadosXProy(mapREmpleadosXProy,arrProyectos);
//
//   FILE* horasR = fopen("HORAS.dat","r+b");
//   Hora h = read<Hora>(horasR);
//   while(!feof(horasR))
//   {
//      actualizarREmpleados(arrREmpleado,h);
//      actualizarMapREmpleadosXProy(mapREmpleadosXProy,h);
//
//      h = read<Hora>(horasR);
//   }
//   fclose(horasR);
//
//   muestroPunto1(mapREmpleadosXProy,arrREmpleado,arrProyectos);
//   emitirPunto2(arrProyectos);
//
//   return 0;
//}
//
//#endif
