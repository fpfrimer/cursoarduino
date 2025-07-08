// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on
  delay(sensorValue);               // wait based on analog input
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off
  delay(sensorValue);               // wait again based on analog input
}
