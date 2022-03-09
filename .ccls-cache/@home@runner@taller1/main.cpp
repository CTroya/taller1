#include <ctime>
#include <iostream>

class bichoCuarto {

public:
  int moves[8][2]= {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
  int M = 1;
  int N = 1;
  int **room;

  int **create() {
    room = new int *[M];
    for (int i = 0; i < N; i++) {
      room[i] = new int[N];
    }
    return room;
  }
  int aleatorio(int limite_superior, int limite_inferior) {
    srand(time(NULL));
    return limite_inferior + rand() % (limite_superior + 1 - limite_inferior);
  }
  // LLenamos la matriz de ceros
  void initRoom(int **room) {
    for (int i = 0; i < M; i++)
      for (int j = 0; j < N; j++)
        room[i][j] = 0;
  }
  // Funcion para printear la matriz
  void printRoom(int **room, int posicI, int posicJ) {
    for (int i = 0; i < M; i++) {
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
  int isFull(int **room) {
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        if (room[i][j] == 0) {
          return 0;
        }
      }
    }
    return 1;
  }
};

int main() {
  bichoCuarto room;
  int k;
  do {
    std::cout << "Inserte el numero de filas: ";
    std::cin >> room.M;
    std::cout << "Inserte el numero de columnas: ";
    std::cin >> room.N;
  } while (room.M<= 2 || room.M >= 41|| room.N >= 2 || room.N >= 21);
  room.create();
  room.initRoom(room.room);
  srand(time(NULL));
  int moves = 0;
  int posicI = rand() % room.M;
  int posicJ = rand() % room.N;
  int candidateI;
  int candidateJ;
  if (room.M == 15 && room.N == 15) {
    posicI = 10;
    posicJ = 10;
  } else if (room.M == 40 && room.N == 20) {
    posicI = 1;
    posicJ = 1;
  }
  room.printRoom(room.room, posicI, posicJ);
  do {
    // printRoom(room, posicI, posicJ);
    do {
      candidateI = posicI + moves[];
      candidateJ = posicJ;
    } while (candidateI > room.M - 1 || candidateJ > room.N - 1 ||
             candidateI < 0 || candidateJ < 0);
    posicI = candidateI;
    posicJ = candidateJ;
    room.room[posicI][posicJ]++;
    moves++;
    if (moves % 100 == 0)
      room.printRoom(room.room, posicI, posicJ);
    // std::cout << "\n" << (int)moves << '|' << (int)posicI << '|' <<
    // (int)posicJ; printRoom(room, posicI, posicJ);
  } while (moves < 25000 && !room.isFull(room.room));
  room.printRoom(room.room, posicI, posicJ);
  if (room.isFull(room.room)) {
    std::cout << "El CR7 recorrio el cuarto en " << (int)moves
              << " pasos \n SIUUUUUUUUUUUU";
  } else {
    std::cout << "El CR7 no recorrio el cuarto en " << (int)moves
              << " pasos \n SIUUUUUUUUUUUU";
  }
  return 0;
}