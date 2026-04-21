#include <DHT.h>

// -------------------- PINOS --------------------
#define PIN_DHT 21
#define PIN_RELE 26
#define PIN_LDR 34

#define PIN_N 12
#define PIN_P 13
#define PIN_K 14

#define DHTTYPE DHT22

DHT dht(PIN_DHT, DHTTYPE);

// -------------------- SETUP --------------------
void setup() {
  Serial.begin(115200);

  // Botões NPK (INPUT_PULLUP)
  pinMode(PIN_N, INPUT_PULLUP);
  pinMode(PIN_P, INPUT_PULLUP);
  pinMode(PIN_K, INPUT_PULLUP);

  // Relé
  pinMode(PIN_RELE, OUTPUT);
  digitalWrite(PIN_RELE, LOW);

  dht.begin();

  Serial.println("Sistema de irrigacao iniciado...");
}

// -------------------- LOOP --------------------
void loop() {

  // ---------- LEITURA DOS BOTÕES ----------
  bool N = digitalRead(PIN_N) == LOW;
  bool P = digitalRead(PIN_P) == LOW;
  bool K = digitalRead(PIN_K) == LOW;

  // ---------- LEITURA DHT ----------
  float umidade = dht.readHumidity();

  if (isnan(umidade)) {
    Serial.println("Erro ao ler o DHT22");
    delay(2000);
    return;
  }

  // ---------- LEITURA LDR ----------
  int leituraLDR = analogRead(PIN_LDR);

  // Simulação de pH (0 a 14)
  float ph = (leituraLDR / 4095.0) * 14.0;

  // ---------- CONTAGEM DE NUTRIENTES ----------
  int nutrientesOK = 0;
  if (N) nutrientesOK++;
  if (P) nutrientesOK++;
  if (K) nutrientesOK++;

  // ---------- LÓGICA DE IRRIGAÇÃO ----------
  bool irrigar = false;

  if (umidade < 50.0 && ph >= 5.0 && ph <= 7.0 && nutrientesOK >= 2) {
    irrigar = true;
  }

  digitalWrite(PIN_RELE, irrigar ? HIGH : LOW);

  // ---------- SERIAL MONITOR ----------
  Serial.println("------ LEITURA ATUAL ------");

  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.println("%");

  Serial.print("LDR: ");
  Serial.println(leituraLDR);

  Serial.print("pH estimado: ");
  Serial.println(ph);

  Serial.print("N: ");
  Serial.println(N ? "OK" : "BAIXO");

  Serial.print("P: ");
  Serial.println(P ? "OK" : "BAIXO");

  Serial.print("K: ");
  Serial.println(K ? "OK" : "BAIXO");

  Serial.print("Nutrientes OK: ");
  Serial.println(nutrientesOK);

  Serial.print("Irrigacao: ");
  Serial.println(irrigar ? "LIGADA" : "DESLIGADA");

  Serial.println("----------------------------\n");

  delay(2000);
}
