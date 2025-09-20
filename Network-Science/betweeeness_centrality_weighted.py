import heapq
from collections import defaultdict

def betweenness_centrality_weighted(graph):
    """
    Compute betweenness centrality for all nodes in a weighted graph.
    :param graph: dict {node: [(neighbor, weight), ...]}
    :return: dict {node: betweenness_centrality}
    """
    betweenness = dict.fromkeys(graph, 0.0)

    for s in graph:
        # Initialization
        S = []   # stack
        P = {v: [] for v in graph}   # predecessors
        sigma = dict.fromkeys(graph, 0.0)  # num shortest paths
        dist = dict.fromkeys(graph, float('inf'))  # distances

        sigma[s] = 1.0
        dist[s] = 0.0

        # Priority queue for Dijkstra
        Q = [(0.0, s)]

        while Q:
            (d, v) = heapq.heappop(Q)
            if d > dist[v]:
                continue
            S.append(v)
            for w, weight in graph[v]:
                vw_dist = dist[v] + weight
                if dist[w] > vw_dist:   # found shorter path
                    dist[w] = vw_dist
                    heapq.heappush(Q, (dist[w], w))
                    sigma[w] = sigma[v]
                    P[w] = [v]
                elif dist[w] == vw_dist:  # another shortest path found
                    sigma[w] += sigma[v]
                    P[w].append(v)

        # Dependency accumulation
        delta = dict.fromkeys(graph, 0.0)
        while S:
            w = S.pop()
            for v in P[w]:
                delta_v = (sigma[v] / sigma[w]) * (1.0 + delta[w])
                delta[v] += delta_v
            if w != s:
                betweenness[w] += delta[w]

    # Normalize for undirected graphs
    for v in betweenness:
        betweenness[v] /= 2.0

    return betweenness


# Example Usage
if __name__ == "__main__":
    # Weighted graph as adjacency list
    graph = {
        0: [(1, 2), (2, 1)],
        1: [(0, 2), (2, 3), (3, 1)],
        2: [(0, 1), (1, 3), (3, 1)],
        3: [(1, 1), (2, 1), (4, 2)],
        4: [(3, 2)]
    }

    bc = betweenness_centrality_weighted(graph)
    print("Betweenness Centrality (Weighted Graph):")
    for node, value in bc.items():
        print(f"Node {node}: {value:.2f}")
