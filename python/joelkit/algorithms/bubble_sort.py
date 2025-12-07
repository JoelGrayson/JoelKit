# Elements bubble their way to the right
# Topmost element bubbles to the last element
# Second-largest element bubbles to the second to last element
# ...
def bubble_sort(arr):
    for i in range(len(arr) - 1): #need -1 because j+1
        for j in range(0, len(arr) - 1 - i): #don't need to consider last i items because they are sorted (i largest items bubbled up)
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

