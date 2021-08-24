#ifndef TETRISPIECES_H
#define TETRISPIECES_H

#include <stdbool.h>

/*! \brief Enum to represent colors for blocks
 */
typedef enum tetrisColor {
    RED,
    BLUE,
    GREEN
} tetrisColor;

/*! \brief Struct to represent an individual block on the tetris board.
 *
 *  Block coordinates start with (0,0) representing the top left corner of the tetris board.
 */
typedef struct tetrisBlock {
    int x, y;
    tetrisColor color;
} tetrisBlock;

/*!\brief Creates a tetris block instance.
 * \param x the x coordinate
 * \param y the y coordinate
 * \param color the color
 * \return the new block
 */
tetrisBlock createTetrisBlock(int x, int y, tetrisColor color);

typedef enum PIECE_TYPE {
    PIECE_T= 0,
    PIECE_SQUARE,
    PIECE_L,
    PIECE_REVERSE_L,
    PIECE_S,
    PIECE_REVERSE_S,
    PIECE_LINE,
    PIECE_TYPE_MAX
} PIECE_TYPE;

/*! \brief Struct to represent a tetris piece consisting of 4 blocks.
 */
#define PIECE_BLOCKS 4
typedef struct tetrisPiece {
    tetrisBlock blocks[PIECE_BLOCKS];
    int pivot; // index into blocks array indicating
               // which block will be the center of rotation.
               // Set it to -1 to indicate the piece should not be
               // rotated (as for square pieces).
} tetrisPiece;

// Pre-defined pieces
extern const tetrisPiece tetrisPiecesPredefined[PIECE_TYPE_MAX];

void initPiece(tetrisPiece *piece, PIECE_TYPE type);

/*!\brief Rotates a piece about its own pivot
 * \param piece a pointer to the piece to rotate
 * \param ccw whether to rotate counter-clockwise
 */
void rotatePiece(tetrisPiece *piece, bool ccw);

#endif
