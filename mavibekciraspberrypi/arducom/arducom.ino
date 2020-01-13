//Cezeri Robotics 2020 Tubitak
//Mavi Bekçi©
int kul_veri = 100;
const int in1 = 11;
const int in2 = 10;
const int in3 = 5;
const int in4 = 6;
const int led = 3;

int trigPin = 6;
int echoPin = 7;

long sure;
long uzaklik;
void setup() {
  Serial.begin(9600); /* Seri haberlesme baslatildi */
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(led, OUTPUT);

  pinMode(trigPin, OUTPUT); /* trig pini çıkış olarak ayarlandı */
  pinMode(echoPin, INPUT); /* echo pini giriş olarak ayarlandı */


}

void loop() {
  sensorGonder();

  if (Serial.available() > 0)
  {
    kul_veri = Serial.read();
  }

  if (kul_veri == 100) // Python ile gönderdiğimiz veri 'd'ye eşitse:
  {
    dur();

  }

  else if (kul_veri == 105) // Python ile gönderdiğimiz veri 'i'ye eşitse:
  {
    ileri();
  }

  else if (kul_veri == 103)// Python ile gönderdiğimiz veri 'g'ye eşitse:
  {
    sag();
  }

  else if (kul_veri == 108)// Python ile gönderdiğimiz veri 'l'ye eşitse:
  {
    sol();
  }

  else if (kul_veri == 111)// Python ile gönderdiğimiz veri 'o'ya eşitse:
  {
    oto();
  }

  else if (kul_veri == 102)// Python ile gönderdiğimiz veri 'f'ye eşitse:
  {
    far();
  }

}
void sensorGonder() {
  if (analogRead(A0 < 350) { // 350'nin altında bir değer okunursa su güvenli seviyededir.Suyun temiz olduğunu belirten 26 şifresini gönderebiliriz.
  Serial.println(26);
  }
  else {
    Serial.println(13); // 350'nin altında değilse suda kirlilik mevcuttur.Kirliliği belirten 13 şifresini gönderebiliriz.
  }
}
void dur() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void ileri() {
  digitalWrite(in1, HIGH);//sağdaki motor ileri
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);//soldaki motor ileri
  digitalWrite(in4, LOW);
}

void sag() {
  digitalWrite(in1, HIGH);//sağdaki motor ileri
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void sol() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);//soldaki motor ileri
  digitalWrite(in4, LOW);

}

void oto() {
  digitalWrite(trigPin, LOW); /* sensör pasif hale getirildi */
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */
  sure = pulseIn(echoPin, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */
  uzaklik = sure / 29.1 / 2; /* ölçülen sure uzaklığa çevriliyor */

  if (uzaklik <= 5)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);//soldaki motor ileri
    digitalWrite(in4, LOW);
  }
  Serial.println(uzaklik);

}
void far() {
  if (digitalRead(led)) { // led yanıksa söndür,sönükse yak.
    digitalWrite(led, LOW);
  }
  else {
    digitalWrite(led, HIGH);
  }
}
