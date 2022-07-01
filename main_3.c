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
void movement(int rp, char tab[rp][rp], struct snake s[300], int *min, int *min_x, int *min_y, int i, int *punkty);
void results (int rp, char tab[rp][rp], struct snake s[300], int punkty, int i, int max_pkt); 
char get_char(float time_limit);

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
            printf("%c ", t[i][g]);
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
        
        
        char r_c = *r;;
        
        *r = get_char(0.5); 
        

        if (*r == -1)
        {
             *r = r_c;
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
        printf("%c %c", *r, r_c);

    }
   

    system("cls");
    
    printf("Wygrana! Twoja liczba punktow to: %d\n\n", punkty);
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
    
    int a = rand() % rp-1;
    int b = rand() % rp-1;
     
    while (t[a][b] != ' ')
    {
        a = rand() % rp-1;
        b = rand() % rp-1;
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
            main(); 
        }
        if (tab[s[i].y][s[i].x] == 254)
        {
            printf("Przegrana!\nTwoja liczba punktow: %d\n\n", punkty);
            main();
        }
}

char get_char(float time_limit){	
	time_t start = time(NULL); //start the clock
	while(!kbhit()){

		if (time(NULL) - start >= time_limit)
		{
            return -1;
		}
			while (time(NULL) - start < time_limit)
				time(NULL);
			



	}
	
    return getch();
}

	






//    tab[0][1] = '*';
     
//      tab[1][1] = '*';
//      tab[1][2] = '*';
//      tab[1][3] = '*';
//       tab[1][4] = '*';
//        tab[1][5] = '*';

//         tab[2][1] = '*';
//          tab[2][2] = '*';
//           tab[2][3] = '*';
//            tab[2][4] = '*';
//             tab[2][5] = '*';

//     tab[3][1] = '*';
//      tab[3][2] = '*';
//       tab[3][3] = '*';
//        tab[3][4] = '*';
//         tab[3][5] = '*';

//      tab[4][1] = '*';
//       tab[4][2] = '*';
//        tab[4][3] = '*';
//         tab[4][4] = '*';
//          tab[4][5] = '*';

//           tab[5][1] = '*';
//            tab[5][2] = '*';
//             tab[5][3] = '*'; 
//              tab[5][4] = '*';
//               tab[5][5] = '*';
