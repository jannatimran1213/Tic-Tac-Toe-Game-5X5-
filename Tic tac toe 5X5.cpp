#include<iostream>
#include<cstdlib>
using namespace std;
string board[5][5]={{"01" ,"02","03","04","05"},{"06","07","08","09","10"},{"11","12","13","14","15"},{"16","17","18","19","20"},{"21","22","23","24","25"}}; //2D array for board (5x5 grid)
string turn=" X"; //variable to decide which player will have the turn
bool draw=false;//variable to decide draw case
void display_board(){ //function to display board
system("cls");//to clear the screen
cout<<"   TICK CROSS GAME   "<<endl;
cout<<"     Player1:  [x]"<<endl;//print the symbol for 1st player
cout<<"     Player2:  [O]"<<endl;//print the symbol for 2nd player
cout<<"     Please select numbers from 1 to 25 "<<endl;
cout<<endl;
cout<<"\t\t     |     |     |     |    "<<endl;
cout<<"\t\t  "<<board[0][0]<<" | "<<board[0][1]<<"  | "<<board[0][2]<<"  | "<<board[0][3]<<"  | "<<board[0][4]<<"  "<<endl;//1st row of board
cout<<"\t\t_____|_____|_____|_____|_____"<<endl;
cout<<"\t\t     |     |     |     |    "<<endl;
cout<<"\t\t  "<<board[1][0]<<" | "<<board[1][1]<<"  | "<<board[1][2]<<"  | "<<board[1][3]<<"  | "<<board[1][4]<<"  "<<endl;//2nd row of board
cout<<"\t\t_____|_____|_____|_____|_____"<<endl;
cout<<"\t\t     |     |     |     |    "<<endl;
cout<<"\t\t  "<<board[2][0]<<" | "<<board[2][1]<<"  | "<<board[2][2]<<"  | "<<board[2][3]<<"  | "<<board[2][4]<<"  "<<endl;//3rd row of board
cout<<"\t\t_____|_____|_____|_____|_____"<<endl;
cout<<"\t\t     |     |     |     |     "<<endl;
cout<<"\t\t  "<<board[3][0]<<" | "<<board[3][1]<<"  | "<<board[3][2]<<"  | "<<board[3][3]<<"  | "<<board[3][4]<<"  "<<endl;//4th row of board
cout<<"\t\t_____|_____|_____|_____|_____"<<endl;
cout<<"\t\t     |     |     |     |     "<<endl;
cout<<"\t\t  "<<board[4][0]<<" | "<<board[4][1]<<"  | "<<board[4][2]<<"  "<<"| "<<board[4][3]<<"  | "<<board[4][4]<<"  "<<endl;//5th row of board
}

void player_turn() {
    int choice;
    bool validInput = false;
    while (!validInput) {
        cout << "\n\tPlayer " << (turn == " X" ? "1 [X]" : "2 [O]") << " turn: ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 25) {  // Check for invalid input or out-of-range input
            cin.clear();               // Clear the error state
            cin.ignore(INT_MAX, '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 25."<<endl;
        } else {
            validInput = true; // Valid input received
        }
    }
    int row, column;
    switch (choice) {
        case 1:  row = 0; column = 0; break;
        case 2:  row = 0; column = 1; break;
        case 3:  row = 0; column = 2; break;
        case 4:  row = 0; column = 3; break;
        case 5:  row = 0; column = 4; break;
        case 6:  row = 1; column = 0; break;
        case 7:  row = 1; column = 1; break;
        case 8:  row = 1; column = 2; break;
        case 9:  row = 1; column = 3; break;
        case 10: row = 1; column = 4; break;
        case 11: row = 2; column = 0; break;
        case 12: row = 2; column = 1; break;
        case 13: row = 2; column = 2; break;
        case 14: row = 2; column = 3; break;
        case 15: row = 2; column = 4; break;
        case 16: row = 3; column = 0; break;
        case 17: row = 3; column = 1; break;
        case 18: row = 3; column = 2; break;
        case 19: row = 3; column = 3; break;
        case 20: row = 3; column = 4; break;
        case 21: row = 4; column = 0; break;
        case 22: row = 4; column = 1; break;
        case 23: row = 4; column = 2; break;
        case 24: row = 4; column = 3; break;
        case 25: row = 4; column = 4; break;
    }

    if (board[row][column] != " X" && board[row][column] != " O") {
        board[row][column] = turn;  // Mark the cell with the current player's symbol
        turn = (turn == " X") ? " O" : " X";  // Switch turns
    } else {
        cout << "Box already filled. Please try again!\n";
        player_turn(); // ask current player t enter number again
    }

    display_board(); // Update the board display
}

bool gameover()//function to end the game after any win case or draw case
{
for(int i=0;i<5;i++)//winning case: matching symbols in row and column
if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]&&board[i][0]==board[i][3]&&board[i][0]==board[i][4]||board[0][i]==board[1][i]&&board[0][i]==board[2][i]&&board[0][i]==board[3][i]&&board[0][i]==board[4][i])
return false;//ends the game
if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]==board[3][3]&&board[0][0]==board[4][4]||board[0][4]==board[1][3]&&board[0][4]==board[2][2]&&board[0][4]==board[3][1]&&board[0][4]==board[4][0])//winning case: matching symbols in diagonals
return false;//ends the game
for(int i=0;i<5;i++){//nested loop to continue the game if any box is not filled
for(int j=0;j<5;j++)
   if(board[i][j]!=" X"&&board[i][j]!=" O")
    return true;//continue the game
}
draw=true;
return false;//ends the game in draw case
}

void reset_board() {
    // Reset the board for a new game
    string initial_board[5][5]={{"01" ,"02","03","04","05"},{"06","07","08","09","10"},{"11","12","13","14","15"},{"16","17","18","19","20"},{"21","22","23","24","25"}};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = initial_board[i][j];
        }
    }
}

int main()
{
system("color 4F");//system command to change console color
    string replay;

    do {
        // Reset the game before starting
        reset_board();
        draw = false;
        turn = " X";

        while (gameover()) {
            display_board();  // Function call to display the board
            player_turn();    // Function call for player's turn
        }

        if(turn==" X" && draw==false)
            cout<<"Player2 won! ***CONGRATULATIONS***";
        else if(turn==" O" && draw==false)
            cout<<"Player1 won! ***CONGRATULATIONS***";
        else
            cout<<"**GAME DRAW!**";

        // Ask the players if they want to play again
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> replay;

    } while (replay == "Y" || replay == "y");  // Replay condition

    cout << "Thanks for playing!" << endl;
    return 0;
}
