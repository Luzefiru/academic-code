# The Initial List of Passengers will be found in the API:
curl -X GET https://my-json-server.typicode.com/troy1129/jsonplaceholder/passengers
# [
#   {
#     "name": "Patrick",
#     "id": 1,
#     "destination": "" 
#   },
#   {
#     "name": "Ean",    
#     "id": 2,
#     "destination": "" 
#   },
#   {
#     "name": "Karlo",  
#     "id": 3,
#     "destination": "" 
#   },
#   {
#     "name": "Gran",
#     "id": 4,
#     "destination": ""
#   },
#   {
#     "name": "Josh",
#     "id": 5,
#     "destination": ""
#   }
# ]

# While the List of Destinations and their corresponding prices will be found in the API:
curl -X GET https://my-json-server.typicode.com/troy1129/jsonplaceholder/destinations
# [
#   {
#     "id": 1,
#     "destination": "Cebu",
#     "price": 100
#   },
#   {
#     "id": 2,
#     "destination": "Mandaue",
#     "price": 120
#   },
#   {
#     "id": 3,
#     "destination": "Lilo-an",
#     "price": 140
#   },
#   {
#     "id": 4,
#     "destination": "Lapu-Lapu",
#     "price": 160
#   },
#   {
#     "id": 5,
#     "destination": "Consolacion",
#     "price": 180
#   },
#   {
#     "id": 6,
#     "destination": "Talisay",
#     "price": 200
#   }
# ]