import random

url = "https://gchq.github.io/CyberChef/#recipe=From_Base58('123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz',true)&input=Qm12NHVIQzlNQjJvbnZZckNjRzhydjhjRDFUTTQ2VTE4WE5iVm1pNXVmTnBkYldQUEJZSldXYU1iZGVGeHVlYzZrZkFwa3lyWUhGWEtTZXZUMWttbUxlczFaMjJnUXZIcDhFWnJTd3lGTkZMTU1wV1RaNUhDdWFpVDRiTEdLamJxcHh6cmlkOGpHRDJ5c1d2R2pLOHRnak5pQkZuaVlvbnU3R1JNdEZTdkszNUdRUEptWUtZaURGTkR5Nnl3Y3hMdGRqYVVheXhyanVGUnFqZnVZMk52ODd2OUFBb0hGcjZEaW81Q3E4TlNzWWMxcEQyTWhYMlBjSk4zUVZkVEJOZE5WU0ppNVd4NVhHSEE0ZHU4U1J3VlF4eGp2VTV4M0JTUUtBdGJYNjhIMU1TajQ0QUUzaG5VdVlLbTR0UlladTlweWZjWENTVEwxa01oVDZXcGpIRXNnY0tSQWIxRUFjcGs0Tm1zbzE3dFhrS3U4aWZ0TDhkUlFyRzNnMmM0akFZcmlid3R6NVBNWG84eUMyZGNaZjRhaG9xUW5tZkR3dGNtNlJudVg1djdQbXRCMlJoS24ySjFCMVhrd2FWR0U4Z1FMUGZkdnhBY3JCTk5YUWYzbkdvWkFtNUMzWDhIaHpkbUZUMTVDOENuU1JTRnRnYm1pb1kxU1pGdVljanR2b1JnTkttbXk1SDlHWUc5aWMxcUsxNE1RUVFIVUFKY25SUktjTjJtR2dTUW8ycDZnWE5zSGU1TFRkNkNHZ0hXcFBpZFh0QWZiVVRvRzJWeXZEVUVUa2tndTJBS3hjQ3A"
mapping = []

for idx, char in enumerate(url):
    mapping.append([hex(ord(char))[2:], idx])


mapping[::-1]

for i in range(0, len(mapping), 100):
    tmp1 = mapping[i]
    tmp2 = mapping[i+1]
    mapping[i] = tmp2
    mapping[i+1] = tmp1

for i in range(0, len(mapping), 50):
    tmp1 = mapping[i]
    tmp2 = mapping[i+1]
    mapping[i] = tmp2
    mapping[i+1] = tmp1

for i in range(0, len(mapping), 30):
    tmp1 = mapping[i]
    tmp2 = mapping[i+1]
    mapping[i] = tmp2
    mapping[i+1] = tmp1

for i in range(0, len(mapping), 200):
    tmp1 = mapping[i]
    tmp2 = mapping[i+1]
    mapping[i] = tmp2
    mapping[i+1] = tmp1

for i in range(0, len(mapping), 5):
    tmp1 = mapping[i]
    tmp2 = mapping[i+1]
    mapping[i] = tmp2
    mapping[i+1] = tmp1

for i in range(0, len(mapping), 3):
    tmp1 = mapping[i]
    tmp2 = mapping[i+1]
    mapping[i] = tmp2
    mapping[i+1] = tmp1

for i in range(0, len(mapping), 8):
    tmp1 = mapping[i]
    tmp2 = mapping[i+1]
    mapping[i] = tmp2
    mapping[i+1] = tmp1

for i in range(0, len(mapping), 11):
    tmp1 = mapping[i]
    tmp2 = mapping[i+1]
    mapping[i] = tmp2
    mapping[i+1] = tmp1

for i in range(0, len(mapping), 90):
    tmp1 = mapping[i]
    tmp2 = mapping[i+1]
    mapping[i] = tmp2
    mapping[i+1] = tmp1

print(mapping[::-1])
