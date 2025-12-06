Input: starting vertex s (Bacon himself)
Output: Explore all vertices. Also, have an L which tells you vertices by their bacon number. L[i] is a list of all vertices with bacon number i

L = [] #bacon numbers. L[2] is a list of all vertices with bacon number 2
mark all vertices as unexplored
mark s as explored
L[0] = [s]
i = 0
while there are unexplored vertices
    new_list = []
    for vertex in L[i]
        for neighbor in vertex
            if neighbor unexplored
                mark neighbor as explored
                new_list.add(neighbor)
    L[i + 1] = new_list
    i++


This is how we saw it in-lecture in CS 161

