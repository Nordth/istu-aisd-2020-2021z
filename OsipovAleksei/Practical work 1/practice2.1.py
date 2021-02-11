x = float(input("Первое число: "))
oper = (input("Операция: "))
y = float(input("Второе число: "))

def calc(a,  b, op):
    result = 0
    if op == "+":
        result = a+b
    if op == "-":
        result = a - b
    if op == "*":
        result = a * b
    if op == "/" and b == 0:
        print("Деление на ноль!")
    elif op == "/":
        result = a/b
    print("Результат:", end = " ")
    print(result)
calc(x, y, oper)
input()
