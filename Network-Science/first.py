import networkx as nx
import matplotlib.pyplot as plt
import tkinter as tk

# Basic graph constructors
G = nx.DiGraph()
G = nx.MultiGraph()
G = nx.MultiDiGraph()
G = nx.Graph()

# G.add_edge(1,2)
# G.add_edge(2,3,weight=0.9)
# G.add_edge("A","B")
# G.add_node("C")
# G.add_node(print)

# edge_list = [(1,2),(2,3),(3,4),(3,5),(4,6),(6,7),(3,7)]
# G.add_edges_from(edge_list)

# print(nx.adjacency_matrix(G))
# print(dict(G.degree)[1]) # degree of node-1
# print(nx.shortest_path(G,7,1))
# print(nx.degree_centrality(G))

G1 = nx.complete_graph(5)
G2 = nx.complete_graph(5)
G2 = nx.relabel_nodes(G2,{0:"A",1:"B",2:"C",3:"D",4:"E"})
G_connector = nx.from_edgelist(([4,"X"],["X","A"]))

G = nx.compose_all([G1,G2,G_connector])
print(nx.degree_centrality(G))
print(nx.density(G)*100)
print(nx.diameter(G))
print(list(nx.find_cliques(G)))
print(list(nx.bridges(G)))

nx.draw_spring(G,with_labels=True)
plt.show()
