#include <iostream>
#include <vector>
using namespace std;
class User {
    vector<string> name;
    vector<string> password;
public:
    User(string name, string password) {
        this->name.push_back(name);
        this->password.push_back(password);
    }
    void AddUser(string name, string password) {
        this->name.push_back(name);
        this->password.push_back(password);
    }
    int login(string name, string password) {
        int location = 0;
        for (int i = 0; i < this->name.size(); i++) {
            if (!this->name[i].compare(name)) {
                location = i;
                break;
            }
        }
        if (!this->password[location].compare(password) ) {
            return location;
        }

        else {
            return -1;
        }
    }
};
int main() {
    char name[10], name1[10], pass[10], pass1[10];
    cin >> name >> pass >> name1 >> pass1;
    User user("LiWei", "liwei101");
    user.AddUser(name, pass);
    if (user.login(name1, pass1) >= 0)
    {
        cout << "Success Login!" << endl;
    }
    else {
        cout << "Login failed!" << endl;
    }
    return 0;
};