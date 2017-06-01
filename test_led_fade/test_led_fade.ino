void setup() {
  // put your setup code here, to run once:
pinMode(A0,OUTPUT);
}

void loop() {
  int i,b;
  digitalWrite(A1,HIGH);
  for(i=1;i<10;i+=1)

  {
    if(i>8)
    {
    for(b=1;b<20;b++)
   {
    digitalWrite(A0,HIGH);
    delay(20-i);
    digitalWrite(A0,LOW);
    delay(i);
   }
    }
    else
    {
       for(b=1;b<30;b++)
   {
    digitalWrite(A0,HIGH);
    delay(20-i);
    digitalWrite(A0,LOW);
    delay(i);
   }
    }
    
  }
  // put your main code here, to run repeatedly:

}
