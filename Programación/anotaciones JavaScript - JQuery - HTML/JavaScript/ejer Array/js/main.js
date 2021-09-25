'use strict' //modo estricto, te muestra cuando tenes un error sin q lo corrija java y da mas funciones

//funciones
function escribirDocumento(a){
	document.write(a + "<br>");
}
function escribirConsola(a){
	console.log(a);
}
function escribirArrDocumento(arr){
	for(let pos in arr){
		document.write(arr[pos] + "<br>");
	}
}
function escribirArrConsola(arr){
	for(let pos in arr){
		console.log(arr[pos]);
	}
}

//variables globales
var arr = new Array();

//punto 1
for(var i = 1; i<7; i++){
	var ele = prompt("ingrese num " + i,0);
	arr.push(ele);
}

//punto 2
escribirDocumento("PUNTO 2:");
escribirArrDocumento(arr);
escribirConsola("PUNTO 2:");
escribirArrConsola(arr);

//punto 3
arr.sort(function(a,b){return a-b;});
escribirDocumento("PUNTO 3:");
escribirArrDocumento(arr);
escribirConsola("PUNTO 3:");
escribirArrConsola(arr);

//punto 4
arr.sort(function(a,b){return b-a;});
escribirDocumento("PUNTO 4:");
escribirArrDocumento(arr);
escribirConsola("PUNTO 4:");
escribirArrConsola(arr);

//punto 5
escribirDocumento("El arr tiene " + arr.length + " elementos");
escribirConsola("El arr tiene " + arr.length + " elementos");

//punto 6
var num = prompt("ingrese num que desesa buscar",0);
var busqueda =  arr.findIndex(elemento => elemento.toString() == num);
if(busqueda >= 0){
	escribirDocumento("Se encontro el numero introducido y esta en la pos: " + busqueda);
	escribirConsola("Se encontro el numero introducido y esta en la pos: " + busqueda);
}else{
	escribirDocumento("NO se encontro el numero introducido");
	escribirConsola("NO encontro el numero introducido");
}