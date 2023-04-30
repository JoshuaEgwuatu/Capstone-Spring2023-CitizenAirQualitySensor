int analogPin = A0; //initializing which pin the arduino is going to read fromn
int val = 0;  // variable to store the value read from the analogRead function

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  float voltage = val * (5.0 / 1023.0); //convert back to voltage
  Serial.println(voltage);           
}
