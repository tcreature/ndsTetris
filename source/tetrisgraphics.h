#ifndef TETRISGRAPHICS_H
#define TETRISGRAPHICS_H

#define ARM9
#include <nds.h>
#include "tetrisstatetype.h"

typedef struct tetrisGameState tetrisGameState;

typedef struct tetrisGfxState {
    const tetrisGameState *gameState;
    int mainBgId, boardBgId, blocksBgId;
    u16 *spriteGfx;
    PrintConsole* console;
    void (*draw)(struct tetrisGfxState*);
} tetrisGfxState;

/*!\brief Performs DS specific graphics initialization and starts the graphics
 * state machine in STATE_TITLE.
 */
void initGraphicsState(tetrisGfxState *gfxState, const tetrisGameState *gameState);
void switchGraphicsState(tetrisGfxState *gfxState, STATE_TYPE newType);
void drawTitlesScreen(tetrisGfxState *gfxState);
void drawGame(tetrisGfxState *gfxState);

#endif
