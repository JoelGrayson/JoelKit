Input: starting vertex s
Output: Explore all vertices

mark all vertices as unexplored
q = Queue()
q.enqueue(s)
while q not empty
    node = q.dequeue()
    mark node as visited
    for neighbor of node
        if neighbor unexplored
            q.enqueue(neighbor)


This is how it was described in Algorithms Illuminated

