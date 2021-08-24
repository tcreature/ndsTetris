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

typedef enum tetrisPieceType {
    T_PIECE,
    SQUARE_PIECE,
    L_PIECE,
    REVERSE_L_PIECE,
    S_PIECE,
    REVERSE_S_PIECE,
    LINE_PIECE
} tetrisPieceType;

/*! \brief Struct to represent a tetris piece consisting of 4 blocks.
 */
#define PIECE_BLOCKS 4
typedef struct tetrisPiece {
    tetrisBlock blocks[PIECE_BLOCKS];
    int pivot; // index into blocks array indicating
               // which block will be the center of rotation.
} tetrisPiece;

/*!\brief Rotates a piece about its own pivot
 * \param piece a pointer to the piece to rotate
 * \param ccw whether to rotate counter-clockwise
 */
void rotatePiece(tetrisPiece *piece, bool ccw);

// Pre-defined pieces
extern const tetrisPiece tetrisPiece_T;
extern const tetrisPiece tetrisPiece_SQUARE;
extern const tetrisPiece tetrisPiece_L;
extern const tetrisPiece tetrisPiece_REVERSE_L;
extern const tetrisPiece tetrisPiece_S;
extern const tetrisPiece tetrisPiece_REVERSE_S;
extern const tetrisPiece tetrisPiece_LINE;

#endif
