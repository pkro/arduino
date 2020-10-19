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
"--.."}; // z

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  if (Serial.available()) {

    char key = Serial.read();
    key = (int) key - 97; // 0 based abc,,,

    morseChar(morseCodes[key]);
  }
}

void morseChar(String str) {
  int signalLengths[] = {400, 800}; // short / long morse
  int lightFor = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '.') {
      lightFor = signalLengths[0];
    } else {
      lightFor = signalLengths[1];
    }

    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(lightFor);                   // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(200);                       // wait for a second
  }
}
