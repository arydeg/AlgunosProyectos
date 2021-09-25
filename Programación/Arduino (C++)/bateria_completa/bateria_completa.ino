// platillo tstststs de intro 65
// otro de carnabal 40 71 33 38
// TERCER BOMBO 78
//bombo GIGANTEEEEEEE 36 
// tstststs 44
// cambio {56,16,43,80,66,34};

unsigned char PadNote[6] = {1,2,3,4,5,6};         // MIDI notes from 0 to 127 (Mid C = 60)

int PadCutOff[6] = {600,600,600,600,600,600};           // Minimum Analog value to cause a drum hit
//90
int MaxPlayTime[6] = {10,10,10,10,10,10};               // Cycles before a 2nd hit is allowed

#define  midichannel	0;                              // MIDI channel from 0 to 15 (+1 in "real world")

boolean VelocityFlag  = true;                           // Velocity ON (true) or OFF (false)




//*******************************************************************************************************************
// Internal Use Variables			
//*******************************************************************************************************************

boolean activePad[6] = {0,0,0,0,0,0};                   // Array of flags of pad currently playing
int PinPlayTime[6] = {0,0,0,0,0,0};                     // Counter since pad started to play

unsigned char status;

int pin = 0;     
int hitavg = 0;

int i=0;
/*
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);*/
  
void setup() 
{
  Serial.begin(57600); // connect to the serial port 115200
  /*
  pinMode(3,INPUT); // pulsador subir
  pinMode(4,INPUT); // pulsador bajar
  pinMode(5,INPUT); // pulsador derecha
  pinMode(6,INPUT); // pulsador izquierda
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);   //Configura el pin 13 como una salida, LED
  pinMode(13,OUTPUT);
  lcd.begin(16, 2);*/
}

void loop() 
{
 /*
  // EMPIEZA LA PARTE DE TABLERO
      if ( digitalRead(3) == HIGH && i<5) //der
 {
     i++;
     delay(200);
     lcd.clear(); 
 }
      if ( digitalRead(4) == HIGH && i>0) //izq
 {
     i--;
     delay(200);
     lcd.clear(); 
 }
     
     if ( digitalRead(5) == HIGH) //sub
 {
     if(PadNote[i] < 127){
       PadNote[i]=PadNote[i]+1; 
        delay (200);  
        lcd.clear(); 
     }
 }

 if ( digitalRead(6) == HIGH) //baj
 {
     if(PadNote[i] > 0){
       PadNote[i]=PadNote[i]-1; //Imprime el valor por consola
        delay (200);           // Retardo
        lcd.clear();      
     }
 }

 // empieza lcd
  int mostradortamb = i+1;
  int mostradormidi = PadNote[i];
  lcd.setCursor(0,0);
  lcd.print("TAMBOR NUMERO  ");
  lcd.print(mostradortamb);

  lcd.setCursor(0,1);
  lcd.print("   MIDI    ");
  lcd.print(mostradormidi);
  
 // termina lcd
 
  // TERMINA LA PARTE DE TABLERO*/
  for(int pin=0; pin < 6; pin++)
  {
    hitavg = analogRead(pin);                              // read the input pin

    if((hitavg > PadCutOff[pin]))
    {
      if((activePad[pin] == false))
      {
        if(VelocityFlag == true)
        {
//          hitavg = 127 / ((1023 - PadCutOff[pin]) / (hitavg - PadCutOff[pin]));    // With full range (Too sensitive ?)
          hitavg = (hitavg / 8) -1 ;                                                 // Upper range
        }
        else
        {
          hitavg = 127;
        }

        MIDI_TX(144,PadNote[pin],hitavg); 
        PinPlayTime[pin] = 0;
        activePad[pin] = true;
      }
      else
      {
        PinPlayTime[pin] = PinPlayTime[pin] + 1;
      }
    }
    else if((activePad[pin] == true))
    {
      PinPlayTime[pin] = PinPlayTime[pin] + 1;
      
      if(PinPlayTime[pin] > MaxPlayTime[pin])
      {
        activePad[pin] = false;
        MIDI_TX(128,PadNote[pin],127); 
      }
    }
  } 
}


//*******************************************************************************************************************
// Transmit MIDI Message			
//*******************************************************************************************************************
void MIDI_TX(unsigned char MESSAGE, unsigned char PITCH, unsigned char VELOCITY) 
{
  status = MESSAGE + midichannel;
  Serial.write(status);
  Serial.write(PITCH);
  Serial.write(VELOCITY);
}


