#include <LiquidCrystal.h>
  lcd.clear();
  lcd.print("Sending SMS");

  gsm.println("AT");
  delay(1000);

  gsm.println("AT+CMGF=1");
  delay(1000);

  gsm.print("AT+CMGS=\"");

  for(int i=0; i<10; i++)
  {
    gsm.print(data[i]);
  }

  gsm.println("\"");

  delay(1000);

  switch(msgCode)
  {
    case 'A':
      gsm.print("EMERGENCY AT BLOCK 2");
      break;

    case 'B':
      gsm.print("ARE YOU SAFE? NEED ASSISTANCE");
      break;

    case 'C':
      gsm.print("ANY ACTIONS NEEDED?");
      break;

    case 'D':
      gsm.print("HOW CAN OTHERS REACH YOU?");
      break;

    case '1':
      gsm.print("ANY RELEVANT DETAILS?");
      break;

    case '2':
      gsm.print("WHAT ACTIONS SHOULD BE TAKEN?");
      break;

    case '3':
      gsm.print("FOLLOW EVACUATION ROUTES");
      break;

    case '4':
      gsm.print("STAY AWAY FROM REACTORS");
      break;

    case '5':
      gsm.print("GAS LEAKAGE NEAR REACTOR");
      break;

    default:
      gsm.print("UNKNOWN MESSAGE");
  }

  delay(500);

  gsm.write(26);

  lcd.setCursor(0,1);
  lcd.print("SMS SENT");

  Serial.println("SMS Sent");
}

void clearData()
{
  for(int i=0; i<12; i++)
  {
    data[i] = '\0';
  }

  cnt = 0;
}
