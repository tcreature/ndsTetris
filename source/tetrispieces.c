#include "tetrispieces.h"
#include <stdbool.h>
#include <stdio.h>

tetrisBlock createTetrisBlock(int x, int y, tetrisColor color) {
    tetrisBlock block = {.x = x, .y = y, .color = color};
    return block;
}

/*!\brief Rotates a piece about its own pivot
 * \param piece a pointer to the piece to rotate
 * \param ccw whether to rotate counter-clockwise
 */
void rotatePiece(tetrisPiece *piece, bool ccw) {
    int pivot = piece->pivot;
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

const tetrisPiece tetrisPiece_T = {.blocks = {{.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 2, .y = 1}},
                                   .pivot = 2};
