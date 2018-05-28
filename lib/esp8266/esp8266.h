//Libreria para senosr de humedad relativa
//y temperatura DHT11

#ifndef esp8266_h
#define esp8266_h

#include <Arduino.h>

class ESP8266
{
public:
  ESP8266();
  rst();
  espera(unsigned long);
  rst_all();
  cwmode(int);
  conectar(String,String);
  cipmux(int);
  set_ip(String);
  set_server(int);
  send_data(String);

};

#endif
