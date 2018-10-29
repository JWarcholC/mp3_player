#include "mediaplayer.h"
#include "ui_mediaplayer.h"
#include <QFileDialog>

QString MediaPlayer::title = "BogiPlayer";

MediaPlayer::MediaPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaPlayer),
    file("")
{
    ui->setupUi(this);
    media = new QMediaPlayer(this);

    connect(media, &QMediaPlayer::positionChanged, [&](qint64 pos) {
        ui->progressBar->setValue(pos);
    });

    connect(media, &QMediaPlayer::durationChanged, [&](qint64 dur) {
        ui->progressBar->setMaximum(dur);
    });
}

MediaPlayer::~MediaPlayer()
{
    delete ui;
}

void MediaPlayer::on_browse_clicked()
{
    setFileName(QFileDialog::getOpenFileName(this, "Browse"));
    if(file.isEmpty())
        return;

     media->setMedia(QUrl::fromLocalFile(file));
     on_play_clicked();
}

void MediaPlayer::on_play_clicked()
{
    media->play();
    setTitle(MediaPlayer::file);
}

void MediaPlayer::on_pause_clicked()
{
    media->pause();
}

void MediaPlayer::on_stop_clicked()
{
    media->stop();
    setTitle();
}

void MediaPlayer::on_mute_clicked()
{
    if(ui->mute->text() == "Mute") {
        media->setMuted(true);
        ui->mute->setText("Unmute");
    } else {
        media->setMuted(false);
        ui->mute->setText("Mute");
    }
}


void MediaPlayer::on_volume_valueChanged(int value)
{
    media->setVolume(value);
}

void MediaPlayer::setTitle(QString &text) {
    this->setWindowTitle(text);
}


