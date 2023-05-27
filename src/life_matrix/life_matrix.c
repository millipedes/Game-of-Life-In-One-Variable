#include "include/life_matrix.h"

long init_cell(int r, int g, int b) {
  long the_cell = (long)calloc(1, sizeof(struct CELL_T));
  CELL_MEM(the_cell, r) = r;
  CELL_MEM(the_cell, g) = g;
  CELL_MEM(the_cell, b) = b;
  return the_cell;
}

void debug_cell(long the_cell) {
  printf("[CELL]\n");
  printf("(%d, %d, %d)\n", CELL_MEM(the_cell, r), CELL_MEM(the_cell, g),
      CELL_MEM(the_cell, b));
}

void free_cell(long the_cell) {
  if(the_cell)
    free(CELL(the_cell));
}

long init_life_matrix(int width, int height) {
  long the_life_matrix = (long)calloc(1, sizeof(struct LIFE_MATRIX_T));
  LIFE_MAT_MEM(the_life_matrix, width) = width;
  LIFE_MAT_MEM(the_life_matrix, height) = height;
  LIFE_MAT_MEM(the_life_matrix, cells) = (long)calloc(height,
      sizeof(struct CELL_T **));
  for(int i = 0; i < height; i++)
    LIFE_MAT_C1(the_life_matrix, i) = calloc(width, sizeof(struct CELL_T *));
  for(int i = 0; i < height; i++)
    for(int j = 0; j < width; j++)
      LIFE_MAT_C2(the_life_matrix, i, j)
        = (cell)init_cell(MIN_COL, MIN_COL, MIN_COL);
  return the_life_matrix;
}

void debug_life_matrix(long the_life_matrix) {
  printf("[LIFE_MATRIX]\n");
  printf("Width: %d Hieght: %d\n", LIFE_MAT_MEM(the_life_matrix, width),
      LIFE_MAT_MEM(the_life_matrix, height));
  for(int i = 0; i < LIFE_MAT_MEM(the_life_matrix, height); i++)
    for(int j = 0; j < LIFE_MAT_MEM(the_life_matrix, width); j++)
      debug_cell((long)LIFE_MAT_C2(the_life_matrix, i, j));
}


/**
 * 1) Any live cell with fewer than two live neighbours dies, as if by
 * underpopulation.
 * 2) Any live cell with two or three live neighbours lives on to the next
 * generation.
 * 3) Any live cell with more than three live neighbours dies, as if by
 * overpopulation.
 * 4) Any dead cell with exactly three live neighbours becomes a live cell, as
 * if by reproduction.
 */

// long transact_generation(life_matrix the_life_matrix) {
//   for(int i = 0; i < (LIFE_MAT_MEM(the_life_matrix))->height; i++)
//     for(int j = 0; j < (LIFE_MAT(the_life_matrix))->height; j++)
// }
// 
// long calculate_alive(long the_life_matrix, int i, int j) {
// }

void free_life_matrix(long the_life_matrix) {
  if(LIFE_MAT(the_life_matrix)) {
    if(LIFE_MAT_MEM(the_life_matrix, cells)) {
      for(int i = 0; i < LIFE_MAT_MEM(the_life_matrix, height); i++) {
        if(LIFE_MAT_C1(the_life_matrix, i)) {
          for(int j = 0; j < LIFE_MAT_MEM(the_life_matrix, width); j++) {
            if(LIFE_MAT_C2(the_life_matrix, i, j))
              free_cell((long)LIFE_MAT_C2(the_life_matrix, i, j));
          }
          free(LIFE_MAT_C1(the_life_matrix, i));
        }
      }
      free(CELL((LIFE_MAT(the_life_matrix))->cells));
    }
    free(LIFE_MAT(the_life_matrix));
  }
}
