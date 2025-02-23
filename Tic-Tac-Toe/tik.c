// Tic-Tac-Toe

#include <stdio.h>

int main()
{

    char arr[3][3];
    int row, col, draw = 0;

    printf("\n A[0][0]='X' A[0][1]='O' A[0][2]='X'  X     O     X    ");
    printf("\n A[1][0]='O' A[1][1]='X' A[1][2]='O'  O     X     O    ");
    printf("\n A[2][0]='X' A[2][1]='O' A[2][2]='X'  X     O     X    ");

    for (int i = 0; i < 9; i++)
    {

        i == 0 || i % 2 == 0 ? printf("\nuser 1 : ") : printf("\nuser 2 : ");

        printf("\nrow(0-2) : ");
        scanf("%d", &row);

        printf("\ncol(0-2) : ");
        scanf("%d", &col);

        if (i == 0 || i % 2 == 0)
        {
            arr[row][col] = 'x';

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%c ", arr[i][j]);
                }
                printf("\n");
            }

            draw++;
        }

        else
        {
            arr[row][col] = 'o';

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%c ", arr[i][j]);
                }
                printf("\n");
            }
            draw++;
        }

        if (draw == 9)
        {
            printf("\nGame Draw");
        }
        else if (arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == 'x' || arr[0][0] == 'o' && arr[1][1] == 'o' && arr[2][2] == 'o')
        {
            i == 0 || i % 2 == 0 ? printf("\nuser 1 won: ") : printf("\nuser 2 won: ");
            break;
        }

        else if (arr[0][2] == 'x' && arr[1][1] == 'x' && arr[2][0] == 'x' || arr[0][2] == 'o' && arr[1][1] == 'o' && arr[2][0] == 'o')
        {
            i == 0 || i % 2 == 0 ? printf("\nuser 1 won: ") : printf("\nuser 2 won: ");
            break;
        }

        else if (arr[0][0] == 'x' && arr[1][0] == 'x' && arr[2][0] == 'x' || arr[0][0] == 'o' && arr[1][0] == 'o' && arr[2][0] == 'o')
        {
            i == 0 || i % 2 == 0 ? printf("\nuser 1 won: ") : printf("\nuser 2 won: ");
            break;
        }

        else if (arr[0][1] == 'x' && arr[1][1] == 'x' && arr[2][1] == 'x' || arr[0][1] == 'o' && arr[1][1] == 'o' && arr[2][1] == 'o')
        {
            i == 0 || i % 2 == 0 ? printf("\nuser 1 won: ") : printf("\nuser 2 won: ");
            break;
        }

        else if (arr[0][2] == 'x' && arr[1][2] == 'x' && arr[2][2] == 'x' || arr[0][2] == 'o' && arr[1][2] == 'o' && arr[2][2] == 'o')
        {
            i == 0 || i % 2 == 0 ? printf("\nuser 1 won: ") : printf("\nuser 2 won: ");
            break;
        }

        else if (arr[0][0] == 'x' && arr[0][1] == 'x' && arr[0][2] == 'x' || arr[0][0] == 'o' && arr[0][1] == 'o' && arr[0][2] == 'o')
        {
            i == 0 || i % 2 == 0 ? printf("\nuser 1 won: ") : printf("\nuser 2 won: ");
            break;
        }

        else if (arr[1][0] == 'x' && arr[1][1] == 'x' && arr[1][2] == 'x' || arr[1][0] == 'o' && arr[1][1] == 'o' && arr[1][2] == 'o')
        {
            i == 0 || i % 2 == 0 ? printf("\nuser 1 won: ") : printf("\nuser 2 won: ");
            break;
        }

        else if (arr[2][0] == 'x' && arr[2][1] == 'x' && arr[2][2] == 'x' || arr[2][0] == 'o' && arr[2][1] == 'o' && arr[2][2] == 'o')
        {
            i == 0 || i % 2 == 0 ? printf("\nuser 1 won: ") : printf("\nuser 2 won: ");
            break;
        }
    }

    return 0;
}
