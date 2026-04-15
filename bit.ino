#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
#define WIFI_CHANNEL 6

const int BUTTON_PIN = 32;
const int LED_PIN = 27;

const char* BITCOIN_URL =
  "https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=usd";

const unsigned long DEBOUNCE_MS = 300;

// Flag alterada pela interrupcao
volatile bool buttonEvent = false;

// Guarda o instante do ultimo clique aceito
unsigned long lastAcceptedPressTime = 0;

void IRAM_ATTR handleButtonInterrupt() {
  buttonEvent = true;
}

void connectWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL);

  Serial.print("Conectando ao WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void fetchBitcoinPrice() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi desconectado. Reconectando...");
    connectWiFi();
  }

  HTTPClient http;
  http.begin(BITCOIN_URL);

  Serial.println("Consultando preco do Bitcoin...");
  int httpCode = http.GET();

  if (httpCode != HTTP_CODE_OK) {
    Serial.print("Erro HTTP: ");
    Serial.println(httpCode);
    digitalWrite(LED_PIN, LOW);
    http.end();
    return;
  }

  String payload = http.getString();
  http.end();

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, payload);

  if (error) {
    Serial.print("Erro ao ler JSON: ");
    Serial.println(error.c_str());
    digitalWrite(LED_PIN, LOW);
    return;
  }

  JsonVariant priceNode = doc["bitcoin"]["usd"];

  if (priceNode.isNull()) {
    Serial.println("Campo bitcoin.usd nao encontrado");
    digitalWrite(LED_PIN, LOW);
    return;
  }

  float bitcoinPrice = priceNode.as<float>();

  Serial.print("Preco do Bitcoin (USD): ");
  Serial.println(bitcoinPrice, 2);

  digitalWrite(LED_PIN, HIGH);
}

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);

  connectWiFi();

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonInterrupt, FALLING);

  Serial.println("Sistema pronto.");
  Serial.println("Pressione o botao para consultar o Bitcoin.");
}

void loop() {
  unsigned long now = millis();

  if (buttonEvent) {
    buttonEvent = false;

    if (now - lastAcceptedPressTime >= DEBOUNCE_MS) {
      lastAcceptedPressTime = now;
      fetchBitcoinPrice();
    }
  }
}