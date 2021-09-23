'use strict' //modo estricto, te muestra cuando tenes un error sin q lo corrija java y da mas funciones

function validarDatos(arrDatos){
	var res = true;
	for (var i in arrDatos) {
		var info = arrDatos[i]
		if((info.trim).length <= 0 && !isNaN(info) && i!=2){
			alert("INGRESE DATOS CORRECTOS");
			res = false;
			break;
		}else if(i==2 && isNaN(info)){
			alert("INGRESE DATOS CORRECTOS");
			res = false;
			break;
		}
	}
	return res;
}

window.addEventListener('load', function(){
	
	var boxBorde = document.querySelector(".borde");
	boxBorde.style.display="none";

	var formulario = document.querySelector("#formulario");
	formulario.addEventListener("submit",function(){
		var nom = document.querySelector("#nombre").value;
		var ape = document.querySelector("#apellidos").value;
		var edad = document.querySelector("#edad").value;
			
		var arrDatos = [nom,ape,edad];

		console.log(arrDatos);

		if (validarDatos(arrDatos)){
			boxBorde.style.display = "block";

			var todosLosSpan = document.getElementsByTagName('span');
			for(var span in todosLosSpan){
				if (typeof(todosLosSpan[span].textContent) == 'string') {
					todosLosSpan[span].innerHTML = arrDatos[span];
				}
			}
		}
	});

});