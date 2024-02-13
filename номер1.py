import math

e = int(input('e: '))
f = int(input('f: '))
g = int(input('g: '))
h = int(input('h: '))

a = math.sqrt(abs(e - (2/f))**2) + g
b = math.sin(e) + (math.cos(h)**2)*h
c = (22*g)/ (e*f-2)

print(f'a = {a}, b = {b}, c = {c}')
