from random import shuffle
from joelkit.algorithms import k_select
from plot_time_complexity import custom_plot_time_complexity

l2 = [ 1, 9, 5, 2, 2, 4, 6, 7 ] #[1, 2, 2, 4, 5, 6, 7, 9]
print(k_select(l2, 3), 4)

l3 = list(range(9000))
print(k_select(l3, 222))
shuffle(l3)
print(k_select(l3, 222))


custom_plot_time_complexity(lambda l, n : k_select(l, n // 3))

