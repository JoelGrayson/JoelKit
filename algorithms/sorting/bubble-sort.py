def bubble_sort(lst):
    for i in range(len(lst) - 1):
        for j in range(i - 1, 0, -1):
            if lst[j] < lst[i]:
                curr = lst[i]
                lst[i] = lst[j]
                lst[j] = curr


    # for i in range(len(lst) - 1):
    #     if lst[i] > lst[i + 1]:
    #         curr = lst[i]
    #         lst[i] = lst[i + 1]
    #         lst[i + 1] = curr

lst = [2, 3, 7, 4, 1, 6, 5, 8]
print(lst)
bubble_sort(lst)
print(lst)
