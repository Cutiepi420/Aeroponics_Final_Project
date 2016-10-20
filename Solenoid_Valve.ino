/*The purpose of this code is to activate and deactivate a solenoid valve*/
// Pin assignments
int SOL1 = 8; // solenoid valve on pin 8
int led = 13; // LED on pin 13 (to see if the system is working properly)

void setup() {
  //Setting the solenoid initially off and reading the output
  digitalWrite(SOL1, LOW);
  pinMode(SOL1, OUTPUT);
  delay(4000);
  pinMode(led, OUTPUT);
}
//Currently, the loop modulates between the open and closed states of a relay. 
//This is not adaptive, however, it will supply a constant amount of water over time

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(SOL1, HIGH);
  delay(3800);
  digitalWrite(SOL1, LOW);
  delay(2000);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(800);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second

}



// What can be added: Eventually, we could add in a feature that pauses the loop 
// so that the solenoid valve can remain closed while maintenance is performed on
// the system
