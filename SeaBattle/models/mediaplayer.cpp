#include "mediaplayer.h"

MediaPlayer::MediaPlayer() {
    player = new QMediaPlayer();
    audioOutput = new QAudioOutput();
    player->setAudioOutput(audioOutput);
}

MediaPlayer::~MediaPlayer()
{
    player->stop();
    delete player;
    delete audioOutput;
}

void MediaPlayer::paly(MusicType musicType)
{
    player->stop();
    player->setSource(QUrl(music.value(musicType)));
    player->play();

    qDebug() << player->error();
}

void MediaPlayer::setLoops(qint32 number)
{
    player->setLoops(number);
}
