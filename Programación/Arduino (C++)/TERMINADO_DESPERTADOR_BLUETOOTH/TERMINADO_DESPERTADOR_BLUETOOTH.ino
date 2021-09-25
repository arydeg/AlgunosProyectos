#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
#include "DHT.h"

#define DHTPIN 13
#define DHTTYPE DHT11 

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //    ( RS, EN, d4, d5, d6, d7)
RTC_DS1307 rtc;
DHT dht(DHTPIN, DHTTYPE);

char daysOfTheWeek[7][12] = {"Dom", "Lun", "Mar", "Mie", "Jue", "Vie", "Sab"};
byte caraSonriente[8] = {
        B00000,
        B01010,
        B01010,
        B01010,
        B00000,
        B10001,
        B01110,
        B00000
};

byte simbol[8] = {
        B00000,
        B00100,
        B01010,
        B10101,
        B01010,
        B00100,
        B00000,
        B00000
};

byte exclamacion[8] = {
        B11111,
        B11111,
        B01110,
        B00100,
        B00000,
        B00100,
        B01110,
        B00100
};

byte uno[8] = {
        B00010,
        B00110,
        B00100,
        B01100,
        B01000,
        B11000,
        B10000,
        B11111
};
byte tres[8] = {
        B01000,
        B01100,
        B00100,
        B00110,
        B00010,
        B00011,
        B00001,
        B11111
};
byte cuatro[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00001,
        B00001,
        B00011
};
byte cinco[8] = {
        B00000,
        B01110,
        B01010,
        B11011,
        B10001,
        B10001,
        B00000,
        B11111
};
byte seis[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B10000,
        B10000,
        B11000
};

int arr[4];
int arrbtn[4];
int luz = 48;
int lampara=50;
int luzBluetooth = 52;
int OnOff = 3;
int pulsAlarma = 4;
int pulsSub = 5;
int pulsBaj = 6;
int cont = 0;
int contDes=0;
int AlarmaHoras = 0;
int AlarmaMinutos = 0;
int AlarmaSegundos = 0;

void setup() {
  dht.begin();
   
  lcd.begin(16, 2);
  lcd.createChar(2,uno);
  lcd.createChar(3,tres);
  lcd.createChar(4,cuatro);
  lcd.createChar(5,cinco);
  lcd.createChar(6,seis);
  lcd.createChar(7,caraSonriente);
  lcd.createChar(8,simbol);
  lcd.createChar(9,exclamacion);
  lcd.setCursor(2,0);
  lcd.print("RELOJ BY ARY");
  delay(2000);
  lcd.clear();
  
  if (! rtc.begin()) {
    lcd.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    lcd.println("RTC is NOT running!");
    //  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  pinMode(luz,OUTPUT);
  pinMode(lampara, OUTPUT); 
  pinMode(luzBluetooth, OUTPUT); 
  pinMode(pulsAlarma,INPUT);
  pinMode(pulsSub,INPUT);
  pinMode(pulsBaj,INPUT);
  pinMode(OnOff,INPUT);

  randomSeed(analogRead(0));

  digitalWrite(lampara, HIGH);
  digitalWrite(luzBluetooth, HIGH);   

  Serial.begin(9600);  
  Serial.println("MODULO CONECTADO");  
  Serial.print("#");  
}

void loop() {
   if (Serial.available())  
    { 
        char VarChar; 
         
        VarChar = Serial.read(); 
         
        if(VarChar == '1'){ 
          digitalWrite(luzBluetooth, LOW); 
          delay(100); 
          Serial.print("LUZ ENCENDIDA"); 
          Serial.print("#"); 
        } 
        
        if(VarChar == '0'){ 
          digitalWrite(luzBluetooth , HIGH); 
          delay(100); 
          Serial.print("LUZ APAGADA#"); 
        }
    }
     
  
  if (digitalRead(pulsAlarma)==HIGH){
      cont++;
      if (cont==4){
        cont = 0;
        lcd.setCursor(9,1);
        lcd.print("       ");
        }
      delay(500);
  }

  if(cont==1){
    lcd.setCursor(0,0);
    lcd.print("Alarma:");
    lcd.setCursor(0,1);
    if(digitalRead(OnOff)==HIGH){
      lcd.setCursor(2,1);
      lcd.print(" ");
      lcd.setCursor(0,1);
      lcd.print("ON");
    }else{lcd.print("OFF");}
    lcd.setCursor(10,1);
    lcd.write(9);
    if(AlarmaHoras<10){
        lcd.print('0');
        }
    lcd.print(AlarmaHoras);
    lcd.print(":");
    if(AlarmaMinutos<10){
        lcd.print('0');
        }
    lcd.print(AlarmaMinutos);
    }

  if(cont==2){
    lcd.setCursor(0,0);
    lcd.print("Configurar ");
    lcd.write(8);
    lcd.print("HRA");
    lcd.write(8);
    lcd.setCursor(0,1);
    lcd.print("alarma");
    lcd.setCursor(12,1);
    //lcd.blink();
    if(digitalRead(pulsSub)==HIGH){
      AlarmaHoras++;
      if(AlarmaHoras > 23){
        AlarmaHoras=0;
        }
      lcd.setCursor(11,1);
      if(AlarmaHoras<10){
        lcd.print('0');
        }
      lcd.print(AlarmaHoras);
      delay(200);
      }
      if(digitalRead(pulsBaj)==HIGH){
      AlarmaHoras--;
      if(AlarmaHoras < 0){
        AlarmaHoras=23;
        }
      lcd.setCursor(11,1);
      if(AlarmaHoras<10){
        lcd.print('0');
        }
      lcd.print(AlarmaHoras);
      delay(200);
      }
    }

  if(cont==3){
    lcd.setCursor(11,0);
    lcd.write(8);
    lcd.print("MIN");
    lcd.write(8);
    lcd.setCursor(15,1);
    //lcd.blink();
    if(digitalRead(pulsSub)==HIGH){
      AlarmaMinutos++;
      if(AlarmaMinutos > 59){
        AlarmaMinutos=0;
        }
      lcd.setCursor(14,1);
      if(AlarmaMinutos<10){
        lcd.print('0');
        }
      lcd.print(AlarmaMinutos);
      delay(200);
      }
      if(digitalRead(pulsBaj)==HIGH){
      AlarmaMinutos--;
      if(AlarmaMinutos < 0){
        AlarmaMinutos=59;
        }
      lcd.setCursor(14,1);
      if(AlarmaMinutos<10){
        lcd.print('0');
        }
      lcd.print(AlarmaMinutos);
      delay(200);
      }
    }

  if(cont==0){
    lcd.setCursor(0,0);
    DateTime now = rtc.now();

      if(now.day()<10){
        lcd.print('0');
        }
      lcd.print(now.day(), DEC);
      lcd.print('/');
      if(now.month()<10){
        lcd.print('0');
        }
      lcd.print(now.month(), DEC);
      lcd.print('/');
      lcd.print(now.year(), DEC);
      
  
     lcd.setCursor(11,0);
      lcd.write(8);
      lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
      lcd.write(8);
      
     lcd.setCursor(0,1);
     if(now.hour()<10){
        lcd.print('0');
        }
      lcd.print(now.hour(), DEC);
      lcd.print(':');
      if(now.minute()<10){
        lcd.print('0');
        }
      lcd.print(now.minute(), DEC);
      lcd.print(':');
      if(now.second()<10){
        lcd.print('0');
        }
      lcd.print(now.second(), DEC);

    if(digitalRead(OnOff)==HIGH){
      lcd.setCursor(10,1);
      lcd.write(9);
      if(AlarmaHoras<10){
        lcd.print('0');
        }
      lcd.print(AlarmaHoras);
      lcd.print(":");
      if(AlarmaMinutos<10){
        lcd.print('0');
        }
      lcd.print(AlarmaMinutos);

      if((now.hour()==AlarmaHoras)&&(now.minute()==AlarmaMinutos)&&(now.second()==AlarmaSegundos)){
        lcd.setCursor(0,0);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(5,0);
        lcd.print("ALARMA");
        lcd.setCursor(0,1);
        lcd.write(2);
        lcd.write(1);
        lcd.write(3);
        lcd.setCursor(0,0);
        lcd.write(4);
        lcd.write(5);
        lcd.write(6);
        lcd.setCursor(13,1);
        lcd.write(2);
        lcd.write(1);
        lcd.write(3);
        lcd.setCursor(13,0);
        lcd.write(4);
        lcd.write(5);
        lcd.write(6);
        digitalWrite(luz,HIGH);
        digitalWrite(lampara,LOW);
        if(digitalRead(pulsAlarma)==HIGH){
          cont=4+contDes;
          if(cont==5){
            lcd.clear();
            lcd.setCursor(5,0);
            arr[0]=random(1,10);
            lcd.print(arr[0]);
            arr[1]=random(1,10);
            lcd.print(arr[1]);
            arr[2]=random(1,10);
            lcd.print(arr[2]);
            arr[3]=random(1,10);
            lcd.print(arr[3]);
            delay(5000);
            lcd.clear();
            }
           if(cont==6){
            lcd.setCursor(5,0);
            lcd.print(arrbtn[0]);
            lcd.print(arrbtn[1]);
            lcd.print(arrbtn[2]);
            lcd.print(arrbtn[3]);
            lcd.setCursor(5,0);
            lcd.blink();
            }
           if(cont==6){
             lcd.setCursor(5,0);
            lcd.print(arrbtn[0]);
            lcd.print(arrbtn[1]);
            lcd.print(arrbtn[2]);
            lcd.print(arrbtn[3]);
            lcd.setCursor(6,0);
            lcd.blink();
            }
           if(cont==7){
            lcd.setCursor(5,0);
            lcd.print(arrbtn[0]);
            lcd.print(arrbtn[1]);
            lcd.print(arrbtn[2]);
            lcd.print(arrbtn[3]);
            lcd.setCursor(7,0);
            lcd.blink();
            }
           if(cont==7){
            lcd.setCursor(5,0);
            lcd.print(arrbtn[0]);
            lcd.print(arrbtn[1]);
            lcd.print(arrbtn[2]);
            lcd.print(arrbtn[3]);
            lcd.setCursor(8,0);
            lcd.blink();
            }
            if(cont==8){
              cont=0;
              }
            //seguir con esto
          }
        delay(600000);
        digitalWrite(luz,LOW);
        digitalWrite(lampara,HIGH);
        }
        contDes++;
      }else{
      lcd.setCursor(11,1); 
      lcd.write(7);
      lcd.print(" ");
      lcd.write(7);
      lcd.print(" ");
      lcd.write(7);}

    if(digitalRead(pulsSub)==HIGH){
      lcd.clear();
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      if (isnan(h) || isnan(t)){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Falla en el");
        lcd.setCursor(0,1);
        lcd.print("sensor DHT");
        delay(1000);
        return;
        }else{
          lcd.setCursor(0,0);
          lcd.print("Temp: ");
          lcd.print(t);
          lcd.print(" C");
          lcd.setCursor(0,1);
          lcd.print("Hum: ");
          lcd.print(h);
          lcd.print(" %    ");
          delay(1000);
        } 
      }
     
    delay(1000);
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
  }
    
}
