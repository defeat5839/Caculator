#include "AlgorithmContext.h"

/*******************************************************************************
 * 函数名称： Calculate
 * 功能描述： 计算
 * 参数列表： eType  - 操作类型
 *
 * 返回结果： 无
 ******************************************************************************/
AlgorithmContext::AlgorithmContext(EAlgorithmType eType)
{
    m_pStrategy = AlgorithmStrategyFactory::Instance()->createStrategy(eType);
}

/*******************************************************************************
 * 函数名称： Calculate
 * 功能描述： 计算
 * 参数列表： leftOperate  - 左操作数
 *           rightOperate - 右操作数
 *
 * 返回结果： 结果
 ******************************************************************************/
QString AlgorithmContext::Calculate(const QString leftOperate, const QString rightOperate)
{
    return m_pStrategy->getResult(leftOperate, rightOperate);
}
