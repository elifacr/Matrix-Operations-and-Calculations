#include <iostream>

void matrixMultiplication(int **A, int rowA, int columnA, int **B, int rowB, int columnB, int **C) {
	if(columnA != rowB) {
		std::cout << "Matrices cannot be multiplied. The number of columns of the first matrix must be equal to the number of rows of the second matrix." << std::endl;
		return;
	}

	for(int i = 0; i < rowA; i++) {
		for(int j = 0; j < columnB; j++) {
			C[i][j] = 0;
			for(int k = 0; k < columnA; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void matrixPrinting(int **matrix, int row, int column) {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	int rowA, columnA, rowB, columnB;

	std::cout << "Enter the number of rows of the first matrix: ";
	std::cin >> rowA;
	std::cout << "Enter the number of columns of the first matrix: ";
	std::cin >> columnA;
	std::cout << "Enter the number of rows of the second matrix: ";
	std::cin >> rowB;
	std::cout << "Enter the number of columns of the second matrix: ";
	std::cin >> columnB;

	std::cout << "\n\n";

	//Dynamic memory allocation for matrices.
	int **A = new int*[rowA];
	for(int i = 0; i < rowA; i++) {
		A[i] = new int[columnA];
	}

	int **B = new int*[rowB];
	for(int i = 0; i < rowB; i++) {
		B[i] = new int[columnB];
	}

	int **C = new int*[rowA];
	for(int i = 0; i < rowA; i++) {
		C[i] = new int[columnB];
	}

	//Getting matrix elements from user.
	std::cout << "Enter the elements of the first matrix:\n";
	for(int i = 0; i < rowA; i++) {
		std::cout << "Enter the elements of row " << i + 1 <<" in order." << std::endl;
		for(int j = 0; j < columnA; j++) {
			std::cin >> A[i][j];
		}
	}
	std::cout << "\n\n";
	
	std::cout << "Enter the elements of the second matrix:\n";
	for(int i = 0; i < columnA; i++) {
		std::cout << "Enter the elements of row " << i + 1 <<" in order." << std::endl;
		for(int j = 0; j < columnB; j++) {
			std::cin >> B[i][j];
		}
	}
	std::cout << "\n\n";

	//Multiplication of matrices.
	matrixMultiplication(A,rowA, columnA, B, rowB, columnB, C);

	//Printing the results matrix to the screen.
	std::cout << "Result matrix:\n";
	matrixPrinting(C, rowA, columnB);

	//Releasing memory.
	for(int i = 0; i < rowA; i++) {
		delete[] A[i];
	}
	delete[] A;

	for(int i = 0; i < rowB; i++) {
		delete[] B[i];
	}
	delete[] B;

	for(int i = 0; i < rowA; i++) {
		delete[] C[i];
	}
	delete[] C;

	return 0;
}
