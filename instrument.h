#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "ui_gopher.h"

#include <QWidget>
#include <QVariant>

class instrument : public QWidget
{
    Q_OBJECT
public:
    explicit instrument(QWidget *parent = 0);
    
signals:
    void instrumentImageMode();
    void instrumentCamera();
    void instumentAquisitionSoftware();
    
public slots:



    
};

#endif // INSTRUMENT_H
