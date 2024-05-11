#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subwindows/secondary_confirm.h"
#include "subwindows/modify_dialog.h"
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QIcon>
#include <QCheckBox>
#include <QStandardItemModel>
#include <QPushButton>
#include <algorithm>
#include <QFile>
#include <QTextStream>
#include <QStringList>

void MainWindow::load_data()
{
    QFile df(data_file_path);
    if (!df.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading: " << df.errorString();
        return;
    }
    QTextStream in(&df);

    while (!in.atEnd()) {
        QString str = in.readLine();
        if (str.isEmpty()) {
            continue;
        }
        QStringList infos = str.split(' ', Qt::SkipEmptyParts);
        if (infos.size() != 4) {
            qDebug() << "data file error";
            continue;
        }
        student s(infos.at(0), infos.at(1), infos.at(2).toInt(), infos.at(3));
        this->data.push_back(s);
    }

    df.close();
}

void MainWindow::save_data()
{
    QFile df(data_file_path);
    if (!df.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing: " << df.errorString();
        return;
    }
    QTextStream out(&df);

    //write data
    for (auto &s : this->data) {
        out << s.output_all_info();
        out << Qt::endl;
    }

    df.close();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //init ui
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(stackedwidget_index::white_board);

    //set data
    this->data_model.setHorizontalHeaderItem(0, new QStandardItem("name"));
    this->data_model.setHorizontalHeaderItem(1, new QStandardItem("gender"));
    this->data_model.setHorizontalHeaderItem(2, new QStandardItem("age"));
    this->data_model.setHorizontalHeaderItem(3, new QStandardItem("ID"));

    //set icon
    this->setWindowIcon(QIcon(icon_path));

    //connection

    //subwindows signals
    connect(&add_w,
            &add_new_student_widget::send_student_info,
            this,
            &MainWindow::receive_new_student_info);
    connect(&name_d, &get_name_dialog::send, this, &MainWindow::receive_name);
    connect(&gender_d, &gender_dialog::send, this, &MainWindow::receive_gender);
    connect(&age_d, &get_age_dialog::send, this, &MainWindow::receive_age);
    connect(&ID_d, &get_ID_dialog::send, this, &MainWindow::receive_ID);

    //mainwindow action
    //add
    connect(ui->action_new_student, &QAction::triggered, this, &MainWindow::add_new_student);
    //show
    connect(ui->actionAll_Students_Info,
            &QAction::triggered,
            this,
            &MainWindow::show_all_students_info);
    //search
    connect(ui->action_Search_By_Name, &QAction::triggered, this, &MainWindow::search_name);
    connect(ui->action_Search_By_Gender, &QAction::triggered, this, &MainWindow::search_gender);
    connect(ui->action_Search_By_Age, &QAction::triggered, this, &MainWindow::search_age);
    connect(ui->action_Search_By_ID, &QAction::triggered, this, &MainWindow::search_ID);
    //remove
    connect(ui->action_remove_list, &QAction::triggered, this, &MainWindow::show_remove_list);
    //connect(ui->pushButton_confirm_remove,&QPushButton::clicked,this,&MainWindow::on_pushButton_confirm_remove_clicked);
    //modefy
    connect(ui->action_modify_list, &QAction::triggered, this, &MainWindow::show_modify_list);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test() {}

void MainWindow::welcome()
{
    ui->textBrowser->append("welcome to student management system!");
    ui->textBrowser->append("please push the button above to begin.");
}

void MainWindow::add_new_student()
{
    ui->textBrowser->clearHistory();
    add_w.show();
}

bool MainWindow::receive_new_student_info(QString name, QString gender, int age, QString ID)
{
    // judge parameter range
    if (age < 0 || age > 100) {
        QMessageBox::warning(&this->add_w, "age error", "invalid age.");
        return false;
    }
    if (ID.length() != 8) {
        QMessageBox::warning(&this->add_w, "id error", "wrong ID digits.");
        return false;
    }

    //create new student and check repetitive ID
    student s(name, gender, age, ID);
    for (auto &i : this->data) {
        if(i.ID==s.ID){
            QMessageBox::warning(&this->add_w, "Error", "Student already exists！Duplicated ID.");
            return false;
        }
    }

    //add new student
    this->add_w.close();
    this->data.push_back(s);
    this->save_data();
    //show add infomation
    ui->stackedWidget->setCurrentIndex(stackedwidget_index::white_board);
    ui->textBrowser->append("Add successfully.\nNew student Info:");
    ui->textBrowser->append(s.show_all_info());
    return true;
}

void MainWindow::show_all_students_info(){
    ui->textBrowser->clear();
    std::sort(this->data.begin(),this->data.end());
    //set data model
    this->QVector_to_QStandardItemModel(this->data,this->data_model);

    //display data model to tableview
    ui->tableView->setModel(&this->data_model);
    ui->tableView->resizeColumnsToContents();

    //switch stackwidegt
    ui->stackedWidget->setCurrentIndex(stackedwidget_index::student_list);
    this->save_data();
}

void MainWindow::show_remove_list()
{
    this->init_remove_list();
    ui->stackedWidget->setCurrentIndex(stackedwidget_index::remove_list);
}

void MainWindow::show_modify_list()
{
    this->init_modify_list();
    ui->stackedWidget->setCurrentIndex(stackedwidget_index::modify_list);
}

void MainWindow::search_name()
{

    //get name from a new dialog
    if (this->name_d.exec() == QDialog::Accepted) {
        //get re_name and search database
        this->init_search_result_database();
        for (auto &s : this->data) {
            if (s.name == this->re_name) {
                search_result.push_back(s);
            }
        }

        //if no students found
        if(search_result.empty()){
            QMessageBox::warning(this,"empty result","no student matching the infomation.");
            return;
        }

        //set search data model
        this->QVector_to_QStandardItemModel(this->search_result, this->search_result_model);

        //display search data model to tableview
        ui->tableView->setModel(&this->search_result_model);
        ui->tableView->resizeColumnsToContents();

        //switch stackwidegt
        ui->stackedWidget->setCurrentIndex(stackedwidget_index::student_list);
    }
    return;
}

void MainWindow::search_gender(){
    if (this->gender_d.exec() == QDialog::Accepted) {
        this->init_search_result_database();
        for (auto &s : this->data) {
            if (s.gender == this->re_gender) {
                search_result.push_back(s);
            }
        }

        if(search_result.empty()){
            QMessageBox::warning(this, "empty result", "no student matching the infomation.");
            return;
        }

        this->QVector_to_QStandardItemModel(this->search_result, this->search_result_model);

        ui->tableView->setModel(&this->search_result_model);
        ui->tableView->resizeColumnsToContents();
        ui->stackedWidget->setCurrentIndex(stackedwidget_index::student_list);
    }
    return;
}

void MainWindow::search_age()
{
    if (this->age_d.exec() == QDialog::Accepted) {
        this->init_search_result_database();
        for (auto &s : this->data) {
            if (s.age == this->re_age) {
                search_result.push_back(s);
            }
        }

        if(search_result.empty()){
            QMessageBox::warning(this, "empty result", "no student matching the infomation.");
            return;
        }
        this->QVector_to_QStandardItemModel(this->search_result, this->search_result_model);
        ui->tableView->setModel(&this->search_result_model);
        ui->tableView->resizeColumnsToContents();
        ui->stackedWidget->setCurrentIndex(stackedwidget_index::student_list);
    }
    return;
}

void MainWindow::search_ID(){
    if (this->ID_d.exec() == QDialog::Accepted) {
        this->init_search_result_database();
        for (auto &s : this->data) {
            if (s.ID == this->re_ID) {
                search_result.push_back(s);
            }
        }

        if(search_result.empty()){
            QMessageBox::warning(this, "empty result", "no student matching the infomation.");
            return;
        }
        this->QVector_to_QStandardItemModel(this->search_result, this->search_result_model);
        ui->tableView->setModel(&this->search_result_model);
        ui->tableView->resizeColumnsToContents();
        ui->stackedWidget->setCurrentIndex(stackedwidget_index::student_list);
    }
    return;
}

void MainWindow::init_search_result_database(){
    this->search_result.clear();
    this->search_result_model.clear();
    //set data model header
    this->search_result_model.setHorizontalHeaderItem(0, new QStandardItem("name"));
    this->search_result_model.setHorizontalHeaderItem(1, new QStandardItem("gender"));
    this->search_result_model.setHorizontalHeaderItem(2, new QStandardItem("age"));
    this->search_result_model.setHorizontalHeaderItem(3, new QStandardItem("ID"));
}

void MainWindow::init_remove_list()
{
    //clear
    ui->tableWidget_remove->clear();
    ui->tableWidget_remove->setRowCount(0);

    //init table widget headers
    ui->tableWidget_remove->setColumnCount(student_parameters + 1);
    QStringList headers = {"name", "gender", "age", "ID", "check"};
    ui->tableWidget_remove->setHorizontalHeaderLabels(headers);
    ui->tableWidget_remove->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

    //sort students data
    std::sort(data.begin(), data.end());

    //add student item to table
    for (int row = 0; row < this->data.size(); row++) {
        //set student info
        ui->tableWidget_remove->insertRow(row);
        for (int col = 0; col < ui->tableWidget_remove->columnCount() - 1; col++){
            ui->tableWidget_remove->setItem(row, col, new QTableWidgetItem(this->data[row].at(col)));
            ui->tableWidget_remove->item(row,col)->setTextAlignment(Qt::AlignCenter);
        }
        //set check box
        ui->tableWidget_remove->setCellWidget(row,
                                              ui->tableWidget_remove->columnCount() - 1,
                                              new QCheckBox());
    }
    ui->tableWidget_remove->resizeColumnsToContents();
}

void MainWindow::init_modify_list()
{
    ui->tableWidget_modify->clear();
    ui->tableWidget_modify->setRowCount(0);
    ui->tableWidget_modify->setColumnCount(student_parameters + 1);
    QStringList headers = {"name", "gender", "age", "ID", "modify"};
    ui->tableWidget_modify->setHorizontalHeaderLabels(headers);
    ui->tableWidget_modify->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

    std::sort(this->data.begin(), this->data.end());

    for (int row = 0; row < this->data.size(); row++) {
        ui->tableWidget_modify->insertRow(row);
        for (int col = 0; col < ui->tableWidget_modify->columnCount() - 1; col++) {
            ui->tableWidget_modify->setItem(row, col, new QTableWidgetItem(this->data[row].at(col)));
            ui->tableWidget_modify->item(row, col)->setTextAlignment(Qt::AlignCenter);
        }
        //set modify button
        QPushButton *pb = new QPushButton("Edit");
        ui->tableWidget_modify->setCellWidget(row, ui->tableWidget_modify->columnCount() - 1, pb);
        connect(pb, &QPushButton::clicked, this, [this, row]() { this->edit_student(row); });
    }
    ui->tableWidget_modify->resizeColumnsToContents();
}

void MainWindow::QVector_to_QStandardItemModel(QVector<student> &qv,QStandardItemModel &qm){
    qm.setColumnCount(student_parameters);
    qm.setRowCount(qv.size());
    for (int row = 0; row < qm.rowCount(); row++) {
        for (int col = 0; col < qm.columnCount(); col++) {
            qm.setData(qm.index(row, col, QModelIndex()), QString(qv[row].at(col)));
        }
    }
}

void MainWindow::receive_name(QString name){
    this->re_name = name;
}

void MainWindow::receive_gender(QString gender)
{
    this->re_gender = gender;
}

void MainWindow::receive_age(int age)
{
    this->re_age = age;
}

void MainWindow::receive_ID(QString ID){
    this->re_ID = ID;
}

void MainWindow::receive_student(student stu)
{
    this->re_stu.copy(stu);
}

void MainWindow::on_pushButton_confirm_remove_clicked()
{
    int mcol = ui->tableWidget_remove->columnCount() - 1;

    //secondary confirm window
    secondary_confirm sc;
    if (sc.exec() == QDialog::Accepted) {
        //iterate table widget and remove students checked
        //QVector<int> mark;
        for (int row = mcol; row >= 0; row--) {
            QCheckBox *cb = static_cast<QCheckBox *>(ui->tableWidget_remove->cellWidget(row, mcol));
            if (cb && cb->isChecked()) {
                this->data.removeAt(row);
                //mark.push_back(row);
            }
        }
        //refresh table widget
        this->show_remove_list();
    }
    this->save_data();
}

void MainWindow::edit_student(int index)
{
    modify_dialog md(nullptr, this->data[index]);
    connect(&md, &modify_dialog::send, this, &MainWindow::receive_student);
    if (md.exec() == QDialog::Rejected) {
        return;
    }
    //accepted and get re_stu
    this->data[index].copy(this->re_stu);
    this->save_data();
    QMessageBox::warning(this, "modify", "Modify information successfully.");
    this->show_modify_list();
    disconnect(&md, &modify_dialog::send, this, &MainWindow::receive_student);
}
