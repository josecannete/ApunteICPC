#include <bits/stdc++.h>
using namespace std;

//Recordar identidad minComunMultiplo(a,b) = (a * b) / gcd(a,b)
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) { return a * (b / gcd(a, b)); }
