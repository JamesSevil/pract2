// Теорема Ферма и св-во сравнений(1 алгоритм)
#include <iostream>
#include <math.h>

using namespace std;

bool CheckPrime(int p) { // проверка, является ли модуль простым числом
    
    if (p <= 1) return false; // не может быть <=1
    for (int i = 2; i * i <= p; ++i) { // начинаем с 2 до (квадратного корня из числа) <=p
        if (p % i == 0) return false; // Если нет остатка, то не простое, иначе простое
    }

    return true;
}

int algorithm(int a, int x, int p) { // Алгоритм нахождения остатка

    int nums[100]; // инициализируем массив чисел, в котором хранятся уникальные остатки

    nums[0] = a % p; // присваиваем 1 числу остаток
    int k=0, n=1; // k - условие выхода | n - счётчик уникальных остатков
    for (int i=1; k==0; i++) {
        nums[i] = pow(a, i+1);
        nums[i] = nums[i] % p;
        if (nums[i] == nums[0]) { 
            k = k + 1; // если найденный остаток = первому, то выходим из цикла
        } else {
            n = n + 1; // иначе увеличиваем счётчик
        }
    }

    int result;
    int num = x % n; // считаем, сколько полных циклов входит в степень
    if (num == 0) { 
        result = nums[n-1]; // если остаток 0, то результат = последнему уникальному остатку
    } else {
        result = nums[num-1]; // иначе результат = своему номеру уникального остатка
    }

    return result;
}

int main(){
    setlocale(LC_ALL, "Rus");

    cout << "Нахождение остатка числа a^x mod p:" << endl;
    
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