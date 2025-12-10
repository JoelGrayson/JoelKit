import matplotlib.pyplot as plt
import time
import numpy as np

# Plots time complexity on functions that take in lists and perform some action to them like sorting
def custom_plot_time_complexity(f, upper_bound = 10_000, num_points = 15, name = 'function'):
    xs = np.linspace(0, upper_bound, num_points).astype(int) #length of list
    ys = [None for _ in range(len(xs))] #ms it takes to sort a list of size x
    lists = list(map(lambda x : np.random.random(x), xs)) #create a list of random numbers of length x

    # Time test
    for i, l in enumerate(lists):
        n = len(l)
        start = time.time()
        f(l, n)
        end = time.time()
        ys[i] = (end - start) * 1000

    plt.title(f'Time Complexity of {name}')
    plt.plot(xs, ys)
    plt.xlabel('n (number of items in a list)')
    plt.ylabel(f'Time to run {name} on a list of size n (ms)')
    plt.show()

def plot_time_complexity(sorting_fn, upper_bound = 10_000, num_points = 15):
    custom_plot_time_complexity(lambda l, n : sorting_fn(l), upper_bound=upper_bound, num_points=num_points, name=sorting_fn.__name__)

