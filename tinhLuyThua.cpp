#include <iostream>
#include <cmath>
#define ll long long
#define mod 1000000007
using namespace std;
// tinh luy thua (a mu b) mod n
ll power(ll a, ll b, ll n)
{
    ll result = 1;
    a = a % n; // Đảm bảo a nhỏ hơn n
    // Giảm a về phạm vi [0,n)
    while (b > 0)
    // Lặp khi b  > 0
    {
        // Kiểm tra bit cuối của b
        if (b & 1)// đây là phép toán AND bitwise để kiểm tra xem 
        //bit cuối của b có phải là 1 (số lẻ) hay không
        {
            // Nếu bit cuối của b là số lẻ
            result = (result * a) % n;
            // kq = (kq * a) mod n
        }
        // b phải là số chẵn tại đây
        b /= 2; // b = b / 2
        // chia b cho 2 để loại bỏ bit cuối đã được xử lý
        a = (a * a) % n;
        // sau mỗi lần lặp, a được bình phương và giảm modulo n
        // Bình phương a
    }
    return result;
}
/*
VD 3 ^ 13 mod 7
Ta có a = 3, b = 13 , n = 7
Lần 1:  kq = 1
a = a % n = 3 % 7 = 3
b = 13 > 0
bit cuối của b là 1
13 = 1101 (bit cuối là 1)
kq = (kq * a) mod n = (1 * 3) mod 7 = 3
b = b / 2 = 13 / 2 = 6
a = (a * a) mod n = (3 * 3) mod 7 = 2
return 3

Lần 2: kq = 3
a = a % n = 2 % 7 = 2
b = 6 > 0
bit cuối của b là 0
6 = 110 (bit cuối là 0)
b = b / 2 = 6 / 2 = 3
a = (a * a) mod n = (2 * 2) mod 7 = 4
return 3

Lần 3: kq = 3
a = a % n = 4 % 7 = 4
b = 3 > 0
bit cuối của b là 1
3 = 11 (bit cuối là 1)
kq = (kq * a) mod n = (3 * 4) mod 7 = 5
b = b / 2 = 3 / 2 = 1
a = (a * a) mod n = (4 * 4) mod 7 = 2
return 5

lần 4: kq = 5
a = a % n = 2 % 7 = 2
b = 1 > 0
bit cuối của b là 1
1 = 1 (bit cuối là 1)
kq = (kq * a) mod n = (5 * 2) mod 7 = 3
b = b / 2 = 1 / 2 = 0
a = (a * a) mod n = (2 * 2) mod 7 = 4
return 3
Vậy kết quả của 3 ^ 13 mod 7 là 3


*/
int main()
{
    ll a, b, n;
    cout << "Nhap a, b, n: ";
    cin >> a >> b >> n;
    cout << "Ket qua: " << power(a, b, n) << endl;
    return 0;
}