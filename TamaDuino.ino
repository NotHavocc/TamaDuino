/* 
TamaDuino by NotHavoc (carbonfoxx)
This project used an Dasduino Core (spinoff nano), although you can use most boards.
Project uses 67% of Dasduinos'(nano's) memory (max is 30720 bytes). So this project requires a board
with atleast 2000bytes of storage.
I reccomend an 128x64 display for better viewability, although 128x32 is supported.

Passive Piezo = Pin 6
Button 1 = Pin 2
Button 2 = Pin 3
Button 3 = Pin 4
OLED SCL = A5(Search I2C pins of your board if youre not using a nano or an uno)
OLED SDA = A4
*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // OLED Setup

// 'Untitled', 128x64px
const unsigned char epd_bitmap_Untitled[] PROGMEM = { // Bitmap of egg
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc1, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc1, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x39, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x38, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x38, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x70, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const int button1 = 3; // Button
const int button2 = 2; // Pins
const int button3 = 4; // 
int inMenu = 0; // other variables
int hunger = 100; //
int happiness = 100; //
int energy = 100; //
int prestate = 0; //
int countValue = 0; //
int mealCountValue = 0; //
int age = 0; //
int gamestate = 1; //
int toggleanim = 0; //
int mealCooldown; //
String pet = "(0v0)"; // pet face (if you want change)
const unsigned long happinessInterval = 45000; // millis functions
const unsigned long hungerInterval = 35000; //
const unsigned long energyInterval = 60000; //
const unsigned long ageInterval = 60000; //
const unsigned long mealcdInterval = 25000; //
const unsigned long animInterval = 1000; //
const unsigned long blinkInterval = 100; //
unsigned long huprevTime = 0; //
unsigned long haprevTime = 0; //
unsigned long enprevTime = 0; //
unsigned long ageprevTime = 0; //
unsigned long mcdprevTime = 0; //
unsigned long animprevTime = 0; //
unsigned long blprevTime = 0; //
const int buzzer = 6;

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1040)
const int epd_bitmap_allArray_LEN = 1;
const unsigned char* epd_bitmap_allArray[1] = {
  epd_bitmap_Untitled
}; // bitmap


void setup() {
  Serial.begin(9600); // begin serial communicationfor debug

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed")); // failsafe if oled not detected
    for (;;)
      ;
  }

  pinMode(button1, INPUT_PULLUP); //button pinmodes
  pinMode(button2, INPUT_PULLUP); //
  pinMode(button3, INPUT_PULLUP); //

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print("TamaDuino v1.0"); // name and version
  display.display();
  delay(500);
  display.clearDisplay();
  display.drawBitmap(0, 0, epd_bitmap_Untitled, 128, 64, 1); // show egg bitmap
  display.display();

  for (int i = 0; i < 5; i++) { // make the egg blink like its hatching
    display.invertDisplay(true);
    tone(6, 750, 200);
    delay(500);
    display.invertDisplay(false);
    tone(6, 500, 200);
    delay(500);
  }
  display.invertDisplay(false);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(32, 25);
  tone(6, 500, 200);
  delay(200);
  tone(6, 750, 200);
  display.print("(0v0)"); // the pet gets hatched
  display.display();
  toggleanim = 1;
}

void loop() {
  int buttonState1 = digitalRead(button1); // button read functions
  int buttonState2 = digitalRead(button2); //
  int buttonState3 = digitalRead(button3); //
  unsigned long time = millis(); // millis function
  int randposx = random(32,51); //random functions to make the pet wander
  int randposy = random(25,39);//

  if (buttonState2 == 0) { // change countvalue for menu scrolling
    countValue++;
    delay(100);
  }

  if (time - huprevTime >= hungerInterval) { // change hunger by time
    hunger -= 10;

    huprevTime = time;
  }

  if (time - haprevTime >= happinessInterval) { // change happiness by time
    happiness -= 20;

    haprevTime = time;
  }

  if (time - enprevTime >= energyInterval) { // change energy by time
    energy -= 30;

    enprevTime = time;
  }

  if (time - ageprevTime >= ageInterval) { // change age (up) by time
    age += 1;

    ageprevTime = time;
  }
  if (time - blprevTime >= blinkInterval) { // make the pet blink
    pet = "(0v0)";
    delay(50);
    pet = "(-v-)";
    delay(50);
    pet = "(0v0)";

  
    blprevTime = time;
  }
  if (time - animprevTime >= animInterval && toggleanim == 1) { //make the pet wander
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(randposx, randposy);
    display.clearDisplay();
    display.print("(-v-)");
    display.display();
    delay(70);
    display.setCursor(randposx, randposy);
    display.clearDisplay();
    display.print("(0v0)");
    display.display();
    delay(70);
    display.setCursor(randposx, randposy);
    display.clearDisplay();
    display.print("(0v0)");
    display.display();
    delay(70);
    
    animprevTime = time;
  }

  //Serial.println(); // UNCOMMENT FOR DEBUG

  if (buttonState1 == 0){ // Menu toggle
    toggleanim = 0;
    tone(6, 750, 200);
    display.clearDisplay();
    display.setCursor(0, 10);
    display.setTextSize(1);
    display.print("Menu");
    display.display();
    display.setCursor(0, 25);
    display.setTextSize(2);
    display.print("Feed");
    display.display();
    inMenu = 1;
    countValue = 0;
  }
  if (countValue == 1 && inMenu == 1){ // Menu scroll to "Play"
    tone(6, 750, 200);
    display.clearDisplay();
    display.setCursor(0, 10);
    display.setTextSize(1);
    display.print("Menu");
    display.display();
    display.setCursor(0, 25);
    display.setTextSize(2);
    display.print("Play");
    display.display();
    inMenu = 2;
  }
  if (countValue == 2 && inMenu == 2){ // Menu scroll to "Stats"
    tone(6, 750, 200);
    display.clearDisplay();
    display.setCursor(0, 10);
    display.setTextSize(1);
    display.print("Menu");
    display.display();
    display.setCursor(0, 25);
    display.setTextSize(2);
    display.print("Stats");
    display.display();
    inMenu = 3;
  }
  if (countValue == 3 && inMenu == 3){ // Menu scroll to "Sleep"
    tone(6, 750, 200);
    display.clearDisplay();
    display.setCursor(0, 10);
    display.setTextSize(1);
    display.print("Menu");
    display.display();
    display.setCursor(0, 25);
    display.setTextSize(2);
    display.print("Sleep");
    display.display();
    inMenu = 4;
  }
  if (countValue == 5 && inMenu == 4){ // Menu scroll to "Exit Menu"
    tone(6, 750, 200);
    display.clearDisplay();
    display.setCursor(0, 10);
    display.setTextSize(1);
    display.print("Menu");
    display.display();
    display.setCursor(0, 25);
    display.setTextSize(2);
    display.print("Exit Menu");
    display.display();
    inMenu = 6;
  }
  if (countValue > 4) { // If countvalue is bigger then 4 reset it (for stability)
    countValue = 1;
  }
  if (buttonState3 == 0 && inMenu == 1){ // make the pet eat when clicking action button on the "Feed" menu
    delay(200);
    display.clearDisplay();
    display.setCursor(32, 25);
    display.print("(0v0) &");
    display.display();
    delay(600);
    display.clearDisplay();
    display.setCursor(32, 25);
    display.print("( 0v0) &");
    display.display();
    delay(600);
    for (int i = 0; i < 6; i++) {
      display.clearDisplay();
      display.setCursor(30, 25);
      tone(6, 750, 200);
      display.print("( 0A0) &");
      display.display();
      delay(300);
      display.setCursor(32, 25);
      display.clearDisplay();
      tone(6, 500, 200);
      display.print("( 0-0) &");
      display.display();
      delay(300);
    }
    display.clearDisplay();
    display.setCursor(32, 25);
    tone(6, 500, 200);
    delay(200);
    tone(6, 750, 200);
    display.print("(0w0)");
    display.display();
    delay(200);
    hunger += 10; // hunger rises by 10
    display.clearDisplay();
    display.setCursor(32, 25);
    display.print(pet);
    display.display();
    toggleanim = 1;
    countValue = 0;
    //mealCooldown = 0;
  }
  if (buttonState3 == 0 && inMenu == 2){ // make the pet play when clicking action button on the "Play" menu
    for (int i = 0; i < 6; i++) {
      display.clearDisplay();
      display.setCursor(30, 25);
      tone(6, 500, 200);
      display.print("( 0v0)-@");
      display.display();
      delay(300);
      display.setCursor(32, 25);
      display.clearDisplay();
      tone(6, 1000, 200);
      display.print("( -v-)-@");
      display.display();
      delay(300);
    }
    display.clearDisplay();
    display.setCursor(32, 25);
    tone(6, 500, 200);
    delay(200);
    tone(6, 750, 200);
    display.print("(0w0)");
    display.display();
    delay(200);
    happiness += 10; // happiness rises by 10
    display.clearDisplay();
    display.setCursor(32, 25);
    display.print(pet);
    display.display();
    toggleanim = 1;
    countValue = 0;
  }


if(buttonState3 == 0 && inMenu == 3){ // show stats when clicking action button on the "Stats" menu
  tone(6, 750, 200);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 10);
  display.print("Happiness");
  display.display();
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(happiness);
  display.display();
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Hunger");
  display.display();
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(hunger);
  display.display();
  display.setTextSize(1);
  display.setCursor(64, 35);
  display.print("Energy");
  display.display();
  display.setTextSize(2);
  display.setCursor(64, 45);
  display.print(energy);
  display.display();
  display.setTextSize(1);
  display.setCursor(64, 10);
  display.print("Age");
  display.display();
  display.setTextSize(2);
  display.setCursor(64, 20);
  display.print(age);
  display.display();
  countValue = 0;
}

if (buttonState3 == 0 && inMenu == 4) { // make the pet sleep when clicking action button on the "Sleep" menu
  display.clearDisplay();
  display.setCursor(32, 25);
  tone(6, 750, 200);
  display.print("(-v-)zzz");
  display.display();
  delay(2000);
  tone(6, 500, 200);
  delay(200);
  tone(6, 750, 200);
  display.clearDisplay();
  display.setCursor(32, 25);
  display.print(pet);
  display.display();
  toggleanim = 1;
  energy += 10;
}
if (buttonState3 == 0 && inMenu == 6) { // Exit menu when clicking action button on the "Exit Menu" menu
  tone(6, 750, 200);
  display.clearDisplay();
  display.setCursor(32, 25);
  display.print(pet);
  display.display();
  toggleanim = 1;
  countValue = 0;
}

if (happiness == 0 || hunger == 0 || energy == 0 || hunger == 150) { // Make pet die when stats reach 0 or if pet overfed to 150
  toggleanim = 0;
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(15, 25);
  display.print("Your pet has died.");
  display.display();
  delay(2000);
  display.setCursor(0, 25);
  display.clearDisplay();
  display.print("It lived till age ");
  display.setCursor(115, 25);
  display.print(age);
  display.display();
  delay(2000);
}

if (energy > 100) { // Disable energy override
  energy = 100;
}
if (happiness > 100) { // Disable happiness override
  happiness = 100;
}

}
