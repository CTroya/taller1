#include <ctime>
#include <iostream>
#include <unistd.h>
#define M 7
#define N 7
// LLenamos la matriz de ceros
void initRoom(int room[M][N]) {
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      room[i][j] = 0;
}
// Funcion para printear la matriz
void printRoom(int room[M][N], int posicI, int posicJ) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (posicI == i && posicJ == j)
        std::cout << "* ";
      else
        std::cout << (int)room[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cout << "-  -  -  -  - ";
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

  while (moves <= 25000 && !isRoomFull(room)) {
    //printRoom(room, posicI, posicJ);
    do {
      posicI = posicI + (rand() % 3)- 1;
      posicJ = posicJ + (rand() % 3) - 1;

    } while (posicI > M - 1 || posicJ > N - 1);
    room[posicI][posicJ]++;
    moves++;
    std::cout << "\n" << (int)moves<< '-' << (int)posicI << '|'<< (int)posicJ;
  }
  //std::cout << (int)moves;
  return 0;
}