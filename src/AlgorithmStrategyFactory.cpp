#include "AlgorithmStrategyFactory.h"

AlgorithmStrategyFactory* AlgorithmStrategyFactory::m_pInstance = NULL;

/*******************************************************************************
 * 函数名称： AlgorithmStrategyFactory
 * 功能描述： 算法策略工厂构造函数
 * 参数列表： void
 *
 * 返回结果： 无
 ******************************************************************************/
AlgorithmStrategyFactory::AlgorithmStrategyFactory()
{
}

/*******************************************************************************
 * 函数名称： Instance
 * 功能描述： 唯一初始化实例
 * 参数列表： void
 *
 * 返回结果： m_pInstance - 唯一实例指针
 ******************************************************************************/
AlgorithmStrategyFactory *AlgorithmStrategyFactory::Instance()
{
    // 如果实例指针为NULL,则创建新的
    if (NULL == m_pInstance)
    {
        m_pInstance = new AlgorithmStrategyFactory;
    }

    return m_pInstance;
}

/*******************************************************************************
 * 函数名称： Release
 * 功能描述： 释放唯一实例
 * 参数列表： void
 *
 * 返回结果： void
 ******************************************************************************/
void AlgorithmStrategyFactory::Release()
{
    if (NULL != m_pInstance)
    {
        delete m_pInstance;
    }
}

/*******************************************************************************
 * 函数名称： createStrategy
 * 功能描述： 创建相应的算法策略
 * 参数列表： eType - 算法类型
 *
 * 返回结果： 无
 ******************************************************************************/
AlgorithmStrategy *AlgorithmStrategyFactory::createStrategy(EAlgorithmType eType)
{
    AlgorithmStrategy *pStrategy = NULL;
    switch (eType)
    {
        case EAlgorithmType_Add:
        {
            pStrategy = new AddStrategy;
            break;
        }
        case EAlgorithmType_Sub:
        {
            pStrategy = new SubStrategy;
            break;
        }
        case EAlgorithmType_Mul:
        {
            pStrategy = new MulStrategy;
            break;
        }
        case EAlgorithmType_Div:
        {
            pStrategy = new DivStrategy;
            break;
        }
        default:
        {
            break;
        }
    }

    return pStrategy;
}
