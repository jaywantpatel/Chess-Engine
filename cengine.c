#include "stdio.h"
#include "stdlib.h"
#include "defs.h"

int main() {

    AllInit();

    S_BOARD board[1];
    S_MOVELIST list[1];

    ParseFen(START_FEN, board);
    GenerateAllMoves(board, list);
    
    int MoveNum = 0;
    int move = 0;
    
    PrintBoard(board);
    getchar();

    for (MoveNum = 0; MoveNum < list->count; MoveNum++) {
        move = list->moves[MoveNum].move;

        if (!MakeMove(board, move)) {
            continue;
        }

        printf("\nMADE: %s\n", PrMove(move));
        PrintBoard(board);

        TakeMove(board);
        printf("\nTAKEN: %s\n", PrMove(move));
        PrintBoard(board);

        getchar();
    }

    return 0;
}