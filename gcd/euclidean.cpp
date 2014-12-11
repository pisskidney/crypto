#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b) {
    int c;
    while (b > 0) {
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}

int main(int argc, char* argv[]) {
    cout << gcd(27, 21) << endl;
    cout << gcd(27, 17) << endl;
    cout << gcd(27, 1) << endl;
    return 0;
}
