//Libreria para senosr de humedad relativa
//y temperatura DHT11

#ifndef dht11_h
#define dht11_h

#include <Arduino.h>

class DHT11
{
public:
  DHT11(int);
  uint8_t encender(int);
  uint8_t apagado(int);
  int getdatos(int);
  float gettemp(int);
  float gethum(int);
  float getfar(int);
  float getK(int);

  int pin;
  float humedad;
  float temperatura;

};

#endif
