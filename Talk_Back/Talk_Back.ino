int led=13;


void setup()
{
  
  Serial.begin(9600);
  Serial1.begin(115200);// RXD - TX1, TXD - RX1
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  delay(100);
  connectWiFi();
 
}

void loop()
{
  Serial1.println("AT+CIPMUX=0\r\n");
  delay(1000);
    
  // TCP connection 
String cmd = "AT+CIPSTART=\"TCP\",\""; 
cmd += "184.106.153.149"; 
// api.thingspeak.com 
cmd += "\",80\r\n\r\n"; 

Serial1.println(cmd);

delay(1000);

if(Serial1.find("ERROR")
)
{ 
Serial.println("AT+CIPSTART error"); 
return; 
}

// prepare GET string 

String getStr = "GET /talkbacks/17511/commands/7636389?api_key=NEATA7F4ZM6VRF7E\r\n\r\n";

// send data length 

cmd = "AT+CIPSEND="; 
cmd += String(getStr.length());
cmd+="\r\n";

Serial1.println(cmd); 

delay(100);

if(Serial1.find(">"))
{
 Serial.println("Request Sent"); 
 Serial1.print(getStr);
 }
 else
{ 
Serial1.println("AT+CIPCLOSE"); 
// alert user 
Serial.println("Closing Connection");
 } 
delay(5000);


String recd="";

if(Serial1.available()>0){
  delay(1000);
   while(Serial1.available())
  {
    recd+=(char(Serial1.read()));
  }
  Serial.println("____________");
  Serial.println("Response: ");
  
  Serial.print(recd);
 }

if(find_text_ON("LEDON",recd)==1)
    digitalWrite(led,HIGH);
if(find_text_OFF("LEDOFF",recd)==1)
  digitalWrite(led,LOW);
    
delay(5000);  

}

 int find_text_ON(String sr, String recd) {
      int foundpos = -1;
      for (int i = 0; (i < recd.length() - sr.length()); i++) {
        if (recd.substring(i,sr.length()+i) == sr) {
          foundpos = 1;
        }
      }
      return foundpos;
    }
  int find_text_OFF(String sr, String recd) {
      int foundpos = -1;
      for (int i = 0; (i < recd.length() - sr.length()); i++) {
        if (recd.substring(i,sr.length()+i) == sr) {
          foundpos = 1;
        }
      }
      return foundpos;
    }
 




boolean connectWiFi()
{
  Serial1.println("AT+CWMODE=1");
  delay(100);
   
  
  String cmd="AT+CWJAP=\"";
  cmd+="Dhinchak Pooja";
  cmd+="\",\"";
  cmd+="Qwerty123";
  cmd+="\"";
  Serial.println(cmd);
  
  Serial1.println(cmd);
  delay(5000);
  
  Serial1.print("AT+CWJAP?");
  
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
