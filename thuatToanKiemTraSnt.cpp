#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

// Ham tinh (base^exp) % mod
ll power(ll base, ll exp, ll mod)
{
    ll result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// thuat toan Miller-Rabin de kiem tra so nguyen to
bool isPrime(ll n, int k)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }

    ll d = n - 1;
    int r = 0;
    while (d % 2 == 0)
    {
        d /= 2;
        r++;
    }

    for (int i = 0; i < k; i++)
    {
        ll a = rand() % (n - 4) + 2; // Chọn ngẫu nhiên a trong khoảng [2, n-2]
        ll x = power(a, d, n);
        if (x == 1 || x == n - 1)
            continue;

        bool composite = true; //
        for (int j = 0; j < r - 1; j++)
        {
            x = power(x, 2, n);
            if (x == n - 1)
            {
                composite = false;
                break;
            }
        }
        if (composite)
            return false;
    }
    return true;
}

int main()
{
    ll n;
    int k; // So lan kiem tra

    cout << "Nhap so can kiem tra: ";
    cin >> n;
    cout << "Nhap so lan kiem tra: ";
    cin >> k;

    if (isPrime(n, k))
    {
        cout << n << " la so nguyen to" << endl;
    }
    else
    {
        cout << n << " khong phai la so nguyen to" << endl;
    }
    return 0;
}