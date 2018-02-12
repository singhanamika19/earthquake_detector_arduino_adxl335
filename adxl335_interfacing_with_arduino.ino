//First of all, we calibrate the accelerometer with respect to its placing surface, so that it will not show alerts with respect to its normal surrounding vibrations. In this calibration, we take some samples and then take an average of them and stores in a variable.//
int samples=5;
  for(int i=0;i<samples;i++)      // taking samples for calibration
  {
    xsample+=analogRead(x);
    ysample+=analogRead(y);
    zsample+=analogRead(z);
  }

  xsample/=samples;   // taking avg for x
  ysample/=samples;   // taking avg for y
  zsample/=samples;   // taking avg for z
  
  delay(3000);
  lcd.clear();
  lcd.print("Calibrated");
  delay(1000);
  lcd.clear();
  lcd.print("Device Ready");
  delay(1000);
  lcd.clear();
  lcd.print(" X     Y     Z   ");
 

//Now whenever Accelerometer takes readings, we will subtract those sample values from the readings so that it can ignore surroundings vibrations.//

    int value1=analogRead(x);   // reading x out
    int value2=analogRead(y);   //reading y out
    int value3=analogRead(z);   //reading z out

    int xValue=xsample-value1;    // finding change in x
    int yValue=ysample-value2;    // finding change in y
    int zValue=zsample-value3;    // finding change in z

  /*displying change in x,y and z axis values over lcd*/
    lcd.setCursor(0,1);
    lcd.print(zValue);
    lcd.setCursor(6,1);
    lcd.print(yValue);
    lcd.setCursor(12,1);
    lcd.print(zValue);
    delay(100)
 

Then Arduino compares those calibrated (subtracted) values with predefined limits. And take action accordingly. If the values are higher than predefined values then it will beep the buzzer and plot the vibration graph on computer using Processing.

      /* comparing change with predefined limits*/
    if(xValue < minVal || xValue > maxVal  || yValue < minVal || yValue > maxVal  || zValue < minVal || zValue > maxVal)
    { 
      if(buz == 0)
      start=millis();   // timer start
       buz=1;       // buzzer / led flag activated
    } 

   else if(buz == 1)        // buzzer flag activated then alerting earthquake
   {
      lcd.setCursor(0,0);
      lcd.print("Earthquake Alert   ");
      if(millis()>= start+buzTime)    
      buz=0;
   }
