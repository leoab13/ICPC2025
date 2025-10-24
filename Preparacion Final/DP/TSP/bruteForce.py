# Define the cities and distances
import itertools
cities = ['Santiago de Querétaro', 'San Juan del Rio', 'Tequisquiapan', 'Santa Rosa Jauregui','Jalpan de Serra', 'Ezequiel Montes', 'Cadereyta de Montes', 'Parque Industrial Queretaro', 'Cumbres del Lago', 'San Miguel', 'Viñedos', 'Loma Blanca', 'El Romeral', 'La Cuesta de los Ibarra', 'La Tecozautla']
# Diccionario de distancias generado desde mx-queretaro.csv
distances = {

    ("Santiago de Querétaro", "San Juan del Rio"): 53,
    ("Santiago de Querétaro", "Tequisquiapan"): 62,
    ("Santiago de Querétaro", "Santa Rosa Jauregui"): 21,
    ("Santiago de Querétaro", "Jalpan de Serra"): 186,
    ("Santiago de Querétaro", "Ezequiel Montes"): 62,
    ("Santiago de Querétaro", "Cadereyta de Montes"): 72,
    ("Santiago de Querétaro", "Parque Industrial Queretaro"): 31,
    ("Santiago de Querétaro", "Cumbres del Lago"): 21,
    ("Santiago de Querétaro", "San Miguel"): 27,
    ("Santiago de Querétaro", "Viñedos"): 15,
    ("Santiago de Querétaro", "Loma Blanca"): 144,
    ("Santiago de Querétaro", "El Romeral"): 14,
    ("Santiago de Querétaro", "La Cuesta de los Ibarra"): 143,
    ("Santiago de Querétaro", "La Tecozautla"): 136,

    ("San Juan del Rio", "Santiago de Querétaro"): 53,
    ("San Juan del Rio", "Tequisquiapan"): 21,
    ("San Juan del Rio", "Santa Rosa Jauregui"): 72,
    ("San Juan del Rio", "Jalpan de Serra"): 181,
    ("San Juan del Rio", "Ezequiel Montes"): 37,
    ("San Juan del Rio", "Cadereyta de Montes"): 49,
    ("San Juan del Rio", "Parque Industrial Queretaro"): 72,
    ("San Juan del Rio", "Cumbres del Lago"): 73,
    ("San Juan del Rio", "San Miguel"): 64,
    ("San Juan del Rio", "Viñedos"): 66,
    ("San Juan del Rio", "Loma Blanca"): 138,
    ("San Juan del Rio", "El Romeral"): 66,
    ("San Juan del Rio", "La Cuesta de los Ibarra"): 137,
    ("San Juan del Rio", "La Tecozautla"): 135,



    ("Tequisquiapan", "San Juan del Rio"): 20,
    ("Tequisquiapan", "Santiago de Querétaro"): 62,
    ("Tequisquiapan", "Santa Rosa Jauregui"): 76,
    ("Tequisquiapan", "Jalpan de Serra"): 162,
    ("Tequisquiapan", "Ezequiel Montes"): 18,
    ("Tequisquiapan", "Cadereyta de Montes"): 30,
    ("Tequisquiapan", "Parque Industrial Queretaro"): 76,
    ("Tequisquiapan", "Cumbres del Lago"): 82,
    ("Tequisquiapan", "San Miguel"): 56,
    ("Tequisquiapan", "Viñedos"): 75,
    ("Tequisquiapan", "Loma Blanca"): 118,
    ("Tequisquiapan", "El Romeral"): 75,
    ("Tequisquiapan", "La Cuesta de los Ibarra"): 118,
    ("Tequisquiapan", "La Tecozautla"): 116,

    ("Santa Rosa Jauregui", "San Juan del Rio"): 73,
    ("Santa Rosa Jauregui", "Santiago de Querétaro"): 21,
    ("Santa Rosa Jauregui", "Tequisquiapan"): 81,
    ("Santa Rosa Jauregui", "Jalpan de Serra"): 206,
    ("Santa Rosa Jauregui", "Ezequiel Montes"): 81,
    ("Santa Rosa Jauregui", "Cadereyta de Montes"): 92,
    ("Santa Rosa Jauregui", "Parque Industrial Queretaro"): 12,
    ("Santa Rosa Jauregui", "Cumbres del Lago"): 8,
    ("Santa Rosa Jauregui", "San Miguel"): 25,
    ("Santa Rosa Jauregui", "Viñedos"): 24,
    ("Santa Rosa Jauregui", "Loma Blanca"): 124,
    ("Santa Rosa Jauregui", "El Romeral"): 34,
    ("Santa Rosa Jauregui", "La Cuesta de los Ibarra"): 124,
    ("Santa Rosa Jauregui", "La Tecozautla"): 117,

    ("Jalpan de Serra", "San Juan del Rio"): 178,
    ("Jalpan de Serra", "Santiago de Querétaro"): 185,
    ("Jalpan de Serra", "Tequisquiapan"): 159,
    ("Jalpan de Serra", "Santa Rosa Jauregui"): 199,
    ("Jalpan de Serra", "Ezequiel Montes"): 142,
    ("Jalpan de Serra", "Cadereyta de Montes"): 137,
    ("Jalpan de Serra", "Parque Industrial Queretaro"): 199,
    ("Jalpan de Serra", "Cumbres del Lago"): 206,
    ("Jalpan de Serra", "San Miguel"): 180,
    ("Jalpan de Serra", "Viñedos"): 199,
    ("Jalpan de Serra", "Loma Blanca"): 107,
    ("Jalpan de Serra", "El Romeral"): 199,
    ("Jalpan de Serra", "La Cuesta de los Ibarra"): 107,
    ("Jalpan de Serra", "La Tecozautla"): 105,

    ("Ezequiel Montes", "San Juan del Rio"): 36,
    ("Ezequiel Montes", "Santiago de Querétaro"): 62,
    ("Ezequiel Montes", "Tequisquiapan"): 17,
    ("Ezequiel Montes", "Santa Rosa Jauregui"): 76,
    ("Ezequiel Montes", "Jalpan de Serra"): 145,
    ("Ezequiel Montes", "Cadereyta de Montes"): 13,
    ("Ezequiel Montes", "Parque Industrial Queretaro"): 76,
    ("Ezequiel Montes", "Cumbres del Lago"): 82,
    ("Ezequiel Montes", "San Miguel"): 57,
    ("Ezequiel Montes", "Viñedos"): 75,
    ("Ezequiel Montes", "Loma Blanca"): 102,
    ("Ezequiel Montes", "El Romeral"): 75,
    ("Ezequiel Montes", "La Cuesta de los Ibarra"): 101,
    ("Ezequiel Montes", "La Tecozautla"): 99,

    ("Cadereyta de Montes", "San Juan del Rio"): 49,
    ("Cadereyta de Montes", "Santiago de Querétaro"): 72,
    ("Cadereyta de Montes", "Tequisquiapan"): 30,
    ("Cadereyta de Montes", "Santa Rosa Jauregui"): 86,
    ("Cadereyta de Montes", "Jalpan de Serra"): 137,
    ("Cadereyta de Montes", "Ezequiel Montes"): 13,
    ("Cadereyta de Montes", "Parque Industrial Queretaro"): 86,
    ("Cadereyta de Montes", "Cumbres del Lago"): 92,
    ("Cadereyta de Montes", "San Miguel"): 67,
    ("Cadereyta de Montes", "Viñedos"): 85,
    ("Cadereyta de Montes", "Loma Blanca"): 94,
    ("Cadereyta de Montes", "El Romeral"): 85,
    ("Cadereyta de Montes", "La Cuesta de los Ibarra"): 93,
    ("Cadereyta de Montes", "La Tecozautla"): 91,

    ("Parque Industrial Queretaro", "San Juan del Rio"): 73,
    ("Parque Industrial Queretaro", "Santiago de Querétaro"): 33,
    ("Parque Industrial Queretaro", "Tequisquiapan"): 81,
    ("Parque Industrial Queretaro", "Santa Rosa Jauregui"): 13,
    ("Parque Industrial Queretaro", "Jalpan de Serra"): 205,
    ("Parque Industrial Queretaro", "Ezequiel Montes"): 81,
    ("Parque Industrial Queretaro", "Cadereyta de Montes"): 92,
    ("Parque Industrial Queretaro", "Cumbres del Lago"): 23,
    ("Parque Industrial Queretaro", "San Miguel"): 20,
    ("Parque Industrial Queretaro", "Viñedos"): 35,
    ("Parque Industrial Queretaro", "Loma Blanca"): 114,
    ("Parque Industrial Queretaro", "El Romeral"): 43,
    ("Parque Industrial Queretaro", "La Cuesta de los Ibarra"): 113,
    ("Parque Industrial Queretaro", "La Tecozautla"): 107,

    ("Cumbres del Lago", "San Juan del Rio"): 72,
    ("Cumbres del Lago", "Santiago de Querétaro"): 20,
    ("Cumbres del Lago", "Tequisquiapan"): 80,
    ("Cumbres del Lago", "Santa Rosa Jauregui"): 10,
    ("Cumbres del Lago", "Jalpan de Serra"): 204,
    ("Cumbres del Lago", "Ezequiel Montes"): 80,
    ("Cumbres del Lago", "Cadereyta de Montes"): 91,
    ("Cumbres del Lago", "Parque Industrial Queretaro"): 19,
    ("Cumbres del Lago", "San Miguel"): 32,
    ("Cumbres del Lago", "Viñedos"): 19,
    ("Cumbres del Lago", "Loma Blanca"): 131,
    ("Cumbres del Lago", "El Romeral"): 28,
    ("Cumbres del Lago", "La Cuesta de los Ibarra"): 130,
    ("Cumbres del Lago", "La Tecozautla"): 124,

    ("San Miguel", "San Juan del Rio"): 64,
    ("San Miguel", "Santiago de Querétaro"): 29,
    ("San Miguel", "Tequisquiapan"): 57,
    ("San Miguel", "Santa Rosa Jauregui"): 23,
    ("San Miguel", "Jalpan de Serra"): 181,
    ("San Miguel", "Ezequiel Montes"): 57,
    ("San Miguel", "Cadereyta de Montes"): 68,
    ("San Miguel", "Parque Industrial Queretaro"): 20,
    ("San Miguel", "Cumbres del Lago"): 30,
    ("San Miguel", "Viñedos"): 34,
    ("San Miguel", "Loma Blanca"): 141,
    ("San Miguel", "El Romeral"): 43,
    ("San Miguel", "La Cuesta de los Ibarra"): 140,
    ("San Miguel", "La Tecozautla"): 133,

    ("Viñedos", "San Juan del Rio"): 67,
    ("Viñedos", "Santiago de Querétaro"): 15,
    ("Viñedos", "Tequisquiapan"): 75,
    ("Viñedos", "Santa Rosa Jauregui"): 21,
    ("Viñedos", "Jalpan de Serra"): 200,
    ("Viñedos", "Ezequiel Montes"): 75,
    ("Viñedos", "Cadereyta de Montes"): 86,
    ("Viñedos", "Parque Industrial Queretaro"): 34,
    ("Viñedos", "Cumbres del Lago"): 18,
    ("Viñedos", "San Miguel"): 35,
    ("Viñedos", "Loma Blanca"): 147,
    ("Viñedos", "El Romeral"): 12,
    ("Viñedos", "La Cuesta de los Ibarra"): 146,
    ("Viñedos", "La Tecozautla"): 139,

    ("Loma Blanca", "San Juan del Rio"): 135,
    ("Loma Blanca", "Santiago de Querétaro"): 144,
    ("Loma Blanca", "Tequisquiapan"): 116,
    ("Loma Blanca", "Santa Rosa Jauregui"): 124,
    ("Loma Blanca", "Jalpan de Serra"): 107,
    ("Loma Blanca", "Ezequiel Montes"): 99,
    ("Loma Blanca", "Cadereyta de Montes"): 94,
    ("Loma Blanca", "Parque Industrial Queretaro"): 117,
    ("Loma Blanca", "Cumbres del Lago"): 134,
    ("Loma Blanca", "San Miguel"): 142,
    ("Loma Blanca", "Viñedos"): 146,
    ("Loma Blanca", "El Romeral"): 154,
    ("Loma Blanca", "La Cuesta de los Ibarra"): 3,
    ("Loma Blanca", "La Tecozautla"): 6,

    ("El Romeral", "San Juan del Rio"): 69,
    ("El Romeral", "Santiago de Querétaro"): 15,
    ("El Romeral", "Tequisquiapan"): 77,
    ("El Romeral", "Santa Rosa Jauregui"): 34,
    ("El Romeral", "Jalpan de Serra"): 201,
    ("El Romeral", "Ezequiel Montes"): 77,
    ("El Romeral", "Cadereyta de Montes"): 88,
    ("El Romeral", "Parque Industrial Queretaro"): 42,
    ("El Romeral", "Cumbres del Lago"): 27,
    ("El Romeral", "San Miguel"): 43,
    ("El Romeral", "Viñedos"): 12,
    ("El Romeral", "Loma Blanca"): 155,
    ("El Romeral", "La Cuesta de los Ibarra"): 154,
    ("El Romeral", "La Tecozautla"): 148,

    ("La Cuesta de los Ibarra", "San Juan del Rio"): 134,
    ("La Cuesta de los Ibarra", "Santiago de Querétaro"): 144,
    ("La Cuesta de los Ibarra", "Tequisquiapan"): 115,
    ("La Cuesta de los Ibarra", "Santa Rosa Jauregui"): 123,
    ("La Cuesta de los Ibarra", "Jalpan de Serra"): 107,
    ("La Cuesta de los Ibarra", "Ezequiel Montes"): 98,
    ("La Cuesta de los Ibarra", "Cadereyta de Montes"): 93,
    ("La Cuesta de los Ibarra", "Parque Industrial Queretaro"): 116,
    ("La Cuesta de los Ibarra", "Cumbres del Lago"): 133,
    ("La Cuesta de los Ibarra", "San Miguel"): 141,
    ("La Cuesta de los Ibarra", "Viñedos"): 145,
    ("La Cuesta de los Ibarra", "Loma Blanca"): 3,
    ("La Cuesta de los Ibarra", "El Romeral"): 153,
    ("La Cuesta de los Ibarra", "La Tecozautla"): 5,

    ("La Tecozautla", "San Juan del Rio"): 132,
    ("La Tecozautla", "Santiago de Querétaro"): 137,
    ("La Tecozautla", "Tequisquiapan"): 113,
    ("La Tecozautla", "Santa Rosa Jauregui"): 116,
    ("La Tecozautla", "Jalpan de Serra"): 105,
    ("La Tecozautla", "Ezequiel Montes"): 96,
    ("La Tecozautla", "Cadereyta de Montes"): 91,
    ("La Tecozautla", "Parque Industrial Queretaro"): 109,
    ("La Tecozautla", "Cumbres del Lago"): 126,
    ("La Tecozautla", "San Miguel"): 134,
    ("La Tecozautla", "Viñedos"): 138,
    ("La Tecozautla", "Loma Blanca"): 6,
    ("La Tecozautla", "El Romeral"): 147,
    ("La Tecozautla", "La Cuesta de los Ibarra"): 5,
}



# Function to calculate the total cost of a route
def calculate_cost(route):
    total_cost = 0
    n = len(route)
    for i in range(n):
        current_city = route[i]
        next_city = route[(i + 1) % n]  # Wrap around to the start of the route
        # Look up the distance in both directions
        if (current_city, next_city) in distances:
            total_cost += distances[(current_city, next_city)]
        else:
            total_cost += distances[(next_city, current_city)]
    return total_cost

# Generate all permutations of the cities
all_permutations = itertools.permutations(cities)

# Initialize variables to track the minimum cost and corresponding route
min_cost = float('inf')
optimal_route = None

# Iterate over all permutations and calculate costs
for perm in all_permutations:
    cost = calculate_cost(perm)
    if cost < min_cost:
        min_cost = cost
        optimal_route = perm + ('a',)

# Print the optimal route and its cost
print(f"Optimal Route: {optimal_route}")
print(f"Total Cost: {min_cost}")