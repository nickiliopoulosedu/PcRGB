String incoming;
char incomingbyte = 0;
String temp = "";

//define pins for RGB values output
#define red 9
#define green 10
#define blue 11

//define loop variables to use them later inside loops
int i = 0;
int j = 0;

//define variables for mode selection
const int maxMode = 1; //if you add/remove a mode increase/decrease this value
int mode = 0; //By changing this value you change on which mode the controller will start

//define variables for RGB values
int rgb[] = {000, 000, 000};

//define variable for wheel animation
const int wheelDelay = 10;

void setup()
{
  //set analog pins 1-3 as inputs for the potentiometers
  for (i = 0; i < 3; i++);
  {
    pinMode("A" + i, INPUT);
  }

  //same for digital pins for RGB outputs
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(115200);
}
void loop()
{
  if(Serial.available() > 0)
  {
    valRead();
    if (((String)incoming.charAt(0)).toInt() != mode)
    {
      mode = ((String)incoming.charAt(0)).toInt();
      //signal for mode change
      for (int i = 0; i < 2; i++)
      {
        analogWrite(red, 255);
        analogWrite(green, 0);
        analogWrite(blue, 0);
        delay(500);
        analogWrite(red, 0);
        delay(500);
      }
    }
  }
  //go to selected mode
  if (mode == 0)
  {
    colorWheel();
  }

  else if (mode == 1)
  {
    manual();
  }
}

//loop through colors (rainbow effect)
void colorWheel()
{
  int rgb[] = {255, 000, 000};
  analogWrite(red, rgb[0]);
  analogWrite(green, rgb[1]);
  analogWrite(blue, rgb[2]);
  Serial.flush();
  for (/* no initialization */; rgb[0] >= 0, rgb[2] < 255; rgb[2]++, rgb[0]--) /*red -> blue*/
  {
    for (int j = 0; j < 3; j++)
    {
      if (rgb[j] < 0)
      {
        rgb[j] = 0;
      }
      else if (rgb[j] > 255)
      {
        rgb[j] = 255;
      }
    }
    
    //output RGB values
    analogWrite(red, rgb[0]);
    analogWrite(blue, rgb[2]);
    delay(wheelDelay);

    //test for mode button press
    if(Serial.available() > 0)
    {
      break;
    }
  }

  for (/* no initialization */; rgb[2] >= 0, rgb[1] < 255; rgb[1]++, rgb[2]--) /*blue -> green*/

  {
    for (int j = 0; j < 3; j++)
    {
      if (rgb[j] < 0)
      {
        rgb[j] = 0;
      }
      else if (rgb[j] > 255)
      {
        rgb[j] = 255;
      }
    }
    analogWrite(blue, rgb[2]);
    analogWrite(green, rgb[1]);
    delay(wheelDelay);
    if(Serial.available() > 0)
    {
      break;
    }
  }

  for (/* no initialization */; rgb[1] >= 0, rgb[0] < 255; rgb[0]++, rgb[1]--) /*green -> red*/

  {
    for (int j = 0; j < 3; j++)
    {
      if (rgb[j] < 0)
      {
        rgb[j] = 0;
      }
      else if (rgb[j] > 255)
      {
        rgb[j] = 255;
      }
    }
    analogWrite(red, rgb[0]);
    analogWrite(green, rgb[1]);
    delay(wheelDelay);
    if(Serial.available() > 0)
    {
      break;
    }
  }
}

//changes the color based on input
void manual()
{
  j = 2;
  for(int i = 0; i < 3; i++)
  {
    temp = "";
    while(1)
    {
      if(incoming.charAt(j) == 32)
      {
        j++;
        break;
      }
      temp = temp + ((String) incoming[j]);
      j++;
    }
    
    rgb[i] = temp.toInt();
  }
  //output RGB values
  analogWrite(red, rgb[0]);
  analogWrite(green, rgb[1]);
  analogWrite(blue, rgb[2]);
}

void valRead()
{
  incoming = "";
  while (1)
  {
    incomingbyte = Serial.read();
    if (incomingbyte == 10){ break; }
    incoming = incoming + (String) incomingbyte;
  }
  Serial.flush();
}
