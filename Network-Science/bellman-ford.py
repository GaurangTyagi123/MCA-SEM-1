import networkx as nx
import matplotlib.pyplot as plt


def bellman_ford(G:nx.Graph,source):    
    V = len(G.nodes())
    dist = [float("inf")] * V
    dist[source] = 0
    edges = G.edges(data=True)
    for _ in range(V-1):
        for edge in edges:
            u,v,weight = edge
            weight = weight['weight']
            if dist[u] != float("inf") and dist[v] > dist[u] + weight:
                dist[v] = dist[u] + weight
    for edge in edges:
            u,v,weight = edge
            weight = weight['weight']
            
            if dist[u] != float("inf") and dist[v] > dist[u] + weight:
                print("Graph contains a negative edge cycle")
                return [-1]
    return dist

if (__name__ == "__main__"):
    G = nx.DiGraph()
    G.add_weighted_edges_from([[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]])
    
    pos = nx.spring_layout(G)
    edge_labels = nx.get_edge_attributes(G,'weight')

    nx.draw_networkx_nodes(G,pos,node_size=700)
    nx.draw_networkx_edge_labels(G,pos,edge_labels=edge_labels,font_size=10)
    nx.draw_networkx_edges(G,pos,edge_color="blue",width=2)
    nx.draw_networkx_labels(G,pos,font_size=12,font_weight="bold")
    
    plt.show()
    source = 1
    d = bellman_ford(G,source)
    for (index,distance) in enumerate(d):
        if(index != source):
            print(f"{source} - {index} = {distance}")
    