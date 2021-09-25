'use strict' //modo estricto, te muestra cuando tenes un error sin q lo corrija java y da mas funciones

do{
	var num1 = prompt("Ingrese un numero",0);
}while(isNaN(num1))

if(num1%2 == 0){
	document.write("Es par");
}else{
	document.write("No es par");
}