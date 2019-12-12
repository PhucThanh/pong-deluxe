#include "Score.h"
Score::Score()
{
	_score = 0;
	_levelScore = 0;
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

void Score::update_LevelScore(BoxManager& bm)
{
	_levelScore = bm.count_DestroyedBox();
}
void Score::update_Score(BoxManager& bm)
{
	update_LevelScore(bm);
	if (_score + _levelScore < _bestScore)// So sanh voi best score
	{
		draw_Score(game_width * 2 / 3 + 15, game_height, _score + _levelScore);
		draw_Score(1 + 15, game_height, _bestScore);
	}
	else
	{
		draw_Score(game_width * 2 / 3 + 15, game_height, _score + _levelScore);
		draw_Score(1 + 15, game_height, _score + _levelScore);
	}
	
	if (bm.Win())// update score khi thang
	{
		_score += _levelScore;
		_levelScore = 0;
	}
}
void Score::draw_Score(int x, int y, int score)//Ham ve diem
{
	Graphic::DrawString(x, y, std::to_string(score), 15);
}
string Score::get_Player()
{
	_score += 9; //_levelScore;//up score len diem hien tai
	Graphic::DrawString(game_width / 3, game_height / 3, "Diem cua ban la: " + std::to_string(_score), 15);
	Graphic::DrawString(game_width / 3, game_height / 3 + 2, "Ten cua ban: ", 15);
	Graphic::goToXY(game_width / 3 + 12, game_height / 3 + 2);
	Graphic::Update();
	getline(cin, _player);
	if (_player == "")
		return "player";
	else
		return _player;
}
void Score::update_HighScore()//Sau khi end game goi ham nay de nhap ten va cap nhat lai high score
{
	
	//_player = "player";
	_player = get_Player();
	_vecHighScore.push_back(pair<string, int>(_player, _score));
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
}
void Score::draw_HighScore()// Ve top 10
{
	//Graphic::ClearScr();
	int i = 0;
	while (i < _vecHighScore.size() && i < 10)
	{
		Graphic::DrawString(game_width / 3 - 2, game_height / 4 + i * 2, _vecHighScore[i].first, 15);
		Graphic::DrawString(game_width * 2 / 3, game_height / 4 + i * 2, std::to_string(_vecHighScore[i].second), 15);
		i++;
	}
}