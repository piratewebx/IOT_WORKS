#include <ESP8266WiFi.h>

const char* host = "api.thingspeak.com"; // Your domain  
String ApiKey = "9XRPW6UPS8PDZXOJ";
String path = "/update?key=" + ApiKey + "&field1=";  


const char* ssid = "Dhinchak Pooja";
const char* pass = "Qwerty123";

int sensor = A0;

float tempc;
float svoltage;
  

void setup(void){
  Serial.begin(115200); // NodeMCU and PC/LAPTOP
  Serial.println("");
  
  WiFi.begin(ssid, pass);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
}


void loop() {

  float xval = analogRead(sensor);
  
  
  svoltage = (xval*3100.0)/1023; // 3.1 V
  tempc = svoltage/10;
  Serial.println(tempc);
  
   
  
  WiFiClient client;
  
  const int httpPort = 80;
  
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  client.print(String("GET ") + path + String(tempc) + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: keep-alive\r\n\r\n");
  delay(16000);

}
