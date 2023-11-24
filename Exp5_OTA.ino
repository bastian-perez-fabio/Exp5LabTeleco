#include <WiFi.h>
#include <ArduinoOTA.h>

const char *ssid = "Orionnn";         // Nombre de tu red WiFi
const char *password = "chillll06";    // Contraseña de tu red WiFi

const int ledPin = 2;  // Pin GPIO del LED

unsigned long periodo = 500;  // Período inicial en milisegundos

void setup() {
  Serial.begin(115200);

  // Conexión a la red WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a la red WiFi");

  // Configuración OTA
  ArduinoOTA.begin();
  ArduinoOTA.setHostname("ESP32-OTA-GRUPO7");  // Puedes cambiar el nombre del dispositivo

  // Configuración del pin del LED
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Manejar actualizaciones OTA
  ArduinoOTA.handle();

  // Encender y apagar el LED con el período actual
  digitalWrite(ledPin, HIGH);
  delay(periodo);
  digitalWrite(ledPin, LOW);
  delay(periodo);
}
