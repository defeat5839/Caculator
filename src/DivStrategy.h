/*******************************************************************************
 * 类名: DivStrategy
 * 功能: 实现除法
 ******************************************************************************/

#ifndef DIVSTRATEGY_H
#define DIVSTRATEGY_H

#include "AlgorithmStrategy.h"

class DivStrategy : public AlgorithmStrategy
{
public:
    DivStrategy();

    QString getResult(const QString leftOperate, const QString rightOperate);
};

#endif // DIVSTRATEGY_H
