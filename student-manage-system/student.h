#pragma once

#include <QString>

#define student_parameters 4

class student
{
public:

    QString name;
    QString gender;
    int age;
    QString ID;

    student(QString name, QString gender, int age, QString ID);
    student();
    bool operator<(const student &other);
    bool operator>(const student &other);
    void copy(const student stu);
    QString at(int index);
    QString show_all_info();
    QString output_all_info();
};
