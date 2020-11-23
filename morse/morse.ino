// morse code a-z
String morseCodes[26] = {
  ".-", //a
  "-...",
  "-.-.",
  "-..",
  ".",
  "..-.",
  "--.",
  "....",
  "..",
  ".---",
  "-.-",
  ".-..",
  "--",
  "-.",
  "---",
  ".--.",
  "--.-",
  ".-.",
  "...",
  "-",
  "..-",
  "...-",
  ".--",
  "-..-",
  "-.--",
  "--.."
}; // z

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}


void loop() {
  if (Serial.available()) {

    char key = Serial.read();
    Serial.println(key);
    key = (int) key - 97; // 0 based abc,,,

    morseChar(morseCodes[key]);
  }
}

void morseChar(String str) {
  int shortSignal = 400; //milisecs to blink
  int longSignal = 800;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '.') {
      blinkLed(shortSignal);
    } else {
      blinkLed(longSignal);
    }
  }
}

void blinkLed(int miliseconds) {
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(miliseconds);                   // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  delay(200);                       // wait for a second
}
