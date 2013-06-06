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

void Gopher::ImportInfo()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject info = QJsonValue(sessionData.value("Session")).toObject();

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

void Gopher::ImportTEM2D()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject tem2D = QJsonValue(sessionData.value("TEM 2D")).toObject();

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

void Gopher::ImportTEMTomo()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject temTomo = QJsonValue(sessionData.value("TEM Tomo")).toObject();

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

void Gopher::ImportCryoTEM()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject cryoTEM2D = QJsonValue(sessionData.value("Cryo-TEM 2D")).toObject();

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

void Gopher::ImportCryoTEMVitrobotSettings()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject vit = QJsonValue(sessionData.value("Vitrobot Settings")).toObject();

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

void Gopher::ImportCryoTEMTomo()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject cryoTEMTomo = QJsonValue(sessionData.value("Cryo-TEM Tomo")).toObject();

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

void Gopher::ImportCryoTEMTomoVitrobotSettings()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject vit = QJsonValue(sessionData.value("Vitrobot Settings")).toObject();

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

void Gopher::ImportStem2D()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject stem2D = QJsonValue(sessionData.value("Stem 2D")).toObject();

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

void Gopher::ImportStemTomo()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject stemTomo = QJsonValue(sessionData.value("Stem Tomo")).toObject();

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

void Gopher::ImportSEM()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject sem2D = QJsonValue(sessionData.value("SEM 2D")).toObject();

    QString coatVal = QJsonValue(sem2D.value("Coating")).toString();
    ui->Coating_DropBox_SEM_2->setCurrentText(coatVal);

    QString coatThickVal = QJsonValue(sem2D.value("Coating Thickness")).toString();
    ui->CoatingThickness_Text_SEM_2->setText(coatThickVal);

}

void Gopher::ImportCryoSEM()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject cryoSEM = QJsonValue(sessionData.value("Cryo-SEM")).toObject();

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

void Gopher::ImportCryoSEMVitrobotSettings()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject vit = QJsonValue(sessionData.value("Vitrobot Settings")).toObject();

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

void Gopher::ImportConfocal()
{
    QString inFile;
    QFile file;
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "" ,"");
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    inFile = file.readAll();
    file.close();

    QJsonDocument input = QJsonDocument::fromJson(inFile.toUtf8());
    header = input.object();

    QJsonObject sessionData = QJsonValue(header.value("Session Data")).toObject();
    QJsonObject confocal = QJsonValue(sessionData.value("Confocal")).toObject();
}

