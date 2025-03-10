#ifndef PHYSICALDATA_H
#define PHYSICALDATA_H
#include"details.h"
#include<fstream>
#include <iostream>
using namespace std;
class PhysicalData:public Details
{
protected:
    double weight;
    double length;
    int age;
    int momAge;
    double headCircumference;
    double temperature;
    char gender;

public:
    void inputDetails() override;
    void saveToFile(ofstream& outFile) override;


    PhysicalData();
    PhysicalData(float weight, float length, float headCircumference, float temperature,int age,int momAge,char g);
    PhysicalData(const PhysicalData& other);


    ~PhysicalData();


    int getAge() const;
    void setAge(int age);
    int getMomAge() const;
    void setMomAge(int momAge);
    double getWeight() const;
    void setWeight(float weight);
    char getGender() const;
    void setGender(char gen);

    double getLength() const;
    void setLength(float length);

    double getHeadCircumference() const;
    void setHeadCircumference(float headCircumference);

    double getTemperature() const;
    void setTemperature(float temperature);


    friend istream& operator>>(std::istream& input, PhysicalData& physic);
    friend ostream& operator<<(std::ostream& output, const PhysicalData& physic);
    void display() const;
};


#endif

