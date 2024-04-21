#include <iostream>
#include <math.h>

using namespace std;

int LastNum(int num, int nums[]) { // нахождение уникальной комбинации последних цифр в числе

    nums[0] = pow(num, 1);
    nums[0] %= 10;
    int n = 1, i = 0;

    do {
        i++;
        nums[i] = pow(num, i+1);
        nums[i] = nums[i] % 10;
        n = n + 1;
    } while (nums[i] != nums[i-1] || nums[i] != nums[i-2] || nums[i] != nums[i-3] || nums[i] != nums[i-4]);

    return n;
}

int main(){
    setlocale(LC_ALL, "Rus");

    int a, b, c;
    cout << "Введите число, первую и вторую степень: ";
    cin >> a >> b >> c;

    a = a % 10;
    int nums1[10];
    int n1;
    n1 = LastNum(a, nums1); // находим уникальные конечные цифры и их кол-во
    int step1 = b % n1;
    if (step1 == 0) {
        b = nums1[n1-1]; // если остаток = 0, то конечная цифра - последняя цифра комбинации 
    } else {
        b = nums1[step1-1]; // иначе (цифра комбинации) - 1
    }

    int nums2[10];
    int n2;
    n2 = LastNum(b, nums2);
    int step2 = c % n2;
    if (step2 == 0) {
        c = nums2[n2-1];   
    } else {
        c = nums2[step2-1];
    }

    cout << "Последняя цифра: " << c;
    
    return 0;
}