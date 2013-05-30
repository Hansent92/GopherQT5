#include "tem2d.h"
#include "gopher.h"

tem2D::tem2D(QObject *parent) :
    QJsonDocument(parent)
{
//    case 1://TEM 2D
//    {
//        ui->stackedWidget->setCurrentIndex(1);
//        ui->tem2D_Toolbox->setItemIcon(0,QIcon(pointer));
//    }




//    case 1://TEM 2D
//    {
//        QJsonObject list;

//        QJsonObject sessionData;//Intro
//        sessionData.insert("Data Taken By", ui->DataTakenBy->currentText());
//        //    sessionData.insert("Date", ui->dateTimeEdit);
//        sessionData.insert("Project ID", ui->ProjectID->displayText());
//        sessionData.insert("Subset ID", ui->SubsetID->displayText());
//        sessionData.insert("Instrument", ui->Instrument->currentText());
//        sessionData.insert("Descriptive Title", ui->DescriptiveTitleText->displayText());
//        sessionData.insert("Specimen/Organism", ui->Specimen_Organism->currentText());
//        sessionData.insert("Sample prep", ui->SamplePrepText->toPlainText());
//        sessionData.insert("Notes", ui->NotesText->toPlainText());

//        list.insert("Data",sessionData);

//        QJsonObject sessionData3;//TEM 2D
//        sessionData3.insert("Camara", ui->Camera_TEM2D_2->currentText());
//        sessionData3.insert("Energy Filter Slit Size", ui->EnergyFilterSlitSize_Text_TEM2D_2->displayText());
//        sessionData3.insert("Acquisition Software",ui->AcquisitionSoftware_TEM2D_2->currentText());
//        sessionData3.insert("Voltage",ui->Voltage_Text_TEM2D_2->displayText());
//        sessionData3.insert("Cs Value",ui->CsValue_Text_TEM2D_2->displayText());

//        list.insert("TEM 2D",sessionData3);

//        QJsonDocument doc = QJsonDocument(list);
//        doc.setObject(list);

//        //("c:/Users/hansentd/Desktop/Gopher4/Tests/myFile2.json")
//        QFile file;
//        QString filename = QFileDialog::getSaveFileName(this, "Save file",(ui->SubsetID->displayText()),"Text Files (*.json)");
//        QFileDialog::DialogLabel::FileType;
//        file.setFileName(filename);
//        if(file.open(QFile::ReadOnly | QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
//        {
//            file.write(doc.toJson());
//            file.close();
//        }
//    }
}
