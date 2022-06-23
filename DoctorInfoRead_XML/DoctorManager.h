#ifndef DOCTORMANAGER_H
#define DOCTORMANAGER_H
#include <QDebug>
#include <QObject>
#include <QList>
#include <MyDoctor.h>
#include <QPointer>
#include <XMLProcessor.h>

class DoctorManager : public QObject
{
    Q_OBJECT
public:
    explicit DoctorManager(QObject *parent = nullptr);
    ~DoctorManager();

    void init();
    void print();

public slots:
    void receiveData(QPointer<MyDoctor>);
signals:

private:
    QList<MyDoctor*> m_doctorList;
    XMLProcessor *m_xml;
};

#endif // DOCTORMANAGER_H
