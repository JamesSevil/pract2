# Теорема Ферма и св-во сравнений(1 алгоритм)
def CheckPrime(p): # проверка, является ли модуль простым числом
    
    if (p <= 1): return False # не может быть <=1
    for i in range(2, int(p ** 0.5) + 1): # начинаем с 2 до (квадратного корня из числа) <=p
        if (p % i == 0): return False # Если нет остатка, то не простое, иначе простое
        
    return True

def algorithm(a, x, p): # Алгоритм нахождения остатка
    
    nums = [0] * 100 # инициализируем массив чисел, в котором хранятся уникальные остатки
    
    nums[0] = a % p # присваиваем 1 числу остаток
    k = 0 # условие выхода
    n = 1 # счётчик
    i = 1
    while k == 0:
        nums[i] = pow(a, i+1)
        nums[i] = nums[i] % p
        if nums[i] == nums[0]: k += 1 # если найденные остаток = первому, то выходим из цикла
        else: n += 1 # иначе увеличиваем счётчик
        i += 1

    result = 0
    num = x % n # считаем, сколько полных циклов входит в степень
    if num == 0: result = nums[n-1] # если остаток 0, то результат = последнему уникальному остатку
    else: result = nums[num-1] # иначе результат = своему номеру уникального остатка

    return result


print("Нахождение остатка числа a^x mod p:")

a = int(input("Введите число а: ")) # ввод чисел
x = int(input("Введите степень x: "))
p = int(input("Введите модуль p: "))

if (CheckPrime(p) == False): print("p не простое число.") # проверка, является ли модуль простым числом
elif (a % p == 0) and (x != 0): print("Теорема Ферма не выполняется: a^x ≡ 0 (mod p)") # проверка, выполняется ли теорема Ферма
else: # вывод результата
    result = algorithm(a, x, p)
    print(f"{a}^{x} mod {p} = {result}")