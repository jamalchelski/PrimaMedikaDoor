const int trigPin = 9;
const int echoPin = 10;
const int mag = 11;
int led_red = 4;
int led_green = 2;
int buzzer = 3;

long duration;
int distance;

//nilai batas cakupan sensorh 
int batas_atas = 40; //196
int batas_bawah = 65; //292

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(mag, INPUT);
  Serial.begin(9600);

}
void loop() {
  baca();
  //Serial.print("jarak : ");
  //Serial.println(distance);
  if (distance <= batas_atas){
    digitalWrite(led_green, LOW);
    digitalWrite(led_red, HIGH);
    noTone(buzzer);
    Serial.print("jarak kurang : ");
    Serial.println(distance);
  }
  else if (distance >= batas_bawah){
    digitalWrite(led_green, LOW);
    digitalWrite(led_red, HIGH);
    noTone(buzzer);
    Serial.print("jarak lebih : ");
    Serial.println(distance);
  }
  else {
    digitalWrite(led_green, HIGH);
    digitalWrite(led_red, LOW);
    tone(buzzer, 2000);
    Serial.print("jarak pas : ");
    Serial.println(distance);
  }

  delay(1000);
}

void baca() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }

  void readMagnetic(){
    if (digitalRead(mag)==HIGH){
      Serial.println("Pintu Tertutup");
    }
    else{
      Serial.print("Pintu Terbuka");
      }
  }
