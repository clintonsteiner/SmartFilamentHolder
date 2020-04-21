# SmartFilamentHolder
smart filament holder programming

# Variables  
  # EEPROM Locations
  0 calibrationFactor
  4 calibrationOffset
  
  8 spool1Weight
  10 spool1Color
  20 spool1Filament
  
  spool 2  
  30
  32
  42
  
  spool3  
  52
  54
  64
  
  spool 4  
  66
  68
  78
  
  spool5  
  88
  90
  100

# Functions
OLED:  
  void displayActiveMenu(int currentMenu) controls which menu is displayed, also handles arrow styling
  

Rotary Encoder:  
  void encoderClick() called on interrupt, advances through menus via incrementing currentMenu  
  void menuIncrement() called on interrupt, advances currentMenuOption  
  
  void encoderRotateInterrupt() implements debounce into encoder programming
  void encoderClickInterrupt() implements debounce

# Pin overview

Rotary Encoder:
  pinA = 2  
  pinB = 4  
  encoder SW = 3  

Oled:  
  0x3C, or A4(SCL), A5(SDA)
  
Load Cell: 
  DOUT = 10  
  SCK = 11  
