#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QWidget>
#include <QFile>

namespace Ui {
class Configure;
}

class Configure : public QWidget
{
    Q_OBJECT
    
public:
    explicit Configure(QWidget *parent = 0);
    ~Configure();
    void LoadConfig();
    void SaveConfig();
    QString MyFile;


    int TransType();
    int TT();
    int ST();

public slots:
    void OnSaveBut();
    void OnResetBut();

private:
    Ui::Configure *ui;
    static QString ExtractPParam(QString content,QString key);
    static QString AddPParam(QString key,QString value);
};

#endif // CONFIGURE_H
