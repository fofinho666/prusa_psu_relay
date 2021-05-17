const int RELAY_PIN = 10;
int incomingByte = 0;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  SerialUSB.begin(9600);
}

void loop() {
   if (SerialUSB.available() > 0) {
    incomingByte = SerialUSB.read();

    if(incomingByte == '0'){
      digitalWrite(RELAY_PIN, LOW);
    }
    else if(incomingByte == '1'){
      digitalWrite(RELAY_PIN, HIGH);
    }
  }
}
