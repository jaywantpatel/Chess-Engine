#include "stdio.h"
#include "stdlib.h"
#include "defs.h"

#define TRICK_FEN "n1n5/PPPk4/8/8/8/8/4Kppp/5N1N w - - 0 1"

int main() {

    AllInit();

    S_BOARD board[1];
    board->PvTable->pTable = (S_PVENTRY *) NULL;
    S_MOVELIST list[1];
    S_SEARCHINFO info[1];
    ParseFen(START_FEN, board);
    //PerftTest(3, board);
    
    char input[6];
    int Move = NOMOVE;
    int PvNum = 0;
    int Max = 0;

    while (TRUE){
        PrintBoard(board);
        printf("Enter move: ");
        fgets(input, 6, stdin);

        if(input[0] == 'q') {
            break;
        } else if(input[0] == 't') {
            TakeMove(board);
        } else if(input[0] == 's') {
            info->depth = 4;
            SearchPosition(board, info);
        } else {
            Move = ParseMove(input, board);
            if(Move != NOMOVE) {
                StorePvMove(board, Move);
                MakeMove(board, Move);
                /*if(IsRepetition(board)) {
                    printf("Position has occurred before!\n");
                }*/
            } else {
                printf("Move is not valid: %s\n", input);
            }
        }

        fflush(stdin);
    }
    

    return 0;
}