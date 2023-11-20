import numpy as np

# Program 1
my_list = [1.0, 2.5, 3.7, 4.2]
array_from_list = np.array(my_list, dtype=float)
my_tuple = (1.0, 2.5, 3.7, 4.2)
array_from_tuple = np.array(my_tuple, dtype=float)
print("Array from list:", array_from_list)
print("Array from tuple:", array_from_tuple)

# Program 2
arr = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
slice_result = arr[2:7]
indexing_result = arr[[1, 3, 5]]
boolean_condition = arr % 2 == 0
boolean_indexing_result = arr[boolean_condition]
print("Slicing result:", slice_result)
print("Integer array indexing result:", indexing_result)
print("Boolean array indexing result:", boolean_indexing_result)

# Program 3
my_array = np.array([10, 5, 8, 2, 7, 1, 9])
min_value = np.min(my_array)
max_value = np.max(my_array)
array_sum = np.sum(my_array)
cumulative_sum = np.cumsum(my_array)
print("Original Array:", my_array)
print("Minimum Value:", min_value)
print("Maximum Value:", max_value)
print("Sum of Array:", array_sum)
print("Cumulative Sum of Array:", cumulative_sum)

# Program 4
my_array = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
num_dimensions = my_array.ndim
array_shape = my_array.shape
array_size = my_array.size
data_type = my_array.dtype
print("Original Array:")
print(my_array)
print("Number of Dimensions (ndim):", num_dimensions)
print("Shape of the Array:", array_shape)
print("Total Number of Elements (size):", array_size)
print("Data Type (dtype):", data_type)

# Program 5
matrix = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
rank = np.linalg.matrix_rank(matrix)
determinant = np.linalg.det(matrix)
trace = np.trace(matrix)
print("Matrix:")
print(matrix)
print("Rank:", rank)
print("Determinant:", determinant)
print("Trace:", trace)

# Program 6
matrix = np.array([[1, 2], [2, 3]])
eigenvalues = np.linalg.eigvals(matrix)
print("Matrix:")
print(matrix)
print("Eigenvalues:")
print(eigenvalues)

# Program 7
matrix_A = np.array([[1, 2], [3, 4]])
matrix_B = np.array([[5, 6], [7, 8]])
vector_x = np.array([1, 2])
vector_y = np.array([3, 4])
dot_product = np.dot(vector_x, vector_y)
inner_product = np.inner(matrix_A, matrix_B)
outer_product = np.outer(vector_x, vector_y)
matrix_product = np.matmul(matrix_A, matrix_B)
exponent = 2
matrix_exponential = np.linalg.matrix_power(matrix_A, exponent)
print("Vector x:", vector_x)
print("Vector y:", vector_y)
print("Matrix A:")
print(matrix_A)
print("Matrix B:")
print(matrix_B)
print("Dot product of x and y:", dot_product)
print("Inner product of A and B:")
print(inner_product)
print("Outer product of x and y:")
print(outer_product)
print("Matrix product of A and B:")
print(matrix_product)
print(f"Matrix A raised to the power {exponent}:")
print(matrix_exponential)

# Program 8
A = np.array([[2, 1], [1, 3]])
b = np.array([3, 9])
solution = np.linalg.solve(A, b)
print("Coefficient matrix (A):")
print(A)
print("Right-hand side vector (b):")
print(b)
print("Solution vector (x):")
print(solution)
