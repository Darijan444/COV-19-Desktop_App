QT += charts
QT += sql
requires(qtConfig(combobox))

HEADERS += \
    landingpage.h \
    signup.h \
    login.h \
    database.h \
    userpage.h \
    usercovid19testresult.h \
    userprofile.h \
    adminmain.h \
    adminusers.h \
    adminreports.h \
    adminlogs.h \
    adminuserdetail.h \
    userreportissue.h \
    userreportratresult.h \
    userrequestvaccinepass.h \
    uservaccinationresult.h


SOURCES += \
    main.cpp \
    landingpage.cpp \
    signup.cpp \
    login.cpp \
    database.cpp \
    userpage.cpp \
    usercovid19testresult.cpp \
    userprofile.cpp \
    adminusers.cpp \
    adminmain.cpp \
    adminreports.cpp \
    adminlogs.cpp \
    adminuserdetail.cpp \
    userreportissue.cpp \
    userreportratresult.cpp \
    userrequestvaccinepass.cpp \
    uservaccinationresult.cpp

target.path = /Users/Ryuuuu/QtProjects/Covid19RegistrationSystem3
INSTALLS += target

FORMS += \
    landingpage.ui \
    signup.ui \
    login.ui \
    userpage.ui \
    usercovid19testresult.ui \
    userprofile.ui \
    adminmain.ui \
    adminusers.ui \
    adminreports.ui \
    adminlogs.ui \
    adminuserdetail.ui \
    userreportissue.ui \
    userreportratresult.ui \
    userrequestvaccinepass.ui \
    uservaccinationresult.ui

RESOURCES += \
    Images.qrc


