/*
 * juego de luces y botones
 * luces 1 al 4 en el pin D2 al D5
 * btn del 1 al 4 en el pin D6 al D9
 */

int arr[8];
int cont=0;
int led1=2;
int led2=3;
int led3=4;
int led4=5;
int btn1=6;
int btn2=7;
int btn3=8;
int btn4=9;

void setup() {
  Serial.begin(57600);
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  pinMode(btn3,INPUT);
  pinMode(btn4,INPUT);

}

void loop(){
  if(cont<8){  
    Serial.print("cont: ");
    Serial.println(cont);
    for (int i=0; i<cont;i++){
      accion(arr[i]);
      Serial.print(arr[i]);
      Serial.print(" ");
    }
    arr[cont] = random(2,6);
      accion(arr[cont]);
      Serial.println(arr[cont]);
    cont++;
  }else{
    cont=0;
    Serial.println("fin del juego");
    }
}

void accion(int x){
  digitalWrite(x,HIGH);
  //tono x HIGH
  delay (1000);
  digitalWrite(x,LOW);
  delay(500);
  //tono x LOW
}

