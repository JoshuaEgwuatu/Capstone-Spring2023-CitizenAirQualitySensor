unsigned long start_time = 0;
unsigned long my_time = 0;
bool has_ran = 0;
float volts = 0.0;
float cm = 0.0;
int Voltsadc;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial.flush();
  pinMode(A0, INPUT);
  start_time = micros();
}

void loop() {
  my_time = micros() - start_time;
  if(my_time <= 1000)
  {
    Voltsadc = analogRead(A0);
    count++;
    has_ran = 1;
  }
  else
  {
    if(has_ran == 1)
    {
      Serial.println(count); 
      has_ran = 0;
    }
    Serial.flush();
  }
}
