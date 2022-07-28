#define MIC A0

int sig = 0;

void setup() {
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
}

void led() {
 sig = analogRead(MIC)*50;

 if (sig>1)  {digitalWrite(2, HIGH);} 
 
 else {digitalWrite(2, LOW);}
 
 // for 300 volt = 49.5dB
 if (sig>300)  {digitalWrite(3, HIGH);} 
 
 else {digitalWrite(3, LOW);}

 //for 170dB = 316227766 volts
 if (sig>316227766) {digitalWrite(4, HIGH);} 
 
 else {digitalWrite(4, LOW);}
 
 //for the protection of mammals,200dB should be given to the condition
 //200dB = 10000000000volt ,when it reaches 200dB buzzer will alert the captian
 if (sig>10000000000) {digitalWrite(5, HIGH);} 
 
 else {digitalWrite(5, LOW);}
}

void loop() {
 led();
}
