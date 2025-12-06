def is_sorted(arr):
    p_el = None #previous element
    for el in arr:
        if p_el is not None:
            if p_el > el:
                return False

        p_el = el
    return True
        

def test():
    print('Testing is_sorted')
    assert is_sorted([1,2,3,4,5])
    assert is_sorted([-10, -3, 0, 1,5, 9999])
    assert not is_sorted([-3, 0, -10, 1,5, 9999])
    assert not is_sorted([5, 4, 3, 2, 1])
    assert is_sorted([])
    assert is_sorted([1])

if __name__ == '__main__':
    test()

