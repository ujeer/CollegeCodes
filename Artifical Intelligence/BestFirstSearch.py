print("Best First Search")
from queue import PriorityQueue
v = 14
graph = [[] for _ in range(v)]
def best_first_search(actual_src, target, n):    # Function for implementing Best First Search
    visited = [False] * n
    pq = PriorityQueue()
    pq.put((0, actual_src))
    visited[actual_src] = True
    while not pq.empty():
        u = pq.get()[1]
        print(u, end=" ")                       # Displaying the path having lowest cost
        if u == target:
            break
        for v, c in graph[u]:
            if not visited[v]:
                visited[v] = True
                pq.put((c, v))
    print()

def addedge(x, y, cost):                   # Function for adding edges to the graph
    graph[x].append((y, cost))
    graph[y].append((x, cost))






addedge(0, 1, 3) # Adding edges to the graph
addedge(0, 2, 6)
addedge(0, 3, 5)
addedge(1, 4, 9)
addedge(1, 5, 8)
addedge(2, 6, 12)
addedge(2, 7, 14)
addedge(3, 8, 7)
addedge(8, 9, 5)
addedge(8, 10, 6)
addedge(9, 11, 1)
addedge(9, 12, 10)
addedge(9, 13, 2)

source = int(input("Enter the source node: ").strip())      # Asking user for source and target nodes
target = int(input("Enter the target node: ").strip())
if 0 <= source < v and 0 <= target < v: # Ensure the source and target are within the valid range
    print(f"\nPerforming Best First Search from {source} to {target}:")
    best_first_search(source, target, v)
else:
    print("Invalid node values. Please enter values between 0 and", v-1)
