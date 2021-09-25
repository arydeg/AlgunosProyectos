'use strict' //modo estricto, te muestra cuando tenes un error sin q lo corrija java y da mas funciones

/*
alert("HOLA MUNDO CON JS");
alert("bienvenido ussando main");
document.write("hola mundo desde fichero externo");
console.log("esto se muestra en la consola");
console.log(2+2);
*/

//variables
//string 
var nom = "ary";
console.log(nom);
//int
var edad = 21;
console.log(edad);

var nomEdad = nom + " " + edad;
console.log(nomEdad);

console.log(nom,edad,nomEdad);

//nota: var es una variable global

//let es una variable local
let prueba = "hola";

// ----------- demostracion de var y let ------------------
//var (Global)
var txt = "no cambio"; 
console.log(txt);
if (true) {
	txt = "cambio";			//es lo mismo q poner var txt = "cambio"
	console.log(txt);
}
console.log(txt);
// rta: no cambio - cambio - cambio

//let (Local)
var txt = "no cambio"; 
console.log(txt);
if (true) {
	let txt = "cambio";		
	console.log(txt);
}
console.log(txt);
// rta: no cambio - cambio - no cambio
// -----------FIN demostracion de var y let ------------------

//Constante: variable final
const v = "esta variable no cambia";

//operadores: + - * / %

//tipos de datos: int, string, float-double, bool
//cambiar de string a int/float-double:
var s = "2";
Number(s);
//cambiar de string a int:
var s = "2";
parseInt(s);
//cambiar de string a float-double:
var s = "2";
parseFloat(s);
//cambiar de int/float-double a string:
var num = 22;
String(22);

typeof s; //te muestra que tipo de variables es la s

//condicionales
// if && || != < > <= >=
// swith
var edad = 18;
var imprime = "";
switch(edad)
{
	case 18:
		imprime ="mayor de edad";
	break;
	case 17:
		imprime ="menor de edad";
	break;
	default:
		imprime = "no tenes edad";
	break;
}
console.log(imprime);
//bucles for, while
//do while
var test = 0; 
do{
	test+=5;
}while(test<20)
//break en bucle hace salir del bucle
if (isNaN(edad)) {		//si es un numero devuelve false sino true
	//codigo
}

//debugger; //podes ver el programa y buscar las variables en "Sources"

/*
//VENTANAS
//alerta
alert("alerta");
//confirmacion
confirm("Seguir continuando");
var continuar = confirm("Seguir continuando");
console.log(continuar);
//ingreso de datos		estructura: texto y variable por defecto
var edad = prompt("que edad tenes?",0);
console.log(edad);
*/

//funciones
//sin parametros
function calculadora(){
	console.log("soy una calculadora");
}
calculadora();
//con parametros
function multiplicar(a, b){
	return a*b;
}
console.log(multiplicar(3,5));
//con parametros opcionales
function sumar(a, b, mostrar=false){ //mostrar esta como parametro opcional
	if (mostrar) {
		document.write(a+b);
	}else{
		console.log(a+b);
	}
}
sumar(1,2);
//funciones dentro de otras
function porConsola(a){
	console.log(a);
}
function porDocumento(a){
	document.write(a);
}
function resta(a, b, mostrar=false){ //mostrar esta como parametro opcional
	if (mostrar) {
		porDocumento(a-b);
	}else{
		porConsola(a-b);
	}
}
resta(9,5);
//funcion con parametros indefinidos (REST)
function frutas(fruta1, fruta2, ...restoDeFrutas){ //el ...variable va a crear un arr con el contendio de las frutas q ponga de mas
	porConsola("fruta: " + fruta1);
	porConsola("fruta: " + fruta2);
	porConsola(restoDeFrutas);
}
frutas("melon","sandia","frutilla","cacauate");
//SPREAD de un arr con los ... podes recorrerlo para pasarlo como atributos
var arrFrutas = ["melon","sandia"];
frutas(...arrFrutas,"frutilla","cacauate"); //sino agrego los ... me tomaria el arr como un solo atributo en cambio asi toma cada atributo como elemntos en el arr tenga
//funciones anonimas. 		es una funcion q no tiene nombre
var pelicula = function(nombre){
	porConsola("la pelicula es: " + nombre);
}
pelicula("madagascar");
// usar funciones anonimas dentro de si mismas
function sumame(num1, num2, sumaYmuestra, sumaPorDos){
	var sumar = num1 + num2;
	sumaYmuestra(sumar);
	sumaPorDos(sumar);
}
sumame(5, 7, function(res){
	porConsola(res);
},
function(res){
	porConsola(res*2);
});
//funcion flecha es cambiar "function" por "=>" , es lo mismo pero con otro nombre
sumame(5, 7, (res)=>{
	porConsola(res);
},
(res)=>{
	porConsola(res*2);
});

//existe el .toString();

//transformacion de textos
var texto = "Bienvenido";
texto = texto.toUpperCase(); //pone todo en mayus
texto = texto.toLowerCase(); //pone todo en minuscula
//calcular longuitud 
var cNombre = "ary";
porConsola(cNombre.length); //si lo utilizo en un arr te cuenta los elementos
//concatenar puedo o sumar un texto con el sigo + o con una funcion q es "concat"
var texto = (edad.toString()).concat(" " + num);
//busqueda en string
texto = "hola pepe como estas"
var busqueda = texto.indexOf("pepe"); // te muestra la posicion de la primera ocurrencia de la palabra
busqueda = texto.search("pepe"); //es igual q el indexOf
busqueda = texto.lastIndexOf("a"); // muestra la posicion de la ultima ocurrencia de la palabra
busqueda = texto.match("pepe"); //me crea un arr con la primera la pos de la ocurrencia, la palabra y el texto
busqueda = texto.match(/e/g); //te muestra como el match anterior pero todas las ocurrencias
busqueda = texto.substr(1,3); //obtengo un string de lo q esta entre dichas posiciones
busqueda = texto.charAt(5); //saco una unica letra
busqueda = texto.startsWith("ho"); //devuelve true o false segun este las palabras desde q empieza en el texto
busqueda = texto.endsWith("ho"); //igual q el startsWith solo q empieza desde el final
busqueda = texto.includes("como"); //devuelve true o false segun contenga la palabra en el texto
//funcion de reemplazo
busqueda = texto.replace("como" , "ary"); //reemplaza "como" por "ary"
busqueda = texto.slice(5); //empieza el texto desde la posicion 5
busqueda = texto.slice(5,12); //recorta desde la posicion 5 hasta la 12
busqueda = texto.split(); //me mete todo dentro de un arr
busqueda = texto.split(" "); //cada vez que haya un espacio me lo pone en un arr (MUY UTIL)
busqueda = texto.trim(); //quita los espacios en blanco por demas

//plantillas de texto
var nombre="ary", apellido="deg";				//de esta forma puedo mostrar todo ese texto y esos pesos con llaves son variables	
var texto = `									
	<h1>Hola ${nombre}</h1> 
	<br>
	<strong> mi apellido es: </strong> ${apellido}
	<br>
`;
porDocumento(texto);

//array
var nombres = ["ary","pepe","canguro"];                 //las dos formas son iguales
var nombres = new Array("ary","pepe","canguro");
//metodo .forEach((elemento, indice, arr) => {}); //recorre mi arr, el  indice es el contador (opcional) y el arr es mi array (opocional)
nombres.forEach((elemento)=>{
	porConsola(elemento);
})
//para seleccionar un array multidimencional tengo q hacer arr[1][3] seleciono fila y columbna (SIN COMA)
//añadir elemento al array
nombres.push("carlos");
//eliminar ultimo elemento de un arr
nombres.pop();
//elimiar desde una posicion
var pos = 1;
nombres.splice(pos,1); //pos = posicion que quiero borrar, y el otro atributo es cuantos lugares quiero borrar
//para guardar un arr en un string separado por comas uso .join
var stringDeArr = nombres.join();
//ordenar arr
var arr = ["nico","ary","jose","zoe"];
arr.sort(); //ordena alfabeticamente
arr.reverse(); //ordena inverso al alfaveto 
var res = arr.sort(function(a,b){return a-b;}); //ordena el arr segun la funcion q pongas
//otra forma de recorrer arr
for(let elemento in arr){
	porConsola(arr[elemento]);
}
//busquedas en un arr
var busqueda =  arr.find(function(elemento){
	return elemento == "ary";
});		//busqueda es igual a ary ya que es un elememnto de mi arr
//otra forma mas simple de escribir lo mismo es
var busqueda =  arr.find(elemento => elemento == "zoe");	// esto es lo mismo q el anterior, aca devuelve zoe ya q es un elemento del arr
//obtener la posicion del arr donde se encuentra
var busqueda =  arr.findIndex(elemento => elemento == "jose");
//devuelve true o flase si cumple o no la condicion
var precios = [10,20,30];
var busqueda =  precios.findIndex(precio => precio >=10); //ademas si lo encuentra y lo guardas te da la posicion

//DOM Document Object Model
var txt = document.getElementById("txtUsoDom"); //obtengo "<div id="txtUsoDom">Uso DOM</div>"
var txt = document.getElementById("txtUsoDom").innerHTML; //obtengo lo de adentro de la etiqueta: "Uso Dom"
document.getElementById("txtUsoDom").innerHTML = "Cambie el DOM"; //cambio el contenido de la etiqueta que agarre
document.getElementById("txtUsoDom").style.background = "grey"; //cambie el fondo de la etiqueta. con esto puedo modificar lo que quieras
document.getElementById("txtUsoDom").className = "nombreDeLaClase"; //le agrege una clase llamada "nombreDeLaClase"
//otra forma es
var txt = document.querySelector("#txtUsoDom"); //fucniona igual q el anterior. NOTA: # = id , . = class y sin nada para el nombre de una etiqueta
//conseguir elemento por su etiqueta
var todosLosDivs = document.getElementsByTagName('div');	//creo un arr con los divs
todosLosDivs[1].innerHTML = "aca iba un div"; //cambio el contenido del div
var parrafo = document.createElement("p"); //crea elemetno parrafo 
var texto = document.createTextNode("hola como estas");
parrafo.appendChild(texto); //pongo adentro de la etiqueta parrafo el texto 
document.querySelector(".parrafo").appendChild(parrafo); //pongo la etiqueta parrafo que contiene al texto en un sector con el class="parrafo"
//para recorrer el contenido de todos los divs
for(var div in todosLosDivs){
	if (typeof(todosLosDivs[div].textContent) == 'string') {
		//ACA YA RECORRO TODOS LOS DIVS
		todosLosDivs[div].style.background = 'pink';
	}
}
var divsAmarillos = document.getElementsByClassName('amarillo'); // obtiene elemento por clase
divsAmarillos[0].style.background = 'yellow';

//BOM - Browser Objet Model
porConsola(window.innerHeight); //muestra el tamaño de la pantalla actual de alto
porConsola(window.innerWidth); //muestra el tamaño de la pantalla actual de ancho 
porConsola(screen.width); // ESTE ES MEJOR ve el tamaño de la pantalla del dispositivo alto
porConsola(screen.height); // ESTE ES MEJOR ve el tamaño de la pantalla del dispositivo ancho
porConsola(window.location); // hay muchas cosas dentro de ellas como ej la url
porConsola(window.location.href); //aca obtengo el utl
//funcion para cmabiar de url en la misma pestaña
function irAgoogle(){
	window.location.href = "http://google.com";
}
//funcion para cmabiar de url en otra pestaña
function irAgoogleNewVent(){
	window.open("http://google.com");
}
//funcion para cmabiar de url en otra pestaña con medidas en espesifico
function irAgoogleNewVent(){
	window.open("http://google.com","","width=400,height=300");
}

//eventos
var boton = document.querySelector("#button");
//forma de onclick con html (agrego en el boton el apartado de onclik)
function cambiarColor(){
	if( boton.style.background == "yellow"){
		boton.style.background = "orange";
	}else{
		boton.style.background = "yellow";
	}	
}
//forma evento click solo con javascript de hacer funcionar un boton
boton.addEventListener("click",  function(){
	cambiarColor();
	this.style.border = "3px dashed black"; //el this selecciona el elemnteo boton en este caso (seria el objeto q estoy modificando)
});
//mouse over (pasar por arriba el mouse)
boton.addEventListener("mouseover",  function(){
	boton.style.background = "pink";
});
//mouse out (saco el mouse del boton)
boton.addEventListener("mouseout",  function(){
	boton.style.background = "grey";
});
//focus cuando entro en un imput
var input = document.querySelector("#campo_nombre");
input.addEventListener("focus",  function(){
	console.log("[focus] estas dentro del imput");
});
//blur cuando salgo de un imput
var input = document.querySelector("#campo_nombre");
input.addEventListener("blur",  function(){
	console.log("[blur] estas afuera del imput");
});
//keydown cuando pulsas una tecla
var input = document.querySelector("#campo_nombre");
input.addEventListener("keydown",  function(evento){
	console.log("[keydown] apretando la tecla " + String.fromCharCode(evento.keyCode)); //obtengo tecla y convierto en char con String.fromCharCode(evento.keyCode) 
});
//keypress cuando presionas una tecla
var input = document.querySelector("#campo_nombre");
input.addEventListener("keypress",  function(evento){
	console.log("[keypress] presionando la tecla " + String.fromCharCode(evento.keyCode)); //obtengo tecla y convierto en char con String.fromCharCode(evento.keyCode) 
});
//keyup cuando soltas una tecla
var input = document.querySelector("#campo_nombre");
input.addEventListener("keyup",  function(evento){
	console.log("[keyup] soltando la tecla " + String.fromCharCode(evento.keyCode)); //obtengo tecla y convierto en char con String.fromCharCode(evento.keyCode) 
});


//evento load para poner el script en el head y no al final del body puedo poner todo mi codigo dentro de esta funcion:
window.addEventListener('load', function(){
	//el codigo que quiero que se ejecute despues de haber cargado todo el html
});

//timers
var tiempo1 = setInterval(function(){			//ejecuta este codigo cada 3s 
	console.log("Set de intervalo ejectutado");
},3000);
var tiempo2 = setTimeout(function(){			//ejecuta despues de 3s una sola vez
	console.log("me ejecuto una sola vez");
},3000);
//para frenar el bucle de los timers
var stopTimer = document.querySelector("#stopTimer");
stopTimer.addEventListener("click", function(){
	clearInterval(tiempo1); //limpia el bucle de los timers (lo detiene)
	clearInterval(tiempo2); 
});

//submit furmulario
var formulario = document.querySelector("#formulario");
formulario.addEventListener("submit",function(){
	//codigo
});






