#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

void playGame(int player1_choice, int player2_choice) {
    if (player1_choice == player2_choice) {
        printf("Game result: Draw\n");
    } else if (
        (player1_choice == ROCK && player2_choice == SCISSORS) ||
        (player1_choice == PAPER && player2_choice == ROCK) ||
        (player1_choice == SCISSORS && player2_choice == PAPER)
    ) {
        printf("Game result: Player 1 wins\n");
    } else {
        printf("Game result: Player 2 wins\n");
    }
}

int main() {
    int numGames;
    printf("Enter the number of games: ");
    scanf("%d", &numGames);

    int player1_choice, player2_choice;
    int player1_wins = 0, player2_wins = 0;

    for (int i = 0; i < numGames; i++) {
        printf("\nGame %d\n", i+1);
        printf("Enter Player 1's choice (0=Rock, 1=Paper, 2=Scissors): ");
        scanf("%d", &player1_choice);
        printf("Enter Player 2's choice (0=Rock, 1=Paper, 2=Scissors): ");
        scanf("%d", &player2_choice);

        int pipefd[2];
        
        pipe(pipefd);

        pid_t pid1, pid2;
        pid1 = fork();

        if (pid1 == 0) {
            close(pipefd[0]); 

            write(pipefd[1], &player1_choice, sizeof(int));

            close(pipefd[1]);
        } else {
            pid2 = fork();

            if (pid2 == 0) {
                close(pipefd[0]); 

                write(pipefd[1], &player2_choice, sizeof(int));

                close(pipefd[1]); 
                
            } else {
                close(pipefd[1]);

                int received_choice;

                read(pipefd[0], &received_choice, sizeof(int));
                player1_choice = received_choice;

                read(pipefd[0], &received_choice, sizeof(int));
                player2_choice = received_choice;

                close(pipefd[0]); 

                playGame(player1_choice, player2_choice);

               
                if (player1_choice != player2_choice) {
                    if (
                        (player1_choice == ROCK && player2_choice == SCISSORS) ||
                        (player1_choice == PAPER && player2_choice == ROCK) ||
                        (player1_choice == SCISSORS && player2_choice == PAPER)
                    ) 
                    {
                        player1_wins++;
                    } 
                    else 
                    {
                        player2_wins++;
                    }
                }
               }
              }
             }
            }        

