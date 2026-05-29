#include <iostream>
#include <tuple>
#define ll long long
using namespace std;

// Extended Euclidean algorithm
// Returns gcd(a,b) and finds x,y such that a*x + b*y = gcd(a,b)
ll extended_gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = (a >= 0) ? 1 : -1;
        y = 0;
        return (a >= 0) ? a : -a;
    }
    ll x1 = 0, y1 = 0;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main()
{
    ll a, b;
    cout << "Nhap 2 so (a b): ";
    if (!(cin >> a >> b))
        return 0;

    ll x = 0, y = 0;
    ll g = extended_gcd(a, b, x, y);

    cout << "gcd(" << a << ", " << b << ") = " << g << "\n";
    cout << "He so: x = " << x << ", y = " << y << "\n";
    cout << "Check: " << a << "*" << x << " + " << b << "*" << y << " = " << (a * x + b * y) << "\n";
    return 0;
}
