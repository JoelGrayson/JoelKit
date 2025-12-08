from joelkit.algorithms.partition import partition

lst = [5, 6, 4, 2, 8, 9]
print(lst)
partition(lst, 0, len(lst), 3)
print(lst)


lst = [2, 1, 3, 4, 6, 8, 7, 5]
print(lst[5])
print(lst)
partition(lst, 1, 8, 5)
# partition(lst, 0, len(lst), 5)
print(lst)


lst2 = [2, 1]
partition(lst2, 0, 2, 1)
print(lst2)


lst3 = [3, 2, 4, 1]
partition(lst3, 0, len(lst3), 3)
print(lst3)
