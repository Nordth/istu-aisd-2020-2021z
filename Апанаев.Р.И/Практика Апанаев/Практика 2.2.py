arr = [5.2, 4.146, 1.999, 2.4, 9.1, 8.3]

def reverse(arr, n):
    i=0
    while i < n/2:
        t = arr[i]
        arr[i] = arr[n - i - 1]
        arr[n - i - 1] = t
        i = i + 1
len = len(arr)
reverse(arr, len)
print(arr)