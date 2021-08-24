#define ARM9
#include <stdio.h>
#include <nds.h>
#include "tetrisgraphics.h"
#include "tetrisgame.h"
#include "tileset.h"
#include "mainbg.h"
#include "boardbg.h"
#include "titlescreenbg.h"
#include "tetrisboard.h"

/*!\brief The size of an individual block in pixels */
#define BLOCK_SIZE 8
/*!\brief The pixel coordinates of the top left of the playable board area */
#define BOARD_ORIGIN_X ((SCREEN_WIDTH / 2) - ((BLOCK_SIZE * BOARD_WIDTH) / 2))
#define BOARD_ORIGIN_Y (BLOCK_SIZE * 2)

/*!\brief Translates a coordinate of a block to a pixel coordinate.
 *
 * For example, a block with coordinates (2,1) will be translated to (16,8)
 * assuming the BLOCK_SIZE is 8 pixels. */
#define blockToScreen(n) (BLOCK_SIZE * n)

/*!\brief Performs DS specific graphics initialization and starts the graphics
 * state machine in STATE_TITLE.
 */
void initGraphicsState(tetrisGfxState *gfxState, const tetrisGameState *gameState) {
    gfxState->gameState = gameState; // obviously we need a pointer to the game state to draw relevant things
    gfxState->console = consoleDemoInit();
    gfxState->draw = &drawTitlesScreen;
    videoSetMode(MODE_0_2D);
    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
    vramSetBankB(VRAM_B_MAIN_SPRITE);

    // Backgrounds
    gfxState->mainBgId = bgInit(2, BgType_Text8bpp, BgSize_T_256x256, 0, 1);
    gfxState->boardBgId = bgInit(1, BgType_Text8bpp, BgSize_T_256x256, 1, 1);
    gfxState->blocksBgId = bgInit(0, BgType_Text8bpp, BgSize_T_256x256, 2, 1);

    dmaCopy(tilesetPal, BG_PALETTE, tilesetPalLen);
    dmaCopy(tilesetTiles, bgGetGfxPtr(gfxState->mainBgId), tilesetTilesLen);
    dmaCopy(titlescreenbgMap, bgGetMapPtr(gfxState->mainBgId), titlescreenbgMapLen);

}

/*!\brief Performs the needed setup when initially switching to STATE_GAME.
 */
void initGameGfx(tetrisGfxState *gfxState) {
    // Backgrounds
    dmaCopy(mainbgMap, bgGetMapPtr(gfxState->mainBgId), mainbgMapLen);
    dmaCopy(boardbgMap, bgGetMapPtr(gfxState->boardBgId), boardbgMapLen);

    // Sprites
    oamInit(&oamMain, SpriteMapping_1D_32, false);
    gfxState->spriteGfx = oamAllocateGfx(&oamMain, SpriteSize_8x8, SpriteColorFormat_256Color);
    dmaCopy(tilesetPal, SPRITE_PALETTE, tilesetPalLen);
    dmaCopy(&tilesetTiles[16], gfxState->spriteGfx, tilesetTilesLen);
    // Set up sprite OAM for the 4 player blocks
    for(int i = 0; i < PIECE_BLOCKS; i++) {
        tetrisBlock block = gfxState->gameState->playerPiece.blocks[i];
        int transformedBlockX = BOARD_ORIGIN_X + blockToScreen(block.x);
        int transformedBlockY = BOARD_ORIGIN_Y + blockToScreen(block.y);
        oamSet(&oamMain, i, transformedBlockX, transformedBlockY, 0, 0, SpriteSize_8x8, SpriteColorFormat_256Color, gfxState->spriteGfx, 0, false, false, false, false, false);
    }
}

/*!\brief draw() function for STATE_GAME.
 */
void drawGame(tetrisGfxState *gfxState) {
    swiWaitForVBlank();
    oamUpdate(&oamMain);
    bgUpdate();
    //printf("Drawing game\n");
}

/*!\brief draw() function for STATE_TITLE.
 */
void drawTitlesScreen(tetrisGfxState *gfxState) {
    swiWaitForVBlank();
    //printf("Drawing title screen\n");
}

/*!\brief Switches the graphics state machine to the specified type
 */
void switchGraphicsState(tetrisGfxState *gfxState, STATE_TYPE newType) {
    switch(newType) {
        case STATE_GAME:
            initGameGfx(gfxState);
            gfxState->draw = &drawGame;
            break;
    }
}
