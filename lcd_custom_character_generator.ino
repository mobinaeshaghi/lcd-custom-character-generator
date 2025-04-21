#include<LiquidCrystal.h> 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
 
byte armsDown[8] = { 
  0b00100, 
  0b01010, 
  0b00100, 
  0b00100, 
  0b01110, 
  0b10101, 
  0b00100, 
  0b01010 
}; 
 
byte armsUp[8] = { 
  0b00100, 
  0b01010, 
  0b00100, 
  0b10101, 
  0b01110, 
  0b00100, 
  0b00100, 
  0b01010 
}; 
 
void setup() { 
  lcd.begin(16, 2); 
  lcd.createChar(0, armsUp); 
  lcd.createChar(1, armsDown); 
} 
 
void loop() { 
  while (true) { 
    for (int i = 0; i < 16; i++) { 
      lcd.clear(); 
      lcd.setCursor(i, 0); 
      lcd.write(i % 2 == 0 ? byte(0) : byte(1)); 
      delay(300); 
    } 
    for (int i = 15; i >= 0; i--) { 
      lcd.clear(); 
      lcd.setCursor(i, 1); 
      lcd.write(i % 2 == 0 ? byte(0) : byte(1)); 
      delay(300); 
    } 
  } 
}