#ifndef MEDIAENGINE_H
#define MEDIAENGINE_H

#include <QObject>
#include <QString>

#include <QMessageBox>
#include <QTextBrowser>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QMediaPlayer>

#include <QFileInfo>
#include <QFile>


class MediaEngine : public QObject
{
    Q_OBJECT

public:
    explicit MediaEngine();

    void msgCatanzaro();

    void checkForEasterEggs(const QString& string);

    void genericVideoPlay(QString url);
    void genericHTMLBrowser(QString url);

private:
    void msgSubscription();
    void msgNotImplemented();
    void msgHelp1();

    //Easter eggs

    void easterEggRichard(bool fullVersion);

    //Media players
};
#endif // MEDIAENGINE_H