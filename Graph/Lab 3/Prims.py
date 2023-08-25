def prims(graph):
    assert type(graph)==dict

    nodes = graph.keys()   
    visited = set()
    path = []
    next = None

    while len(visited) < len(nodes):
        distance = float('inf') 
        for s in nodes:
            for d in nodes:
                if s in visited and d in visited or s == d:
                    continue
                if graph[s][d] < distance:
                    distance = graph[s][d]
                    pre = s
                    next = d

        path.append((pre, next))
        visited.add(pre)
        visited.add(next)

    return path


if __name__ == '__main__':
    graph_dict = #Graph input
    path = prims(graph_dict)
    print path