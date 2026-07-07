// safetyanalysis.cpp

#include "safetyanalysis.h"

int SafetyAnalysis::calculateRiskScore(
    int fuel,
    int speed,
    int verticalSpeed)
{
    int riskScore = 0;

    if(fuel < 20)
        riskScore += 30;

    if(verticalSpeed < -1200)
        riskScore += 40;

    if(speed > 300)
        riskScore += 30;

    return riskScore;
}