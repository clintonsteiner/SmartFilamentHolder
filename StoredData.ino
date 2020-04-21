#include <avr/pgmspace.h>

const char string_0[] PROGMEM = "Mid-Kansas";
const char string_1[] PROGMEM = "Innovations";
const char string_2[] PROGMEM = "Team 13";
const char string_3[] PROGMEM = "Instructions";
//////////////////////////////////////////////////////////////////////////////
const char string_4[] PROGMEM = "- turn to scroll";
const char string_5[] PROGMEM = "- push in to select";
const char string_6[] PROGMEM = "1st Boot?";
const char string_7[] PROGMEM = "- calibrate b4 use";
const char string_8[] PROGMEM = "% Push for Menu %";
//////////////////////////////////////////////////////////////////////////////
const char string_9[] PROGMEM = "Main Menu";
const char string_10[] PROGMEM = "Spool Weight";
const char string_11[] PROGMEM = "Manage Spools";
const char string_12[] PROGMEM = "Recalibrate";
const char string_13[] PROGMEM = "Instructions";
const char string_14[] PROGMEM = "Run Diagnostics";
const char string_15[] PROGMEM = "Contact Us";
//////////////////////////////////////////////////////////////////////////////
const char string_16[] PROGMEM = "Filament Remaining";
const char string_17[] PROGMEM = "1000 grams";
const char string_18[] PROGMEM = "Change Spool";
const char string_19[] PROGMEM = "Exit";
//////////////////////////////////////////////////////////////////////////////
const char string_20[] PROGMEM = "Spool Selection";
const char string_21[] PROGMEM = "Spool 1";
const char string_22[] PROGMEM = "Spool 2";
const char string_23[] PROGMEM = "Spool 3";
const char string_24[] PROGMEM = "Spool 4";
const char string_25[] PROGMEM = "Spool 5";
const char string_26[] PROGMEM = "Exit";
//////////////////////////////////////////////////////////////////////////////
const char string_27[] PROGMEM = "Calibration";
const char string_28[] PROGMEM = "Weight :";
const char string_29[] PROGMEM = " 987 grams";
const char string_30[] PROGMEM = "Calib #: ";
const char string_31[] PROGMEM = "1234";
const char string_32[] PROGMEM = "Recalibrate";
const char string_33[] PROGMEM = "Exit";
//////////////////////////////////////////////////////////////////////////////
const char string_34[] PROGMEM = "Run Diagnostics";
const char string_35[] PROGMEM = "Test: RotEnc.";
const char string_36[] PROGMEM = "Test: HX711";
const char string_37[] PROGMEM = "Exit";
//////////////////////////////////////////////////////////////////////////////
const char string_38[] PROGMEM = "Contact Us";
const char string_39[] PROGMEM = "ME574 - Team 13";
const char string_40[] PROGMEM = "K-State - Spring 2020";
const char string_41[] PROGMEM = "Clinton S., Vibhav V.,";
const char string_42[] PROGMEM = "Wesley M., Cade M.,";
const char string_43[] PROGMEM = "Tyler G.";
const char string_44[] PROGMEM = "Exit";
//////////////////////////////////////////////////////////////////////////////
const char string_45[] PROGMEM = "Spool 1";
const char string_46[] PROGMEM = "Color: ";
const char string_47[] PROGMEM = "Red";
const char string_48[] PROGMEM = "Mass: ";
const char string_49[] PROGMEM = "1000 grams";
const char string_50[] PROGMEM = "Change Color";
const char string_51[] PROGMEM = "Adjust Weight";
const char string_52[] PROGMEM = "Exit";
const char string_53[] PROGMEM = "Spool 2";
const char string_54[] PROGMEM = "Spool 3";
const char string_55[] PROGMEM = "Spool 4";
const char string_56[] PROGMEM = "Spool 5";
//////////////////////////////////////////////////////////////////////////////
const char string_57[] PROGMEM = "Change Spool";
const char string_58[] PROGMEM = "Spool 1";
const char string_59[] PROGMEM = "Spool 2";
const char string_60[] PROGMEM = "Spool 3";
const char string_61[] PROGMEM = "Spool 4";
const char string_62[] PROGMEM = "Spool 5";
//////////////////////////////////////////////////////////////////////////////
const char string_63[] PROGMEM = "Recalibrate";
const char string_64[] PROGMEM = "Weight : ";
const char string_65[] PROGMEM = "Calib #: ";
const char string_66[] PROGMEM = "Adjust Calib #";
const char string_67[] PROGMEM = "Zero Scale";
const char string_68[] PROGMEM = "Exit";


const char *const stringTable[] PROGMEM = {string_0, string_1, string_2, string_3, string_4, string_5, string_6, string_7, string_8, string_9, string_10, string_11, string_12
, string_13, string_14, string_15, string_16, string_17, string_18, string_19, string_20, string_21, string_22, string_23, string_24, string_25, string_26, string_27, string_28
, string_29, string_30, string_31, string_32, string_33, string_34, string_35, string_36, string_37, string_38, string_39, string_40, string_41, string_42, string_43, string_44, string_45, string_46, string_47, string_48
, string_49, string_50, string_51, string_52, string_53, string_54, string_55, string_56, string_57, string_58, string_59, string_60, string_61, string_62, string_63, string_64, string_65, string_66, string_67, string_68
};
const byte *const stringXAxisLocations[] PROGMEM = {34,31,43,28,7,7,37,7,13,37,12,12,12,12,12,12,10,32,12,12,19,12,12,12,12,12,12,31,12,64,12,66,12,12,19,12,12,12,34,19,1,0,7,40,52,43,12,52,12,52,12,12,12,43,43,43,43,28,12,12,12,12,12,31,12,12,12,12,12};
const byte *const stringYAxisLocations[] PROGMEM = {2,4,6,0,2,3,4,5,7,0,2,3,4,5,6,7,0,2,6,7,0,2,3,4,5,6,7,0,3,3,4,4,6,7,0,3,4,5,0,2,3,4,5,6,7,0,2,2,3,3,4,5,6,0,0,0,0,0,2,3,4,5,6,0,2,3,4,5,6};

byte byteBuffer;
char stringBuffer[30];  // make sure this is large enough for the largest string it must hold

void loopForMenus(int startingMenuNumber, int numMenuLines, int specialFlag=0)
{
  int j;

  for(int i = startingMenuNumber; i< numMenuLines; i++)
  {
    if(i==startingMenuNumber) oled.setFont(Callibri15);
    else oled.setFont(System5x7);


    if((specialFlag > 2)&&(i==startingMenuNumber)) {
      j = specialFlag;
      specialFlag=0;
    }
    else{
      j = i;}


    oled.setCursor(pgm_read_byte_near(stringXAxisLocations+j), pgm_read_byte_near(stringYAxisLocations+j));
    oled.print(strcpy_P(stringBuffer, (char *)pgm_read_word(&(stringTable[j]))));
  }
}
void displayRecalibrateProcedure()
{
  loopForMenus(63,69);
}
void displayChangeSpool()
{
  loopForMenus(57,63);
}
void displaySpool(int spoolNum)
{
  if(spoolNum ==1) loopForMenus(45,53);
  else loopForMenus(45,53,spoolNum+51);
}


void displayContactUs() {loopForMenus(38,45);}
void displayDiagnosticsMenu(){loopForMenus(34,38);}
void displayCalibrationMenu(){loopForMenus(27,34);}
void displaySpoolManagement()
{
  loopForMenus(20,27);
}
void displayFilamentRemaining(int weightRemaining)
{
  oled.setFont(Callibri15);
  //loopForMenus(16,20,1);
  for(int i = 16;i<20;i++)
  {
    if(i==18) oled.setFont(System5x7);
    oled.setCursor(pgm_read_byte_near(stringXAxisLocations+i), pgm_read_byte_near(stringYAxisLocations+i));
    if(i==17) oled.print(weightRemaining);
    else oled.print(strcpy_P(stringBuffer, (char *)pgm_read_word(&(stringTable[i]))));
  }
}
void displayMainMenu()
{
  loopForMenus(9,16);
}

void displayInstructionsMenu()
{
  loopForMenus(3,9);
}

void displayCreditsIntroMenu()
{
  loopForMenus(0,3);
}





//////////////////////////////////////////////////////////////////////////////
//EEPROM
const char color_0[] PROGMEM = "White";
const char color_1[] PROGMEM = "Black";
const char color_2[] PROGMEM = "Blue";
const char color_3[] PROGMEM = "Red";
const char color_4[] PROGMEM = "Clear";
const char color_5[] PROGMEM = "Green";
const char color_6[] PROGMEM = "Grey";
const char color_7[] PROGMEM = "Orange";
const char color_8[] PROGMEM = "Yellow";
const char color_9[] PROGMEM = "Silver";
const char color_10[] PROGMEM = "Gold";
const char color_11[] PROGMEM = "Purple";
const char color_12[] PROGMEM = "Pink";
const char color_13[] PROGMEM = "Brown";
///////////////////////////////////////////
const char filament_1[] PROGMEM = "ABS";
const char filament_2[] PROGMEM = "PLA";
const char filament_3[] PROGMEM = "PVA";
const char filament_4[] PROGMEM = "PET";
const char filament_5[] PROGMEM = "PETG";
const char filament_6[] PROGMEM = "PETT";
const char filament_7[] PROGMEM = "HIPS";
const char filament_8[] PROGMEM = "Nylon";
const char filament_9[] PROGMEM = "Wood";
const char filament_10[] PROGMEM = "Sandstone";
const char filament_11[] PROGMEM = "Metal";
const char filament_12[] PROGMEM = "IronPLA";
const char filament_13[] PROGMEM = "Cond.PLA";
const char filament_14[] PROGMEM = "CarbFiber";
const char filament_15[] PROGMEM = "TPE";
const char filament_16[] PROGMEM = "GlowInDark";
const char filament_17[] PROGMEM = "Amphora";


const char *const filamentTable[] PROGMEM = {filament_1, filament_2, filament_3, filament_4, filament_5, filament_6, filament_7, filament_8, filament_9, filament_10, filament_11, filament_12, filament_13, filament_14, filament_15, filament_16, filament_17};
const char *const colorTable[] PROGMEM = {color_0,color_1,color_2,color_3,color_4,color_5,color_6,color_7,color_8,color_9,color_10,color_11,color_12,color_13};
int activeSpool = 0;
void setActiveSpool(int i){
  activeSpool = i;
}

float calibrationFactor = 543;
float calibrationOffset = 64135;

int spool1Weight = 6969;
int spool2Weight = 768;
int spool3Weight = 843;
int spool4Weight = 234;
int spool5Weight = 1000;

char spool1Color[10] = "N/A";
char spool2Color[10]= "N/A";
char spool3Color[10]= "N/A";
char spool4Color[10]= "N/A";
char spool5Color[10]= "N/A";

char spool1Filament[10]= "N/A";
char spool2Filament[10]= "N/A";
char spool3Filament[10]= "N/A";
char spool4Filament[10]= "N/A";
char spool5Filament[10]= "N/A";

float getCalibrationFactor(){return calibrationFactor;}
float getCalibrationOffset(){return calibrationOffset;}

void EEPROMBeginningPull()
{
  if(calibrationFactor != EEPROM.read(0)) EEPROM.get(0, calibrationFactor);
  if(calibrationFactor != EEPROM.read(4)) EEPROM.get(4, calibrationOffset);

  if(calibrationFactor != EEPROM.read(8)) EEPROM.get(8, spool1Weight);
  if(calibrationFactor != EEPROM.read(10)) EEPROM.get(10, spool1Color);
  if(calibrationFactor != EEPROM.read(20)) EEPROM.get(20, spool1Filament);

  if(calibrationFactor != EEPROM.read(30)) EEPROM.get(30, spool2Weight);
  if(calibrationFactor != EEPROM.read(32)) EEPROM.get(32, spool2Color);
  if(calibrationFactor != EEPROM.read(42)) EEPROM.get(42, spool2Filament);

  if(calibrationFactor != EEPROM.read(52)) EEPROM.get(52, spool3Weight);
  if(calibrationFactor != EEPROM.read(54)) EEPROM.get(54, spool3Color);
  if(calibrationFactor != EEPROM.read(64)) EEPROM.get(64, spool3Filament);

  if(calibrationFactor != EEPROM.read(66)) EEPROM.get(66, spool4Weight);
  if(calibrationFactor != EEPROM.read(68)) EEPROM.get(68, spool4Color);
  if(calibrationFactor != EEPROM.read(78)) EEPROM.get(78, spool4Filament);

  if(calibrationFactor != EEPROM.read(88)) EEPROM.get(88, spool5Weight);
  if(calibrationFactor != EEPROM.read(90)) EEPROM.get(90, spool5Color);
  if(calibrationFactor != EEPROM.read(100)) EEPROM.get(100, spool5Filament);

}

void EEPROMPut(int selection)
{

  if(selection == 0)
  {
  EEPROM.put(0, calibrationFactor);
  EEPROM.put(4, calibrationOffset);
  }

  else if(selection == 1)
  {
    EEPROM.put(8, spool1Weight); ;
    EEPROM.put(10, spool1Color);
    EEPROM.put(20, spool1Filament);
  }

  else if(selection ==2)
  {
    EEPROM.put(30, spool2Weight);
    EEPROM.put(32, spool2Color);
    EEPROM.put(42, spool2Filament);
  }

  else if(selection ==3)
  {
    EEPROM.put(52, spool3Weight);
    EEPROM.put(54, spool3Color);
    EEPROM.put(64, spool3Filament);
  }

  else if(selection == 4)
  {
    EEPROM.put(66, spool4Weight);
    EEPROM.put(68, spool4Color);
    EEPROM.put(78, spool4Filament);
  }

  else if(selection ==5)
  {
    EEPROM.put(88, spool5Weight);
    EEPROM.put(90, spool5Color);
    EEPROM.put(100, spool5Filament);
  }

}

void EEPROMRetrieve()
{


}
