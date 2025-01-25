def matrixMultiplication(A, rowA, columnA, B, rowB, columnB):
	if columnA != rowB:
		print("Matrices cannot be multiplied. The number of columns of the first matrix must be equal to the number of rows of the second matrix.")
		return None

	C = [[0 for _ in range(columnB)] for _ in range(rowA)]

	for i in range(rowA):
		for j in range(columnB):
			for k in range(columnA):
				C[i][j] += A[i][k] * B[k][j]
	
	return C

def printMatrix(matrix):
	for row in matrix:
		for element in row:
			print(element, end=" ")
		print()

rowA = int(input("Enter the number of rows of the first matrix: "))
columnA = int(input("Enter the number of columns of the first matrix: "))
rowB = int(input("Enter the number of rows of the second matrix: "))
columnB = int(input("Enter the number of columns of the second matrix: "))

print("\nEnter the elements of the first matrix: ")
A = []
for i in range(rowA):
	row = []
	for j in range(columnA):
		row.append(int(input(f"Enter element at row {i + 1}, column {j + 1}: ")))
	A.append(row)

print("\nEnter the elements of the second matrix: ")
B = []
for i in range(rowB):
	row = []
	for j in range(columnB):
		row.append(int(input(f"Enter element at row {i + 1}, column {j + 1}: ")))
	B.append(row)

C = matrixMultiplication(A, rowA, columnA, B, rowB, columnB)

if C:
	print("\nResult matrix:")
	printMatrix(C)
