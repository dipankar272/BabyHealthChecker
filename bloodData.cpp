#include "bloodData.h"
#include<fstream>
#include<iostream>
#include<limits>//for exception
#include"Exception.h"
#include<string>

using namespace std;

BloodData::BloodData() : RBCCount(0), WBCCount(0), Platelets(0), Hemoglobin(0), Hematocrit(0), MeanCorpuscularVolume(0), MeanCorpuscularHemoglobin(0) {}

BloodData::BloodData(double rbc, double wbc, double platelets, double hemoglobin, double hematocrit, double mcv, double mch) : RBCCount(rbc), WBCCount(wbc), Platelets(platelets), Hemoglobin(hemoglobin), Hematocrit(hematocrit), MeanCorpuscularVolume(mcv), MeanCorpuscularHemoglobin(mch) {}

BloodData::BloodData(const BloodData& other) : RBCCount(other.RBCCount), WBCCount(other.WBCCount), Platelets(other.Platelets), Hemoglobin(other.Hemoglobin),Hematocrit(other.Hematocrit), MeanCorpuscularVolume(other.MeanCorpuscularVolume), MeanCorpuscularHemoglobin(other.MeanCorpuscularHemoglobin) {}

BloodData::~BloodData() {}

double BloodData::getRBCCount() const
{
    return RBCCount;
}

double BloodData::getWBCCount() const
{
    return WBCCount;
}

double BloodData::getPlatelets() const
{
    return Platelets;
}

double BloodData::getHemoglobin() const
{
    return Hemoglobin;
}

double BloodData::getHematocrit() const
{
    return Hematocrit;
}

double BloodData::getMeanCorpuscularVolume() const
{
    return MeanCorpuscularVolume;
}

double BloodData::getMeanCorpuscularHemoglobin() const
{
    return MeanCorpuscularHemoglobin;
}

void BloodData::setRBCCount(double count1)
{
    RBCCount = count1;
}

void BloodData::setWBCCount(double count2)
{
    WBCCount = count2;
}

void BloodData::setPlatelets(double count3)
{
    Platelets = count3;
}

void BloodData::setHemoglobin(double hemoglobin)
{
    Hemoglobin = hemoglobin;
}

void BloodData::setHematocrit(double hematocrit)
{
    Hematocrit = hematocrit;
}

void BloodData::setMeanCorpuscularVolume(double volume)
{
    MeanCorpuscularVolume = volume;
}

void BloodData::setMeanCorpuscularHemoglobin(double hemoglobin)
{
    MeanCorpuscularHemoglobin = hemoglobin;
}



istream& operator>>(istream& in, BloodData& blood)
{
    cout << "Enter RBC Count: ";
    in >> blood.RBCCount;
    cout << "Enter WBC Count: ";
    in >> blood.WBCCount;
    cout << "Enter Platelets Count: ";
    in >> blood.Platelets;
    cout << "Enter Hemoglobin Level: ";
    in >> blood.Hemoglobin;
    cout << "Enter Hematocrit Level: ";
    in >> blood.Hematocrit;
    cout << "Enter Mean Corpuscular Volume: ";
    in >> blood.MeanCorpuscularVolume;
    cout << "Enter Mean Corpuscular Hemoglobin: ";
    in >> blood.MeanCorpuscularHemoglobin;
    //blood(RBCCount,WBCCount,Platelets,Hemoglobin,Hematocrit,MeanCorpuscularVolume,MeanCorpuscularHemoglobin);
    return in;
}

ostream& operator<<(ostream& out, const BloodData& blood)
{

    out << "RBC Count: "<<blood.getRBCCount()<<endl;
    out << "Enter WBC Count: "<<blood.getWBCCount()<<endl;
    out << "Enter Platelets Count: "<<blood.getPlatelets()<<endl;
    out << "Enter Hemoglobin Level: "<<blood.getHemoglobin()<<endl;
    out << "Enter Hematocrit Level: "<<blood.getHematocrit()<<endl;
    out << "Enter Mean Corpuscular Volume: "<<blood.getMeanCorpuscularVolume()<<endl;
    out << "Enter Mean Corpuscular Hemoglobin: "<<blood.getMeanCorpuscularHemoglobin()<<endl;
    return out;
}
void BloodData::inputDetails() {
    bool validInput = false;
    while (!validInput) {
        try {
            cout << "Enter RBC Count:(in million / microliter (mcL))===>range(3.7 mcL to 5.6 mcL) ";
            cin >> RBCCount;
            if (cin.fail()|| RBCCount < 3.0 || RBCCount > 6.0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }
    setRBCCount(RBCCount);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter WBC Count: (in cells /microliter (mcL))===>range(9000 mcL to 34000 mcL)";
            cin >> WBCCount;
            if (cin.fail() ||WBCCount < 3000 || WBCCount >34000) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setWBCCount(WBCCount);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Platelets Count:(in cells / microliter (mcL))===>range(150000 mcL to 450000 mcL) ";
            cin >> Platelets;
            if (cin.fail()||Platelets < 100000 || Platelets >550000) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setPlatelets(Platelets);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Hemoglobin Level:(in grams per deciliter (g/dL))===>range(11.3 to 15.0 g/dl) ";
            cin >> Hemoglobin;
            if (cin.fail()||Hemoglobin < 8.0 || Hemoglobin >20.0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setHemoglobin(Hemoglobin);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Hematocrit Level:(in percentage)===>range(30.0% to 60.0%) ";
            cin >> Hematocrit;
            if (cin.fail()||Hematocrit < 29.0|| Hematocrit >66.0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setHematocrit(Hematocrit);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Mean Corpuscular Volume: (in femtoliters (fL))===>range(80.0-100.0)fL";
            cin >> MeanCorpuscularVolume;
            if (cin.fail()||MeanCorpuscularVolume < 70.0|| MeanCorpuscularVolume >108.0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setMeanCorpuscularVolume(MeanCorpuscularVolume);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Mean Corpuscular Hemoglobin:(in grams per deciliter (g/dL))===>range(32.0 to 34.0)g/dL ";
            cin >> MeanCorpuscularHemoglobin;
            if (cin.fail()||MeanCorpuscularHemoglobin < 23.0|| MeanCorpuscularHemoglobin >34.0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setMeanCorpuscularHemoglobin(MeanCorpuscularHemoglobin);

}

void BloodData::saveToFile(ofstream& outFile) {
    outFile.open("bloodtest.bin", ofstream::out | ofstream::binary | ofstream::trunc);
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file for writing" << endl;
        return;
    }
    outFile << "Blood Data" << endl;
    outFile << "RBC Count: " << RBCCount <<"mcL"<< endl;
    outFile << "WBC Count: " << WBCCount <<"mcL"<< endl;
    outFile << "Platelets Count: " << Platelets <<"mcL"<< endl;
    outFile << "Hemoglobin Level: " << Hemoglobin <<"g/dL"<< endl;
    outFile << "Hematocrit Level: " << Hematocrit <<"%"<< endl;
    outFile << "Mean Corpuscular Volume: " << MeanCorpuscularVolume <<"fL"<< endl;
    outFile << "Mean Corpuscular Hemoglobin: " << MeanCorpuscularHemoglobin <<"g/dL"<< endl;

    outFile << endl;
    outFile.close();
}

