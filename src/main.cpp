#include <QApplication>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QTextCodec>
#include "Ui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::addLibraryPath("./plugins");

    // 以下部分解决中文乱码
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    // 以上部分解决中文乱码

    QFile file(":my.qss");
    if (file.open(QFile::ReadOnly))
    {
        qApp->setStyleSheet(file.readAll());
        file.close();
    }
    else
    {
        QMessageBox::warning(NULL, "警告", "加载  <font color='red'>my.qss</font> 失败");
        exit(-1);
    }

    Ui ui;
    ui.show();

    return app.exec();
}
