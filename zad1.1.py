def CheckPrime(p):
    
    if (p <= 1): return False
    if (p <= 3): return True
    if (p % 2 == 0) or (p % 3 == 0): return False
    for i in range(5, int(p**0.5)+1, 6):
        if (p % i == 0) or (p % (i+2) == 0): return False
    
    return True

def algorithm(a, x, p):
    
    result = 1
    
    a = a % p
    while (x > 0):
        if (x % 2 == 1): result = (result * a) % p
        x //= 2
        a = (a * a) % p
    
    return result


print("Сравнение по модулю простого числа a^x mod p:")

a = int(input("Введите число а: ")) # ввод чисел
x = int(input("Введите степень x: "))
p = int(input("Введите модуль p: "))

if (CheckPrime(p) == False): print("p не простое число.") # проверка, является ли модуль простым числом
elif (a % p == 0) and (x != 0): print("Теорема Ферма не выполняется: a^x ≡ 0 (mod p)") # проверка, выполняется ли теорема Ферма
else: # вывод результата
    result = algorithm(a, x, p)
    print(f"{a}^{x} mod {p} = {result}")