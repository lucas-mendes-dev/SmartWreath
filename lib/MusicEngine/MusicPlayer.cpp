#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(uint8_t buzzerPin) {
    _buzzerPin = buzzerPin;
    _bpm = 120;
    _isPlaying = false;
    _noteIndex = 0;
    pinMode(_buzzerPin, OUTPUT);
}

void MusicPlayer::setBPM(int bpm) {
    _bpm = bpm;
}

void MusicPlayer::play(const MusicNote* melody, int length, uint8_t ledPin) {
    _currentMelody = melody;
    _melodyLength = length;
    _ledPin = ledPin;
    _noteIndex = 0;
    _isPlaying = true;
    _lastNoteTime = millis();
    _currentNoteDurationMs = 0;
    _noteState = false;
    pinMode(_ledPin, OUTPUT);
    noTone(_buzzerPin);
}

void MusicPlayer::stop() {
    _isPlaying = false;
    noTone(_buzzerPin);
    if (_ledPin != 0) digitalWrite(_ledPin, LOW);
}

unsigned long MusicPlayer::calculateDuration(NoteType noteType) {
    if (noteType == REST) return 0;
    return (60000 * 4) / (_bpm * (int)noteType);
}

void MusicPlayer::update() {
    if (!_isPlaying) return;
    unsigned long currentMillis = millis();
    if (currentMillis - _lastNoteTime >= _currentNoteDurationMs) {
        if (_noteIndex < _melodyLength) {
            MusicNote note = _currentMelody[_noteIndex];
            unsigned long fullDuration = calculateDuration(note.duration);
            if (note.frequency > 0) {
                tone(_buzzerPin, note.frequency, fullDuration);
                if (_ledPin != 0) digitalWrite(_ledPin, HIGH);
            } else {
                if (_ledPin != 0) digitalWrite(_ledPin, LOW);
            }
            _lastNoteTime = currentMillis;
            _currentNoteDurationMs = fullDuration;
            _noteIndex++;
        } else {
            stop();
        }
    } else {
        if (_ledPin != 0 && (currentMillis - _lastNoteTime > _currentNoteDurationMs / 2)) {
            digitalWrite(_ledPin, LOW);
        }
    }
}

bool MusicPlayer::isPlaying() const {
    return _isPlaying;
}
