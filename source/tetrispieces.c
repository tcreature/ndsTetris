#include "tetrispieces.h"
#include <stdbool.h>

tetrisBlock createTetrisBlock(int x, int y, tetrisColor color) {
    tetrisBlock block = {.x = x, .y = y, .color = color};
    return block;
}

/*!\brief Rotates a piece about its own pivot
 * \param piece a pointer to the piece to rotate
 * \param ccw whether to rotate counter-clockwise
 */
void rotatePiece(tetrisPiece *piece, bool ccw) {
    for(int i = 0; i < PIECE_BLOCKS; i++) {
        // TODO
    }
}

const tetrisPiece tetrisPiece_T = {.blocks = {{.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 2, .y = 1}},
                                   .pivot = 2};
