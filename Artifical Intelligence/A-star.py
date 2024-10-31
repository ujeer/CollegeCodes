print("A* Search Algorithm")
import heapq
class Node:
    def __init__(self, name, heuristic):
        self.name = name
        self.heuristic = heuristic
        self.g = float('inf')
        self.f = float('inf')
        self.parent = None

    def __lt__(self, other):
        return self.f < other.f

def a_star_search(graph, start, goal):
    start_node = Node(start, heuristic(graph, start, goal))
    goal_node = Node(goal, 0)
    open_list = []
    closed_list = set()

    heapq.heappush(open_list, start_node)

    while open_list:
        current_node = heapq.heappop(open_list)
        closed_list.add(current_node.name)

        if current_node.name == goal:
            path = []
            while current_node.parent:
                path.append(current_node.name)
                current_node = current_node.parent
            path.append(start)
            path.reverse()
            return path

        for neighbor, cost in graph[current_node.name].items():
            if neighbor not in closed_list:
                neighbor_node = Node(neighbor, heuristic(graph, neighbor, goal))
                neighbor_node.g = current_node.g + cost
                neighbor_node.f = neighbor_node.g + neighbor_node.heuristic
                neighbor_node.parent = current_node
                heapq.heappush(open_list, neighbor_node)

    return None

def heuristic(graph, node, goal):
    # Manhattan distance heuristic
    return abs(ord(node) - ord(goal))

# Example graph
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'D': 2, 'E': 5},
    'C': {'A': 4, 'F': 3},
    'D': {'B': 2},
    'E': {'B': 5, 'F': 1},
    'F': {'C': 3, 'E': 1}
}


start_node = input("Enter the starting node: ")
goal_node = input("Enter the goal node: ")

if start_node in graph and goal_node in graph:
    path = a_star_search(graph, start_node, goal_node)
    if path:
        print("Path:", " -> ".join(path))
    else:
        print("No path found")
else:
    print("Invalid node. Please enter a node that exists in the graph")


