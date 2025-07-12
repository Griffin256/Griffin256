#include <iostream>
#include <algorithm>
using namespace std;

int menu = 6;
int initial_amount = 2000;
int deposit, amount, new_pin ;

string name, New_name;
string user = "Griffin";
int user_pin = 1234;
// Withdraw function
int withdraw_money(int amount, int &initial_amount) {
    cout << "Enter amount to Withdraw: ";
    cin >> amount;

    if (initial_amount >= amount) {
        initial_amount -= amount;
        cout << "You have withdrawn Amount: " << amount << endl;
        cout << "New Balance is: " << initial_amount << endl;
    } else {
        cout << "You have insufficient Balance" << endl;
    }

    return initial_amount;
}

void change(int &new_pin, string &user) {
    string response;
    cout << "Make Changes on Your account\n Select What you want to Edit \n 1.Name\n2.Pin\n --Just Type Like Pin or Name to make changes---" << endl;
    cin >> response;
    if(response == "name" || response == "Name") {
        cout << "Enter New User name: ";
        cin >> New_name;
        user = New_name;
        cout << "You have changed Your Username from: "<<user<<"To :"<<New_name;
    }
    else if( response == "pin" || response == "Pin") {
        cout << "Enter New Pin : ";
        cin >> new_pin;
        user_pin = new_pin;
        cout << "You have changed Your pin successfully 🤝🤝" << endl;
    } else {
        cout << "Invalid Request! ❌❌❌❌. Try again 😕😕" << endl;
    }
    
}

int main() {
    int pin;

    cout << "Name: ";
    cin >> name;
    cout << "Enter Pin: ";
    cin >> pin;

    if (name == user && pin == user_pin) {
        cout << "Login Successful!\n" << endl;
    } else {
        cout << "Wrong user name or pin. Access Denied." << endl;
        return 0;
    }

    while (true) {
        cout << "----- ATM MENU -----\n"
             << "Enter your Choice \n"
             << "1. Account Balance\n"
             << "2. Deposit Money\n"
             << "3. Withdraw Money\n"
             << "4. Settings\n"
             << "5. Exit" << endl;
        cin >> menu;

        switch (menu) {
        case 1:
            cout << "Account Balance is: $" << initial_amount << "\n" << endl;
            break;
        case 2:
            cout << "Enter amount to Deposit: ";
            cin >> deposit;
            initial_amount += deposit;
            cout << "Deposit Successful.\nNew Balance is: " << initial_amount << endl;
            break;
        case 3:
            withdraw_money(amount, initial_amount);
            break;

        case 4:
            change(new_pin, New_name);
            break;
        case 5:
            cout << "Exit Successful!" << endl;
            return 0;
        default:
            cout << "Invalid Option. Please choose 1, 2, 3 or 4." << endl;
        }
    }

    return 0;
}
    
