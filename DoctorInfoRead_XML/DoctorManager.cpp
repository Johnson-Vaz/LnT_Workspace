#include "DoctorManager.h"

DoctorManager::DoctorManager(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
}

DoctorManager::~DoctorManager()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    for(auto it = m_doctorList.begin();it!=m_doctorList.end();it++){\
      delete (*it);
        qDebug()<<"Doctor object deleted"<<Qt::endl;
    }
}

void DoctorManager::init()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_xml = new XMLProcessor;
    connect(m_xml,&XMLProcessor::sendXmlObj,this,&DoctorManager::receiveData);
    m_xml->readXml();
}

void DoctorManager::print()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    for(auto it = m_doctorList.begin();it!=m_doctorList.end();it++){
        qDebug()<<" Doctor name ==="<<(*it)->doctorName()<<Qt::endl;
        qDebug()<<" Doctor speciality ==="<<(*it)->speciality()<<Qt::endl;
        qDebug()<<" Doctor qualification ==="<<(*it)->qualification()<<Qt::endl;

    }
}

void DoctorManager::receiveData(QPointer<MyDoctor> obj)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_doctorList.append(obj);
}


