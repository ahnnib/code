import sys
sys.setrecursionlimit(131072)
input_data = sys.stdin.readline

n, m = map(int, input_data().split())

adj = {i: [] for i in range(n+1)}

for _ in range(m):
    u, v = map(int, input_data().split())
    adj[u].append(v)
    adj[v].append(u)

visited = [False] * (n + 1)

def dfs(u):
    visited[u] = True
    for child in adj[u]:
        if not visited[child]:
            dfs(child)

singles = []
for u in range(1, n + 1):
    if not visited[u]:
        dfs(u)
        singles.append(u)

# Prepare output
output = []
output.append(str(len(singles) - 1) + "\n")
for i in range(len(singles) - 1):
    output.append(f"{singles[i]} {singles[i+1]}\n")

# Write all output at once
sys.stdout.write("".join(output))

"""
\"\"\"Increasing recursion limit to avoid overflow.\"\"\"
import sys
sys.setrecursionlimit(131072)
n, m = map(int, input().split())

adj = {}
for i in range(n + 1):
    adj[i] = []

\"\"\"Obtaining graph information.\"\"\"
for i in range(m):
    u, v = map(int, input().split())

    \"\"\"Adding the nodes to adjacent list.\"\"\"

    adj[u].append(v)
    adj[v].append(u)

visited = [False] * (n + 1)
def dfs(u):
    \"\"\"Mark u as visited.\"\"\"
    visited[u] = True
    \"\"\"DFS to every adjacent nodes of node u.\"\"\"
    for child in adj[u]:
        if not visited[child]:
            dfs(child)

\"\"\"Stores nodes between which a road will be built.\"\"\"
singles = []
for u in range(1, n + 1):
    if not visited[u]:
        dfs(u)
        singles.append(u)

\"\"\"Output the answer.\"\"\"
print(len(singles) - 1)
for i in range(len(singles) - 1):
    print(singles[i], singles[i + 1])
"""