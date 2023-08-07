int incoming_data{0};

void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  while(!Serial);
}

void loop()
{
  while(Serial.available())
  {
    incoming_data = Serial.read();
    if (incoming_data == '1')
    {
      digitalWrite(6, HIGH);
    }
    if (incoming_data == '0')
    {
      digitalWrite(6, LOW);
    }

  }
}
