'use client';

import Yt from "@/components/Yt";
import videos from "../videos";
import Toggle from "./Toggle";
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';
import { Switch } from "@/components/ui/switch";
import { useState } from "react";

export default function InsertionSort() {
    const [inPlace, setInPlace] = useState(true);

    return <>
        <Toggle title="Insertion Sort">
            <Yt>{videos.insertionSort}</Yt>

            <div className="flex items-center space-x-2 my-2">
                <Switch
                    id="in-place-toggle"
                    checked={inPlace}
                    onCheckedChange={setInPlace}
                />
                <label htmlFor="in-place-toggle">In Place</label>
            </div>

            <div className="sm:grid sm:grid-cols-2 gap-4">
                <div>
                    <h4>Python</h4>
                    <SyntaxHighlighter language="python" style={oneDark}>
                        {inPlace ? insertionSortPythonInPlace : insertionSortPython}
                    </SyntaxHighlighter>
                </div>
                <div>
                    <h4>C++</h4>
                    <SyntaxHighlighter language="cpp" style={oneDark}>
                        {inPlace ? insertionSortCppInPlace : insertionSortCpp}
                    </SyntaxHighlighter>
                </div>
            </div>
            
            <h3>Runtime</h3>
            <p>Best case: O(n)</p>
            <p>Worst case: O(n<sup>2</sup>)</p>
        </Toggle>
    </>;
}

const insertionSortPythonInPlace = `# from joelkit.algorithms import insertion_sort

def insertion_sort(arr): #in place
    for i in range(1, len(arr)): #first item already sorted
        to_move = arr[i]
        curr_i = i
        while curr_i > 0 and arr[curr_i - 1] > to_move:
            arr[curr_i] = arr[curr_i - 1] #nudge item to the right
            curr_i -= 1
        arr[curr_i] = to_move`;

const insertionSortCppInPlace = `template <typename T>
void insertion_sort(std::vector<T>& v) {
    for (int i = 1; i < v.size(); i++) {
        T el = v[i]; //element to insert
        int curr_i = i;
        while (curr_i > 0 && v[curr_i - 1] > el) {
            v[curr_i] = v[curr_i - 1];
            curr_i--;
        }
        v[curr_i] = el;
    }
}`;


const insertionSortPython = `# from joelkit.algorithms import insertion_sorted

def insertion_sorted(arr):
    sorted_arr = [None for _ in range(len(arr))] #blank array
    for i, el in enumerate(arr): #insert el into sorted_arr in this iteration
        curr_i = i #i to insert el
        while curr_i > 0 and sorted_arr[curr_i - 1] > el:
            sorted_arr[curr_i] = sorted_arr[curr_i - 1] #move it right
            curr_i -= 1

        sorted_arr[curr_i] = el
    return sorted_arr`;

const insertionSortCpp = `template <typename T>
std::vector<T> insertion_sorted(const std::vector<T>& v) {
    std::vector<T> sorted_list(v.size());
    for (int i = 0; i < v.size(); i++) {
        T el = v[i]; //element to insert
        int curr_i = i;
        while (curr_i > 0 && sorted_list[curr_i - 1] > el) {
            sorted_list[curr_i] = sorted_list[curr_i - 1];
            curr_i--;
        }
        sorted_list[curr_i] = el;
    }
    return sorted_list;
}`;



