#include "JsonProcessor.h"

JsonProcessor::JsonProcessor(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}


void JsonProcessor::readJson()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QFile file("D:/LandTProject/DoctorInfoRead_JSON_XML_CSV/doctorinfo.json");
    if(file.open(QIODevice::ReadOnly) )
    {
        cout<<"Json file opened successfully"<<endl;

        QByteArray bytes = file.readAll();

        file.close();

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson( bytes, &jsonError );
        if( jsonError.error != QJsonParseError::NoError )
        {
            cout << "fromJson failed: " << jsonError.errorString().toStdString() << endl;
            return ;
        }
        qDebug()<<"********************************"<<Qt::endl;
        if( document.isObject() )
        {
            qDebug()<<"Object found in document"<<Qt::endl;
            QJsonObject jsonObj = document.object();

//            QStringList doctors = {"Doctor1","Doctor2","Doctor3","Doctor4","Doctor5","Doctor6","Doctor7","Doctor8","Doctor9","Doctor10"};

            QStringList doctors = jsonObj.keys();
            for(auto doctor: doctors )
            {
                if( jsonObj.contains( doctor ) )
                {
                    m_docInfo = new MyDoctor;
                    QJsonObject obj = jsonObj.value( doctor ).toObject();//convert value to object
                    QStringList keys = obj.keys();

                    for( auto key: keys )
                    {
                        auto value = obj.take( key );
                        if(key == l_doctorName){
                            qDebug()<<"Doctor name: "<<value.toString()<<Qt::endl;
                            m_docInfo->setDoctorName(value.toString());
                        }
                        else if(key == l_speciality){
                            qDebug()<<"speciality: "<<value.toString()<<Qt::endl;
                            m_docInfo->setSpeciality(value.toString());
                        }
                        else if(key == l_qualification){
                            qDebug()<<"Qualification: "<<value.toString()<<Qt::endl;
                            m_docInfo->setQualification(value.toString());
                        }
                    }
                    emit sendJsonObj(m_docInfo);
                }
            }
        }
    }
}
JsonProcessor::~JsonProcessor()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    delete m_docInfo;
}
void JsonProcessor::init()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;

}

void JsonProcessor::print()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}


