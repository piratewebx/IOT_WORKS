void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0 ){
      int val = Serial.parseInt();
      if(val == "kash"){
          digitalWrite(13, HIGH);
        }
      if(val == 'b'){
          digitalWrite(13, LOW);
        }
    }
}
