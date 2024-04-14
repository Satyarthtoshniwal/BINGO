#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void winner(int arr[5][5]);
void computer(int rra[5][5]);
int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
int size = 25;
int deletion1(int del[size], int select);
int deletion(int led[size], int choice);
char name[15];
int flag = 0, flag1 = 0, galf = 0, galf1 = 0;
int main()
{
    int i, j, k, num[5][5], player[5][5], temp = 1, un, nu;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            num[i][j] = temp;
            temp++;
        }
    }
    srand(time(0));
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {

            k = rand() % (i + 1);
            temp = num[j][i];
            num[j][i] = num[k][i];
            num[k][i] = temp;
        }
    }
    printf("Enter your name:  ");
    scanf("%s", &name);
    printf("Enter your numbers row wise:\n");
    for (i = 0; i < 5; i++)
    {
        printf("Enter %d row numbers:\n", i + 1);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &player[i][j]);
        }
    }
    printf("Game starts:\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d\t  ", player[i][j]);
        }
        printf("\n\n");
    }
    while (1)
    {
        printf("Your turn Enter a number:\t");
        scanf("%d", &un);
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (player[i][j] == un)
                {
                    player[i][j] = 0;
                }
            }
        }
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (num[i][j] == un)
                {
                    num[i][j] = 0;
                }
            }
        }
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                printf("%d\t  ", player[i][j]);
            }
            printf("\n\n");
        }
        deletion(list, un);
        size--;
        winner(player);
        nu = rand() % size;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (player[i][j] == list[nu])
                {
                    player[i][j] = 0;
                }
            }
        }
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (num[i][j] == list[nu])
                {
                    num[i][j] = 0;
                }
            }
        }
        printf("Computer entered %d\n", list[nu]);
        printf("new chart:\n");
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                printf("%d\t  ", player[i][j]);
            }
            printf("\n\n");
        }
        deletion1(list, nu);
        size--;
        computer(num);
    }
    return 0;
}
void winner(int arr[5][5])
{
    int count = 0, k;
    for (k = 0; k < 5; k++)
    {
        if (arr[k][0] == arr[k][1] && arr[k][1] == arr[k][2] && arr[k][2] == arr[k][3] && arr[k][3] == arr[k][4])
        {
            count++;
        }
    }
    for (k = 0; k < 5; k++)
    {
        if (arr[0][k] == arr[1][k] && arr[1][k] == arr[2][k] && arr[2][k] == arr[3][k] && arr[3][k] == arr[4][k])
        {
            count++;
        }
    }
    for (k = 0; k < 2; k++)
    {
        if (flag == 0)
        {
            if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3] && arr[3][3] == arr[4][4])
            {
                flag++;
            }
        }
        if (flag1 == 0)
        {
            if (arr[0][4] == arr[1][3] && arr[1][3] == arr[2][2] && arr[2][2] == arr[3][1] && arr[3][1] == arr[4][0])
            {
                flag1++;
            }
        }
    }
    if ((count + flag + flag1) >= 5)
    {
        printf("BINGO  %d\n", (count + flag + flag1));
        printf("%s won the match\n", name);
        exit(0);
    }
    else
        printf("BINGO  %d\n", (count + flag + flag1));
}
void computer(int rra[5][5])
{
    int count1 = 0, l;
    for (l = 0; l < 5; l++)
    {
        if (rra[l][0] == rra[l][1] && rra[l][1] == rra[l][2] && rra[l][2] == rra[l][3] && rra[l][3] == rra[l][4])
        {
            count1++;
        }
    }
    for (l = 0; l < 5; l++)
    {
        if (rra[0][l] == rra[1][l] && rra[1][l] == rra[2][l] && rra[2][l] == rra[3][l] && rra[3][l] == rra[4][l])
        {
            count1++;
        }
    }
    for (l = 0; l < 2; l++)
    {
        if (galf == 0)
        {
            if (rra[0][0] == rra[1][1] && rra[1][1] == rra[2][2] && rra[2][2] == rra[3][3] && rra[3][3] == rra[4][4])
            {
                galf++;
            }
        }
        if (galf1 == 0)
        {
            if (rra[0][4] == rra[1][3] && rra[1][3] == rra[2][2] && rra[2][2] == rra[3][1] && rra[3][1] == rra[4][0])
            {
                galf1++;
            }
        }
    }
    if ((count1 + galf + galf1) >= 5)
    {
        printf("Computer Bingo=%d\n", (count1 + galf + galf1));
        printf("%s you loss the match\n", name);
        exit(0);
    }
    else
        printf("Computer Bingo=%d\n", (count1 + galf + galf1));
}
int deletion1(int del[size], int select)
{
    int i;
    for (i = select; i < size; i++)
    {
        del[i] = del[i + 1];
    }
}
int deletion(int led[size], int choice)
{
    int j;
    for (j = 0; j < size; j++)
    {
        if (led[j] == choice)
        {
            led[j] = led[j + 1];
            choice = led[j + 1];
        }
    }
}