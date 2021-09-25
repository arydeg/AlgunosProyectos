'use strict' //modo estricto, te muestra cuando tenes un error sin q lo corrija java y da mas funciones

var num = prompt("introduce numero tabla");

for(let a=1; a<=num; a++){
	document.write("<h1>TABLA DEL "+ a +"</h1>");
	for(let b=1; b<=num; b++){
		document.write(b + " x " + a + " = "+(a*b) + "<br>");
	}
}