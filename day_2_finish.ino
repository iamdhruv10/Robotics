 #include <rgb_lcd.h>

#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include "rgb_lcd.h"


#define DHTPIN 4      // Pin connected to the DHT sensor
#define DHTTYPE DHT11 // Define the type of sensor used

DHT dht(DHTPIN, DHTTYPE); // Create an instance of the DHT class
rgb_lcd lcd;


unsigned long previousMillis = 0;  // Stores the last time the temperature was updated
const long interval = 1000;        // Interval at which to switch units (milliseconds)
bool showCelsius = true;           // Flag to toggle between Celsius and Fahrenheit

void setup() {
  Serial.begin(9600);
  dht.begin(); // Initialize the sensor
   // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    lcd.setRGB(0, 255, 61);
    
    dht.begin(); // Initialize the DHT sensor
    
}



void loop() {
  unsigned long currentMillis = millis(); // Get the current time

  // Read sensor data
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  float temperatureF = dht.readTemperature(true); // true for Fahrenheit

  // Check if any reads failed and exit early
  if (isnan(humidity) || isnan(temperatureC)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed to read sensor!");
    return;
  }

  // Alternate the display every `interval` milliseconds
  if (currentMillis - previousMillis >= interval) {
    // Save the last time you updated the display
    previousMillis = currentMillis;

    // Toggle the temperature unit
    showCelsius = !showCelsius;
  }
   // Print the results
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C or ");
  Serial.print(temperatureF);
  Serial.println(" °F");

  // Display humidity on the top line
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  // Display temperature on the bottom line, alternating between Celsius and Fahrenheit
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  if (showCelsius) {
    lcd.print(temperatureC);
    lcd.print(char(223));
    lcd.print(" C");
  } else {
    lcd.print(temperatureF);
    lcd.print(char(223));
    lcd.print(" F");
  }


  if (temperatureF > 85 && humidity <= 35){
    lcd.setRGB(0, 0, 250);
    delay(200);
    lcd.setRGB(250, 0, 0);
    delay(500);
  }
  else if (temperatureF >= 75 && temperatureF <= 85 && humidity <= 25) {
    lcd.setRGB(0, 0, 250);
    delay(200);
    lcd.setRGB(250, 0, 0);
    delay(500);
  }
  else if (temperatureF >= 65 && temperatureF <= 75 && humidity < 15) {
    lcd.setRGB(255, 0, 255);
    delay(200);
    lcd.setRGB(255, 0, 0);
    delay(500);
  }
}
