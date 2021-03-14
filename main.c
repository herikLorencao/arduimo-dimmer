#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd (13, 12, A0, A1, A2, A3);

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
String intensityValueBuffer = "";
int ledPin = 9;

void setup() {
    lcd.begin(16, 2);
    pinMode(ledPin, OUTPUT);
  	printLcd(0, 0, "Escala (0-100):");
  	delay(1000);
}

void loop() {
    char key = keypad.waitForKey();
    handleKey(key);
}

void handleKey(char key) {
  switch (key) {
  case '1':
    handleNumberKey("1");
    break;
  case '2':
    handleNumberKey("2");
    break;
  case '3':
    handleNumberKey("3");
    break;
  case '4':
    handleNumberKey("4");
    break;
  case '5':
    handleNumberKey("5");
    break;
  case '6':
    handleNumberKey("6");
    break;
  case '7':
    handleNumberKey("7");
    break;
  case '8':
    handleNumberKey("8");
    break;
  case '9':
    handleNumberKey("9");
    break;
  case '0':
    handleNumberKey("0");
    break;
  case '*':
    clearKeyHandler();
    break;
  case '#':
    confirmKeyHandler();
    break;
  default:
    invalidKeyHandler();
    break;
  }
}

void handleNumberKey(String key) {
  intensityValueBuffer = intensityValueBuffer + key;
  printLcd(1, 0, intensityValueBuffer);
}

void printLcd(int line, int column, String message) {
  lcd.setCursor(column, line);
  lcd.print(message);
}

void confirmKeyHandler() {
  if (intensityValueBuffer == "") {
    invalidKeyHandler();
  } else {
    defineLedIntensity(intensityValueBuffer.toInt());
    clearLcd();
    printLcd(1, 0, "Valor definido");
    delay(1000);
    clearLcd();
  }
}

void clearKeyHandler() {
  intensityValueBuffer = "";
  clearLcd();
  printLcd(1, 0, intensityValueBuffer);
}

void invalidKeyHandler() {
  printLcd(1, 0, "Tecla invalida");
  delay(1000);
  clearLcd();
  printLcd(1, 0, intensityValueBuffer);
}

void clearLcd() {
    lcd.clear();
    printLcd(0, 0, "Escala (0-100):");
}

void defineLedIntensity(int value) {
  int luminosity = value * 2;
  analogWrite(ledPin, luminosity);
  intensityValueBuffer = "";
}