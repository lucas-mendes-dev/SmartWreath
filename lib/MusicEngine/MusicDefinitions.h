#ifndef MUSIC_DEFINITIONS_H
#define MUSIC_DEFINITIONS_H

#include <Arduino.h>

// Frequências (Hz)
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_As4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_As5 932
#define NOTE_B5 988

// Definição de figuras rítmicas (base 4/4)
enum NoteType {
    WHOLE     = 1,
    HALF      = 2,
    QUARTER   = 4,
    EIGHTH    = 8,
    SIXTEENTH = 16,
    REST      = 0 // Pausa
};

struct MusicNote {
    int frequency;
    NoteType duration;
};

#endif
