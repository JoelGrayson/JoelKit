from test_a_sorting_alg import test_a_sorting_alg
from joelkit.algorithms import quick_sorted
from plot_time_complexity import plot_time_complexity

l = [3, 6, 5, 4, 1, 8, 7, 2]
print(l)
print(quick_sorted(l))

test_a_sorting_alg(quick_sorted, inplace=False)

