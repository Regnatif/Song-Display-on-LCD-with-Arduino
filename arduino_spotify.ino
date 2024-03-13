#include "DFRobot_RGBLCD1602.h"

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;


unsigned long key_value = 0;

String readArtistSong = " ";

String oldSong = " ";

DFRobot_RGBLCD1602 lcd(/*RGBAddr*/0x60 ,/*lcdCols*/16,/*lcdRows*/2);

void setup() 
{
    Serial.begin(9600);
    lcd.init(); 
    lcd.setRGB(colorR, colorG, colorB);
    Serial.setTimeout(0);

}

void loop() 
{
  if(Serial.available())
  {
    readArtistSong = Serial.readStringUntil(':');
  }

  if(readArtistSong != oldSong)
  { 
    lcd.clear(); 
    String Artist = readArtistSong.substring(0, readArtistSong.indexOf(','));
    String Song = readArtistSong.substring(readArtistSong.indexOf(',') + 1);
    delay(200);
    lcd.setCursor(0, 0); 
    lcd.println(Artist);
    lcd.setCursor(0, 1); 
    lcd.println(Song);
    oldSong = readArtistSong;
  }

}

