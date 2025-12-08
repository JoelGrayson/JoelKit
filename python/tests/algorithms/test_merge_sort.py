from test_a_sorting_alg import test_a_sorting_alg
from joelkit.algorithms import merge_sorted, merge_sort
from plot_time_complexity import plot_time_complexity

l = [3, 6, 5, 4, 1, 8, 7, 2]
print(l)
print(merge_sorted(l))
merge_sort(l)
print(l)

test_a_sorting_alg(merge_sort, inplace=True)
test_a_sorting_alg(merge_sorted, inplace=False)


plot_time_complexity(merge_sorted)

