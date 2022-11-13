cmake_minimum_required(VERSION 3.5)

project(Covid19RegistrationSystem3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp

        ########################################################
        #Common
        ########################################################
        landingpage.h
        landingpage.cpp
        landingpage.ui

        signup.cpp
        signup.h
        signup.ui

        login.h
        login.cpp
        login.ui

        databaseusers.h
        databaseusers.cpp

        ########################################################
        #User
        ########################################################
        userpage.h
        userpage.cpp
        userpage.ui

        usercovid19testresult.h
        usercovid19testresult.cpp
        usercovid19testresult.ui

        userprofile.h
        userprofile.cpp
        userprofile.ui

        Images.qrc


        ########################################################
        #Admin
        ########################################################
        adminmain.h
        adminmain.cpp
        adminmain.ui

        adminusers.h
        adminusers.cpp
        adminusers.ui

        adminreports.h
        adminreports.cpp
        adminreports.ui

        adminlogs.h
        adminlogs.cpp
        adminlogs.ui

        adminuserdetail.h
        adminuserdetail.cpp
        adminuserdetail.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Covid19RegistrationSystem3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Covid19RegistrationSystem3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Covid19RegistrationSystem3 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Covid19RegistrationSystem3
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Covid19RegistrationSystem3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

set_target_properties(Covid19RegistrationSystem3 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Covid19RegistrationSystem3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Covid19RegistrationSystem3)
endif()
