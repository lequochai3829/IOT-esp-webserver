#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer webServer(80);
#include "Mainpage.h"

char* ssid = "TEN WIFI";
char* pass = "MAT KHAU WIFI";

void setup() {
  WiFi.begin(ssid,pass);
  Serial.begin(9600);
  Serial.print("Connecting");
  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print("...");
  }
  Serial.println(WiFi.localIP());

  webServer.on("/",mainpage);
  webServer.on("/readA0", [] {
    webServer.send(200, "text/html", String(analogRead(A0))
          );
  });
  webServer.begin();
}
void loop() {
  webServer.handleClient(); //ESP cho tin hieu tu Client
}
//==========Chương trình con=================//
void mainpage(){
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
