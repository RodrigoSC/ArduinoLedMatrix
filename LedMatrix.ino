//byte character[8]={0xe7, 0xc3, 0x81, 0x24, 0x0, 0xdb, 0xa5, 0x5a}; // A space invader
//byte character[8]={0x93, 0x6d, 0x7d, 0x7d, 0xbb, 0xd7, 0xef, 0xff}; // A heart
byte character[8]={0xc3, 0xbd, 0x5a, 0x7e, 0x5a, 0x66, 0xbd, 0xc3}; // A smile

uint8_t rowPins[8]={10,11,12,13,A0,A1,A2,A3};
uint8_t colPins[8]={ 2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  // Turn everything to low
  for(int i=0; i<8; i++) {
    pinMode(colPins[i],OUTPUT);
    pinMode(rowPins[i],OUTPUT);
  }
}

void loop() {
  // iterate each row
   for(int row=0; row<8; row++) {
    for(int k=0; k<8; k++) digitalWrite(colPins[k],HIGH); // Cleanup cols
    digitalWrite(rowPins[row], HIGH); // prepare to write the row
    for(int col=0; col<8; col++) {
      digitalWrite(colPins[7-col], character[row] & 1 << col);
    }
    delay(1);
    digitalWrite(rowPins[row],LOW);
  }  
}
