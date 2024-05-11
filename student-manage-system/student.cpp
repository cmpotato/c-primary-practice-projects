#include "student.h"

student::student(QString name, QString gender, int age, QString ID)
{
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->ID = ID;
}
student::student():name("none"),gender("none"),age(0),ID("00000000")
{

}

bool student::operator<(const student &other)
{
    return this->ID.toInt() < other.ID.toInt();
}

bool student::operator>(const student &other)
{
    return this->ID.toInt() > other.ID.toInt();
}

void student::copy(const student stu)
{
    this->name = stu.name;
    this->gender = stu.gender;
    this->age = stu.age;
    this->ID = stu.ID;
}

QString student::show_all_info()
{
    return QString("name:%1\ngender:%2\nage:%3\nID:%4")
        .arg(this->name)
        .arg(this->gender)
        .arg(this->age)
        .arg(this->ID);
}

QString student::output_all_info()
{
    QString info;
    info += this->name + ' ';
    info += this->gender + ' ';
    info += QString::number(this->age) + ' ';
    info += this->ID;
    return info;
}

QString student::at(int index){
    switch (index) {
    case 0:
        return this->name;
        break;
    case 1:
        return this->gender;
        break;
    case 2:
        return QString(QString::number(this->age));
        break;
    case 3:
        return this->ID;
        break;
    default:
        break;
    }
    return QString("error");
}
