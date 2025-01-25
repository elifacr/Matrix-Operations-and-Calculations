#include <iostream>

void matrixPrinting(int *matrix, int row, int column) {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			std::cout << *(matrix + i * column + j) << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	int row, column;

	std::cout << "Enter the number of rows: ";
	std::cin >> row;
	std::cout << "Enter the number of columns: ";
	std::cin >> column;
	std::cout << std::endl;

	int matrix[row][column], transpose[column][row];

	std::cout << "Enter the elements of the matrix:\n";
	for(int i = 0; i < row; i++) {
		std::cout << "Row: " << i + 1 << std::endl;
		for(int j = 0; j < column; j++) {
			std::cin >> matrix[i][j];
		}
	}
	std::cout << std::endl;
	
	std::cout << "Matrix:\n";
	matrixPrinting(&matrix[0][0], row, column);
	std::cout << std::endl;

	std::cout << "Transpose matrix:\n";
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			transpose[j][i] = matrix[i][j];
		}
	}
	matrixPrinting(&transpose[0][0], column, row);
	std::cout << std::endl;

	return 0;
}