def sorted(arr):
    sorted_arr = [None for _ in range(len(arr))] #blank array
    for i, el in enumerate(arr): #insert el into sorted_arr in this iteration
        curr_i = i #i to insert el
        while curr_i > 0 and sorted_arr[curr_i - 1] > el:
            sorted_arr[curr_i] = sorted_arr[curr_i - 1] #move it right
            curr_i -= 1

        sorted_arr[curr_i] = el
    return sorted_arr


def sort(arr): #inline
    # first item already sorted
    for i in range(1, len(arr)):
        to_move = arr[i]
        curr_i = i
        while curr_i > 0 and arr[curr_i - 1] > to_move:
            arr[curr_i] = arr[curr_i - 1]
            curr_i -= 1
        arr[curr_i] = to_move


def test():
    arr = [8, 2, 4, 1, 3]
    print(sorted(arr))
    print([1, 2, 3, 4, 8])
    print(arr)
    sort(arr)
    print(arr)

if __name__ == '__main__':
    test()

