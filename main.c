#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


struct snake
{
    int x;
    int y;
    char z;
    char zz;
};

void game_field(int rp, char t[rp][rp]);
void gameplay(char* r, int rp, char tab[rp][rp], struct snake s[300]);
void wypelnij(int rp, char t[rp][rp], struct snake s[300]);
void points(int rp, char[rp][rp]);
void border(int rp, char t[rp][rp]);
void movement(int rp, char tab[rp][rp], struct snake s[300], int *min, int *min_x, int *min_y, int i);

int main()
{
    int rp = 2, licznik = 0;



    printf("Podaj rozmiar pola(liczba nieparzysta): ");
    while (rp % 2 == 0)
        scanf("%d", &rp);


    char pole[rp][rp], ruch;
    struct snake s[300];

    wypelnij(rp, pole, s);
    points(rp, pole);
    gameplay(&ruch, rp, pole, s);

    printf("\nWspolrzedne wszystkich zebranych punktow: ");
    for (int z = 0; z < rp; z++)
        printf("\n%d %d", s[z].x, s[z].y);

}

void game_field(int rp, char t[rp][rp])
{
    border(rp, t);
    for (int i = 0; i < rp; i++)
    {
        for (int g = 0; g < rp; g++)
        {
            printf("%c", t[i][g]);
        }
        printf("\n");
    }
}

void gameplay(char* r, int rp, char tab[rp][rp], struct snake s[300])
{

    int x = 1, y = (rp / 2), punkty = 0, min = 0, min_x, min_y;

     tab[5][2] = '*';
     tab[5][3] = '*';
     

    s[0].x = x;
    s[0].y = y;

    min_x = s[min].x;
    min_y = s[min].y;

    tab[s[0].y][s[0].x] = 254;

    game_field(rp, tab);

    for (int i = 1; i < rp * rp - 1; i++)
    {

        *r = _getch();
        
        system("cls");

        if (*r == 'e')
        {
            x++;
            s[i].x = x;
            s[i].y = y; 

            movement(rp, tab, s, &min, &min_x, &min_y, i); 

        }

        if (*r == ',')
        {
            y--;
            s[i].x = x;
            s[i].y = y; 

            movement(rp, tab, s, &min, &min_x, &min_y, i);
        }

        if (*r == 'o')
        {
            y++;
            s[i].x = x;
            s[i].y = y;

            movement(rp, tab, s, &min, &min_x, &min_y, i);
        }

        if (*r == 'a')
        {
            x--;
            s[i].x = x;
            s[i].y = y;

            movement(rp, tab, s, &min, &min_x, &min_y, i);
        }


        game_field(rp, tab);
        // printf("%d %d\n", s[0].x, s[0].y);
        //  printf("%d %d\n", s[1].x, s[1].y);
        //   printf("%d %d\n", s[2].x, s[2].y);
        //    printf("%d %d\n", s[3].x, s[3].y);
        //     printf("%d %d\n", s[4].x, s[4].y);
        //      printf("%d %d\n", s[5].x, s[5].y);
        printf("%d %d\n", min_x, min_y);
        printf("%d\n", min);
             printf("i = %d", i); 


        printf("\n%c %c %c %c\n", s[0].z, s[1].z, s[2].z, s[3].z);
        printf("\n%d %d", x, y);
        printf("\n%d\n", punkty);

    }

}


void wypelnij(int rp, char t[rp][rp], struct snake s[300])
{
    for (int i = 0; i <= rp; i++)
    {
        for (int g = 0; g < rp; g++)
        {
            t[i][g] = 32;
        }


    }
}

void points(int rp, char t[rp][rp])
{
    srand(time(NULL));
    int a = rand() % rp-1;
    int b = rand() % rp-1;
    if (t[a][b] == ' ')
        t[a][b] = '*';




}

void border(int rp, char t[rp][rp])
{
    int i = 1;
    t[0][0] = 201;
    t[0][rp - 1] = 187;
    t[rp - 1][0] = 200;
    t[rp - 1][rp - 1] = 188;
    while (i < rp - 1)
    {
        t[0][i] = 205;
        t[rp - 1][i] = 205;
        t[i][0] = 186;
        t[i][rp - 1] = 186;
        i++;
    }


}

void movement(int rp, char tab[rp][rp], struct snake s[300], int *min, int *min_x, int *min_y, int i)
{
    if (tab[s[i].y][s[i].x] == '*')
                {
                    tab[s[i].y][s[i].x] = 254;
                }
                if (tab[s[i].y][s[i].x]== ' ')
                {
                    tab[s[i].y][s[i].x] = 254;
                    tab[*min_y][*min_x] = ' ';
                    (*min)++;
                    *min_x = s[*min].x;
                    *min_y = s[*min].y;
                    
                }
}

