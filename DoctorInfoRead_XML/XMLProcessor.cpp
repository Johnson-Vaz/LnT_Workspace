#include "XMLProcessor.h"

XMLProcessor::XMLProcessor(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<< Qt::endl;
}

XMLProcessor::~XMLProcessor()
{
    qDebug()<<Q_FUNC_INFO<< Qt::endl;
    delete m_doctor;
}


void XMLProcessor::readXml()
{
    qDebug()<<Q_FUNC_INFO<< Qt::endl;
    QDomDocument document;
    QFile file("D:/LandTProject/DoctorInfoRead_XML/doctorinfo.xml");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open the file for reading.";
    }
    document.setContent(&file);//parse XML doc from byte array data & detects encoding
    file.close();

    QDomElement rootele = document.documentElement();// returns root element of document
    QString  elelist = rootele.tagName();

    qDebug()<<"============================"<<elelist <<Qt::endl;
    QDomElement Component = rootele.firstChild().toElement();
    qDebug()<<"============================"<<Component.tagName() <<Qt::endl;

    m_doctor = new MyDoctor;
    while(!Component.isNull())
    {
        if (Component.tagName()=="doctor")
        {

            QDomElement Child=Component.firstChild().toElement(); // Get the first child of the component
            qDebug()<<"Fisrt child =="<<Child.tagName();
            while (!Child.isNull())
            {
                // Read Name and value
                if (Child.tagName()=="doctorName") {
                    docNam = Child.firstChild().toText().data();
                    m_doctor->setDoctorName(docNam);
                    qDebug()<<docNam<<Qt::endl;
                }
                else if (Child.tagName()=="speciality") {
                    spec = Child.firstChild().toText().data();
                    m_doctor->setSpeciality(spec);
                    qDebug()<<spec<<Qt::endl;
                }
                else if (Child.tagName()=="qualification") {
                    qual = Child.firstChild().toText().data();
                    m_doctor->setQualification(qual);
                    qDebug()<<qual<<Qt::endl;
                }
                // Next child
                Child = Child.nextSibling().toElement();
            }
            Component = Component.nextSibling().toElement();
            emit sendXmlObj(m_doctor);
        }
    }
}
