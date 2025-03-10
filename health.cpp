#include<iostream>
#include<algorithm>
#include<cctype>
#include"health.h"
#include"bloodData.h"
#include"urineData.h"
#include"physicalData.h"
#include"details.h"
#include"checkHealth.h"
#include<vector>
#include<string>
#include<conio.h>
#include<cstring>
#include<cassert>
#include<memory>
#include<limits>
#include<fstream>
#include "Exception.h"
using namespace std;


void Login::createAccount()
{
    cout<<"\n\t\t\t\t ________________________________________\n";
    cout<<"\t\t\t\t|                                        |";
    cout<<"\n\t\t\t\t|               Create Account           |"<<endl;
    cout<<"\t\t\t\t|________________________________________|"<<endl<<endl;
    string username, password;
    cout << "Enter UserName(Mother Name): ";
    cin >> username;
    cout << "Enter password: ";
    char ch;
    password = "";
    ch = _getch();
    while (ch != 13) {
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout << endl;
    usernames.push_back(username);
    passwords.push_back(password);
    cout << "Account created successfully!" << endl;

}
bool isStringAlph(const string& str) {
    for (char ch : str) {
        if (!isalpha(ch)) {
            return false;
        }
    }
    return true;
}
void Login::login()
{
    string response;
    cout<<"\n\t\t\t\t\t ______________________________________\n";
    cout<<"\t\t\t\t\t|                                      |";
    cout<<"\n\t\t\t\t\t|               LOGIN PAGE             |";
    cout<<"\n\t\t\t\t\t|______________________________________|"<<endl<<endl;
    string username, password;
    int count1 =1;
    while(count1!=5){
        cout << "Enter UserName(Mother Name): ";
        cin >> username;
        cout << "Enter password: ";
        char ch;
        password = "";
        ch = _getch();
        while (ch != 13) {
            password.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        cout << endl;

        bool found = false;
        for (size_t i = 0; i < usernames.size(); ++i) {//unsigned integer...size_t
            if (usernames[i] == username && passwords[i] == password) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Login successful!" << endl;
            string loggedInUser = username;
            menu(loggedInUser);
            break;
        } else {
            cout << "Invalid username or password. Please try again.(Attempts left:"<<4-count1<< ")" << endl;
            if(count1==2)
            {
                int opt;
                cout<<"Did you create your Account:(1=yes or 0=no)\n";
                cin>>opt;
                if(opt==1)
                {
                    cout<<"Then try again to login!!\n";
                }
                else{
                    createAccount();
                    cout<<"\n\t\t\t\t\t ______________________________________\n";
                    cout<<"\t\t\t\t\t|                                      |";
                    cout<<"\n\t\t\t\t\t|               LOGIN PAGE             |";
                    cout<<"\n\t\t\t\t\t|______________________________________|"<<endl<<endl;
                }
            }

            count1++;
        }
    }
    if (count1>=5){
        string response;
        cout<<"You exceeded try limit ....\n";


        bool validInput = false;
        while (!validInput) {
            try {
                cout<<"Do you want to change your password:(yes or no)\n";
                cin>>response;
                if (cin.fail()|| !isStringAlph(response)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw InvalidInputException();
                }
                validInput = true;
            } catch (InvalidInputException& e) {
                cerr << e.what() << endl;
            }
        }

        transform(response.begin(), response.end(), response.begin(), ::tolower);

        if(response=="yes")
        {
            changePassword();
        }
        else
        {
            exit(1);
        }
    }

}
void Login::readUsernamesPasswords() {
    ifstream infile("user_data.bin", ios::binary);
    if (!infile.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }
    usernames.clear();
    passwords.clear();
    int numUsers;
    infile.read(reinterpret_cast<char*>(&numUsers), sizeof(numUsers));
    for (int i = 0; i < numUsers; ++i) {
        int usernameSize, passwordSize;
        infile.read(reinterpret_cast<char*>(&usernameSize), sizeof(usernameSize));
        string username(usernameSize, ' ');
        infile.read(&username[0], usernameSize);
        infile.read(reinterpret_cast<char*>(&passwordSize), sizeof(passwordSize));
        string password(passwordSize, ' ');
        infile.read(&password[0], passwordSize);
        usernames.push_back(username);
        passwords.push_back(password);
    }
    infile.close();
}
void Login::saveUsernamesPasswords() {
    ofstream outfile("user_data.bin", ios::binary);
    if (!outfile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    int numUsers = usernames.size();
    outfile.write(reinterpret_cast<const char*>(&numUsers), sizeof(numUsers));
    for (int i = 0; i < numUsers; ++i) {
        int usernameSize = usernames[i].size();
        outfile.write(reinterpret_cast<const char*>(&usernameSize), sizeof(usernameSize));
        outfile.write(usernames[i].c_str(), usernameSize);
        int passwordSize = passwords[i].size();
        outfile.write(reinterpret_cast<const char*>(&passwordSize), sizeof(passwordSize));
        outfile.write(passwords[i].c_str(), passwordSize);
    }
    outfile.close();
}

void Login::changePassword()
{
    int index=0;//for password changing
    string usernam;
    cout<<endl<<"\t\t\t\t\tEnter your UserName: "<<endl<<"\t\t\t\t\t";
    cin>>usernam;
    bool found = false;
    for (size_t i = 0; i < usernames.size(); ++i) {
        if (usernames[i] == usernam ) {
            found = true;
            index=i;
            break;
        }
    }

    if (found) {
        cout << "User Name found!" << endl;
        cout<<endl<<"\t\t\t\t\tEnter your New password: "<<endl<<"\t\t\t\t\t";
        char ch;
        string password = "";
        ch = _getch();
        while (ch != 13)
            {
                password.push_back(ch);
                cout << '*';
                ch = _getch();
            }
            passwords[index]=password;
            login();
    } else {
        cout << "Invalid User Name or password. Please try again." << endl;
    }


}
void Login::menu(const string& loggedInUser)
{
    int choice=0;
        while (choice!=4) {
        cout<<"\n\t     ____________________________________________________________________________________________"<<endl;
        cout<<"\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t    |\t\t\t              WELCOME TO BABY HEALTH CHECKER AND CARE                  |"<<endl;
        cout<<"\n\t    |\t\t\t              (TWO HEARTS,ONE LOVE.)                                   |"<<endl;
        cout<<"\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t    |___________________________________________________________________________________________|"<<endl<<endl<<endl;
        cout<<"\n\t\t\t\t\t ______________________________________\n";
        cout<<"\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|                MENU                |";
        cout<<"\n\t\t\t\t\t|______________________________________|";
        cout<<"\n\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|Kindly select an option below:        |";
        cout<<"\n\t\t\t\t\t|1. Enter the details                  |";
        cout<<"\n\t\t\t\t\t|2. Check Health                       |";
        cout<<"\n\t\t\t\t\t|3. View details                       |";
        cout<<"\n\t\t\t\t\t|4. Exit                               |"<<endl;
        cout<<"\t\t\t\t\t|______________________________________|"<<endl<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
                addDetails(loggedInUser);

                break;
            case 2:
                checker(loggedInUser);
                break;
            //case 3:
                // Implement schedule appointment functionality
               // break;
            case 3:
                saveDetailsToFile(loggedInUser);
                readDetailsFromFile(loggedInUser);
                break;
            case 4:
                cout<<"YOU LOGGED OUT OF THE PROGRAM\n";
                exit(0);
            case 5:
                saveDetailsToFile(loggedInUser);
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
void Login::addDetails(const string & username) {
    int detailChoice;
    cout << "---------------------------" << endl;
    cout << "|    Add Details Menu     |" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Blood Data" << endl;
    cout << "2. Urine Data" << endl;
    cout << "3. Physical Status" << endl;
    cout<<"Enter Only Doctor consulted Test Data and Check here......"<<endl;


    cout << "Enter your choice: ";
    cin >> detailChoice;



   // Details* detail = NULL;
    ofstream fileptr;

    switch (detailChoice) {
        case 1:
            {
                auto bloodData = make_unique<BloodData>();//This part creates a new instance of the BloodData class using make_unique, which is a C++14 feature
                //BloodData* bloodData = new BloodData();//
                bloodData->inputDetails();
                bloodData->saveToFile(fileptr);
                bloodDataMap[username].push_back(move(bloodData));

                //detail = bloodData;
                //delete bloodData;
                break;
            }
            //test="bloodTest";
            //detail = new BloodData();

        case 2:
            {
                auto urineData = make_unique<UrineData>();
                //UrineData* urineData = new UrineData();
                urineData->inputDetails();
                urineData->saveToFile(fileptr);
                urineDataMap[username].push_back(move(urineData));


                //delete urineData;
                //detail = urineData;
                break;
            }
            //test="urineTest";
            //detail = new UrineData();

        case 3:
            {
                auto physicalData = make_unique<PhysicalData>();
                //PhysicalData* physicalData = new PhysicalData();
                physicalData->inputDetails();
                physicalData->saveToFile(fileptr);
                physicalDataMap[username].push_back(move(physicalData));


                //detail = physicalData;
                //delete physicalData;
                break;
            }
            //test="physicalTest";
            //detail = new PhysicalData();

        default:
            cout << "Invalid choice" << endl;
            return;
    }
    fileptr.close();
    //delete detail;

}

void Login::checker(const string &username) {
    cout << "Checking health for user: " << username << endl;

    auto& bloodDataVec = bloodDataMap[username];
    auto& urineDataVec = urineDataMap[username];
    auto& physicalDataVec = physicalDataMap[username];

    if (bloodDataVec.empty() || urineDataVec.empty() || physicalDataVec.empty()) {
        cout << "No health data available for user: " << username << endl;
        return;
    }

    BloodData* latestBloodData = bloodDataVec.back().get();
    UrineData* latestUrineData = urineDataVec.back().get();
    PhysicalData* latestPhysicalData = physicalDataVec.back().get();
    if (!latestBloodData || !latestUrineData || !latestPhysicalData) {
        cout << "Error: Null pointer encountered in health data for user: " << username << endl;
        return;
    }
    CheckHealth checkHealth;
    checkHealth.checkBaby(latestBloodData, latestUrineData, latestPhysicalData);
}

void Login::saveDetailsToFile(const string& username) {
    ofstream outFile(username + "_details.txt", ios::out|ios::trunc);
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file for writing" << endl;
        assert(false);
    }


    ifstream bloodFile("bloodtest.bin", ios::binary);
    if (bloodFile) {
        outFile << bloodFile.rdbuf();
        bloodFile.close();
    } else {
        cout << "Error: Unable to open blood test file for reading" << endl;
    }

    ifstream urineFile("urinetest.bin", ios::binary);
    if (urineFile) {
        outFile << urineFile.rdbuf();
        urineFile.close();
    } else {
        cout << "Error: Unable to open urine test file for reading" << endl;
    }

    ifstream physicalFile("physicaltest.bin", ios::binary);
    if (physicalFile) {
        outFile << physicalFile.rdbuf();
        physicalFile.close();


    } else {
        cout << "Error: Unable to open physical test file for reading" << endl;
    }
    outFile.close();
}

void Login::readDetailsFromFile(const string & username) {
    ifstream inFile(username + "_details.txt");
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file for reading" << endl;
        return;
    }

    cout << "Details for user: " << username << endl;
    cout << "------------------------------------------" << endl;

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

