'use strict' //modo estricto, te muestra cuando tenes un error sin q lo corrija java y da mas funciones


var total = 0;
var prom = 0;
var cont = 0;

var num1 = prompt("INTRODUCE UN NUMERO",0);
while(num1>=0){
	cont++;
	total+=Number(num1);
	num1 = prompt("INTRODUCE UN NUMERO",0);
}

prom = total/cont;

document.write("total: " + total);
document.write(" promedio: " + prom); 

