from test_a_sorting_alg import test_a_sorting_alg
from joelkit.algorithms import bubble_sort
from plot_time_complexity import plot_time_complexity

l = [3, 6, 5, 4, 1, 8, 7, 2]
print(l)
bubble_sort(l)
print(l)

test_a_sorting_alg(bubble_sort)

plot_time_complexity(bubble_sort, upper_bound=10_000, num_points=15)

