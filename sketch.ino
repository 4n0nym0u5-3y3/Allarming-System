int pirsensor = 0;

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT); 
 pinMode(13, OUTPUT);
 pinMode(2, INPUT);
 pinMode(8, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  pirsensor = digitalRead(2);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;


  if(pirsensor == HIGH || distance < 50){
    digitalWrite(13, HIGH);
    tone(8, 1000, 500);
  }
  else{
    digitalWrite(13, LOW);
  }

  Serial.print("Distanza: ");
  Serial.println(distance);
  delay(10);
}