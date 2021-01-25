mass = [1, 6, 2, 5, 9, 8, 6, 5, 8, 6, 9, 6, 2, 4, 5, 6, 7, 8, 9, 2, 5, 0]
count = [0] * 10

for i in mass:
    count[i] += 1
print (count)
sorting = []
for i in range(len(count)):
    if count[i] > 0:
        for k in range(count[i]):
            sorting.append(i)

print (sorting)