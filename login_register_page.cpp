#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
private:
    string username, password;

public:
    User(string username, string password) {
        this->username = username;
        this->password = password;
    }

    string getusername() {
        return username;
    }

    string getpassword() {
        return password;
    }
};

class UserManager {
private:
    vector<User> users;

public:
    void registerUser() {
        string uname, pass;
        cout << "\t\tEnter username: ";
        cin >> uname;
        cout << "\t\tEnter password: ";
        cin >> pass;

        User newuser(uname, pass); // Object of User class
        users.push_back(newuser);
        cout << "Registration successful\n";
    }

    bool login(string uname, string pass) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getusername() == uname && users[i].getpassword() == pass) {
                cout << "\t\tLogin successful\n";
                return true;
            }
        }
        cout << "Login unsuccessful\n";
        return false;
    }

    void showUsers() {
        cout << "\t\t----USERS LIST---" << endl;
        for (int i = 0; i < users.size(); i++) {
            cout << users[i].getusername() << endl;
        }
    }

    void searchUser(string name) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getusername() == name) {
                cout << "User found\n";
                return;
            }
        }
        cout << "User not found\n";
        return;
    }

    void deleteUser(string name) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getusername() == name) {
                users.erase(users.begin() + i);
                cout << "Removal successful\n";
                return;
            }
        }
        cout << "User not found for deletion\n";
    }
};

int main() {
    UserManager umanage;
    int op;
    char choice;
    do {
        system("cls");
        cout << "\t\t1. Register user\n";
        cout << "\t\t2. Login user\n";
        cout << "\t\t3. Show user list\n";
        cout << "\t\t4. Search user\n";
        cout << "\t\t5. Delete user\n";
        cout << "\t\t6. Exit\n";
        cout << "\t\tEnter your choice: ";
        cin >> op;

        switch (op) {
        case 1: {
            umanage.registerUser();
            break;
        }

        case 2: {
            string uname, pass;
            cout << "\t\tEnter username: ";
            cin >> uname;
            cout << "\t\tEnter password: ";
            cin >> pass;
            umanage.login(uname, pass);
            break;
        }
        case 3: {
            umanage.showUsers();
            break;
        }
        case 4: {
            string name;
            cout << "Enter the user you want to search: ";
            cin >> name;
            umanage.searchUser(name);
            break;
        }
        case 5: {
            string name;
            cout << "Enter the user you want to delete: ";
            cin >> name;
            umanage.deleteUser(name);
            break;
        }
        case 6: {
            exit(0);
        }
        default:
            cout << "Invalid choice\n";
        }

        cout << "Do you want to continue [yes/no]? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    //if(choice=="N"|| choice=="n") cout<<"program ended successfully";

    return 0;
}
