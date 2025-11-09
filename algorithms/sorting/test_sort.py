def test_sort(algorithm, in_place=False):
    print(f'Testing {algorithm.__name__}')
    lists_to_test = [
        [4, 2, 3, 1, 5],
        [9, 2, 4, 1, 11],
        [3, -1, 23, 2, 5],
    ]
    for lst in lists_to_test:
        print('Original:', lst)
        if in_place:
            algorithm(lst)
        else:
            lst = algorithm(lst)
        print('Sorted:', lst)

