from collections import deque

def closeness_centrality(graph):
    """
    Calculate closeness centrality without built-in functions.
    graph: dict adjacency list, e.g. {0:[1,2], 1:[0,2], 2:[0,1,3], 3:[2]}
    returns: dict with node as key and closeness centrality as value
    """
    closeness = {}
    N = len(graph)

    for node in graph:
        # BFS to compute shortest paths
        dist = {n: -1 for n in graph}
        dist[node] = 0
        queue = deque([node])

        while queue:
            v = queue.popleft()
            for w in graph[v]:
                if dist[w] == -1:  # not visited
                    dist[w] = dist[v] + 1
                    queue.append(w)

        # Sum of shortest path lengths
        total_dist = sum(d for d in dist.values() if d > 0)

        if total_dist > 0:
            closeness[node] = (N - 1) / total_dist
        else:
            closeness[node] = 0.0  # isolated node

    return closeness

# Example usage
graph = {
    0: [1, 2],
    1: [0, 2],
    2: [0, 1, 3],
    3: [2]
}

print(closeness_centrality(graph))
