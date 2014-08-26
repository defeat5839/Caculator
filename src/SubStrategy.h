/*******************************************************************************
 * 类名: SubStrategy
 * 功能: 实现减法
 ******************************************************************************/

#ifndef SUBSTRATEGY_H
#define SUBSTRATEGY_H

#include "AlgorithmStrategy.h"

class SubStrategy : public AlgorithmStrategy
{
public:
    SubStrategy();

    QString getResult(const QString leftOperate, const QString rightOperate);
};

#endif // SUBSTRATEGY_H
