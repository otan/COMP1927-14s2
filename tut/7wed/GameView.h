// GameView.h ... Interface for GameViewADT
// Tutorial Group:
// Date:
// Version:
 
typedef struct gameView *GameView;
 
// Build a new Game view to summarise the current state of the game.
GameView newGameView (char *pastPlays, playerMessage messages[]);
 
// Frees all memory previously allocated for the GameView toBeDeleted.
void disposeGameView (GameView toBeDeleted);

typedef int LocationID;
typedef int PlayerID;

LocationID getPosition(GameView gv, PlayerID player);
int getTurnNumber(GameView gv);
int getScore(GameView gv);
int getHP(GameView gv, PlayerID player);

void getDraculaTrail(GameView gv, char *trail);

int getConnectingVertices(GameView gv, Vertex from, LocationID *locations);
