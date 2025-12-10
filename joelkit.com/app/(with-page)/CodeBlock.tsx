'use client';

import { useState } from 'react';

export default function CodeBlock({ children }: { children: string }) {
    const [copied, setCopied] = useState(false);

    const handleCopy = async () => {
        await navigator.clipboard.writeText(children);
        setCopied(true);
        setTimeout(() => setCopied(false), 2000);
    };

    return (
        <div className="inline-flex items-center gap-2 bg-gray-900 text-white px-4 py-2 rounded-lg font-mono text-sm relative group">
            <span className="select-all">{children}</span>
            <button
                onClick={handleCopy}
                className="ml-2 px-2 py-1 bg-gray-700 hover:bg-gray-600 rounded text-xs text-white transition-colors"
                aria-label="Copy to clipboard"
            >
                {copied ? '✓' : 'Copy'}
            </button>
        </div>
    );
}
