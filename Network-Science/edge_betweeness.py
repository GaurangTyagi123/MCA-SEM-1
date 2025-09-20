from collections import defaultdict, deque

def edge_betweenness_centrality(graph):
    """
    Calculate edge betweenness centrality without using built-in functions.
    graph: dict adjacency list, e.g. {0:[1,2], 1:[0,2], 2:[0,1,3], 3:[2]}
    returns: dict with edge tuple as key and betweenness as value
    """
    betweenness = defaultdict(float)

    for s in graph:
        # Single-source shortest-paths problem
        stack = []
        pred = defaultdict(list)
        sigma = dict.fromkeys(graph, 0.0)  # number of shortest paths
        dist = dict.fromkeys(graph, -1)    # distance from source

        sigma[s] = 1.0
        dist[s] = 0
        queue = deque([s])

        while queue:
            v = queue.popleft()
            stack.append(v)
            for w in graph[v]:
                if dist[w] < 0:  # found for first time
                    dist[w] = dist[v] + 1
                    queue.append(w)
                if dist[w] == dist[v] + 1:  # shortest path to w via v
                    sigma[w] += sigma[v]
                    pred[w].append(v)

        # Accumulation
        delta = dict.fromkeys(graph, 0.0)
        while stack:
            w = stack.pop()
            for v in pred[w]:
                c = (sigma[v] / sigma[w]) * (1 + delta[w])
                edge = tuple(sorted((v, w)))
                betweenness[edge] += c
                delta[v] += c

    # For undirected graphs, divide by 2
    for edge in betweenness:
        betweenness[edge] /= 2.0

    return dict(betweenness)

# Example usage
graph = {
    0: [1, 2],
    1: [0, 2],
    2: [0, 1, 3],
    3: [2]
}

print(edge_betweenness_centrality(graph))
