const int led = 7;
const int sw = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(sw, INPUT); //Floating state
}

void loop() {
  // put your main code here, to run repeatedly:

  int val = digitalRead(sw);

  if(val ==LOW)
    digitalWrite(led, HIGH);
  if(val == HIGH)
    digitalWrite(led, LOW);
  //  (pin Number, State);

}
