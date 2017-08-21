void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(13, OUTPUT);
}



//Bluetooth

//VCC of BT (Bluetooth)) will be connected to 5v of arduino
//GND of BT will be connecgted to gnd of Arduino
//RXD of BT to the TX1(pin 18) of your arduino
//TXD of BT will go to RX1 (pin 19) of Arduino




void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available() > 0 ){
      int val = Serial1.read();
      if(val == "kash"){
          digitalWrite(13, HIGH);
          Serial.println("Led is ON");
          Serial1.println("Led is ON");
        }
      if(val == "aniket"){
          digitalWrite(13, LOW);
          Serial.println("Led is oFF");
          Serial1.println("Led is OFF");
        }
    }
}
