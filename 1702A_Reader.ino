void setup() {
  //IO
  DDRB = 0b00111111; //Addr 2-7
  DDRD = 0b11000010;
    //Addr 0-1, Data 6-7, NC, NC, TX, RX
  DDRC = 0b00000000; //Data 0-5
  PORTC = 0b00111111; //pull ups
  PORTD = 0b00110000; //pull up
  
  Serial.begin(9600);

  for(int i = 0; i < 256; i++) { //loop data
    if(i % 16 == 0) Serial.println();
    PORTB = i >> 2; //set addr hi
    PORTD = (i << 6) | 0b110000; //lo
    delayMicroseconds(50);
    byte data = PINC | ((PIND <<2) & 0b11000000); //data
    if (data < 16) Serial.print("0"); //leading zero
    Serial.print(data, HEX); //output byte
    Serial.print(", ");
  }
}

void loop() {
}
