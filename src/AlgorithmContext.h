/*******************************************************************************
 * 类名: AlgorithmContext
 * 功能: 算法上下文类,用于调用相应的算法
 ******************************************************************************/

#ifndef CONTEXT_H
#define CONTEXT_H

#include <algorithm>
#include "AlgorithmStrategy.h"
#include "AlgorithmStrategyFactory.h"

class AlgorithmContext
{
public:
    AlgorithmContext(EAlgorithmType eType);
    QString Calculate(const QString leftOperate, const QString rightOperate);
private:
    AlgorithmStrategy *m_pStrategy;
};

#endif // CONTEXT_H
