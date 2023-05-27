#ifndef LIF_H
#define LIF_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_COL 255
#define MIN_COL 0

typedef struct CELL_T {
  int r;
  int g;
  int b;
} * cell;

#define CELL(c)    ((cell)c)
#define CELL_1P(c) ((cell *)c)
#define CELL_2P(c) ((cell **)c)

#define CELL_MEM(c, m) ((cell)c)->m

long init_cell(int r, int g, int b);
void debug_cell(long the_cell);
void free_cell(long the_cell);

typedef struct LIFE_MATRIX_T {
  long cells;
  int width;
  int height;
} * life_matrix;

#define LIFE_MAT(l) ((life_matrix)l)
#define LIFE_MAT_MEM(l, m) (LIFE_MAT(l))->m
#define LIFE_MAT_C1(l, i) (CELL_1P(LIFE_MAT_MEM(l, cells)))[i]
#define LIFE_MAT_C2(l, i, j) (CELL_2P(LIFE_MAT_MEM(l, cells)))[i][j]

long init_life_matrix(int width, int height);
void debug_life_matrix(long the_life_matrix);
void free_life_matrix(long the_life_matrix);

#endif
