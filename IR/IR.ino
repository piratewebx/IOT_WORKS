const int ir = 3;
const int led = 7;
int cstate = 1;
int pstate =1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(ir, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int cstate = digitalRead(ir);
if(cstate != pstate){
  if(cstate == 0){
    digitalWrite(led, HIGH);
    Serial.println("There is a visitor");
    }
    else
    digitalWrite(led, LOW);

    pstate = cstate;
  }

  delay(1000);
}
