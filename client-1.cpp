// Roshni Dave. CS 10B. Sarkar s. client.cpp


#include "boolMatrix.h" 
#include <fstream>
#include <string>

void initialize(boolMatrix &m, const std::string &filename);
void playGameOfLife(boolMatrix &m, int generations);
void displayStatistics(const boolMatrix &m);

int main() {
    boolMatrix life;
    initialize(life, "lifedata.txt");
    int generations = 5;
    std::cout << "Enter number of generations: ";
    std::cin >> generations;

    playGameOfLife(life, generations);
    life.print();
    displayStatistics(life);

    return 0;
}

// function to initialize the boolean matrix based on data from a file
void initialize(boolMatrix &m, const std::string &filename) {
    std::ifstream file(filename); 
    int row, col;
    while (file >> row >> col) { // read row and column from file
        m.set(row, col, true);
    }
}

// function to simulate the Game of Life for a specified number of generations
void playGameOfLife(boolMatrix &m, int generations) {
    boolMatrix temp; // temporary matrix to store the next generation
    for (int gen = 0; gen < generations; ++gen) { // iterate through generations
        for (int row = 0; row < boolMatrix::NUM_ROWS; ++row) { // iterate through rows
            for (int col = 0; col < boolMatrix::NUM_COLS; ++col) { // iterate through columns
                int neighbors = m.neighborCount(row, col); // count neighbors for current cell
                bool current = m.get(row, col); 
                bool newState = false;

                if (current) { // if cell is alive
                    newState = (neighbors == 2 || neighbors == 3); 
                } else { // if cell is dead
                    newState = (neighbors == 3); 
                }

                temp.set(row, col, newState); // set the new state of cell in temp matrix
            }
        }
        m = temp; 
    }
}

// function to display statistics of the boolean matrix after the last generation
void displayStatistics(const boolMatrix &m) {
    std::cout << "Statistics after last generation:\n";
    std::cout << "Total alive in row 10 = " << m.rowCount(10) << std::endl; // count alive cells in row 10
    std::cout << "Total dead in row 16 = " << (boolMatrix::NUM_COLS - m.rowCount(16)) << std::endl; // count dead cells in row 16
    std::cout << "Total alive in column 10 = " << m.colCount(10) << std::endl; // count alive cells in column 10
    std::cout << "Total dead in column 1 = " << (boolMatrix::NUM_ROWS - m.colCount(1)) << std::endl; // count dead cells in column 1
    std::cout << "Total alive = " << m.totalCount() << std::endl; // count total alive cells in matrix
    std::cout << "Total dead = " << (boolMatrix::NUM_ROWS * boolMatrix::NUM_COLS - m.totalCount()) << std::endl; // count total dead cells in matrix
}


/*
The neighborCount function calculates the number of neighboring cells that are true around a specified cell within a boolean matrix. It begins by validating that the specified row and col indices are within the matrix bounds. The it iterates over the eight potential neighboring positions using a nested loop structure, where the outer loop adjusts the row offset and the inner loop adjusts the column offset. It doesnt look at the cell itself by skipping the case where both offsets are zero. For each neighboring position, the function checks if the position is valid and if the cell at that position is true. If both conditions are met, it increments the count of live neighbors. Then it returns the counnt for the next stage.

In the client code playGameOfLife function (I did not write a determine generations function), the matrix's state progression is managed across multiple generations. It has a temporary boolMatrix to avoid altering the original matrix prematurely. Each cell's fate in the next generations is decided by iterating over every cell, counting its live neighbors, and applying the Game of Life rules whre a live cell survives if it has two or three live neighbors otherwise it dies. ANd a dead cell revives only if it has exactly three live neighbors. After getting the states for all cells in the current generation, these are set in the temporary matrix. Once all calculations for the current generation are complete, the main matrix is updated from the temporary one for the next generation's calculations.*/