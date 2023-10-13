const int redPin = 2;     // Red LED connected to pin 2 
const int greenPin = 3;   // Green LED connected to pin 3
const int yellowPin = 4;  // Yellow LED connected to pin 4
const int buttonPin = 5;  // Button connected to pin 5
const int buzzerPin = 6;  // Buzzer connected to pin 6
unsigned long prevmillis = 0;
unsigned long curmillis = 0;
const long onesec = 1000;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT); 
}

void loop()

 // Initially, Red light flashes until the button is pressed with 1 sec delay
{
 long int curmillis = millis();
 while (millis() - curmillis < onesec)
  {digitalWrite(redPin, HIGH);
    if (digitalRead(buttonPin) == LOW) 
    {trafficlight();}
   }
 
 long int prevmillis = millis();
 while (millis() - prevmillis < onesec)
  {digitalWrite(redPin, LOW);
    if (digitalRead(buttonPin) == LOW) 
    {trafficlight();}
   }
}

void trafficlight () //Traffic light Function
 {
  // Red light stays on for 24 seconds
  digitalWrite(redPin, HIGH);
  delay(21000);
  
  // During the last three seconds, flash the Red light
  for (int i = 0; i < 3; i++) {
    digitalWrite(redPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(redPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }
  
  // Green light stays on for 20 seconds
  digitalWrite(greenPin, HIGH);
  delay(17000);
  
  // During the last three seconds, flash the Green light
  for (int i = 0; i < 3; i++) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(greenPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }
  
  // Yellow light stays on for 3 seconds
 for (int i = 0; i < 3; i++) {
    digitalWrite(yellowPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }
  
  
  // Transition back to Red light
  digitalWrite(buzzerPin, LOW);
  digitalWrite(yellowPin, LOW);
  
 
  trafficlight ();
}
