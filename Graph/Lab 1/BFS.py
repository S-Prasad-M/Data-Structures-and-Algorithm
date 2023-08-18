from ds import Graph, Queue


def bfs(grph: Graph, vrt):

    if not grph.isVertice(vrt):
        return None

    numberofVertices = grph.numberOfVertices()
    q = Queue()
    q.enQueue(vrt)
    visited = []
    while len(visited) != numberofVertices:
        vrtx = q.deQueue()
        # print(vrtx,end="\t")
        visited.append(vrtx)
        neibours = grph.edgesOf(vrtx)
        # print(neibours, visited)
        for neibour in neibours:
            if not(neibour in visited) and not q.inQueue(neibour):
                q.enQueue(neibour)
            else:
                continue
        # q.display()
    return visited


G = Graph(graph={1: [2, 4], 2: [1, 3, 4, 5], , 4: [1, 2,5], 5:[2, 3, 4], 3: [2, 5]})
# # G = Graph()
# G.add_vertice(1)
# G.add_vertice(2)
# G.add_vertice(3)
# G.add_vertice(4)

# G.add_edge(1, 2)
# G.add_edge(1, 3)
# G.add_edge(4, 2)
# G.add_edge(4, 3)
# G.add_edge(4, 5)

G.Print_adjList()


bfs = bfs(G, 1)
print(bfs)