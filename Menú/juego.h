#define N 500   //Cabecera
#define bloc 4

typedef struct //Declaramos una estructura con los componentes de la base de un teletransportador;
{
    int x,y;//Posiciones del teletransportador;
    char identificador;//Carácter identificador del teletransportador;
}teleporter;

typedef struct //Declaramos una estructura con los componentes de la base de un teletransportador;
{
    int x,y;//Posiciones del bloqueo;
    char identificador;//Carácter identificador del bloqueo;
}bloqueo;

void juego_lab(void);    //Se define la función del laberinto

void reiniciar(int a,int b, int f1, int f2, int anch, int alt, char m, char n, char p,int x,int y,teleporter t1,teleporter t2,bloqueo b1[],int T1,int T2,int B1[],int si,int sj, int maze[N][N], char lab[N][N]);
//Rehacemos el laberinto completamente con la cruceta en el inicio de la semilla.

void construir(int a,int b, int f1, int f2, int anch, int alt, char m, char n, char p,int x,int y,teleporter t1,teleporter t2,bloqueo b1[],int si,int sj, int maze[N][N], char lab[N][N]);
//Funcion para replicar el laberinto unja vez movida la cruceta.
//Creación de bloqueos mediante un vector de estructuras y creación del teleportador.
//Primero crea un patr�n de direcciones aleatorio, luego con esa direcci�n comprueba si se puede.
//Si no puede, pasa a otra direcci�n hasta que una se pueda, y marca esas casillas como camino.
//Una vez creado el camino vuelve a repetirse todo el proceso.


void recursion(int r, int c, int anch, int alt, int maze[N][N], char n);
