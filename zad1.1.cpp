// Теорема Ферма и св-во сравнений
#include <iostream>

using namespace std;

bool CheckPrime(int p) { // проверка, является ли модуль простым числом
    
    if (p <= 1) return false; // не может быть <=1
    if (p <= 3) return true; // 2, 3 подходит
    if (p % 2 == 0 || p % 3 == 0) return false; // исключаем числа, которые делятся на 2 и 3
    for (int i=5; i*i<=p; i=i+6) {
        if (p % i == 0 || p % (i+2) == 0) {
            return false;
        }
    }

    return true;
}

int algorithm(int a, int x, int p) { // Алгоритм нахождения остатка

    int result = 1;

    a = a % p;
    while (x > 0) {
        if (x % 2 == 1)
            result = (result * a) % p;
        x /= 2;
        a = (a * a) % p;
    }

    return result;
}

int main(){
    setlocale(LC_ALL, "Rus");

    cout << "Сравнение по модулю простого числа a^x mod p:" << endl;
    
    int a, x, p; // ввод чисел
    cout << "Введите числа a, x и p: ";
    cin >> a >> x >> p;

    if (CheckPrime(p)==false) { // проверка, является ли модуль простым числом
        cout << "p не простое число." << endl;
        return 1;
    }

    if (a % p == 0 && x != 0) { // проверка, выполняется ли теорема Ферма
        cout << "Теорема Ферма не выполняется: a^x ≡ 0 (mod p)" << endl;
        return 1;
    }

    int result = algorithm(a, x, p); // вывод результата
    cout << a << "^" << x << " mod " << p << " = " << result;

    return 0;
}