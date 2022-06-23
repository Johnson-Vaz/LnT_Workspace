#include "MyDoctor.h"

MyDoctor::MyDoctor(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

MyDoctor::~MyDoctor()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &MyDoctor::doctorName() const
{
    return m_doctorName;
}

void MyDoctor::setDoctorName(const QString &newDoctorName)
{
    m_doctorName = newDoctorName;
    emit doctorNameChanged();
}

const QString &MyDoctor::speciality() const
{
    return m_speciality;
}

void MyDoctor::setSpeciality(const QString &newSpeciality)
{
    m_speciality = newSpeciality;
    emit specialityChanged();
}

const QString &MyDoctor::qualification() const
{
    return m_qualification;
}

void MyDoctor::setQualification(const QString &newQualification)
{
    m_qualification = newQualification;
    emit qualificationChanged();
}
