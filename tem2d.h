#ifndef TEM2D_H
#define TEM2D_H

#include <QJsonDocument>

class tem2D : public QJsonDocument
{
    Q_OBJECT
public:
    explicit tem2D(QObject *parent = 0);
    
signals:
    
public slots:
    QString camera;
    qint32 energyFilterSlitSize;
    QString acquisitionSoftware;
    qint32 voltage;
    QString csValue;
    
};

#endif // TEM2D_H
