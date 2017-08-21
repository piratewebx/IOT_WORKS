int ledPin = 13;

float j=0;
int sensor = A0; 

String apiKey = "9XRPW6UPS8PDZXOJ";


void setup()
 { 
pinMode(ledPin, OUTPUT); 

Serial.begin(9600); 
Serial1.begin(115200); 
connectWiFi();

} 

void loop() { 

float val=analogRead(sensor);
float vout = (val*5000.0)/1023;
float tempc=vout/10; // Storing value in Degree Celsius
  
j=tempc;

digitalWrite(ledPin, HIGH); 
delay(500); 
digitalWrite(ledPin, LOW); 

Serial1.println("AT+CIPMUX=0\r\n");
delay(2000);

// TCP connection 
String cmd = "AT+CIPSTART=\"TCP\",\""; 
cmd += "184.106.153.149"; 
// api.thingspeak.com 
cmd += "\",80\r\n\r\n"; 

Serial1.println(cmd);
Serial.println(cmd);

delay(20000);

if(Serial1.find("ERROR"))
{ 
Serial.println("AT+CIPSTART error"); 
//return; 
}

// prepare GET string 

String getStr = "GET /update?api_key=";
 getStr += apiKey;
 getStr +="&field1=";
 getStr += j; 
getStr += "\r\n\r\n"; 

// send data length 

Serial.println(getStr);

cmd = "AT+CIPSEND="; 
cmd += String(getStr.length());
cmd+="\r\n";

Serial1. println(cmd); 
Serial.println(cmd);

delay(20000);

if(Serial1.find(">"))
{
Serial.println("connected to Cloud"); 
Serial1.print(getStr);
 }
 else
{ 
Serial1.println("AT+CIPCLOSE\r\n"); 
// alert user 

Serial.println("AT+CIPCLOSE");
 } 
// thingspeak needs 16 sec delay between updates 

delay(16000); 

 }

boolean connectWiFi()
{

Serial1.println("AT+CWMODE=1\r\n");
delay(100);

String cmd = "AT+CWJAP=\"";
cmd += "Dhinchak Pooja";
cmd += "\",\"";
cmd += "Qwerty123";
cmd += "\"\r\n";
  
Serial.println(cmd);
Serial1.println(cmd);
  
delay(10000);

Serial1.println("AT+CWJAP?");

 if(Serial1.find("+CWJAP"))
  {
    Serial.println("OK, Connected to WiFi.");
    return true;
  }
  else{
    Serial.println("Can not connect to the WiFi.");
    return false;
  }
}
