mass = [5.2, 4.146, 1.999, 2.4, 9.1, 8.3]
sum = 0.0
for i in mass:
    sum = sum+i
average_value = sum / len(mass)
for i in range(len(mass)):
    if mass[i] < average_value:
        mass[i] = 0
print (mass)
print(average_value)