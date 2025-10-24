from collections import deque
import heapq


HEURISTIC = {
    'A': 10, 'B': 8, 'D': 7, 'C': 5, 'E': 3,
    'F': 6, 'G': 5, 'H': 3, 'I': 1, 'J': 0
}


def dfs(graph, start_node, target_node):
    best = {'path': None, 'weight': float('inf')}
    def dfs(node, visited, path, weight):
        if weight >= best['weight']:
            return
        if node == target_node:
            best['path'] = list(path)
            best['weight'] = weight
            return
        for neighbor, w in graph.get(node, []):
            if neighbor not in visited:
                visited.add(neighbor)
                path.append(neighbor)
                dfs(neighbor, visited, path, weight + w)
                path.pop()
                visited.remove(neighbor)
    dfs(start_node, {start_node}, [start_node], 0)
    if best['path'] is None:
        return None, None
    return best['path'], best['weight']

def bfs(graph, start_node, target_node):
    queue = deque()
    queue.append((start_node, [start_node], 0))
    best_path = None
    best_weight = float('inf')
    while queue:
        node, path, weight = queue.popleft()
        if weight >= best_weight:
            continue
        if node == target_node:
            if weight < best_weight:
                best_weight = weight
                best_path = path
            continue
        for neighbor, w in graph.get(node, []):
            if neighbor not in path:
                queue.append((neighbor, path + [neighbor], weight + w))
    if best_path is None:
        return None, None
    return best_path, best_weight

def nearest_neighbor(graph, start_node, target_node):
    current = start_node
    visited = {current}
    path = [current]
    total = 0
    while current != target_node:
        candidates = [(w, neigh) for neigh, w in graph.get(current, []) if neigh not in visited]
        if not candidates:
            return None, None
        w, neigh = min(candidates, key=lambda x: x[0])
        path.append(neigh)
        total += w
        visited.add(neigh)
        current = neigh
    return path, total

def dfs_max_depth(graph, start_node, target_node, max_depth):
    best = {'path': None, 'weight': float('inf')}
    def dls(node, depth, visited, path, weight):
        if weight >= best['weight']:
            return
        if depth < 0:
            return
        if node == target_node:
            if weight < best['weight']:
                best['path'] = list(path)
                best['weight'] = weight
            return
        if depth == 0:
            return
        for neighbor, w in graph.get(node, []):
            if neighbor not in visited:
                visited.add(neighbor)
                path.append(neighbor)
                dls(neighbor, depth-1, visited, path, weight + w)
                path.pop()
                visited.remove(neighbor)
    for depth in range(max_depth + 1):
        dls(start_node, depth, {start_node}, [start_node], 0)
    if best['path'] is None:
        return None, None
    return best['path'], best['weight']

def best_first_search(graph, start_node, target_node, heuristic=HEURISTIC):
    pq = []
    heapq.heappush(pq, (heuristic.get(start_node, 0), start_node, [start_node], 0))
    visited_states = set()
    while pq:
        hval, node, path, g = heapq.heappop(pq)
        state = (node, tuple(path))
        if state in visited_states:
            continue
        visited_states.add(state)
        if node == target_node:
            return path, g
        for neigh, w in graph.get(node, []):
            if neigh not in path:
                heapq.heappush(pq, (heuristic.get(neigh, 0), neigh, path + [neigh], g + w))
    return None, None

def a_star(graph, start_node, target_node, heuristic=HEURISTIC):
    open_heap = []
    heapq.heappush(open_heap, (heuristic.get(start_node, 0), 0, start_node, [start_node]))  
    closed = {}
    while open_heap:
        f, g, node, path = heapq.heappop(open_heap)
        if node == target_node:
            return path, g
        if node in closed and closed[node] <= g:
            continue
        closed[node] = g
        for neigh, w in graph.get(node, []):
            if neigh in path:
                continue
            g2 = g + w
            f2 = g2 + heuristic.get(neigh, 0)
            heapq.heappush(open_heap, (f2, g2, neigh, path + [neigh]))
    return None, None

graph = {
    'A': [('B', 6), ('F', 3)],
    'B': [('D', 2), ('C', 3)],
    'C': [('D', 1),('E',5)],
    'D': [('E',8)],
    'E': [('I', 5),('J',5)],
    'F': [('G',1),('H',7)],
    'G' : [('I',3)],
    'H' : [('I',2)],
    'I' : [('J',3)],
    'J' : []
}

if __name__ == "__main__":
    start = 'A'
    target = 'J'

    path, w = dfs(graph, start, target)
    print("DFS:", path, w)

    path, w = bfs(graph, start, target)
    print("BFS:", path, w)

    path, w = nearest_neighbor(graph, start, target)
    print("Nearest neighbor:", path, w)

    path, w = dfs_max_depth(graph, start, target, max_depth=10)
    print("DFS MAX DEPTH = 10:", path, w)

    path, w = best_first_search(graph, start, target)
    print("Best first search:", path, w)

    path, w = a_star(graph, start, target)
    print("A*:", path, w)
