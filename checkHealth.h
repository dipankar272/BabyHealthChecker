#ifndef CHECKHEALTH_H
#define CHECKHEALTH_H
#include"details.h"
#include"bloodData.h"
#include"urineData.h"
#include"physicalData.h"
class CheckHealth:public BloodData,public UrineData,public PhysicalData
{
public:
    void checkBaby(const BloodData *latestBloodData, const UrineData *latestUrineData, const PhysicalData *latestPhysicalData);
    int analyzeBloodData(const BloodData *bloodData);
    int analyzeUrineData(const UrineData *urineData);
    int analyzePhysicalData(const PhysicalData *physicalData);
};
#endif // CHECKHEALTH_H
