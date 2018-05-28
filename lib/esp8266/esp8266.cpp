#include <esp8266.h>
#include <SoftwareSerial.h>

SoftwareSerial esp=SoftwareSerial(2,3);

ESP8266::ESP8266()
{
  esp.begin(115200);
}

ESP8266::rst()
{
  int val=0;
  esp.println("AT+RST");
  espera(1000);
  esp.println("AT");
  espera(300);
  if(esp.find("OK"))
  {
    val= 1;
  }
  return val;

}
ESP8266::rst_all()
{
  int val=0;
  esp.println("AT");
  espera(300);
  if(esp.find("OK"))
  {
    val=1;
    esp.println("AT+RESTORE");
    espera(1000);
  }
  return val;
}
ESP8266::cwmode(int m)
{
  int val=0;
  String cmd = "AT+CWMODE="+String(m);
  esp.println(cmd);
  espera(300);
  if(esp.find("OK")) {val=1;}
  return val;
}
ESP8266::conectar(String ssid, String pwd)
{
  int val=0;
  String cmd = "AT+CWJAP=\"" +ssid+"\",\"" + pwd + "\"";
  esp.println(cmd);
  espera(4000);
  esp.println("AT+CWJAP?");
  espera(500);
  if (esp.find("no AP"))
  { val=0;
    conectar(ssid,pwd);}
  else{val=1;}
  return val;
}
ESP8266::espera(unsigned long t)
{
  unsigned long ta;
  unsigned long tant;
  ta = millis();
  tant = millis();
  while ((ta - tant) < t)
  {
    ta = millis();
  }
  return 1;
}
ESP8266::cipmux(int c)
{
  int val=0;
  String cmd="AT+CIPMUX="+String(c);
  esp.println(cmd);
  espera(300);
  if(esp.find("OK")){val=1;}
  return val;

}
ESP8266::set_ip(String ip)
{
  int val=0;
  String cmd="AT+CIPSTA=\""+ip+"\"";
  esp.println(cmd);
  espera(300);
  if(esp.find("OK")){val=1;}
  return val;
}
ESP8266::set_server(int puerto)
{
  int val=0;
  String cmd="AT+CIPSERVER=1,"+String(puerto);
  esp.println(cmd);
  espera(300);
  if(esp.find("OK")){val=1;}
  return val;
}
ESP8266::send_data(String dato)
{
  int val=0;
  unsigned int l=dato.length();
  String cmd="AT+CIPSEND=0,"+String(l);
  esp.println(cmd);
  espera(50);
  if(esp.find("OK"))
  {
    esp.println(dato);
    espera(50);
    if(esp.find("SEND OK"))
    {
      esp.println("AT+CIPCLOSE=0");
      espera(50);
      if(esp.find("OK")){val=1;}
    }
  }
  else{val=0;}
  return val;
}
