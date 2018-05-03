//parameters
typedef struct
{
  //arrary of ten
  char one[10];
  //an int pointer
  int *two;
  int three;
}
record_type;
record_type record[8];
char inByte = 0; //incoming serial byte

int num1= 125;
int num2= 120;
int num3= 135;
int num4= 145;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  record[0] = (record_type) {"ADC1", &num1,3};
  record[1] = (record_type) {"ADC2", &num2,6};
  record[2] = (record_type) {"ADC3", &num3,9};
  record[3] = (record_type) {"data", &num4,9};
  establishContact()//send a byte to establish contact until received
}


void loop() {
  // put your main code here, to run repeatedly
  if(Serial.available()>0)
  {
    inByte = Serial.read();
    if(inByte == 'A')
    {
      Serial.print(inByte);
      //Serial.print(",");
     for(int a = 0; a < 3; a++)
     {
      Serial.print(",");
      Serial.print(record[a].one);
      Serial.print(",");
      Serial.print(*(record[a].two));
      Serial.print(",");
      Serial.print(record[a].three);
      Serial.print(",");
     }
     Serial.println();
    }
    delay(2000);
  }
}

void establishContact() {
  while(Serial.available() <=0)
  {
    Serial.println("A");
    delay(1000);
  }
}

