const int led = 7;
const int IR = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(IR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(IR);
  if(value == HIGH)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}
