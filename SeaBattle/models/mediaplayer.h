#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMap>
#include "models/musictype.h"

class MediaPlayer
{
private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    QMap<MusicType, QString> music{
        {MusicType::BACKGROUND_MUSIC, "qrc:/resources/music/Ignis(chosic.com).mp3"},
        {MusicType::BLAST_MUSIC, "qrc:/resources/music/boom.mp3"},
        {MusicType::MISS_MUSIC, "qrc:/resources/music/water.mp3"}
    };
public:
    MediaPlayer();
    ~MediaPlayer();
    void paly(MusicType musicType);
    void setLoops(qint32 number);
    void setVolume(qint32 number);
};

#endif // MEDIAPLAYER_H
