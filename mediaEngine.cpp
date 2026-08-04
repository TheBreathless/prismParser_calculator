#include "mediaEngine.h"

MediaEngine::MediaEngine() {}



void MediaEngine::checkForEasterEggs(const QString& string)
{
    if(string.contains("18*59"))
        easterEggRichard(true);
    else if(string.contains("1062/0") || string.contains("1062÷0"))
        easterEggRichard(false);
}





///Msg boxes
void MediaEngine::msgCatanzaro()
{
    QMessageBox niggaMsg(nullptr);   //Has some bugs

    niggaMsg.setAttribute(Qt::WA_DeleteOnClose);

    niggaMsg.setWindowTitle("SOLUZIONE FINALE");
    niggaMsg.setText("La soluzione finale ha avuto inizio");
    niggaMsg.setInformativeText("Confermare l'annientamento del medio oriente?");
    niggaMsg.setIcon(QMessageBox::Warning);
    niggaMsg.setStandardButtons(QMessageBox::Yes | QMessageBox::Abort | QMessageBox::Cancel);
    niggaMsg.setDefaultButton(QMessageBox::Yes);

    niggaMsg.exec();
}

void MediaEngine::msgSubscription()
{
    QMessageBox msg(nullptr);

    msg.setAttribute(Qt::WA_DeleteOnClose);

    msg.setWindowTitle("Funzionalità premium");

    msg.setText("Per questa funzionalità è necessario un abbonamento");
    msg.setInformativeText("4,99€ per il primo mese, poi 9,99€.\nIl pagamento è esclusivamente via bonifico bancario");

    msg.setIcon(QMessageBox::Question);

    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::Ignore | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Yes);

    int lvalue = msg.exec();

    switch(lvalue)
    {
    case QMessageBox::Yes:
        msg.setIcon(QMessageBox::Warning);
        msg.setText("In attesa della conferma...");
        msg.setInformativeText("In attesa dell'approvazione della transazione...");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        break;

    default:
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Transazione annullata");
        msg.setInformativeText("Annullamento della transazione...");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        break;
    }
}

void MediaEngine::msgNotImplemented()
{
    QMessageBox msg(nullptr);

    msg.setAttribute(Qt::WA_DeleteOnClose);

    msg.setWindowTitle("Funzionalità non implementata");

    msg.setText("La funzionalità richiesta non esiste o non è stata implementata");
    msg.setInformativeText("Aggiorna o riavvia l'app, altrimenti segnala il problema\nUn log contenente il report è stato generato");

    msg.setIcon(QMessageBox::Critical);

    msg.setDefaultButton(QMessageBox::Ok);

    msg.exec();
}

void MediaEngine::msgHelp1()
{
    QMessageBox msg(nullptr);

    msg.setAttribute(Qt::WA_DeleteOnClose);

    msg.setWindowTitle("Funzionalità non implementata");

    msg.setText("La funzionalità richiesta non esiste o non è stata implementata");
    msg.setInformativeText("La pagina di aiuto sarà disponibile entro la versione v.1.3");

    msg.setIcon(QMessageBox::Warning);

    msg.setDefaultButton(QMessageBox::Ok);

    msg.exec();
}

///Easter eggs
void MediaEngine::easterEggRichard(bool fullVersion)
{
    QMediaPlayer *player = new QMediaPlayer();
    QVideoWidget *video = new QVideoWidget();
    QAudioOutput *audio = new QAudioOutput();

    player->setVideoOutput(video);
    player->setAudioOutput(audio);
    player->setParent(video);
    player->setSource(QUrl::fromLocalFile(".\\CalcGameReviewITA.media"));

    video->setWindowTitle("Recensione gioco \"calcolatrice\"");
    video->setGeometry(50, 50, 640, 360);
    video->setAttribute(Qt::WA_DeleteOnClose);  //Delete object to prevent memory leak when window is closed

    audio->setVolume(1);
    audio->setParent(video);

    player->play();
    video->show();

    int timer = 29750;

    if(fullVersion)
        timer = 0;

    QObject::connect(player, &QMediaPlayer::mediaStatusChanged, video, [player, timer](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::BufferedMedia) {
            player->setPosition(timer);
        }
    });

    QObject::connect(player, &QMediaPlayer::mediaStatusChanged, video, [video](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            video->close();
        }
    });
}

void MediaEngine::genericHTMLBrowser(QString url)
{
    QTextBrowser *browser = new QTextBrowser();

    browser->setAttribute(Qt::WA_DeleteOnClose);

    browser->setTextInteractionFlags(Qt::TextBrowserInteraction);
    browser->setGeometry(120, 120, 400, 650);

    browser->setSource(QUrl::fromLocalFile(url));
    browser->show();
}


void MediaEngine::genericVideoPlay(QString url)
{
    QMediaPlayer *player = new QMediaPlayer();
    QVideoWidget *video = new QVideoWidget();
    QAudioOutput *audio = new QAudioOutput();
    QUrl fileUrl = QUrl::fromLocalFile(url);

    player->setVideoOutput(video);
    player->setAudioOutput(audio);

    QObject::connect(video, &QObject::destroyed, player, &QObject::deleteLater);
    QObject::connect(video, &QObject::destroyed, audio, &QObject::deleteLater);

    if (fileUrl.isLocalFile() && QFileInfo::exists(fileUrl.toLocalFile())) {
        player->setSource(fileUrl);
    }
    else
    {
        player->deleteLater();
        audio->deleteLater();
        video->deleteLater();
        return;
    }

    video->setWindowTitle("Riproduzione video");
    video->setGeometry(30, 30, 640, 360);
    video->setAttribute(Qt::WA_DeleteOnClose);

    audio->setVolume(1);

    player->play();
    video->show();

    QObject::connect(player, &QMediaPlayer::mediaStatusChanged, video, [video](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            video->close();
        }
    });
}