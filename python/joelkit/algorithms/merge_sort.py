def merge_sorted(l):
    # Base case: already sorted
    if len(l) == 0 or len(l) == 1:
        return l
    
    # Recursive step
    middle = len(l) // 2
    left = l[0:middle]
    right = l[middle:]
    left_sorted = merge_sorted(left)
    right_sorted = merge_sorted(right)
    return merge(left_sorted, right_sorted)


def merge(l1, l2):
    merged = [] #out
    i1 = 0 #index on l1
    i2 = 0
    while i1 < len(l1) or i2 < len(l2): #while there are still items to process
        if i1 == len(l1): #must process l2 because l1 already all processed
            merged.append(l2[i2])
            i2 += 1
        elif i2 == len(l2):
            merged.append(l1[i1])
            i1 += 1
        else: #add that which is smaller
            if l1[i1] <= l2[i2]:
                merged.append(l1[i1])
                i1 += 1
            else:
                merged.append(l2[i2])
                i2 += 1

    return merged

