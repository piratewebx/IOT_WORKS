#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;


void setup() {

    pinMode(LED_BUILTIN, OUTPUT);  
   
    USE_SERIAL.begin(115200);
   // USE_SERIAL.setDebugOutput(true);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);
    }

    WiFiMulti.addAP("AndroidAP", "dznv9966");

}

void loop() {
    // wait for WiFi connection
    if((WiFiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;

        USE_SERIAL.print("[HTTP] begin...\n");
        
        http.begin("http://184.106.153.149/talkbacks/17502/commands/7633986?api_key=3T61W9SMDFHSR7ZU"); //HTTP

        USE_SERIAL.print("[HTTP] GET...\n");
        
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                USE_SERIAL.println(payload);
            if(payload=="LEDOFF")
            {
              digitalWrite(LED_BUILTIN, HIGH);
              //digitalWrite(relay, HIGH);
            }
            if(payload=="LEDON")
              {
              digitalWrite(LED_BUILTIN, LOW);
              //digitalWrite(relay, LOW);
              }
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

    delay(10000);
}
