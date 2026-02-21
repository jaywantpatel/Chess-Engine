#include "stdio.h"
#include "stdlib.h"
#include "defs.h"

#define PAWNMOVESW "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1"
#define PAWNMOVESB "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1"

int main() {

    AllInit();

   S_BOARD board[1];

   ParseFen(PAWNMOVESW, board);
   PrintBoard(board);

   S_MOVELIST list[1];
   GenerateAllMoves(board, list);
   PrintMoveList(list);


    return 0;
}