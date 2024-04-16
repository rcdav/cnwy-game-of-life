// Roshni Dave. CS 10B. Sarkar s. boolMatrix.h

#ifndef BOOLMATRIX_H
#define BOOLMATRIX_H

#include <cassert>
#include <iostream>
#include <iomanip>

class boolMatrix {
public:
    static const int NUM_ROWS = 20;
    static const int NUM_COLS = 20;

    boolMatrix();
    bool get(int row, int col) const;
    void set(int row, int col, bool value);
    int rowCount(int row) const;
    int colCount(int col) const;
    int totalCount() const;
    int neighborCount(int row, int col) const;
    void print() const;

private:
    bool matrix[NUM_ROWS][NUM_COLS]; // 2D array representing the boolean matrix
};

#endif // BOOLMATRIX_H
