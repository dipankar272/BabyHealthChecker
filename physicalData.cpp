#include "physicalData.h"
#include<iostream>
#include<string>
#include<fstream>
#include <cctype>//toupper
#include"Exception.h"
#include<limits>//for exception
using namespace std;


PhysicalData::PhysicalData() {
    weight = 0.0f;
    length = 0.0f;
    headCircumference = 0.0f;
    temperature = 0.0f;
    age=0;
    momAge=0;
    gender='N';
}

PhysicalData::PhysicalData(float weight, float length, float headCircumference, float temperature,int age,int momAge,char gen) {
    this->weight = weight;
    this->length = length;
    this->headCircumference = headCircumference;
    this->temperature = temperature;
    this->age=age;
    this->momAge=momAge;
    this->gender=gen;
}

PhysicalData::PhysicalData(const PhysicalData& other) {
    weight = other.weight;
    length = other.length;
    headCircumference = other.headCircumference;
    temperature = other.temperature;
    age=other.age;
    momAge=other.momAge;
    gender=other.gender;
}

PhysicalData::~PhysicalData() {
}

double  PhysicalData::getWeight() const {
    return weight;
}

void PhysicalData::setWeight(float weight) {
    this->weight = weight;
}

char  PhysicalData::getGender() const {
    return gender;
}

void PhysicalData::setGender(char gen) {
    this->gender = gen;
}


double PhysicalData::getLength() const {
    return length;
}

void PhysicalData::setLength(float length) {
    this->length = length;
}

double PhysicalData::getHeadCircumference() const {
    return headCircumference;
}

void PhysicalData::setHeadCircumference(float headCircumference) {
    this->headCircumference = headCircumference;
}

double PhysicalData::getTemperature() const {
    return temperature;
}

void PhysicalData::setTemperature(float temperature) {
    this->temperature = temperature;
}
int PhysicalData::getAge() const{
    return age;
}
void PhysicalData::setAge(int age)
{
    this->age=age;
}

int PhysicalData::getMomAge() const{
    return momAge;
}
void PhysicalData::setMomAge(int momAge)
{
    this->momAge=momAge;
}

istream& operator>>(istream& in, PhysicalData& physic) {
    cout << "Enter Weight of the baby: (in kgs)";
    in >> physic.weight;
    cout << "Enter Length of the baby: (in cm)";
    in >> physic.length;
    cout << "Enter Head Circumference: (in cm)";
    in >> physic.headCircumference;
    cout << "Enter Temperature of the Baby(in celsius): ";
    in >> physic.temperature;
    cout<<"Enter  Age of the baby: ";
    in>>physic.age;
    cout<<"Enter  Gender of the baby: (M or F)";
    in>>physic.gender;
    cout<<"Enter  Age of the Mother: ";
    in>>physic.momAge;
    return in;
}

ostream& operator<<(ostream& output, const PhysicalData& physic) {
    output << "Weight: " << physic.weight << " kg\n";
    output << "Length: " << physic.length << " cm\n";
    output << "Head Circumference: " << physic.headCircumference << " cm\n";
    output << "Temperature: " << physic.temperature << " celsius\n";
    output<<"Age of the Baby: "<<physic.age<<endl;
    output<<"Gender of the Baby: "<<physic.gender<<endl;
    output<<"Age of the Mother: "<<physic.momAge<<endl;
    return output;
}
void PhysicalData::inputDetails() {

    bool validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Weight of the baby:(in kgs)====>approx range according to age(1 month to 10 years) (2.5kg to 23.5kg) ";
            cin >> weight;
            if (cin.fail()|| weight < 2.5 || weight > 23.5) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setWeight(weight);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Length of the baby:(in cm)====>approx range according to age(1 month to 10 years) (47cm to 124.4cm):  ";
            cin >> length;
            if (cin.fail()|| length < 47.0 || length > 124.4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setLength(length);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Head Circumference: (in cm)===>approx range(34 to 67 cm)";
            cin >> headCircumference;
            if (cin.fail()|| headCircumference < 34.0 || headCircumference > 67.0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setHeadCircumference(headCircumference);

    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter Temperature of the Baby(in Celsius):===>approx range(35.9C to 37.3C) ";
            cin >> temperature;
            if (cin.fail()|| temperature < 35.9 || temperature > 37.3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setTemperature(temperature);

    validInput = false;
    while (!validInput) {
        try {
            cout<<"Enter  Age of the baby:(in months) ";
            cin>>age;
            if (cin.fail()||age<0||age>120) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setAge(age);
    validInput = false;
    while (!validInput) {
        try {
            cout<<"Enter  Gender of the baby: (M or F)";
            cin>>gender;
            gender = toupper(gender);
            if (cin.fail()||(gender!='M' && gender!='F')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setGender(gender);

    validInput = false;
    while (!validInput) {
        try {
            cout<<"Enter  Age of the Mother: ";
            cin>>momAge;
            if (cin.fail()||momAge>70||momAge<0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InvalidInputException();
            }
            validInput = true;
        } catch (InvalidInputException& e) {
            cerr << e.what() << endl;
        }
    }

    setMomAge(momAge);

}

void PhysicalData::saveToFile(ofstream& outFile) {
    outFile.open("physicaltest.bin", ofstream::out | ofstream::binary | ofstream::trunc);
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file for writing" << endl;
        return;
    }
    outFile << "\nPhysical Test Data" << endl;
    outFile << "Weight of the baby: " << weight <<"kg"<< endl;
    outFile << "Length of the baby: " << length <<"cm"<< endl;
    outFile << "Head circumference of the baby: " << headCircumference <<"cm"<< endl;
    outFile << "Age of Baby: " << age << endl;
    outFile << "Gender of Baby: " << gender << endl;
    outFile << "Age of Mother: " << momAge << endl;
    outFile.close();
}


void PhysicalData::display() const {
    cout << "Weight: " << weight << " pounds\n";
    cout << "Length: " << length << " inches\n";
    cout << "Head Circumference: " << headCircumference << " inches\n";
    cout << "Temperature: " << temperature << " Fahrenheit\n";
    cout << "Age of Baby: " << age << endl;
    cout << "Age of Mother: " << momAge << endl;
}
