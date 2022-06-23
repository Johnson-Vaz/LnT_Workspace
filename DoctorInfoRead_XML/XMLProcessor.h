#ifndef XMLPROCESSOR_H
#define XMLPROCESSOR_H
#include <QtXml>
#include <QObject>
#include <QFile>
#include <QDebug>
#include "MyDoctor.h"

class XMLProcessor : public QObject
{
    Q_OBJECT
public:
    explicit XMLProcessor(QObject *parent = nullptr);
    ~XMLProcessor();

    void readXml();
signals:
    void sendXmlObj(QPointer<MyDoctor>);
private:
    QString docNam;
    QString qual;
    QString spec;

    MyDoctor *m_doctor;
};

#endif // XMLPROCESSOR_H
