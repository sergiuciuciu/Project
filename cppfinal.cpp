#include <iostream>
#include <conio.h>
#include <Windows.h>
#include<string.h>
#include<fstream>
using namespace std;
void afisaremoulty();
void instructiuni();
void ascunderecursor();
void pozitiecursor(short x, short y);
void input1();
void input2();
void start();
void afisare();
void fruct();
void miscare();
void miscare1();
void menu();
void miscare2();
void felicitari();
void input();
void gameover();
void startmoulty();
void culoare();
void powerup();
void declararemoulty();

void ascunderecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void pozitiecursor(short x, short y) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x,y };
	SetConsoleCursorPosition(handle, position);
}
int scor1, scor2, nrsarpe1, nrsarpe2;
char optiune = 0;
int dublare = 0;
int snake1, snake2;
char revenire = NULL;
int width = 20;
int nivelh, scorh;
int xsarpe1, xsarpe2, ysarpe1, ysarpe2;
int height = 20;
int meniu = 0;
int timp = 31;
int xpow, ypow, powup;
char golire[400];
int x, y, fructx, fructy, scor = 0, nivel = 1, somn = 200, nrsarpe = 0;
bool oprirejoc;
struct coada {
	int x, y;
};
coada sarpe[400];
coada sarpe1[400], sarpe2[400];
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;
eDirecton dir1;
eDirecton dir2;
void felicitari()
{
	cout << "\n\n\n\n\n\n\n\n       Felicitari!Ati terminat jocul!\n";
	cout << "\n\n\n\n\nPentru a reveni la meniu apasati M!\n";
	cout << "Pentru a iesi apasati X!\n";
	cin >> optiune; 
	while (optiune != 'm'&&optiune != 'M'&&optiune != 'x'&&optiune != 'X') {
		pozitiecursor(0,16);
		cout << "                                                                           ";
		pozitiecursor(0, 16);
		cin >> optiune;
	}
	cin.getline(golire, 400);
	if (optiune == 'M' || optiune == 'm') {
		system("cls");
		menu();
	}
	else {
		if (optiune == 'x' || optiune == 'X') {
			exit(EXIT_FAILURE);
		}
		else felicitari();
	}

}
void powerup() {
	int gresit = 0;
	xpow = rand() % 18 + 1;
	ypow = rand() % 18 + 1;
	if (xpow == fructx&&ypow == fructy) {
		powerup();
	}
	for (int i = 0; i <= nrsarpe; i++) {
		if (xpow == sarpe[i].x&&ypow == sarpe[i].y) {
			i = nrsarpe + 1;
			gresit = 1;
		}
	}
	if (gresit == 1)powerup();
	powup = rand() % 3 + 1;
	pozitiecursor(xpow, ypow);
	ascunderecursor();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	cout << '?';
}
void declarare() {
	scor = 0;
	nivel = 1;
	somn = 200;
	nrsarpe = 0;
	meniu = 0;
}
void declararemoulty() {
	meniu = 0;
	scor1 = 0;
	scor2 = 0;
	nrsarpe1 = 0;
	nrsarpe2 = 0;
}
void pause() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	cout << '\n' << "\n\n\n";
	cout << "   " << char(201) << char(205) << char(205) << char(205) << char(205) << char(187) << "  " << char(201) << char(205) << char(205) << char(205) << char(205) << char(187) << "  " << char(186) << "    " << char(186) << "  " << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << "  " << char(201) << char(205) << char(205) << char(205) << char(205);
	cout << "   " << '\n';
	cout << "   " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "       " << char(186) << '\n';
	cout << "   " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "       " << char(186) << '\n';
	cout << "   " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "       " << char(186) << '\n';
	cout << "   " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "       " << char(186) << '\n';
	cout << "   " << char(204) << char(205) << char(205) << char(205) << char(205) << char(188) << "  " << char(204) << char(205) << char(205) << char(205) << char(205) << char(185) << "  " << char(186) << "    " << char(186) << "  " << char(200) << char(205) << char(205) << char(205) << char(205) << char(187) << "  " << char(204) << char(205) << char(205) << '\n';
	cout << "   " << char(186) << "    " << "   " << char(186) << "  " << "  " << char(186) << "  " << char(186) << "    " << char(186) << "  " << "     " << char(186) << "  " << char(186) << '\n';
	cout << "   " << char(186) << "    " << "   " << char(186) << "  " << "  " << char(186) << "  " << char(186) << "    " << char(186) << "  " << "     " << char(186) << "  " << char(186) << '\n';
	cout << "   " << char(186) << "    " << "   " << char(186) << "  " << "  " << char(186) << "  " << char(186) << "    " << char(186) << "  " << "     " << char(186) << "  " << char(186) << '\n';
	cout << "   " << char(186) << "    " << "   " << char(186) << "  " << "  " << char(186) << "  " << char(186) << "    " << char(186) << "  " << "     " << char(186) << "  " << char(186) << '\n';
	cout << "   " << char(186) << "    " << "   " << char(186) << "  " << "  " << char(186) << "  " << char(200) << char(205) << char(205) << char(205) << char(205) << char(188) << "  " << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << "  " << char(200) << char(205) << char(205) << char(205) << char(205) << '\n';
	cout << '\n';
	cout << "        Pentru a reveni apasati X!\n";

	cin >> optiune;
	while (optiune != 'x'&&optiune != 'X') {
		pozitiecursor(0, 17);
		cout << "                                                                           ";
		pozitiecursor(0, 17);
		cin >> optiune;
	}
	cin.getline(golire, 400);
	if (optiune == 'x' || optiune == 'X') {
		system("cls");
		afisare();
		pozitiecursor(fructx, fructy);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
		cout << '*';
		pozitiecursor(xpow, ypow);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
		cout << '?';
	}
	else {
		system("cls");
			pause();

	}
}
int snake;
void player1win() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	cout << "\n\n\n\n              PLAYER 1 WIN!\n\n                  Scor:"<<scor1<<"\n\n\n\n    Pentru a reveni la meniu apasati M!\n         Pentru a iesi apasati X!\n";
	cin >> optiune;
	while (optiune != 'm'&&optiune != 'M'&&optiune != 'x'&&optiune != 'X') {
		pozitiecursor(0, 11);
		cout << "                                                                           ";
		pozitiecursor(0, 11);
		cin >> optiune;
	}
	cin.getline(golire, 400);
	if (optiune == 'M' || optiune == 'm') {
		system("cls");
		menu();
	}
	else {
		if (optiune == 'x' || optiune == 'X') {
			exit(EXIT_FAILURE);
		}
		else player1win();
	}
}
void player2win() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	cout << "\n\n\n\n              PLAYER 2 WIN!\n\n                  Scor:" << scor2 << "\n\n\n\n    Pentru a reveni la meniu apasati M!\n         Pentru a iesi apasati X!\n";
	cin >> optiune;
	while (optiune != 'm'&&optiune != 'M'&&optiune != 'x'&&optiune != 'X') {
		pozitiecursor(0, 11);
		cout << "                                                                           ";
		pozitiecursor(0, 11);
		cin >> optiune;
	}
		cin.getline(golire, 400);
	if (optiune == 'M' || optiune == 'm') {
		system("cls");
		menu();
	}
	else {
		if (optiune == 'x' || optiune == 'X') {
			exit(EXIT_FAILURE);
		}
		else player2win();
	}
}
void culoare() {
	snake = rand() % 16;
	while (snake < 1) {
		snake = rand() % 16;
	}
}
void menu() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 60;
	cfi.dwFontSize.Y = 80;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	optiune = 0;
	cout << "            " << "SNAKE";
	cout << '\n';
	cout << "\n          :Oooooooo\n\n";
	cout << "1.Single Player\n";
	cout << "2.Multiplayer\n";
	cout << "Pentru a iesi,apasati tasta X!\n";
	cin >> optiune;
	ifstream f("highscore.txt");
	f >> nivelh;
	f.close();
	if (nivel > nivelh) {
		ofstream g("highscore.txt");
		g << nivel;
		g.close();
		nivelh = nivel;
	}
	else {
		ofstream g("highscore.txt");
		g << nivelh;
		g.close();
	}
	while (optiune != 1 + '0' && optiune != 2 + '0' && optiune != 'x' && optiune != 'X') {
		pozitiecursor(0, 7);
		cout << "                                                                           ";
		pozitiecursor(0, 7);
		cin >> optiune;
	}
	cin.getline(golire,400);
	if (optiune == 1 + '0' || optiune == 2 + '0' || optiune == 'x' || optiune == 'X') {
		if (optiune == 'x' || optiune == 'X') {
			exit(EXIT_FAILURE);
		}
		if (optiune == 2 + '0') {
			CONSOLE_FONT_INFOEX cfi;
			cfi.cbSize = sizeof cfi;
			cfi.nFont = 0;
			cfi.dwFontSize.X = 40;
			cfi.dwFontSize.Y = 40;
			cfi.FontFamily = FF_DONTCARE;
			cfi.FontWeight = FW_NORMAL;

			SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
			declararemoulty();
			culoare();
			snake1 = snake;
			snake2 = abs(snake1 - 2);
			if (snake2 == 0)snake2 += 4;
			afisaremoulty();
			startmoulty();
			pozitiecursor(xsarpe1, ysarpe1);
			while (oprirejoc == false) {
				input1();
				input2();
				miscare1();
				miscare2();
				if (nrsarpe1 == 0) {
					pozitiecursor(xsarpe1, ysarpe1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake1);
					cout << 'O';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
				}
				if (nrsarpe2 == 0) {
					pozitiecursor(xsarpe2, ysarpe2);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake2);
					cout << 'O';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
				}
				Sleep(200);
			}
			if (meniu == 1) {
				system("cls");
				menu();
			}

		}

		if (optiune == 1 + '0') {
			CONSOLE_FONT_INFOEX cfi;
			cfi.cbSize = sizeof cfi;
			cfi.nFont = 0;
			cfi.dwFontSize.X = 40;
			cfi.dwFontSize.Y = 40;
			cfi.FontFamily = FF_DONTCARE;
			cfi.FontWeight = FW_NORMAL;

			SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
			declarare();
			culoare();
			afisare();
			powerup();
			pozitiecursor(42, 7);
			cout << "  ";
			pozitiecursor(42, 7);
			cout << nivelh;
			start();

			while (oprirejoc == false) {
				input();
				miscare();
				if (nrsarpe == 0) {
					pozitiecursor(x, y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake);
					cout << 'O';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
				}
				Sleep(somn);
				if (scor == 100 && scor > 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);

					nivel++;
					if (nivel == 10) {
						system("cls");
						oprirejoc = true;
						felicitari();
					}
					scor = 0;
					pozitiecursor(37, 2);
					ascunderecursor();
					cout << "   ";
					pozitiecursor(37, 2);
					ascunderecursor();
					cout << scor;
					pozitiecursor(38, 4);
					ascunderecursor();
					cout <<"   ";
					pozitiecursor(38, 4);
					ascunderecursor();
					cout << nivel;
					pozitiecursor(x, y);
					ascunderecursor();
					somn = somn - 20;
				}
			}
			if (meniu == 1) {
				system("cls");
				menu();
			}
			Beep(800, 200);
			Beep(700, 300);
			Beep(600, 400);
			Beep(500, 1000);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
			gameover();

		}
	}
	else {
		system("cls");
		menu();
	}
}
void gameover()
{
	cout << "                 GAME OVER\nLEVEL:" << nivel << '\n' << "SCOR:" << scor << '\n';
	cout << "Pentru a reveni la meniu apasati M\n";
	cout << "Pentru a iesi apasati X\n";
	cin >> optiune;
	if (optiune == 'M' || optiune == 'm') {
		system("cls");
		menu();
	}
	else if (optiune == 'X' || optiune == 'x') {

		exit(EXIT_FAILURE);
	}
	else {
		system("cls");
		gameover();
	}
}
void startmoulty() {
	oprirejoc = false;
	xsarpe1 = rand() % 18 + 1;
	ysarpe1 = rand() % 18+ 1;
	xsarpe2 = rand() % 18 + 1;
	ysarpe2 = rand() % 18 + 1;
	while (ysarpe1 == ysarpe2&&xsarpe1 == xsarpe2) {
		xsarpe2 = rand() % 18 + 1;
		ysarpe2 = rand() % 18 + 1;
	}
	sarpe1[nrsarpe1].x = xsarpe1;
	sarpe1[nrsarpe1].y = ysarpe1;
	sarpe2[nrsarpe2].x = xsarpe2;
	sarpe2[nrsarpe2].y = ysarpe2;
	fructx = rand() % width;
	fructy = rand() % height;
	while (fructx < 1 || fructy < 1) {
		fructx = rand() % width;
		fructy = rand() % height;
	}
	dir1 = STOP;
	dir2 = STOP;
	pozitiecursor(xsarpe1, ysarpe1);
	ascunderecursor();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake1);
	cout << 'O';
	pozitiecursor(xsarpe2, ysarpe2);
	ascunderecursor();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake2);
	cout << 'O';
	pozitiecursor(fructx, fructy);
	ascunderecursor();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);

	cout << '*';
	pozitiecursor(x, y);
	ascunderecursor();

}
void start() {
	dublare = 0;
	oprirejoc = false;
	x = width / 2;
	y = height / 2;
	sarpe[nrsarpe].x = x;
	sarpe[nrsarpe].y = y;
	fructx = rand() % width;
	fructy = rand() % height;
	while (fructx < 1 || fructy < 1) {
		fructx = rand() % width;
		fructy = rand() % height;
	}
	dir = STOP;
	pozitiecursor(x, y);
	ascunderecursor();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake);
	cout << 'O';
	pozitiecursor(fructx, fructy);
	ascunderecursor();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);

	cout << '*';
	pozitiecursor(x, y);
	ascunderecursor();

}
void afisare() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);

	system("cls");
	cout << char(201);
	for (int i = 1; i <= width + 1; i++)
		cout << char(205);
	cout << char(187);
	cout << '\n';
	for (int i = 0; i < height + 1; i++) {
		for (int j = 0; j <= width + 1; j++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
			int gasit = 0;
			bool print = true;
			if (j == 0)cout << char(186);
			else  print = false;
			if (print != true)cout << ' ';
			if (j == width + 1)cout << char(186);
		}
		if (i == 0)cout << "       " << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191);
		if (i == 1) {
			cout << "       " << char(179) << " Scor:" << scor;
			if (scor == 0)cout << "    " << char(179);
			else if (scor >= 10 && scor<100)cout << "   " << char(179);
			else cout << "   " << '|';
		}
		if (i == 2)cout << "       " << char(195) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(180);
		if (i == 3)cout << "       " << char(179) << " Level:" << nivel << "   " << char(179);
		if (i == 4)cout << "       " << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217);
		if (i == 6)cout << "Level maxim atins: "<< nivelh;
		if (i == 8)cout << "Powerup: " << '-';
		if (i == 10)cout << "       Taste:";
		if (i == 12)cout << "       W(SUS)";
		if (i == 14)cout << " A(STANGA) D(DREAPTA)";
		if (i == 16)cout << "       S(JOS)";
		cout << '\n';
	}
	cout << char(200);
	for (int i = 1; i <= width + 1; i++) {
		cout << char(205);
	}
	cout << char(188);
	cout << '\n';
	cout << "Apasati tasta :\n BACKSPACE pentru a reveni la meniu\n ESC pentru Pauza\n X pentru a iesi";
}
void afisaremoulty() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);

	system("cls");
	cout << char(201);
	for (int i = 1; i <= width + 1; i++)
		cout << char(205);
	cout << char(187);
	cout << '\n';
	for (int i = 0; i < height + 1; i++) {
		for (int j = 0; j <= width + 1; j++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
			int gasit = 0;
			bool print = true;
			if (j == 0)cout << char(186);
			else  print = false;
			if (print != true)cout << ' ';
			if (j == width + 1)cout << char(186);
		}
		if (i == 0)cout << "       " << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191);
		if (i == 1) {
			cout << "       " << char(179) << " Scor1:" << scor1;
			if (scor == 0)cout << "   " << char(179);
			else if (scor >= 10 && scor < 100)cout << "   " << char(179);
			else cout << "  " << '|';
		}
		if (i == 2)cout << "       " << char(195) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(180);
		if (i == 3) {
			cout << "       " << char(179) << " Scor2:" << scor2;
			if (scor == 0)cout << "   " << char(179);
			else if (scor >= 10 && scor < 100)cout << "   " << char(179);
			else cout << "  " << '|';
		}	
		if (i == 4)cout << "       " << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217);
		if (i == 6) {
			cout << "Culoare Player1: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake1);
			cout << char(219);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		}
		if (i ==8) {
			cout << "Culoare Player2: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake2);
			cout << char(219);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		}
		cout << '\n';
	}
	cout << char(200);
	for (int i = 1; i <= width + 1; i++) {
		cout << char(205);
	}
	cout << char(188);
	cout << '\n';
	cout << "Apasati tasta :\n BACKSPACE pentru a reveni la meniu\n ESC pentru Pauza\n X pentru a iesi!";
}
void fructmoulty() {
	int ok = 1;
	fructx = rand() % width;
	fructy = rand() % height;
	while (fructx < 1 || fructy < 1) {
		fructx = rand() % width;
		fructy = rand() % height;
	}
	for (int i = 0; i <= nrsarpe1; i++) {
		if (fructx == sarpe1[i].x&&fructy == sarpe1[i].y) {
			ok = 0;
			i = nrsarpe1 + 1;
		}
	}
	for (int i = 0; i <= nrsarpe2; i++) {
		if (fructx == sarpe2[i].x&&fructy == sarpe2[i].y) {
			ok = 0;
			i = nrsarpe2 + 1;
		}
	}
	if (ok == 0)fructmoulty();
	pozitiecursor(fructx, fructy);
	ascunderecursor();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	cout << '*';
	//pozitiecursor(x, y);
	ascunderecursor();

}
void fruct() {
	int ok = 1;
	fructx = rand() % 18+1;
	fructy = rand() % 18+1;
	while (fructx < 1 || fructy < 1) {
		fructx = rand() % 18+1;
		fructy = rand() % 18+1;
	}
	for (int i = 0; i <= nrsarpe; i++) {
		if (fructx == sarpe[i].x&&fructy == sarpe[i].y) {
			ok = 0;
			i = nrsarpe + 1;
		}
	}
	if (fructx == xpow&&fructy == ypow)fruct();
	if (ok == 0)fruct();
	pozitiecursor(fructx, fructy);
	ascunderecursor();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	cout << '*';
	pozitiecursor(x, y);
	ascunderecursor();

}
void input1() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (dir1 != RIGHT || nrsarpe1 == 0)dir1 = LEFT;
			break;
		case 'd':
			if (dir1 != LEFT || nrsarpe1 == 0)dir1 = RIGHT;
			break;
		case 'w':
			if (dir1 != DOWN || nrsarpe1 == 0)dir1 = UP;
			break;
		case 's':
			if (dir1 != UP || nrsarpe1 == 0)dir1 = DOWN;
			break;
		case 'A':
			if (dir1 != RIGHT || nrsarpe1 == 0)dir1 = LEFT;
			break;
		case 'D':
			if (dir1 != LEFT || nrsarpe1 == 0)dir1 = RIGHT;
			break;
		case 'W':
			if (dir1 != DOWN || nrsarpe1 == 0)dir1 = UP;
			break;
		case 'S':
			if (dir1 != UP || nrsarpe1 == 0)dir1 = DOWN;
			break;

		case VK_ESCAPE:
			system("cls");
			pause();
			break;
		case 'x':
			exit(EXIT_FAILURE);
		case 'X':
			exit(EXIT_FAILURE);
		case VK_BACK:
			oprirejoc = true;

			meniu = 1;
			break;
		}
	}
}
void input2() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 75:
			if (dir2 != RIGHT || nrsarpe2 == 0)dir2 = LEFT;
			break;
		case 77:
			if (dir2 != LEFT || nrsarpe2 == 0)dir2 = RIGHT;
			break;
		case 72:
			if (dir2 != DOWN || nrsarpe2 == 0)dir2 = UP;
			break;
		case 80:
			if (dir2 != UP || nrsarpe2 == 0)dir2 = DOWN;
			break;
		case VK_ESCAPE:
			system("cls");
			pause();
			break;
		case 'x':
			exit(EXIT_FAILURE);
		case 'X':
			exit(EXIT_FAILURE);
		case VK_BACK:
			oprirejoc = true;

			meniu = 1;
			break;
		}
	}
}
void input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (dir != RIGHT || nrsarpe == 0)dir = LEFT;
			break;
		case 'd':
			if (dir != LEFT || nrsarpe == 0)dir = RIGHT;
			break;
		case 'w':
			if (dir != DOWN || nrsarpe == 0)dir = UP;
			break;
		case 's':
			if (dir != UP || nrsarpe == 0)dir = DOWN;
			break;
		case 'A':
			if (dir != RIGHT || nrsarpe == 0)dir = LEFT;
			break;
		case 'D':
			if (dir != LEFT || nrsarpe == 0)dir = RIGHT;
			break;
		case 'W':
			if (dir != DOWN || nrsarpe == 0)dir = UP;
			break;
		case 'S':
			if (dir != UP || nrsarpe == 0)dir = DOWN;
			break;
		case VK_ESCAPE:
			system("cls");
			pause();
			break;
		case 'x':
			exit(EXIT_FAILURE);
		case 'X':
			exit(EXIT_FAILURE);
		case VK_BACK:
			oprirejoc = true;
			meniu = 1;
			break;
		}
	}
}
void miscare1() {

	switch (dir1)
	{
	case LEFT:
		pozitiecursor(xsarpe1, ysarpe1);
		ascunderecursor();
		cout << ' ';
		xsarpe1--;
		pozitiecursor(xsarpe1, ysarpe1);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake1);
		cout << 'O';
		break;
	case RIGHT:
		pozitiecursor(xsarpe1, ysarpe1);
		ascunderecursor();
		cout << ' ';
		xsarpe1++;
		pozitiecursor(xsarpe1, ysarpe1);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake1);
		cout << 'O';
		break;
	case UP:
		pozitiecursor(xsarpe1, ysarpe1);
		ascunderecursor();
		cout << ' ';
		ysarpe1--;
		pozitiecursor(xsarpe1, ysarpe1);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake1);
		cout << 'O';
		break;
	case DOWN:
		pozitiecursor(xsarpe1, ysarpe1);
		ascunderecursor();
		cout << ' ';
		ysarpe1++;
		pozitiecursor(xsarpe1, ysarpe1);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake1);
		cout << 'O';
		break;
	default:
		break;
	}
	if (xsarpe1 > width + 1 || ysarpe1 > height + 1 || xsarpe1 < 1 || ysarpe1 < 1) {
		oprirejoc = true;
		player2win();
	}
	for (int i = 0; i <= nrsarpe2; i++) {
		if (xsarpe1 == sarpe2[i].x&&ysarpe1 == sarpe2[i].y) {
			oprirejoc = true;
			player2win();
		}
	}
	for (int i = 0; i < nrsarpe1; i++) {
		if (xsarpe1 == sarpe1[i].x&&ysarpe1 == sarpe1[i].y) {
			oprirejoc = true;
			i = nrsarpe1;
			player2win();
		}
	}
	if (xsarpe1 == fructx&&ysarpe1 == fructy) {
		scor1 = scor1 + 10;
		pozitiecursor(38, 2);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
		cout << scor1;
		pozitiecursor(xsarpe1, ysarpe1);
		ascunderecursor();
		fructmoulty();
		Beep(500, 100);
		nrsarpe1 = nrsarpe1 + 1;
		sarpe1[nrsarpe1].x = xsarpe1;
		sarpe1[nrsarpe1].y = ysarpe1;
	}
	else {
		if (sarpe2[0].x != 0 && sarpe2[0].y != 0) {
			pozitiecursor(sarpe1[0].x, sarpe1[0].y);
			ascunderecursor();
			cout << ' ';
		}
		pozitiecursor(xsarpe1, ysarpe1);
		ascunderecursor();
		for (int i = 0; i < nrsarpe1; i++) {
			sarpe1[i].x = sarpe1[i + 1].x;
			sarpe1[i].y = sarpe1[i + 1].y;
		}
		sarpe1[nrsarpe1].x = xsarpe1;
		sarpe1[nrsarpe1].y = ysarpe1;
	}
	for (int i = 0; i < nrsarpe1; i++) {
		pozitiecursor(sarpe1[i].x, sarpe1[i].y);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake1);
		cout << 'o';
	}
	pozitiecursor(xsarpe1, ysarpe1);
	ascunderecursor();
}
void miscare2() {

	switch (dir2)
	{
	case LEFT:
		pozitiecursor(xsarpe2, ysarpe2);
		ascunderecursor();
		cout << ' ';
		xsarpe2--;
		pozitiecursor(xsarpe2, ysarpe2);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake2);
		cout << 'O';
		break;
	case RIGHT:
		pozitiecursor(xsarpe2, ysarpe2);
		ascunderecursor();
		cout << ' ';
		xsarpe2++;
		pozitiecursor(xsarpe2, ysarpe2);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake2);
		cout << 'O';
		break;
	case UP:
		pozitiecursor(xsarpe2, ysarpe2);
		cout << ' ';
		ysarpe2--;
		pozitiecursor(xsarpe2, ysarpe2);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake2);
		cout << 'O';
		break;
	case DOWN:
		pozitiecursor(xsarpe2, ysarpe2);
		ascunderecursor();
		cout << ' ';
		ysarpe2++;
		pozitiecursor(xsarpe2, ysarpe2);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake2);
		cout << 'O';
		break;
	default:
		break;
	}
	if (xsarpe2 > width + 1 || ysarpe2 > height + 1 || xsarpe2 < 1 || ysarpe2 < 1) {
		oprirejoc = true;
		player1win();
	}
	for (int i = 0; i <= nrsarpe1; i++) {
		if (xsarpe2 == sarpe1[i].x&&ysarpe2 == sarpe1[i].y) {
			oprirejoc = true;
			player1win();
		}
	}
	for (int i = 0; i < nrsarpe2; i++) {
		if (xsarpe2 == sarpe2[i].x&&ysarpe2 == sarpe2[i].y) {
			oprirejoc = true;
			i = nrsarpe2;
			player1win();
		}
	}
	if (xsarpe2 == fructx&&ysarpe2 == fructy) {
		scor2 = scor2 + 10;
		pozitiecursor(38, 4);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
		cout << scor2;
		pozitiecursor(xsarpe2, ysarpe2);
		ascunderecursor();
		fructmoulty();
		Beep(500, 100);
		nrsarpe2 = nrsarpe2 + 1;
		sarpe2[nrsarpe2].x = xsarpe2;
		sarpe2[nrsarpe2].y = ysarpe2;
	}
	else {
		if (sarpe2[0].x != 0 && sarpe2[0].y != 0) {
			pozitiecursor(sarpe2[0].x, sarpe2[0].y);
			ascunderecursor();
			cout << ' ';
		}
		pozitiecursor(xsarpe2, ysarpe2);
		ascunderecursor();
		for (int i = 0; i < nrsarpe2; i++) {
			sarpe2[i].x = sarpe2[i + 1].x;
			sarpe2[i].y = sarpe2[i + 1].y;
		}
		sarpe2[nrsarpe2].x = xsarpe2;
		sarpe2[nrsarpe2].y = ysarpe2;
	}
	for (int i = 0; i < nrsarpe2; i++) {
		pozitiecursor(sarpe2[i].x, sarpe2[i].y);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake2);
		cout << 'o';
	}
	pozitiecursor(xsarpe2, ysarpe2);
	ascunderecursor();
}
void miscare() {

	switch (dir)
	{
	case LEFT:
		pozitiecursor(x, y);
		ascunderecursor();
		cout << ' ';
		x--;
		pozitiecursor(x, y);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake);
		cout << 'O';
		break;
	case RIGHT:
		pozitiecursor(x, y);
		ascunderecursor();
		cout << ' ';
		x++;
		pozitiecursor(x, y);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake);
		cout << 'O';
		break;
	case UP:
		pozitiecursor(x, y);
		cout << ' ';
		y--;
		pozitiecursor(x, y);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake);
		cout << 'O';
		break;
	case DOWN:
		pozitiecursor(x, y);
		ascunderecursor();
		cout << ' ';
		y++;
		pozitiecursor(x, y);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake);
		cout << 'O';
		break;
	default:
		break;
	}
	if (x > width + 1 || y > height + 1 || x <1 || y <1)oprirejoc = true;
	for (int i = 0; i < nrsarpe; i++) {
		if (x == sarpe[i].x&&y == sarpe[i].y) {
			oprirejoc = true;
			i = nrsarpe;
		}
	}
	if (x == xpow&&y == ypow) {
		if (timp == 0) {
			timp = 31;
			somn = somn *3/ 2;
		}
		if (powup == 1) {
			dublare = 0;
			nrsarpe = nrsarpe / 2;
			

			for (int i = 0; i <=nrsarpe; i++) {
				pozitiecursor(sarpe[i].x, sarpe[i].y);
				ascunderecursor();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
				cout << ' ';
			}
			for (int i = 0; i <= nrsarpe; i++) {
				sarpe[i].x = sarpe[i + nrsarpe].x;
				sarpe[i].y = sarpe[i + nrsarpe].y;
			}
			pozitiecursor(31, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
			cout << "                   ";
			pozitiecursor(31, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
			cout << "Injumatatire";
		}
		if (powup == 2) {
			dublare = 1;
			pozitiecursor(31, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
			cout << "                   ";
			pozitiecursor(31, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
			cout << "Puncte duble";
		}
		if (powup == 3) {
			dublare = 0;
			timp = 0;
			somn = somn/3*2;
			pozitiecursor(31, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
			cout << "                   ";
			pozitiecursor(31, 9);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
			cout << "Viteza";
		}
		powerup();
		Beep(600, 100);
		pozitiecursor(x, y);
		ascunderecursor();
	}
	if (x == fructx&&y == fructy) {
		pozitiecursor(31, 9);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
		cout << "                                       ";
		pozitiecursor(31, 9);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
		cout << '-';
		if (dublare == 1) {
			scor = scor + 20;
			dublare = 0;
			if (scor > 90) {
				scor = scor % 100;
				nivel++;
				timp=timp-20;
				pozitiecursor(38, 4);
				ascunderecursor();
				cout << "  ";
				pozitiecursor(38, 4);
				ascunderecursor();
				cout << nivel;
				if (nivel == 10) {
					system("cls");
					oprirejoc = true;
					felicitari();
				}

			}
		}
		else scor = scor + 10;
		if (timp == 0) {
			timp = 31;
			somn = somn * 3 / 2;
		}
		pozitiecursor(37, 2);
		ascunderecursor();
		cout << "  ";
		pozitiecursor(37, 2);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
		cout << scor;
		pozitiecursor(x, y);
		ascunderecursor();
		fruct();
		Beep(500, 100);
		nrsarpe = nrsarpe + 1;
		sarpe[nrsarpe].x = x;
		sarpe[nrsarpe].y = y;
	}
	else{
		pozitiecursor(sarpe[0].x, sarpe[0].y);
		ascunderecursor();
		cout << ' ';
		pozitiecursor(x, y);
		ascunderecursor();
		for (int i = 0; i < nrsarpe; i++) {
			sarpe[i].x = sarpe[i + 1].x;
			sarpe[i].y = sarpe[i + 1].y;
		}
		sarpe[nrsarpe].x = x;
		sarpe[nrsarpe].y = y;
	}
	for (int i = nrsarpe-1; i >= 0; i--) {
		pozitiecursor(sarpe[i].x, sarpe[i].y);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake);
		cout << 'o';
	}
}
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("TITLE SNAKE");
	menu();
}
