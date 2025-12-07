from joelkit.algorithms import insertion_sort, insertion_sorted
from test_a_sorting_alg import test_a_sorting_alg

arr = [8, 2, 4, 1, 3]
print(insertion_sorted(arr))
print([1, 2, 3, 4, 8])
print(arr)
insertion_sort(arr)
print(arr)

test_a_sorting_alg(insertion_sort)

