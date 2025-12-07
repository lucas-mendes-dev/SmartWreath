#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "MusicDefinitions.h"

class MusicPlayer {
private:
    uint8_t _buzzerPin;
    uint8_t _ledPin;
    int _bpm;
    const MusicNote* _currentMelody;
    int _melodyLength;
    int _noteIndex;
    unsigned long _lastNoteTime;
    unsigned long _currentNoteDurationMs;
    bool _isPlaying;
    bool _noteState;
    unsigned long calculateDuration(NoteType noteType);
public:
    MusicPlayer(uint8_t buzzerPin);
    void setBPM(int bpm);
    void play(const MusicNote* melody, int length, uint8_t ledPin);
    void stop();
    void update();
    bool isPlaying() const;
};

#endif
