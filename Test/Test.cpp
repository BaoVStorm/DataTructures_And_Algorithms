#include<bits/stdc++.h> 
using namespace std;

int main() {
    string s1, s2;
    // s1 = "100022";
    // s2 = "200044";

    cin >> s1 >> s2;

    if(s1.compare(s2) == 1) {
        cout << "S1 > S2";
    }
    else 
    if(s1.compare(s2) == 0) {
        cout << "S1 = S2";
    }
    else {
        cout << "S1 < S2";
    }
}