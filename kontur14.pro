QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += c:/OpenCV/opencv/build/include/opencv2
INCLUDEPATH += c:\OpenCV\opencv\build\include\opencv
INCLUDEPATH += c:\OpenCV\opencv\sources\include\opencv
INCLUDEPATH += c:/OpenCV/opencv/build/include
LIBS += -Lc:\OpenCV\opencv\build\x64\vc15\bin
LIBS += -Lc:\OpenCV\opencv\build\x64\vc15\lib

# Под Win32 имена библиотек получают суффикс с номером версии (например, libopencv_core320.dll)
OPENCV_VER = 3416
#LIBS += -lopencv_world$${OPENCV_VER}
LIBS += -lopencv_world$${OPENCV_VER}d

SOURCES += \
        FindPoint.cpp \
        TextGrab.cpp \
        funct.cpp \
        main.cpp \
        preprocessing.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    FindPoint.h \
    TextGrab.h \
    funct.h \
    preprocessing.h
