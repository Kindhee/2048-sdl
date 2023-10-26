#include "grid.h"
#include <iostream>
#include "time.h"
#include <list>
using namespace std;

Grid::Grid(int grid[size_gridC][size_gridC]) {

    starting = 2;

    srand(time(NULL));

    for (int j = 0; j < size_gridC; ++j)
    {
        for (int i = 0; i < size_gridC; ++i)
        {
            grid[j][i] = 0;
        }
    }

    int test_starting_tiles;
    int x, y;

    for (int i = 0; i < starting; ++i) {

        test_starting_tiles = 0;

        while (test_starting_tiles == 0) {
            x = randomNumberC(size_gridC);
            y = randomNumberC(size_gridC);
            if (grid[x][y] == 0) {
                test_starting_tiles = 1;
            }
        }
        grid[x][y] = 2;
    }
}

int Grid::randomNumberC(int number){
    int randomnumber;
    randomnumber = rand() % number;
    return(randomnumber);
}

bool Grid::testInGridC(int grid[size_gridC][size_gridC], int i, int j) {
    if (i > 3 || i < 0 || j>3 || j < 0) {
        return false;
    }
    else {
        return true;
    }
}

void Grid::moveUpC(int grid[size_gridC][size_gridC]) {
    list<int> list_col{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if ((grid[j][i] != 0)) {
                list_col.push_back(grid[j][i]);
            }
        }
        while (list_col.size() < size_gridC) {
            list_col.push_back(0);
        }
        for (int l = 0; l < size_gridC; l++) {
            grid[l][i] = list_col.front();
            list_col.pop_front();
            if (testInGridC(grid, i, l - 1) == true && grid[l - 1][i] == grid[l][i]) {
                grid[l - 1][i] += grid[l][i];
                grid[l][i] = 0;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((grid[j][i] == 0 && grid[j + 1][i] != 0)) {
                grid[j][i] = grid[j + 1][i];
                grid[j + 1][i] = 0;
            }
        }
    }
}

void Grid::moveDownC(int grid[size_gridC][size_gridC]) {
    list<int> list_col{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 3; j > -1; --j) {
            if ((grid[j][i] != 0)) {
                list_col.push_back(grid[j][i]);
            }
        }
        while (list_col.size() < size_gridC) {
            list_col.push_back(0);
        }
        for (int l = 3; l > -1; l--) {
            grid[l][i] = list_col.front();
            list_col.pop_front();
            if (testInGridC(grid, i, l + 1) == true && grid[l + 1][i] == grid[l][i]) {
                grid[l + 1][i] += grid[l][i];
                grid[l][i] = 0;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 3; j > 0; --j) {
            if ((grid[j][i] == 0 && grid[j - 1][i] != 0)) {
                grid[j][i] = grid[j - 1][i];
                grid[j - 1][i] = 0;
            }
        }
    }
}

void Grid::moveLeftC(int grid[size_gridC][size_gridC]) {
    list<int> list_col{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if ((grid[i][j] != 0)) {
                list_col.push_back(grid[i][j]);
            }
        }
        while (list_col.size() < size_gridC) {
            list_col.push_back(0);
        }
        for (int l = 0; l < size_gridC; l++) {
            grid[i][l] = list_col.front();
            list_col.pop_front();
            if (testInGridC(grid, i, l - 1) == true && grid[i][l - 1] == grid[i][l]) {
                grid[i][l - 1] += grid[i][l];
                grid[i][l] = 0;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((grid[i][j] == 0 && grid[i][j + 1] != 0)) {
                grid[i][j] = grid[i][j + 1];
                grid[i][j + 1] = 0;
            }
        }
    }
}

void Grid::moveRightC(int grid[size_gridC][size_gridC]) {
    list<int> list_col{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 3; j > -1; --j) {
            if ((grid[i][j] != 0)) {
                list_col.push_back(grid[i][j]);
            }
        }
        while (list_col.size() < size_gridC) {
            list_col.push_back(0);
        }
        for (int l = 3; l > -1; l--) {
            grid[i][l] = list_col.front();
            list_col.pop_front();
            if (testInGridC(grid, i, l + 1) == true && grid[i][l + 1] == grid[i][l]) {
                grid[i][l + 1] += grid[i][l];
                grid[i][l] = 0;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 3; j > 0; --j) {
            if ((grid[i][j] == 0 && grid[i][j - 1] != 0)) {
                grid[i][j] = grid[i][j - 1];
                grid[i][j - 1] = 0;
            }
        }
    }
}

int Grid::newTilesC(int grid[size_gridC][size_gridC]) {
    int count = 0, count_random = 0;
    int random_coord;
    for (int i = 0; i < size_gridC; ++i) {
        for (int j = 0; j < size_gridC; ++j)
        {
            if (grid[i][j] == 0) {
                count += 1;
            }
        }
    }
    if (count == 0) {
        return 0;
    }

    if (count == 1) {
        random_coord = 1;
    } else {
        random_coord = randomNumberC(count);
    }
    for (int i = 0; i < size_gridC; ++i) {
        for (int j = 0; j < size_gridC; ++j) {
            if (grid[i][j] == 0) {
                count_random += 1;
                if (count_random == random_coord) {
                    if (randomNumberC(3) == 0) {
                        grid[i][j] = 4;
                    }
                    else {
                        grid[i][j] = 2;
                    }
                }
            }
        }
    }
    return 1;
}

bool Grid::testLooseC(int grid[size_gridC][size_gridC], int zero) {
    if (zero == 1) {
        return false;
    }
    else {
        for (int j = 0; j < 4; ++j)
        {
            for (int i = 0; i < 4; ++i)
            {
                if (grid[i][j - 1] == grid[i][j] || grid[i - 1][j] == grid[i][j] || grid[i + 1][j] == grid[i][j] || grid[i][j + 1] == grid[i][j]) {
                    return false;
                }            
            }
        }
    }
    return true;
}

void Grid::showTableC(int grid[size_gridC][size_gridC]) {

    for (int j = 0; j < 4; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (grid[j][i] < 10) {
                std::cout << "   " << grid[j][i] << "  ";
            } else if (grid[j][i] > 10 && grid[j][i] < 100) {
                std::cout << "   " << grid[j][i] << " ";
            } else if (grid[j][i] > 100 && grid[j][i] < 1000) {
                std::cout << "  " << grid[j][i] << " ";
            } else if (grid[j][i] > 1000 && grid[j][i] < 10000) {
                std::cout << " " << grid[j][i] << " ";
            } else if (grid[j][i] > 10000 && grid[j][i] < 100000) {
                std::cout << " " << grid[j][i] << "";
            } else {
                std::cout << grid[j][i];
            }
        } 
        std::cout << std::endl << std::endl;
    }
}

