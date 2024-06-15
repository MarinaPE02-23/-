import numpy 
M4 = numpy.array([[1., 2., -2.,6.], [-3., -5., 14.,13.], [1., 2., -2., -2.],[-2., -4., 5., 10.]]) 
v4 = numpy.array([24., 41., 0., 20.]) 

a=numpy.linalg.solve(M4, v4) 
print('Решение СЛАУ')
print(a)