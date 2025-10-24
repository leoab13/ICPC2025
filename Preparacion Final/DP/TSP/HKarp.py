import math

# Example distances between cities (cost matrix)
distances = [
    # Santiago de Querétaro
    [0, 53, 62, 21, 186, 62, 72, 31, 21, 27, 15, 144, 14, 143, 136],
    # San Juan del Rio
    [53, 0, 21, 72, 181, 37, 49, 72, 73, 64, 66, 138, 66, 137, 135],
    # Tequisquiapan
    [62, 20, 0, 76, 162, 18, 30, 76, 82, 56, 75, 118, 75, 118, 116],
    # Santa Rosa Jauregui
    [21, 73, 81, 0, 206, 81, 92, 12, 8, 25, 24, 124, 34, 124, 117],
    # Jalpan de Serra
    [186, 178, 159, 199, 0, 142, 137, 199, 206, 180, 199, 107, 199, 107, 105],
    # Ezequiel Montes
    [62, 36, 17, 76, 145, 0, 13, 76, 82, 57, 75, 102, 75, 101, 99],
    # Cadereyta de Montes
    [72, 49, 30, 86, 137, 13, 0, 86, 92, 67, 85, 94, 85, 93, 91],
    # Parque Industrial Queretaro
    [31, 73, 81, 13, 205, 81, 92, 0, 23, 20, 35, 114, 43, 113, 107],
    # Cumbres del Lago
    [21, 72, 80, 10, 204, 80, 91, 19, 0, 32, 19, 131, 28, 130, 124],
    # San Miguel
    [27, 64, 57, 23, 181, 57, 68, 20, 30, 0, 34, 141, 43, 140, 133],
    # Viñedos
    [15, 67, 75, 21, 200, 75, 86, 34, 18, 35, 0, 147, 12, 146, 139],
    # Loma Blanca
    [144, 135, 116, 124, 107, 99, 94, 117, 134, 142, 146, 0, 154, 3, 6],
    # El Romeral
    [14, 69, 77, 34, 201, 77, 88, 42, 27, 43, 12, 155, 0, 154, 148],
    # La Cuesta de los Ibarra
    [143, 134, 115, 123, 107, 98, 93, 116, 133, 141, 145, 3, 153, 0, 5],
    # La Tecozautla
    [136, 132, 113, 116, 105, 96, 91, 109, 126, 134, 138, 6, 147, 5, 0],
]

n = len(distances)  # Number of cities
dp = [[math.inf] * n for _ in range(1 << n)]
parent = [[None] * n for _ in range(1 << n)]

# Base case: starting from city 0
dp[1][0] = 0

# Fill DP table
for mask in range(1 << n):
    for last in range(n):
        if not (mask & (1 << last)):
            continue
        for next in range(n):
            if mask & (1 << next):
                continue
            new_mask = mask | (1 << next)
            new_dist = dp[mask][last] + distances[last][next]
            if new_dist < dp[new_mask][next]:
                dp[new_mask][next] = new_dist
                parent[new_mask][next] = last

# Find the optimal tour and minimum cost
min_cost = math.inf
end_city = None
full_mask = (1 << n) - 1
for last in range(1, n):
    cost = dp[full_mask][last] + distances[last][0]
    if cost < min_cost:
        min_cost = cost
        end_city = last

# Reconstruct the optimal tour
tour = []
mask = full_mask
last = end_city
while mask:
    tour.append(last)
    new_last = parent[mask][last]
    mask ^= (1 << last)
    last = new_last
tour = tour[::-1]
tour.append(0)  # Add the starting city at the end to complete the loop

cities = ['Santiago de Querétaro', 'San Juan del Rio', 'Tequisquiapan', 'Santa Rosa Jauregui','Jalpan de Serra', 'Ezequiel Montes', 'Cadereyta de Montes', 'Parque Industrial Queretaro', 'Cumbres del Lago', 'San Miguel', 'Viñedos', 'Loma Blanca', 'El Romeral', 'La Cuesta de los Ibarra', 'La Tecozautla']

# Print the final dp table values
print("Final DP Table:")
for mask in range(1 << n):
    print(f"mask = {mask:04b}: {dp[mask]}")

# Print the optimal tour and minimum cost
#Imprimir la ciudad en relacion a la matriz cities[tour]
print("\nOptimal Tour:")
for i in tour:
    print(cities[i])
print("Minimum Cost:", min_cost)