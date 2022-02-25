#include <iostream>
using namespace std;

 long long div1(long long dividend, long long divisor) {
    long long result = 1;
    int k = 1;

    if (divisor < 0 && dividend > 0) { divisor *= -1; k = -1; }
    else if (divisor > 0 && dividend < 0) { dividend *= -1; k = -1;}
    else if (divisor < 0 && dividend < 0) { dividend *= -1; divisor *= -1; }
    if ((divisor > dividend) | (divisor ==0) | (dividend ==0)) return 0;

    //  ��������� ������� ����������� denominator �� ��� ���, ���� ��� �� ������ ������ ��������
    long long denominator = divisor;
    while (dividend > denominator) {
        denominator <<= 1;
        result <<= 1;
    }

    // �������� �������� �������� �� ����������� �� ��� ���, ���� ��� �� ������ ������ ��������
    while (denominator > dividend) {
        denominator -= divisor;
        result -= 1;
    }

    return k*result;
}

 int main() {
     long long dividend, divisor;
     cin >> dividend >> divisor;
     cout << div1(dividend, divisor);
 
 }