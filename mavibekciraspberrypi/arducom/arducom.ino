//Cezeri Robotics 2020 Tubitak
//Mavi Bekçi

int kul_veri = 0;
const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 8;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
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

void dur(){
 
}

void ileri(){
  
}

void sag(){

  
}

void sol(){

 
}

void oto(){

  
}
void far(){
  
}
