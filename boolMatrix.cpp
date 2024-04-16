// Roshni Dave. CS 10B. Sarkar s. boolMatrix.cpp

#include "boolMatrix.h"

// constructor to initialize the boolean matrix with false values
boolMatrix::boolMatrix() {
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            matrix[i][j] = false;
        }
    }
}

// function to retrieve the boolean value at the specified row and column
bool boolMatrix::get(int row, int col) const {
    assert(row >= 0 && row < NUM_ROWS);
    assert(col >= 0 && col < NUM_COLS);
    return matrix[row][col];
}

// function to set the boolean value at the specified row and column
void boolMatrix::set(int row, int col, bool value) {
    assert(row >= 0 && row < NUM_ROWS);
    assert(col >= 0 && col < NUM_COLS);
    matrix[row][col] = value;
}

// function to count the number of 'true' values in the specified row
int boolMatrix::rowCount(int row) const {
    assert(row >= 0 && row < NUM_ROWS);
    int count = 0;
    for (int col = 0; col < NUM_COLS; ++col) {
        if (matrix[row][col]) {
            ++count;
        }
    }
    return count;
}

// function to count the number of 'true' values in the specified column
int boolMatrix::colCount(int col) const {
    assert(col >= 0 && col < NUM_COLS);
    int count = 0;
    for (int row = 0; row < NUM_ROWS; ++row) {
        if (matrix[row][col]) {
            ++count;
        }
    }
    return count;
}

// function to count the total number of 'true' values in the entire matrix
int boolMatrix::totalCount() const {
    int count = 0;
    for (int i = 0; i < NUM_ROWS; ++i) {
        count += rowCount(i);
    }
    return count;
}

// function to count the number of neighboring 'true' values around the specified cell
int boolMatrix::neighborCount(int row, int col) const {
    assert(row >= 0 && row < NUM_ROWS);
    assert(col >= 0 && col < NUM_COLS);
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // skip the current cell
            int nr = row + i; // calculate neighbor row
            int nc = col + j; // calculate neighbor column
            if (nr >= 0 && nr < NUM_ROWS && nc >= 0 && nc < NUM_COLS && get(nr, nc)) {
                ++count;
            }
        }
    }
    return count;
}

// function to print the matrix with row and column indices
void boolMatrix::print() const {
    std::cout << "  ";
    for (int col = 0; col < NUM_COLS; ++col) {
        std::cout << col % 10; // print column indices
    }
    std::cout << std::endl;
    for (int row = 0; row < NUM_ROWS; ++row) {
        std::cout << std::setw(2) << row; // print row index
        for (int col = 0; col < NUM_COLS; ++col) {
            std::cout << (matrix[row][col] ? '*' : ' '); // print '*' for true and ' ' for false
        }
        std::cout << std::endl;
    }
}
