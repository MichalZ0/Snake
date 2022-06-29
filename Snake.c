#include <stdio.h>
#include <conio.h>

typedef struct snake {
    int x; 
    int y;
};

int print_board (int tab[][20]);
int fill_board (int tab[][20]);
int gameplay (int tab[][20], struct snake s[400]); 

int main()
{
    // bazowe zmienne
    int matryca[20][20]; 
    struct snake s[400];

    // poczatkowe wspolrzedne pierwszego elementu
    s[0].x = 0;
    s[0].y = 0;

    // wypelnia matryce pustymi znakami
    fill_board(matryca);

    matryca[s[0].y][s[0].x] = 254;

    print_board(matryca);

    gameplay(matryca, s); 

    


}

int print_board (int tab[][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
            printf("%c", tab[j][i]);
        printf("\n");
    }
}    

int fill_board (int tab[][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
            tab[j][i] = ' '; 
    }
}

int gameplay (int tab[][20], struct snake s[400])
{
    
    int x=0, y=0;
    for (int i = 0; i < 400; i++)
    {
        char *r = getch(); 
        int punkty = 0;

        if (*r == 'e')
        {
            x++;
            s[i].x = x+1;

            tab[s[i].y][s[i].x] = 254;

        }
        print_board(tab);
    }
    
}
        



