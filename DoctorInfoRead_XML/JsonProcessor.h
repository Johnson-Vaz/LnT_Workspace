#ifndef JSONPROCESSOR_H
#define JSONPROCESSOR_H
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <iostream>
#include <MyDoctor.h>
#include <QPointer>
using namespace std;

class JsonProcessor : public QObject
{
    Q_OBJECT
public:
    explicit JsonProcessor(QObject *parent = nullptr);
    ~JsonProcessor();

    void init();
    void print();
    void readJson();
signals:
    void sendJsonObj(QPointer<MyDoctor>);

private:

    MyDoctor *m_docInfo;
    QString l_doctorName = "doctorname";
    QString l_speciality = "speciality";
    QString l_qualification = "qualification";

};

#endif // JSONPROCESSOR_H
