//
//  main.cpp
//  lab5
//
//  Created by Khaled  Nana  on 05/03/2024.
//

#include <iostream>
#include <cmath>
using namespace std;

int digits(long x) {
    int d = 0;
    while (x >= 10) {
        x = x / 10;
        d++;
    }
    return d + 1;
}

long kAlgo(long n1, long n2) {
    if (n1 < 10 || n2 < 10) {
        return n1 * n2;
    }
    
    long dn1 = digits(n1);
    long dn2 = digits(n2);
    long dn = max(dn1, dn2);
    long m = max(dn1, dn2) / 2;
    long n1_1 = n1 / static_cast<long>(pow(10, m));
    long n1_2 = n1 % static_cast<long>(pow(10, m));
    long n2_1 = n2 / static_cast<long>(pow(10, m));
    long n2_2 = n2 % static_cast<long>(pow(10, m));
    long ac = kAlgo(n2_2, n2_1);
    long eq3 = kAlgo((n2_1 + n1_2), (n2_2 + n1_1));
    long bd = kAlgo(n1_2, n1_1);
    return (bd * static_cast<long>(pow(10, 2 * m))) + ((eq3 - bd - ac) * static_cast<long>(pow(10, m))) + ac;
}

int main(int argc, const char * argv[]) {
    cout << kAlgo(123, 45) << endl;
    return 0;
}
