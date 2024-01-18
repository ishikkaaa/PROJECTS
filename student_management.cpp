#include <iostream>
#include <vector>
#include <string>
using namespace std;

class student {
private:
    int rollNo, age;
    string name;

public:
    student(int rollNo, int age, string name) {
        this->age = age;
        this->name = name;
        this->rollNo = rollNo;
    }

    void setRollno(int r) {
        rollNo = r;
    }

    int getRollno() {
        return rollNo;
    }

    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setAge(int a) {
        age = a;
    }

    int getAge() {
        return age;
    }
};

void addNewStudent(vector<student> &students) {
    int age, r;
    string name;
    cout << "enter age" << endl;
    cin >> age;
    cout << "enter roll no" << endl;
    cin >> r;
    // to check if student already exists
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getRollno() == r) {
            cout << "student already exists" << endl;
            return;
        }
    }
    cout << "enter name" << endl;
    cin >> name;
    student newStudent(r, age, name);
    students.push_back(newStudent);
    cout << "student added successfully" << endl;
}

void display(vector<student>&students){
    if(students.size()==0){
        cout<<"no student exists"<<endl;
        return;
    }
    for(int i=0;i<students.size();i++){
        cout<<students[i].getRollno()<<" "<<students[i].getAge()<<" "<<students[i].getName()<<endl;
    }
}

void search(vector<student>&students){
    int r;
    cout<<"enter the roll no u want to search"<<endl;
    cin>>r;
    for(int i=0;i<students.size();i++){
        if(students[i].getRollno()==r){
            cout<<"student found"<<endl;
            return;
        }
    }
    cout<<"student not found"<<endl;
}

void update(vector<student> &students) {
    cout << "enter the roll no of student you want to update information of." << endl;
    int r;
    cin >> r;
    bool studentFound = false;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getRollno() == r) {
            cout << "student found" << endl;
            cout << "enter the option of corresponding info you want to update" << endl;
            cout << "1. update name" << endl;
            cout << "2. update age" << endl;
            cout << "3. update rollno" << endl;

            int op;
            cin >> op;

            switch (op) {
            case 1: {
                cout << "enter new name: ";
                string name;
                cin >> name;
                students[i].setName(name);
                break;
            }
            case 2: {
                cout << "enter new age: ";
                int age;
                cin >> age;
                students[i].setAge(age);
                break;
            }
            case 3: {
                cout << "enter new roll no: ";
                int roll_no;
                cin >> roll_no;
                students[i].setRollno(roll_no);
                break;
            }
            }

            studentFound = true;
            break;
        }
    }

    if (!studentFound) {
        cout << "student not found" << endl;
    }
}

void deleteRecord(vector<student>&students){
    string name;
    cout<<"enter the name of student u want to delete from records"<<endl;
    cin>>name;
    for(int i=0;i<students.size();i++){
        if(students[i].getName()==name){
            students.erase(students.begin()+i);
            cout<<"deletion successfull"<<endl;
            return;
        }
    }
    cout<<"no such student found"<<endl;
    return;  
}


int main() {
    vector<student> students;
    students.push_back(student(1, 12, "ali"));
    int op;
    char choice;
    do {
        cout << "1. Add new student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Search student" << endl;
        cout << "4. Update student" << endl;
        cout << "5. Delete student" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice" << " ";
        cin >> op;

        switch (op) {
        case 1: {
            addNewStudent(students);
            break;
        }
        case 2:{
            display(students);
            break;
        }
        case 3:{
            search(students);
            break;
        }
        case 4:{
            update(students);
            break;
        }
        case 5:{
            deleteRecord(students);
            break;
        }
        case 6:{
            exit(0);
            break;
        }


        }

        cout << "do you want to continue [yes/no]?" << endl;
        cin >> choice;
    } while (tolower(choice) == 'y');

    return 0;
}
