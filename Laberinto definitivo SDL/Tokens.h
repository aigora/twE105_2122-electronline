#define N 100

typedef struct{   //Se define otra vez la misma estructura pero con otro nombre ya que estamos en otra librería .h
    int x;
    int y;
} Tokenn;

void InitTokens(int maze[N][N]);
void TLuna(int coordx, int coordy, Tokenn Luna[2], int *inversion);
void TSol(int coordx, int coordy, Tokenn Sol[2], int *inversion);
void TP(int coordx, int coordy, Tokenn Teleport[2], int *teletransportar, int *x_pos, int *y_pos);
