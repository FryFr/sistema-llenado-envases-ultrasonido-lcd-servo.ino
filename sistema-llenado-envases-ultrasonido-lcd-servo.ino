// Sistema semi-automatico de distribucion de producto en envases por medio de sensor de ultrasonido, servomotor y LCD
// created by Sebas Silva Tecnologia, 2023
// youtube channel: https://www.youtube.com/@juansilva4256

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myservo;
const int trigger = 9;             //Pin digital 9 para el Trigger del sensor
const int echo = 10;               //Pin digital 10 para el Echo del sensor
const int push = 2;                //Pin digital 2 para el boton pulsador
int valor = 0;                     //Varible para capturar el valor del boton
boolean proceso;                   //Variable de activacion de procesos
LiquidCrystal_I2C lcd(0x27,16,2);  //tamano y configuracion de la pantalla con modulo I2C

void setup() {
  Serial.begin(9600);         //Inicializamos la comunicacion
  pinMode(push, INPUT);       //Configuramos el boton como una entrada de senal
  pinMode(trigger, OUTPUT);   //definimos el Trigger como salida
  pinMode(echo, INPUT);       //definimos el Echo como entrada
  digitalWrite(trigger, LOW); //Inicializamos el pin con un 0 digital 
  myservo.attach(3);          //definimos el pin 3 de comunicacion PWM del servomotor 
  lcd.init();
  lcd.backlight();
}

void loop() {
  float tiempo;       //variable que definira el tiempo que demora en llegar el eco
  float distancia;    //variable que definira la distancia en CM
  float llenado;      //variable que mostrara la cantidad de producto envasado
  int gramos;       //variable que definira los gramos

  valor = digitalRead(push);  //lectura del boton
  proceso = false;            //declaramos el proceso como 0 digital

  if (valor == HIGH){         //si el pulso del boton es 1, la senal se almacena en un HIGH
    Serial.println("ON");     
    proceso = true;           //declaramos el proceso como 1 digital
  }else{                      //si el pulso del boton es 0, la senal se almacena en un LOW
    Serial.println("OFF");    
    proceso = false;          //declaramos el proceso como 0 digital
  }

  while(proceso == true){               //creamos un bucle que funcione siempre que el proceso sea 1 digital
    digitalWrite(trigger, HIGH);  
    delayMicroseconds(10);              //Enviamos un pulso de 10microsegundos
    digitalWrite(trigger, LOW);

    tiempo = pulseIn(echo, HIGH);       //Obtenemos el ancho del pulso
    distancia = tiempo / 58;            //operamos la senal para obtener la distancia en CM
    llenado = ((-1) * distancia )+ 16;  //transformamos el dato a cantidad de producto llenado en el envase en CM
    gramos = 69.4 * llenado;            //calculamos el dato de los gramos de producto en el envase

    lcd.setCursor(0,0);                 //definimos el punto inicial del LCD en la esquina superior izquierda
    lcd.print("Altura: ");
    lcd.print(llenado, 1);                 //Enviamos serialmente el valor del llenado al LCD
    lcd.print("cms  ");

    lcd.setCursor(0,1);                 //definimos el punto inicial del LCD en la esquina inferior izquierda
    lcd.print("Peso: ");
    lcd.print(gramos);                  //Enviamos serialmente el valor de los gramos al LCD
    lcd.print("grs  ");
      if(distancia > 6){                //si la distancia es superior a 6cm iniciamos el proceso
        Serial.println("abierto");      
        myservo.write(180);             //Movemos el servomotor 180 grados desde la posicion 0
      }else{
        Serial.println("cerrrado");     //si la distancia es inferior a 6cm detenemos el proceso
        myservo.write(0);               //Movemos el servomotor 180 grados desde la posicion 180
        proceso = false;                //declaramos el proceso como 0 digital
      }
    delay(100);
  }
}
