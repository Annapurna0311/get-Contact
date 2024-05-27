#include <iostream>
#include <string>
#include <map>
#include <regex>
#include<sstream>
using namespace std;

map<string, string> contact;

void displayMenu() {
    cout << "Contact Management Program" << endl;
    cout << "-------------------------" << endl;
    cout << "1. Store Contact" << endl;
    cout << "2. Search Contact" << endl;
    cout << "3. Update Contact" << endl;
    cout << "4. Delete Contact" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void storeContact() {
    string name, phoneNumber;
    cout << "Enter name: ";
    cin >> name;

    bool isValidPhoneNumber = false;
    while (!isValidPhoneNumber) {
        cout << "Enter phone number (numeric digits only): ";
        cin >> phoneNumber;

        // Use stringstream to extract only numeric digits from the input string
        stringstream ss;
        ss.str(phoneNumber);
        int num;
        string discarded;
        isValidPhoneNumber = true;
        while (ss >> num) {
            // If any non-numeric characters are found, set isValidPhoneNumber to false
            if (discarded.size() > 0) {
                isValidPhoneNumber = false;
                break;
            }
            discarded = "";
        }
        if (ss.str().size() != phoneNumber.size()) {
            isValidPhoneNumber = false;
        }

        if (isValidPhoneNumber) {
            // Format the phone number as XXX-XXX-XXXX
            phoneNumber = string(phoneNumber.begin(), phoneNumber.begin() + 3) + "-"
                          + string(phoneNumber.begin() + 3, phoneNumber.begin() + 6) + "-"
                          + string(phoneNumber.begin() + 6, phoneNumber.end());
            contact[name] = phoneNumber;
            cout << "Contact stored successfully!" << endl;
        } else {
            cout << "Invalid phone number input. Please enter only numeric digits." << endl;
        }
    }
}

void searchContact() {
    string name;
    cout << "Enter name to search: ";
    cin >> name;
    if (contact.find(name) != contact.end()) {
        cout << "Contact found: " << name << " - " << contact[name] << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
}

void updateContact() {
    string name, phoneNumber;
    cout << "Enter name to update: ";
    cin >> name;
    if (contact.find(name) != contact.end()) {
        cout << "Enter new phone number: ";
        cin >> phoneNumber;
        contact[name] = phoneNumber;
        cout << "Contact updated successfully!" << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
}

void deleteContact() {
    string name;
    cout << "Enter name to delete: ";
    cin >> name;
    if (contact.find(name) != contact.end()) {
        contact.erase(name);
        cout << "Contact deleted successfully!" << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                storeContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                updateContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
