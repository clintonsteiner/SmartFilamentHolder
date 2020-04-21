#include <SPI.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
#include <EEPROM.h>
#include "HX711.h"

//rotary encoder definitions
const byte pinA = 2;
const byte pinB = 4;
const byte encoderSW = 3;

//loadcell definitions
#define LOADCELL_DOUT_PIN 10
#define LOADCELL_SCK_PIN  11

HX711 scale;

//oled definitions
SSD1306AsciiAvrI2c oled;

int currentMenu = 0;
int currentMenuOption = 0;

int maxMenuOption;
int arrowOffsetFromTop = 7;

void setup()
{
Serial.begin(9600);
while(!Serial);

oledSetup();
//EEPROMBegin();
//EEPROMRetrieve();
rotaryEncoderSetup();
scaleSetup();

}
void loop()
{
  Serial.println(scale.get_units(5),1);
}

//////////////////////////////////////////////////////////////////////////////
//Display Controllers
void displayActiveMenu(int currentMenu = currentMenu)
{
  if(currentMenu == 0)
  {
    maxMenuOption = 0;
    arrowOffsetFromTop = 7;
    displayInstructionsMenu();
  }
  else if(currentMenu == 1)
  {
    maxMenuOption = 5;
    arrowOffsetFromTop = 2;
    displayMainMenu();
  }
  else if(currentMenu ==2)
  {
    maxMenuOption = 1;
    arrowOffsetFromTop = 6;
    displayFilamentRemaining(696);
  }
  else if(currentMenu ==3)
  {
    maxMenuOption = 5;
    arrowOffsetFromTop = 2;
    displaySpoolManagement();
  }
  else if(currentMenu ==4)
  {
    maxMenuOption = 1;
    arrowOffsetFromTop = 6;
    displayCalibrationMenu();
  }
  else if(currentMenu ==5)
  {
    maxMenuOption = 2;
    arrowOffsetFromTop = 3;
    displayDiagnosticsMenu();
  }
  else if(currentMenu ==6)
  {
    maxMenuOption = 0;
    arrowOffsetFromTop = 7;
    displayContactUs();
  }
  else if((currentMenu >= 7)&&(currentMenu <= 11))
  {
    maxMenuOption = 2;
    arrowOffsetFromTop = 4;
    displaySpool(currentMenu -6);
  }

  else if(currentMenu == 12)
  {
    maxMenuOption = 4;
    arrowOffsetFromTop = 2;
    displayChangeSpool();
  }
  else if(currentMenu == 13)
  {
    maxMenuOption = 2;
    arrowOffsetFromTop = 4;
    displayRecalibrateProcedure();
  }
}

void encoderClick()
{
  oled.clear();
  if(currentMenu == 0) //intro instructions
  {
    currentMenu = 1; //goto main menu
  }

  else if(currentMenu == 1) //main menu
  //spool weight, manage spools, recalib, instructions, diagnostics, contact us
  {
    if(currentMenuOption == 3) currentMenu = 0;
    else if(currentMenuOption == 4) currentMenu = 5;
    else if(currentMenuOption == 5) currentMenu = 6;
    else currentMenu = currentMenuOption+2;
  }
  else if(currentMenu == 2) //filament remaining
  //change spool or exit
    {
        if(currentMenuOption == 0)
        {
          currentMenu = 12; //change spool

        }
        else
        {
          currentMenu = 1; //main menu

        }
    }
  else if(currentMenu == 3) //spool mgmt
  {
      if(currentMenuOption ==5) currentMenu = 1; //main menu
      else currentMenu = currentMenuOption+7;

  }
  else if(currentMenu == 4) //calibration
  //recalib exit
    {
        if(currentMenuOption ==0)
        {
          currentMenu = 13; //goto recalib

        }
        else
        {
          currentMenu = 1; //main menu

        }
    }

  else if(currentMenu == 5) //diagnostics
    {
      if(currentMenuOption == 0)
      {
        //testRotaryEncoder();
      }
      else if(currentMenuOption == 1)
      {
        //testHX711();
      }
      else currentMenu = 1;
    }
    else if(currentMenu == 6) //contact us
    {
      currentMenu = 1;
    }
    else if(currentMenu == 7)
    {
      if(currentMenuOption==0) Serial.println("Change Color");
      else if(currentMenuOption==1)Serial.println("Adjust Weight");
      else currentMenu = 1;
    }
    else if(currentMenu == 8)
    {
      if(currentMenuOption==0) Serial.println("Change Color");
      else if(currentMenuOption==1)Serial.println("Adjust Weight");
      else currentMenu = 1;
    }
    else if(currentMenu == 9)
    {
      if(currentMenuOption==0) Serial.println("Change Color");
      else if(currentMenuOption==1)Serial.println("Adjust Weight");
      else currentMenu = 1;
    }
    else if(currentMenu == 10)
    {
      if(currentMenuOption==0) Serial.println("Change Color");
      else if(currentMenuOption==1)Serial.println("Adjust Weight");
      else currentMenu = 1;
    }
    else if(currentMenu == 11)
    {
      if(currentMenuOption==0) Serial.println("Change Color");
      else if(currentMenuOption==1)Serial.println("Adjust Weight");
      else currentMenu = 1;
    }
    else if(currentMenu == 12)
    {
      if(currentMenuOption ==0) Serial.println("Spool 1");
      else if(currentMenuOption==1)Serial.println("Spool 2");
      else if(currentMenuOption==2)Serial.println("Spool 3");
      else if(currentMenuOption==3)Serial.println("Spool 4");
      else if(currentMenuOption==4)Serial.println("Spool 5");
      currentMenu = 2;
    }
    else if(currentMenu == 13)
    {
      if(currentMenuOption ==0) Serial.println("Adjust calib #");
      else if(currentMenuOption ==0) Serial.println("zero scale");
      else currentMenu = 1;
    }
  currentMenuOption = 0;
  displayActiveMenu(currentMenu);


}

void menuIncrement(byte a)
{
  if(a==0)
  {
    //Serial.println("Increment down");
    if(currentMenuOption == maxMenuOption) currentMenuOption = 0;
    else currentMenuOption++;

  }
  else
  {
    //Serial.println("Increment up");

    if(currentMenuOption == 0) currentMenuOption = maxMenuOption;
    else currentMenuOption--;
  }
  Serial.println(currentMenuOption);
  oled.clear();
  oled.setCursor(0,arrowOffsetFromTop+currentMenuOption);
  oled.print("->");
  displayActiveMenu();
}

//////////////////////////////////////////////////////////////////////////////
//Encoder Functions
void encoderRotateInterrupt()
{
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if(interruptTime - lastInterruptTime > 5)
  {
    if(digitalRead(pinB)==LOW) menuIncrement(0);
    else menuIncrement(1);
  }
  lastInterruptTime = interruptTime;
}

void encoderClickInterrupt()
{
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();

  if(interruptTime - lastInterruptTime > 10)
  {
  Serial.println("Encoder Clicked");
  encoderClick();
  delay(50);
  }
  lastInterruptTime = interruptTime;
}

//////////////////////////////////////////////////////////////////////////////
//Setup Functions
void rotaryEncoderSetup()
{
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  pinMode(encoderSW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinA), encoderRotateInterrupt, LOW);
  attachInterrupt(digitalPinToInterrupt(encoderSW), encoderClickInterrupt, LOW);
}
void scaleSetup()
{
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(getCalibrationFactor());
  scale.set_offset(getCalibrationOffset());
}
void oledSetup()
{
  oled.begin(&Adafruit128x64, 0x3C);
  oled.setFont(Adafruit5x7);
  oled.clear();
  displayCreditsIntroMenu();
  delay(1000);
  oled.clear();
  displayInstructionsMenu();
  delay(3000);
}
