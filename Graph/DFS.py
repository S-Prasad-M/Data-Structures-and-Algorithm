def dfs(graph, node, visited):
    if node not in visited:
        visited.append(node)
        for k in graph[node]:
            dfs(graph,k, visited)
    return visited

graph = {1: [2, 4], 2: [1, 3, 4, 5], 3: [2, 5], 4: [1, 2,5], 5:[2, 3, 4]}   # Input Graph as dictionary here
n = int(input())
for i in range(1,n+1):
    print("Enter Adjacent vertices of ",i,"as list:")
    graph[i] = eval(input())
visited = dfs(graph,1, [])
print(visited)
