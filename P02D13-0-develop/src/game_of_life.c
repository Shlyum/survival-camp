#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#define Y 25
#define X 80

void setWorld(char world[][X]);
void runGame(char a[][X], char b[][X]);
void lifeAct(char a[][X], char b[][X]);
int checkNeighbour(char a[][X], int y, int x);
void drawWorld(char b[][X]);
void draw(char b[][X]);

int main() {
    char world[Y][X], sw[Y][X];
    setWorld(world);
    runGame(world, sw);
}

void setWorld(char world[][X]) {
    char check;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            scanf("%c", &check);
            if (check != '\n')
                world[i][j] = check;
            else
                scanf("%c", &world[i][j]);
        }
    }
    drawWorld(world);
}

void runGame(char a[][X], char b[][X]) {
    int count = 0;
    int delay = 1000000;
    FILE*readFile;
    readFile = freopen("/dev/tty", "r", stdin);
    initscr();
    noecho();
    timeout(0);
    while (1) {
        char c;
        c = getch();
        if (c == '1') {
            delay = 1000000;
        } else if (c == '2') {
            delay = 500000;
        } else if (c == '3') {
            delay = 250000;
        } else if (c == '4') {
            delay = 125000;
        } else if (c == '0') {
            break;
        }
        if (count % 2 == 0) {
            lifeAct(a, b);
            draw(b);
            refresh();
        } else {
            lifeAct(b, a); draw(a); refresh();
        }
        count++;
        usleep(delay);
    }
    fclose(readFile);
    endwin();
}

void lifeAct(char a[][X], char b[][X]) {
    int n;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            n = checkNeighbour(a, i, j);
            if (a[i][j] == '#') {
                if (n == 3 || n == 2)
                    b[i][j] = '#';
                else
                    b[i][j] = ' ';
            } else {
                if (n != 3)
                    b[i][j] = ' ';
                else
                    b[i][j] = '#';
            }
        }
    }
}

int checkNeighbour(char a[][X], int y, int x) {
     int neighbours = 0;
     int n, m;
     for (int i = -1; i < 2; i++) {
         for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            m = y + i;
            n = x + j;
            if (m < 0) {
                m = Y + m;
            } else if (m > Y-1) {
                m = m - Y;
            }
            if (n < 0) {
                n = X + n;
            } else if (n > X - 1) {
                n = n - X;
            }
            if (a[m][n] == '#')
                neighbours++;
        }
     }
    return neighbours;
}

void drawWorld(char b[][X]) {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            printf("%c", b[i][j]);
        }
        if (i < (Y - 1))
            printf("\n");
    }
}

void draw(char b[][X]) {
    move(0, 0);
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            printw("%c", b[i][j]);
        }
        if (i < (Y - 1))
            printw("\n");
    }
}
