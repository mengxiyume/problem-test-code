#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) { // ע�� while ������ case
        string subStr;
        subStr += (str.c_str() + str.find_last_of(' ') + 1);
        cout << subStr.size() << endl;
    }
}