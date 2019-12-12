#pragma once
#include <fstream>
#include "BoxManager.h"
class Score
{
	int _bestScore;
	int _score;
	int _levelScore;
	vector<pair<string,int>> _vecHighScore;
	string _player;
public:
	Score();
	~Score();
	
	string get_Player();

	void update_LevelScore(BoxManager&);
	void update_Score(BoxManager&);
	void draw_Score(int x, int y, int score);

	void update_HighScore();
	void draw_HighScore();
};

