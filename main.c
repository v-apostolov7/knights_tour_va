#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define CELL_VISITED 118 // 'v'
#define CELL_KNIGHT  107 // 'k'

static void print_board(int zone[10][10], char knight_char, char visited_char)
{
    int i, j, k;

    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (zone[i][j] == CELL_KNIGHT)
            {
                printf("  %c |", knight_char);
            }
            else if (zone[i][j] == CELL_VISITED)
            {
                printf("  %c |", visited_char);
            }
            else
            {
                printf(" %d |", zone[i][j]);
            }

            if (j == BOARD_SIZE - 1)
            {
                printf("\n");
                for (k = 1; k <= 40; k++)
                {
                    printf("-");
                }
                printf("\n");
            }
        }
    }
}

int main(void)
{
    int i = 0, j = 0, k = 0, g = 0;
    int ii[100], jj[100];
    int zone[10][10];
    int arr[100];
    int choice = 0;
    int check = 0;
    char visited = 'v';
    char knight = 'k';
    int counter = 1;
    int row = 0, column = 0;
    int next[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int least_g = 9;
    int gg = 0;

    /* Initialize board coordinates and valid choices array */
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            zone[i][j] = (i + 1) * 10 + j + 1;
            arr[i * BOARD_SIZE + j] = (i + 1) * 10 + j + 1;
        }
    }

    /* Initial display of numbered board */
    print_board(zone, knight, visited);

    printf("\nThis is the chess board, but the zones are numbered. "
           "The first number is the row, the second number is the column.\n");

    /* Validate starting position */
    while (check == 0)
    {
        printf("\nChoose a valid zone to start: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n'); // clear invalid input
            continue;
        }

        for (k = 0; k < 64; k++)
        {
            if (choice == arr[k])
            {
                check = 1;
                break;
            }
        }
    }

    /* Place knight at starting square */
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (zone[i][j] == choice)
            {
                zone[i][j] = CELL_KNIGHT;
                row = i;
                column = j;
            }
        }
    }

    print_board(zone, knight, visited);

    /* Main Knight's Tour loop using Warnsdorff's heuristic */
    while (counter <= 64)
    {
        k = 0;

        /* Step 1: Find all valid L-shaped knight moves from current square */
        for (i = 0; i < BOARD_SIZE; i++)
        {
            for (j = 0; j < BOARD_SIZE; j++)
            {
                if (abs(row - i) == 1 && abs(column - j) == 2)
                {
                    if (zone[i][j] != CELL_VISITED)
                    {
                        ii[k] = i;
                        jj[k] = j;
                        k++;
                    }
                }
                if (abs(row - i) == 2 && abs(column - j) == 1)
                {
                    if (zone[i][j] != CELL_VISITED)
                    {
                        ii[k] = i;
                        jj[k] = j;
                        k++;
                    }
                }
            }
        }

        /* If no more reachable unvisited squares remain, stop the tour */
        if (k == 0)
        {
            break;
        }

        /* Step 2: Calculate onward accessibility degree for each candidate move */
        for (g = 0; g < k; g++)
        {
            for (i = 0; i < BOARD_SIZE; i++)
            {
                for (j = 0; j < BOARD_SIZE; j++)
                {
                    if (abs(ii[g] - i) == 1 && abs(jj[g] - j) == 2)
                    {
                        if (zone[i][j] != CELL_VISITED)
                        {
                            next[g]++;
                        }
                    }
                    if (abs(ii[g] - i) == 2 && abs(jj[g] - j) == 1)
                    {
                        if (zone[i][j] != CELL_VISITED)
                        {
                            next[g]++;
                        }
                    }
                }
            }

            /* Choose move with the minimal onward options (Warnsdorff's rule) */
            if (next[g] <= least_g)
            {
                least_g = next[g];
                gg = g;
            }
        }

        /* Step 3: Transition state to the chosen next square */
        zone[row][column] = CELL_VISITED;
        zone[ii[gg]][jj[gg]] = CELL_KNIGHT;

        choice = (ii[gg] + 1) * 10 + jj[gg] + 1;
        row = ii[gg];
        column = jj[gg];

        printf("The next zone is %d\n", choice);

        /* Reset counters for the next step */
        least_g = 9;
        gg = 0;
        for (k = 0; k < 8; k++)
        {
            next[k] = 0;
        }

        /* Print updated board state */
        print_board(zone, knight, visited);

        counter++;
    }

    return 0;
}