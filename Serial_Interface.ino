 /* 2016.11.27
  *  This code will be to send variables to the arduino from the raspberry pi.
  *  
  *  This code was adapted from Trossen Robotics Community
  *  http://forums.trossenrobotics.com/tutorials/how-to-diy-128/complete-control-of-an-arduino-via-serial-3300/
  *  Numbers sent via serial are delimted by /
  *  Numbers sent to serial will be delimited by -
  *  Example Usage:
  *   '1/2/7/1/' will turn pin 7 on HIGH
  *   Sending '1/2/7/0/' would turn it off
  *   Sending '1/1/7/255/' would turn pin 7 on at a analog rate of 255 or full power
  *  
  */
// serialdata will be an unassigned long floating integer that stores a chain of numbers
unsigned long serialdata;

// inbyte will be the number recieved from the serial port
int inbyte;

//variables to control pins on the arduino
int digitalState;
int pinNumber;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //retreive latest data written on the serial port
  getSerial();
 //There are two cases for switch. One will be for the digital write and one for analog, which might be 
 //needed if we use an analog motor for dispensing nutrients.
  switch(serialdata)
  {
  case 1:
    {
      //analog digital write
      getSerial();
      switch (serialdata)
      {
      case 1:
        {
          //analog write
          getSerial();
          pinNumber = serialdata;
          getSerial();
          analogRate = serialdata;
          pinMode(pinNumber, OUTPUT);
          analogWrite(pinNumber, analogRate);
          pinNumber = 0;
          break;
        }
      case 2:
        {
          //digital write
          getSerial();
          pinNumber = serialdata;
          getSerial();
          digitalState = serialdata;
          pinMode(pinNumber, OUTPUT);
          if (digitalState == 0)
          {
            digitalWrite(pinNumber, LOW);
          }
          if (digitalState == 1)
          {
            digitalWrite(pinNumber, HIGH);
          }
          pinNumber = 0;
          break;
          
        }
     }
     break; 
   }
  }
}

long getSerial()
{
  serialdata = 0;
  while (inbyte != '/')
  {
    inbyte = Serial.read(); 
    if (inbyte > 0 && inbyte != '/')
    {
     
      serialdata = serialdata * 10 + inbyte - '0';
    }
  }
  inbyte = 0;
  return serialdata;
}
