#include "Board.h"

Board::Board() : grid(SIZE, std::vector<char>(SIZE, '-')) {}

void Board::placeQueen(int row, int col)
{
    grid[row][col] = 'Q';
}

void Board::removeQueen(int row, int col)
{
    grid[row][col] = '-';
}

bool Board::isSafe(int row, int col) const
{
    for (int i = 0; i < col; i++)
        if (grid[row][i] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (grid[i][j] == 'Q')
            return false;

    for (int i = row, j = col; i < SIZE && j >= 0; i++, j--)
        if (grid[i][j] == 'Q')
            return false;

    return true;
}

void Board::display() const
{
    for (const auto &row : grid)
    {
        for (char cell : row)
            std::cout << cell << " ";
        std::cout << std::endl;
    }
}