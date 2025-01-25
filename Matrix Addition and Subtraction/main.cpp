#include <iostream>

void matrixAddition(int row, int column, int *matrix1, int *matrix2, int *result) {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			*(result + i*column + j) = *(matrix1 + i*column + j) + *(matrix2 + i*column + j);
		}
	}
}

void matrixSubtraction(int row, int column, int *matrix1, int *matrix2, int *result) {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			*(result + i*column + j) = *(matrix1 + i*column + j) - *(matrix2 + i*column + j);
		}
	}
}

void matrixPrinting(int row, int column, int *matrix) {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			std::cout << *(matrix + i*column + j) << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	int row, column, choice;
	std::cout << "Enter the size of matrices (row column): ";
	std::cin >> row >> column;

	int matrix1[row][column], matrix2[row][column], result[row][column];
	std::cout << "Enter the first matrix:\n";
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < column; j++) {
				std::cin >> matrix1[i][j];
			}
		}
	std::cout << "Enter the second matrix:\n";
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < column; j++) {
				std::cin >> matrix2[i][j];
			}
		}

	bool control = 0;

	while (control != 1) {
		std::cout << "Matrix operations menu:\n";
		std::cout << "1. Matrix Addition\n";
		std::cout << "2. Matrix Subtraction\n";
		std::cout << "3. Exit\n";
		std::cout << "Your choice: ";
		std::cin >> choice;

		if(choice == 1) {
			matrixAddition(row, column, &matrix1[0][0], &matrix2[0][0], &result[0][0]);
			std::cout << "Result matrix:\n";
			matrixPrinting(row, column, &result[0][0]);
		} else if(choice == 2) {
			matrixSubtraction(row, column, &matrix1[0][0], &matrix2[0][0], &result[0][0]);
			std::cout << "Result matrix:\n";
			matrixPrinting(row, column, &result[0][0]);
		} else if(choice == 3) {
			std::cout << "Exiting the program...\n";
			control = 1;
		} else {
			std::cout << "Wrong choice.\n";
		}
	}

	return 0;
}
