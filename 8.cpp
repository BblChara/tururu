#include <iostream>
using namespace std;

 long long div1(long long dividend, long long divisor) {
    long long result = 1;
    long long denominator = divisor;
    //  ��������� ������� ����������� denominator �� ��� ���, ���� ��� �� ������ ������ ��������
    while (dividend > denominator) {
        denominator <<= 1;
        result <<= 1;
    }

    // �������� �������� �������� �� ����������� �� ��� ���, ���� ��� �� ������ ������ ��������
    while (denominator > dividend) {
        denominator -= divisor;
        result -= 1;
    }

    return result;
}

 int main() {
     long long dividend, divisor;
     cin >> dividend >> divisor;
     cout << div1(dividend, divisor);
 
 }