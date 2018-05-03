void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int myArrary[10];

  fillArrary(myArrary, 10);

  for(int i = 0; i < 10; i++)
  {
    Serial.println(myArrary[i]);
  }
  delay(1000);
}

void fillArrary(int theArrary[], int n)
{
  for(int i = 0; i < n; i++)
  {
    theArrary[i] = 10 * i;
  }
}

