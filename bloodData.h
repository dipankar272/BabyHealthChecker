#ifndef BLOODDATA_H
#define BLOODDATA_H
#include "Details.h"
#include<vector>
#include<string>
#include<conio.h>
#include <iostream>


using namespace std;

class BloodData : public Details {
protected:
    double RBCCount;
    double WBCCount;
    double Platelets;
    double Hemoglobin;
    double Hematocrit;
    double MeanCorpuscularVolume;
    double MeanCorpuscularHemoglobin;

public:
    BloodData();
    BloodData(double rbc, double wbc, double platelets, double hemoglobin, double hematocrit, double mcv, double mch);
    BloodData(const BloodData& other);
    ~BloodData();


    double getRBCCount() const;
    double getWBCCount() const;
    double getPlatelets() const;
    double getHemoglobin() const;
    double getHematocrit() const;
    double getMeanCorpuscularVolume() const;
    double getMeanCorpuscularHemoglobin() const;


    void setRBCCount(double count);
    void setWBCCount(double count);
    void setPlatelets(double count);
    void setHemoglobin(double hemoglobin);
    void setHematocrit(double hematocrit);
    void setMeanCorpuscularVolume(double volume);
    void setMeanCorpuscularHemoglobin(double hemoglobin);





    friend istream& operator>>(istream& in, BloodData& blood);
    friend ostream& operator<<(ostream& out, const BloodData& blood);
    void inputDetails() override;
    void saveToFile(ofstream& outFile) override;

};

#endif // BLOODDATA_H
