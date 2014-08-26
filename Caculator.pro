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

# ����ģ��Ӧ�ó���
TEMPLATE = app

#ָ��rcc���.qrc�ļ�ת����qrc_*.h�ļ��Ĵ��Ŀ¼
RCC_DIR += ./tmp/rcc

#ָ��moc�����Q_OBJECT��ͷ�ļ�ת���ɱ�׼.h�ļ��Ĵ��Ŀ¼
MOC_DIR += ./tmp/moc

#ָ��Ŀ���ļ�(obj)�Ĵ��Ŀ¼
OBJECTS_DIR += ./tmp/obj

UI_DIR += tmp/ui

#������debug��releaseĿ¼
CONFIG -= debug_and_release

CONFIG(debug,debug|release):   TARGET = Caculatord
CONFIG(release,debug|release): TARGET = Caculator
#ָ�����ɵ�Ӧ�ó�����õ�Ŀ¼
DESTDIR = ./bin

#warn_on���ָ���qmakeҪ�ѱ���������Ϊ���������Ϣ�ġ�1
CONFIG += warn_on
