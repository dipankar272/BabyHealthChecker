#include "checkHealth.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;
void CheckHealth::checkBaby(const BloodData *latestBloodData, const UrineData *latestUrineData, const PhysicalData *latestPhysicalData) {
    cout << "Checking the health of the baby...\n";


    if (!latestBloodData || !latestUrineData || !latestPhysicalData) {
        cerr << "Error in accessing health data.\n";
        return;
    }

    int flag = 0,flag1=0,flag2=0;


    flag += analyzeBloodData(latestBloodData);
    delete(latestBloodData);


    flag2 += analyzePhysicalData(latestPhysicalData);
    delete(latestPhysicalData);

    flag1 += analyzeUrineData(latestUrineData);
    delete(latestUrineData);

    if (flag == 0&&flag1==0&&flag2==0) {
        cout << "Baby is Healthy...\n";
    }
    else{
        cout<<"Baby is unhealthy.....Consult Nearby HealthCare centers or Hospitals..\n";
    }
}

int CheckHealth::analyzeBloodData(const BloodData *bloodData) {
    int flag = 0;

    double RBCs = bloodData->getRBCCount();
    double WBCs = bloodData->getWBCCount();
    double platelets = bloodData->getPlatelets();
    double hemoglobin = bloodData->getHemoglobin();
    double hematocrit = bloodData->getHematocrit();
    double MCV = bloodData->getMeanCorpuscularVolume();
    double MCH = bloodData->getMeanCorpuscularHemoglobin();



    if (RBCs <3.5 || RBCs > 5.5) {
        cout << "Warning: Abnormal Red Blood Cell count detected.\n";
        flag += 1;
    }
    if (WBCs < 5000 || WBCs > 20000) {
        cout << "Warning: Abnormal White Blood Cell count detected." << endl;
        flag+=1;
    }


    if (platelets < 150000 || platelets > 450000) {
        cout << "Warning: Abnormal Platelet count detected." << endl;
        flag+=1;
    }


    if (hemoglobin < 10 || hemoglobin > 16) {
        cout << "Warning: Abnormal Hemoglobin level detected." << endl;
        flag+=1;
    }


    if (hematocrit < 30 || hematocrit >60) {
        cout << "Warning: Abnormal Hematocrit level detected." << endl;
        flag+=1;
    }


    if (MCV < 80 || MCV > 100) {
        cout << "Warning: Abnormal Mean Corpuscular Volume detected." << endl;
        flag+=1;
    }


    if (MCH < 27 || MCH > 33) {
        cout << "Warning: Abnormal Mean Corpuscular Hemoglobin detected." << endl;
        flag+=1;
    }





    return flag;
}
int CheckHealth::analyzeUrineData(const UrineData *urineData) {
    cout<<"Checking urine data...\n";
    int flag = 0;
    string safeColor="pale yellow",sC1="amber",sC2="light yellow",sC3="white",sC4="yellow",clarity="clear";

    string colorOfUrine = urineData->getColorOfUrine();
    string clarityOfUrine = urineData->getClarityOfUrine();
    double phLevel = urineData->getPhLevel();
    bool glucose = urineData->isGlucose();
    bool ketones = urineData->isKetones();
    bool bilirubin = urineData->isBilirubin();
    bool blood = urineData->isBlood();
    int RBCell = urineData->getRBCell();
    int WBCell = urineData->getWBCell();
    int epithelialCells = urineData->getEpithelialCells();
    bool crystal = urineData->isCrystal();
    bool bacteria = urineData->isBacteria();



    if (colorOfUrine != safeColor && colorOfUrine != sC1 && colorOfUrine != sC2 && colorOfUrine != sC3 && colorOfUrine != sC4) {
        cout << "Warning: Abnormal color of urine detected: " << colorOfUrine << endl;
        flag += 1;
    }
    if (clarityOfUrine !=clarity ) {
        cout << "Warning: Abnormal clarity of urine detected: " << clarityOfUrine << endl;
        flag += 1;
    }
    if (phLevel < 4.5 || phLevel > 8.0) {
        cout << "Warning: Abnormal pH level detected: " << phLevel << endl;
        flag += 1;
    }
    if (glucose) {
        cout << "Warning: Glucose detected in urine."<<glucose<< endl;
        flag+=1;
    }

    if (ketones) {
        cout << "Warning: Ketones detected in urine." <<ketones<< endl;
        flag+=1;
    }

    if (bilirubin) {
        cout << "Warning: Bilirubin detected in urine." <<bilirubin<< endl;
        flag+=1;
    }


    if (blood) {
        cout << "Warning: Blood detected in urine."<<blood << endl;
        flag+=1;
    }


    if (RBCell > 5) {
        cout << "Warning: Abnormal Red Blood Cells count detected:"<<RBCell << endl;
        flag+=1;
    }


    if (WBCell > 5) {
        cout << "Warning: Abnormal White Blood Cells count detected."<<WBCell << endl;
        flag+=1;
    }


    if (epithelialCells > 5) {
        cout << "Warning: Abnormal epithelial cells count detected." <<epithelialCells<< endl;
        flag+=1;
    }

    if (crystal) {
        cout << "Warning: Crystals detected in urine." <<crystal<< endl;
        flag+=1;
    }

    if (bacteria) {
        cout << "Warning: Bacteria detected in urine." <<bacteria<< endl;
        flag+=1;
    }


    return flag;
}
int CheckHealth::analyzePhysicalData(const PhysicalData *physicalData) {
    cout<<"Checking physical data...\n";
    int flag = 0;


    int age = physicalData->getAge();
    char gender = physicalData->getGender();
    double weight = physicalData->getWeight();
    double length = physicalData->getLength();
    double momAge = physicalData->getMomAge();
    double headCircumference = physicalData->getHeadCircumference();
    double temperature = physicalData->getTemperature();


    if (age < 0) {
        cout << "Error: Invalid age: " << age << endl;
        flag += 1;
    }
    if (gender != 'M' && gender != 'F') {
        cout << "Error: Invalid gender." << endl;
        flag+=1;

    }


    if (age >= 0 && age <= 12) {

        if (weight <= 0 || length <= 0) {
            cout << "Error: Invalid weight or length value." << endl;
            return 1;
        }

        double infantAge = age / 12.0;


        const double normalWeightMale = 3.0 + 0.5 * infantAge;
        const double normalWeightFemale = 2.8 + 0.5 * infantAge;
        const double normalLengthMale = 52.5 + 2.45 * infantAge;
        const double normalLengthFemale = 50.8 + 2.15 * infantAge;

        double normalWeight = (gender == 'M') ? normalWeightMale : normalWeightFemale;
        double normalLength = (gender == 'M') ? normalLengthMale : normalLengthFemale;


        const double weightDeviationFactor = 0.2;
        const double lengthDeviationFactor = 0.2;

        if (weight < (1 - weightDeviationFactor) * normalWeight || weight > (1 + weightDeviationFactor) * normalWeight) {
            cout << "Warning: Abnormal weight detected. Expected range: " << (1 - weightDeviationFactor) * normalWeight << " - " << (1 + weightDeviationFactor) * normalWeight << " kg." << endl;
            flag += 1;
        }

        if (length < (1 - lengthDeviationFactor) * normalLength || length > (1 + lengthDeviationFactor) * normalLength) {
            cout << "Warning: Abnormal length detected. Expected range: " << (1 - lengthDeviationFactor) * normalLength << " - " << (1 + lengthDeviationFactor) * normalLength << " cm." << endl;
            flag += 1;
        }
    } else {
        cout << "Warning: Age out of range for infant analysis." << endl;
    }
    if (momAge < 19 || momAge > 50) {
        cout << "Warning: Abnormal mom's age detected." << endl;
        flag+=1;
        }


   if (age >= 0 && age <= 12) {
        // Convert head circumference to centimeters if it's not already in that unit
        // Assuming headCircumference is already in centimeters
        if (gender == 'M') {
            if (age < 3) {
                if (headCircumference < 33 || headCircumference > 55) {
                    cout << "Warning: Abnormal head circumference detected." << endl;
                    flag += 1;
                }
            } else {
                if (headCircumference < 40 || headCircumference > 60) {
                    cout << "Warning: Abnormal head circumference detected." << endl;
                    flag += 1;
                }
            }
        } else { // Assuming gender is 'F'
            if (age < 3) {
                if (headCircumference < 32 || headCircumference > 53) {
                    cout << "Warning: Abnormal head circumference detected." << endl;
                    flag += 1;
                }
            } else {
                if (headCircumference < 38 || headCircumference > 58) {
                    cout << "Warning: Abnormal head circumference detected." << endl;
                    flag += 1;
                }
            }
        }
    }

    if (temperature < 35.0 || temperature > 37.5) {
            cout << "Warning: Abnormal temperature detected." << endl;
            flag+=1;
        }


    return flag;
}
