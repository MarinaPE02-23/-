#Метод complex
import math
import cmath

a = complex(1, 1)
print('a =',a)
print('Type of a is',type(a))

b = complex(4, -1)
print('b =',b)
print('Type of b is',type(a))

c = complex(-1, -2)
print('c =',c)
print('Type of c is',type(c))

# Арифметические операции
z1= a + b 
print('a + b =', z1)
z2 = a - b
print('a - b =', z2)
z3 = a * b
print('a * b =', z3)
z4 = a / b
print('a / b =', z4)
z5 = c ** 4
print('a ** 4 =', c)


z = complex(-1, -0)
n = int(4)
r, phi = cmath.polar(z)
r **= 1 / n
print("n-ые корни комплексного числа: \n")
for k in range(n):
    roots = cmath.rect(r, (phi + 2 * cmath.pi * k) / n)
    print("k=",k, ", z_k=", roots, sep="")


