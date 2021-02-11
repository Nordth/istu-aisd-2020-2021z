arr = [0.5, 0.25, 0.1, 5.5, 3.5, 7.2]

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