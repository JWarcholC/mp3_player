#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QWidget>
#include <QMediaPlayer>

namespace Ui {
class MediaPlayer;
}

class MediaPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPlayer(QWidget *parent = nullptr);
    ~MediaPlayer();

private slots:
    void on_browse_clicked();

    void on_play_clicked();

    void on_pause_clicked();

    void on_stop_clicked();

    void on_mute_clicked();

    void on_volume_valueChanged(int value);

private:
    Ui::MediaPlayer *ui;
    QMediaPlayer *media;
    static QString title;
    QString file;

    void setTitle(QString &text = title);
    inline void setFileName(QString text) { file = text; }
};

#endif // MEDIAPLAYER_H
