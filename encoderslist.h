#ifndef ENCODERSLIST_H
#define ENCODERSLIST_H

#include <QWidget>
#include "bass.h"
#include "encoder.h"

namespace Ui {
class EncodersList;
}

class EncodersList : public QWidget
{
    Q_OBJECT
    
public:
    explicit EncodersList(QWidget *parent = 0);
    ~EncodersList();
    void SetMainStream(HSTREAM mains);
    int AddNewEncoder();
    int DeleteEncoder(int enc);

    HSTREAM stream;
    HSTREAM main;
    Encoder*encoder[200];
    int encoders;
    QString MyFile;

    void SetListFile(QString file);
    void LoadConfig();
    void SaveConfig();
    void UpdateInfo();
    void SetEncodersTag(QString tag);
    void StartAll();
    void StopAll();
    bool EncodersWork();

    QString ExtractPParam(QString content,QString key);
    QString AddPParam(QString key,QString value);

    
private:
    Ui::EncodersList *ui;
public slots:
    void OnAddEncoder();
    void OnDeleteEncoder();
    void EncoderStarted(int enc);
    void EncoderStopped(int enc);
    void EncoderError(int enc);
    void OnStartAll();
    void OnStopAll();
signals:
    void OnEncoderError();
};





#endif // ENCODERSLIST_H
