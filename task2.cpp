#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool usernameExists(const string& username) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "Register\nEnter username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "Username already exists.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    cout << "Registration successful.\n";
}

void loginUser() {
    string username, password;
    cout << "Login\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    bool found = false;

    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Login successful. Welcome, " << username << "!\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
