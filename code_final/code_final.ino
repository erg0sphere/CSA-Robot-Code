#include <PRIZM.h>    // include the PRIZM library in the sketch
PRIZM prizm;          // instantiate a PRIZM object “prizm” so we can use its functions

void setup() 

{        

  prizm.PrizmBegin();   // Initialize the PRIZM controller
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  while(!Serial)
  {
    ;
  }
}

void loop() 
{     
  if (Serial.available() > 0) 
  {
    
    byte incomingByte = Serial.read();

    int data = incomingByte;

   
    if(incomingByte != -1)
    {
      if(data == 1)
      {
        prizm.setMotorPower(1,-50); 
        prizm.setMotorPower(2,50);
      }
      else if(data == 2)
      {
        prizm.setMotorPower(1,50); 
        prizm.setMotorPower(2,-50);
      }
      else if(data == 3)
      {
        prizm.setMotorPower(1,0); 
        prizm.setMotorPower(2,0);
      }
    }
  }
 
}

/*
  while(prizm.readSonicSensorCM(3) > 30)
  {
    prizm.setMotorPower(1,-50); 
    prizm.setMotorPower(2,50);
  }
  prizm.setMotorPower(1,0); 
  prizm.setMotorPower(2,0);
  
  if (prizm.readLineSensor(2) == HIGH)
  {
    prizm.setMotorPower(1,50); 
    prizm.setMotorPower(2,-50);

    delay(3000);

    prizm.setMotorPower(1,0); 
    prizm.setMotorPower(2,0);

    prizm.setMotorPower(1,-50); 
    prizm.setMotorPower(2,0);

    delay(3000);

    prizm.setMotorPower(1,-50); 
    prizm.setMotorPower(2,50);

    prizm.setMotorPower(1,0); 
    prizm.setMotorPower(2,0);
    
  }
      
  
} */
