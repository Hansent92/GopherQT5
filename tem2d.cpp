#include "tem2d.h"
#include "gopher.h"
#include "ui_gopher.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonDocument>
tem2d::tem2d()
{

}
void Gopher::SaveTEM2D()
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

    QJsonObject sessionObject3;//TEM 2D
    sessionObject3.insert("Camera", ui->Camera_TEM2D_2->currentText());
    sessionObject3.insert("Energy Filter Slit Size", ui->EnergyFilterSlitSize_Text_TEM2D_2->displayText());
    sessionObject3.insert("Acquisition Software",ui->AcquisitionSoftware_TEM2D_2->currentText());
    sessionObject3.insert("Voltage",ui->Voltage_Text_TEM2D_2->displayText());
    sessionObject3.insert("Cs Value",ui->CsValue_Text_TEM2D_2->displayText());

    list.insert("TEM 2D",sessionObject3);
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
