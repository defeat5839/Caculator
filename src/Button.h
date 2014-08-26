/*******************************************************************************
 * 类名: Button
 * 功能: 继承自QPushButton,主要是记录按钮的名字
 ******************************************************************************/

#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QString>

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = 0);
    void setName(const QString name);
    QString getName();
private:
    QString m_name;
};

#endif // BUTTON_H
