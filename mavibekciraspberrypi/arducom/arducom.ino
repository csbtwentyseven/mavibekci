int datafromUser=0;
void setup() {
  // put your setup code here, to run once:
  pinMode( 8 , OUTPUT );
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    datafromUser=Serial.read();
  }

  if(datafromUser == 97)
  {
    digitalWrite( 8 , HIGH );
    
  }
  else
  {
    digitalWrite( 8, LOW);
  }
  
}
