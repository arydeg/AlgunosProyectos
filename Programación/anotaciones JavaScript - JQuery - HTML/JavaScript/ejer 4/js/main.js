'use strict' //modo estricto, te muestra cuando tenes un error sin q lo corrija java y da mas funciones

var num1 = prompt("Ingrese numero 1");
var num2 = prompt("Ingrese numero 2");

for(var i=(Number(num1)+1); i<num2; i++){
	if(i%2 != 0){
		document.write(" " + i + " ");
	}
}
