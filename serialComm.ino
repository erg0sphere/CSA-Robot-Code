

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  while(!Serial){
    ;
  }
}

void loop() {
  // send data only when you receive data:

  
  if (Serial.available() > 0) 
  {
    
    byte incomingByte = Serial.read();

    int data = incomingByte;

   
    if(incomingByte != -1)
    {
      if(data == 1)
      {
        digitalWrite(2, HIGH);
        delay(5000);
      }
      else if(data == 2)
      {
        digitalWrite(3, HIGH);
        delay(5000);
      }
    }
  }
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}
