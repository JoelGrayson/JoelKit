def insertion_sort(arr): #TODO: make inline
    sorted_arr = [None for _ in range(len(arr))] #blank array
    for i, el in enumerate(arr): #insert el into sorted_arr in this iteration
        curr_i = i #i to insert el
        while curr_i > 0:
            if sorted_arr[curr_i - 1] > el:
                sorted_arr[curr_i] = sorted_arr[curr_i - 1] #move it right
            else: #found spot to insert
                break
            curr_i -= 1

        sorted_arr[curr_i] = el
    return sorted_arr


def test():
    arr = [8,2,4,1,3]
    print(insertion_sort(arr))
    print([1, 2, 3, 4, 8])

test()
