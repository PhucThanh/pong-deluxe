#include "Console.h"

Console::Console()
{
	SetConsoleTitle(TEXT("Pong"));

	/* Khoá phóng to và co giãn cửa sổ console */
	// lấy id console 
	HWND consoleWindow = GetConsoleWindow();
	// lấy giá trị cấu hình cửa sổ
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	//tắt nút phóng to và co giãn console
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	// Đặt lại giá trị cấu hình của cửa sổ
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	/*http://www.cplusplus.com/forum/beginner/95699/*/
	/* Cấu hình vị trí cửa sổ trên màn hình */
	SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	/*https://stackoverflow.com/questions/33975912/how-to-set-console-font-to-raster-font-programmatically*/
	/* Cấu hình font của cửa sổ để hiện phần tên game ổn định */
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = font_x;
	cfi.dwFontSize.Y = font_y;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	//Font chạy ổn định nhất: Lucida Console
	wcscpy_s(cfi.FaceName, L"Lucida Console");
	//wcscpy_s(cfi.FaceName, L"Consolas");

	//lấy con trỏ giữ màn hình
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetCurrentConsoleFontEx(handle, FALSE, &cfi);
	/*https://stackoverflow.com/questions/21238806/how-to-set-output-console-width-in-visual-studio*/
	/* Cấu hình kích thước  */
	MoveWindow(consoleWindow, 0, 0, console_width, console_height, TRUE);
	/*https://cboard.cprogramming.com/cplusplus-programming/97959-[ask]-how-remove-scrollbar.html*/
	/*Xoá thanh trượt*/
	CONSOLE_SCREEN_BUFFER_INFO info;

	//Lấy cấu hình buffer của màn hình
	GetConsoleScreenBufferInfo(handle, &info);
	//Cấu hình lại sao cho buffer của màn hình giống với kích thước của màn hình
	COORD new_size = {
		(short int)(info.srWindow.Right - info.srWindow.Left + 1),
		(short int)(info.srWindow.Bottom - info.srWindow.Top + 1),
	};
	//Đặt lại theo cấu hình mới
	SetConsoleScreenBufferSize(handle, new_size);
	HideCursor();
}
Console::~Console()
{

}

void Console::GoToXY(int x1, int y1)		//dua con tro toi vi tri chi dinh
{
	x = x1; y = y1;
	HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void Console::ChangeColorText(int color)	//doi mau console
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}

void Console::HideCursor()			//xoa dau con tro
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 10;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

//void Console::resizeConsole(int width, int height)		//thay doi kich thuoc console
//{
//	HANDLE h = NULL;
//	h = GetStdHandle(STD_OUTPUT_HANDLE);
//	SMALL_RECT DisplayArea = { 0, 0, width, height + 3 };
//	SetConsoleWindowInfo(h, TRUE, &DisplayArea);
//}

void Console::DrawConsole(int color)		//tao console
{
	ChangeColorText(color);					//chon mau console
	for (int i = 0; i < console_width + 1; ++i)
		cout << '_';						//ve bien tren
	for (int i = 0; i < console_height - 1 ; ++i)
	{
		cout << endl << static_cast<char>(219) << static_cast<char>(219);		//ve bien trai
		for (int i = 0; i < console_width - 3; ++i)		//dua con tro den bien phai
			cout << ' ';
		cout << static_cast<char>(219) << static_cast<char>(219);				//ve bien phai
	}
	cout << endl;
	for (int i = 0; i < console_width + 1; ++i)
		cout << '_';					//ve bien duoi
	cout << endl << "\tPlayer 1 \t \t Player 2" << endl << endl;		//ve bang diem
	for (int i = 0; i < console_width + 1; ++i)
		cout << '_';					//khung duoi bang diem
}

void Console::DrawConsoleBOT(int color)		//Tuong tu cai tren
{
	ChangeColorText(color);
	for (int i = 0; i < console_width + 1; ++i)
		cout << '_';
	for (int i = 0; i < console_height - 1; ++i)
	{
		cout << endl << static_cast<char>(219) << static_cast<char>(219);
		for (int i = 0; i < console_width - 3; ++i)
			cout << ' ';
		cout << static_cast<char>(219) << static_cast<char>(219);
	}
	cout << endl;
	for (int i = 0; i < console_width + 1; ++i)
		cout << '_';
	cout << endl << "\tPlayer \t \t \t  BOT" << endl << endl;
	for (int i = 0; i < console_width + 1; ++i)
		cout << '_';
}

