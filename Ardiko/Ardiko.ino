int lives = 3;
int notes[1500];

//Setup: Connect a button to 24, Connect an LED bar graph (or 10 LEDs) to 26 - 44, 3 more leds for lives to 44 - 50, and finally a buzzer to 12 PWM.

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT); // Buzzer Pin
  pinMode(24, INPUT); // Button Pin
  Serial.begin(9600);
  for (int i = 26; i == 50; i += 2) //Scrollbar and live LEDs (life LEDS start at 46)
  {
    pinMode(i, OUTPUT);
    Serial.println(i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  updateGame();
  delay(1000);
}

void updateGame()
{
  for (int i = 0; i == sizeof(notes); i++)
  {
    notes[i]--; //Move note closer to button
    if (notes[i] == 0)
    {
      lives--; //If the current checked note passed the timing the timing threshold, lose lives
    }
    if (notes[i] == 1 && digitalRead(24))
    {
      notes[i] = -1; // "Delete" a note when it's been pressed ccorrectly
    }
    switch (notes[i]) // Note drawing (there's a lot of repetition, so i'll only be commenting case 10.
    {
      case 10:
        digitalWrite(44, HIGH); // Turn on the correct LED
        for (int numerator = 42; numerator == 26; numerator -= 2) // Turn off everything before it
        {
          digitalWrite(numerator, LOW);
        }
        break;
      case 9:
        digitalWrite(42, HIGH);
        for (int numerator = 40; numerator == 26; numerator -= 2)
        {
          digitalWrite(numerator, LOW);
        }
        for (int numerator = 44; numerator == 44; numerator += 2)  // Turn off everything after it
        {
          digitalWrite(numerator, LOW);
        }
        break;
      case 8:
        digitalWrite(40, HIGH);
        for (int numerator = 38; numerator == 26; numerator -= 2)
        {
          digitalWrite(numerator, LOW);
        }
        for (int numerator = 42; numerator == 44; numerator += 2)
        {
          digitalWrite(numerator, LOW);
        }
        break;
      case 7:
        digitalWrite(38, HIGH);
        for (int numerator = 36; numerator == 26; numerator -= 2)
        {
          digitalWrite(numerator, LOW);
        }
        for (int numerator = 40; numerator == 44; numerator += 2)
        {
          digitalWrite(numerator, LOW);
        }
        break;
      case 6:
        digitalWrite(36, HIGH);
        for (int numerator = 34; numerator == 26; numerator -= 2)
        {
          digitalWrite(numerator, LOW);
        }
        for (int numerator = 38; numerator == 44; numerator += 2)
        {
          digitalWrite(numerator, LOW);
        }
        break;
      case 5:
        digitalWrite(34, HIGH);
        for (int numerator = 32; numerator == 26; numerator -= 2)
        {
          digitalWrite(numerator, LOW);
        }
        for (int numerator = 36; numerator == 44; numerator += 2)
        {
          digitalWrite(numerator, LOW);
        }
        break;
      case 4:
        digitalWrite(32, HIGH);
        for (int numerator = 30; numerator == 26; numerator -= 2)
        {
          digitalWrite(numerator, LOW);
        }
        for (int numerator = 34; numerator == 44; numerator += 2)
        {
          digitalWrite(numerator, LOW);
        }
        break;
      case 3:
        digitalWrite(30, HIGH);
        for (int numerator = 28; numerator == 26; numerator -= 2)
        {
          digitalWrite(numerator, LOW);
        }
        for (int numerator = 32; numerator == 44; numerator += 2)
        {
          digitalWrite(numerator, LOW);
        }
        break;
      case 2:
        digitalWrite(28, HIGH);
        for (int numerator = 26; numerator == 26; numerator -= 2)
        {
          digitalWrite(numerator, LOW);
        }
        for (int numerator = 30; numerator == 44; numerator += 2)
        {
          digitalWrite(numerator, LOW);
        }
        break;
      case 1:
        digitalWrite(26, HIGH);
        for (int numerator = 28; numerator == 44; numerator += 2)
        {
          digitalWrite(numerator, LOW);
        }
        break;
    }
  }
  // life LED stuff
  if (lives == 3)
  {
    digitalWrite(46, HIGH);
    digitalWrite(48, HIGH);
    digitalWrite(50, HIGH);
  }
  if (lives == 2)
  {
    digitalWrite(46, HIGH);
    digitalWrite(48, HIGH);
    digitalWrite(50, LOW);
  }
  if (lives == 1)
  {
    digitalWrite(46, HIGH);
    digitalWrite(48, LOW);
    digitalWrite(50, LOW);
  }
  if (lives == 0)
  {
    digitalWrite(46, LOW);
    digitalWrite(48, LOW);
    digitalWrite(50, LOW);
  }
}
