#include<bits/stdc++.h> 
using namespace std;

int compareString(string s1, string s2) {
    while(s1[0] == '0')
        s1.erase(0, 1);
    
    while(s2[0] == '0')
        s2.erase(0, 1);

    if(s1.length() > s2.length()) 
        return 1;

    if(s1.length() < s2.length()) 
        return -1;  

    return s1.compare(s2);
}

string Subtraction_NumberString(string s1, string s2) {
    int compare = compareString(s1, s2);
    string subString = "";
    int n;

    if(compare == 0)
        return "0";
    else
    if(compare < 0)
        swap(s1, s2);
    
    int m = s1.length() - s2.length();

    for(int i = 1; i <= m; i++) 
        s2 = "0" + s2;

    n = s1.length();
    vector<int> mem(n, 0);

    for(int i = n - 1; i >= 0; i--) {
        if(int(s1[i]) - mem[i] >= int(s2[i])) 
            subString = to_string(int(s1[i]) - mem[i] - int(s2[i])) + subString;
        else {
            subString = to_string(10 + int(s1[i]) - mem[i] - int(s2[i])) + subString;
            
            if(i - 1 >= 0)
                mem[i - 1] = 1;
        }
    }
    
    while(subString[0] == '0') {
        subString.erase(0, 1);
    }

    if(compare < 0)
        subString = "-" + subString;

    return subString;
}

int main() {
    string s1, s2;

    cout << "Input s1, s2 (s1 >= 0, s2 >= 0): ";
    cin >> s1 >> s2;

    cout << "Subtraction: " << Subtraction_NumberString(s1, s2);
}