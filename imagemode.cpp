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

void Gopher::FillImageMode()
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
}

void Gopher::FillTEM2D()
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    ui->stackedWidget->setCurrentIndex(1);
    ui->tem2D_Toolbox->setItemIcon(0,QIcon(pointer));
}

void Gopher::FillTEMTomo()
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    ui->stackedWidget->setCurrentIndex(2);
    ui->temTomo_Toolbox->setItemIcon(0,QIcon(pointer));
}

void Gopher::FillCryoTEM2D()
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    ui->stackedWidget->setCurrentIndex(3);
    ui->cryoTem2D_Toolbox->setCurrentIndex(1);
    ui->cryoTem2D_Toolbox->setItemIcon(0,QIcon(pointer));
    ui->cryoTem2D_Toolbox->setItemIcon(1,QIcon(pointer));
}

void Gopher::FillCryoTEMTomo()
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    ui->stackedWidget->setCurrentIndex(4);
    ui->cryoTEMTomo_Toolbox->setCurrentIndex(1);
    ui->cryoTEMTomo_Toolbox->setItemIcon(0,QIcon(pointer));
    ui->cryoTEMTomo_Toolbox->setItemIcon(1,QIcon(pointer));
}

void Gopher::FillStem2D()
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    ui->stackedWidget->setCurrentIndex(5);
    ui->stem2D_Toolbox->setItemIcon(0,QIcon(pointer));
}

void Gopher::FillStemTomo()
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    ui->stackedWidget->setCurrentIndex(6);
    ui->stemTomo_Toolbox->setItemIcon(0,QIcon(pointer));
}

void Gopher::FillSEM2D()
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    ui->stackedWidget->setCurrentIndex(7);
    ui->sem2D_Toolbox->setItemIcon(0,QIcon(pointer));
}

void Gopher::FillCryoSEM()
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    ui->stackedWidget->setCurrentIndex(8);
    ui->cryoSEM_Toolbox->setCurrentIndex(1);
    ui->cryoSEM_Toolbox->setItemIcon(0,QIcon(pointer));
    ui->cryoSEM_Toolbox->setItemIcon(1,QIcon(pointer));
}

void Gopher::FillConfocal()
{
    //Called to show what needs filled out
    QIcon pointer(QIcon("Warning_icon.png"));

    ui->stackedWidget->setCurrentIndex(9);
    ui->confocal_Toolbox->setItemIcon(0,QIcon(pointer));
}

