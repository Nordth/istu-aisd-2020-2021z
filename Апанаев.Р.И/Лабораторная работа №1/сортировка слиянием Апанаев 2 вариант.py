def mergeSort(mylist):
    if len(mylist)>1:
        i=0
        j=0
        k=0
        mid = len(mylist)//2
        left = mylist[:mid]
        right = mylist[mid:]
        mergeSort(left)
        mergeSort(right)
        while i<len(left) and j<len(right):
            if left[i]<right[j]:
                mylist[k]=left[i]
                i=i+1
            else:
                mylist[k]=right[j]
                j=j+1
            k=k+1
        while i<len(left):
            mylist[k]=left[i]
            i=i+1
            k=k+1

        while j<len(right):
            mylist[k]=right[j]
            j=j+1
            k=k+1
inp = int(input("Колличество элементов массива:"));
mylist =[]
for i in range (inp):
    new_element = int(input())
    mylist.append(new_element)
mergeSort(mylist)
print(mylist)
