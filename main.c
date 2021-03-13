#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[COLS] = {7, 6, 5, 4};
byte colPins[ROWS] = {3, 2, 1, 0};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
    lcd.begin(16, 2);
    printLcd(0, 0, "INICIANDO ...");
  	delay(1000);
}

void loop() {
    char key = keypad.waitForKey();
}

void printLcd(int line, int column, String message) {
    lcd.setCursor(column, line);
  	lcd.print(message);
}

void clearLcd() {
    lcd.clear();
}
