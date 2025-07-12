#include <iostream>
using namespace std;

int menu = 6;
double initial_amount = 2000.00;
double deposit;
int new_pin;
string name;
string user = "Griffin";
int user_pin = 1234;

// Withdraw function
double withdraw_money(double &initial_amount) {
    double amount;
    cout << "Enter amount to Withdraw: ";
    cin >> amount;

    if (initial_amount >= amount) {
        initial_amount -= amount;
        cout << "You have withdrawn Amount: $" << amount << endl;
        cout << "New Balance is: $" << initial_amount << endl;
    } else {
        cout << "You have insufficient Balance" << endl;
    }

    return initial_amount;
}

// Settings function
void change(int &new_pin, string &user, int &user_pin) {
    string response;
    cout << "\nMake Changes to Your Account\n"
         << "Select what you want to edit:\n"
         << "1. Name\n2. Pin\n(Type 'Name' or 'Pin' to make changes): ";
    cin >> response;

    if (response == "name" || response == "Name") {
        string old_name = user;
        cout << "Enter New User name: ";
        cin >> user;
        cout << "You have changed your Username from: " << old_name << " to: " << user << endl;
    } else if (response == "pin" || response == "Pin") {
        cout << "Enter New Pin: ";
        cin >> new_pin;
        user_pin = new_pin;
        cout << "You have changed your PIN successfully 🤝🤝" << endl;
    } else {
        cout << "Invalid Request! ❌ Try again 😕" << endl;
    }
}

int main() {
    int pin;

    cout << "Name: ";
    cin >> name;
    cout << "Enter Pin: ";
    cin >> pin;

    if (name == user && pin == user_pin) {
        cout << "\nLogin Successful!\n" << endl;
    } else {
        cout << "Wrong user name or pin. Access Denied." << endl;
        return 0;
    }

    while (true) {
        cout << "\n----- ATM MENU -----\n"
             << "1. Account Balance\n"
             << "2. Deposit Money\n"
             << "3. Withdraw Money\n"
             << "4. Settings\n"
             << "5. Exit\n"
             << "Enter your Choice: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Account Balance is: $" << initial_amount << "\n" << endl;
                break;
            case 2:
                cout << "Enter amount to Deposit: ";
                cin >> deposit;
                initial_amount += deposit;
                cout << "Deposit Successful.\nNew Balance is: $" << initial_amount << endl;
                break;
            case 3:
                withdraw_money(initial_amount);
                break;
            case 4:
                change(new_pin, user, user_pin);
                break;
            case 5:
                cout << "Exit Successful!" << endl;
                return 0;
            default:
                cout << "Invalid Option. Please choose 1 to 5." << endl;
        }
    }

    return 0;
}
