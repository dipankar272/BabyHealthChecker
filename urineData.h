#ifndef URINEDATA_H
#define URINEDATA_H
#include<iostream>
#include "Details.h"
#include<vector>
#include<string>
#include<conio.h>

using namespace std;
class UrineData: public Details {
protected:
    string colorOfUrine;
    string clarityOfUrine;
    double phLevel;
    bool glucose;
    bool ketones;
    bool bilirubin;
    bool blood;
    int RBCell;
    int WBCell;
    int epithelialCells;
    bool crystal;
    bool bacteria;

public:

    UrineData();
    UrineData(string color, string clarity, double pH, bool glu, bool keto, bool bili, bool bl, int rb, int wb, int epith, bool crys, bool bact); // Parameterized constructor
    UrineData(const UrineData &other); // Copy constructor


    ~UrineData();
    string getColorOfUrine() const;
    string getClarityOfUrine() const;
    double getPhLevel() const;
    bool isGlucose() const;
    bool isKetones() const;
    bool isBilirubin() const;
    bool isBlood() const;
    int getRBCell() const;
    int getWBCell() const;
    int getEpithelialCells() const;
    bool isCrystal() const;
    bool isBacteria() const;
    void setColorOfUrine(string color);
    void setClarityOfUrine( string clarity);
    void setPhLevel(double pH);
    void setGlucose(bool glu);
    void setKetones(bool keto);
    void setBilirubin(bool bili);
    void setBlood(bool bl);
    void setRBCell(int rb);
    void setWBCell(int wb);
    void setEpithelialCells(int epith);
    void setCrystal(bool crys);
    void setBacteria(bool bact);


    void inputDetails() override;
    void saveToFile(ofstream& outFile) override;



    void displayInfo() const;


    friend ostream& operator<<(ostream& os, const UrineData& obj);

    friend istream& operator>>(istream& is, UrineData& obj);
};
#endif // URINEDATA_H

