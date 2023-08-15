#include <LiquidCrystal.h>
#include "Keypad.h"

const byte ROWS = 4; // number of rows
const byte COLS = 4; // number of columns
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

char key;
byte rowPins[ROWS] = {9, 8, 7, 6}; // row pinouts of the keypad R1 = D8, R2 = D7, R3 = D6, R4 = D5
byte colPins[COLS] = {5, 4, 3, 2};    // column pinouts of the keypad C1 = D4, C2 = D3, C3 = D2
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
const int LCD_COLS = 16;
const int rs = 12, en = 11, d4 = 17, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int userNum = 2;
String users[userNum][2];

const int buzzerPin = 10;

void setup() {

  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(LCD_COLS, 2);
  pinMode(buzzerPin, OUTPUT);
  playStartupSound();

}


char handleScrollingAndInput(const String& topRowText, const String& bottomRowText) {
  unsigned long lastScrollTime = 0;
  bool scrolling = true;
  char pressedKey = '\0';

  while (scrolling) {
    unsigned long currentTime = millis();

    if (currentTime - lastScrollTime >= 750) {
      lastScrollTime = currentTime;

      lcd.clear();
      lcd.setCursor(LCD_COLS - topRowText.length(), 0);
      lcd.print(topRowText);

      lcd.setCursor(LCD_COLS - bottomRowText.length(), 1);
      lcd.print(bottomRowText);

      topRowText = topRowText.substring(1) + topRowText.charAt(0);
      bottomRowText = bottomRowText.substring(1) + bottomRowText.charAt(0);
    }

    key = keypad.getKey();
    if (key) {
      inputSound();
      scrolling = false; // Stop scrolling
      pressedKey = key;
    }
  }

  return pressedKey;
}

void create() {

  lcd.clear();
  lcd.home();
  lcd.print("Create username");
  lcd.setCursor(0, 1);
  String usr = "";
  do {
    key = keypad.getKey();
    if (key != '#' && key != NO_KEY) {
      inputSound();
      usr += key;
      lcd.print(key);
    }
    
  }while(key != '#');
  inputComplete();
  delay(1000);
  lcd.clear();

  if (usr.length() <= 0) {
    playFailedLogin();
    handleScrollingAndInput("Username error   ", " ");  
    return;
  }

  lcd.home();
  lcd.print("Create password");
  lcd.setCursor(0, 1);

  String password = "";
  do {
    key = keypad.getKey();
    if (key != '#' && key != NO_KEY) {
      inputSound();
      password += key;
      lcd.print(key);
    } 
    
  }while(key != '#');
  inputComplete();
  delay(1000);
  lcd.clear();
  

  if (password.length() == 0) {
    playFailedLogin();
    handleScrollingAndInput("Password error   ", " ");  
    delay(5000);
    return;
  }
  
  for (int i = 0; i < userNum; ++i) {
    if (users[i][0].length() == 0) {     
      users[i][0] = usr;
      users[i][1] = password;
      playNewAccountSound();
      handleScrollingAndInput("New account created   ", " ");  
      return;
    }
    
  }
  playFailedLogin();
  handleScrollingAndInput("Too many users   ", " ");  
  return;
}

void login() {

  lcd.clear();
  lcd.home();
  lcd.print("Input username");
  lcd.setCursor(0, 1);
  String usr =""; 
  do {

    key = keypad.getKey();
    if (key != '#' && key != NO_KEY) {
      inputSound();
      usr += key;
      lcd.print(key);
    }

  }while(key != '#');
  inputComplete();
  delay(1000);
  lcd.clear();
  lcd.home();
  lcd.print("Input password");
  lcd.setCursor(0, 1);

  String password = "";
  do {

    key = keypad.getKey();
    if (key != '#' && key != NO_KEY) {
      inputSound();
      password += key;
      lcd.print(key);
    }
    
  }while(key != '#');
  inputComplete();
  delay(1000);
  lcd.clear();

  for (int i = 0; i < userNum; ++i) {

    if (users[i][0] == usr) {
      if (users[i][1] == password) {
        playLoginSound();
        handleScrollingAndInput("Login successful   ", "");
        return;

      }
    }
    
  }
  playFailedLogin();
  handleScrollingAndInput("User not found   ", "");
  delay(3000);
  return;

}



void playNote(int frequency, int duration) {
  for (long i = 0; i < duration * 1000L; i += frequency * 2) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(frequency);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(frequency);
  }
}

void playStartupSound() {
  int melody[] = {
    523, 75, 0, 25, 523, 75, 0, 25,
    784, 75, 0, 25,
    523, 75, 0, 25, 392, 75, 0, 25,
    523, 75, 0, 25
  };

  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i += 2) {
    int note = melody[i];
    int duration = melody[i + 1];
    
    if (note == 0) {
      delay(duration);
    } else {
      playNote(note, duration);
      delay(duration / 2);
    }
  }
}


void playLoginSound() {
  int melody[] = {
    659, 100, 0, 100, 554, 100, 659, 100
  };

  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i += 2) {
    int note = melody[i];
    int duration = melody[i + 1];
    
    if (note == 0) {
      delay(duration);
    } else {
      playNote(note, duration);
      delay(duration / 2);
    }
  }
}

void playFailedLogin() {
  playNote(440, 100);
  delay(50);
  playNote(330, 100);
  delay(50);
  playNote(220, 100);
}

void playNewAccountSound() {
  int melody[] = {
    659, 100, 0, 50, 500, 100, 0, 50,
    659, 100
  };

  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i += 2) {
    int note = melody[i];
    int duration = melody[i + 1];
    
    if (note == 0) {
      delay(duration);
    } else {
      playNote(note, duration);
      delay(duration / 2);
    }
  }
}

void inputSound() {
  playNote(600, 100);
}

void inputComplete() {
  playNote(750, 250);
}

void loop() {

  key = handleScrollingAndInput("Account login   ", "1-New 2-Login   ");
  if (key == '1') {
    create();
  }
  else {
    if (key == '2') {
      login();
    }
  }
  
  
}

