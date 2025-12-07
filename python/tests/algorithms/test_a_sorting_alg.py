def test_a_sorting_alg(f, inplace = True):
    lists = [
        ( [2, 4, 1, 3, -1, 0], [-1, 0, 1, 2, 3, 4] ),
        ( [-1, 1], [-1, 1] ),
        ( [10, 100, 2], [2, 10, 100] ),
    ]
    for unsorted, sorted in lists:
        try:
            if inplace:
                l = unsorted
                f(l)
                assert l == sorted
            else:
                assert f(l) == sorted
        except:
            print('Unable to sort', unsorted)
            print('It should be', sorted)
            print('But it returned', f(unsorted))
    
