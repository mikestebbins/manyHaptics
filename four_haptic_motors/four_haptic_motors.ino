#include "Adafruit_DRV2605.h"
#include <i2c_t3.h>

Adafruit_DRV2605_0 drv_0;
Adafruit_DRV2605_1 drv_1;
Adafruit_DRV2605_2 drv_2;
Adafruit_DRV2605_3 drv_3;

//-----------------------------------------------------------------------------------------
// SETUP
//-----------------------------------------------------------------------------------------

void setup() {
  Serial.begin(9600);
  Serial.println("DRV test");

  drv_0.begin();
  drv_1.begin();
  drv_2.begin();
  drv_3.begin();

  // I2C trigger by sending 'go' command 
  drv_0.setMode(DRV2605_MODE_INTTRIG); // default, internal trigger when sending GO command
  drv_1.setMode(DRV2605_MODE_INTTRIG);
  drv_2.setMode(DRV2605_MODE_INTTRIG);
  drv_3.setMode(DRV2605_MODE_INTTRIG);

  drv_0.selectLibrary(1);
  drv_1.selectLibrary(1);
  drv_2.selectLibrary(1);
  drv_3.selectLibrary(1);
}

//-----------------------------------------------------------------------------------------
// LOOP
//-----------------------------------------------------------------------------------------
void loop()  {
    sequence(0,'A',1,0,'B',1,0,'C',1,0,'D',1);
    delay(500);
    sequence(100,'A',1,100,'B',1,100,'C',1,100,'D',1);
    delay(500);
    sequence(100,'D',1,100,'C',1,100,'B',1,100,'A',1);
    delay(500);
    
    sequence(0,'D',1,0,'C',1);
    delay(100);
    sequence(0,'A',1,0,'B',1);
    delay(100);
    sequence(0,'D',1,0,'C',1);
    delay(100);
    sequence(0,'A',1,0,'B',1);
    delay(100);
    sequence(0,'D',1,0,'C',1);
    delay(100);
    sequence(0,'A',1,0,'B',1);
    delay(2000);
}

//-----------------------------------------------------------------------------------------
// FUNCTIONS
//-----------------------------------------------------------------------------------------

// Play a sequence of effects on 4 motors (one effect on motor 0, then some milliseconds later one effect on motor 2, etc.)
void sequence(int dly0, char motor0, int effect0, int dly1, char motor1, int effect1, int dly2, char motor2, int effect2,int dly3, char motor3, int effect3)
{
    if (dly0 != 0)  {
        delay(dly0);
    }
    playEffect(motor0,effect0);
    
    if (dly1 != 0)  {
        delay(dly1);
    }
    playEffect(motor1,effect1);
    
    if (dly2 != 0)  {
        delay(dly2);
    }
    playEffect(motor2,effect2);
    
    if (dly3 != 0)  {
        delay(dly3);
    }
    playEffect(motor3,effect3);
}

// Play a sequence of effects on 3 motors (one effect on motor 0, then some milliseconds later one effect on motor 2, etc.)
void sequence(int dly0, char motor0, int effect0, int dly1, char motor1, int effect1, int dly2, char motor2, int effect2)
{
    if (dly0 != 0)  {
        delay(dly0);
    }
    playEffect(motor0,effect0);
    
    if (dly1 != 0)  {
        delay(dly1);
    }
    playEffect(motor1,effect1);
    
    if (dly2 != 0)  {
        delay(dly2);
    }
    playEffect(motor2,effect2);
}

// Play a sequence of effects on 2 motors (one effect on motor 0, then some milliseconds later one effect on motor 2, etc.)
void sequence(int dly0, char motor0, int effect0, int dly1, char motor1, int effect1)
{
    if (dly0 != 0)  {
        delay(dly0);
    }
    playEffect(motor0,effect0);
    
    if (dly1 != 0)  {
        delay(dly1);
    }
    playEffect(motor1,effect1);
}

// Play a sequence of effects on 1 motor1 (one effect on motor 0, then some milliseconds later one effect on motor 2, etc.)
void sequence(int dly0, char motor0, int effect0)
{
    if (dly0 != 0)  {
        delay(dly0);
    }
    playEffect(motor0,effect0);
}

// Play one effect on one motor
void playEffect(char motor, int effectNumber)  
{
    if (motor == 'A') 
    {
        drv_0.setWaveform(0, effectNumber);
        drv_0.setWaveform(1, 0);  // end of waveforms
        drv_0.go();  
    }
    if (motor == 'B') 
    {
        drv_1.setWaveform(0, effectNumber);
        drv_1.setWaveform(1, 0);  // end of waveforms
        drv_1.go();  
    }
    if (motor == 'C') 
    {
        drv_2.setWaveform(0, effectNumber);
        drv_2.setWaveform(1, 0);  // end of waveforms
        drv_2.go();  
    }
    if (motor == 'D') 
    {
        drv_3.setWaveform(0, effectNumber);
        drv_3.setWaveform(1, 0);  // end of waveforms
        drv_3.go();  
    }
}
