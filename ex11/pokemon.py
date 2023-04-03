import requests

pokemon_name = input("Enter the name of a Pokemon: ")
response = requests.get(f"https://pokeapi.co/api/v2/pokemon/{pokemon_name.lower()}")

if response.status_code != 200:
    print(f"Failed to retrieve information about {pokemon_name}")
    exit()

abilities = [ability['ability']['name'] for ability in response.json()['abilities']]
print(f"Name: {pokemon_name}")
print("Abilities:")
for ability in abilities:
    print(f"- {ability.capitalize().replace('-', ' ')}")
