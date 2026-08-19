#include <WiFi.h>
#include <PubSubClient.h>

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;

// Use um tópico específico para evitar conflito com outros usuários
const char* MQTT_TOPIC = "arnaldo/unity/btn1";

const int BTN1 = 33;

WiFiClient espClient;
PubSubClient mqtt(espClient);

void conectarWiFi() {
  Serial.print("Conectando ao WiFi");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, 6);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi conectado!");
}

void conectarMQTT() {
  while (!mqtt.connected()) {
    Serial.print("Conectando ao MQTT...");

    String clientId = "wokwi-unity-" + String(random(0xffff), HEX);

    if (mqtt.connect(clientId.c_str())) {
      Serial.println(" conectado!");
    } else {
      Serial.println(" falhou. Tentando novamente...");
      delay(1000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(BTN1, INPUT_PULLUP);

  conectarWiFi();

  mqtt.setServer(MQTT_BROKER, MQTT_PORT);
}

void loop() {
  if (!mqtt.connected()) {
    conectarMQTT();
  }

  mqtt.loop();

  int estado = digitalRead(BTN1);

  if (estado == LOW) {
    mqtt.publish(MQTT_TOPIC, "1");
    Serial.println("BTN1: 1");
  } else {
    mqtt.publish(MQTT_TOPIC, "0");
    Serial.println("BTN1: 0");
  }

  delay(500);
}