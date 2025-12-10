export default function Toggle({ title, children }: { title: string; children: any }) {
    return <details>
        <summary className="cursor-pointer">
            {title}
        </summary>

        <div className="pl-8 py-3">
            {children}
        </div>
    </details>;
}

