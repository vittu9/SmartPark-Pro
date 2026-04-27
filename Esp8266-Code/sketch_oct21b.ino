#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "enter your template id"          // Updated Blynk Template ID
#define BLYNK_TEMPLATE_NAME "car parking"          // Updated Blynk Template Name
#define BLYNK_AUTH_TOKEN "enter your token"  // Updated Blynk Auth Token

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "blnyk authorization code";  // Updated Blynk authorization code
char ssid[] = "ios";
char pass[] = "password";

BlynkTimer timer;  // Use BlynkTimer instead of SimpleTimer

String myString;  // Complete message from Arduino, which consists of sensor data
char rdata;       // Received characters

int led1, led2, led3, count = 0;  // sensors

void setup() {
  Serial.begin(9600);                                // Initialize serial communication for debugging
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);  // Connect to Blynk

  timer.setInterval(1000L, sensorvalue1);
  timer.setInterval(1000L, sensorvalue2);
  timer.setInterval(1000L, sensorvalue3);
  timer.setInterval(1000L, totalcars);
}

void loop() {
  if (Serial.available() > 0) {
    rdata = Serial.read();
    myString += rdata;
    if (rdata == '\n') {
      Serial.println(myString);

      String l = getValue(myString, ',', 0);
      String m = getValue(myString, ',', 1);
      String n = getValue(myString, ',', 2);

      led1 = l.toInt();
      led2 = m.toInt();
      led3 = n.toInt();

      myString = "";
    }
  }

  Blynk.run();
  timer.run();
}

void sensorvalue1() {
  int sdata = led1;
  Blynk.virtualWrite(V1, sdata);
}

void sensorvalue2() {
  int sdata = led2;
  Blynk.virtualWrite(V2, sdata);
}

void sensorvalue3() {
  int sdata = led3;
  Blynk.virtualWrite(V3, sdata);
}

void totalcars() {
  int arr[] = {led1, led2, led3};
  count = countNonZeroElements(arr, 3);
  Blynk.virtualWrite(V4, count);
}

int countNonZeroElements(int arr[], int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] != 0) {
      count++;
    }
  }
  return count;
}

String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
