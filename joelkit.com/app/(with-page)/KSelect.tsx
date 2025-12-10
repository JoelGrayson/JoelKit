import Yt from "@/components/Yt";
import videos from "../videos";
import Toggle from "./Toggle";
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';

export default function KSelect() {
    return <>
        <Toggle title="K-Select">
            <Yt>{videos.kSelect}</Yt>

            <p>k-select(list, k) - find the kth-smallest element of the list in O(n) time</p>

            <div>
                <h4>Python</h4>
                <SyntaxHighlighter language="python" style={oneDark}>
                    {kSelectPy}
                </SyntaxHighlighter>
            </div>
            <div>
                <h4>C++</h4>
                <SyntaxHighlighter language="cpp" style={oneDark}>
                    {kSelectCpp}
                </SyntaxHighlighter>
            </div>
        </Toggle>
    </>;
}

const kSelectPy = `def find_pivot(lst):
    medians = []
    for i in range(0, len(lst), 5):
        five = []
        for j in range(i, i + 5):
            if j >= len(lst):
                break
            five.append((j, lst[j]))
        five.sort(key=lambda x : x[1])
        median = five[len(five) // 2]
        medians.append(median)
    return sorted(medians, key=lambda x : x[1])[len(medians) // 2]
    # return k_select(medians, len(medians) // 2)


def k_select(lst, k):
    if k > len(lst) or len(lst) == 0: #not possible (check)
        return None
    if len(lst) < 10:
        return sorted(lst)[k]
    
    pivot_index, pivot_value = find_pivot(lst)
    
    # Partition
    left = []
    right = []
    for i, item in enumerate(lst):
        if i == pivot_index:
            continue
        if item <= pivot_value:
            left.append(item)
        else:
            right.append(item)
    
    # Recursion
    if k == len(left): #is the pivot
        return pivot_value
    if k < len(left):
        return k_select(left, k)
    else:
        return k_select(right, k - len(left) - 1)`

const kSelectCpp = `template <typename T>
using IndexAndValue = std::pair<int, T>;

/** Finds median of medians. @returns its index in the passed-in list as well as its value */
template <typename T, typename KeyFunc>
IndexAndValue<T> find_pivot(std::vector<T> list, KeyFunc key) {
    std::vector<IndexAndValue<T>> medians;
    for (int i = 0; i < list.size(); i += 5) {
        std::vector<IndexAndValue<T>> five;
        for (int j = i; j < list.size() && j < i + 5; j++) {
            five.push_back(
                std::make_pair(j, list[j])
            );
        }
        insertion_sort(five, [&key](IndexAndValue<T> item) { return key(item.second); }); //insertion sort is nice on small lists
        IndexAndValue<T> median = five[five.size() / 2]; //do this instead of [2] in the case that |five|<5
        medians.push_back(median);
    }
    insertion_sort(medians, [](IndexAndValue<T> item) { return item.second; });
    IndexAndValue<T> median_of_medians = medians[medians.size() / 2];
    // IndexAndValue<T> median_of_medians = k_select(medians, medians.size() / 2, [&key](IndexAndValue<T> el) {
    //     return key(el.second);
    // });
    return median_of_medians;
}

template <typename T, typename KeyFunc>
T k_select(std::vector<T> list, int k, KeyFunc key) {
    if (list.size() < 50) //base case
        return insertion_sorted(list, key)[k];
    
    
    IndexAndValue<T> pivot = find_pivot(list, key);

    // Partition
    std::vector<T> left;
    std::vector<T> right;
    for (int i = 0; i < list.size(); i++) {
        T item = list[i];
        if (i == pivot.first) //skip the pivot. It is neither in left nor right
            continue;
        if (key(item) <= key(pivot.second))
            left.push_back(item);
        else
            right.push_back(item);
    }
    
    // Recursive step
    if (k == left.size()) //is pivot
        return pivot.second;
    else if (k < left.size())
        return k_select(left, k, key);
    else
        return k_select(right, k - left.size() - 1, key); //takes out the left and the pivot
}

template <typename T>
T k_select(std::vector<T> list, int k) {
    return k_select(list, k, [](T el) { return el; }); //use the self selector
}`;

