#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;

    getline(cin, input);

    if (input.find("d2") != string::npos || input.find("D2") != string::npos) {
        cout << "D2" << endl;
    } else {
        cout << "unrated" << endl;
    }

    return 0;
}