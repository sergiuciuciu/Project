#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

void instructiuni();
void ascunderecursor();
void pozitiecursor(short x, short y);

void start();
void afisare();
void fruct();
void miscare();
void input();
void gameover();
void culoare();
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
char revenire = NULL;
int width = 20;
//int x1, x2, y1, y2;
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
void declararemoulty() {
	scor1 = 0;
	scor2 = 0;
	nrsarpe1 = 0;
	nrsarpe2 = 0;
}
void pause() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	cout << '\n'<<"\n\n\n";
	cout <<"   "<< char(201) << char(205) << char(205) << char(205) << char(205) << char(187) << "  " << char(201) << char(205) << char(205) << char(205) << char(205) << char(187) << "  " << char(186) << "    " << char(186) <<"  "<<char(201)<<char(205)<<char(205) << char(205) << char(205)<<char(205)<<"  "<< char(201)<<char(205) << char(205) << char(205) << char(205);
	cout << "   " << '\n';
	cout << "   " <<char(186) << "    "<< char(186)<<"  "<< char(186) <<"    "<< char(186) <<"  "<<char(186) << "    " << char(186) << "  "<<char(186) << "       " <<char(186)<< '\n';
	cout << "   " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186)<<"  " << char(186) << "    " << char(186) << "  " << char(186) << "       "<<char(186) << '\n';
	cout << "   "<< char(186) << "    " <<char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "       " << char(186) <<'\n';
	cout << "   " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "    " << char(186) << "  " << char(186) << "       " << char(186) <<'\n';
	cout << "   " << char(204) << char(205) << char(205) << char(205) << char(205) << char(188) <<"  "<<char(204)<<char(205) << char(205) << char(205) << char(205) <<char(185) << "  " << char(186) << "    " << char(186) << "  " <<char(200)<< char(205) << char(205) << char(205) << char(205)<<char(187) << "  " <<char(204)<<char(205)<<char(205)<< '\n';
	cout << "   " << char(186) << "    " << "   " <<char(186) << "  "  << "  " << char(186) << "  " << char(186) << "    " << char(186) << "  " <<"     " << char(186) << "  " << char(186) << '\n';
	cout << "   " << char(186) << "    " << "   "<< char(186) << "  "  << "  " << char(186) << "  " << char(186) << "    " << char(186) << "  " << "     "<<char(186) << "  " << char(186)<<'\n';
	cout << "   " << char(186) << "    " << "   "<< char(186) << "  "  << "  " << char(186) << "  " << char(186) << "    " << char(186) << "  " <<  "     "<<char(186) << "  " << char(186)<<'\n';
	cout << "   " << char(186) << "    " << "   "<< char(186) << "  "  << "  " << char(186) << "  " << char(186) << "    " << char(186) << "  " << "     " <<char(186) << "  " << char(186)<< '\n';
	cout << "   " << char(186) << "    " << "   "<< char(186) << "  "  << "  " << char(186) <<"  "<<char(200)<<char(205) << char(205) << char(205) << char(205) <<char(188) << "  "<<char(205) << char(205) << char(205) << char(205) << char(205) <<char(188) << "  " <<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<< '\n';
	cout << '\n';
	cout << "        Pentru a reveni apasati X!";
	cin >> optiune;
	if (optiune == 'x' || optiune == 'X') {
		system("cls");
		afisare();
		pozitiecursor(fructx, fructy);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
		cout << '*';
	}
	else {
		system("cls");
		pause();

	}
}
int snake;

void culoare() {
	snake = rand() % 16;
	while (snake < 1) {
		snake = rand() % 16;
	}
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
	cout << "1.Singler Player\n";
	cout << "2.Multiplayer\n";
	cout << "Pentru a iesi,apasati tasta X!\n";
	cin >> optiune;
	if (optiune == 1 + '0' || optiune == 2 + '0' || optiune == 'x' || optiune == 'X') {
		if (optiune == 'x' || optiune == 'X')exit(EXIT_FAILURE);
		if (optiune == 2) {
			CONSOLE_FONT_INFOEX cfi;
			cfi.cbSize = sizeof cfi;
			cfi.nFont = 0;
			cfi.dwFontSize.X = 40;
			cfi.dwFontSize.Y = 40;
			cfi.FontFamily = FF_DONTCARE;
			cfi.FontWeight = FW_NORMAL;
			SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
			declararemoulty();


			
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
			start();

			while (oprirejoc == false) {
				input();
				miscare();
				Sleep(somn);
				if (scor == 100 && scor > 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
					nivel++;
					scor = 0;
					pozitiecursor(37, 2);
					ascunderecursor();
					cout << "   ";
					pozitiecursor(37, 2);
					ascunderecursor();
					cout << scor;
					pozitiecursor(40, 4);
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
/*void startmoulty() {
	oprirejoc = false;
	x1 = rand() % 20;
	y1 = rand() % 20;
	x2 = rand() % 20;
	y2 = rand() % 20;
	while (y1 == y2&&x1 == x2) {
		x2 = rand() % 20;
		y2 = rand() % 20;
	}

}*/
void start() {
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
	for (int i = 0; i < height+1; i++) {
		for (int j = 0; j <= width+1; j++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
			int gasit = 0;
			bool print = true;
			if (j == 0)cout << char(186);
			else  print = false;
			if (print != true)cout << ' ';
			if (j == width+1)cout << char(186);
		}
		if (i == 0)cout << "       "<<char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)<<char(191);
		if (i == 1) {
			cout << "       " <<char(179)<< " Scor:" << scor;
			if (scor == 0)cout << "    " << char(179);
			else if (scor >= 10 && scor<100)cout << "   " << char(179);
			else cout << "   " << '|';
		}
		if (i == 2)cout << "       "<< char(195)<<char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196)<<char(196)<<char(180);
		if (i == 3)cout << "       " <<char(179)<< " Level:" << nivel << "   " << char(179);
		if (i == 4)cout << "       "<<char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) <<char(217);
		if (i == 6)cout << "       Taste:";
		if (i == 8)cout << "       W(UP)";
		if (i == 10)cout << "  A(LEFT)  D(RIGHT)";
		if (i == 12)cout << "       S(DOWN)";
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
void fruct() {
	int ok = 1;
	fructx = rand() % width;
	fructy = rand() % height;
	while (fructx < 1 || fructy < 1) {
		fructx = rand() % width;
		fructy = rand() % height;
	}
	for (int i = 0; i <= nrsarpe; i++) {
		if (fructx == sarpe[i].x&&fructy == sarpe[i].y) {
			ok = 0;
			i = nrsarpe + 1;
		}
	}
		if (ok == 0)fruct();
		pozitiecursor(fructx, fructy);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
		cout << '*';
		pozitiecursor(x, y);
		ascunderecursor();

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
	if (x > width+1 || y > height+1 || x <1 || y <1)oprirejoc = true;
	for (int i = 0; i < nrsarpe; i++) {
		if (x == sarpe[i].x&&y == sarpe[i].y) {
			oprirejoc = true;
			i = nrsarpe;
		}
	}
	if (x == fructx&&y == fructy) {
		scor = scor + 10;
		pozitiecursor(37,2);
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
	else {
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
	for (int i = 0; i < nrsarpe; i++) {
		pozitiecursor(sarpe[i].x, sarpe[i].y);
		ascunderecursor();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), snake);
		cout << 'o';
	}
	pozitiecursor(x, y);
	ascunderecursor();
}
int main() 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("TITLE SNAKE"); 
	menu();
}
