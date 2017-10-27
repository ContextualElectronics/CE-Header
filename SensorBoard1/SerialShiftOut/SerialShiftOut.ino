#define CE_spi_cs_gpio3 10
#define CE_spi_mosi_gpio0 11
#define CE_spi_miso_gpio1 12
#define CE_spi_clk_gpio2 13
#define CE_usart_rx_gpio4 1
#define CE_usart_tx_gpio5 0
#define CE_i2c_sclk_gpio6 19
#define CE_i2c_sdat_gpio7 18
#define CE_aio0_gpio8 14
#define CE_aio1_gpio9 15
#define CE_aio2_gpio10 16
#define CE_aio3_gpio11 17

/*
  Shift Register Example
 for 74HC595 shift register

 This sketch turns reads serial input and uses it to set the pins
 of a 74HC595 shift register.

 Hardware:
 * 74HC595 shift register attached to pins 8, 12, and 11 of the Arduino,
 as detailed below.
 * LEDs attached to each of the outputs of the shift register.


 Created 22 May 2009
 Created 23 Mar 2010
 by Tom Igoe

 */

//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = CE_spi_cs_gpio3;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = CE_spi_clk_gpio2;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = CE_usart_rx_gpio4;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("reset");
}

void loop() {
  if (Serial.available() > 0) {
    // ASCII '0' through '9' characters are
    // represented by the values 48 through 57.
    // so if the user types a number from 0 through 9 in ASCII, 
    // you can subtract 48 to get the actual value:
    int bitToSet = Serial.read() - 48;

  // write to the shift register with the correct bit set high:
    registerWrite(bitToSet, HIGH);
  }
}

// This method sends bits to the shift register:

void registerWrite(int whichPin, int whichState) {
// the bits you want to send
  byte bitsToSend = 0;

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchPin, LOW);

  // turn on the next highest bit in bitsToSend:
  bitWrite(bitsToSend, whichPin, whichState);

  // shift the bits out:
  shiftOut(dataPin, clockPin, MSBFIRST, 0b00101100); 

    // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);

}
