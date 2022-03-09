#include <iostream>
#include <ctime>
#define M 7
#define N 7

void initRoom(int room[M][N]){
  for(int i = 0; i < M;i++)
    for(int j = 0; j < N;j++)
      room[i][j]='#';
}
void printRoom(int room[M][N],int posicI,int posicJ){
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if(posicI != i && posicJ != j)
        std::cout << (char)room[i][j] << " ";
      else
        std::cout << "*  ";
    }
      std::cout << '\n';
  }
}
int isRoomFull(int room[M][N]){
  for (int i=0; i<M;i++){
    for(int j=0; j < M; j++){
      if (room[i][j] == 0){
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int room[M][N];
  srand(time(NULL));
  int moves = 0;
  int posicI = rand()%M;
  int posicJ = rand()%N;
  
  while (moves <= 25000 && isRoomFull(room)){
  initRoom(room);
  //printRoom(room,posicI,posicJ);
    do{
      posicI = posicI + rand()%3 - 1;
      posicJ = posicJ + rand()%3 - 1;
    }while(posicI > M-1 && posicJ > N - 1);
    printRoom(room);
    room[posicI][posicJ]++;
    moves++;
  }
  std::cout << (int)moves;
  return 0;
  }