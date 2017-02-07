# ifndef MAP_H_
# define MAP_H_

# define _BOMB 666
# define _PLAYER 42
# define _PLAYER2 2020
# define _BGN 41
# define _WALLU 13
# define _WALLE 27
# define _KBOOM 99

# define _KRED "\x1B[31m"
# define _KGRN "\x1B[32m"
# define _KBLU "\x1B[34m"
# define _KWHT "\x1B[37m"
# define _TEST "\033[36m"

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

struct matrix
{
  int *data;
  size_t lines;
  size_t cols;
};

struct matrix *newMat(size_t lines, size_t cols);

struct matrix *cloneMat(struct matrix *mat);

void freeMat(struct matrix *mat);

void printMat(struct matrix *mat);

void buildMap(struct matrix *mat);

# endif
