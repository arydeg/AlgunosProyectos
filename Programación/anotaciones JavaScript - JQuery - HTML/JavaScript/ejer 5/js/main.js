'use strict' //modo estricto, te muestra cuando tenes un error sin q lo corrija java y da mas funciones

var num1 = prompt("Ingrese un numero");

for(var i=1; i<=num1; i++){
	if(num1%i == 0){
		document.write(" " + i + " ");
	}
}
