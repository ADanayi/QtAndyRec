#include "qtandyrec.h"

QtAndyRec::QtAndyRec(QObject *parent) :
    QObject(parent)
{
    setup_format();
    setup_audio();
    this->dest_file = nullptr;
}

void QtAndyRec::setup_format() {
    format = new QAudioFormat();
    format->setSampleRate(16000);
    format->setSampleType(QAudioFormat::SignedInt);
    format->setChannelCount(1);
    format->setSampleSize(16);
    format->setCodec("audio/pcm");
    format->setByteOrder(QAudioFormat::LittleEndian);
    format->setSampleType(QAudioFormat::SignedInt);
}

void QtAndyRec::setup_audio() {
    audio = new QAudioInput(*format, this);
}

bool QtAndyRec::setup_file(QString path) {
    this->dest_file = new QFile(path);
    if (!dest_file->open(QIODevice::ReadWrite)) {
        return false;
    }
    return true;
}

void QtAndyRec::setdown_file() {
    if (this->dest_file != nullptr) {
        this->dest_file->close();
        this->dest_file->deleteLater();
    }
}

bool QtAndyRec::start_recording(QString path) {
    if (!(this->setup_file(path))) {
        return false;
    }
    if ((this->audio->state() == QAudio::StoppedState ))
        this->audio->start(this->dest_file);
    else
        return false;
    return true;
}

void QtAndyRec::stop_recording() {
    if (this->audio->state() == QAudio::StoppedState)
        this->audio->stop();
}
