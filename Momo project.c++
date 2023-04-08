#include <iostream>
using namespace std;

int amount, balance, option, wrong_pin_count;
string pin, enter_pin, old_pin, new_pin, receiver_number;

bool authenticate(string entered_pin)
{
    if (entered_pin == pin)
    {
        wrong_pin_count = 0;
        return true;
    }
    else
    {
        wrong_pin_count++;
        if (wrong_pin_count >= 3)
        {
            cout << "Too many wrong attempts. Program will exit." << endl;
            exit(0);
        }
        else
        {
            cout << "Wrong pin. Please try again." << endl;
            return false;
        }
    }
}

int main()
{
    pin = "0000";
    balance = 1000;
    wrong_pin_count = 0;

    do
    {
        cout << " " << endl;
        cout << "=====================================" << endl;
        cout << "   Humphrey's Mobile Money Service   " << endl;
        cout << "=====================================" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset/Change Pin" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter pin: ";
            cin >> enter_pin;
            if (authenticate(enter_pin))
            {
                cout << "Authentication Successful." << endl;
            }
            break;

        case 2:
            cout << "Enter old pin: ";
            cin >> old_pin;
            if (authenticate(old_pin))
            {
                cout << "Enter new pin: ";
                cin >> new_pin;
                pin = new_pin;
                cout << "Pin changed successfully." << endl;
            }
            break;
        case 3:
            cout << "Enter pin: ";
            cin >> enter_pin;
            if (authenticate(enter_pin))
            {
                cout << "YOur balance is: " << balance << endl;
            }
            break;
        case 4:
            cout << "Enter receiver's phone number: " << endl;
            cin >> receiver_number;
            cout << "Enter amount: " << endl;
            cin >> amount;
            cout << "Enter pin: " << endl;
            cin >> enter_pin;
            if (authenticate(enter_pin))
            {
                if (amount <= balance)
                {
                    balance -= amount;
                    cout << amount << " was successfully sent to " << receiver_number << endl;
                    cout << "Your new balance is: " << balance << endl;
                }
                else
                {
                    cout << "You have insufficient funds." << endl;
                }
            }
            break;
        case 5:
            cout << "Thank you for using Humphrey's Mobile Money Service." << endl;
            break;
        default:
            cout << "Invalid Option. Please select a valid option." << endl;
        }

    } while (option != 5);

    return 0;
}
