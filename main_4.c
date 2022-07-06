#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <winuser.h>


char buffer[100];

struct snake
{
    int x;
    int y;
    char z;
    char zz;
};

char left, right, up, down;
int counter=0; 


void game_field(int rp, char t[rp][rp]);
void gameplay(char* r, int rp, char tab[rp][rp], struct snake s[300]);
void wypelnij(int rp, char t[rp][rp], struct snake s[300]);
void points(int rp, char[rp][rp]);
void border(int rp, char t[rp][rp]);
void movement(int rp, char tab[rp][rp], struct snake s[300], int *min, int *min_x, int *min_y, int i, int *punkty);
void results (int rp, char tab[rp][rp], struct snake s[300], int punkty, int i, int max_pkt);




int main()
{
    int rp = 2;



    printf("Podaj rozmiar pola(liczba nieparzysta): ");
    while (rp % 2 == 0)
        scanf("%d", &rp);

    if (counter == 0)
    {
        printf("Podaj sterowanie: \n");
        printf("Gora: \n");
        scanf("%s", &up);
        printf("Dol: \n");
        scanf("%s", &down);
        printf("Lewo: \n");
        scanf("%s", &left);
        printf("Prawo: \n");
        scanf("%s", &right);
    }

    char pole[rp][rp], ruch;
    
    struct snake *s;
    s = malloc(sizeof(*s));
    

    wypelnij(rp, pole, s);
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
            if (i == 0 || i == rp-1)
            {
                printf("%c", t[i][g]);
                if (g < rp-1)
                    printf("%c", 205);
            }
            else
            {
                printf("%c ", t[i][g]);
            }

        }

        printf("\n");
    }
}

void gameplay(char* r, int rp, char tab[rp][rp], struct snake s[300])
{

    int x = 1, y = (rp / 2), punkty = 1, min = 0, min_x, min_y, max_pkt = (rp-2)*(rp-2);

    s[0].x = x;
    s[0].y = y;
    *r = 'e';


    min_x = s[min].x;
    min_y = s[min].y;

    tab[s[0].y][s[0].x] = 254;

    points(rp, tab);

    game_field(rp, tab);

    for (int i = 1; punkty != max_pkt; i++)
    {
        s = realloc(s, (i+1)*sizeof(*s));
        time_t start = time(NULL);
        char r_c = *r;
        char ruch;
        if (i == 1)
            while (time(NULL) - start < 1);

        while (time(NULL) - start < 1)
        {
            if (GetAsyncKeyState(VK_OEM_COMMA) && *r != 'o')
            {
                *r = ',';
            }
            if (GetAsyncKeyState(0x41) && *r != 'e')
            {
                *r = 'a';
            }
            if (GetAsyncKeyState(0x4F) && *r != ',')
            {
                *r = 'o';
            }
            if (GetAsyncKeyState(0x45) && *r != 'a')
            {
                *r = 'e';
            }
        }


        

        system("cls");
        if (*r == 'e')
        {
            x++;
            s[i].x = x;
            s[i].y = y;

            

            results(rp, tab, s, punkty, i, max_pkt);
            movement(rp, tab, s, &min, &min_x, &min_y, i, &punkty);

        }

        if (*r == ',')
        {
            y--;
            s[i].x = x;
            s[i].y = y;

            results(rp, tab, s, punkty, i, max_pkt);
            movement(rp, tab, s, &min, &min_x, &min_y, i, &punkty);
        }

        if (*r == 'o')
        {
            y++;
            s[i].x = x;
            s[i].y = y;

            results(rp, tab, s, punkty, i, max_pkt);
            movement(rp, tab, s, &min, &min_x, &min_y, i, &punkty);

        }

        if (*r == 'a')
        {
            x--;
            s[i].x = x;
            s[i].y = y;

            results(rp, tab, s, punkty, i, max_pkt);
            movement(rp, tab, s, &min, &min_x, &min_y, i, &punkty);
            
            

        }


        game_field(rp, tab);

        printf("Punkty: %d", punkty);
        printf("%c %c\n", *r, r_c);
        printf("%ld", ftell(stdin));

    }
    free(s);


    system("cls");

    printf("Wygrana! Twoja liczba punktow to: %d\n\n", punkty);
    counter++;
    main();
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

    int a = rand() % (rp -2) + 1;
    int b = rand() % (rp -2) + 1;

    while (t[a][b] != ' ')
    {
        a = rand() % (rp -2) + 1;
        b = rand() % (rp - 2) + 1;
    }

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

void movement(int rp, char tab[rp][rp], struct snake s[300], int *min, int *min_x, int *min_y, int i, int *punkty)
{
    if (tab[s[i].y][s[i].x] == '*')
                {
                    (*punkty)++;
                    tab[s[i].y][s[i].x] = 254;
                    points(rp, tab);
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

void results (int rp, char tab[rp][rp], struct snake s[300], int punkty, int i, int max_pkt)
{
        if (tab[s[i].y][s[i].x] != ' ' && tab[s[i].y][s[i].x] != '*' )
        {
            printf("Przegrana!\nTwoja liczba punktow: %d\n\n", punkty);
            counter++;
            main();
        }
        if (tab[s[i].y][s[i].x] == 254)
        {
            printf("Przegrana!\nTwoja liczba punktow: %d\n\n", punkty);
            counter++;
            main();
        }
}

