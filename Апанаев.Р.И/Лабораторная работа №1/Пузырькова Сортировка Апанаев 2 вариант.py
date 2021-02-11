print("Введите колличество элементов")
N=int(input())
print("Вводите элементы через пробел")
s=input()
a=[]
s=s.split(" ")
for i in range(N):
    a.append(int(s[i]))
print("Изначальный массив",a)
print("Соритровка массива:") 
for i in range(N-1):
    for j in range(N-i-1):
        if a[j] > a[j+1]:
            a[j], a[j+1] = a[j+1], a[j]
    print(a)

print("Отсортированный массив:") 
print(a)