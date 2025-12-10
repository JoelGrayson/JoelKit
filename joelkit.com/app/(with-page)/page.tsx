import InsertionSort from "./sorting/InsertionSort";
import QuickSort from "./sorting/QuickSort";
import CodeBlock from "./CodeBlock";
import MergeSort from "./sorting/MergeSort";
import BubbleSort from "./sorting/BubbleSort";
import KSelect from "./other/KSelect";
import Partition from "./other/Partition";
import Stack from "./data-structures/Stack";
import Queue from "./data-structures/Queue";
import LinkedList from "./data-structures/LinkedList";
import BST from "./data-structures/BST";

export default function Home() {
    return <div className="max-w-[800px] mx-auto mt-8">
        <h1 className="text-center">JoelKit</h1>
        <div>To use JoelKit in Python, run <CodeBlock>pip install joelkit</CodeBlock></div>
        <div>To use the C++ code, copy the header and source files into your project and #include</div>
        
        <h2>Algorithms</h2>
        <h3>Sorting</h3>
        <ul className="styled">
            <InsertionSort />
            <QuickSort />
            <MergeSort />
            <BubbleSort />
        </ul>
        
        <h3>Other</h3>
        <KSelect />
        <Partition />
        
        <h2>Data Structures</h2>
        <ul>
            <Stack />
            <Queue />
            <LinkedList />
            <BST />
        </ul>
        
    </div>;
}

