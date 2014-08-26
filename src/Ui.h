/*******************************************************************************
 * 类名: Ui
 * 功能: 实现计算器界面显示
 ******************************************************************************/

#ifndef UI_H
#define UI_H

#include <QFrame>
#include <QVector>
#include <QLineEdit>
#include <QGridLayout>
#include <QPalette>

#include "Button.h"
#include "TitleBar.h"
#include "AlgorithmContext.h"

class Ui : public QFrame
{
    Q_OBJECT
public:
    explicit Ui(QWidget *parent = 0);
    ~Ui();

private:
    void init();
    void layout();

public slots:
    void numButtonClicked();
    void addButtonClicked();
    void subButtonClicked();
    void mulButtonClicked();
    void divButtonClicked();
    void clearButtonClicked();
    void dotButtonClicked();
    void delButtonClicked();
    void equalButtonClicked();

private:
    QLineEdit m_display;
    Button m_clearButton; // 清除按钮
    Button m_delButton;   // 删除按钮
    Button m_addButton;   // 加法按钮
    Button m_subButton;   // 减法按钮
    Button m_mulButton;   // 乘法按钮
    Button m_divButton;   // 除法按钮
    Button m_dotButton;   // 小数点按钮
    Button m_equalButton; // 等号按钮
    Button m_numButtons[10]; // 数字按钮集合

    TitleBar m_titleBar;

    EAlgorithmType m_eType;
    bool m_bWaitForOprate;

    QString m_leftOperate;
};

#endif // UI_H
