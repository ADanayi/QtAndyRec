#ifndef QTANDYREC_H
#define QTANDYREC_H

#include <QFile>
#include <QObject>
#include <QtMultimedia/QAudioFormat>
#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudio>

class QtAndyRec : public QObject
{
    Q_OBJECT
public:
    explicit QtAndyRec(QObject *parent = nullptr);
    Q_INVOKABLE bool start_recording(QString path);
    Q_INVOKABLE void stop_recording();

private:
    QAudioFormat * format;
    QAudioInput * audio;
    void setup_format();
    void setup_audio();
    bool setup_file(QString path);

    void setdown_file();
    QFile * dest_file;
signals:

public slots:
};

#endif // QTANDYREC_H
