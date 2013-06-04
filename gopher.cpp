#include "gopher.h"
#include "ui_gopher.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QVariant>
#include <QVariantMap>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSettings>
#include <QObject>
#include <QQueue>
#include <QToolBox>
#include <QIcon>
#include <QResource>
#include <QDesktopServices>
#include <QUrl>

Gopher::Gopher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gopher)
{
    ui->setupUi(this);
}

Gopher::~Gopher()
{
    delete ui;
}

void Gopher::on_Cancel_clicked()
{
    close();
}

void Gopher::on_Instrument_currentIndexChanged(int index)
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

    switch (index)
    {
    case 0://Insturments
    {
        //Image Mode
        FillInstrumentsImageMode();
        //Camera
        FillInstrumentsCameras();
        //Aquisition Software
        FillInstrumentsAquisitionSoftware();
    }
        break;
    case 1://H7500
    {
        //Image Mode
        FillH7500ImageModes();
        //Camera
        FillH7500Camera();
        //Aquisition Software
        FillH7500AquisitionSoftware();
    }
        break;
    case 2://SU8000
    {
        //Image Mode
        FillSU8000ImageMode();
        //Camera
        FillSU8000Camera();
        //Aquisition Software
        FillSU8000AquisitionSoftware();
    }
        break;
    case 3://S5200
    {
        //Image Mode
        FillS5200ImageMode();
        //Camera
        FillS5200Camera();
        //Aquisition Software
        FillS5200AquisitionSoftware();
    }
        break;
    case 4://Tecnai-AMT
    {
        //Image Mode
        FillTecnaiAMTImageMode();
        //Camera
        FillTecnaiAMTCamera();
        //Aquisition Software
        FillTecnaiAMTAquisitionSoftware();
    }
        break;
    case 5://Tecnai-Tomo
    {
        //Image Mode
        FillTecnaiTomoImageMode();
        //Camera
        FillTecnaiTomoCamera();
        //Aquisition Software
        FillTecnaiTomoAquisitionSoftware();
    }
        break;
    case 6://Krios
    {
        //Image Mode
        FillKriosImageMode();
        //Camera
        FillKriosCamera();
        //Aquisition Software
        FillKriosAquisitionSoftware();
    }
        break;
    case 7://510 Meta
    {
        //Image Mode
        Fill510MetaImageMode();
    }
        break;
    }
}

void Gopher::on_imageMode_currentIndexChanged(int index)
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    //Switch between the Image Modes
    switch (index)
    {
    case 0://Image Mode
    {
        FillImageMode();
    }
        break;
    case 1://TEM 2D
    {
        FillTEM2D();
    }
        break;
    case 2://TEM Tomo
    {
        FillTEMTomo();
    }
        break;
    case 3://Cryo-TEM 2D / Vitrobot Settings
    {
        FillCryoTEM2D();
    }
        break;
    case 4://Cryo-TEM Tomo / Vitrobot Settings
    {
        FillCryoTEMTomo();
    }
        break;
    case 5://Stem 2D
    {
        FillStem2D();
    }
        break;
    case 6://Stem Tomo
    {
        FillStemTomo();
    }
        break;
    case 7://SEM 2D
    {
        FillSEM2D();
    }
        break;
    case 8://Cryo-SEM / Vitrobot Settings
    {
        FillCryoSEM();
    }
        break;
    case 9://Confocal
    {
       FillConfocal();
    }
        break;

    }
}

void Gopher::on_Done_clicked()
{
    switch (ui->imageMode->currentIndex())
    {
    case 0:
    {
        QMessageBox::warning(0, QString("Gopher"), QString("Please Select Image Mode")
                             , QMessageBox::Ok);
    }
        break;
    case 1://TEM 2D
    {
       SaveTEM2D();
    }
        break;
    case 2://TEM Tomo
    {
       SaveTEMTomo();
    }
        break;
    case 3://Cryo-TEM 2D
    {
       SaveCryoTEM2D();
    }
        break;
    case 4://Cryo-TEM Tomo
    {
        SaveCryoTomo();
    }
        break;
    case 5://Stem 2D
    {
        SaveStem2D();
    }
        break;
    case 6://Stem Tomo
    {
        SaveStemTomo();
    }
        break;
    case 7://SEM 2D
    {
        SaveSEM2D();
    }
        break;
    case 8://Cryo-SEM
    {
        SaveCryoSEM();
    }
        break;
    case 9://Confocal
    {
        SaveConfocal();
    }
        break;
    }
}

void Gopher::on_actionHedwig_triggered()
{
    QDesktopServices::openUrl(QUrl("http://www.google.com"));
}

void Gopher::on_actionImport_triggered()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    list = input.object();
    //Info
    {
       ImportInfo();
    }
    //TEM 2D
    {
       ImportTEM2D();
    }
    //TEM Tomo
    {
        ImportTEMTomo();
    }
    //Cryo-Tem 2D
    {
        //Cryo-Tem Tab
        {
          ImportCryoTEM();
        }
        //Vitrobot Settings Tab
        {
           ImportCryoTEMVitrobotSettings();
        }
    }
    //Cryo-Tem Tomo
    {
        //Cryo-Tem Tomo Tab
        {
           ImportCryoTEMTomo();
        }
        //Vitrobot Settings Tab
        {
            ImportCryoTEMTomoVitrobotSettings();
        }
    }
    //Stem 2D
    {
       ImportStem2D();
    }
    //Stem Tomo
    {
        ImportStemTomo();
    }
    //SEM
    {
       ImportSEM();
    }
    //Cryo-SEM
    {
        //Cryo-SEM Tab
        {
           ImportCryoSEM();
        }
        //vitrobot Tab
        {
          ImportCryoSEMVitrobotSettings();
        }
    }
    //Confocal
    {
        ImportConfocal();
    }
}

void Gopher::on_actionExport_triggered()
{
    on_Done_clicked();
}

void Gopher::on_actionExit_triggered()
{
    exit(0);
}

void Gopher::on_actionAbout_triggered()
{
    QMessageBox::information(0, QString("Gopher"), QString("This program is brought to you by the RML staff.")
                             , QMessageBox::Ok);
}

void Gopher::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                                                    tr(".json"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"),
                                  tr("Could not open file"));
            return;
        }
        QTextStream in(&file);

        file.close();
    }
}

void Gopher::on_actionSave_triggered()
{
    on_Done_clicked();
}
