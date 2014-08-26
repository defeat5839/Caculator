#include "TitleBar.h"

/*******************************************************************************
 * 函数名称： TitleBar
 * 功能描述： TitleBar构造函数
 * 参数列表： parent - 父指针
 *
 * 返回结果： 无
 ******************************************************************************/
TitleBar::TitleBar(QWidget *parent) :
    QFrame(parent)
{
    m_bMouseLeftDonw = false;
}

/*******************************************************************************
 * 函数名称： mouseMoveEvent
 * 功能描述： 鼠标移动事件
 * 参数列表： event - 鼠标事件
 *
 * 返回结果： void
 ******************************************************************************/
void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    Q_ASSERT(NULL != event);

    // 左键按下,然后把窗口移动到相应位置
    if (m_bMouseLeftDonw && (event->buttons() & Qt::LeftButton))
    {
        QPoint movePot = mapToParent(event->globalPos() - m_MousePosition);
        parentWidget()->move(movePot);
        event->accept();
    }
}

/*******************************************************************************
 * 函数名称： mousePressEvent
 * 功能描述： 鼠标按下事件
 * 参数列表： event - 鼠标事件
 *
 * 返回结果： void
 ******************************************************************************/
void TitleBar::mousePressEvent(QMouseEvent *event)
{
    Q_ASSERT(NULL != event);

    if (Qt::LeftButton == event->button())
    {
        m_bMouseLeftDonw = true;
        m_MousePosition = event->pos();// - frameGeometry().topLeft();
    }
}

/*******************************************************************************
 * 函数名称： mouseReleaseEvent
 * 功能描述： 鼠标释放事件
 * 参数列表： event - 鼠标事件
 *
 * 返回结果： 无
 ******************************************************************************/
void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    Q_ASSERT(NULL != event);

    if (Qt::LeftButton == event->button())
    {
        m_bMouseLeftDonw = false;
    }
}

