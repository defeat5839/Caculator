QT += core \
      gui  \
      widgets

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

SOURCES += \
    src/AddStrategy.cpp \
    src/AlgorithmContext.cpp \
    src/Button.cpp \
    src/DivStrategy.cpp \
    src/main.cpp \
    src/MulStrategy.cpp \
    src/SubStrategy.cpp \
    src/TitleBar.cpp \
    src/Ui.cpp \
    src/AlgorithmStrategyFactory.cpp

HEADERS += \
    src/AddStrategy.h \
    src/AlgorithmContext.h \
    src/AlgorithmStrategy.h \
    src/Button.h \
    src/DivStrategy.h \
    src/MulStrategy.h \
    src/SubStrategy.h \
    src/TitleBar.h \
    src/Ui.h \
    src/AlgorithmStrategyFactory.h

RC_FILE += desktop.rc

RESOURCES += \
    rec.qrc

# 程序模板应用程序
TEMPLATE = app

#指定rcc命令将.qrc文件转换成qrc_*.h文件的存放目录
RCC_DIR += ./tmp/rcc

#指定moc命令将含Q_OBJECT的头文件转换成标准.h文件的存放目录
MOC_DIR += ./tmp/moc

#指定目标文件(obj)的存放目录
OBJECTS_DIR += ./tmp/obj

UI_DIR += tmp/ui

#不生成debug和release目录
CONFIG -= debug_and_release

CONFIG(debug,debug|release):   TARGET = Caculatord
CONFIG(release,debug|release): TARGET = Caculator
#指定生成的应用程序放置的目录
DESTDIR = ./bin

#warn_on部分告诉qmake要把编译器设置为输出警告信息的。1
CONFIG += warn_on
