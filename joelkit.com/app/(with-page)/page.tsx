import InsertionSort from "./InsertionSort";
import QuickSort from "./QuickSort";
import CodeBlock from "./CodeBlock";

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
        </ul>
        
    </div>;
}

