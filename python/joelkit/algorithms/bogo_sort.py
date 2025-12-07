import random
from .is_sorted import is_sorted

def bogo_sort(arr):
    while True:
        random.shuffle(arr)
        if is_sorted(arr):
            return arr


def test():
    print(bogo_sort([2, 4, 1, 5, 3]))


if __name__ == '__main__':
    test()

