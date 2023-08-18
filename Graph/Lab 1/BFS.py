from ds import Graph, Queue


def bfs(grph: Graph, vrt):
    """
    The algorithm works as follows:
        1. Start by putting any one of the graph's vertices at the back of a queue.
        2. Take the front item of the queue and add it to the visited list.
        3. Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the back of the queue.
        4. Keep repeating steps 2 and 3 until the queue is empty.
    """

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


G = Graph(graph={0: [1, 2, 3], 1: [0, 2], 2: [0, 4], 3: [1], 4: [2]})
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