# ♟️ consoleChess ♟️

***consoleChess*** is a 2-player chess application running on shell.  
Two players can interactively input their moves using standard [chess move notation](https://en.wikipedia.org/wiki/Algebraic_notation_(chess)#Formatting).

## 💻 Usage
  ### Windows
  Simply create a new project on Visual Studio and add Source and Header files to their respective folders. Finally run **main.cpp**.
  ### Linux/OS X
  1. Gather all Header and Source files into a single directory together with the **Makefile** file.
  2. Run `make` in your terminal to build the project:
  3. Then type `./output`. You will be greeted with a *:::Welcome!:::* message.
  4. After you're done with the program, type `make clean` to delete any redundant files.

![App Demo](https://i.imgur.com/WBcU5UQ.gif)

## 👨‍💻 Code Itself
Code is written in an [OOP](https://en.wikipedia.org/wiki/Object-oriented_programming) fashion. The program constains two general objects namely:
  - Board
  - Piece 
<!-- -->
A **Board** object is needed at the start of every game. Pieces are subsequently attached to the board object.  
**Piece** is an [abstract class](https://www.educative.io/edpresso/what-is-a-cpp-abstract-class) meaning that a Piece object cannot be created on its own.  
Specific chess pieces are:
- Pawn
- Knight
- Bishop
- Rook
- Queen
- King
<!-- -->
They all inherit some shared functionality from **Piece** class and override some functions if needed.  
### Board Setting
You can setup the board to the standard piece setup by running `board.setup_board()` method.  
In case you want to start from a certain position, you can create an object of that piece and attach it to the board using `board.insert_piece()` method. Eventually, `board.play()` brings you to the game's interactive interface.
