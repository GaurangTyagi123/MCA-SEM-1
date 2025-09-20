from collections import deque
import networkx as nx

def betweenness_centrality(graph):
    """
    Compute betweenness centrality for all nodes in an unweighted graph.
    :param graph: dict {node: [neighbors]}
    :return: dict {node: betweenness_centrality}
    """
    betweenness = dict.fromkeys(graph, 0.0)  # initialize betweenness to 0
    
    for s in graph:  
        # Step 1: BFS from source node s
        stack = []  
        pred = {w: [] for w in graph}  # list of predecessors
        sigma = dict.fromkeys(graph, 0.0)  # number of shortest paths
        dist = dict.fromkeys(graph, -1)    # distance from s

        sigma[s] = 1.0
        dist[s] = 0
        queue = deque([s])
        
        while queue:
            v = queue.popleft()
            stack.append(v)
            for w in graph[v]:
                # found for the first time?
                if dist[w] < 0:
                    queue.append(w)
                    dist[w] = dist[v] + 1
                # shortest path to w via v?
                if dist[w] == dist[v] + 1:
                    sigma[w] += sigma[v]
                    pred[w].append(v)

        # Step 2: Accumulate dependencies
        delta = dict.fromkeys(graph, 0.0)
        while stack:
            w = stack.pop()
            for v in pred[w]:
                delta_v = (sigma[v] / sigma[w]) * (1 + delta[w])
                delta[v] += delta_v
            if w != s:
                betweenness[w] += delta[w]
    # Step 3: Normalize (for undirected graphs)
    for v in betweenness:
        betweenness[v] /= 2.0
    
    return betweenness


# Example Usage
if __name__ == "__main__":
    # Graph as adjacency list
    graph = {
        0: [1, 2],
        1: [0, 2, 3],
        2: [0, 1, 3],
        3: [1, 2, 4],
        4: [3]
    }
    G = nx.Graph(graph)

    bc = betweenness_centrality(G)
    print("Betweenness Centrality:")
    for node, value in bc.items():
        print(f"Node {node}: {value:.2f}")
