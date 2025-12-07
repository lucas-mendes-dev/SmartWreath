#include <Arduino.h>

// Definicao dos pinos
const int buzzer = 4;
const int led1 = 6;
const int led2 = 7;
const int btn1 = 8;
const int btn2 = 9;

// Notas musicais (Frequencias)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587

void playJingleBells();

void playCarolOfTheBells();

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  // Usando PULLUP para dispensar resistor externo no bot�o
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}

void loop() {
  // Verifica bot�o 1 - Jingle Bells
  if (digitalRead(btn1) == LOW) {
    digitalWrite(led1, HIGH);
    playJingleBells();
    digitalWrite(led1, LOW);
  }

  // Verifica bot�o 2 - Carol of the Bells
  if (digitalRead(btn2) == LOW) {
    digitalWrite(led2, HIGH);
    playCarolOfTheBells();
    digitalWrite(led2, LOW);
  }
}

// --- Fun��es Musicais ---

void toneOut(int note, int duration) {
  tone(buzzer, note, duration);
  delay(duration * 1.30); // Pausa entre notas
  noTone(buzzer);
}

void playJingleBells() {
  // 4 compassos simplificados (Refre�o)
  int melody[] = { NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4 };
  int durations[] = { 200, 200, 400, 200, 200, 400, 200, 200, 200, 200, 800 };
  
  for (int i = 0; i < 11; i++) {
    toneOut(melody[i], durations[i]);
  }
}

void playCarolOfTheBells() {
  // Motivo principal repetido 4 vezes
  int motif[] = { NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_G4 };
  int dur = 200;

  for (int compasso = 0; compasso < 4; compasso++) {
    for (int i = 0; i < 4; i++) {
      toneOut(motif[i], dur);
    }
  }
}
