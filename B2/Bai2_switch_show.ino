#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer webServer(80);
#include "Mainpage.h"

char* ssid = "My";
char* pass = "123456789thuong";

void setup() {
  pinMode(D1,OUTPUT);
  pinMode(D4,OUTPUT);
  digitalWrite(D1,HIGH);
  digitalWrite(D4,HIGH);
  WiFi.begin(ssid,pass);
  Serial.begin(9600);
  Serial.print("Connecting");
  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print("...");
  }
  Serial.println(WiFi.localIP());

  webServer.on("/",mainpage);
  webServer.on("/onD1",on_D1);
  webServer.on("/offD1",off_D1);
  webServer.on("/onD4",on_D4);
  webServer.on("/offD4",off_D4);
  webServer.on("/checkstatusD1D4",check_statusD1D4);
  webServer.begin();
}
void loop() {
  webServer.handleClient();
}
//==========Chương trình con=================//
void mainpage(){
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void on_D1(){
  digitalWrite(D1,LOW);
  webServer.send(200,"text/html","D1  ON");
}
void off_D1(){
  digitalWrite(D1,HIGH);
  webServer.send(200,"text/html","D1 OFF");
}
void on_D4(){
  digitalWrite(D4,LOW);
  webServer.send(200,"text/html","D4  ON");
}
void off_D4(){
  digitalWrite(D4,HIGH);
  webServer.send(200,"text/html","D4 OFF");
}
void check_statusD1D4(){
  String d1,d4;
  if(digitalRead(D1)==1){
    d1 = "OFF";
  }else{
    d1 = "ON";
  }
  if(digitalRead(D4)==1){
    d4 = "OFF";
  }else{
    d4 = "ON";
  }
  String s = "{\"D1\": \""+ d1 +"\",\"D4\": \""+ d4 +"\"}";
  webServer.send(200,"application/json",s);
}
