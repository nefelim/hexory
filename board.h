#ifndef BOARD_H
#define BOARD_H
#include <vector>

class Board
{
public:
    typedef std::vector<int> HEXAGON_CELL;
    typedef std::vector<HEXAGON_CELL> HEXAGON_LINE_TYPE;
    typedef std::vector<HEXAGON_LINE_TYPE> HEXAGON_BOARD_TYPE;

    Board(unsigned boardSize, unsigned colorsCount);
    unsigned GetSize() const;
    HEXAGON_BOARD_TYPE& GetData();
    unsigned GetColorsCount() const;
    void RandomFill();
private:
    unsigned _boardSize;
    HEXAGON_BOARD_TYPE _board;
    unsigned _colorsCount;
};

#endif // BOARD_H
