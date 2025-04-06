print("Breadth First Search")
from collections import deque

graph = {     # Define the graph
    'A': ['B', 'D', 'E'],
    'B': ['C'],
    'C': [],
    'D': [],
    'E': ['F'],
    'F': ['G', 'H'],
    'G': [],
    'H': [],
}

def bfs_tree(graph, start):
    visited = []
    queue = deque([start])
    parent = {start: None}
    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.append(node)
            print(node, end=" ")
            for neighbour in graph[node]:
                if neighbour not in visited:
                    queue.append(neighbour)
                    parent[neighbour] = node
    return parent

def print_tree(parent, root):
    print("\nTree structure:")
    for node in parent:
        if parent[node] is not None:
            print(f"{parent[node]} -> {node}")

def main():
    root_node = input("Enter the root node: ")
    goal_node = input("Enter the goal node: ")
    print("Following is the Breadth-First Search")
    parent = bfs_tree(graph, root_node)
    print_tree(parent, root_node)
    
    # Additional logic to find the path from root to goal
    path = []
    current_node = goal_node
    while current_node is not None:
        path.append(current_node)
        current_node = parent.get(current_node)
    path.reverse()
    print("Path from root to goal:", path)

if __name__ == "__main__":
    main()
