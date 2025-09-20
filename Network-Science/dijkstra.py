import networkx as nx
import matplotlib.pyplot as plt
import heapq as heap

def djikstra(G:nx.Graph,source:int):
    adjacency_list = dict(G.adjacency())
    dist = [10e8]*len(G.nodes())
    dist[source] = 0
    pq = []
    heap.heappush(pq,[source,dist[source]])
    
    while(pq):
        u = heap.heappop(pq)[0]
        for V in adjacency_list[u]:
            weight = adjacency_list[u][V]['weight']
            if dist[V] > dist[u] + weight:
                dist[V] = dist[u] + weight
                heap.heappush(pq,[V,dist[V]])
    
    return dist
    


if(__name__ == "__main__"):
    G = nx.Graph()
    G.add_weighted_edges_from([(0,1,4),(0,2,8),(1,4,6),(2,3,2),(3,4,10)])

    pos = nx.spring_layout(G)
    edge_labels = nx.get_edge_attributes(G,"weight")
    
    nx.draw_networkx_nodes(G, pos, node_size=700, node_color="lightblue")

    # Draw edges
    nx.draw_networkx_edges(G, pos, width=2)

    # Draw node labels
    nx.draw_networkx_labels(G, pos, font_size=12, font_weight="bold")
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10)
    
    plt.show()
    source = 0
    d = djikstra(G,source)
    for (index,distance) in enumerate(d):
        if(index != source):
            print(f"{source} - {index} = {distance}")