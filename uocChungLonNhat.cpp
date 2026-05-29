#include <iostream>
#include <cmath>
#define ll long long
#define MAX 1000000
#define MOD 1000000007
using namespace std;

// Tinh UCLN (gcd) bang thuat toan Euclid
ll ucln(ll a, ll b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (b != 0)
    {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

ll bcnn(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    ll g = ucln(a, b);
    return (a / g) * b;
}

int main()
{
    ll a, b;
    cout << "Nhap 2 so (a b): ";
    if (!(cin >> a >> b))
        return 0;

    ll g = ucln(a, b);
    ll l = bcnn(a, b);

    cout << "UCLN(" << a << ", " << b << ") = " << g << endl;
    cout << "BCNN(" << a << ", " << b << ") = " << l << endl;
    return 0;
}
