#define ARM9

#include <stdio.h>
#include <nds.h>
#include "tetrisgraphics.h"
#include "tetrisgame.h"

int main(void) {

    // Game state init
    tetrisGameState gameState;
    initGameState(&gameState);

    // DS graphics init
    tetrisGfxState gfxState;
    initGraphicsState(&gfxState, &gameState);

    while(1) {
        STATE_TYPE currentType = gameState.stateType;
        if(gameState.update(&gameState) != currentType) {
            currentType = gameState.stateType;
            switchGraphicsState(&gfxState, currentType);
        }
        gfxState.draw(&gfxState);
    }

    return 0;
}
