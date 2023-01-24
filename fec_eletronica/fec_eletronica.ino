#include <Keypad.h>
#include <Servo.h>
const byte LINHAS = 2;

const byte COLUNAS = 3;

char keys[LINHAS][COLUNAS] = {

  {'1','2','3'},

  {'4','5','6'},
  };

byte pinoslinha[LINHAS] = {8,9};
byte pinoscoluna[COLUNAS] = {12,11,10};

char* senha = "15612";

int posicao = 0;

Keypad keypad = Keypad( makeKeymap(keys), pinoslinha, pinoscoluna, LINHAS, COLUNAS );

Servo servo;

int pos = 0;

bool x;

void setup(){
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);  
servo.attach(7);
x = 0;
}

  

void loop(){
  Serial.print(x);
  posicao = 0;
  char key = keypad.getKey();
  while(key == NO_KEY){key = keypad.getKey();}
   if (key == senha[posicao]){
    posicao++;
    Serial.print(key);
    key = NO_KEY;
    }
   else{
    Serial.print("erro");
    Serial.print(key);
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    digitalWrite(4,1);
    delay(1000);
    digitalWrite(4,0);
    return; 
   }
  while(key == NO_KEY){key = keypad.getKey();}
  
  if (key == senha[posicao]){
    posicao++; 
    Serial.print(key);
    key = NO_KEY;
    }
  
   else{
    Serial.print("erro");
    Serial.print(key);
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    digitalWrite(4,1);
    delay(1000);
    digitalWrite(4,0);
    return;  
   }
   while(key == NO_KEY){key = keypad.getKey();}
   
   if (key == senha[posicao]){
    posicao++;
    Serial.print(key);
    key = NO_KEY;
    }
  
   else{
    Serial.print("erro");
    Serial.print(key);
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    digitalWrite(4,1);
    delay(1000);
    digitalWrite(4,0);
    return;  
   }
   while(key == NO_KEY){key = keypad.getKey();}
   if (key == senha[posicao]){
    posicao++;
    Serial.print(key);
    key = NO_KEY;
    }
  
   else{
    
    Serial.print("erro");
    Serial.print(key);
     while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    digitalWrite(4,1);
    delay(1000);
    digitalWrite(4,0);
    return;  
   }
    while(key == NO_KEY){key = keypad.getKey();}
   if (key == senha[posicao]){
    posicao++;
    Serial.print(key);
    key = NO_KEY;
    }
  
   else{
    Serial.print("erro");
    Serial.print(key);
    while(key == NO_KEY){key = keypad.getKey();}
    key = NO_KEY;
    digitalWrite(4,1);
    delay(1000);
    digitalWrite(4,0);
    return;  
   }

   if(posicao == 5){
    digitalWrite(3,1);
    delay(1000);
    digitalWrite(3,0);
    key = NO_KEY;
    posicao = 0;
    if(x == 0){
       servo.write(180);
       Serial.print("a");
       x = 1;
    }
    else{
       servo.write(0); 
       Serial.print("b");
       x = 0; 
    }
   }
  return;
}
