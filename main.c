#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(char table[]);
void firstMove(char *table, char player, char pc);
void secondMove(char *table, char player, char pc);
bool checkWinner(char table[], char player, char pc);
bool checkDraw(char table[]);

int main() {
    srand(time(NULL));

    char table[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player, pc;

    if(rand() % 2) {
        player = 'O';
        pc = 'X';
    } else {
        player = 'X';
        pc = 'O';
    }

    printf("You are playing as \"%c\"\n", player);

    while(true) {
        drawBoard(table);
        if(checkWinner(table, player, pc)) {
            break;
        } else if(checkDraw(table)) {
            break;
        }
        firstMove(table, player, pc);
        drawBoard(table);
        if(checkWinner(table, player, pc)) {
            break;
        } else if(checkDraw(table)) {
            break;
        }
        secondMove(table, player, pc);
    }

    return 0;
}

void drawBoard(char table[]) {
    printf("\n  %c  |  %c  |  %c  \n", table[0], table[1], table[2]);
    printf("_____|_____|_____\n");
    printf("  %c  |  %c  |  %c  \n", table[3], table[4], table[5]);
    printf("_____|_____|_____\n");
    printf("  %c  |  %c  |  %c  \n", table[6], table[7], table[8]);
    printf("     |     |     \n\n");
}

void firstMove(char *table, char player, char pc) {
    if(player == 'X') {
        int tile;
        do {
            printf("Enter a tile to mark with your character: ");
            scanf("%d", &tile);
        } while(table[tile - 1] != ' ');

        table[tile - 1] = player;
    } else {
        int tile;
        do {
            tile = rand() % 9 + 1;
        } while(table[tile - 1] != ' ');

        table[tile - 1] = pc;
    }
}

void secondMove(char *table, char player, char pc) {
    if(player == 'O') {
        int tile;
        do {
            printf("Enter a tile to mark with your character: ");
            scanf("%d", &tile);
        } while(table[tile - 1] != ' ');

        table[tile - 1] = player;
    } else {
        int tile;
        do {
            tile = rand() % 9 + 1;
        } while(table[tile - 1] != ' ');

        table[tile - 1] = pc;
    }
}

bool checkWinner(char table[], char player, char pc) {
    char isWinner = 'C';
    if(table[0] == table[1] && table[0] == table[2]) {
        if(table[0] == player) {
            isWinner = 'Y';
        } else if(table[0] == pc) {
            isWinner = 'N';
        }
    } else if(table[3] == table[4] && table[3] == table[5]) {
        if(table[3] == player) {
            isWinner = 'Y';
        } else if(table[3] == pc) {
            isWinner = 'N';
        }
    } else if(table[6] == table[7] && table[6] == table[8]) {
        if(table[6] == player) {
            isWinner = 'Y';
        } else if(table[6] == pc) {
            isWinner = 'N';
        }
    } else if(table[0] == table[3] && table[0] == table[6]) {
        if(table[0] == player) {
            isWinner = 'Y';
        } else if(table[0] == pc) {
            isWinner = 'N';
        }
    } else if(table[1] == table[4] && table[1] == table[7]) {
        if(table[1] == player) {
            isWinner = 'Y';
        } else if(table[1] == pc) {
            isWinner = 'N';
        }
    } else if(table[2] == table[5] && table[2] == table[8]) {
        if(table[2] == player) {
            isWinner = 'Y';
        } else if(table[2] == pc) {
            isWinner = 'N';
        }
    } else if(table[0] == table[4] && table[0] == table[8]) {
        if(table[0] == player) {
            isWinner = 'Y';
        } else if(table[0] == pc) {
            isWinner = 'N';
        }
    } else if(table[2] == table[4] && table[2] == table[6]) {
        if(table[2] == player) {
            isWinner = 'Y';
        } else if(table[2] == pc) {
            isWinner = 'N';
        }
    }

    if(isWinner == 'Y') {
        printf("YOU WON!!!\n");
        return true;
    } else if(isWinner == 'N') {
        printf("YOU LOSE!!!\n");
        return true;
    } else {
        return false;
    }
}

bool checkDraw(char table[]) {
    for(int i = 0; i < 9; i++) {
        if(table[i] == ' ') {
            return false;
        }
    }
    
    printf("DRAW!!!\n");
    return true;
}