#define N 100
typedef struct{   //Se define otra vez la misma estructura pero con otro nombre ya que estamos en otra librer�a .h
    int x;
    int y;
} Tokenn;

void InitTokens(int maze[N][N]);//Funci�n para iniciar los tokens del laberinto
void TLuna(int coordx, int coordy, Tokenn Luna[2], int *inversion);//Funci�n para los tokens de tipo luna
void TSol(int coordx, int coordy, Tokenn Sol[2], int *inversion);//Funci�n para los tokens de tipo sol
void TP(int coordx, int coordy, Tokenn Teleport[2], int *teletransportar, int *x_pos, int *y_pos);// Funci�n para TP
