import ast

output = open("output.txt", "r").read()
data = ast.literal_eval(output) 
mapping = {}

for i in data:
    mapping[i[1]] = chr(int(i[0], 16))

charset = sorted(mapping)

decoded = ""

for i in charset:
    decoded += mapping[i]

print(decoded)
