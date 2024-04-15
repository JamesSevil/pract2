a = int(input("Введите число: "))
b = int(input("Введите 1-ю степень числа: "))
c = int(input("Введите 2-ю степень числа: "))

a = a % 10
step1 = pow(a, b)
step1 = step1 % 10
step2 = pow(step1, c)
step2 = step2 % 10

print("Последняя цифра: ", step2)