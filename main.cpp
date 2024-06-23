/* 
 * 2048 game
 * author: faker
 * date: 2024/6/23
*/

#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int w[4][4];
int vis[4][4];
int moveX[4] = {0, 0, -1, 1};
int moveY[4] = {-1, 1, 0, 0};

int random(int n);
void create_box();
void init();
void show();
void input();
void moveW();
void moveA();
void moveS();
void moveD();
void hit(int x, int y, int dir);

int main(int argc, char *argv[])
{
    init();
    while (true)
    {
        input();
    }

    return 0;
}

int random(int n)
{
    return rand() % n;
}

void create_box()
{
    int x, y;
    do
    {
        x = random(4);
        y = random(4);
    }
    while(w[x][y] != 0);
    
    w[x][y] = random(10) < 7 ? 2 : 4;
}

void init()
{
    srand(time(0));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            w[i][j] = 0;
        }
    }
    create_box();
    create_box();
    show();
}

void show()
{
    system("cls");
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%4d", w[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
}

void input()
{
    char key = _getch();

    while(! _kbhit());
    {
        switch (key)
        {
        case 'w':
            moveW();
            break;
        case 'a':
            moveA();
            break;
        case 's':
            moveS();
            break;
        case 'd':
            moveD();
            break;
        default:
            break;
        }
        key = _getch();
    }


}

void moveW()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            hit(i, j, 0);
        }
    }
}

void moveA()
{
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 4; i++)
        {
            hit(i, j, 2);
        }
    }
}

void moveS()
{
    for(int i = 3; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            hit(i, j, 1);
        }
    }
}

void moveD()
{
    for(int j = 3; j >= 0; j--)
    {
        for(int i = 0; i < 4; i++)
        {
            hit(i, j, 3);
        }
    }
}

void hit(int x, int y, int dir)
{
    int nx = x + moveX[dir];
    int ny = y + moveY[dir];

    // if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) return;

    while()
    {
        if(w[nx][ny] == 0)
        {
            w[nx][ny] = w[x][y];
            w[x][y] = 0;
            continue;
        }
        if(w[nx][ny] == w[x][y])
        {
            
            w[nx][ny] += w[x][y];
            w[x][y] = 0;
            break;
        }
        if(w[nx][ny] != 0) break;
        x = nx;
        y = ny;
        nx = x + moveX[dir];
        ny = y + moveY[dir];
        create_box();
    }

}