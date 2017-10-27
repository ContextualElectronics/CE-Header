

#define CE_aio0_gpio8 14

void setup()
{                
  Serial.begin(38400);
}

int val;
double math;

void loop()                     
{
  val = analogRead(CE_aio0_gpio8);
  math = val * 0.003222;
  Serial.print("analog 0 is: ");
  Serial.println(math);
  delay(250);
}
