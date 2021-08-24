#ifndef TETRISGAME_H
#define TETRISGAME_H

#define ARM9
#include <nds.h>
#include "tetrisstatetype.h"
#include "tetrispieces.h"

typedef struct tetrisGameState {
    STATE_TYPE stateType;
    unsigned int frame;
    STATE_TYPE (*update)(struct tetrisGameState *state);

    tetrisPiece playerPiece;
    tetrisPiece nextPiece;
} tetrisGameState;

/*!\brief Initializes the game state machine in STATE_TITLE. */
void initGameState(tetrisGameState *state);
STATE_TYPE updateTitle(tetrisGameState *state);
/*!\brief Performs the needed setup when initially switching to STATE_GAME. */
void initGame(tetrisGameState *state);
STATE_TYPE updateGame(tetrisGameState *state);

#endif
