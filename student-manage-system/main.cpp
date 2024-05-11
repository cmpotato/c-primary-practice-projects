#include "mainwindow.h"
#include "student.h"

#include <QApplication>
#include <QIcon>

void add_test_students(MainWindow &w)
{
    w.data.push_back(student("lisa", "female", 19, "00000004"));
    w.data.push_back(student("david", "male", 20, "00000003"));
    w.data.push_back(student("tony", "male", 24, "00000001"));
    w.data.push_back(student("aliya", "female", 18, "00000002"));
    w.data.push_back(student("tyrion", "male", 30, "00000090"));
    w.data.push_back(student("admin", "female", 25, "00000000"));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //add_test_students(w);
    w.load_data();

    w.show();
    w.welcome();

    return a.exec();
}
