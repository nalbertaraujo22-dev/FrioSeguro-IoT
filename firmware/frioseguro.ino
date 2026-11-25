#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Definições de Pinos
#define DHTPIN 2
#define DHTTYPE DHT22
#define BUZZER_PIN 8
#define LED_VERDE 9
#define LED_VERMELHO 10

// Faixas Operacionais (Câmara Fria Farmacêutica / Insumos)
const float TEMP_MIN = 2.0;
const float TEMP_MAX = 8.0;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("FrioSeguro IoT");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(temperatura) || isnan(umidade)) {
    lcd.setCursor(0, 0);
    lcd.print("Erro Sensor DHT!");
    Serial.println("ERRO: Falha na leitura do sensor DHT22");
    delay(2000);
    return;
  }

  // Envio estruturado via Serial para o Gateway Python/Web
  Serial.print("TEMP:");
  Serial.print(temperatura, 1);
  Serial.print("|UMID:");
  Serial.print(umidade, 1);

  // Exibição no LCD
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura, 1);
  lcd.print("C U:");
  lcd.print(umidade, 0);
  lcd.print("%  ");

  // Lógica de Controle e Alerta
  if (temperatura < TEMP_MIN || temperatura > TEMP_MAX) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    tone(BUZZER_PIN, 1000); // Alerta sonoro 1kHz
    
    lcd.setCursor(0, 1);
    lcd.print("STATUS: ALERTA! ");
    Serial.println("|STATUS:CRITICO");
  } else {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER_PIN);
    
    lcd.setCursor(0, 1);
    lcd.print("STATUS: NORMAL  ");
    Serial.println("|STATUS:OK");
  }

  delay(2000);
}
