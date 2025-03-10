#include <iostream>
#include"health.h"
#include<string>

using namespace std;

int main()
{
    Login login;
    login.readUsernamesPasswords();
    int choice=0;
    cout << "---------------------------" << endl;
    cout << "|       BABY HEALTH CARE        |" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Login" << endl;
    cout << "2. Create Account" << endl;
    cout << "3. Change Password" << endl;
    cout<<"4. Exit"<<endl;

    while(choice!=4)
    {
        cout <<"\n\n"<< "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                login.login();
                exit(0);
                break;
            case 2:
                login.createAccount();
                login.saveUsernamesPasswords();
                break;
            case 3:
                login.changePassword();
                break;
            case 4:
                cout<<"You exited the program\n";
                login.saveUsernamesPasswords();
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }


    return 0;
}
