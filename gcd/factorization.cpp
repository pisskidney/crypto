#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

vector<int> get_prime_factors(int n) {
    vector<int> facts;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            n /= i;
            facts.push_back(i);
        } else {
            i += 1;
        }
    }
    if (n > 1) facts.push_back(n);

    return facts;
}

long int gcd_fact(int a, int b) {
    if (a == 1 || b == 1) return 1;
    unsigned long int gcd = 1;
    vector<int> f1, f2;
    f1 = get_prime_factors(a);
    f2 = get_prime_factors(b);
    unsigned int i = 0;
    unsigned int j = 0;
    while ((i < f1.size()) && (j < f2.size())) {
        if (f1[i] == f2[j]) {
            gcd *= f1[i];
            i++;
            j++;
        } else if (f1[i] < f2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return gcd;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./a.out [nr1] [nr2]" << endl;
        return 1;
    }
    long int a = atoi(argv[1]);
    long int b = atoi(argv[2]);
    cout << "->" << gcd_fact(a, b) << endl;

    return 0;
}
