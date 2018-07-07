//#include <QtGui/QApplication>
 #include <QApplication>
#include "mbcwindow.h"
#include "bass.h"
#include <QTextCodec>
#include <QLocale>

int main(int argc, char *argv[])
{

//    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("System"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("System"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("System"));


    if(!BASS_Init(-1, 44100, 0,0, NULL))
    {
        //cout<< "  *ERROR: Can't init BASS\n Error " << BASS_ErrorGetCode();
        return 1;
    }

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/icon.png"));
    //QApplication::setWindowIcon(QIcon(":/icon.png"));

    MBCWindow w;
    w.show();
    
    return a.exec();
}
