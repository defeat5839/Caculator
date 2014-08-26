/*******************************************************************************
 * 类名: MulStrategy
 * 功能: 实现乘法
 ******************************************************************************/

#ifndef MULSTRATEGY_H
#define MULSTRATEGY_H

#include "AlgorithmStrategy.h"

class MulStrategy : public AlgorithmStrategy
{
public:
    MulStrategy();

    QString getResult(const QString leftOperate, const QString rightOperate);
};

#endif // MULSTRATEGY_H
