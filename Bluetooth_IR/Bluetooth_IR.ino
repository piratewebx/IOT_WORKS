const int IR = 2;
const int led = 7;
int cstate = 1;
int pstate = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(IR, INPUT);
  Serial.begin(9600);
  Serial1.begin(9600);
}



//Bluetooth

//VCC of BT (Bluetooth)) will be connected to 5v of arduino
//GND of BT will be connecgted to gnd of Arduino
//RXD of BT to the TX1(pin 18) of your arduino
//TXD of BT will go to RX1 (pin 19) of Arduino




void loop() {
  // put your main code here, to run repeatedly:
  int cstate = digitalRead(IR);
  if(cstate != pstate){
    if(cstate == 0){
      digitalWrite(led, HIGH);
      Serial1.println("There is a visitor");
    }
    else
      digitalWrite(led, LOW);
      pstate = cstate;
  }

  delay(1000);
}
