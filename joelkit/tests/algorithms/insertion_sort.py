from joelkit.algorithms import insertion_sort, insertion_sorted

def test():
    arr = [8, 2, 4, 1, 3]
    print(insertion_sorted(arr))
    print([1, 2, 3, 4, 8])
    print(arr)
    insertion_sort(arr)
    print(arr)

if __name__ == '__main__':
    test()

