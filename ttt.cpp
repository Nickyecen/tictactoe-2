#include <iostream>

using namespace std;

// The two variables used
long int v1, v2;

/*

Board:
02 03 05 - Uses prime numbers, it is multiplied once by it
07 11 13   if the first player marked it, twice if the second
17 19 23   player marked it and none if it wasn't marked

29 - Victory 1
31 - Victory 2
A choice was made to separate the victory variable in two,
only for code simplification pourpuses

37 - Turn 0 or 1
Being 0 player 1 and 1 player 2

41 - Draw 

*/

// Function using exclusevely constants, it's easy to see
// how they would translate to a code without them
void play(const long int space);
void checkWin();
void checkPartWin(const long int a, const long int b, const long int c);
void draw();
void drawPart(const long int s, const char p);

int main() {
    // Set player 1's turn
	v1 = 37;

    // While no end game was reached
	while(v1 % 29 && v1 % 31 && v1 % 41) {

		draw(); // Draw board

        // Uses second variable as input buffer
		cout<<"Insert your play\n";
		cin>>v2;

		switch(v2) {

            // Line 1
			case 1:
				play(2);
				break;
			case 2:
				play(3);
				break;
			case 3:
				play(5);
				break;

            // Line 2
			case 4:
				play(7);
				break;
			case 5:
				play(11);
				break;
			case 6:
				play(13);
				break;

            // Line 3
			case 7:
				play(17);
				break;
			case 8:
				play(19);
				break;
			case 9:
				play(23);
				break;

            // If invalid number was played, plays a useless move
			default:
				play(1);
		}

        // Prints variable keeping the entire game state
		cout<<"V1: "<<v1<<'\n';

		checkWin(); // Checks if there was a win or draw

	}

    // Game ends, checks who won
	if(v1 % 29 == 0)
		cout<<"Player 1's victorious!\n";
	else if(v1 % 41 == 0)
		cout<<"Draw!\n";
	else
		cout<<"Player 2's victorious!\n";
}

// Pattern repeated for a play
void play(const long int space) {
	if(v1 % space == 0) {
		cout<<"Invalid play. Try again.\n";
		return;
	}

	if(v1 % 37 == 0) {
		v1 *= space*space;
	} else {
		v1 *= space;
	}

    // Changes turn
    if(v1 % 37) v1 *= 37;
    else v1 /= 37;
}

// Function to draw the board
void draw() {
	drawPart(2, '1');
	cout<<'|';
	drawPart(3, '2');
	cout<<'|';
	drawPart(5, '3');
	cout<<'\n';

	cout<<"-----\n";

	drawPart(7, '4');
	cout<<'|';
	drawPart(11, '5');
	cout<<'|';
	drawPart(13, '6');
	cout<<'\n';

	cout<<"-----\n";

	drawPart(17, '7');
	cout<<'|';
	drawPart(19, '8');
	cout<<'|';
	drawPart(23, '9');
	cout<<'\n';

}

// Auxiliary function to draw a square of the board
void drawPart(const long int s, const char p) {
	if(v1 % s == 0) {
		if(v1 % (s*s) == 0) {
			cout<<'X';
		} else {
			cout<<'O';
		}
	} else {
		cout<<p;
	}
}

// Checks if there was a win
void checkWin() {
    
    // Three rows 
	checkPartWin(2, 3, 5);
	checkPartWin(7, 11, 13);
	checkPartWin(17, 19, 23);

    // Three columns
	checkPartWin(2, 7, 17);
	checkPartWin(3, 11, 19);
	checkPartWin(5, 13, 23);

    // Two diagonals
	checkPartWin(2, 11, 23);
	checkPartWin(5, 11, 17);

    // Checks for draw
	if(!(v1%2)&&!(v1%3)&&!(v1%5)&&!(v1%7)&&!(v1%11)&&!(v1%13)&&!(v1%17)&&!(v1%19)&&!(v1%23))
		v1 *= 41;
}

// Auxiliary function that checks if there was a win in a certain position
void checkPartWin(const long int a, const long int b, const long int c) {
	if(!(v1 % a) && !(v1 % b) && !(v1 % c)) {
		if(!(v1 % (a*a)) && !(v1 % (b*b)) && !(v1 % (c*c))) {
			v1 *= 29;
		} else if(v1 % (a*a) && v1 % (b*b) && v1 % (c*c)) {
			v1 *= 31;
		}
	}
}
