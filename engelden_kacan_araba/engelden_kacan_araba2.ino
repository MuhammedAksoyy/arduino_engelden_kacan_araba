#define echoPin 13
#define trigPin 12
#define MotorR1 7
#define MotorR2 6
#define MotorRE 9
#define MotorL1 5
#define MotorL2 4
#define MotorLE 3
//#define buzzerPin 8 // Buzzer pini tanımlanıyor

long sure, uzaklik;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT);
 // pinMode(buzzerPin, OUTPUT); // Buzzer pini çıkış olarak ayarlanıyor
}

void loop() {
  digitalWrite(trigPin, 0);
  delayMicroseconds(2);
  digitalWrite(trigPin, 1);
  delayMicroseconds(5);
  digitalWrite(trigPin, 0);

  sure = pulseIn(echoPin, HIGH);
  uzaklik = sure / 58;

  if (uzaklik < 20) {
    
    geri();
    delay(600);
    sag();
    delay(400);
   // digitalWrite(buzzerPin, HIGH); // Buzzer'a sinyal gönderilerek ötmesi sağlanıyor
    //delay(200); // Buzzer'ın ötme süresi
    //digitalWrite(buzzerPin, LOW); // Buzzer kapatılıyor
    
  } else {
    ileri();
  }
}

void sag() {
  digitalWrite(MotorR1, 0);
  digitalWrite(MotorR2, 1);
  analogWrite(MotorRE, 150);
  
  digitalWrite(MotorL1, 1);
  analogWrite(MotorL2, 0);
  analogWrite(MotorLE, 150);
}

void ileri() {
  digitalWrite(MotorR1, 1);
  digitalWrite(MotorR2, 0);
  analogWrite(MotorRE, 255);
  
  digitalWrite(MotorL1, 1);
  digitalWrite(MotorL2, 0);
  analogWrite(MotorLE, 255);
}

void geri() {
  digitalWrite(MotorR1, 0);
  digitalWrite(MotorR2, 1);
  analogWrite(MotorRE, 150);
  
  digitalWrite(MotorL1, 0);
  digitalWrite(MotorL2, 1);
  analogWrite(MotorLE, 150);
}
