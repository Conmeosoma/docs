#include <iostream>
#define ll long long
using namespace std;

// Extended Euclidean algorithm: returns g = gcd(a,b) and finds x,y such that a*x + b*y = g
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

// Compute modular inverse of a modulo m.
// If inverse exists, returns inverse in [0, m-1] and true; otherwise returns 0 and false.
pair<ll,bool> modInverse(ll a, ll m)
{
    if (m <= 0) return {0, false};
    a %= m;
    if (a < 0) a += m;
    ll x = 0, y = 0;
    ll g = extended_gcd(a, m, x, y);
    if (g != 1) // inverse doesn't exist
        return {0, false};
    // x is the inverse modulo m, may be negative
    ll inv = x % m;
    if (inv < 0) inv += m;
    return {inv, true};
}

int main()
{
    cout << "Nhap a va m (tim nghich dao a mod m): ";
    ll a, m;
    if (!(cin >> a >> m))
        return 0;

    auto res = modInverse(a, m);
    if (!res.second)
        cout << "Khong ton tai nghich dao cua " << a << " mod " << m << "\n";
    else
        cout << "Nghich dao cua " << a << " mod " << m << " la: " << res.first << "\n";

    return 0;
}
