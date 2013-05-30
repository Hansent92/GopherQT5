﻿#include "gopher.h"
#include "ui_gopher.h"
#include "tem2d.h"

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
        break;
    case 1://H7500
    {
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
        break;
    case 2://SU8000
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
        break;
    case 3://S5200
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
        break;
    case 4://Tecnai-AMT
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
        break;
    case 5://Tecnai-Tomo
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
        break;
    case 6://Krios
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
    //c:/Users/hansentd/Desktop/Gopher4/Warning_icon.png
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

        QJsonObject sessionData;//Intro
        sessionData.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionData.insert("Project ID", ui->ProjectID->displayText());
        sessionData.insert("Subset ID", ui->SubsetID->displayText());
        sessionData.insert("Instrument", ui->Instrument->currentText());
        sessionData.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionData.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionData.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionData.insert("Notes", ui->NotesText->toPlainText());

        list.insert("Data",sessionData);

        QJsonObject sessionData3;//TEM 2D
        sessionData3.insert("Camara", ui->Camera_TEM2D_2->currentText());
        sessionData3.insert("Energy Filter Slit Size", ui->EnergyFilterSlitSize_Text_TEM2D_2->displayText());
        sessionData3.insert("Acquisition Software",ui->AcquisitionSoftware_TEM2D_2->currentText());
        sessionData3.insert("Voltage",ui->Voltage_Text_TEM2D_2->displayText());
        sessionData3.insert("Cs Value",ui->CsValue_Text_TEM2D_2->displayText());

        list.insert("TEM 2D",sessionData3);

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
    case 2://TEM Tomo
    {
        QJsonObject list;

        QJsonObject sessionData;//Intro
        sessionData.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionData.insert("Project ID", ui->ProjectID->displayText());
        sessionData.insert("Subset ID", ui->SubsetID->displayText());
        sessionData.insert("Instrument", ui->Instrument->currentText());
        sessionData.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionData.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionData.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionData.insert("Notes", ui->NotesText->toPlainText());

        list.insert("Data",sessionData);

        QJsonObject sessionData4;//TEM Tomo
        sessionData4.insert("Max Specimen Thickness",ui->MaxSpecimenThickness_Text_TEMTomo_2->displayText());
        sessionData4.insert("Max Fiducial Size",ui->MaxFiducialSize_Text_TEMTomo_2->displayText());
        sessionData4.insert("Camera",ui->Camera_TEMTomo_2->currentText());
        sessionData4.insert("Energy Filter Slit Size",ui->EnergyFilterSlitSize_Text_TEMTomo_2->displayText());
        sessionData4.insert("Acquisition Software",ui->AcquisitionSoftware_TEMTomo_2->currentText());
        sessionData4.insert("Voltage",ui->Voltage_Text_TEMTomo_2->displayText());
        sessionData4.insert("Cs Value",ui->CsValue_Text_TEMTomo_2->displayText());

        list.insert("TEM Tomo", sessionData4);

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
    case 3://Cryo-TEM 2D
    {
        QJsonObject list;
        QJsonObject sessionData;//Intro
        sessionData.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionData.insert("Project ID", ui->ProjectID->displayText());
        sessionData.insert("Subset ID", ui->SubsetID->displayText());
        sessionData.insert("Instrument", ui->Instrument->currentText());
        sessionData.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionData.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionData.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionData.insert("Notes", ui->NotesText->toPlainText());

        list.insert("Data",sessionData);

        QJsonObject sessionData5;//Cryo-TEM 2D
        sessionData5.insert("Dose",ui->Dose_Text_CryoTEM2D_2->displayText());
        sessionData5.insert("Camera",ui->Camera_CryoTEM2D_2->currentText());
        sessionData5.insert("Energy Filter Slit Size",ui->EnergyFilterSlitSize_Text_CryoTEM2D_3->displayText());
        sessionData5.insert("Acquisition Software",ui->AcquisitionSoftware_CryoTEM2D_2->currentText());
        sessionData5.insert("Voltage",ui->Voltage_Text_CryoTEM2D_2->displayText());
        sessionData5.insert("Cs Value",ui->CsValue_Text_CryoTEM2D_2->displayText());

        list.insert("Cryo-TEM 2D", sessionData5);

        QJsonObject sessionData2;//Vitrobot Settings
        sessionData2.insert("Blot Force",ui->BlotForceText_VitrobotSettings_2->displayText());
        sessionData2.insert("Blot",ui->BlotText_VitrobotSettings_2->displayText());
        sessionData2.insert("Drain", ui->DrainText_VitrobotSettings_2->displayText());
        sessionData2.insert("Wait",ui->WaitText_VitrobotSettings_2->displayText());
        sessionData2.insert("Humidity Set",ui->HumiditySetText_VitrobotSettings_2->displayText());
        sessionData2.insert("Actual",ui->ActualText_VitrobotSettings_2->displayText());

        list.insert("Vitrobot Settings", sessionData2);

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
    case 4://Cryo-TEM Tomo
    {
        QJsonObject list;

        QJsonObject sessionData;//Intro
        sessionData.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionData.insert("Project ID", ui->ProjectID->displayText());
        sessionData.insert("Subset ID", ui->SubsetID->displayText());
        sessionData.insert("Instrument", ui->Instrument->currentText());
        sessionData.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionData.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionData.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionData.insert("Notes", ui->NotesText->toPlainText());

        list.insert("Data",sessionData);

        QJsonObject sessionData11;//Cryo-TEM Tomo
        sessionData11.insert("Max Specimen Thickness",ui->MaxSpecimenThickness_Text_CryoTomo_2->displayText());
        sessionData11.insert("Max Fiducial Size",ui->MaxFidecialSize_Text_CryoTomo_2->displayText());
        sessionData11.insert("Dose",ui->Dose_Text_CryoTomo_2->displayText());
        sessionData11.insert("Camera",ui->Camera_CryoTEMTomo_2->currentText());
        sessionData11.insert("Energy Filter Slit Size",ui->EnergyFilterSlitSize_Text_CryoTomo_2->displayText());
        sessionData11.insert("Acquisition Software",ui->AcquisitionSoftware_CryoTomo_2->currentText());
        sessionData11.insert("Cs Value",ui->CsValue_Text_CryoTomo_2->displayText());
        sessionData11.insert("Voltage",ui->Voltage_Text_CryoTomo_2->displayText());

        list.insert("Cryo-TEM Tomo", sessionData11);

        QJsonObject sessionData2;//Vitrobot Settings
        sessionData2.insert("Blot Force",ui->BlotForceText_VitrobotSettings_3->displayText());
        sessionData2.insert("Blot",ui->BlotText_VitrobotSettings_3->displayText());
        sessionData2.insert("Drain", ui->DrainText_VitrobotSettings_3->displayText());
        sessionData2.insert("Wait",ui->WaitText_VitrobotSettings_3->displayText());
        sessionData2.insert("Humidity Set",ui->HumiditySetText_VitrobotSettings_3->displayText());
        sessionData2.insert("Actual",ui->ActualText_VitrobotSettings_3->displayText());

        list.insert("Vitrobot Settings", sessionData2);

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

        QJsonObject sessionData;//Intro
        sessionData.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionData.insert("Project ID", ui->ProjectID->displayText());
        sessionData.insert("Subset ID", ui->SubsetID->displayText());
        sessionData.insert("Instrument", ui->Instrument->currentText());
        sessionData.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionData.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionData.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionData.insert("Notes", ui->NotesText->toPlainText());

        list.insert("Data",sessionData);

        QJsonObject sessionData6;//Stem 2D
        sessionData6.insert("Spot Size",ui->SpotSizeText_STEM2D_2->displayText());
        sessionData6.insert("Dwell Time",ui->DwellTimeText_STEM2D_2->displayText());
        sessionData6.insert("I",ui->I_Text_STEM2D_2->displayText());
        sessionData6.insert("Convergence Angle",ui->ConvergenceAngle_Text_STEM2D_2->displayText());
        sessionData6.insert("Probe Mode Microprobe",ui->Microprobe_STEM2D_2->checkState());
        sessionData6.insert("Probe Mode Nanoprobe",ui->NanoProbe_STEM2D_2->checkState());
        sessionData6.insert("Camera Length", ui->CameraLengthText_STEM2D_2->displayText());
        sessionData6.insert("Acquisition Software",ui->AcquisitionSoftware_STEM2D_2->currentText());
        sessionData6.insert("Nominal Magnification",ui->NominalMagnification_Text_STEM2D_2->displayText());

        list.insert("Stem 2D", sessionData6);

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

        QJsonObject sessionData;//Intro
        sessionData.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionData.insert("Project ID", ui->ProjectID->displayText());
        sessionData.insert("Subset ID", ui->SubsetID->displayText());
        sessionData.insert("Instrument", ui->Instrument->currentText());
        sessionData.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionData.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionData.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionData.insert("Notes", ui->NotesText->toPlainText());

        list.insert("Data",sessionData);

        QJsonObject sessionData7;//Stem Tomo
        sessionData7.insert("Max Section Thickness",ui->MaxSectionThickness_Text_STEMTomo_2->displayText());
        sessionData7.insert("Max Fiducial Size",ui->MaxFiducialSize_Text_STEMTomo_2->displayText());
        sessionData7.insert("Spot Size",ui->SpotSize_Text_STEMTomo_2->displayText());
        sessionData7.insert("Dwell Time",ui->DwellTime_Text_STEMTomo_2->displayText());
        sessionData7.insert("I",ui->I_Text_STEMTomo_2->displayText());
        sessionData7.insert("Convergence Angle",ui->ConvergenceAngle_Text_STEMTomo_2->displayText());
        sessionData7.insert("Probe Mode Microprobe",ui->Microprobe_STEMTomo_2->checkState());
        sessionData7.insert("Probe Mode Nanoprobe",ui->NanoProbe_STEMTomo_2->checkState());
        sessionData7.insert("Detector",ui->Detector_DropBox_STEMTomo_2->currentText());
        sessionData7.insert("Camera Length",ui->CameraLength_Text_STEMTomo_2->displayText());
        sessionData7.insert("Acquisition Software",ui->AcquisitionSoftware_STEMTomo_2->currentText());

        list.insert("Stem Tomo", sessionData7);

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

        QJsonObject sessionData;//Intro
        sessionData.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionData.insert("Project ID", ui->ProjectID->displayText());
        sessionData.insert("Subset ID", ui->SubsetID->displayText());
        sessionData.insert("Instrument", ui->Instrument->currentText());
        sessionData.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionData.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionData.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionData.insert("Notes", ui->NotesText->toPlainText());

        list.insert("Data",sessionData);

        QJsonObject sessionData8;//SEM 2D
        sessionData8.insert("Coating",ui->Coating_DropBox_SEM_2->currentText());
        sessionData8.insert("Coating Thickness",ui->CoatingThickness_Text_SEM_2->displayText());

        list.insert("SEM 2D", sessionData8);

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

        QJsonObject sessionData;//Intro
        sessionData.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionData.insert("Project ID", ui->ProjectID->displayText());
        sessionData.insert("Subset ID", ui->SubsetID->displayText());
        sessionData.insert("Instrument", ui->Instrument->currentText());
        sessionData.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionData.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionData.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionData.insert("Notes", ui->NotesText->toPlainText());

        list.insert("Data",sessionData);

        QJsonObject sessionData9;//Cryo-SEM
        sessionData9.insert("Primary Coating",ui->PrimaryCoating_DropBox_CryoSEM_2->currentText());
        sessionData9.insert("Primary Coating Thickness",ui->PrimaryCoatingThickness_Text_CryoSEM_2->displayText());
        sessionData9.insert("Secondary Coating",ui->SecondaryCoating_DropBox_CryoSEM_2->currentText());
        sessionData9.insert("Seconday Coating Thickness",ui->SecondaryCoatingThickness_Text_CryoSEM_2->displayText());
        sessionData9.insert("Primary Sublimation Time",ui->PrimaryCoatingThickness_Text_CryoSEM_2->displayText());
        sessionData9.insert("Primary Sublimation Temp",ui->PrimarySublimationTemp_Text_CryoSEM_2->displayText());
        sessionData9.insert("Secondary Sublimation Time",ui->SecondarySublimationTime_Text_CryoSEM_2->displayText());
        sessionData9.insert("Secondary Sublimation Temp",ui->SecondarySublimationTemp_Text_CryoSEM_2->displayText());
        sessionData9.insert("Viewing Temp",ui->ViewingTemp_Text_CryoSEM_2->displayText());
        sessionData9.insert("Primary Coating Angle", ui->primaryCoatingAngle_Text->displayText());
        sessionData9.insert("Primary Coating Angle Rotation", ui->primaryCoatingAngle_Rotation->checkState());
        sessionData9.insert("Secondary Coating Angle", ui->secondaryCoatingAngle_Text->displayText());
        sessionData9.insert("Secondary Coating Angle Rotation", ui->secondaryCoatingAngle_Rotation->checkState());

        list.insert("Cryo-SEM", sessionData9);

        QJsonObject sessionData2;//Vitrobot Settings
        sessionData2.insert("Blot Force",ui->BlotForceText_VitrobotSettings_4->displayText());
        sessionData2.insert("Blot",ui->BlotText_VitrobotSettings_4->displayText());
        sessionData2.insert("Drain", ui->DrainText_VitrobotSettings_4->displayText());
        sessionData2.insert("Wait",ui->WaitText_VitrobotSettings_4->displayText());
        sessionData2.insert("Humidity Set",ui->HumiditySetText_VitrobotSettings_4->displayText());
        sessionData2.insert("Actual",ui->ActualText_VitrobotSettings_4->displayText());

        list.insert("Vitrobot Settings", sessionData2);

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

        QJsonObject sessionData;//Intro
        sessionData.insert("Data Taken By", ui->DataTakenBy->currentText());
        //    sessionData.insert("Date", ui->dateTimeEdit);
        sessionData.insert("Project ID", ui->ProjectID->displayText());
        sessionData.insert("Subset ID", ui->SubsetID->displayText());
        sessionData.insert("Instrument", ui->Instrument->currentText());
        sessionData.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
        sessionData.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
        sessionData.insert("Sample prep", ui->SamplePrepText->toPlainText());
        sessionData.insert("Notes", ui->NotesText->toPlainText());

        list.insert("Data",sessionData);

        QJsonObject sessionData10;//Confocal
        list.insert("Confocal", sessionData10);

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

void Gopher::on_actionExport_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save file", "", ".json");
    QFile f( filename );
    f.open( QIODevice::WriteOnly );
    f.close();
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
