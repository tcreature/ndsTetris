#include "tetrispieces.h"
#include <stdbool.h>
#include <stdio.h>

tetrisBlock createTetrisBlock(int x, int y, tetrisColor color) {
    tetrisBlock block = {.x = x, .y = y, .color = color};
    return block;
}

void initPiece(tetrisPiece *piece, PIECE_TYPE type) {
    *piece = tetrisPiecesPredefined[type];
}

/*!\brief Rotates a piece about its own pivot
 * \param piece a pointer to the piece to rotate
 * \param ccw whether to rotate counter-clockwise
 */
void rotatePiece(tetrisPiece *piece, bool ccw) {
    int pivot = piece->pivot;
    if(pivot == -1) return; // pivot being -1 indicates no rotation

    int pivotX = piece->blocks[pivot].x;
    int pivotY = piece->blocks[pivot].y;
    for(int i = 0; i < PIECE_BLOCKS; i++) {
        if(i == pivot) continue;
        tetrisBlock *block = &piece->blocks[i];
        int distX = block->x - pivotX;
        int distY = block->y - pivotY;

        int newX, newY;
        if(ccw) {
            newX = pivotX + distY;
            newY = pivotY - distX;
        } else {
            newX = pivotX - distY;
            newY = pivotY + distX;
        }

        block->x = newX;
        block->y = newY;
    }
    printf("rotate\n");

}

/*! \brief Array containing the data of predefined tetris pieces.
 *
 * Intended to be indexed into with the PIECE_TYPE enum. The elements are
 * ordered the same as in the enum.
 */
const tetrisPiece tetrisPiecesPredefined[PIECE_TYPE_MAX] = {
    {.blocks = {{.x = 0, .y = 0}, {.x = 1, .y = 0}, // PIECE_T
                {.x = 2, .y = 0}, {.x = 1, .y = 1}},
                 .pivot = 1},
    {.blocks = {{.x = 0, .y = 0}, {.x = 1, .y = 0}, // PIECE_SQUARE
                {.x = 0, .y = 1}, {.x = 1, .y = 1}},
                 .pivot = -1},
    {.blocks = {{.x = 0, .y = 0}, {.x = 1, .y = 0}, // PIECE_L
                {.x = 2, .y = 0}, {.x = 0, .y = 1}},
                 .pivot = 1},
    {.blocks = {{.x = 0, .y = 0}, {.x = 1, .y = 0}, // PIECE_REVERSE_L
                {.x = 2, .y = 0}, {.x = 2, .y = 1}},
                 .pivot = 1},
    {.blocks = {{.x = 1, .y = 0}, {.x = 2, .y = 0}, // PIECE_S
                {.x = 0, .y = 1}, {.x = 1, .y = 1}},
                 .pivot = 0},
    {.blocks = {{.x = 0, .y = 0}, {.x = 1, .y = 0}, // PIECE_REVSERSE_S
                {.x = 1, .y = 1}, {.x = 2, .y = 1}},
                 .pivot = 1},
    {.blocks = {{.x = 0, .y = 0}, {.x = 1, .y = 0}, // PIECE_LINE
                {.x = 2, .y = 0}, {.x = 3, .y = 0}},
                 .pivot = 1}
};
