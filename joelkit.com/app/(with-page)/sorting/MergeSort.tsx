'use client';

import Yt from "@/components/Yt";
import videos from "../../videos";
import Toggle from "../Toggle";
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';
import { Switch } from "@/components/ui/switch";
import { useState } from "react";

export default function MergeSort() {
    const [inPlace, setInPlace] = useState(false);

    return <>
        <Toggle title="Merge Sort">
            <Yt>{videos.mergeSort}</Yt>

            <div className="flex items-center space-x-2 my-2">
                <Switch
                    id="in-place-toggle"
                    checked={inPlace}
                    onCheckedChange={setInPlace}
                />
                <label htmlFor="in-place-toggle">In Place</label>
            </div>

            <div>
                <h4>Python</h4>
                <SyntaxHighlighter language="python" style={oneDark}>
                    {inPlace ? mergeSortPy : mergeSortedPy}
                </SyntaxHighlighter>
            </div>
            <div>
                <h4>C++</h4>
                <SyntaxHighlighter language="cpp" style={oneDark}>
                    {inPlace ? mergeSortCpp : mergeSortedCpp}
                </SyntaxHighlighter>
            </div>
            
            <h3>Runtime</h3>
            <p>O(nlogn)</p>
        </Toggle>
    </>;
}

const mergeSortPy = `# from joelkit.algorithms import merge_sort

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
        l[i] = merged[i - start_i]`;

const mergeSortedPy = `# from joelkit.algorithms import merge_sort

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

    return merged`

const mergeSortCpp = `template <typename T>
std::vector<T> merge_sorted(const std::vector<T>& l) {
    if (l.size() == 0 || l.size() == 1)
        return l;
    
    int middle = l.size() / 2;
    std::vector<T> left(l.begin(), l.begin() + middle);
    std::vector<T> right(l.begin() + middle, l.end());
    std::vector<T> left_sorted = merge_sorted(left);
    std::vector<T> right_sorted = merge_sorted(right);
    return merge(left_sorted, right_sorted);
}

template <typename T>
std::vector<T> merge(const std::vector<T>& l1, const std::vector<T>& l2) {
    std::vector<T> merged(l1.size() + l2.size());
    auto merged_it = merged.begin();

    auto i1 = l1.begin();
    auto i2 = l2.begin();
    while (i1 != l1.end() || i2 != l2.end()) { //while there is still something to process
        if (i1 == l1.end()) { //must do l2
            *merged_it = *i2;
            merged_it++;
            i2++;
        } else if (i2 == l2.end()) { //must do l1
            *merged_it = *i1;
            merged_it++;
            i1++;
        } else {
            if (*i1 < *i2) {
                *merged_it = *i1;
                i1++;
                merged_it++;
            } else {
                *merged_it = *i2;
                i2++;
                merged_it++;
            }
        }
    }
    return merged;
}

template <typename T>
void merge_sort(std::vector<T>& l) {
    l = merge_sorted(l); //I'm too lazy. Fugheddaboudit
}`


const mergeSortedCpp = `template <typename T>
std::vector<T> merge_sorted(const std::vector<T>& l) {
    if (l.size() == 0 || l.size() == 1)
        return l;
    
    int middle = l.size() / 2;
    std::vector<T> left(l.begin(), l.begin() + middle);
    std::vector<T> right(l.begin() + middle, l.end());
    std::vector<T> left_sorted = merge_sorted(left);
    std::vector<T> right_sorted = merge_sorted(right);
    return merge(left_sorted, right_sorted);
}

template <typename T>
std::vector<T> merge(const std::vector<T>& l1, const std::vector<T>& l2) {
    std::vector<T> merged(l1.size() + l2.size());
    auto merged_it = merged.begin();

    auto i1 = l1.begin();
    auto i2 = l2.begin();
    while (i1 != l1.end() || i2 != l2.end()) { //while there is still something to process
        if (i1 == l1.end()) { //must do l2
            *merged_it = *i2;
            merged_it++;
            i2++;
        } else if (i2 == l2.end()) { //must do l1
            *merged_it = *i1;
            merged_it++;
            i1++;
        } else {
            if (*i1 < *i2) {
                *merged_it = *i1;
                i1++;
                merged_it++;
            } else {
                *merged_it = *i2;
                i2++;
                merged_it++;
            }
        }
    }
    return merged;
}`

