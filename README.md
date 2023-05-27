# :hammer: In the Works
  
# :star: The Challenge
  This is a challenge project to write Conway's Game of Life only using one
  variable. The rules are:

  1) Only one variable can be used to respresent all data structures.
  2) Iterators do no count (i.e. `i` in `for` loops).
  3) The input is a file that specifies:
    - The Width of the Canvas
    - The Height of the Canvas
    - The Size of the Cells (they are represented in the traditional way of
      squares).
    - The color of the Cells (in RGB format).
    - The number of generations.
  4) The output is *n* `.png` files showing each frame of the simulation.

# :book: Rules of Conway's Game of Life
  The following is a direct quote from the [wikipedia article](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life):
  - Any live cell with fewer than two live neighbours dies, as if by
    underpopulation.
  - Any live cell with two or three live neighbours lives on to the next
    generation.
  - Any live cell with more than three live neighbours dies, as if by
    overpopulation.
  - Any dead cell with exactly three live neighbours becomes a live cell, as if
    by reproduction.

# References
  - https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
