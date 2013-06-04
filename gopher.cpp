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

void Gopher::FillH7500ImageModes() {

    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

    QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
    ui->imageMode->model()->setData(index1, m, Qt::UserRole -1);
    QModelIndex index2 = ui->imageMode->model()->index(2,0);//Tem Tomo
    ui->imageMode->model()->setData(index2, v, Qt::UserRole -1);
    QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryp-Tem-2D
    ui->imageMode->model()->setData(index3, v, Qt::UserRole -1);
    QModelIndex index4 = ui->imageMode->model()->index(4,0);//Cryo-Tem-Tomo
    ui->imageMode->model()->setData(index4, v, Qt::UserRole -1);
    QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
    ui->imageMode->model()->setData(index5, v, Qt::UserRole -1);
    QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
    ui->imageMode->model()->setData(index6, v, Qt::UserRole -1);
    QModelIndex index7 = ui->imageMode->model()->index(7,0);//Sem 2D
    ui->imageMode->model()->setData(index7, v, Qt::UserRole -1);
    QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-Sem
    ui->imageMode->model()->setData(index8, v, Qt::UserRole -1);
    QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
    ui->imageMode->model()->setData(index9, v, Qt::UserRole -1);

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
        {
            QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
            ui->imageMode->model()->setData(index1, m, Qt::UserRole -1);
            QModelIndex index2 = ui->imageMode->model()->index(2,0);//Tem Tomo
            ui->imageMode->model()->setData(index2, m, Qt::UserRole -1);
            QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryp-Tem-2D
            ui->imageMode->model()->setData(index3, m, Qt::UserRole -1);
            QModelIndex index4 = ui->imageMode->model()->index(4,0);//Cryo-Tem-Tomo
            ui->imageMode->model()->setData(index4, m, Qt::UserRole -1);
            QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
            ui->imageMode->model()->setData(index5, m, Qt::UserRole -1);
            QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
            ui->imageMode->model()->setData(index6, m, Qt::UserRole -1);
            QModelIndex index7 = ui->imageMode->model()->index(7,0);//Sem 2D
            ui->imageMode->model()->setData(index7, m, Qt::UserRole -1);
            QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-Sem
            ui->imageMode->model()->setData(index8, m, Qt::UserRole -1);
            QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
            ui->imageMode->model()->setData(index9, m, Qt::UserRole -1);
        }
        //Camera
        {
            QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
            ui->Camera->model()->setData(index1, m, Qt::UserRole -1);
            QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
            ui->Camera->model()->setData(index2, m, Qt::UserRole -1);
            QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
            ui->Camera->model()->setData(index3, m, Qt::UserRole -1);
            QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
            ui->Camera->model()->setData(index4, m, Qt::UserRole -1);
        }
        //Aquisition Software
        {

            QModelIndex index1 = ui->AquisitionSoftware->model()->index(1,0);//AMT
            ui->AquisitionSoftware->model()->setData(index1, m, Qt::UserRole -1);
            QModelIndex index2 = ui->AquisitionSoftware->model()->index(2,0);//Digital Micrograph
            ui->AquisitionSoftware->model()->setData(index2, m, Qt::UserRole -1);
            QModelIndex index3 = ui->AquisitionSoftware->model()->index(3,0);//Xplore3D
            ui->AquisitionSoftware->model()->setData(index3, m, Qt::UserRole -1);
            QModelIndex index4 = ui->AquisitionSoftware->model()->index(4,0);//TIA
            ui->AquisitionSoftware->model()->setData(index4, m, Qt::UserRole -1);
            QModelIndex index5 = ui->AquisitionSoftware->model()->index(5,0);//EPU
            ui->AquisitionSoftware->model()->setData(index5, m, Qt::UserRole -1);
            QModelIndex index6 = ui->AquisitionSoftware->model()->index(6,0);//Hitachi SEM
            ui->AquisitionSoftware->model()->setData(index6, m, Qt::UserRole -1);
        }
    }
        break;
    case 1://H7500
    {
        //Image Mode
        FillH7500ImageModes();
        //Camera
        {
            QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
            ui->Camera->model()->setData(index1, m, Qt::UserRole -1);
            QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
            ui->Camera->model()->setData(index2, v, Qt::UserRole -1);
            QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
            ui->Camera->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
            ui->Camera->model()->setData(index4, v, Qt::UserRole -1);
        }
        //Aquisition Software
        {
            QModelIndex index1 = ui->AquisitionSoftware->model()->index(1,0);//AMT
            ui->AquisitionSoftware->model()->setData(index1, m, Qt::UserRole -1);
            QModelIndex index2 = ui->AquisitionSoftware->model()->index(2,0);//Digital Micrograph
            ui->AquisitionSoftware->model()->setData(index2, v, Qt::UserRole -1);
            QModelIndex index3 = ui->AquisitionSoftware->model()->index(3,0);//Xplore3D
            ui->AquisitionSoftware->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->AquisitionSoftware->model()->index(4,0);//TIA
            ui->AquisitionSoftware->model()->setData(index4, v, Qt::UserRole -1);
            QModelIndex index5 = ui->AquisitionSoftware->model()->index(5,0);//EPU
            ui->AquisitionSoftware->model()->setData(index5, v, Qt::UserRole -1);
            QModelIndex index6 = ui->AquisitionSoftware->model()->index(6,0);//Hitachi SEM
            ui->AquisitionSoftware->model()->setData(index6, v, Qt::UserRole -1);
        }
    }
        break;
    case 2://SU8000
    {
        //Image Mode
        {
            QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
            ui->imageMode->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomo
            ui->imageMode->model()->setData(index2, v, Qt::UserRole -1);
            QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-Tem-2d
            ui->imageMode->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->imageMode->model()->index(4,0);//cryo-tem-tomo
            ui->imageMode->model()->setData(index4, v, Qt::UserRole -1);
            QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
            ui->imageMode->model()->setData(index5, m, Qt::UserRole -1);
            QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
            ui->imageMode->model()->setData(index6, v, Qt::UserRole -1);
            QModelIndex index7 = ui->imageMode->model()->index(7,0);//Sem 2D
            ui->imageMode->model()->setData(index7, m, Qt::UserRole -1);
            QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-Sem
            ui->imageMode->model()->setData(index8, v, Qt::UserRole -1);
            QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
            ui->imageMode->model()->setData(index9, v, Qt::UserRole -1);
        }
        //Camera
        {
            QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
            ui->Camera->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
            ui->Camera->model()->setData(index2, v, Qt::UserRole -1);
            QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
            ui->Camera->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
            ui->Camera->model()->setData(index4, v, Qt::UserRole -1);
        }
        //Aquisition Software
        {
            QModelIndex index1 = ui->AquisitionSoftware->model()->index(1,0);//AMT
            ui->AquisitionSoftware->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->AquisitionSoftware->model()->index(2,0);//Digital Micrograph
            ui->AquisitionSoftware->model()->setData(index2, v, Qt::UserRole -1);
            QModelIndex index3 = ui->AquisitionSoftware->model()->index(3,0);//Xplore3D
            ui->AquisitionSoftware->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->AquisitionSoftware->model()->index(4,0);//TIA
            ui->AquisitionSoftware->model()->setData(index4, v, Qt::UserRole -1);
            QModelIndex index5 = ui->AquisitionSoftware->model()->index(5,0);//EPU
            ui->AquisitionSoftware->model()->setData(index5, v, Qt::UserRole -1);
            QModelIndex index6 = ui->AquisitionSoftware->model()->index(6,0);//Hitachi SEM
            ui->AquisitionSoftware->model()->setData(index6, m, Qt::UserRole -1);
        }
    }
        break;
    case 3://S5200
    {
        //Image Mode
        {
            QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
            ui->imageMode->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomo
            ui->imageMode->model()->setData(index2, v, Qt::UserRole -1);
            QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-Tem-2d
            ui->imageMode->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->imageMode->model()->index(4,0);//cryo-tem-tomo
            ui->imageMode->model()->setData(index4, v, Qt::UserRole -1);
            QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
            ui->imageMode->model()->setData(index5, v, Qt::UserRole -1);
            QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
            ui->imageMode->model()->setData(index6, v, Qt::UserRole -1);
            QModelIndex index7 = ui->imageMode->model()->index(7,0);//Sem 2D
            ui->imageMode->model()->setData(index7, m, Qt::UserRole -1);
            QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-Sem
            ui->imageMode->model()->setData(index8, m, Qt::UserRole -1);
            QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
            ui->imageMode->model()->setData(index9, v, Qt::UserRole -1);
        }
        //Camera
        {
            QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
            ui->Camera->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
            ui->Camera->model()->setData(index2, v, Qt::UserRole -1);
            QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
            ui->Camera->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
            ui->Camera->model()->setData(index4, v, Qt::UserRole -1);
        }
        //Aquisition Software
        {
            QModelIndex index1 = ui->AquisitionSoftware->model()->index(1,0);//AMT
            ui->AquisitionSoftware->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->AquisitionSoftware->model()->index(2,0);//Digital Micrograph
            ui->AquisitionSoftware->model()->setData(index2, v, Qt::UserRole -1);
            QModelIndex index3 = ui->AquisitionSoftware->model()->index(3,0);//Xplore3D
            ui->AquisitionSoftware->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->AquisitionSoftware->model()->index(4,0);//TIA
            ui->AquisitionSoftware->model()->setData(index4, v, Qt::UserRole -1);
            QModelIndex index5 = ui->AquisitionSoftware->model()->index(5,0);//EPU
            ui->AquisitionSoftware->model()->setData(index5, v, Qt::UserRole -1);
            QModelIndex index6 = ui->AquisitionSoftware->model()->index(6,0);//Hitachi SEM
            ui->AquisitionSoftware->model()->setData(index6, m, Qt::UserRole -1);
        }
    }
        break;
    case 4://Tecnai-AMT
    {
        //Image Mode
        {
            QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
            ui->imageMode->model()->setData(index1, m, Qt::UserRole -1);
            QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomo
            ui->imageMode->model()->setData(index2, m, Qt::UserRole -1);
            QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-Tem-2d
            ui->imageMode->model()->setData(index3, m, Qt::UserRole -1);
            QModelIndex index4 = ui->imageMode->model()->index(4,0);//cryo-tem-tomo
            ui->imageMode->model()->setData(index4, v, Qt::UserRole -1);
            QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
            ui->imageMode->model()->setData(index5, v, Qt::UserRole -1);
            QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
            ui->imageMode->model()->setData(index6, v, Qt::UserRole -1);
            QModelIndex index7 = ui->imageMode->model()->index(7,0);//Sem 2D
            ui->imageMode->model()->setData(index7, v, Qt::UserRole -1);
            QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-Sem
            ui->imageMode->model()->setData(index8, v, Qt::UserRole -1);
            QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
            ui->imageMode->model()->setData(index9, v, Qt::UserRole -1);
        }
        //Camera
        {
            QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
            ui->Camera->model()->setData(index1, m, Qt::UserRole -1);
            QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
            ui->Camera->model()->setData(index2, m, Qt::UserRole -1);
            QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
            ui->Camera->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
            ui->Camera->model()->setData(index4, v, Qt::UserRole -1);
        }
        //Aquisition Software
        {
            QModelIndex index1 = ui->AquisitionSoftware->model()->index(1,0);//AMT
            ui->AquisitionSoftware->model()->setData(index1, m, Qt::UserRole -1);
            QModelIndex index2 = ui->AquisitionSoftware->model()->index(2,0);//Digital Micrograph
            ui->AquisitionSoftware->model()->setData(index2, m, Qt::UserRole -1);
            QModelIndex index3 = ui->AquisitionSoftware->model()->index(3,0);//Xplore3D
            ui->AquisitionSoftware->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->AquisitionSoftware->model()->index(4,0);//TIA
            ui->AquisitionSoftware->model()->setData(index4, v, Qt::UserRole -1);
            QModelIndex index5 = ui->AquisitionSoftware->model()->index(5,0);//EPU
            ui->AquisitionSoftware->model()->setData(index5, v, Qt::UserRole -1);
            QModelIndex index6 = ui->AquisitionSoftware->model()->index(6,0);//Hitachi SEM
            ui->AquisitionSoftware->model()->setData(index6, v, Qt::UserRole -1);
        }
    }
        break;
    case 5://Tecnai-Tomo
    {
        //Image Mode
        {
            QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
            ui->imageMode->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomo
            ui->imageMode->model()->setData(index2, m, Qt::UserRole -1);
            QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-Tem-2d
            ui->imageMode->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->imageMode->model()->index(4,0);//cryo-tem-tomo
            ui->imageMode->model()->setData(index4, m, Qt::UserRole -1);
            QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
            ui->imageMode->model()->setData(index5, v, Qt::UserRole -1);
            QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
            ui->imageMode->model()->setData(index6, v, Qt::UserRole -1);
            QModelIndex index7 = ui->imageMode->model()->index(7,0);//Sem 2D
            ui->imageMode->model()->setData(index7, v, Qt::UserRole -1);
            QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-Sem
            ui->imageMode->model()->setData(index8, v, Qt::UserRole -1);
            QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
            ui->imageMode->model()->setData(index9, v, Qt::UserRole -1);
        }
        //Camera
        {
            QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
            ui->Camera->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
            ui->Camera->model()->setData(index2, m, Qt::UserRole -1);
            QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
            ui->Camera->model()->setData(index3, v, Qt::UserRole -1);
            QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
            ui->Camera->model()->setData(index4, v, Qt::UserRole -1);
        }
        //Aquisition Software
        {
            QModelIndex index1 = ui->AquisitionSoftware->model()->index(1,0);//AMT
            ui->AquisitionSoftware->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->AquisitionSoftware->model()->index(2,0);//Digital Micrograph
            ui->AquisitionSoftware->model()->setData(index2, v, Qt::UserRole -1);
            QModelIndex index3 = ui->AquisitionSoftware->model()->index(3,0);//Xplore3D
            ui->AquisitionSoftware->model()->setData(index3, m, Qt::UserRole -1);
            QModelIndex index4 = ui->AquisitionSoftware->model()->index(4,0);//TIA
            ui->AquisitionSoftware->model()->setData(index4, v, Qt::UserRole -1);
            QModelIndex index5 = ui->AquisitionSoftware->model()->index(5,0);//EPU
            ui->AquisitionSoftware->model()->setData(index5, v, Qt::UserRole -1);
            QModelIndex index6 = ui->AquisitionSoftware->model()->index(6,0);//Hitachi SEM
            ui->AquisitionSoftware->model()->setData(index6, v, Qt::UserRole -1);
        }
    }
        break;
    case 6://Krios
    {
        //Image Mode
        {
            QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
            ui->imageMode->model()->setData(index1, m, Qt::UserRole -1);
            QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomo
            ui->imageMode->model()->setData(index2, m, Qt::UserRole -1);
            QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-Tem-2d
            ui->imageMode->model()->setData(index3, m, Qt::UserRole -1);
            QModelIndex index4 = ui->imageMode->model()->index(4,0);//cryo-tem-tomo
            ui->imageMode->model()->setData(index4, m, Qt::UserRole -1);
            QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
            ui->imageMode->model()->setData(index5, m, Qt::UserRole -1);
            QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
            ui->imageMode->model()->setData(index6, m, Qt::UserRole -1);
            QModelIndex index7 = ui->imageMode->model()->index(7,0);//Sem 2D
            ui->imageMode->model()->setData(index7, v, Qt::UserRole -1);
            QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-Sem
            ui->imageMode->model()->setData(index8, v, Qt::UserRole -1);
            QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
            ui->imageMode->model()->setData(index9, v, Qt::UserRole -1);
        }
        //Camera
        {
            QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
            ui->Camera->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
            ui->Camera->model()->setData(index2, v, Qt::UserRole -1);
            QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
            ui->Camera->model()->setData(index3, m, Qt::UserRole -1);
            QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
            ui->Camera->model()->setData(index4, m, Qt::UserRole -1);
        }
        //Aquisition Software
        {
            QModelIndex index1 = ui->AquisitionSoftware->model()->index(1,0);//AMT
            ui->AquisitionSoftware->model()->setData(index1, v, Qt::UserRole -1);
            QModelIndex index2 = ui->AquisitionSoftware->model()->index(2,0);//Digital Micrograph
            ui->AquisitionSoftware->model()->setData(index2, m, Qt::UserRole -1);
            QModelIndex index3 = ui->AquisitionSoftware->model()->index(3,0);//Xplore3D
            ui->AquisitionSoftware->model()->setData(index3, m, Qt::UserRole -1);
            QModelIndex index4 = ui->AquisitionSoftware->model()->index(4,0);//TIA
            ui->AquisitionSoftware->model()->setData(index4, m, Qt::UserRole -1);
            QModelIndex index5 = ui->AquisitionSoftware->model()->index(5,0);//EPU
            ui->AquisitionSoftware->model()->setData(index5, m, Qt::UserRole -1);
            QModelIndex index6 = ui->AquisitionSoftware->model()->index(6,0);//Hitachi SEM
            ui->AquisitionSoftware->model()->setData(index6, v, Qt::UserRole -1);
        }
    }
        break;
    case 7://510 Meta
    {
        QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
        ui->imageMode->model()->setData(index1, v, Qt::UserRole -1);
        QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomo
        ui->imageMode->model()->setData(index2, v, Qt::UserRole -1);
        QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-Tem-2d
        ui->imageMode->model()->setData(index3, v, Qt::UserRole -1);
        QModelIndex index4 = ui->imageMode->model()->index(4,0);//cryo-tem-tomo
        ui->imageMode->model()->setData(index4, v, Qt::UserRole -1);
        QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
        ui->imageMode->model()->setData(index5, v, Qt::UserRole -1);
        QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
        ui->imageMode->model()->setData(index6, v, Qt::UserRole -1);
        QModelIndex index7 = ui->imageMode->model()->index(7,0);//Sem 2D
        ui->imageMode->model()->setData(index7, v, Qt::UserRole -1);
        QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-Sem
        ui->imageMode->model()->setData(index8, v, Qt::UserRole -1);
        QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
        ui->imageMode->model()->setData(index9, m, Qt::UserRole -1);
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
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(0);
    }
        break;
    case 1://TEM 2D
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->tem2D_Toolbox->setItemIcon(0,QIcon(pointer));
    }
        break;
    case 2://TEM Tomo
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->temTomo_Toolbox->setItemIcon(0,QIcon(pointer));
    }
        break;
    case 3://Cryo-TEM 2D / Vitrobot Settings
    {
        ui->stackedWidget->setCurrentIndex(3);
        ui->cryoTem2D_Toolbox->setCurrentIndex(1);
        ui->cryoTem2D_Toolbox->setItemIcon(0,QIcon(pointer));
        ui->cryoTem2D_Toolbox->setItemIcon(1,QIcon(pointer));
    }
        break;
    case 4://Cryo-TEM Tomo / Vitrobot Settings
    {
        ui->stackedWidget->setCurrentIndex(4);
        ui->cryoTEMTomo_Toolbox->setCurrentIndex(1);
        ui->cryoTEMTomo_Toolbox->setItemIcon(0,QIcon(pointer));
        ui->cryoTEMTomo_Toolbox->setItemIcon(1,QIcon(pointer));
    }
        break;
    case 5://Stem 2D
    {
        ui->stackedWidget->setCurrentIndex(5);
        ui->stem2D_Toolbox->setItemIcon(0,QIcon(pointer));
    }
        break;
    case 6://Stem Tomo
    {
        ui->stackedWidget->setCurrentIndex(6);
        ui->stemTomo_Toolbox->setItemIcon(0,QIcon(pointer));
    }
        break;
    case 7://SEM 2D
    {
        ui->stackedWidget->setCurrentIndex(7);
        ui->sem2D_Toolbox->setItemIcon(0,QIcon(pointer));
    }
        break;
    case 8://Cryo-SEM / Vitrobot Settings
    {
        ui->stackedWidget->setCurrentIndex(8);
        ui->cryoSEM_Toolbox->setCurrentIndex(1);
        ui->cryoSEM_Toolbox->setItemIcon(0,QIcon(pointer));
        ui->cryoSEM_Toolbox->setItemIcon(1,QIcon(pointer));
    }
        break;
    case 9://Confocal
    {
        ui->stackedWidget->setCurrentIndex(9);
        ui->confocal_Toolbox->setItemIcon(0,QIcon(pointer));
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
        QJsonObject list;

        QJsonObject sessionObject;//Intro
        sessionObject.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionObject.insert("Project ID", ui->ProjectID->displayText());
        sessionObject.insert("Subset ID", ui->SubsetID->displayText());
        sessionObject.insert("Instrument", ui->Instrument->currentText());
        sessionObject.insert("Image Mode", ui->imageMode->currentText());
        sessionObject.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionObject.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionObject.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionObject.insert("Notes", ui->NotesText->toPlainText());
        sessionObject.insert("Camera", ui->Camera->currentText());
        sessionObject.insert("Acquisition Software", ui->AquisitionSoftware->currentText());

        list.insert("Info",sessionObject);

        QJsonObject sessionObject3;//TEM 2D
        sessionObject3.insert("Camera", ui->Camera_TEM2D_2->currentText());
        sessionObject3.insert("Energy Filter Slit Size", ui->EnergyFilterSlitSize_Text_TEM2D_2->displayText());
        sessionObject3.insert("Acquisition Software",ui->AcquisitionSoftware_TEM2D_2->currentText());
        sessionObject3.insert("Voltage",ui->Voltage_Text_TEM2D_2->displayText());
        sessionObject3.insert("Cs Value",ui->CsValue_Text_TEM2D_2->displayText());

        list.insert("TEM 2D",sessionObject3);

        QJsonDocument doc = QJsonDocument(list);
        doc.setObject(list);

        QFile file;
        QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"Text Files (*.json)");
        QFileDialog::DialogLabel::FileType;
        file.setFileName(filename);
        if(file.open(QFile::ReadOnly | QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            file.write(doc.toJson());
            file.close();
        }

        QMessageBox::information(0, QString("Gopher"), QString("You Were Successful!")
                                 , QMessageBox::Ok);
        exit(0);
    }
        break;
    case 2://TEM Tomo
    {
        QJsonObject list;

        QJsonObject sessionObject;//Intro
        sessionObject.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionObject.insert("Project ID", ui->ProjectID->displayText());
        sessionObject.insert("Subset ID", ui->SubsetID->displayText());
        sessionObject.insert("Instrument", ui->Instrument->currentText());
        sessionObject.insert("Image Mode", ui->imageMode->currentText());
        sessionObject.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionObject.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionObject.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionObject.insert("Notes", ui->NotesText->toPlainText());
        sessionObject.insert("Camera", ui->Camera->currentText());
        sessionObject.insert("Acquisition Software", ui->AquisitionSoftware->currentText());

        list.insert("Info",sessionObject);

        QJsonObject sessionObject4;//TEM Tomo
        sessionObject4.insert("Actual Specimen Thickness",ui->MaxSpecimenThickness_Text_TEMTomo_2->displayText());
        sessionObject4.insert("Max Fiducial Size",ui->MaxFiducialSize_Text_TEMTomo_2->displayText());
        sessionObject4.insert("Camera",ui->Camera_TEMTomo_2->currentText());
        sessionObject4.insert("Energy Filter Slit Size",ui->EnergyFilterSlitSize_Text_TEMTomo_2->displayText());
        sessionObject4.insert("Acquisition Software",ui->AcquisitionSoftware_TEMTomo_2->currentText());
        sessionObject4.insert("Voltage",ui->Voltage_Text_TEMTomo_2->displayText());
        sessionObject4.insert("Cs Value",ui->CsValue_Text_TEMTomo_2->displayText());

        list.insert("TEM Tomo", sessionObject4);

        QJsonDocument doc = QJsonDocument(list);
        doc.setObject(list);

        QFile file;
        QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"Text Files (*.json)");
        QFileDialog::DialogLabel::FileType;
        file.setFileName(filename);
        if(file.open(QFile::ReadOnly | QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            file.write(doc.toJson());
            file.close();
        }

        QMessageBox::information(0, QString("Gopher"), QString("You Were Successful!")
                                 , QMessageBox::Ok);
        exit(0);
    }
        break;
    case 3://Cryo-TEM 2D
    {
        QJsonObject list;

        QJsonObject sessionObject;//Intro
        sessionObject.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionObject.insert("Project ID", ui->ProjectID->displayText());
        sessionObject.insert("Subset ID", ui->SubsetID->displayText());
        sessionObject.insert("Instrument", ui->Instrument->currentText());
        sessionObject.insert("Image Mode", ui->imageMode->currentText());
        sessionObject.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionObject.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionObject.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionObject.insert("Notes", ui->NotesText->toPlainText());
        sessionObject.insert("Camera", ui->Camera->currentText());
        sessionObject.insert("Acquisition Software", ui->AquisitionSoftware->currentText());

        list.insert("Info",sessionObject);

        QJsonObject sessionObject5;//Cryo-TEM 2D
        sessionObject5.insert("Dose",ui->Dose_Text_CryoTEM2D_2->displayText());
        sessionObject5.insert("Camera",ui->Camera_CryoTEM2D_2->currentText());
        sessionObject5.insert("Energy Filter Slit Size",ui->EnergyFilterSlitSize_Text_CryoTEM2D_3->displayText());
        sessionObject5.insert("Acquisition Software",ui->AcquisitionSoftware_CryoTEM2D_2->currentText());
        sessionObject5.insert("Voltage",ui->Voltage_Text_CryoTEM2D_2->displayText());
        sessionObject5.insert("Cs Value",ui->CsValue_Text_CryoTEM2D_2->displayText());

        list.insert("Cryo-TEM 2D", sessionObject5);

        QJsonObject sessionObject2;//Vitrobot Settings
        sessionObject2.insert("Blot Force",ui->BlotForceText_VitrobotSettings_2->displayText());
        sessionObject2.insert("Blot Time",ui->BlotText_VitrobotSettings_2->displayText());
        sessionObject2.insert("Drain", ui->DrainText_VitrobotSettings_2->displayText());
        sessionObject2.insert("Wait",ui->WaitText_VitrobotSettings_2->displayText());
        sessionObject2.insert("Humidity Set",ui->HumiditySetText_VitrobotSettings_2->displayText());
        sessionObject2.insert("Actual Humidity",ui->ActualText_VitrobotSettings_2->displayText());

        list.insert("Vitrobot Settings", sessionObject2);

        QJsonDocument doc = QJsonDocument(list);
        doc.setObject(list);

        QFile file;
        QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"Text Files (*.json)");
        QFileDialog::DialogLabel::FileType;
        file.setFileName(filename);
        if(file.open(QFile::ReadOnly | QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            file.write(doc.toJson());
            file.close();
        }

        QMessageBox::information(0, QString("Gopher"), QString("You Were Successful!")
                                 , QMessageBox::Ok);
        exit(0);
    }
        break;
    case 4://Cryo-TEM Tomo
    {
        QJsonObject list;

        QJsonObject sessionObject;//Intro
        sessionObject.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionObject.insert("Project ID", ui->ProjectID->displayText());
        sessionObject.insert("Subset ID", ui->SubsetID->displayText());
        sessionObject.insert("Instrument", ui->Instrument->currentText());
        sessionObject.insert("Image Mode", ui->imageMode->currentText());
        sessionObject.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionObject.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionObject.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionObject.insert("Notes", ui->NotesText->toPlainText());
        sessionObject.insert("Camera", ui->Camera->currentText());
        sessionObject.insert("Acquisition Software", ui->AquisitionSoftware->currentText());

        list.insert("Info",sessionObject);

        QJsonObject sessionObject11;//Cryo-TEM Tomo
        sessionObject11.insert("Max Specimen Thickness",ui->MaxSpecimenThickness_Text_CryoTomo_2->displayText());
        sessionObject11.insert("Max Fiducial Size",ui->MaxFidecialSize_Text_CryoTomo_2->displayText());
        sessionObject11.insert("Dose",ui->Dose_Text_CryoTomo_2->displayText());
        sessionObject11.insert("Camera",ui->Camera_CryoTEMTomo_2->currentText());
        sessionObject11.insert("Energy Filter Slit Size",ui->EnergyFilterSlitSize_Text_CryoTomo_2->displayText());
        sessionObject11.insert("Acquisition Software",ui->AcquisitionSoftware_CryoTomo_2->currentText());
        sessionObject11.insert("Cs Value",ui->CsValue_Text_CryoTomo_2->displayText());
        sessionObject11.insert("Voltage",ui->Voltage_Text_CryoTomo_2->displayText());

        list.insert("Cryo-TEM Tomo", sessionObject11);

        QJsonObject sessionObject2;//Vitrobot Settings
        sessionObject2.insert("Blot Force",ui->BlotForceText_VitrobotSettings_3->displayText());
        sessionObject2.insert("Blot Time",ui->BlotText_VitrobotSettings_3->displayText());
        sessionObject2.insert("Drain", ui->DrainText_VitrobotSettings_3->displayText());
        sessionObject2.insert("Wait",ui->WaitText_VitrobotSettings_3->displayText());
        sessionObject2.insert("Humidity Set",ui->HumiditySetText_VitrobotSettings_3->displayText());
        sessionObject2.insert("Actual Humidity",ui->ActualText_VitrobotSettings_3->displayText());

        list.insert("Vitrobot Settings", sessionObject2);

        QJsonDocument doc = QJsonDocument(list);
        doc.setObject(list);

        QFile file;
        QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"Text Files (*.json)");
        QFileDialog::DialogLabel::FileType;
        file.setFileName(filename);
        if(file.open(QFile::ReadOnly | QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            file.write(doc.toJson());
            file.close();
        }

        QMessageBox::information(0, QString("Gopher"), QString("You Were Successful!")
                                 , QMessageBox::Ok);
        exit(0);
    }
        break;
    case 5://Stem 2D
    {
        QJsonObject list;

        QJsonObject sessionObject;//Intro
        sessionObject.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionObject.insert("Project ID", ui->ProjectID->displayText());
        sessionObject.insert("Subset ID", ui->SubsetID->displayText());
        sessionObject.insert("Instrument", ui->Instrument->currentText());
        sessionObject.insert("Image Mode", ui->imageMode->currentText());
        sessionObject.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionObject.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionObject.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionObject.insert("Notes", ui->NotesText->toPlainText());
        sessionObject.insert("Camera", ui->Camera->currentText());
        sessionObject.insert("Acquisition Software", ui->AquisitionSoftware->currentText());

        list.insert("Info",sessionObject);

        QJsonObject sessionObject6;//Stem 2D
        sessionObject6.insert("Spot Size",ui->SpotSizeText_STEM2D_2->displayText());
        sessionObject6.insert("Dwell Time",ui->DwellTimeText_STEM2D_2->displayText());
        sessionObject6.insert("Current(I)",ui->I_Text_STEM2D_2->displayText());
        sessionObject6.insert("Convergence Angle",ui->ConvergenceAngle_Text_STEM2D_2->displayText());
        sessionObject6.insert("Probe Mode Microprobe",ui->Microprobe_STEM2D_2->checkState());
        sessionObject6.insert("Probe Mode Nanoprobe",ui->NanoProbe_STEM2D_2->checkState());
        sessionObject6.insert("Camera Length", ui->CameraLengthText_STEM2D_2->displayText());
        sessionObject6.insert("Acquisition Software",ui->AcquisitionSoftware_STEM2D_2->currentText());
        sessionObject6.insert("Nominal Magnification",ui->NominalMagnification_Text_STEM2D_2->displayText());

        list.insert("Stem 2D", sessionObject6);

        QJsonDocument doc = QJsonDocument(list);
        doc.setObject(list);

        //("c:/Users/hansentd/Desktop/Gopher4/Tests/myFile2.json")
        QFile file;
        QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"Text Files (*.json)");
        QFileDialog::DialogLabel::FileType;
        file.setFileName(filename);
        if(file.open(QFile::ReadOnly | QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            file.write(doc.toJson());
            file.close();
        }

        QMessageBox::information(0, QString("Gopher"), QString("You Were Successful!")
                                 , QMessageBox::Ok);
        exit(0);
    }
        break;
    case 6://Stem Tomo
    {
        QJsonObject list;

        QJsonObject sessionObject;//Intro
        sessionObject.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionObject.insert("Project ID", ui->ProjectID->displayText());
        sessionObject.insert("Subset ID", ui->SubsetID->displayText());
        sessionObject.insert("Instrument", ui->Instrument->currentText());
        sessionObject.insert("Image Mode", ui->imageMode->currentText());
        sessionObject.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionObject.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionObject.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionObject.insert("Notes", ui->NotesText->toPlainText());
        sessionObject.insert("Camera", ui->Camera->currentText());
        sessionObject.insert("Acquisition Software", ui->AquisitionSoftware->currentText());

        list.insert("Info",sessionObject);

        QJsonObject sessionObject7;//Stem Tomo
        sessionObject7.insert("Max Section Thickness",ui->MaxSectionThickness_Text_STEMTomo_2->displayText());
        sessionObject7.insert("Max Fiducial Size",ui->MaxFiducialSize_Text_STEMTomo_2->displayText());
        sessionObject7.insert("Spot Size",ui->SpotSize_Text_STEMTomo_2->displayText());
        sessionObject7.insert("Dwell Time",ui->DwellTime_Text_STEMTomo_2->displayText());
        sessionObject7.insert("Current(I)",ui->I_Text_STEMTomo_2->displayText());
        sessionObject7.insert("Convergence Angle",ui->ConvergenceAngle_Text_STEMTomo_2->displayText());
        sessionObject7.insert("Probe Mode Microprobe",ui->Microprobe_STEMTomo_2->checkState());
        sessionObject7.insert("Probe Mode Nanoprobe",ui->NanoProbe_STEMTomo_2->checkState());
        sessionObject7.insert("Detector",ui->Detector_DropBox_STEMTomo_2->currentText());
        sessionObject7.insert("Camera Length",ui->CameraLength_Text_STEMTomo_2->displayText());
        sessionObject7.insert("Acquisition Software",ui->AcquisitionSoftware_STEMTomo_2->currentText());

        list.insert("Stem Tomo", sessionObject7);

        QJsonDocument doc = QJsonDocument(list);
        doc.setObject(list);

        QFile file;
        QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"Text Files (*.json)");
        QFileDialog::DialogLabel::FileType;
        file.setFileName(filename);
        if(file.open(QFile::ReadOnly | QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            file.write(doc.toJson());
            file.close();
        }

        QMessageBox::information(0, QString("Gopher"), QString("You Were Successful!")
                                 , QMessageBox::Ok);
        exit(0);
    }
        break;
    case 7://SEM 2D
    {
        QJsonObject list;

        QJsonObject sessionObject;//Intro
        sessionObject.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionObject.insert("Project ID", ui->ProjectID->displayText());
        sessionObject.insert("Subset ID", ui->SubsetID->displayText());
        sessionObject.insert("Instrument", ui->Instrument->currentText());
        sessionObject.insert("Image Mode", ui->imageMode->currentText());
        sessionObject.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionObject.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionObject.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionObject.insert("Notes", ui->NotesText->toPlainText());
        sessionObject.insert("Camera", ui->Camera->currentText());
        sessionObject.insert("Acquisition Software", ui->AquisitionSoftware->currentText());

        list.insert("Info",sessionObject);

        QJsonObject sessionObject8;//SEM 2D
        sessionObject8.insert("Coating",ui->Coating_DropBox_SEM_2->currentText());
        sessionObject8.insert("Coating Thickness",ui->CoatingThickness_Text_SEM_2->displayText());

        list.insert("SEM 2D", sessionObject8);

        QJsonDocument doc = QJsonDocument(list);
        doc.setObject(list);

        //("c:/Users/hansentd/Desktop/Gopher4/Tests/myFile2.json")
        QFile file;
        QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"Text Files (*.json)");
        QFileDialog::DialogLabel::FileType;
        file.setFileName(filename);
        if(file.open(QFile::ReadOnly | QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            file.write(doc.toJson());
            file.close();
        }

        QMessageBox::information(0, QString("Gopher"), QString("You Were Successful!")
                                 , QMessageBox::Ok);
        exit(0);
    }
        break;
    case 8://Cryo-SEM
    {
        QJsonObject list;

        QJsonObject sessionObject;//Intro
        sessionObject.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionObject.insert("Project ID", ui->ProjectID->displayText());
        sessionObject.insert("Subset ID", ui->SubsetID->displayText());
        sessionObject.insert("Instrument", ui->Instrument->currentText());
        sessionObject.insert("Image Mode", ui->imageMode->currentText());
        sessionObject.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionObject.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionObject.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionObject.insert("Notes", ui->NotesText->toPlainText());
        sessionObject.insert("Camera", ui->Camera->currentText());
        sessionObject.insert("Acquisition Software", ui->AquisitionSoftware->currentText());

        list.insert("Info",sessionObject);

        QJsonObject sessionObject9;//Cryo-SEM
        sessionObject9.insert("Primary Coating",ui->PrimaryCoating_DropBox_CryoSEM_2->currentText());
        sessionObject9.insert("Primary Coating Thickness",ui->PrimaryCoatingThickness_Text_CryoSEM_2->displayText());
        sessionObject9.insert("Secondary Coating",ui->SecondaryCoating_DropBox_CryoSEM_2->currentText());
        sessionObject9.insert("Secondary Coating Thickness",ui->SecondaryCoatingThickness_Text_CryoSEM_2->displayText());
        sessionObject9.insert("Primary Sublimation Time",ui->PrimaryCoatingThickness_Text_CryoSEM_2->displayText());
        sessionObject9.insert("Primary Sublimation Temp",ui->PrimarySublimationTemp_Text_CryoSEM_2->displayText());
        sessionObject9.insert("Secondary Sublimation Time",ui->SecondarySublimationTime_Text_CryoSEM_2->displayText());
        sessionObject9.insert("Secondary Sublimation Temp",ui->SecondarySublimationTemp_Text_CryoSEM_2->displayText());
        sessionObject9.insert("Viewing Temp",ui->ViewingTemp_Text_CryoSEM_2->displayText());
        sessionObject9.insert("Primary Coating Angle", ui->primaryCoatingAngle_Text->displayText());
        sessionObject9.insert("Primary Coating Angle Rotation", ui->primaryCoatingAngle_Rotation->checkState());
        sessionObject9.insert("Secondary Coating Angle", ui->secondaryCoatingAngle_Text->displayText());
        sessionObject9.insert("Secondary Coating Angle Rotation", ui->secondaryCoatingAngle_Rotation->checkState());

        list.insert("Cryo-SEM", sessionObject9);

        QJsonObject sessionObject2;//Vitrobot Settings
        sessionObject2.insert("Blot Force",ui->BlotForceText_VitrobotSettings_4->displayText());
        sessionObject2.insert("Blot Time",ui->BlotText_VitrobotSettings_4->displayText());
        sessionObject2.insert("Drain", ui->DrainText_VitrobotSettings_4->displayText());
        sessionObject2.insert("Wait",ui->WaitText_VitrobotSettings_4->displayText());
        sessionObject2.insert("Humidity Set",ui->HumiditySetText_VitrobotSettings_4->displayText());
        sessionObject2.insert("Actual Humidity",ui->ActualText_VitrobotSettings_4->displayText());

        list.insert("Vitrobot Settings", sessionObject2);

        QJsonDocument doc = QJsonDocument(list);
        doc.setObject(list);

        //("c:/Users/hansentd/Desktop/Gopher4/Tests/myFile2.json")
        QFile file;
        QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"Text Files (*.json)");
        QFileDialog::DialogLabel::FileType;
        file.setFileName(filename);
        if(file.open(QFile::ReadOnly | QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            file.write(doc.toJson());
            file.close();
        }

        QMessageBox::information(0, QString("Gopher"), QString("You Were Successful!")
                                 , QMessageBox::Ok);
        exit(0);
    }
        break;
    case 9://Confocal
    {
        QJsonObject list;

        QJsonObject sessionObject;//Intro
        sessionObject.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionObject.insert("Project ID", ui->ProjectID->displayText());
        sessionObject.insert("Subset ID", ui->SubsetID->displayText());
        sessionObject.insert("Instrument", ui->Instrument->currentText());
        sessionObject.insert("Image Mode", ui->imageMode->currentText());
        sessionObject.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionObject.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionObject.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionObject.insert("Notes", ui->NotesText->toPlainText());
        sessionObject.insert("Camera", ui->Camera->currentText());
        sessionObject.insert("Acquisition Software", ui->AquisitionSoftware->currentText());

        list.insert("Info",sessionObject);

        QJsonObject sessionObject10;//Confocal
        list.insert("Confocal", sessionObject10);

        QJsonDocument doc = QJsonDocument(list);
        doc.setObject(list);

        //("c:/Users/hansentd/Desktop/Gopher4/Tests/myFile2.json")
        QFile file;
        QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"Text Files (*.json)");
        QFileDialog::DialogLabel::FileType;
        file.setFileName(filename);
        if(file.open(QFile::ReadOnly | QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            file.write(doc.toJson());
            file.close();
        }

        QMessageBox::information(0, QString("Gopher"), QString("You Were Successful!")
                                 , QMessageBox::Ok);
        exit(0);
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
        QJsonObject info = QJsonValue(list.value("Info")).toObject();

        QString takenVal = QJsonValue(info.value("Data Taken By")).toString();
        ui->DataTakenBy->setCurrentText(takenVal);

        QString projectVal = QJsonValue(info.value("Project ID")).toString();
        ui->ProjectID->setText(projectVal);

        QString SubVal = QJsonValue(info.value("Subset ID")).toString();
        ui->SubsetID->setText(SubVal);

        QString instrumentVal = QJsonValue(info.value("Instrument")).toString();
        ui->Instrument->setCurrentText(instrumentVal);

        QString imageVal = QJsonValue(info.value("Image Mode")).toString();
        ui->imageMode->setCurrentText(imageVal);

        QString desVal = QJsonValue(info.value("Descriptive Title")).toString();
        ui->DescriptiveTitleText->setText(desVal);

        QString specVal = QJsonValue(info.value("Specimen/Organism")).toString();
        ui->Specimen_Organism->setCurrentText(specVal);

        QString samVal = QJsonValue(info.value("Sample prep")).toString();
        ui->SamplePrepText->setText(samVal);

        QString notesVal = QJsonValue(info.value("Notes")).toString();
        ui->NotesText->setText(notesVal);
    }
    //TEM 2D
    {
        QJsonObject tem2D = QJsonValue(list.value("TEM 2D")).toObject();

        QString csval = QJsonValue(tem2D.value("Cs Value")).toString();
        ui->CsValue_Text_TEM2D_2->setText(csval);

        QString voltageVal = QJsonValue(tem2D.value("Voltage")).toString();
        ui->Voltage_Text_TEM2D_2->setText(voltageVal);

        QString efssVal = QJsonValue(tem2D.value("Energy Filter Slit Size")).toString();
        ui->EnergyFilterSlitSize_Text_TEM2D_2->setText(efssVal);

        QString camVal = QJsonValue(tem2D.value("Camera")).toString();
        ui->Camera_TEM2D_2->setCurrentText(camVal);

        QString acqSofVal = QJsonValue(tem2D.value("Acquisition Software")).toString();
        ui->AcquisitionSoftware_TEM2D_2->setCurrentText(acqSofVal);
    }
    //TEM Tomo
    {
        QJsonObject temTomo = QJsonValue(list.value("TEM Tomo")).toObject();

        QString astVal = QJsonValue(temTomo.value("Actual Specimen Thickness")).toString();
        ui->MaxSpecimenThickness_Text_TEMTomo_2->setText(astVal);

        QString mfsVal = QJsonValue(temTomo.value("Max Fiducial Size")).toString();
        ui->MaxFiducialSize_Text_TEMTomo_2->setText(mfsVal);

        QString camVal = QJsonValue(temTomo.value("Camera")).toString();
        ui->Camera_TEMTomo_2->setCurrentText(camVal);

        QString efssVal = QJsonValue(temTomo.value("Energy Filter Slit Size")).toString();
        ui->EnergyFilterSlitSize_Text_TEMTomo_2->setText(efssVal);

        QString acqSofVal = QJsonValue(temTomo.value("Acquisition Software")).toString();
        ui->AcquisitionSoftware_TEMTomo_2->setCurrentText(acqSofVal);

        QString voltageVal = QJsonValue(temTomo.value("Voltage")).toString();
        ui->Voltage_Text_TEMTomo_2->setText(voltageVal);

        QString csval = QJsonValue(temTomo.value("Cs Value")).toString();
        ui->CsValue_Text_TEMTomo_2->setText(csval);
    }
    //Cryo-Tem 2D
    {
        //Cryo-Tem Tab
        {
            QJsonObject cryoTEM2D = QJsonValue(list.value("Cryo-TEM 2D")).toObject();

            QString doseVal = QJsonValue(cryoTEM2D.value("Dose")).toString();
            ui->Dose_CryoTEM2D_2->setText(doseVal);

            QString camVal = QJsonValue(cryoTEM2D.value("Camera")).toString();
            ui->Camera_CryoTEM2D_2->setCurrentText(camVal);

            QString efssVal = QJsonValue(cryoTEM2D.value("Energy Filter Slit Size")).toString();
            ui->EnergyFilterSlitSize_CryoTEM2D_3->setText(efssVal);

            QString acqSofVal = QJsonValue(cryoTEM2D.value("Acquisition Software")).toString();
            ui->AcquisitionSoftware_CryoTEM2D_2->setCurrentText(acqSofVal);

            QString voltageVal = QJsonValue(cryoTEM2D.value("Voltage")).toString();
            ui->Voltage_Text_CryoTEM2D_2->setText(voltageVal);

            QString csval = QJsonValue(cryoTEM2D.value("Cs Value")).toString();
            ui->CsValue_Text_CryoTEM2D_2->setText(csval);
        }
        //Vitrobot Settings Tab
        {
            QJsonObject vit = QJsonValue(list.value("Vitrobot Settings")).toObject();

            QString forceVal = QJsonValue(vit.value("Blot Force")).toString();
            ui->BlotForceText_VitrobotSettings_2->setText(forceVal);

            QString timeVal = QJsonValue(vit.value("Blot Time")).toString();
            ui->BlotText_VitrobotSettings_2->setText(timeVal);

            QString humVal = QJsonValue(vit.value("Humidity Set")).toString();
            ui->HumiditySetText_VitrobotSettings_2->setText(humVal);

            QString acthumVal = QJsonValue(vit.value("Actual Humidity")).toString();
            ui->ActualText_VitrobotSettings_2->setText(acthumVal);

            QString waitVal = QJsonValue(vit.value("Wait")).toString();
            ui->WaitText_VitrobotSettings_2->setText(waitVal);

            QString drainVal = QJsonValue(vit.value("Drain")).toString();
            ui->DrainText_VitrobotSettings_2->setText(drainVal);

        }
    }
    //Cryo-Tem Tomo
    {
        //Cryo-Tem Tomo Tab
        {
            QJsonObject cryoTEMTomo = QJsonValue(list.value("Cryo-TEM Tomo")).toObject();

            QString mstVal = QJsonValue(cryoTEMTomo.value("Max Specimen Thickness")).toString();
            ui->MaxSpecimenThickness_Text_CryoTomo_2->setText(mstVal);

            QString mfsVal = QJsonValue(cryoTEMTomo.value("Max Fiducial Size")).toString();
            ui->MaxFidecialSize_Text_CryoTomo_2->setText(mfsVal);

            QString doseVal = QJsonValue(cryoTEMTomo.value("Dose")).toString();
            ui->Dose_Text_CryoTomo_2->setText(doseVal);

            QString camVal = QJsonValue(cryoTEMTomo.value("Camera")).toString();
            ui->Camera_CryoTEMTomo_2->setCurrentText(camVal);

            QString efssVal = QJsonValue(cryoTEMTomo.value("Energy Filter Slit Size")).toString();
            ui->EnergyFilterSlitSize_Text_CryoTomo_2->setText(efssVal);

            QString acqSofVal = QJsonValue(cryoTEMTomo.value("Acquisition Software")).toString();
            ui->AcquisitionSoftware_CryoTomo_2->setCurrentText(acqSofVal);

            QString voltageVal = QJsonValue(cryoTEMTomo.value("Voltage")).toString();
            ui->Voltage_Text_CryoTomo_2->setText(voltageVal);

            QString csval = QJsonValue(cryoTEMTomo.value("Cs Value")).toString();
            ui->CsValue_Text_CryoTomo_2->setText(csval);
        }
        //Vitrobot Settings Tab
        {
            QJsonObject vit = QJsonValue(list.value("Vitrobot Settings")).toObject();

            QString forceVal = QJsonValue(vit.value("Blot Force")).toString();
            ui->BlotForceText_VitrobotSettings_3->setText(forceVal);

            QString timeVal = QJsonValue(vit.value("Blot Time")).toString();
            ui->BlotText_VitrobotSettings_3->setText(timeVal);

            QString humVal = QJsonValue(vit.value("Humidity Set")).toString();
            ui->HumiditySetText_VitrobotSettings_3->setText(humVal);

            QString acthumVal = QJsonValue(vit.value("Actual Humidity")).toString();
            ui->ActualText_VitrobotSettings_3->setText(acthumVal);

            QString waitVal = QJsonValue(vit.value("Wait")).toString();
            ui->WaitText_VitrobotSettings_3->setText(waitVal);

            QString drainVal = QJsonValue(vit.value("Drain")).toString();
            ui->DrainText_VitrobotSettings_3->setText(drainVal);

        }
    }
    //Stem 2D
    {
        QJsonObject stem2D = QJsonValue(list.value("Stem 2D")).toObject();

        QString spotVal = QJsonValue(stem2D.value("Spot Size")).toString();
        ui->SpotSizeText_STEM2D_2->setText(spotVal);

        QString dwellVal = QJsonValue(stem2D.value("Dwell Time")).toString();
        ui->DwellTimeText_STEM2D_2->setText(dwellVal);

        QString currentVal = QJsonValue(stem2D.value("Current(I)")).toString();
        ui->I_Text_STEM2D_2->setText(currentVal);

        QString conVal = QJsonValue(stem2D.value("Convergence Angle")).toString();
        ui->ConvergenceAngle_Text_STEM2D_2->setText(conVal);

        //        QString probeMicroVal = QJsonValue(stem2D.value("Probe Mode Microprobe")).toString();
        //        ui->Microprobe_STEM2D_2->setChecked(probeMicroVal);

        //        QString probeNanoVal = QJsonValue(stem2D.value("Probe Mode Nanoprobe")).toString();
        //        ui->NanoProbe_STEM2D_2->setChecked(probeNanoVal);

        QString camLenVal = QJsonValue(stem2D.value("Camera Length")).toString();
        ui->CameraLengthText_STEM2D_2->setText(camLenVal);

        QString acqSofVal = QJsonValue(stem2D.value("Acquisition Software")).toString();
        ui->AcquisitionSoftware_STEM2D_2->setCurrentText(acqSofVal);

        QString nomMagVal = QJsonValue(stem2D.value("Nominal Magnification")).toString();
        ui->NominalMagnification_Text_STEM2D_2->setText(nomMagVal);
    }
    //Stem Tomo
    {
        QJsonObject stemTomo = QJsonValue(list.value("Stem Tomo")).toObject();

        QString mstVal = QJsonValue(stemTomo.value("Max Section Thickness")).toString();
        ui->MaxSectionThickness_Text_STEMTomo_2->setText(mstVal);

        QString mfsVal = QJsonValue(stemTomo.value("Max Fiducial Size")).toString();
        ui->MaxFiducialSize_Text_STEMTomo_2->setText(mfsVal);

        QString spotVal = QJsonValue(stemTomo.value("Spot Size")).toString();
        ui->SpotSize_Text_STEMTomo_2->setText(spotVal);

        QString dwellVal = QJsonValue(stemTomo.value("Dwell Time")).toString();
        ui->DwellTime_Text_STEMTomo_2->setText(dwellVal);

        QString currentVal = QJsonValue(stemTomo.value("Current(I)")).toString();
        ui->I_Text_STEMTomo_2->setText(currentVal);

        QString conVal = QJsonValue(stemTomo.value("Convergence Angle")).toString();
        ui->ConvergenceAngle_Text_STEMTomo_2->setText(conVal);

        //        QString probeMicroVal = QJsonValue(stemTomo.value("Probe Mode Microprobe")).toString();
        //        ui->Microprobe_STEMTomo_2->setChecked(probeMicroVal);

        //        QString probeNanoVal = QJsonValue(stemTomo.value("Probe Mode Nanoprobe")).toString();
        //        ui->NanoProbe_STEMTomo_2->setChecked(probeNanoVal);

        QString decVal = QJsonValue(stemTomo.value("Detector")).toString();
        ui->Detector_DropBox_STEMTomo_2->setCurrentText(decVal);

        QString camLenVal = QJsonValue(stemTomo.value("Camera Length")).toString();
        ui->CameraLength_Text_STEMTomo_2->setText(camLenVal);

        QString acqSofVal = QJsonValue(stemTomo.value("Acquisition Software")).toString();
        ui->AcquisitionSoftware_STEMTomo_2->setCurrentText(acqSofVal);
    }
    //SEM
    {
        QJsonObject sem2D = QJsonValue(list.value("SEM 2D")).toObject();

        QString coatVal = QJsonValue(sem2D.value("Coating")).toString();
        ui->Coating_DropBox_SEM_2->setCurrentText(coatVal);

        QString coatThickVal = QJsonValue(sem2D.value("Coating Thickness")).toString();
        ui->CoatingThickness_Text_SEM_2->setText(coatThickVal);

    }
    //Cryo-SEM
    {
        //Cryo-SEM Tab
        {
            QJsonObject cryoSEM = QJsonValue(list.value("Cryo-SEM")).toObject();

            QString priCoatVal = QJsonValue(cryoSEM.value("Primary Coating")).toString();
            ui->PrimaryCoating_DropBox_CryoSEM_2->setCurrentText(priCoatVal);

            QString priCoatAngVal = QJsonValue(cryoSEM.value("Primary Coating Angle")).toString();
            ui->primaryCoatingAngle_Text->setText(priCoatAngVal);

            //            QJsonObject rotVal = QJsonValue(cryoSEM.value("Rotation")).toObject();
            //            ui->primaryCoatingAngle_Rotation->setChecked(rotVal);

            QString priCoatThickVal = QJsonValue(cryoSEM.value("Primary Coating Thickness")).toString();
            ui->PrimaryCoatingThickness_Text_CryoSEM_2->setText(priCoatThickVal);

            QString secCoatVal = QJsonValue(cryoSEM.value("Secondary Coating Angle")).toString();
            ui->SecondaryCoating_DropBox_CryoSEM_2->setCurrentText(secCoatVal);

            QString secCoatAngVal = QJsonValue(cryoSEM.value("Secondary Coating Angle")).toString();
            ui->secondaryCoatingAngle_Text->setText(secCoatAngVal);

            //        QString secRotVal = QJsonValue(cryoSEM.value("Rotation")).toString();
            //        ui->secondaryCoatingAngle_Rotation->setChecked(secRotVal);

            QString secCoatThickVal = QJsonValue(cryoSEM.value("Secondary Coating Thickness")).toString();
            ui->SecondaryCoatingThickness_Text_CryoSEM_2->setText(secCoatThickVal);

            QString priSubTimeVal = QJsonValue(cryoSEM.value("Primary Sublimation Time")).toString();
            ui->PrimarySublimationTime_Text_CryoSEM_2->setText(priSubTimeVal);

            QString priSubTempVal = QJsonValue(cryoSEM.value("Primary Sublimation Temp")).toString();
            ui->PrimarySublimationTemp_Text_CryoSEM_2->setText(priSubTempVal);

            QString secSubTimeVal = QJsonValue(cryoSEM.value("Secondary Sublimation Time")).toString();
            ui->SecondarySublimationTime_Text_CryoSEM_2->setText(secSubTimeVal);

            QString secSubTempVal = QJsonValue(cryoSEM.value("Secondary Sublimation Temp")).toString();
            ui->SecondarySublimationTemp_Text_CryoSEM_2->setText(secSubTempVal);

            QString viewTempVal = QJsonValue(cryoSEM.value("Viewing Temp")).toString();
            ui->ViewingTemp_Text_CryoSEM_2->setText(viewTempVal);
        }
        //vitrobot Tab
        {
            QJsonObject vit = QJsonValue(list.value("Vitrobot Settings")).toObject();

            QString forceVal = QJsonValue(vit.value("Blot Force")).toString();
            ui->BlotForceText_VitrobotSettings_4->setText(forceVal);

            QString timeVal = QJsonValue(vit.value("Blot Time")).toString();
            ui->BlotText_VitrobotSettings_4->setText(timeVal);

            QString humVal = QJsonValue(vit.value("Humidity Set")).toString();
            ui->HumiditySetText_VitrobotSettings_4->setText(humVal);

            QString acthumVal = QJsonValue(vit.value("Actual Humidity")).toString();
            ui->ActualText_VitrobotSettings_4->setText(acthumVal);

            QString waitVal = QJsonValue(vit.value("Wait")).toString();
            ui->WaitText_VitrobotSettings_4->setText(waitVal);

            QString drainVal = QJsonValue(vit.value("Drain")).toString();
            ui->DrainText_VitrobotSettings_4->setText(drainVal);
        }
    }
    //Confocal
    {
        QJsonObject confocal = QJsonValue(list.value("Confocal")).toObject();
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
