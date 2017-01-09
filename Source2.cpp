#include <iostream>
#include <conio.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
using namespace std;

void instructiuni();
void start();
void afisare();
void fruct();
void miscare();
void input();
void gameover();
char optiune = 0;
char revenire = NULL;
int width = 20;
int height = 20;
int meniu = 0;
int x, y, fructx, fructy, scor = 0, nivel = 1, somn = 200,nrsarpe=0,schimbare;
bool oprirejoc;
struct coada {
	int x, y;
};
coada sarpe[400];
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;
void declarare(){
	scor = 0;
	nivel = 1;
	somn = 200;
	nrsarpe = 0;
	meniu = 0;
}
void menu() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 60;
	cfi.dwFontSize.Y = 80;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	optiune = 0;
	cout << "            "<<"SNAKE";
	cout << '\n';
	cout << "\n          :Oooooooo\n\n";
	cout << "1.Start Game\n";
	cout << "2.Instructiuni joc\n";
	cout << "Pentru a iesi,apasati tasta X!\n";
	cin >> optiune;
	if (optiune == 1 + '0' || optiune == 2 + '0' || optiune == 'x' || optiune == 'X') {
		if (optiune == 'x' || optiune == 'X')exit(EXIT_FAILURE);
		if (optiune == 2 + '0') {
			system("cls");
			instructiuni();
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
			start();
			while (oprirejoc == false) {
				afisare();
				input();
				miscare();
				Sleep(somn);
				if (scor == 100 && scor > 0) {
					nivel++;
					scor = 0;
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
void instructiuni() {
	cout << "Trebuie sa colectati * (punctele) fara a va intersecta cu marginile chenarului si fara\na va musca propria coada.Fiecare punct colectat va creste dimensiunea sarpelui si va \nadauga 10 puncte la scorul dv.Odata ce veti atinge 100 puncte nivelul dv va creste.\nCresterea nivelului consta in rapiditate cu care se va misca sarpele,cu cat nivelul va\nfi mai mare,cu atat sarpele va avea o viteza mai ridicata.\n";
	cout << "Butoanele sunt:\n" << "           W(sus)\n" << "A(stanga)  S(jos)  D(dreapta)\n";
	cout << "Pentru a iesi apasati tasta X!\n";
	cout << "Pentru a reveni la meniu apasati tasta M!\n";
	cin >> optiune;
	if (optiune == 'x' || optiune == 'X') exit(EXIT_FAILURE);
	else if (optiune == 'm' || optiune == 'M') {
		system("cls");
		menu();
	}
	else {
		system("cls");
		instructiuni();
	}

}
void start() {
	oprirejoc = false;
	x = width / 2;
	y = height / 2;
	sarpe[nrsarpe].x = x;
	sarpe[nrsarpe].y = y;
	fructx = rand() % width;
	fructy = rand() % height;
	dir = STOP;
}
void afisare() {
	system("cls");
	cout << '.';
	for (int i = 1; i <= width + 1; i++)
		cout << '-';
	cout << '.';
	cout << '\n';
	for (int i = 0; i < height+1; i++) {
		for (int j = 0; j <= width; j++) {
			int gasit = 0;
			bool print = true;
			if (j == 0)cout << '|';
			for (int snake = 0; snake <= nrsarpe; snake++) {
				if (i == sarpe[snake].y&&j == sarpe[snake].x) {
					gasit = 1;
					if (snake == nrsarpe)cout << 'O';
					else cout << 'o';
				}
			}
		    if (j == fructx&&i == fructy&&gasit==0)cout << '*';
			else if(gasit==0) print = false;
			if (print != true)cout << ' ';
			if (j == width)cout << '|';
		}
		if (i == 0)cout << "       " << " ___________";
		if (i == 1) {
			cout << "       " << "| Scor:" << scor;
			if (scor == 0)cout << "    " << '|';
			else if (scor >= 10 && scor<100)cout << "   " << '|';
			else cout << "   " << '|';
		}
		if (i == 2)cout << "       " << "|___________|";
		if (i == 3)cout << "       " << "| Level:" << nivel << "   " << '|';
		if (i == 4)cout << "       " << "|___________|";
		cout << '\n';
	}
	cout << '.';
	for (int i = 1; i <= width + 1; i++) {
		cout << '-';
	}
	cout << '.';
	cout << '\n';
	cout << "Apasati tasta :\n BACKSPACE pentru a reveni la meniu\n ESC pentru a parasi jocul";
}
void fruct() {
	int ok = 1;
	fructx = rand() % width;
	fructy = rand() % height;
	for (int i = 0; i <= nrsarpe; i++) {
		if (fructx == sarpe[i].x&&fructy == sarpe[i].y) {
			ok = 0;
			i = nrsarpe + 1;
		}
	}
		if (ok == 0)fruct();
}
void input() {
	schimbare = 0;
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (dir != RIGHT||nrsarpe==0)dir = LEFT;
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
			exit(EXIT_FAILURE);
		case VK_BACK:
			oprirejoc = true;
			meniu = 1;
			break;
		}
	}
}
void miscare() {
	
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width || y > height || x < 0 || y < 0)oprirejoc = true;
	for (int i = 0; i < nrsarpe; i++) {
		if (x == sarpe[i].x&&y == sarpe[i].y) {
			oprirejoc = true;
			i = nrsarpe;
		}
	}
	if (x == fructx&&y == fructy) {
		scor = scor + 10;
		fruct();
		Beep(500, 100);

		nrsarpe = nrsarpe + 1;
		sarpe[nrsarpe].x = x;
		sarpe[nrsarpe].y = y;
	}
	else {
		for (int i = 0; i < nrsarpe; i++) {
			sarpe[i].x = sarpe[i + 1].x;
			sarpe[i].y = sarpe[i + 1].y;
		}
		sarpe[nrsarpe].x = x;
		sarpe[nrsarpe].y = y;
	}
}
int main() {
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(outcon, 0x0C);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("TITLE SNAKE"); 
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);

	menu();
}
