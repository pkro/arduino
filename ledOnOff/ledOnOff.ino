/*
 * Turn led on by sending 1 over serial, off with 0
 * 
 */
int myPin = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(myPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char key = Serial.read();
    if(key=='1') {
      digitalWrite(myPin, HIGH);
      notify(key);
    }
    else if(key=='0') {
      digitalWrite(myPin, LOW);
      notify(key);
    }
    
  }
  // put your main code here, to run repeatedly:
  
  //delay(1000);
  //digitalWrite(myPin, LOW);
  //delay(1000);
  
}

void notify(char state) {
  char *msg = "Led was turned ";
  char *cr = "\r\n";
  //msg.concat((state == '0' ? "off" : "on"));
  //msg.concat(cr);
  
  Serial.write(msg, sizeof(msg));
}
