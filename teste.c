#include<ncurses.h>
#include <stdio.h>
#include<stdlib.h>
int main(int argc, char*argv[])
{
    initscr();
    //printw("hello wolrd");

if (has_colors() == FALSE) {
        endwin();
        printf("Seu terminal não suporta cores.\n");
        exit(1);
    }
    start_color();

    // Define pares de cores (foreground, background)
    init_pair(1, COLOR_YELLOW, COLOR_BLUE);  // Texto amarelo com fundo azul
    init_pair(2, COLOR_RED, COLOR_BLACK);    // Texto vermelho com fundo preto
    init_pair(3, COLOR_GREEN, COLOR_BLACK);  // Texto verde com fundo preto

    // Usa o par de cores 1 e imprime texto centralizado
    attron(COLOR_PAIR(1));  // Ativa par de cores 1
    mvprintw(LINES / 2, (COLS - 20) / 2, "hello, world in style!");
    attroff(COLOR_PAIR(1)); // Desativa par de cores 1

    // Move o cursor para uma nova linha e usa outro par de cores
    attron(COLOR_PAIR(2));
    mvprintw(LINES / 2 + 2, (COLS - 25) / 2, "text with a red and black style!");
    attroff(COLOR_PAIR(2));

    // Exemplo de borda
    attron(COLOR_PAIR(3)); 
    border(0, 0, 0, 0, 0, 0, 0, 0); // Desenha uma borda em volta da tela
    attroff(COLOR_PAIR(3));


    refresh();
    getch();
    endwin();
    return 0;
}
