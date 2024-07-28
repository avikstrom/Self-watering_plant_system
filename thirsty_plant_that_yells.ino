//author: Abigail Vikstrom
//date: February 2024
//purpose: This code lights up an LED (output) and sounds an alarm (output) based on water levels (input) to keep my plant happy

//Arduino water level sensor code
// CODE FROM: https://circuitdigest.com/microcontroller-projects/interfacing-water-level-sensor-with-arduino
// Sensor pins pin D22 LED output, pin A8 analog Input

#define ledPin 45
#define sensorPin A8
#define buzzer 22

void setup() {

  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzer,OUTPUT);

  digitalWrite(ledPin, LOW);
  digitalWrite(buzzer,LOW);

}

void loop()

{
  int toneFreq = 300;
  unsigned int sensorValue = analogRead(sensorPin);

  if (sensorValue < 540)

    return;

  uint8_t outputValue = map(sensorValue, 540, 800, 0, 255);

  Serial.print(sensorValue);

  Serial.print(" ");

  //Serial.println(outputValue);
  //led gets brighter when sensor gets wetter
  analogWrite(ledPin, outputValue); // generate PWM signal

if (outputValue < 5){

  tone(buzzer, toneFreq, 5000);  // ... and play the tone for a half second
  delay(500);
  noTone(buzzer);
}
 

}


