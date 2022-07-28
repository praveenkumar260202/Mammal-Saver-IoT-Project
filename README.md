
## MAMMAL SAVER

Our project aims to detect the sound level of the ship. If the sound level of the ship is above 200dB ,the detector will alert the captain of the ship so that he could reduce the speed of the ship which reduce the sound energy. This could reduce the death of marine mammals.

We will use a normal Electret Condenser microphone with Arduino and try measuring the sound or noise pollution level in dB as close as possible to the actual value. We will use a normal amplifier circuit to amplify the sound signals and feed it to Arduino .We use regression method to calculate the sound signals in db. If the sound level is above the critical level (200 dB) then the indicator light will be glown.

Once we are ready with our circuit we can connect the Arduino to computer and upload the “Analog Read Serial” Example program from Arduino to check if we are getting valid ADC values fromour microphone. Now we have to convert this ADC values to dB.

CONVERTING Analogread values from microphone to Decibel:

sensorValue = analogRead(A0); //where A0 is the analoginpin

double db = 20.0 * log10 (sensorValue + 1.); //this is the basic formula to convert analog read values to decibel

CODE EXPLANATION:

#define MIC A0 //The A0 pin gets the analog read values(voltage)

int sig = 0;

void setup() //4 LEDS are glown based on decibel

{

pinMode(2, OUTPUT);

pinMode(3, OUTPUT);

pinMode(4, OUTPUT);

pinMode(5, OUTPUT);

}

void led() {

sig = analogRead(MIC)*50;//amplifying the analog read value (voltage)

if (sig>1) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);} //1 volt =0 dB, if the incoming signal is greater than 0dB then the pin 2 will be glown

if (sig>300) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);} //300 volt =49.5dB, if the incoming signal is greater than 49.5dB then the pin 3 will be glown

if (sig>800) {digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);} //800 volt =58.1db ,if the incoming signal is greater than 58.1dB then the pin 4 will be glown

if (sig>950) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);} //950volt =59.6db, if the incoming signal is greater than 59.6dB then the pin 5 will be glown

//for the protection of mammals,200dB should be given to the condition loop ie.

if (sig>10000000000) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);} //10000000000volt =200db, if the incoming signal is greater than 200dB then the LED will be glown

}

void loop() {

led();

}
