#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QWidget>
#include <QMediaPlayer>

#ifdef __WIN32__
    #define SPLIT_SIGN "\\"
#else
    #define SPLIT_SIGN "/"
#endif

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

    void setTitle(const QString text);
    inline void setFileName(QString text) { file = text; }
    QString splitTitle(QString text);

};

#endif // MEDIAPLAYER_H
