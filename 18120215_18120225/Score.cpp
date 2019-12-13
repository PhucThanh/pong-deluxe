#include "Score.h"
Score::Score()
{
	_levelScore = 0;//Score dua tren so box bi tieu diet trong 1 level
	_totalScore = 0;//Tong so score
	ifstream inf;
	string line_info;
	int score;
	int i = 0;
	inf.open("HighScore.txt");
	while (!inf.eof())
	{
		getline(inf, line_info);
		score = atoi(line_info.substr(line_info.find("|") + 1).c_str());
		line_info = line_info.substr(0, line_info.find("|"));
		_vecHighScore.push_back(pair<string, int>(line_info, score));
	}
	inf.close();
	_bestScore = _vecHighScore[0].second;
}
void Score::reset_Score() 
{
	_levelScore = 0;//Score dua tren so box bi tieu diet trong 1 level
	_totalScore = 0;//Tong so score
}
Score::~Score()
{
	ofstream onf;
	int i = 0;
	onf.open("HighScore.txt");//ghi file
	while (i < 10 && i < _vecHighScore.size())// dieu kien sau de tranh out of range
	{
		onf << _vecHighScore[i].first << "|" << _vecHighScore[i].second << endl;
		i++;
	}
}

void Score::update_LevelScore(BoxManager& bm,int& level)
{
	_levelScore = (95+level*5)*bm.count_DestroyedBox();
	//100 for each box and 200 for every level
	//Vi 1 ly do nao do level bi + den 2 lan
	//cho nen (level-1)*500 nghia la qua 1 man duoc tang 1000 diem
}
void Score::update_Score(BoxManager& bm,int& level)
{
	update_LevelScore(bm,level);
	if (_totalScore+_levelScore < _bestScore)// So sanh voi best score
	{
		Graphic::DrawRec(game_width * 2 / 3 + 14, game_height, game_width * 2 / 3 + 22, game_height, ' ', 0);
		draw_Score(game_width * 2 / 3 + 14, game_height, _totalScore+_levelScore);
		draw_Score(1 + 14, game_height, _bestScore);
	}
	else
	{
		Graphic::DrawRec(game_width * 2 / 3 + 14, game_height, game_width * 2 / 3 + 22, game_height, ' ', 0);
		draw_Score(game_width * 2 / 3 + 14, game_height, _totalScore+_levelScore);
		draw_Score(1 + 14, game_height, _totalScore + _levelScore);
	}
	
	if (bm.Win())// update score khi thang
	{
		_totalScore += _levelScore;
		_levelScore = 0;
	}
}
void Score::draw_Score(int x, int y, int score)//Ham ve diem
{
	Graphic::DrawString(x, y, std::to_string(score), 15);
}
string Score::get_Player()
{
	_totalScore += _levelScore;
	Graphic::DrawBox(game_width / 3-5, game_height / 3, game_width * 2 / 3+5, game_height / 3 + 14, 0x000F);

	Graphic::DrawString(game_width / 3+2, game_height / 3 + 2,		"Highest scores", 0x000A);
	Graphic::DrawString(game_width / 3 + 2, game_height / 3 + 4,to_string(_bestScore), 0x000A);

	Graphic::DrawString(game_width / 3+2, game_height / 3+6,	"Your scores ", 0x000C);
	Graphic::DrawString(game_width / 3 + 2, game_height / 3 + 8,  to_string(_totalScore), 0x000C);

	Graphic::DrawString(game_width / 3+2, game_height / 3 + 10,	"Your name  ", 0x000F);
	Graphic::Update();

	string c="__________";
	int size = 0;
	for (int i = 0;i < 10;i++)
	{
		Graphic::Draw(game_width / 3 + 2 + i * 2, game_height / 3 + 12, 196, 15);//- sperator
	}
	Graphic::Update();
	char t = _getch();//absorb the space key
	while (1) 
	{
		if (t == ' ') //flush all space key and escape key
		{
			t = _getch();
		}
		if (t == -32) //flush all arrowkey
		{
			_getch();
			t = _getch();
		}
		if (t != ' ' && t != -32) 
			break; //When user press anykey but space and arrow, stop flushing
	}

	
	while (1)
	{
		t = _getch();
		//if (t == 13) //ENTER
		//{
		//	break;
		//}
		if (GetAsyncKeyState(VK_RETURN)) 
		{
			Sleep(200);
			break;
		};
		if (t == 8)//Backspace key
		{
			if (size > 0)
			{

				size--;
				c[size] = '_';
			}
		}
		else if (t == -32) //Arrow key
		{
			_getch();	//Ignore arrowkey
		}
		else if (t == 27) //Ignore escape
		{

		}
		else
		{
			if (size < 10)
			{
				c[size] = t;
				size++;
			}
		}
		
		for (int i = 0;i < 10;i++) 
		{
			Graphic::Draw(game_width / 3 + 2+i*2, game_height / 3 + 12, 196, 15);//- sperator
			Graphic::Draw(game_width / 3 + 2 + i * 2, game_height / 3 + 12, c[i], 15);//-name input
		}
		Graphic::Update();
	}

	_player = c.substr(0,size);

	if (_player == "")
		return "player";
	else
		return _player;
}
void Score::update_HighScore()//Sau khi end game goi ham nay de nhap ten va cap nhat lai high score
{
	//_player = "player";
	_player = get_Player();
	_vecHighScore.push_back(pair<string, int>(_player, _totalScore));
	//lay top 10
	for (int i = 0; i < _vecHighScore.size()-1; i++)
	{
		for (int j = i; j < _vecHighScore.size(); j++)
		{
			if (_vecHighScore[i].second < _vecHighScore[j].second)
			{
				_vecHighScore[i].swap(_vecHighScore[j]);
			}
		}
	}
	if (_vecHighScore.size() > 10)
		_vecHighScore.pop_back();// bo cai thu 11
	ofstream onf;
	int i = 0;
	onf.open("HighScore.txt");
	while (i < _vecHighScore.size() && i < 10)
	{
		onf << _vecHighScore[i].first << "|" << _vecHighScore[i].second << endl;
		i++;
	}
	onf.close();
}
void Score::draw_HighScore()// Ve top 10
{
	int i = 0;
	while (i < _vecHighScore.size() && i < 10)
	{
		Graphic::DrawString(game_width / 3 - 2, game_height / 4 + i * 2, _vecHighScore[i].first, 15);
		Graphic::DrawString(game_width * 2 / 3, game_height / 4 + i * 2, std::to_string(_vecHighScore[i].second), 15);
		i++;
	}

	//system("pause");
}