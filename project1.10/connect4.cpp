#include <cstring>
#include <unistd.h>
#include <ncurses.h>
#include <iostream>

using namespace std;

#define rows 6
#define cols 7

int setAI;

struct player
{
    char name[20];
    char chip;
};

int checkRange(int colChoice)
{
    if (colChoice == '1' || colChoice == '2' || colChoice == '3' || colChoice == '4' ||
        colChoice == '5' || colChoice == '6' || colChoice == '7')
    {
        colChoice = ((colChoice - '0'));
    }
    return colChoice;
}

int playerChoice(char board[][10], player activePlayer)
{
    int colChoice;
    echo();
    curs_set(1);

    do
    {

        mvprintw(9, 0, "%s's turn\n", activePlayer.name);
        mvprintw(10, 0, "Please enter column number: ");
        refresh();
        colChoice = getch();

        if (colChoice == 'q')
        {
            return -1;
        }
        colChoice = checkRange(colChoice);

        while (board[1][colChoice] == 'X' || board[1][colChoice] == 'O')
        {
            mvprintw(11, 0, "Please enter a column number within 1 to 7: ");
            refresh();
            colChoice = getch();
            colChoice = checkRange(colChoice);
        }

    } while (colChoice < 1 || colChoice > 7);

    noecho();
    curs_set(0);

    return colChoice;
}

void isSpotEmpty(char board[][10], player activePlayer, int colChoice)
{
    int inTurn = 0;
    int row = 6;

    do
    {
        if (board[row][colChoice] != 'X' && board[row][colChoice] != 'O')
        {
            board[row][colChoice] = activePlayer.chip;
            inTurn = 1;
        }
        else
            --row;
    } while (inTurn != 1);
}

// initialize and print board
void gameBoard(char board[][10])
{
    int i;
    int j;

    clear();
    echo();
    curs_set(1);

    mvprintw(0, 0, "Press q to quit game");
    mvprintw(1, 0, "|1|2|3|4|5|6|7|");
    mvprintw(2, 0, "===============");
    for (i = 1; i <= rows; i++)
    {
        mvaddch(i + 2, 0, '|');

        for (j = 1; j <= cols; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                board[i][j] = '*';
            }

            if (board[i][j] == 'X')
            {
                attron(COLOR_PAIR(COLOR_RED));
                mvaddch(i + 2, j, board[i][j]);
                attroff(COLOR_PAIR(COLOR_RED));
            }
            if (board[i][j] == 'O')
            {
                attron(COLOR_PAIR(COLOR_BLUE));
                mvaddch(i + 2, j, board[i][j]);
                attroff(COLOR_PAIR(COLOR_BLUE));
            }
            if (board[i][j] == '*')
            {
                attron(COLOR_PAIR(COLOR_WHITE));
                mvaddch(i + 2, j, board[i][j]);
                attroff(COLOR_PAIR(COLOR_WHITE));
            }
        }
        mvaddch(i + 2, j, '|');
    }
    refresh();
}

int connect4(char board[][10], player activePlayer)
{
    char chip;
    int win;
    int i;
    int j;

    chip = activePlayer.chip;
    win = 0;

    for (i = 8; i >= 1; --i)
    {

        for (j = 9; j >= 1; --j)
        {
            // CHECK FOR ALL POSSIBLE WINS

            // col
            if (board[i][j] == chip &&
                board[i][j - 1] == chip &&
                board[i][j - 2] == chip &&
                board[i][j - 3] == chip)
            {
                win = 1;
            }

            // row
            if (board[i][j] == chip &&
                board[i - 1][j] == chip &&
                board[i - 2][j] == chip &&
                board[i - 3][j] == chip)
            {
                win = 1;
            }

            // col
            if (board[i][j] == chip &&
                board[i][j + 1] == chip &&
                board[i][j + 2] == chip &&
                board[i][j + 3] == chip)
            {
                win = 1;
            }

            // diagonal increase
            if (board[i][j] == chip &&
                board[i - 1][j - 1] == chip &&
                board[i - 2][j - 2] == chip &&
                board[i - 3][j - 3] == chip)
            {
                win = 1;
            }

            // diagonal decrease
            if (board[i][j] == chip &&
                board[i - 1][j + 1] == chip &&
                board[i - 2][j + 2] == chip &&
                board[i - 3][j + 3] == chip)
            {
                win = 1;
            }
        }
    }

    return win;
}

int isBoardFull(char board[][10])
{
    int full;
    full = 0;
    for (int j = 1; j <= cols; ++j)
    {
        if (board[1][j] != '*')
            ++full;
    }

    return full;
}

int newGame(char board[][10])
{
    int restart;
    int i;
    int j;
    bool input_ok = false;

    clear();

    // check if digit and input is 1 or 2
    do
    {
        mvprintw(0, 0, "Try Again?: Yes(1) No(2): ");
        restart = getch();

        if (restart == '1' || restart == '2')
        {
            restart = ((restart - '0'));
            input_ok = true;
        }

    } while (!input_ok);

    if (restart == 1)
    {
        for (i = 1; i <= rows; i++)
        {
            for (j = 1; j <= cols; j++)
            {
                board[i][j] = '*';
            }
        }
    }

    refresh();
    return restart;
}

void init_terminal(void)
{
    initscr();
    raw();
    curs_set(0);
    noecho();
    start_color();
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
}

void init_game(void)
{
    int input;

    echo();
    mvprintw(0, 20, "WELCOME TO CONNECT 4");
    mvprintw(9, 20, "Press any button to continue...");
    mvprintw(11, 20, "1. Start game");
    mvprintw(12, 20, "2. Game with AI");

    refresh();
    input = getch();

    if (input == '2')
    {
        setAI = 0;
    }
    else
    {
        setAI = 1;
    }

    noecho();
}

void winScreen(player activePlayer)
{
    clear();
    mvprintw(0, 0, "|   |   /***\\   |     |     |     |    |       *     | \\   | ||");
    mvprintw(1, 0, " \\ /   |     |  |     |      \\    |   /        *     |  \\  | ||");
    mvprintw(2, 0, "  |    |     |  |     |       \\  /\\  /         |     |   \\ | ");
    mvprintw(3, 0, "  |     \\***/    \\___/         \\/  \\/          |     |    \\| ||");
    mvprintw(4, 0, " ");
    mvprintw(5, 0, " ");
    mvprintw(6, 22, "A Haiku to player %s", activePlayer.name);
    mvprintw(7, 20, "=======================");
    mvprintw(8, 22, "You are the winner");
    mvprintw(9, 20, "The other is the loser");
    mvprintw(10, 23, "Congratulations");
    refresh();
}

void loseScreen()
{
    clear();
    mvprintw(0, 0, "|   |   /***\\   |     |    |       /***\\    /***\\     ******");
    mvprintw(1, 0, " \\ /   |     |  |     |    |      |     |  |____        |");
    mvprintw(2, 0, "  |    |     |  |     |    |      |     |       \\       |");
    mvprintw(3, 0, "  |     \\***/    \\___/     |_____  \\***/    \\***/       |");
    mvprintw(4, 0, " ");
    mvprintw(5, 0, " ");
    mvprintw(6, 22, "A Haiku to the Loser");
    mvprintw(7, 20, "========================");
    mvprintw(8, 21, "You have lost the game");
    mvprintw(9, 20, "How unfortunate for you");
    mvprintw(10, 21, "Better luck next time");
    mvprintw(11, 30, ".");
    mvprintw(12, 30, ".");
    mvprintw(13, 30, ".");
    mvprintw(14, 28, "Noob");
    refresh();
}

int main()
{
    player playerOne, playerTwo;
    char board[9][10];
    int colChoice;
    int win = 0;
    int full = 0;
    int again = 0;
    unsigned int microsecond = 1000000;

    init_terminal();
    init_game();

    // open game
    clear();
    echo();
    curs_set(1);

    int isSame = 1;

    mvprintw(0, 0, "Player One Name: ");
    getstr(playerOne.name);
    playerOne.chip = 'X';

    if (setAI == 0)
    {
        mvprintw(1, 0, "Player Two Name (AI): ");
    }
    else
    {
        mvprintw(1, 0, "Player Two Name: ");
    }
    getstr(playerTwo.name);
    playerTwo.chip = 'O';
    refresh();

    // check if same name:
    if (strcmp(playerOne.name, playerTwo.name) == 0)
    {
        while (isSame)
        {
            clear();
            mvprintw(0, 0, "Please input a different name player two: ");
            getstr(playerTwo.name);
            refresh();
            if (strcmp(playerOne.name, playerTwo.name) != 0)
            {
                clear();
                isSame = 0;
            }
        }
    }
    noecho();
    curs_set(0);
    //

    gameBoard(board);

    do
    {

        // Player one
        colChoice = playerChoice(board, playerOne);
        if (colChoice == -1)
        {
            break;
        }
        isSpotEmpty(board, playerOne, colChoice);
        gameBoard(board);
        win = connect4(board, playerOne);
        if (win == 1)
        {
            winScreen(playerOne);
            usleep(5 * microsecond);
            again = newGame(board);
            if (again == 2)
            {
                break;
            }
        }

        // Player two
        if (setAI == 0)
        {
            colChoice = 1 + (rand() % 7);
        }
        else
        {
            colChoice = playerChoice(board, playerTwo);
        }
        if (colChoice == -1)
        {
            break;
        }
        isSpotEmpty(board, playerTwo, colChoice);
        gameBoard(board);
        win = connect4(board, playerTwo);
        if (win == 1)
        {
            if (setAI == 0)
            {
                loseScreen();
            }
            else
            {
                winScreen(playerTwo);
            }
            usleep(5 * microsecond);
            again = newGame(board);
            if (again == 2)
            {
                break;
            }
        }

        full = isBoardFull(board);
        if (full == cols)
        {
            cout << "A Draw!" << endl;
            again = newGame(board);
        }

    } while (again != 2);

    endwin();

    return 0;
}