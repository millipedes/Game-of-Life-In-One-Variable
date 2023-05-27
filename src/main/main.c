#include "../life_matrix/include/life_matrix.h"

#define HW 10

int main(void) {
  long the_life_matrix = (long)init_life_matrix(HW, HW);
  debug_life_matrix(the_life_matrix);
  free_life_matrix(the_life_matrix);
  return 0;
}
