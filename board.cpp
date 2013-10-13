#include "board.h"
#include <stdlib.h>

Board::Board(unsigned boardSize, unsigned colorsCount):
    _boardSize(boardSize),
    _board(HEXAGON_BOARD_TYPE(boardSize, HEXAGON_LINE_TYPE(boardSize, HEXAGON_CELL(3, 0)))),
    _colorsCount(colorsCount)
{
}

unsigned Board::GetSize() const
{
    return _boardSize;
}

Board::HEXAGON_BOARD_TYPE& Board::GetData()
{
    return _board;
}

void Board::RandomFill()
{
    for (unsigned i = 0; i < _board.size(); i++)
    {
        for (unsigned j = 0; j < _board.size(); j++)
        {
            for (unsigned k = 0; k < 3; k++)
            {
                _board[i][j][k] = rand() % _colorsCount + 1;
            }
        }
    }
}
