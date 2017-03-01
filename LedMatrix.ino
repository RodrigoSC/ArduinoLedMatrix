//byte character[8]={0x18, 0x3c, 0x7e, 0xdb, 0xff, 0x24, 0x5a, 0xa5}; // A space invader
//byte character[8]={0x6c, 0x92, 0x82, 0x82, 0x44, 0x28, 0x10, 0x0};// A heart
byte character[8]={0x3c, 0x42, 0xa5, 0x81, 0xa5, 0x99, 0x42, 0x3c}; // A smile

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
      digitalWrite(colPins[7-col], character[row] & 1 << col ? LOW : HIGH);
    }
    delay(1);
    digitalWrite(rowPins[row],LOW);
  } 
}
