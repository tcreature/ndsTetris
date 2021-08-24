#include <stdio.h>
#include "tetrisgame.h"
#include "tetrisgraphics.h"
#include "tetrispieces.h"

/*!\brief Initializes the game state machine in STATE_TITLE
 */
void initGameState(tetrisGameState *state) {
    state->stateType = STATE_TITLE;
    state->frame = 1;
    state->update = &updateTitle;
}

void switchState(tetrisGameState *state, STATE_TYPE newType) {
    state->stateType = newType;
    switch(newType) {
        case STATE_GAME:
            initGame(state);
            state->update = &updateGame;
            break;
    }
}

STATE_TYPE updateTitle(tetrisGameState *state) {
    state->frame++;

    scanKeys();
    int keys = keysDown();
    if(keys & KEY_START)
        switchState(state, STATE_GAME);

    return state->stateType;
}

/*!\brief Performs the needed setup when initially switching to STATE_GAME.
 */
void initGame(tetrisGameState *state) {
    // test
    for(int i = 0; i < PIECE_BLOCKS; i++) {
        state->playerPiece = tetrisPiece_T;
        printf("%x\n", &state->playerPiece.blocks[0]);
    }
}

STATE_TYPE updateGame(tetrisGameState *state) {
    state->frame++;

    scanKeys();
    int keys = keysDown();
    if(keys & KEY_A)
        rotatePiece(&state->playerPiece, false);
    if(keys & KEY_B)
        rotatePiece(&state->playerPiece, true);

    return state->stateType;
}
