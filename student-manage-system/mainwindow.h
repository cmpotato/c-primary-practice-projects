#pragma once

#include <QMainWindow>
#include <QStandardItemModel>
#include "student.h"
#include "subwindows/add_new_student_widget.h"
#include "subwindows/get_name_dialog.h"
#include "subwindows/gender_dialog.h"
#include "subwindows/get_age_dialog.h"
#include "subwindows/get_id_dialog.h"

#define remove_table_column 4
#define icon_path ":/resources/system icon.png"
#define data_file_path "students_data_file.txt"

enum stackedwidget_index { white_board, student_list, remove_list, modify_list };

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //data
    QVector<student> data;
    QStandardItemModel data_model;
    QVector<student> search_result;
    QStandardItemModel search_result_model;

    QStandardItem name;
    QStandardItem gender;
    QStandardItem age;
    QStandardItem ID;

    void load_data();
    void save_data();

    //buffer
    QString re_name;
    QString re_gender;
    int re_age;
    QString re_ID;
    student re_stu;

    //subwindws
    add_new_student_widget add_w;
    get_name_dialog name_d;
    gender_dialog gender_d;
    get_age_dialog age_d;
    get_ID_dialog ID_d;

    //init
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //functions
    void test();
    void welcome();

    void delete_student(student s);
    void modify_student(student s);

    void init_search_result_database();
    void init_remove_list();
    void init_modify_list();
    void QVector_to_QStandardItemModel(QVector<student> &qv,QStandardItemModel &qm);//only data


public slots:

    void add_new_student();

    //receice message form new windows
    bool receive_new_student_info(QString name, QString gender, int age, QString ID);
    void receive_name(QString name);
    void receive_gender(QString gender);
    void receive_age(int age);
    void receive_ID(QString ID);
    void receive_student(student stu);

    //action functions
    void search_name();
    void search_gender();
    void search_age();
    void search_ID();
    void show_all_students_info();
    void show_remove_list();
    void show_modify_list();
    //void confirm_remove();

private slots:
    void on_pushButton_confirm_remove_clicked();

    void edit_student(int index);

private:
    Ui::MainWindow *ui;

};

