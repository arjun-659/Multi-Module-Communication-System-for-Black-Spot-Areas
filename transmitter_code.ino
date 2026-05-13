#include <Keypad.h>

  clearData();
}

void loop()
{
  char key = keypad.getKey();

  if (key)
  {
    Serial.print("Pressed: ");
    Serial.println(key);

    // Clear data
    if (key == '*')
    {
      clearData();
    }

    // Send data
    else if (key == '#')
    {
      sendData();
    }

    // Store entered characters
    else
    {
      if (cnt < 11)
      {
        data[cnt] = key;

        lcd.setCursor(cnt,1);
        lcd.print(key);

        cnt++;
      }
    }
  }
}

void clearData()
{
  for(int i=0; i<12; i++)
  {
    data[i] = '\0';
  }

  cnt = 0;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ENTER DATA");
}

void sendData()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SENDING...");

  Serial.print("Sending: ");
  Serial.println(data);

  LoRa.beginPacket();
  LoRa.print(data);
  LoRa.endPacket();

  lcd.setCursor(0,1);
  lcd.print("DATA SENT");

  delay(2000);

  clearData();
}
