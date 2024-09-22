#import <iostream>

using namespace std;

long int v1, v2;

/*

Tabuleiro:
02 03 05
07 11 13
17 19 23

29 - Vitória 1
31 - Vitória 2

37 - Turno 0 ou 1

41 - Velha

*/

// Funcoes utilizam apenas constantes
void play(const long int space);
void checkWin();
void checkPartWin(const long int a, const long int b, const long int c);
void draw();
void drawPart(const long int s, const char p);

int main() {
	v1 = 37;

	while(v1 % 29 && v1 % 31 && v1 % 41) {

		draw();

		cout<<"Insira sua jogada\n";
		cin>>v2;

		switch(v2) {
			case 1:
				play(2);
				break;
			case 2:
				play(3);
				break;
			case 3:
				play(5);
				break;

			case 4:
				play(7);
				break;
			case 5:
				play(11);
				break;
			case 6:
				play(13);
				break;

			case 7:
				play(17);
				break;
			case 8:
				play(19);
				break;
			case 9:
				play(23);
				break;
			default:
				play(1);
		}

		cout<<"V1: "<<v1<<'\n';
		checkWin();
		if(v1 % 37) v1 *= 37;
		else v1 /= 37;

	}

	if(v1 % 29 == 0)
		cout<<"Vitoria do jogador 1\n";
	else if(v1 % 41 == 0)
		cout<<"Empate!\n";
	else
		cout<<"Vitoria do jogador 2\n";
}

void play(const long int space) {
	if(v1 % space == 0) {
		cout<<"Jogada invalida. Jogue novamente.\n";
		return;
	}

	if(v1 % 37 == 0) {
		v1 *= space*space;
	} else {
		v1 *= space;
	}
}

// 02 03 05
// 07 11 13
// 17 19 23

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

void drawPart(const long int s, const char p) {
	if(v1 % s == 0) {
		if(v1 % (s*s) == 0) {
			cout<<'O';
		} else {
			cout<<'X';
		}
	} else {
		cout<<p;
	}
}

void checkWin() {
	checkPartWin(2, 3, 5);
	checkPartWin(7, 11, 13);
	checkPartWin(17, 19, 23);

	checkPartWin(2, 7, 17);
	checkPartWin(3, 11, 19);
	checkPartWin(5, 13, 23);

	checkPartWin(2, 11, 23);
	checkPartWin(5, 11, 17);

	if(!(v1%2)&&!(v1%3)&&!(v1%5)&&!(v1%7)&&!(v1%11)&&!(v1%13)&&!(v1%17)&&!(v1%19)&&!(v1%23))
		v1 *= 41;
}

void checkPartWin(const long int a, const long int b, const long int c) {
	if(!(v1 % a) && !(v1 % b) && !(v1 % c)) {
		if(!(v1 % (a*a)) && !(v1 % (b*b)) && !(v1 % (c*c))) {
			v1 *= 29;
		} else if(v1 % (a*a) && v1 % (b*b) && v1 % (c*c)) {
			v1 *= 31;
		}
	}
}
