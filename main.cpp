#include "mediaplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");
    MediaPlayer w;
    w.show();

    return a.exec();
}
