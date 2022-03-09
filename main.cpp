#include <ctime>
#include <iostream>
#define M 7
#define N 7
int aleatorio(int limite_superior, int limite_inferior) {
    srand(time(NULL));
    return limite_inferior + rand() % (limite_superior + 1 - limite_inferior);
}
// LLenamos la matriz de ceros
void initRoom(int room[M][N]) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            room[i][j] = 0;
}
// Funcion para printear la matriz
void printRoom(int room[M][N], int posicI, int posicJ) {
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++) {
            if (posicI == i && posicJ == j)
                std::cout << "* ";
            else
                std::cout << (int)room[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << "-  -  -  -  - \n";
}
int isRoomFull(int room[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (room[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int room[M][N];
    initRoom(room);
    srand(time(NULL));
    int moves = 0;
    int posicI = rand() % M;
    int posicJ = rand() % N;
    int candidateI;
    int candidateJ;
    printRoom(room, posicI, posicJ);
    do{
        //printRoom(room, posicI, posicJ);
        do {
            candidateI = posicI + rand()%3 -1;
            candidateJ = posicJ + rand()%3 -1;
        } while (candidateI > M -1|| candidateJ > N-1);
        posicI = candidateI;
        posicJ = candidateJ;
        room[posicI][posicJ]++;
        moves++;
        //std::cout << "\n" << (int)moves << '|' << (int)posicI << '|' << (int)posicJ;
        //printRoom(room, posicI, posicJ);
    }while (moves < 25000 && !isRoomFull(room));
    printRoom(room, posicI, posicJ);
    std::cout << (int)moves;
    return 0;
}