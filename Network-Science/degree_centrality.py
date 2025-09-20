import networkx as nx
import matplotlib.pyplot as plt

def degree_centrality(G:nx.Graph) ->set:
    length = 1/(len(G) - 1)
    centrality = {n : d*length for n,d in G.degree()}
    return centrality

G = nx.Graph()
G.add_edges_from([(1,2),(1,3),(2,4),(2,3)])

centrality:set = degree_centrality(G)

nx.draw_spring(G,with_labels=True)
plt.show()