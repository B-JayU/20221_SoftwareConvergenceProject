int trig = 8;
int echo = 9;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
   float Length, distance;

   digitalWrite(trig, LOW);
   delay(2);
   digitalWrite(trig, HIGH);
   delay(10);
   digitalWrite(trig, LOW);
}

distance = ((float) (340*Length) / 10000) /2;

Serial.print(distance)
Serial.println(" Cm");

delay(1000)
