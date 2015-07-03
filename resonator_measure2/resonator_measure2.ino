
int buttonState = 0;
int foo = 0;
int numPoints = 100;
int delayTime = 3;
int initialTime = 0;
int changeState = 0;
int x1 = 0;
int x2 = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(2,INPUT);
}

void loop()
{
  int x[numPoints];
  int t[numPoints];
  int index =0;
  buttonState = digitalRead(2);
  x1 = analogRead(A3);
  delay(delayTime);
  x2 = analogRead(A3);
  if(abs(x2 - x1) > 3 || buttonState){
    initialTime = millis();
    for(index = 0;index < numPoints;index++){
       x[index] = analogRead(A3);
       t[index] = millis() - initialTime;
       delay(delayTime);
    }
    for(index = 0;index < numPoints;index++){
       Serial.print(x[index],DEC);
       Serial.print(", ");
    }

    Serial.println();
    
    int maxx = x[0];
    int minx = x[0];
    for(index = 0;index < numPoints;index++){
       if(x[index] > maxx){
         maxx = x[index];
       }
       if(x[index] < minx){
         minx = x[index];
       }
    }   
    int midpoint = (maxx + minx)/2;
    Serial.print("max = ");
    Serial.print(maxx,DEC); 
    Serial.println();
    Serial.print("min = ");
    Serial.print(minx,DEC); 
    Serial.println();
    Serial.print("midpoint = ");
    Serial.print(midpoint,DEC); 
    Serial.println();
    
    
  }  

}
