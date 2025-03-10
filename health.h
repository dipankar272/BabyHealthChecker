
#ifndef HEALTH_H
#define HEALTH_H
using namespace  std;
#include <unordered_map>
#include<iostream>
#include<string>
#include<vector>
#include"bloodData.h"
#include"urineData.h"
#include"physicalData.h"
#include<conio.h>
#include"checkHealth.h"
#include"details.h"
#include <memory>
using namespace std;
class Login{
public:
    void createAccount();
    void login();
    void changePassword();
    void addDetails(const string & username);
    void readUsernamesPasswords();
    void saveUsernamesPasswords();
    void saveDetailsToFile(const string& username);
    void readDetailsFromFile(const string& username);
    void checker(const string & username);
protected:
    void menu(const string& loggedInUser);

    vector<string>usernames;
    vector<string> passwords;
    unordered_map<string, vector<unique_ptr<BloodData>>> bloodDataMap;
    unordered_map<string, vector<unique_ptr<UrineData>>> urineDataMap;
    unordered_map<string, vector<unique_ptr<PhysicalData>>> physicalDataMap;
};

#endif
