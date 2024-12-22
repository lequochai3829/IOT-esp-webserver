#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer webServer(80);
#include "Mainpage.h"

char* ssid = "Tên wifi";
char* pass = "mật khẩu wifi";
String sliderValue = "50";

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
  webServer.on("/setPOS",handleSlider); // Goi ham doc value cua slider
  webServer.on("/checkstatus",check_status);
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
void handleSlider(){
  String POS = webServer.arg("sliderPOS");  // Đọc tín hiệu từ web
  sliderValue = webServer.arg("sliderPOS");
  int pos = POS.toInt();  // Chuyển đổi string thành int
  delay(15);
  Serial.print("Slider Angle:");
  Serial.println(pos);
  webServer.send(200, "text/plane","");
}
void check_status(){
  String s = "{\"slidervalue\": \""+ sliderValue +"\"}";
  webServer.send(200,"application/json",s);
}
