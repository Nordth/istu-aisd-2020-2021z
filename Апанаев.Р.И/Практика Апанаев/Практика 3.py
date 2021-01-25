
n = 6
a = [5.2, 4.146, 1.999, 2.4, 9.1, 8.3]
def sum_mass(mass, size):
    if (size == 0):
        return 0
    else:
        return mass[size - 1] + sum_mass(mass, size - 1)


print("Cписок элементов массива:")
print(a)
print("Сумма элементов массива равна:")
b = sum_mass(a, n)
print(b)