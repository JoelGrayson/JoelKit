import matplotlib.pyplot as plt
import time
import numpy as np

# Plots time complexity on functions that take in lists and perform some action to them like sorting
def plot_time_complexity(sorting_fn, upper_bound = 10_000, num_points = 15):
    xs = np.linspace(0, upper_bound, num_points).astype(int) #length of list
    ys = [None for _ in range(len(xs))] #ms it takes to sort a list of size x
    lists = list(map(lambda x : np.random.random(x), xs)) #create a list of random numbers of length x

    # Time test
    for i, l in enumerate(lists):
        start = time.time()
        sorting_fn(l)
        end = time.time()
        ys[i] = (end - start) * 1000

    plt.title(f'Time Complexity of {sorting_fn.__name__}')
    plt.plot(xs, ys)
    plt.xlabel('n (number of items in a list)')
    plt.ylabel(f'Time to run {sorting_fn.__name__} on a list of size n (ms)')
    plt.show()

