'use strict' //modo estricto, te muestra cuando tenes un error sin q lo corrija java y da mas funciones

var num1 = prompt("ingrese num 1",0);
var num2 = prompt("ingrese num 2",0);

while(isNaN(num1) || isNaN(num2)){
	num1 = prompt("ingrese num 1",0);
	num2 = prompt("ingrese num 2",0);
}

if (num1>num2) {
	document.write("el numero " + num1 + " es mayor");
}else if (num1<num2) {
	document.write("el numero " + num2 + " es mayor");
}else{
	document.write("son iguales");
}

