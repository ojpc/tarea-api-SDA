#include <dht11.h>

DHT11::DHT11(int dp){
  pin=dp;
}

uint8_t DHT11::encender(int pin){
pinMode(pin,OUTPUT);
digitalWrite(pin,HIGH);
Serial.println("LED ENCENDIDO");
float t = 1;
return t;
}

uint8_t DHT11::apagado(int pin){
pinMode(pin,OUTPUT);
digitalWrite(pin,LOW);
Serial.println("LED APAGADO");
float t = 0;
return t;
}

int DHT11::getdatos(int pin){

  uint8_t bits[5];
  uint8_t cnt = 7;
  uint8_t idx = 0;

  // EMPTY BUFFER
  for (int i=0; i< 5; i++) bits[i] = 0;

  // REQUEST SAMPLE
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delay(18);
  digitalWrite(pin, HIGH);
  delayMicroseconds(40);
  pinMode(pin, INPUT);

  // ACKNOWLEDGE or TIMEOUT
  unsigned int conteoloop = 10000;
  while(digitalRead(pin) == LOW)
    if (conteoloop-- == 0) return -2;

  conteoloop = 10000;
  while(digitalRead(pin) == HIGH)
    if (conteoloop-- == 0) return -2;

  // READ OUTPUT - 40 BITS => 5 BYTES or TIMEOUT
  for (int i=0; i<40; i++)
  {
    conteoloop = 10000;
    while(digitalRead(pin) == LOW)
      if (conteoloop-- == 0) return -2;

    unsigned long t = micros();

    conteoloop = 10000;
    while(digitalRead(pin) == HIGH)
      if (conteoloop-- == 0) return -2;

    if ((micros() - t) > 40) bits[idx] |= (1 << cnt);
    if (cnt == 0)   // next byte?
    {
      cnt = 7;    // restart at MSB
      idx++;      // next byte!
    }
    else cnt--;
  }

  // WRITE TO RIGHT VARS
    // as bits[1] and bits[3] are allways zero they are omitted in formulas.
  humedad    = bits[0]+(bits[1]*0.1);
  temperatura = bits[2]+(bits[3]*0.1);

  uint8_t sum = bits[0] +bits[1]+ bits[2]+bits[3];

  if (bits[4] == sum)
  {
  return 1;
  }
  else
  {
  return 0;
  }

}

float DHT11::gethum(int pin){

int var=getdatos(pin);
if (var==1)
{
  return humedad;
}
else
{
  humedad =-2.635;
  return humedad;
}

}

float DHT11::gettemp(int pin){

int var=getdatos(pin);
if (var==1)
{
  return temperatura;
}
else
{
  temperatura =-2.635;
  return temperatura;
}
}

float DHT11::getfar(int pin){
  float t=gettemp(pin);
  float f=(t*1.8)+32;
  return f;
}

float DHT11::getK(int){
  float t=gettemp(pin);
  float k=t+273.15;
  return k;
}
