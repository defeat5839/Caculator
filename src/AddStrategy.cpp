#include "AddStrategy.h"

/*******************************************************************************
 * 函数名称： AddStrategy
 * 功能描述： AddStrategy构造函数
 * 参数列表： void
 *
 * 返回结果： 无
 ******************************************************************************/
AddStrategy::AddStrategy()
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
QString AddStrategy::getResult(const QString leftOperate, const QString rightOperate)
{
    return QString::number(leftOperate.toFloat() + rightOperate.toFloat());
}
