/*******************************************************************************
 * 类名: TitleBar
 * 功能: 实现窗体拖拽功能
 ******************************************************************************/

#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QFrame>
#include <QMouseEvent>

class TitleBar : public QFrame
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPoint m_MousePosition;
    bool  m_bMouseLeftDonw;
};

#endif // TITLEBAR_H
