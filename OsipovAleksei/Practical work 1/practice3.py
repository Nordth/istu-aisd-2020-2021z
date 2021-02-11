#Разработайте рекурсивный алгоритм рассчета суммы элементов целочисленного массива
arr = [1, 5, 456, 43, 78, 867, 345]

def recurSum(arr, i=0):
    if i >= len(arr):
        return 0
    else:
        return arr[i] + recurSum(arr, i + 1)

print (recurSum(arr))