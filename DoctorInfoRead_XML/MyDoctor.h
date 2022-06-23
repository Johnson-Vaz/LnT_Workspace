#ifndef MYDOCTOR_H
#define MYDOCTOR_H
#include <QDebug>
#include <QObject>

class MyDoctor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString doctorname READ doctorName WRITE setDoctorName NOTIFY doctorNameChanged)
    Q_PROPERTY(QString speciality READ speciality WRITE setSpeciality NOTIFY specialityChanged)
    Q_PROPERTY(QString qualification READ qualification WRITE setQualification NOTIFY qualificationChanged)

public:
    explicit MyDoctor(QObject *parent = nullptr);
    ~MyDoctor();

    const QString &doctorName() const;
    void setDoctorName(const QString &newDoctorName);

    const QString &speciality() const;
    void setSpeciality(const QString &newSpeciality);

    const QString &qualification() const;
    void setQualification(const QString &newQualification);

signals:
    void doctorNameChanged();
    void specialityChanged();
    void qualificationChanged();

private:
    QString m_doctorName;
    QString m_speciality;
    QString m_qualification;
};

#endif // MYDOCTOR_H
