//define pins for RGB values output and button
#define red 9
#define green 10
#define blue 11
#define button 7

//define loop variables to use them later inside loops
int i = 0;
int j = 0;

//define variables for mode selection
int mode = 0; //By changing this value you change on which mode the controller will start

//define variables for wheel and breath animations
const float breathPercentage = 0.98; //percentage to increase/decrease breathing smoothness
const int wheelDelay = 10;
const int breathDelay = 50;

int rgb[] = {000, 000, 000};

void setup()
{
  //same for digital pins for RGB outputs and button
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}
void loop()
{
  //go to selected mode
  if (mode == 0)
  {
    breath();
  }
  else if (mode == 1)
  {
    colorWheel();
  }
}

//loop through colors (rainbow effect)
void colorWheel()
{
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
    if (digitalRead(button) == LOW)
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
    if (digitalRead(button) == LOW)
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
    if (digitalRead(button) == LOW)
    {
      break;
    }
  }
}

void breath()
{
  int rgb[] = {255, 255, 255}; //define breath color
  analogWrite(red, rgb[0]);
  analogWrite(green, rgb[1]);
  analogWrite(blue, rgb[2]);

  //save rgb values for later use
  int beforeRGB[] = {rgb[0], rgb[1], rgb[2]};
  int previousRGB[] = {0, 0, 0};
  //dim down
  while (rgb[0] > 0 || rgb[1] > 0 || rgb[2] > 0)
  {
    for (int j = 0; j < 3; j++)
    {
      // test for button press
      if (digitalRead(button) == LOW)
      {
        break;
      }

      //change RGB values and correct any mistakes
      if (rgb[j] > 0)
      {
        rgb[j] = round(rgb[j] * 0.9);
        if (rgb[j] == previousRGB[j])
        {
          rgb[j]--;
        }
        previousRGB[j] = rgb[j];
      }
      else
      {
        rgb[j] = 0;
      }

      if (rgb[j] < 0)
      {
        rgb[j] = 0;
      }
      else if (rgb[j] > 255)
      {
        rgb[j] = 255;
      }
    }

    //write new RGB values
    analogWrite(red, rgb[0]);
    analogWrite(green, rgb[1]);
    analogWrite(blue, rgb[2]);

    //test for button press
    if (digitalRead(button) == LOW)
    {
      break;
    }
    delay(breathDelay);
  }
  delay(150);

  previousRGB[0] = -1;
  previousRGB[1] = -1;
  previousRGB[2] = -2;
  
  // dim up
  while (rgb[0] < beforeRGB[0] || rgb[1] < beforeRGB[1] || rgb[2] < beforeRGB[2])
  {
    for (int j = 0; j < 3; j++)
    {
      //test for button press
      if (digitalRead(button) == LOW)
      {
        break;
      }

      //change RGB values and correct any mistakes
      if (beforeRGB[j] != 0 && rgb[j] < beforeRGB[j] && rgb[j] < 255)
      {
        rgb[j] = round((rgb[j] * 1.1) + 0.3);
        if (rgb[j] == previousRGB[j])
        {
          rgb[j]++;
        }

        previousRGB[j] = rgb[j];
      }
      else
      {
        rgb[j] = beforeRGB[j];
      }
      if (rgb[j] < 0)
      {
        rgb[j] = 0;
      }
      else if (rgb[j] > 255)
      {
        rgb[j] = 255;
      }
    }
    
    //output new RGB values
    analogWrite(red, rgb[0]);
    analogWrite(green, rgb[1]);
    analogWrite(blue, rgb[2]);

    //test for button press
    if (digitalRead(button) == LOW)
    {
      break;
    }
    delay(breathDelay);
  }
  delay(1500);
}
