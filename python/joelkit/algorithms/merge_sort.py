def merge_sort(l):
    merge_sort_helper(l, 0, len(l))

def merge_sort_helper(l, start_i, end_i): #list and starting index and ending index. [start_i, end_i) - includes start_i and excludes end_i, just like a python range would
    range = end_i - start_i
    # Base case: already sorted
    if range == 0 or range == 1:
        return
    
    # Recursive step
    middle_i = (start_i + end_i) // 2
    merge_sort_helper(l, start_i, middle_i)
    merge_sort_helper(l, middle_i, end_i)
    merge(l, start_i, middle_i, end_i)


def merge(l, start_i, middle_i, end_i):
    merged = [] #out
    i1 = start_i
    i2 = middle_i
    while i1 < middle_i or i2 < end_i: #while there are still items to process
        if i1 == middle_i: #must process l2 because l1 already all processed
            merged.append(l[i2])
            i2 += 1
        elif i2 == end_i:
            merged.append(l[i1])
            i1 += 1
        else: #add that which is smaller
            if l[i1] <= l[i2]:
                merged.append(l[i1])
                i1 += 1
            else:
                merged.append(l[i2])
                i2 += 1

    for i in range(start_i, end_i):
        l[i] = merged[i - start_i]

