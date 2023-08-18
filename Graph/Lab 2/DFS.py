def dfs(graph, node, visited):
    if node not in visited:
        visited.append(node)
        for k in graph[node]:
            dfs(graph,k, visited)
    return visited

graph = {}   #Input Graph as dictionary here
visited = dfs(graph,'A', [])
print(visited)