#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>



LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change the HEX address
Servo gateServo;

int entrySensor = 8;
int exitSensor = 9;
int availableSlots = 3;  // Enter Total number of parking Slots

int entryFlag = 0;
int exitFlag = 0;

SoftwareSerial nodemcu(2, 3);

int parking1_slot1_ir_s = 5; // parking slot1 infrared sensor connected with pin number 5 of Arduino
int parking1_slot2_ir_s = 6; // parking slot2 infrared sensor connected with pin number 6 of Arduino
int parking1_slot3_ir_s = 7; // parking slot3 infrared sensor connected with pin number 7 of Arduino

String slot1Status;
String slot2Status;
String slot3Status;

String parkingData = "";  // Complete data, consisting of sensor values

void setup() {
  delay(2000);
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  lcd.backlight();
  
  pinMode(entrySensor, INPUT);
  pinMode(exitSensor, INPUT);
  
  gateServo.attach(10);
  gateServo.write(100);

  lcd.setCursor(0, 0);
  lcd.print("     PARKEASE    ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING CENTER ");
  delay(3000);
  lcd.clear();

  Serial.begin(9600);
  nodemcu.begin(9600);

  pinMode(parking1_slot1_ir_s, INPUT);
  pinMode(parking1_slot2_ir_s, INPUT);
  pinMode(parking1_slot3_ir_s, INPUT);
}

void loop() {
  // Car enters
  if (digitalRead(entrySensor1) == LOW && entryFlag == 0) {
    if (availableSlots > 0) {
      entryFlag = 1;
      if (exitFlag == 0) {
        gateServo.write(0);
        availableSlots = availableSlots - 1;
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print("    SORRY :(    ");
      lcd.setCursor(0, 1);
      lcd.print("  Parking Full  ");
      delay(3000);
      lcd.clear();
    }
  }

  // Car exits
  if (digitalRead(exitSensor) == LOW && exitFlag == 0) {
    exitFlag = 1;
    if (entryFlag == 0) {
      gateServo.write(0);
      availableSlots = availableSlots + 1;
    }
  }

  // Reset flags and close gate
  if (entryFlag == 1 && exitFlag == 1) {
    delay(1000);
    gateServo.write(100);
    entryFlag = 0;
    exitFlag = 0;
  }

  // Display available slots
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME!    ");
  lcd.setCursor(0, 1);
  lcd.print("Slot Left: ");
  lcd.print(Slot);

  // Check parking slots status
  p1slot1();
  p1slot2();
  p1slot3();

  // Send data to NodeMCU
  parkingData = slot1Status + "," + slot2Status + "," + slot3Status;
  Serial.println(parkingData);
  nodemcu.println(parkingData);

  delay(3000);
  parkingData = "";  // Reset data for next loop

  digitalWrite(parking1_slot1_ir_s, HIGH);
  digitalWrite(parking1_slot2_ir_s, HIGH);
  digitalWrite(parking1_slot3_ir_s, HIGH);
}

void p1slot1() {  // Parking slot 1
  if (digitalRead(parking1_slot1_ir_s) == LOW) {
    slot1Status = "255";  // Slot occupied
    delay(200);
  }
  if (digitalRead(parking1_slot1_ir_s) == HIGH) {
    slot1Status = "0";  // Slot free
    delay(200);
  }
}

void p1slot2() {  // Parking slot 2
  if (digitalRead(parking1_slot2_ir_s) == LOW) {
    slot2Status = "255";  // Slot occupied
    delay(200);
  }
  if (digitalRead(parking1_slot2_ir_s) == HIGH) {
    slot2Status = "0";  // Slot free
    delay(200);
  }
}

void p1slot3() {  // Parking slot 3
  if (digitalRead(parking1_slot3_ir_s) == LOW) {
    slot3Status = "255";  // Slot occupied
    delay(200);
  }
  if (digitalRead(parking1_slot3_ir_s) == HIGH) {
    slot3Status = "0";  // Slot free
    delay(200);
  }
}
