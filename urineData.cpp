#include "urineData.h"
#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>
#include<limits>//for exception
#include"Exception.h"
using namespace std;

UrineData::UrineData() {
    colorOfUrine = "";
    clarityOfUrine = "";
    phLevel = 0.0;
    glucose = false;
    ketones = false;
    bilirubin = false;
    blood = false;
    RBCell = 0;
    WBCell = 0;
    epithelialCells = 0;
    crystal = false;
    bacteria = false;
}


UrineData::UrineData(string color, string clarity, double pH, bool glu, bool keto, bool bili, bool bl, int rb, int wb, int epith, bool crys, bool bact) {
    colorOfUrine = color;
    clarityOfUrine = clarity;
    phLevel = pH;
    glucose = glu;
    ketones = keto;
    bilirubin = bili;
    blood = bl;
    RBCell = rb;
    WBCell = wb;
    epithelialCells = epith;
    crystal = crys;
    bacteria = bact;
}


UrineData::UrineData(const UrineData &other) {
    colorOfUrine = other.colorOfUrine;
    clarityOfUrine = other.clarityOfUrine;
    phLevel = other.phLevel;
    glucose = other.glucose;
    ketones = other.ketones;
    bilirubin = other.bilirubin;
    blood = other.blood;
    RBCell = other.RBCell;
    WBCell = other.WBCell;
    epithelialCells = other.epithelialCells;
    crystal = other.crystal;
    bacteria = other.bacteria;
}


UrineData::~UrineData() {
}

bool isStringAlpha(const string& str) {
    for (char ch : str) {
        if (!isalpha(ch)) {
            return false;
        }
    }
    return true;
}
void UrineData::inputDetails() {

    bool validInput = false;
    while (!validInput) {
        try {
            cout << "Enter color of urine: ";
            cin >> colorOfUrine;
            transform(colorOfUrine.begin(), colorOfUrine.end(), colorOfUrine.begin(), ::tolower);
            if (cin.fail()|| !isStringAlpha(colorOfUrine)||
               (colorOfUrine != "yellow" && colorOfUrine != "pale yellow" &&
                colorOfUrine != "amber" && colorOfUrine != "light yellow" &&
                colorOfUrine != "white" && colorOfUrine != "clear"&& colorOfUrine != "red")) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setColorOfUrine(colorOfUrine);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter clarity of urine: (clear or turbid)";
            cin >> clarityOfUrine;
            transform(clarityOfUrine.begin(), clarityOfUrine.end(), clarityOfUrine.begin(), ::tolower);
            if ((clarityOfUrine != "clear" && clarityOfUrine != "turbid\") || cin.fail() || !isStringAlpha(clarityOfUrine) ) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setClarityOfUrine(clarityOfUrine);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter pH Level: ";
            cin >> phLevel;
            if (cin.fail()|| phLevel < 4 || phLevel > 8) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setPhLevel(phLevel);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Is glucose present? (1 for yes, 0 for no): ";
            cin >> glucose;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setGlucose(glucose);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Is ketones present? (1 for yes, 0 for no): ";
            cin >> ketones;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setKetones(ketones);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Is bilirubin present? (1 for yes, 0 for no): ";
            cin >> bilirubin;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setBilirubin(bilirubin);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Is blood present? (1 for yes, 0 for no): ";
            cin >> blood;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setBlood(blood);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Red Blood Cells Count:(in high power field (HPF))===>range(0 to 5) ";
            cin >> RBCell;
            if (cin.fail()|| RBCell < 0 || RBCell > 5) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setRBCell(RBCell);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter White Blood Cells Count:(in high power field (HPF))===>range(0 to 5) ";
            cin >> WBCell;
            if (cin.fail()|| WBCell < 0 || WBCell > 5) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setWBCell(WBCell);


    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Epithelial Cells Count:(in high power field (HPF))===>range(0 to 5) ";
            cin >> epithelialCells;
            if (cin.fail()|| epithelialCells < 0 || epithelialCells > 5) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setEpithelialCells(epithelialCells);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Are crystals present? (1 for yes, 0 for no): ";
            cin >> crystal;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setCrystal(crystal);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Are bacteria present? (1 for yes, 0 for no): ";
            cin >> bacteria;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setBacteria(bacteria);
}


void UrineData::saveToFile(ofstream& outFile) {
    outFile.open("urinetest.bin", ofstream::out | ofstream::binary | ofstream::trunc);
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file for writing" << endl;
        return;
    }
    outFile << "Urine Data" << endl;
    outFile << "Color of urine: " << colorOfUrine << endl;
    outFile << "Clarity of urine: " << clarityOfUrine << endl;
    outFile << "pH Level: " << phLevel << endl;
    outFile << "Glucose: " << (glucose ? "Present" : "Absent") << endl;
    outFile << "Ketones: " << (ketones ? "Present" : "Absent") << endl;
    outFile << "Bilirubin: " << (bilirubin ? "Present" : "Absent") << endl;
    outFile << "Blood: " << (blood ? "Present" : "Absent") << endl;
    outFile << "Red Blood Cells Count: " << RBCell << endl;
    outFile << "White Blood Cells Count: " << WBCell << endl;
    outFile << "Epithelial Cells Count: " << epithelialCells << endl;
    outFile << "Crystals: " << (crystal ? "Present" : "Absent") << endl;
    outFile << "Bacteria: " << (bacteria ? "Present" : "Absent") << endl;
    outFile.close();
}



void UrineData::displayInfo() const {
    cout << "Color of urine: " << colorOfUrine << endl;
    cout << "Clarity of urine: " << clarityOfUrine << endl;
    cout << "pH Level: " << phLevel << endl;
    cout << "Glucose: " << (glucose ? "Present" : "Absent") << endl;
    cout << "Ketones: " << (ketones ? "Present" : "Absent") << endl;
    cout << "Bilirubin: " << (bilirubin ? "Present" : "Absent") << endl;
    cout << "Blood: " << (blood ? "Present" : "Absent") << endl;
    cout << "Red Blood Cells Count: " << RBCell << endl;
    cout << "White Blood Cells Count: " << WBCell << endl;
    cout << "Epithelial Cells Count: " << epithelialCells << endl;
    cout << "Crystals: " << (crystal ? "Present" : "Absent") << endl;
    cout << "Bacteria: " << (bacteria ? "Present" : "Absent") << endl;
}
ostream& operator<<(ostream& os, const UrineData& obj) {
    os << "Color of urine: " << obj.colorOfUrine << endl;
    os << "Clarity of urine: " << obj.clarityOfUrine << endl;
    os << "pH Level: " << obj.phLevel << endl;
    os << "Glucose: " << (obj.glucose ? "Present" : "Absent") << endl;
    os << "Ketones: " << (obj.ketones ? "Present" : "Absent") << endl;
    os << "Bilirubin: " << (obj.bilirubin ? "Present" : "Absent") << endl;
    os << "Blood: " << (obj.blood ? "Present" : "Absent") << endl;
    os << "Red Blood Cells Count: " << obj.RBCell << endl;
    os << "White Blood Cells Count: " << obj.WBCell << endl;
    os << "Epithelial Cells Count: " << obj.epithelialCells << endl;
    os << "Crystals: " << (obj.crystal ? "Present" : "Absent") << endl;
    os << "Bacteria: " << (obj.bacteria ? "Present" : "Absent") << endl;
    return os;
}
string UrineData::getColorOfUrine() const {
    return colorOfUrine;
}

string UrineData::getClarityOfUrine() const {
    return clarityOfUrine;
}

double UrineData::getPhLevel() const {
    return phLevel;
}

bool UrineData::isGlucose() const {
    return glucose;
}

bool UrineData::isKetones() const {
    return ketones;
}

bool UrineData::isBilirubin() const {
    return bilirubin;
}

bool UrineData::isBlood() const {
    return blood;
}

int UrineData::getRBCell() const {
    return RBCell;
}

int UrineData::getWBCell() const {
    return WBCell;
}

int UrineData::getEpithelialCells() const {
    return epithelialCells;
}

bool UrineData::isCrystal() const {
    return crystal;
}

bool UrineData::isBacteria() const {
    return bacteria;
}

// Setters implementation
void UrineData::setColorOfUrine(string color) {
    colorOfUrine = color;
}

void UrineData::setClarityOfUrine(string clarity) {
    clarityOfUrine = clarity;
}

void UrineData::setPhLevel(double pH) {
    phLevel = pH;
}

void UrineData::setGlucose(bool glu) {
    glucose = glu;
}

void UrineData::setKetones(bool keto) {
    ketones = keto;
}

void UrineData::setBilirubin(bool bili) {
    bilirubin = bili;
}

void UrineData::setBlood(bool bl) {
    blood = bl;
}

void UrineData::setRBCell(int rb) {
    RBCell = rb;
}

void UrineData::setWBCell(int wb) {
    WBCell = wb;
}

void UrineData::setEpithelialCells(int epith) {
    epithelialCells = epith;
}

void UrineData::setCrystal(bool crys) {
    crystal = crys;
}

void UrineData::setBacteria(bool bact) {
    bacteria = bact;
}


istream& operator>>(istream& is, UrineData& obj) {
    cout << "Enter color of urine: ";
    is >> obj.colorOfUrine;
    cout << "Enter clarity of urine: ";
    is >> obj.clarityOfUrine;
    cout << "Enter pH Level: ";
    is >> obj.phLevel;
    cout << "Is glucose present? (1 for yes, 0 for no): ";
    is >> obj.glucose;
    cout << "Is ketones present? (1 for yes, 0 for no): ";
    is >> obj.ketones;
    cout << "Is bilirubin present? (1 for yes, 0 for no): ";
    is >> obj.bilirubin;
    cout << "Is blood present? (1 for yes, 0 for no): ";
    is >> obj.blood;
    cout << "Enter Red Blood Cells Count: ";
    is >> obj.RBCell;
    cout << "Enter White Blood Cells Count: ";
    is >> obj.WBCell;
    cout << "Enter Epithelial Cells Count: ";
    is >> obj.epithelialCells;
    cout << "Are crystals present? (1 for yes, 0 for no): ";
    is >> obj.crystal;
    cout << "Are bacteria present? (1 for yes, 0 for no): ";
    is >> obj.bacteria;
    return is;
}

