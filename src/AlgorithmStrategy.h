/*******************************************************************************
 * 类名: AlgorithmStrategy
 * 功能: 纯虚算法策略类型
 ******************************************************************************/

#ifndef ALGORITHMSTRATEGY_H
#define ALGORITHMSTRATEGY_H

#include <QString>

typedef enum AlgorithmType
{
    EAlgorithmType_Add    = 0,
    EAlgorithmType_Sub    = 1,
    EAlgorithmType_Mul    = 2,
    EAlgorithmType_Div    = 3,
    EAlgorithmType_Unkonw = 100
}EAlgorithmType;

class AlgorithmStrategy
{
public:
    virtual QString getResult(const QString leftOperate, const QString rightOperate) = 0;
};

#endif // ALGORITHMSTRATEGY_H
