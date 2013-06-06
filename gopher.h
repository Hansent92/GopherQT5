#ifndef GOPHER_H
#define GOPHER_H

#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>

namespace Ui
{
class Gopher;
}

class Gopher : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Gopher(QWidget *parent = 0);
    ~Gopher();

    Ui::Gopher* ui;
    
private slots:
    void on_Cancel_clicked();

    void on_Done_clicked();

    void on_imageMode_currentIndexChanged(int index);

    void on_Instrument_currentIndexChanged(int index);

    void on_actionHedwig_triggered();

    void on_actionImport_triggered();

    void on_actionExport_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:


    QJsonObject* sessionObject;
    QJsonObject list;\
    QJsonObject header;

    QJsonDocument* file;

    //Instrument Function
    void FillInstrumentsImageMode();
    void FillInstrumentsCameras();
    void FillInstrumentsAquisitionSoftware();

    void FillH7500ImageModes();
    void FillH7500Camera();
    void FillH7500AquisitionSoftware();

    void FillSU8000ImageMode();
    void FillSU8000Camera();
    void FillSU8000AquisitionSoftware();

    void FillS5200ImageMode();
    void FillS5200Camera();
    void FillS5200AquisitionSoftware();

    void FillTecnaiAMTImageMode();
    void FillTecnaiAMTCamera();
    void FillTecnaiAMTAquisitionSoftware();

    void FillTecnaiTomoImageMode();
    void FillTecnaiTomoCamera();
    void FillTecnaiTomoAquisitionSoftware();

    void FillKriosImageMode();
    void FillKriosCamera();
    void FillKriosAquisitionSoftware();

    void Fill510MetaImageMode();

    //Image Mode Function
    void FillImageMode();
    void FillTEM2D();
    void FillTEMTomo();
    void FillCryoTEM2D();
    void FillCryoTEMTomo();
    void FillStem2D();
    void FillStemTomo();
    void FillSEM2D();
    void FillCryoSEM();
    void FillConfocal();

    //Save Function
    void SaveTEM2D();
    void SaveTEMTomo();
    void SaveCryoTEM2D();
    void SaveCryoTomo();
    void SaveStem2D();
    void SaveStemTomo();
    void SaveSEM2D();
    void SaveCryoSEM();
    void SaveConfocal();

    //Import Function
    void ImportInfo();
    void ImportTEM2D();
    void ImportTEMTomo();
    void ImportCryoTEM();
    void ImportCryoTEMVitrobotSettings();
    void ImportCryoTEMTomo();
    void ImportCryoTEMTomoVitrobotSettings();
    void ImportStem2D();
    void ImportStemTomo();
    void ImportSEM();
    void ImportCryoSEM();
    void ImportCryoSEMVitrobotSettings();
    void ImportConfocal();

};

#endif // GOPHER_H
