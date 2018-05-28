#include <SoftwareSerial.h>
#include <Arduino.h>
#include <dht11.h>
#include <esp8266.h>
#include <ArduinoJson.h>

int rx = 2;
int tx = 3;
int pin=8;
int h=1;
String ssid="INSERTAR NOMBRE DE RED";
String pwd="INSERTAR CONTRASEÑA";
String ip="192.168.0.18";
DHT11 DHT= DHT11(pin);
ESP8266 ESP=ESP8266();

void setup()
{
  Serial.begin(9600);

    while (!Serial)
    {
    }
  Serial.println("Started");
  int val=ESP.rst();
  if (val==1) Serial.println("OK");
  val=ESP.rst_all();
  if (val==1) Serial.println("RESTORE DONE");
  val=ESP.cwmode(3);
  if (val==1) Serial.println("CWMODE=3");
  val=ESP.conectar(ssid, pwd);
  if (val==1){Serial.println("CONNECTED!");}
  else{Serial.println("CANNOT CONNECT TO WIFI");}
  val=ESP.cipmux(1);
  if (val==1) Serial.println("MULTIPLEX=1");
  val=ESP.set_ip(ip);
  if (val==1) Serial.println("IP SET");
  val=ESP.set_server(80);
  if (val==1) Serial.println("SERVER SET");
}

void loop()
{
  StaticJsonBuffer<200> jsonBuffer;
  float dato=DHT.gettemp(pin);
  int val=ESP.espera(100);
  float dato2=DHT.gethum(pin);
  char json[256];
  JsonObject& root = jsonBuffer.createObject();
  root["temperature"] =String(dato) ;
  root["humidity"] =String(dato) ;
  root.printTo(json, sizeof(json));
  val=ESP.send_data(json);
  if (val==1){Serial.println("MENSAJE ENVIADO");}
  else{Serial.println("NO SE ENVIO MENSAJE");}
}
