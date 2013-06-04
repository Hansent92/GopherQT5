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

void Gopher::FillInstrumentsImageMode()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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


void Gopher::FillInstrumentsCameras()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

    QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
    ui->Camera->model()->setData(index1, m, Qt::UserRole -1);
    QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
    ui->Camera->model()->setData(index2, m, Qt::UserRole -1);
    QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
    ui->Camera->model()->setData(index3, m, Qt::UserRole -1);
    QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
    ui->Camera->model()->setData(index4, m, Qt::UserRole -1);
}

void Gopher::FillInstrumentsAquisitionSoftware()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillH7500ImageModes()
{

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

void Gopher::FillH7500Camera()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

    QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
    ui->Camera->model()->setData(index1, m, Qt::UserRole -1);
    QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
    ui->Camera->model()->setData(index2, v, Qt::UserRole -1);
    QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
    ui->Camera->model()->setData(index3, v, Qt::UserRole -1);
    QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
    ui->Camera->model()->setData(index4, v, Qt::UserRole -1);
}

void Gopher::FillH7500AquisitionSoftware()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillSU8000ImageMode()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillSU8000Camera()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

    QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
    ui->Camera->model()->setData(index1, v, Qt::UserRole -1);
    QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
    ui->Camera->model()->setData(index2, v, Qt::UserRole -1);
    QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
    ui->Camera->model()->setData(index3, v, Qt::UserRole -1);
    QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
    ui->Camera->model()->setData(index4, v, Qt::UserRole -1);
}

void Gopher::FillSU8000AquisitionSoftware()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillS5200ImageMode()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillS5200Camera()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

    QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
    ui->Camera->model()->setData(index1, v, Qt::UserRole -1);
    QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
    ui->Camera->model()->setData(index2, v, Qt::UserRole -1);
    QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
    ui->Camera->model()->setData(index3, v, Qt::UserRole -1);
    QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
    ui->Camera->model()->setData(index4, v, Qt::UserRole -1);
}

void Gopher::FillS5200AquisitionSoftware()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillTecnaiAMTImageMode()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillTecnaiAMTCamera()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

    QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
    ui->Camera->model()->setData(index1, m, Qt::UserRole -1);
    QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
    ui->Camera->model()->setData(index2, m, Qt::UserRole -1);
    QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
    ui->Camera->model()->setData(index3, v, Qt::UserRole -1);
    QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
    ui->Camera->model()->setData(index4, v, Qt::UserRole -1);
}

void Gopher::FillTecnaiAMTAquisitionSoftware()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillTecnaiTomoImageMode()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillTecnaiTomoCamera()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

    QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
    ui->Camera->model()->setData(index1, v, Qt::UserRole -1);
    QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
    ui->Camera->model()->setData(index2, m, Qt::UserRole -1);
    QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
    ui->Camera->model()->setData(index3, v, Qt::UserRole -1);
    QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
    ui->Camera->model()->setData(index4, v, Qt::UserRole -1);
}

void Gopher::FillTecnaiTomoAquisitionSoftware()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillKriosImageMode()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::FillKriosCamera()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

    QModelIndex index1 = ui->Camera->model()->index(1,0);//Hamamatsu Xr-100
    ui->Camera->model()->setData(index1, v, Qt::UserRole -1);
    QModelIndex index2 = ui->Camera->model()->index(2,0);//UltraScan 1000 Gatan CCD
    ui->Camera->model()->setData(index2, v, Qt::UserRole -1);
    QModelIndex index3 = ui->Camera->model()->index(3,0);//UltraScan 4000 Gata CCD
    ui->Camera->model()->setData(index3, m, Qt::UserRole -1);
    QModelIndex index4 = ui->Camera->model()->index(4,0);//UltaScan GIF 2002
    ui->Camera->model()->setData(index4, m, Qt::UserRole -1);
}

void Gopher::FillKriosAquisitionSoftware()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

void Gopher::Fill510MetaImageMode()
{
    QVariant v(0);//disables
    QVariant m(1 | 32);//enables

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

