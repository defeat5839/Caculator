/*******************************************************************************
 * 类名: AddStrategy
 * 功能: 实现加法
 ******************************************************************************/

#ifndef ADDSTRATEGY_H
#define ADDSTRATEGY_H

#include "AlgorithmStrategy.h"

class AddStrategy : public AlgorithmStrategy
{
public:
    AddStrategy();

    QString getResult(const QString leftOperate, const QString rightOperate);
};

#endif // ADDSTRATEGY_H
