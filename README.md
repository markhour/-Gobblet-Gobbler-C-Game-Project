# Gobblet Gobbler – C++ Game Project

A console-based C++ implementation of **Gobblet Gobbler**, a strategic two-player game inspired by Tic-Tac-Toe but with a twist—players use different sized pieces to "gobble" smaller ones on the board!

## � Game Overview

The objective is to be the first player to align **three pieces in a row**, either horizontally, vertically, or diagonally. Players can **stack larger pieces on top of smaller ones**, adding a layer of strategy.

### Piece Sizes
- **Large**: Represented as `YY` (Yellow) or `RR` (Red)
- **Medium**: Represented as `Y` (Yellow) or `R` (Red)
- **Small**: Represented as `y` (Yellow) or `r` (Red)

##  How to Play

- Players take turns.
- On your turn, enter your move in the format `<piece><position>`, such as:
  - `a2` — Place a **large** piece on square 2.
  - `b5` — Place a **medium** piece on square 5.
  - `c9` — Place a **small** piece on square 9.
- Valid piece selections:
  - `a` = large
  - `b` = medium
  - `c` = small
- Each player has 2 of each piece size.
- You can **cover smaller pieces** with larger ones, but not the other way around.
- Enter `q` to quit the game.

## Game Features

- Full 3x3 board rendering in console.
- Visual cues for remaining pieces per player.
- Move validation (invalid input, wrong size, invalid covering).
- Win and tie detection logic.
- Clear turn-based gameplay interface.

## Example Output

         1|2|3
         --------
         4|5|6
         --------
         7|8|9
a. YY 2 remain.
b. Y 2 remain.
c. y 2 remain.
q to exit.

It is yellow's turn.

