#include "DivStrategy.h"

/*******************************************************************************
 * 函数名称： DivStrategy
 * 功能描述： DivStrategy构造函数
 * 参数列表： void
 *
 * 返回结果： 无
 ******************************************************************************/
DivStrategy::DivStrategy()
{
}

/*******************************************************************************
 * 函数名称： getResult
 * 功能描述： 获得结果
 * 参数列表： leftOperate  - 左操作数
 *          rightOperate - 右操作数
 *
 * 返回结果： 结果
 ******************************************************************************/
QString DivStrategy::getResult(const QString leftOperate, const QString rightOperate)
{
    if (rightOperate.toFloat() == 0)
    {
        return QString("Error");
    }

    return QString::number(leftOperate.toFloat() / rightOperate.toFloat());
}

