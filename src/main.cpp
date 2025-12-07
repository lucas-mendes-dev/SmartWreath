#include <Arduino.h>
#include "../lib/MusicEngine/MusicPlayer.h"

#define PIN_BUZZER 4
#define PIN_LED1 6
#define PIN_LED2 7
#define PIN_BTN1 8
#define PIN_BTN2 9

MusicPlayer player(PIN_BUZZER);

// Jingle Bells
const MusicNote melody_jingle[] = {
  {NOTE_E4, EIGHTH}, {NOTE_E4, EIGHTH}, {NOTE_E4, QUARTER},
  {NOTE_E4, EIGHTH}, {NOTE_E4, EIGHTH}, {NOTE_E4, QUARTER},
  {NOTE_E4, EIGHTH}, {NOTE_G4, EIGHTH}, {NOTE_C4, EIGHTH}, {NOTE_D4, EIGHTH},
  {NOTE_E4, HALF}
};

// Carol of the Bells
const MusicNote melody_carol[] = {
  {NOTE_F5, QUARTER}, {NOTE_E5, EIGHTH}, {NOTE_F5, EIGHTH}, {NOTE_D5, EIGHTH},{NOTE_A4, EIGHTH},
  {NOTE_F5, QUARTER}, {NOTE_E5, EIGHTH}, {NOTE_F5, EIGHTH}, {NOTE_D5, EIGHTH},{NOTE_A4, EIGHTH},
  {NOTE_F5, QUARTER}, {NOTE_E5, EIGHTH}, {NOTE_F5, EIGHTH}, {NOTE_D5, EIGHTH},{NOTE_A4, EIGHTH}, 
  {NOTE_F5, QUARTER}, {NOTE_E5, EIGHTH}, {NOTE_F5, EIGHTH}, {NOTE_D5, HALF},
};

void setup() {
    pinMode(PIN_BTN1, INPUT_PULLUP);
    pinMode(PIN_BTN2, INPUT_PULLUP);
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);

    player.setBPM(80);
    player.play(melody_jingle, sizeof(melody_jingle)/sizeof(MusicNote), PIN_LED1);

    unsigned long initial_time = millis();
    unsigned long jingle_duration = (60000 * 4) / (80 * (int)8)*8 + (60000 * 4) / (80 * (int)4)*2 + (60000 * 4) / (80 * (int)2)*1;

    while(millis() - initial_time < jingle_duration) {
        player.update();
    }
    
    delay(1500);
    player.setBPM(140);
    player.play(melody_carol, sizeof(melody_carol)/sizeof(MusicNote), PIN_LED2);
}

void loop() {
    player.update();
    if (digitalRead(PIN_BTN1) == LOW) {
        player.setBPM(80);
        player.play(melody_jingle, sizeof(melody_jingle)/sizeof(MusicNote), PIN_LED1);
        delay(200);
    }
    if (digitalRead(PIN_BTN2) == LOW) {
        player.setBPM(140);
        player.play(melody_carol, sizeof(melody_carol)/sizeof(MusicNote), PIN_LED2);
        delay(200);
    }
}
