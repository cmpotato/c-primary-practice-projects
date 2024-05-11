QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    student.cpp \
    subwindows/add_new_student_widget.cpp \
    subwindows/gender_dialog.cpp \
    subwindows/get_age_dialog.cpp \
    subwindows/get_id_dialog.cpp \
    subwindows/get_name_dialog.cpp \
    subwindows/modify_dialog.cpp \
    subwindows/secondary_confirm.cpp

HEADERS += \
    mainwindow.h \
    student.h \
    subwindows/add_new_student_widget.h \
    subwindows/gender_dialog.h \
    subwindows/get_age_dialog.h \
    subwindows/get_id_dialog.h \
    subwindows/get_name_dialog.h \
    subwindows/modify_dialog.h \
    subwindows/secondary_confirm.h

FORMS += \
    mainwindow.ui \
    subwindows/add_new_student_widget.ui \
    subwindows/gender_dialog.ui \
    subwindows/get_age_dialog.ui \
    subwindows/get_id_dialog.ui \
    subwindows/get_name_dialog.ui \
    subwindows/modify_dialog.ui \
    subwindows/secondary_confirm.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

