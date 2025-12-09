def insertion_sorted(arr):
    sorted_arr = [None for _ in range(len(arr))] #blank array
    for i, el in enumerate(arr): #insert el into sorted_arr in this iteration
        curr_i = i #i to insert el
        while curr_i > 0 and sorted_arr[curr_i - 1] > el:
            sorted_arr[curr_i] = sorted_arr[curr_i - 1] #move it right
            curr_i -= 1

        sorted_arr[curr_i] = el
    return sorted_arr


def insertion_sort(arr): #in place
    for i in range(1, len(arr)): #first item already sorted
        to_move = arr[i]
        curr_i = i
        while curr_i > 0 and arr[curr_i - 1] > to_move:
            arr[curr_i] = arr[curr_i - 1] #nudge item to the right
            curr_i -= 1
        arr[curr_i] = to_move

