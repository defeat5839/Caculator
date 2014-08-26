#include "Ui.h"

#include <QDebug>

/*******************************************************************************
 * 函数名称： Ui
 * 功能描述： Ui构造函数
 * 参数列表： parent - 父窗口指针
 *
 * 返回结果： 无
 ******************************************************************************/
Ui::Ui(QWidget *parent) :
    QFrame(parent)
{
    init();
    layout();
}

/*******************************************************************************
 * 函数名称： Ui
 * 功能描述： Ui析构函数
 * 参数列表： void
 *
 * 返回结果： 无
 ******************************************************************************/
Ui::~Ui()
{
}

/*******************************************************************************
 * 函数名称： init
 * 功能描述： 初始化
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::init()
{
    setWindowFlags(Qt::FramelessWindowHint); // 去掉窗体的边框
    setWindowIcon(QIcon("./image/1.png")); // 设置状态栏图片
    setFixedSize(324, 576); // 设置窗体大小

    m_titleBar.setFixedSize(324, 20); // 设置可拖拽区域大小
    m_titleBar.setObjectName("titleBar_Label"); // 设置可拖拽区域类名
    m_titleBar.setParent(this); // 设置可拖拽区域父窗体

    // 初始化数字按钮
    QString strNum = "";
    for (int i = 0; i < 10; ++i)
    {
        strNum = ("Num" + QString::number(i));
        m_numButtons[i].setObjectName(strNum); // 设置数字按钮的类名
        m_numButtons[i].setFixedSize(60, 75);  // 设置数字按钮的大小
        m_numButtons[i].setName(QString::number(i));
        connect(&m_numButtons[i], SIGNAL(clicked()), this, SLOT(numButtonClicked())); // 设置数字按钮和相应的槽函数关联
    }

    m_display.setFixedSize(324, 90); // 设置结果显示窗体的大小(是一个QLineEdit)
    m_display.setObjectName("result_Lable"); // 设置结果显示窗体的类名
    m_display.setParent(this); // 设置结果显示窗体的父窗体
    m_display.setText("0"); // 结果显示窗体的默认内容是为0
    m_display.setAlignment(Qt::AlignVCenter | Qt::AlignRight); // 结果显示窗体的文本设置向右对齐,上下居中
    m_display.setReadOnly(true); // 结果显示窗体的文本设置为只读
    m_display.setMaxLength(19); // 结果显示窗体的的最大长度的设置为19

    m_clearButton.setFixedSize(210,75); // 设置清除按钮大小
    m_clearButton.setObjectName("clear_btn"); // 设置清除按钮的类名
    connect(&m_clearButton, SIGNAL(clicked()), this, SLOT(clearButtonClicked())); // 设置清除按钮和相应的槽函数关联

    m_delButton.setFixedSize(90,75); // 设置删除按钮大小
    m_delButton.setObjectName("del_btn"); // 设置删除按钮的类名
    connect(&m_delButton, SIGNAL(clicked()), this, SLOT(delButtonClicked())); // 设置删除按钮和相应的槽函数关联

    m_addButton.setFixedSize(90,75); // 设置加法按钮大小
    m_addButton.setObjectName("add_btn");  // 设置加法按钮的类名
    connect(&m_addButton, SIGNAL(clicked()), this, SLOT(addButtonClicked())); // 设置加法按钮和相应的槽函数关联

    m_subButton.setFixedSize(90,75); // 设置减法按钮大小
    m_subButton.setObjectName("sub_btn"); // 设置减法按钮的类名
    connect(&m_subButton, SIGNAL(clicked()), this, SLOT(subButtonClicked())); // 设置减法按钮和相应的槽函数关联


    m_mulButton.setFixedSize(90,75); // 设置乘法按钮大小
    m_mulButton.setObjectName("mul_btn"); // 设置乘法按钮的类名
    connect(&m_mulButton, SIGNAL(clicked()), this, SLOT(mulButtonClicked())); // 设置乘法按钮和相应的槽函数关联

    m_divButton.setFixedSize(90,75); // 设置除法按钮大小
    m_divButton.setObjectName("div_btn"); // 设置除法按钮的类名
    connect(&m_divButton, SIGNAL(clicked()), this, SLOT(divButtonClicked())); // 设置除法按钮和相应的槽函数关联

    m_dotButton.setFixedSize(60, 75); // 设置小数点按钮大小
    m_dotButton.setObjectName("dot_btn"); // 设置小数点按钮的类名
    connect(&m_dotButton, SIGNAL(clicked()), this, SLOT(dotButtonClicked())); // 设置小数点按钮和相应的槽函数关联

    m_equalButton.setFixedSize(60, 75); // 设置等号按钮大小
    m_equalButton.setObjectName("equal_btn"); // 设置等号按钮的类名
    connect(&m_equalButton, SIGNAL(clicked()), this, SLOT(equalButtonClicked())); // 设置等号按钮和相应的槽函数关联

    m_bWaitForOprate = true;

    m_leftOperate  = 0.0; // 左操作数设置默认值

    m_eType = EAlgorithmType_Unkonw; // 算法类型设置为未知
}

/*******************************************************************************
 * 函数名称： layout
 * 功能描述： 布局
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::layout()
{
    m_titleBar.move(0, 0); // 可拖拽窗体移动到相对于父窗体的(0, 0)位置
    m_display.move(0, 20); // 结果显示窗体移动到相对于父窗体的(0, 20)位置

    QGridLayout *pGridLayout = new QGridLayout; // 创建网格布局
    Q_CHECK_PTR(pGridLayout);

    pGridLayout->setMargin(0);

    // 第一行,把清除按按钮和删除按钮加到网格布局里
    pGridLayout->addWidget(&m_clearButton, 0, 0, 1, 3);
    pGridLayout->addWidget(&m_delButton,   0, 3, 1, 1);

    // 第二行,把数字按钮按按钮7,8,9 和除法按钮加到网格布局里
    pGridLayout->addWidget(&m_numButtons[7], 1, 0, 1, 1);
    pGridLayout->addWidget(&m_numButtons[8], 1, 1, 1, 1);
    pGridLayout->addWidget(&m_numButtons[9], 1, 2, 1, 1);
    pGridLayout->addWidget(&m_divButton,     1, 3, 1, 1);

    // 第三行,把数字按钮按按钮4,5,6和乘法按钮加到网格布局里
    pGridLayout->addWidget(&m_numButtons[4], 2, 0, 1, 1);
    pGridLayout->addWidget(&m_numButtons[5], 2, 1, 1, 1);
    pGridLayout->addWidget(&m_numButtons[6], 2, 2, 1, 1);
    pGridLayout->addWidget(&m_mulButton,     2, 3, 1, 1);

    // 第四行,把数字按钮按按钮1,2,3和减法按钮加到网格布局里
    pGridLayout->addWidget(&m_numButtons[1], 3, 0, 1, 1);
    pGridLayout->addWidget(&m_numButtons[2], 3, 1, 1, 1);
    pGridLayout->addWidget(&m_numButtons[3], 3, 2, 1, 1);
    pGridLayout->addWidget(&m_subButton,     3, 3, 1, 1);

    // 第五行,把清小数点按钮,数字0按钮和等号按钮加到网格布局里
    pGridLayout->addWidget(&m_dotButton,     4, 0, 1, 1);
    pGridLayout->addWidget(&m_numButtons[0], 4, 1, 1, 1);
    pGridLayout->addWidget(&m_equalButton,   4, 2, 1, 1);
    pGridLayout->addWidget(&m_addButton,     4, 3, 1, 1);

    pGridLayout->setContentsMargins(2,2,2,2);
    pGridLayout->setMargin(2);
    pGridLayout->setSpacing(2);

    QFrame *pGrindFrame = new QFrame(this); // 创建网格窗体(因为布局一定要放到widget才行)
    Q_CHECK_PTR(pGrindFrame);
    pGrindFrame->setFixedSize(324, 465); // 设置网格窗体的大小
    pGrindFrame->setObjectName("bg"); // 设置网格窗体的类名
    pGrindFrame->setLayout(pGridLayout); // 设置布局(把布局加到widget)
    pGrindFrame->move(0, 110);
}

/*******************************************************************************
 * 函数名称： numButtonClicked
 * 功能描述： 数字按钮的槽函数
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::numButtonClicked()
{
    if (m_display.text() == "Error")
    {
        return;
    }

    // 把相应的数字按钮转化为响应的指针
    Button *pClickedButton = qobject_cast<Button *>(sender());
    Q_CHECK_PTR(pClickedButton);
    if ((m_display.text() == QString::number(0)) && (!m_display.text().contains(".")))
    {
         m_display.clear();
    }

    if (m_bWaitForOprate)
    {
        m_display.clear();
        m_display.setText(m_display.text() + pClickedButton->getName());

        m_bWaitForOprate = false;
    }
    else
    {
        m_display.setText(m_display.text() + pClickedButton->getName());
    }
}

/*******************************************************************************
 * 函数名称： addButtonClicked
 * 功能描述： 加法按钮的槽函数
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::addButtonClicked()
{
    // 算法类型不等于未知
    if (EAlgorithmType_Unkonw != m_eType)
    {
        // 通过算法上下文类调用相应的算法
        AlgorithmContext contxt(m_eType);
        m_display.setText(contxt.Calculate(m_leftOperate,
                                           m_display.text()));

        // 记录结果,为下次计算
        m_leftOperate = m_display.text();
    }
    else
    {
        // 记录结果,为下次计算
        m_leftOperate = m_display.text();
    }

    m_eType = EAlgorithmType_Add; // 设置算法类型为加法
    m_bWaitForOprate = true;
}

/*******************************************************************************
 * 函数名称： subButtonClicked
 * 功能描述： 减法按钮的槽函数
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::subButtonClicked()
{
    // 算法类型不等于未知
    if (EAlgorithmType_Unkonw != m_eType)
    {
        // 通过算法上下文类调用相应的算法
        AlgorithmContext contxt(m_eType);
        m_display.setText(contxt.Calculate(m_leftOperate,
                                           m_display.text()));

        // 记录结果,为下次计算
        m_leftOperate = m_display.text();
    }
    else
    {
        // 记录结果,为下次计算
        m_leftOperate = m_display.text();
    }

    m_eType = EAlgorithmType_Sub; // 设置算法类型为减法
    m_bWaitForOprate = true;
}

/*******************************************************************************
 * 函数名称： mulButtonClicked
 * 功能描述： 乘法按钮的槽函数
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::mulButtonClicked()
{
    // 算法类型不等于未知
    if (EAlgorithmType_Unkonw != m_eType)
    {
        // 通过算法上下文类调用相应的算法
        AlgorithmContext contxt(m_eType);
        m_display.setText(contxt.Calculate(m_leftOperate,
                                           m_display.text()));

        // 记录结果,为下次计算
        m_leftOperate = m_display.text();
    }
    else
    {
        // 记录结果,为下次计算
        m_leftOperate = m_display.text();
    }

    m_bWaitForOprate = true;
    m_eType = EAlgorithmType_Mul; // 设置算法类型为乘法
}

/*******************************************************************************
 * 函数名称： divButtonClicked
 * 功能描述： 除法按钮的槽函数
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::divButtonClicked()
{
    // 算法类型不等于未知
    if (EAlgorithmType_Unkonw != m_eType)
    {
        // 通过算法上下文类调用相应的算法
        AlgorithmContext contxt(m_eType);
        m_display.setText(contxt.Calculate(m_leftOperate,
                                           m_display.text()));

        // 记录结果,为下次计算
        m_leftOperate = m_display.text();
    }
    else
    {
        m_leftOperate = m_display.text();
    }

    m_bWaitForOprate = true;
    m_eType = EAlgorithmType_Div; // 设置算法类型为除法
}

/*******************************************************************************
 * 函数名称： clearButtonClicked
 * 功能描述： 清除按钮的槽函数
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::clearButtonClicked()
{
    m_eType = EAlgorithmType_Unkonw; // 重置算法类型
    m_display.setText("0"); // 重置文本内容
    m_leftOperate  = 0.0; // 重置左操作数
    m_bWaitForOprate = true; // 重置标志位
}

/*******************************************************************************
 * 函数名称： dotButtonClicked
 * 功能描述： 小数点按钮的槽函数
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::dotButtonClicked()
{
    // 如果已经有小数点了
    if (m_display.text().contains("."))
    {
        return;
    }

    // 如果显示结果窗体为空
    if (m_display.text().isEmpty())
    {
        m_display.setText("0.");
    }
    else
    {
        // 否则添加小数点
        m_display.setText(m_display.text() + ".");
    }
}

/*******************************************************************************
 * 函数名称： delButtonClicked
 * 功能描述： 删除按钮的槽函数
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::delButtonClicked()
{
    QString text = "";
    if (m_display.text().isEmpty())
    {
        // 如果只有一个数字,删除后重置为0
        text = "0";
    }
    else
    {
        // 删除最后一个字符
        text = m_display.text().remove(m_display.text().size()-1, 1);
        if (text.isEmpty())
        {
            // 如果只有一个数字,删除后重置为0
            text = "0";
        }
    }

    // 设置删除后的结果
    m_display.setText(text);
}

/*******************************************************************************
 * 函数名称： equalButtonClicked
 * 功能描述： 等号按钮的槽函数
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void Ui::equalButtonClicked()
{
//    qDebug() << m_eType;
//    qDebug() << m_leftOperate;
//    qDebug() << m_display.text();

    // 算法类型不等于未知
    if (EAlgorithmType_Unkonw != m_eType)
    {
        // 调用算法上下文类进行计算结果
        AlgorithmContext contxt(m_eType);
        m_display.setText(contxt.Calculate(m_leftOperate,
                                           m_display.text()));

        m_leftOperate = m_display.text(); // 把这此结果记录为左操作数,为了下次计算用
        m_eType = EAlgorithmType_Unkonw; // 重置算法类型
        m_bWaitForOprate = true; // 是否在等在操作符号
    }
}
