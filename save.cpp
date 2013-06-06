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





void Gopher::SaveCryoTEM2D()
{
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

    list.insert("Session",sessionObject);

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
    header.insert("Session Data", list);

    QJsonDocument doc = QJsonDocument(header);
    doc.setObject(header);

    QFile file;
    QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"");
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

void Gopher::SaveCryoTomo()
{
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

    list.insert("Session",sessionObject);

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
    header.insert("Session Data",list);

    QJsonDocument doc = QJsonDocument(header);
    doc.setObject(header);

    QFile file;
    QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"");
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

void Gopher::SaveStem2D()
{
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

    list.insert("Session",sessionObject);

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
    header.insert("Session Data",list);

    QJsonDocument doc = QJsonDocument(header);
    doc.setObject(header);

    QFile file;
    QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"");
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

void Gopher::SaveStemTomo()
{
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

    list.insert("Session",sessionObject);

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
    header.insert("Session Data",list);

    QJsonDocument doc = QJsonDocument(header);
    doc.setObject(header);

    QFile file;
    QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"");
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

void Gopher::SaveSEM2D()
{
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

    list.insert("Session",sessionObject);

    QJsonObject sessionObject8;//SEM 2D
    sessionObject8.insert("Coating",ui->Coating_DropBox_SEM_2->currentText());
    sessionObject8.insert("Coating Thickness",ui->CoatingThickness_Text_SEM_2->displayText());

    list.insert("SEM 2D", sessionObject8);
    header.insert("Session Data",list);

    QJsonDocument doc = QJsonDocument(header);
    doc.setObject(header);

    QFile file;
    QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"");
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

void Gopher::SaveCryoSEM()
{
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

    list.insert("Session",sessionObject);

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
    header.insert("Session Data",list);

    QJsonDocument doc = QJsonDocument(header);
    doc.setObject(header);

    QFile file;
    QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"");
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

void Gopher::SaveConfocal()
{
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

    list.insert("Session",sessionObject);

    QJsonObject sessionObject10;//Confocal
    list.insert("Confocal", sessionObject10);
    header.insert("Session Data",list);

    QJsonDocument doc = QJsonDocument(header);
    doc.setObject(header);

    QFile file;
    QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"");
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

