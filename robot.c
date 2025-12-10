#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct { int x, y; } Point;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char moveChar[4] = {'N', 'S', 'O', 'E'};

char grid[100][100];
int visited[100][100];
Point parent[100][100];
char parentMove[100][100];

char* defi_robot() {
    int n = 10, m = 10;
    strcpy(grid[0], "S.....#...");
    strcpy(grid[1], ".###..#..#");
    strcpy(grid[2], "..#....#..");
    strcpy(grid[3], "..#.##.#..");
    strcpy(grid[4], "....#..#..");
    strcpy(grid[5], "##..#..#.#");
    strcpy(grid[6], "..#...##..");
    strcpy(grid[7], "..#.#.....");
    strcpy(grid[8], "..#..###..");
    strcpy(grid[9], ".......E..");

    memset(visited, 0, sizeof(visited));

    Point start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') start = (Point){i, j};
            if (grid[i][j] == 'E') end = (Point){i, j};
        }
    }

    printf("\nLabyrinthe chargé :\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", grid[i]);

    Point queue[MAX];
    int front = 0, back = 0;
    queue[back++] = start;
    visited[start.x][start.y] = 1;

    int found = 0;
    while (front < back) {
        Point p = queue[front++];
        if (p.x == end.x && p.y == end.y) {
            found = 1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == '#') continue;
            visited[nx][ny] = 1;
            parent[nx][ny] = p;
            parentMove[nx][ny] = moveChar[i];
            queue[back++] = (Point){nx, ny};
        }
    }

    if (!found) {
        printf("Aucun chemin trouvé.\n");
        return NULL;
    }

    char path[10000];
    int len = 0;
    Point cur = end;
    while (!(cur.x == start.x && cur.y == start.y)) {
        path[len++] = parentMove[cur.x][cur.y];
        cur = parent[cur.x][cur.y];
    }
    path[len] = '\0';
    
    for (int i = 0; i < len / 2; i++) {
        char tmp = path[i];
        path[i] = path[len - 1 - i];
        path[len - 1 - i] = tmp;
    }
    
    strrev(path);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    strcpy(str, path);
    return str;
}
