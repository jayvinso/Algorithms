#Author: Noor Imtiaz & Jayden Vinson  
import networkx as nx
import matplotlib.pyplot as plt
import random

def generate_random_weighted_graph(num_nodes, edge_probability):
    G = nx.gnp_random_graph(num_nodes, edge_probability)
    weight_range=(1, 10)
    
    # Assign a random positive weight to each edge from weight_range
    for u, v in G.edges():
        G[u][v]['weight'] = random.randint(weight_range[0], weight_range[1])
    
    return G

"""
 1  function Dijkstra(Graph, source):
 2     
 3      for each vertex v in Graph.Vertices:
 4          dist[v] ← INFINITY
 5          prev[v] ← UNDEFINED
 6          add v to Q
 7      dist[source] ← 0
 8     
 9      while Q is not empty:
10          u ← vertex in Q with minimum dist[u]
11          remove u from Q
12         
13          for each neighbor v of u still in Q:
14              alt ← dist[u] + Graph.Edges(u, v)
15              if alt < dist[v]:
16                  dist[v] ← alt
17                  prev[v] ← u
18
19      return dist[], prev[]
"""
#PSEUDO CODE ABOVE FOR MY ALGORITHIM. 
#STOLEN FROM WIKI. CODE FOLLOWS THIS TO A TEA

def dijkstra_shortest_path(G, target):
    dist = {v: float('inf') for v in G.nodes()}
    prev = {v: None for v in G.nodes()}
    source = 0
    Q = set(G.nodes())
    dist[source] = 0

    #main loop
    while Q:
        u = min(Q, key=lambda v: dist[v])
        Q.remove(u)
        for v in G.neighbors(u):
            if v in Q:
                alt = dist[u] + G[u][v]['weight']    
                if alt < dist[v]:                    
                    dist[v] = alt                    
                    prev[v] = u                     
    if dist[target] == float('inf'):
        return None, None

    path = []
    u = target
    while u is not None:
        path.insert(0, u)
        u = prev[u]

    return path, dist[target]


def visualize_dijkstra(G, path):
    pos = nx.spring_layout(G)  
    
    plt.figure(figsize=(10, 8))
    
    # Draw all nodes and edges.
    nx.draw_networkx_nodes(G, pos, node_color='lightblue', node_size=500)
    nx.draw_networkx_edges(G, pos, edge_color='gray')
    nx.draw_networkx_labels(G, pos, font_size=10, font_color='black')
    
    # Display edge weight labels for every edge in the graph.
    all_edge_labels = {(u, v): G[u][v]['weight'] for u, v in G.edges()}
    nx.draw_networkx_edge_labels(G, pos, edge_labels=all_edge_labels, font_color='black')
    
    # If a shortest path exists, highlight its edges in red.
    if path is not None:
        path_edges = list(zip(path, path[1:]))
        nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color='red', width=3)
    
    plt.title("Graph")
    plt.axis('off')
    plt.show()


# Get user input and convert to proper types.
num_nodes = int(input("How many nodes would you like? "))
edge_prob = float(input("What edge probability (0 to 1)? "))

# Create the graph.
graph = generate_random_weighted_graph(num_nodes, edge_prob)

# Define source and target nodes.
target_node = num_nodes - 1  

# Compute the shortest path 
path, distance = dijkstra_shortest_path(graph, target_node)

if path is not None:
    print(f"Shortest path from 0 to {target_node}: {path}")
    print(f"Total distance: {distance}")
else:
    print(f"No path found between 0 and {target_node}.")

# display the graph 
visualize_dijkstra(graph, path)
