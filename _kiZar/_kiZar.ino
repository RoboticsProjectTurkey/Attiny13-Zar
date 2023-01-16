#define latchPin  PB2
#define clockPin PB1
#define dataPin  PB0
#define buttonPin  PB4
byte bits;
byte myfnNumToBits(int someNumber) {
  switch (someNumber) {
    case 0:
      return B00000011;
      break;
    case 1:
      return B11110011;
      break;
    case 2:
      return B00100101;
      break;
    case 3:
      return B00001101;
      break;
    case 4:
      return B10011001;
      break;
    case 5:
      return B01001001;
      break;
    case 6:
      return B01000001;
      break;
    default:
      return B11111101; // Error condition, displays three vertical bars
      break;
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  randomSeed(analogRead(A3));
}

void loop() {
  // generate characters to display for hexidecimal numbers 0 to F
  if (digitalRead(buttonPin) == 1) {
    digitalWrite(latchPin, LOW);
    bits = myfnNumToBits(random(0, 7)) ;
    myfnUpdateDisplay(bits);    // display alphanumeric digit 
    bits = myfnNumToBits(random(0, 7)) ;
    myfnUpdateDisplay(bits);
    digitalWrite(latchPin, HIGH); // update display
    delay(1500);                 // pause for 1/2 second
  }
}
void myfnUpdateDisplay(byte eightBits) {
  shiftOut(dataPin, clockPin, LSBFIRST, eightBits); // send data
}
