#include <Servo.h>
#include <DHT.h>

////////////CODIGO INNTELLIGENT GREENHOUSE/////////////////
///////////HUMEDAD Y LUZ///////////////
int sensorPin = A0; 
int humedad = 0;
int bocinaPin = 10;
int ledPin = 6;
int relePin = 5;
////////////TEMPERATURA////////
int Pin_sensor = 3;
int TEMPERATURA = 0;
int VENTILADORES= 7;
int Luz_ROJA = 4;
int Luz_AMARILLA = 8;
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
 
// Inicializamos el sensor DHT11
DHT dht(Pin_sensor, DHTTYPE);
////////////DIOXIDO DE CARBONO///////////////
int Pin_sensor2 = A1;
int LED3 = 11;
int BW = 13;
int DIOXIDO_CARBONO = 0;
/////////////////AGUA/////////////////
Servo servoMotor; 
int Pin_Sensor3 = A3; 
int LED_VERDE = 12;
int AGUA = 0;
void setup()
{
   Serial.begin(9600);
   pinMode(sensorPin, INPUT);
   pinMode(bocinaPin, OUTPUT);
   pinMode(ledPin, OUTPUT);
   pinMode(relePin, OUTPUT);
   pinMode(Pin_sensor, INPUT);
   pinMode(VENTILADORES, OUTPUT);
   pinMode(Luz_ROJA , OUTPUT);
   pinMode(Luz_AMARILLA, OUTPUT);
   pinMode(Pin_sensor2, INPUT);
   pinMode(LED3, OUTPUT);
   pinMode(BW, OUTPUT);
   servoMotor.attach(9);
   pinMode(LED_VERDE, OUTPUT);
   pinMode(Pin_Sensor3, INPUT);
   dht.begin();
  
}
void loop()
{
  humedad = analogRead(sensorPin);
 Serial.println("HUMEDAD DEL SUELO:");
 Serial.println(humedad);
 delay(1000);
 if (humedad >= 580){
  digitalWrite(relePin, LOW );
 }
 else{
  digitalWrite(relePin, HIGH);
 }
if (humedad <= 350){
  digitalWrite(bocinaPin, HIGH );
 }
 else{
  digitalWrite(bocinaPin, LOW);
 }
 if (humedad >= 350 and humedad < 579){
  digitalWrite(ledPin, HIGH );
 }
 else{
  digitalWrite(ledPin, LOW);
 }

  ///////////////////////////////////////////////////////SENSOR DE TEMPERATURA//////////////////////////////
      // Esperamos 5 segundos entre medidas
  delay(5000);
 
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahreheit
  float f = dht.readTemperature(true);
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
  // Calcular el índice de calor en Fahreheit
  float hif = dht.computeHeatIndex(f, h);
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);
 
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  if (h >= 95.00) {
    Serial.println("La humedad relativa es adecuada");
    digitalWrite(Luz_ROJA, LOW);
    }
 else{
  Serial.println("La humedad relativa es muy baja.");
  digitalWrite(Luz_ROJA, HIGH);
  
  }
 if (t >= 23.30){
  Serial.println("La temperatura es alta, se activara la ventilacion");
  digitalWrite(VENTILADORES, LOW);
  digitalWrite(Luz_AMARILLA, HIGH);
  }
  else{
    Serial.println("La temperatura es adecuada");
  digitalWrite(VENTILADORES, HIGH);
  digitalWrite(Luz_AMARILLA, LOW);
 }
 /////////////////////////////////////SENSOR DIOXIDO DE CARBONO///////////////////////////////
  DIOXIDO_CARBONO = analogRead(Pin_sensor2);
  Serial.println("EL NIVEL DE DIOXIDO DE CARBONO EN AIRE DEL INVERNADERO ES DE:");
  Serial.println(DIOXIDO_CARBONO);
  delay(1000);
  if (DIOXIDO_CARBONO <= 490){
    Serial.println("Los niveles de dioxido de carbono son muy bajos, se activara la ventilacion.");
    digitalWrite(BW, HIGH);
    digitalWrite(VENTILADORES, LOW);
    }
    else{
      digitalWrite(BW, LOW);

      digitalWrite(VENTILADORES, HIGH);
      }
   if (DIOXIDO_CARBONO >= 500){
    Serial.println("Los niveles de CO2 son adecuados.");
    digitalWrite(LED3, HIGH);}
    else{
      digitalWrite(LED3, LOW);
  
  }
///////////////////////////////////////////////////////////////SENSOR DE AGUA////////////////////////////////7
  AGUA = analogRead(Pin_Sensor3);
  Serial.println(AGUA);
  delay(1000);
  if (AGUA >= 290){
    Serial.println("Se abriran las canaletas de recoleccion.");
    servoMotor.write(HIGH);
    servoMotor.write(90);
    delay(1000);   
    digitalWrite(LED_VERDE, HIGH);
    }
    else{
      servoMotor.write(LOW);
      digitalWrite(LED_VERDE, LOW);
      }

}
  

 
