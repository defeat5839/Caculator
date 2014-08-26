/*******************************************************************************
 * 类名: AlgorithmStrategyFactory
 * 功能: 算法产生工厂(用于产生相应的的算法)
 ******************************************************************************/

#ifndef ALGORITHMSTRATEGYFACTORY_H
#define ALGORITHMSTRATEGYFACTORY_H

#include <QObject>
#include "AddStrategy.h"
#include "SubStrategy.h"
#include "MulStrategy.h"
#include "DivStrategy.h"

class AlgorithmStrategyFactory
{
private:
    AlgorithmStrategyFactory();

public:
    static AlgorithmStrategyFactory* Instance();
    static  void Release();
    AlgorithmStrategy* createStrategy(EAlgorithmType eType);

private:
    static AlgorithmStrategyFactory* m_pInstance;
};

#endif // ALGORITHMSTRATEGYFACTORY_H
