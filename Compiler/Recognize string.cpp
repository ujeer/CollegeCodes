#include <iostream>
#include <string>
using namespace std;

// Function to check if string is a*
bool is_a_star(const string &s) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] != 'a') return false;
    return true;
}

// Function to check if string is a*b+
bool is_a_star_b_plus(const string &s) {
    int i = 0;
    while (i < s.size() && s[i] == 'a') i++; // skip a*
    
    int bCount = 0;
    while (i < s.size() && s[i] == 'b') {
        i++;
        bCount++;
    }

    return (i == s.size() && bCount > 0); // must end with only b+
}

// Function to check if string is exactly "abb"
bool is_abb(const string &s) {
    return s == "abb";
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    if (is_abb(str))
        cout << "String matches abb" << endl;
    else if (is_a_star(str))
        cout << "String matches a*" << endl;
    else if (is_a_star_b_plus(str))
        cout << "String matches a*b+" << endl;
    else
        cout << "String does not match any pattern" << endl;

    return 0;
}


