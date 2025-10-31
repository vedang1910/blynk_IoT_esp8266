#define BLYNK_TEMPLATE_ID "----------"
#define BLYNK_TEMPLATE_NAME "------------"
#define BLYNK_AUTH_TOKEN "-------------"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials
char ssid[] = "YourSSID";
char pass[] = "YourPass";

// Relay connected to D0 (GPIO16)
#define RELAY_PIN D0

// Blynk Virtual Pin for controlling relay
BLYNK_WRITE(V0) {
  int value = param.asInt(); // Get value from Blynk app (0 or 1)
  digitalWrite(RELAY_PIN, value);
  Serial.print("Relay Status: ");
  Serial.println(value ? "ON" : "OFF");
}

void setup() {
  Serial.begin(115200);
  
  // Initialize relay pin as output
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Start with relay OFF
  
  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  Serial.println("Device Started");
}

void loop() {
  Blynk.run(); // Run Blynk magic
}