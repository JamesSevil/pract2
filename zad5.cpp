// последняя цифра трехэтажного числа
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");

    int a, b, c;
    cout << "Введите число, первую и вторую степень: ";
    cin >> a >> b >> c;

    a = a % 10;
    
    long long int step1 = (long long int) pow(a, b);
    step1 = step1 % 10;

    long long int step2 = (long long int) pow(step1, c);
    step2 = step2 % 10;

    cout << "Последняя цифра числа: " << step2;

    return 0;
}