#include <PRIZM.h>    // include the PRIZM library in the sketch
PRIZM prizm;          // instantiate a PRIZM object “prizm” so we can use its functions

void setup() 

{        

  prizm.PrizmBegin();   // Initialize the PRIZM controller
}

void loop() 
{     
  while(prizm.readSonicSensorCM(3) > 30)
  {
    prizm.setMotorPower(1,50); 
    prizm.setMotorPower(2,50);
  }
  
  prizm.setMotorPower(1,0); 
  prizm.setMotorPower(2,0);     
  
}
