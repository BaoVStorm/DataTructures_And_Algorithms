#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = a; i <= b; i = i + c)

using namespace std;

int Greatest_Common_Divisor (int num1, int num2) {
    while(num1 != 0 && num2 != 0) {
        if(num1 > num2)
            num1 %= num2;
        else
            num2 %= num1;
    }
    
    return (num1 + num2);
}

int Least_Common_Multiple(int num1, int num2) {
    int gcd = Greatest_Common_Divisor(num1, num2);
    return (num1 / gcd) * num2;
}

int main() {
    int num1, num2;
    
	cout << "Input num1, num2: ";
	cin >> num1 >> num2;
	
// 	gcd(a,b)
	
	cout << "Greatest Common Divisor: " << Greatest_Common_Divisor(num1, num2) << endl;
	cout << "Least Common Multiple: " << Least_Common_Multiple(num1, num2) << endl;
}