QT += charts
QT += sql
requires(qtConfig(combobox))

HEADERS += \
#    adminuserdetail2.h \
    adminuserdetail3.h \
    landingpage.h \
    signup.h \
    login.h \
#    database.h \
    userpage.h \
    usercovid19testresult.h \
    userprofile.h \
    adminmain.h \
    adminusers.h \
    adminreports.h \
    adminlogs.h \
#    adminuserdetail.h \
    userreportissue.h \
    userreportratresult.h \
    userrequestvaccinepass.h \
    uservaccinationresult.h \
    uservaccinepass.h


SOURCES += \
#    adminuserdetail2.cpp \
    adminuserdetail3.cpp \
    main.cpp \
    landingpage.cpp \
    signup.cpp \
    login.cpp \
#    database.cpp \
    userpage.cpp \
    usercovid19testresult.cpp \
    userprofile.cpp \
    adminusers.cpp \
    adminmain.cpp \
    adminreports.cpp \
    adminlogs.cpp \
#    adminuserdetail.cpp \
    userreportissue.cpp \
    userreportratresult.cpp \
    userrequestvaccinepass.cpp \
    uservaccinationresult.cpp \
    uservaccinepass.cpp

target.path = /Users/Ryuuuu/QtProjects/Covid19RegistrationSystem3
INSTALLS += target

FORMS += \
#    adminuserdetail2.ui \
    adminuserdetail3.ui \
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
#    adminuserdetail.ui \
    userreportissue.ui \
    userreportratresult.ui \
    userrequestvaccinepass.ui \
    uservaccinationresult.ui \
    uservaccinepass.ui

RESOURCES += \
    Images.qrc


