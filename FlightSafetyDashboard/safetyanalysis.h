#ifndef SAFETYANALYSIS_H
#define SAFETYANALYSIS_H

#include <QtCore/qglobal.h>

#if defined(SAFETYANALYSIS_LIBRARY)
#  define SAFETYANALYSIS_EXPORT Q_DECL_EXPORT
#else
#  define SAFETYANALYSIS_EXPORT Q_DECL_IMPORT
#endif

class SAFETYANALYSIS_EXPORT SafetyAnalysis
{
public:
    static int calculateRiskScore(
        int fuel,
        int speed,
        int verticalSpeed);
};

#endif