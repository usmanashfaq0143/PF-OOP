#pragma warning (disable : 6385 6262 4305 4244 6282 4553)
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace sf;
using namespace std;


void GameScreen();
void LoadGameScreen();
void SaveGameData(int arr[9][9], int moves, int score)
{
	ofstream DataSave;
	DataSave.open("GameData.txt");

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			DataSave << arr[i][j];
		}
		DataSave << endl;
	}
		DataSave << endl;
		DataSave << moves;
		DataSave << endl;
		DataSave << score;
		DataSave << endl;
}
void Winner()
{
	RenderWindow winner(VideoMode(600, 600), "Results");
	Event ev;
	Vector2i mousePos;
	Font font;
	font.loadFromFile("font/Hardigan.otf");

	Text showWin;
	showWin.setString("You are Winner!");
	showWin.setFont(font);
	showWin.setPosition(60, 170);
	showWin.setCharacterSize(60);
	showWin.setFillColor(Color::Blue);

	RectangleShape rect1(Vector2f(200, 80));
	rect1.setFillColor(Color(255, 166, 48));
	rect1.setOutlineThickness(2);
	rect1.setOutlineColor(Color::Blue);
	rect1.setPosition(195, 313);

	Text playAgain;
	playAgain.setString("Play Again");
	playAgain.setFont(font);
	playAgain.setPosition(219, 330);
	playAgain.setCharacterSize(30);
	playAgain.setFillColor(Color::Blue);

	RectangleShape rect2(Vector2f(200, 80));
	rect2.setFillColor(Color(255, 166, 48));
	rect2.setOutlineThickness(2);
	rect2.setOutlineColor(Color::Blue);
	rect2.setPosition(195, 413);

	Text close;
	close.setString("Close");
	close.setFont(font);
	close.setPosition(250, 430);
	close.setCharacterSize(30);
	close.setFillColor(Color::Blue);

	int flag = 0;
	while (winner.isOpen())
	{
		flag = 0;
		mousePos = Mouse::getPosition(winner);
		while (winner.pollEvent(ev))
		{
			switch (ev.type)
			{
			case Event::Closed:
				winner.close();
			case Event::MouseButtonPressed:
				flag = 1;
			}
		}

		if (flag == 1)
		{
			if (mousePos.x >= 193 && mousePos.x <= 395 && mousePos.y >= 311 && mousePos.y <= 391)
			{
				winner.close();
				GameScreen();
			}
			else if (mousePos.x >= 193 && mousePos.x <= 395 && mousePos.y >= 412 && mousePos.y <= 491)
			{
				winner.close();
			}
		}
		winner.clear(Color(255, 166, 48));
		winner.draw(showWin);
		winner.draw(rect1);
		winner.draw(playAgain);
		winner.draw(rect2);
		winner.draw(close);
		winner.display();
	}
}

void Loser()
{
	RenderWindow winner(VideoMode(600, 600), "Results");
	Event ev;
	Vector2i mousePos;
	Font font;
	font.loadFromFile("font/Hardigan.otf");

	Text showWin;
	showWin.setString("You are Loser!");
	showWin.setFont(font);
	showWin.setPosition(60, 170);
	showWin.setCharacterSize(60);
	showWin.setFillColor(Color::Blue);

	RectangleShape rect1(Vector2f(200, 80));
	rect1.setFillColor(Color(255, 166, 48));
	rect1.setOutlineThickness(2);
	rect1.setOutlineColor(Color::Blue);
	rect1.setPosition(195, 313);

	Text playAgain;
	playAgain.setString("Play Again");
	playAgain.setFont(font);
	playAgain.setPosition(219, 330);
	playAgain.setCharacterSize(30);
	playAgain.setFillColor(Color::Blue);

	RectangleShape rect2(Vector2f(200, 80));
	rect2.setFillColor(Color(255, 166, 48));
	rect2.setOutlineThickness(2);
	rect2.setOutlineColor(Color::Blue);
	rect2.setPosition(195, 413);

	Text close;
	close.setString("Close");
	close.setFont(font);
	close.setPosition(250, 430);
	close.setCharacterSize(30);
	close.setFillColor(Color::Blue);

	int flag = 0;
	while (winner.isOpen())
	{
		flag = 0; //resetting the flag
		mousePos = Mouse::getPosition(winner);
		while (winner.pollEvent(ev))
		{
			switch (ev.type)
			{
			case Event::Closed:
				winner.close();
			case Event::MouseButtonPressed:
				flag = 1;
			}
		}

		if (flag == 1)
		{
			if (mousePos.x >= 193 && mousePos.x <= 395 && mousePos.y >= 311 && mousePos.y <= 391)
			{
				GameScreen();
			}
			else if (mousePos.x >= 193 && mousePos.x <= 395 && mousePos.y >= 412 && mousePos.y <= 491)
			{
				winner.close();
			}
		}
		winner.clear(Color(255, 166, 48));
		winner.draw(showWin);
		winner.draw(rect1);
		winner.draw(playAgain);
		winner.draw(rect2);
		winner.draw(close);
		winner.display();
	}
}

void SwapFunction(int candy1, int candy2);
bool CrushCheck = false;

void Main()
{
	RenderWindow window(VideoMode(600, 600), "Candy Crush");
	Event ev;


	// Music
	SoundBuffer introSound;
	introSound.loadFromFile("music/intro.ogg");
	Sound intro;
	intro.setBuffer(introSound);
	intro.setLoop(true);
	intro.play();

	Mouse mouse;
	RectangleShape rect(Vector2f(200, 80));
	rect.setFillColor(Color::Blue);
	rect.setPosition(200, 370);
	rect.setOutlineColor(Color::White);
	rect.setOutlineThickness(2);

	RectangleShape rect2(Vector2f(200, 80));
	rect2.setFillColor(Color::Blue);
	rect2.setPosition(200, 280);
	rect2.setOutlineColor(Color::White);
	rect2.setOutlineThickness(2);

	RectangleShape rect3(Vector2f(200, 80));
	rect3.setFillColor(Color::Blue);
	rect3.setPosition(200, 460);
	rect3.setOutlineColor(Color::White);
	rect3.setOutlineThickness(2);

	Texture texture;
	texture.loadFromFile("img/gamebg.jpg");
	Sprite sprite;
	sprite.setTexture(texture);

	Font font;
	font.loadFromFile("font/Hardigan.otf");

	Text text;
	text.setFont(font);
	text.setCharacterSize(75);
	text.setString("Candy\nCrush\nGame");
	text.setFillColor(Color::Yellow);
	text.setOutlineColor(Color::Blue);
	text.setOutlineThickness(2);
	text.setPosition(180, 40);
	text.setLineSpacing(0.7);

	Text text2;
	text2.setFont(font);
	text2.setString("Play!");
	text2.setCharacterSize(30);
	text2.setFillColor(Color::Blue);
	text2.setOutlineColor(Color::Yellow);
	text2.setOutlineThickness(2);
	text2.setPosition(260, 300);

	Text text3;
	text3.setFont(font);
	text3.setString("Close!");
	text3.setCharacterSize(30);
	text3.setFillColor(Color::Blue);
	text3.setOutlineColor(Color::Yellow);
	text3.setOutlineThickness(2);
	text3.setPosition(255, 390);

	Text text4;
	text4.setFont(font);
	text4.setString("Load!");
	text4.setCharacterSize(30);
	text4.setFillColor(Color::Blue);
	text4.setOutlineColor(Color::Yellow);
	text4.setOutlineThickness(2);
	text4.setPosition(255, 479);

	Vector2i CursorPos;
	while (window.isOpen())
	{
		while (window.pollEvent(ev))
		{
			CursorPos = Mouse::getPosition(window);
			switch (ev.type)
			{
			case Event::Closed:
				window.close();

			case Event::MouseMoved:
				cout << CursorPos.x << " , " << CursorPos.y << endl;
			}

		}
		window.clear();
		window.draw(sprite);
		window.draw(rect);
		window.draw(rect2);
		window.draw(rect3);
		window.draw(text);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);

		if (mouse.isButtonPressed(mouse.Left))
		{
			Vector2i mousePositioin = mouse.getPosition(window);
			if (mousePositioin.x >= 200 && mousePositioin.x <= 400 && mousePositioin.y >= 280 && mousePositioin.y <= 360)
			{
				window.close();
				GameScreen();
			}
			else if (mousePositioin.x >= 200 && mousePositioin.x <= 400 && mousePositioin.y >= 370 && mousePositioin.y <= 460)
			{
				window.close();
			}
			else if (mousePositioin.x >= 200 && mousePositioin.x <= 400 && mousePositioin.y >= 461 && mousePositioin.y <= 535)
			{
				window.close();
				GameScreen();
			}
		}

		window.display();
	}
}

void GameScreen()
{
	RenderWindow window(VideoMode(900, 600), "Candy Crush");
	Event ev;
	bool frameCheck = false;

	int GridArr[9][9] = { 0 };
	RectangleShape rect;
	rect.setFillColor(Color(17, 5, 25, 220));
	rect.setOutlineColor(Color::White);
	rect.setOutlineThickness(1);

	//ScoreCard
	RectangleShape ScoreCard(Vector2f(200, 80));
	ScoreCard.setFillColor(Color(20, 15, 45, 250));
	ScoreCard.setPosition(100, 60);

	RectangleShape ScoreProjected(Vector2f(200,80));
	ScoreProjected.setFillColor(Color(20, 15, 45, 250));
	ScoreProjected.setPosition(100, 350);


	Font font;
	font.loadFromFile("font/Hardigan.otf");
	Text score;
	score.setString("Score");
	score.setCharacterSize(24);
	score.setFont(font);
	score.setFillColor(Color::Yellow);
	score.setPosition(160, 70);

	//Projected Score
	Text projScore;
	projScore.setFont(font);
	projScore.setFillColor(Color::Yellow);
	projScore.setCharacterSize(24);
	projScore.setString("850");
	projScore.setPosition(170, 390);

	Text projScoreHead;
	projScoreHead.setFont(font);
	projScoreHead.setFillColor(Color::Yellow);
	projScoreHead.setString("PROJECTED SCORE");
	projScoreHead.setCharacterSize(21);
	projScoreHead.setPosition(110, 360);

	// Grid
	Texture grid;
	grid.loadFromFile("img/Grid.png");
	Sprite Grid;
	Grid.setTexture(grid);
	Grid.setPosition(350, 60);

	//Initializing random Values the Grid
	bool CheckRandom = true;
	srand(time(0));
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int number = 0;
				number = 1 + rand() % ((5 + 1) - 1);
				GridArr[i][j] = number;
				cout << GridArr[i][j] << " ";
			}
			cout << endl;
		}

		//Check to remove duplicates on first print
	for (int a = 0; a < 10; a++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (GridArr[i][j + 1] == GridArr[i][j] && GridArr[i][j + 2] == GridArr[i][j])
				{
					GridArr[i][j] = 1 + rand() % ((5 + 1) - 1);;
					GridArr[i][j + 1] = 1 + rand() % ((5 + 1) - 1);;
					GridArr[i][j + 2] = 1 + rand() % ((5 + 1) - 1);;
				}
				else if (GridArr[j + 1][i] == GridArr[j][i] && GridArr[j + 2][i] == GridArr[j][i])
				{
					GridArr[j][i] = 1 + rand() % ((5 + 1) - 1);;
					GridArr[j + 1][i] = 1 + rand() % ((5 + 1) - 1);;
					GridArr[j + 2][i] = 1 + rand() % ((5 + 1) - 1);;
				}
			}
		}


		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (GridArr[i][j] == 0)
				{
					GridArr[i][j] = 1 + rand() % ((5 - 1) + 1);

				}

			}

		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (GridArr[i][j + 1] == GridArr[i][j] && GridArr[i][j + 2] == GridArr[i][j])
			{
				GridArr[i][j] = 0;
				GridArr[i][j + 1] = 0;
				GridArr[i][j + 2] = 0;
			}
			else if (GridArr[j + 1][i] == GridArr[j][i] && GridArr[j + 2][i] == GridArr[j][i])
			{
				GridArr[j][i] = 0;
				GridArr[j + 1][i] = 0;
				GridArr[j + 2][i] = 0;
			}
		}
	}
	// Updating the Grid
	//Candies


	Texture candyPng1, candyPng2, candyPng3, candyPng4, candyPng5, candyStrip1, candyStrip2, candyStrip3, candyStrip4, candyStrip5, colorBomb;
	Texture SpecialCandy1, SpecialCandy2, SpecialCandy3, SpecialCandy4, SpecialCandy5;
	candyPng1.loadFromFile("img/redCandy.png");
	candyPng2.loadFromFile("img/yellowCandy.png");
	candyPng3.loadFromFile("img/blueCandy.png");
	candyPng4.loadFromFile("img/orangeCandy.png");
	candyPng5.loadFromFile("img/greenCandy.png");
	candyStrip1.loadFromFile("img/RedStriped.png");
	candyStrip2.loadFromFile("img/yellowStripped.png");
	candyStrip3.loadFromFile("img/blueStripped.png");
	candyStrip4.loadFromFile("img/orangeStripped.png");
	candyStrip5.loadFromFile("img/greenStripped.png");
	colorBomb.loadFromFile("img/colorBomb.png");
	SpecialCandy1.loadFromFile("img/redWrap.png");
	SpecialCandy2.loadFromFile("img/yellowWrap.png");
	SpecialCandy3.loadFromFile("img/blueWrap.png");
	SpecialCandy4.loadFromFile("img/orangeWrap.png");
	SpecialCandy5.loadFromFile("img/greenWrap.png");
	Sprite Candy[9][9];
	int number[9][9] = { 0 };
	int y = 65;
	int j = 0;
	int x = 305;
	for (int i = 0; i < 9; i++)
	{
		x = 305;
		for (j = 0; j < 9; j++)
		{
			x = x + 50;
			if (GridArr[i][j] == 1)
			{
				Candy[i][j].setTexture(candyPng1);
				Candy[i][j].setPosition(x, y);
			}
			else if (GridArr[i][j] == 2)
			{
				Candy[i][j].setTexture(candyPng2);
				Candy[i][j].setPosition(x, y);
			}
			else if (GridArr[i][j] == 3)
			{
				Candy[i][j].setTexture(candyPng3);
				Candy[i][j].setPosition(x, y);
			}
			else if (GridArr[i][j] == 4)
			{
				Candy[i][j].setTexture(candyPng4);
				Candy[i][j].setPosition(x, y);
			}
			else if (GridArr[i][j] == 5)
			{
				Candy[i][j].setTexture(candyPng5);
				Candy[i][j].setPosition(x, y);
			}
		}
		y = y + 50;
	}

	//Mouse Position

	Vector2i CursorPos;
	CursorPos.x = 350;
	CursorPos.y = 60;

	Vector2i SwappingPos;
	SwappingPos.x = 300;
	SwappingPos.y = 60;

	// size of One Box Of Grid
	int boxSize = 50;
	int xAxis = 0;
	int yAxis = 0;
	Vector2i mousePosition;

	//Moves Board
	RectangleShape Moves(Vector2f(200, 80));
	Moves.setFillColor(Color(20, 15, 45, 250));
	Moves.setPosition(100, 200);


	Text moves;
	moves.setCharacterSize(21);
	moves.setFont(font);
	moves.setString("Moves Remaining");
	moves.setFillColor(Color::Yellow);
	moves.setPosition(115, 210);

	

	// Background Image
	Texture texture;
	texture.loadFromFile("img/secscreen.png");

	Sprite sprite;
	sprite.setTexture(texture);

	// Target Icon

	Texture target;
	target.loadFromFile("img/target.png");
	Sprite targetFocus[9][9];

	int trgtX = 305;
	int trgtY = 60;

	// Placing the Hover Target Icon
	for (int i = 0; i < 9; i++)
	{
		trgtX = 300;
		for (int j = 0; j < 9; j++)
		{
			trgtX = trgtX + 50;
			targetFocus[i][j].setTexture(target);
			targetFocus[i][j].setPosition(trgtX, trgtY);
		}
		trgtY = trgtY + 50;
	}
	// Main Execution
	Vector2i CandiePos;
	CandiePos = Mouse::getPosition(window);
	int click = 0;
	int x0 = 0;
	int y0 = 0;
	int x1 = 0;
	int y1 = 0;
	bool checkIndex1 = false;
	bool checkIndex2 = false;
	bool Swap = true;
	bool PrintArray = false;
	bool SecClick = false;
	bool MovesCheck = false;
	int movesCount = 20;
	bool SwapCheck = false;
	bool ScoreCheck = false;

	// Candies Scores
	int ScoreTotal = 0;
	int redCandy = 30;
	int yellowCandy = 30;
	int greenCandy = 40;
	int blueCandy = 50;
	int orangeCandy = 60;
	bool stripCandies = false;
	bool wrapCandies = false;

	// Save Game
	Vector2i SaveCursor;
	RectangleShape Save(Vector2f(150, 60));
	Save.setFillColor(Color::Green);
	Save.setOutlineColor(Color::Yellow);
	Save.setOutlineThickness(2);
	Save.setPosition(100, 500);

	Text SaveGame;
	SaveGame.setFont(font);
	SaveGame.setCharacterSize(24);
	SaveGame.setString("Save Game");
	SaveGame.setFillColor(Color::Blue);
	SaveGame.setPosition(120, 515);
	int flag = 0;

	//Opening the Window
	while (window.isOpen())
	{
		flag = 0;
		stripCandies = false;
		wrapCandies = false;

		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
			{
				window.close();
			}
			CursorPos = Mouse::getPosition(window);
			SaveCursor = Mouse::getPosition(window);
			if (ev.type == Event::MouseButtonPressed)
			{
				if (ev.key.code == Mouse::Left)
				{
					click++;
					checkIndex1 = false;
					checkIndex2 = false;
					Swap = false;
					if (SaveCursor.x >= 100 && SaveCursor.x <= 250 && SaveCursor.y >= 500 && SaveCursor.y <= 560)
					{
						flag = 1;
					}
				}
			}
		}
		for (int a = 0; a < 10; a++)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (GridArr[i][j + 1] == GridArr[i][j] && GridArr[i][j + 2] == GridArr[i][j])
					{
						GridArr[i][j] = 1 + rand() % ((5 + 1) - 1);
						GridArr[i][j + 1] = 1 + rand() % ((5 + 1) - 1);
						GridArr[i][j + 2] = 1 + rand() % ((5 + 1) - 1);
					}
					else if (GridArr[j + 1][i] == GridArr[j][i] && GridArr[j + 2][i] == GridArr[j][i])
					{
						GridArr[j][i] = 1 + rand() % ((5 + 1) - 1);
						GridArr[j + 1][i] = 1 + rand() % ((5 + 1) - 1);
						GridArr[j + 2][i] = 1 + rand() % ((5 + 1) - 1);
					}
				}
			}


			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (GridArr[i][j] == 0)
					{
						GridArr[i][j] = 1 + rand() % ((5 - 1) + 1);

					}

				}

			}
		}
		// Showing the Moves
		string movCnt = to_string(movesCount);
		Text MovesCountBoard;
		MovesCountBoard.setString(movCnt);
		MovesCountBoard.setCharacterSize(25);
		MovesCountBoard.setFont(font);
		MovesCountBoard.setFillColor(Color::Yellow);
		MovesCountBoard.setPosition(175, 240);

		// Drawing Score on the box 
		string totalScore = to_string(ScoreTotal);
		Text TotalScr;
		TotalScr.setFillColor(Color::Yellow);
		TotalScr.setFont(font);
		TotalScr.setCharacterSize(24);
		TotalScr.setString(totalScore);
		TotalScr.setPosition(185, 100);

		// Storing the Indexes of the 1st Click
		if (ev.type == Event::MouseButtonPressed && MovesCheck == false)
		{
			if (ScoreCheck == false)
			{
				SecClick == false;
					PrintArray = false;
					if (click % 2 != 0)
					{
						for (int i = 0; i < 9 && checkIndex1 == false; i++)
						{
							for (int j = 0; j < 9 && checkIndex1 == false; j++)
							{
								if (Candy[i][j].getGlobalBounds().contains(static_cast<Vector2f>(CursorPos)))
								{
									x0 = i;
									y0 = j;
									cout << "Index 1st\n";
									cout << x0 << " , " << y0 << endl;
									checkIndex1 = true;
									SecClick = true;
								}
							}
						}
					}
				// Storing the Indexes of the 2nd Click
				if (click % 2 == 0 && SecClick == true)
				{
					for (int i = 0; i < 9 && checkIndex2 == false; i++)
					{
						for (int j = 0; j < 9 && checkIndex2 == false; j++)
						{
							if (Candy[i][j].getGlobalBounds().contains(static_cast<Vector2f>(CursorPos)))
							{
								x1 = i;
								y1 = j;
								if (abs(x0 - x1) == 1 || abs(y0 - y1) == 1) // Checking whether user is moving the candies righly
								{
									cout << "Index 2nd\n";
									cout << x1 << " , " << y1 << endl;
									checkIndex2 = true;
									Swap = true;
									PrintArray = true;
									SwapCheck = true;
									movesCount--;
									CrushCheck = true;
								}
								if (movesCount <= 0)
								{
									MovesCheck = true;
								}
							}
						}
					}
				}
			}
		}
		// Swapping the Candies according to the given parameters
		if (SwapCheck == true)
		{
			//Swappinng the indexes of the array !
			swap(GridArr[x0][y0], GridArr[x1][y1]);
			if (GridArr[x0][y0] == 1)
			{
				ScoreTotal = redCandy + ScoreTotal;
			}
			else if (GridArr[x0][y0] == 2)
			{
				ScoreTotal = yellowCandy + ScoreTotal;
			}
			else if (GridArr[x0][y0] == 3)
			{
				ScoreTotal = blueCandy + ScoreTotal;
			}
			else if (GridArr[x0][y0] == 4)
			{
				ScoreTotal = orangeCandy + ScoreTotal;
			}
			else if (GridArr[x0][y0] == 5)
			{
				ScoreTotal = greenCandy + ScoreTotal;
			}

			while (Swap == true)
			{
				for (int i = 0; i < 9; i++)
				{
					for (j = 0; j < 9; j++)
					{
						if (GridArr[i][j] == 1)
						{
							Candy[i][j].setTexture(candyPng1);
							Swap = false;
						}
						else if (GridArr[i][j] == 2)
						{
							Candy[i][j].setTexture(candyPng2);
							Swap = false;
						}
						else if (GridArr[i][j] == 3)
						{
							Candy[i][j].setTexture(candyPng3);
							Swap = false;
						}
						else if (GridArr[i][j] == 4)
						{
							Candy[i][j].setTexture(candyPng4);
							Swap = false;
						}
						else if (GridArr[i][j] == 5)
						{
							Candy[i][j].setTexture(candyPng5);
							Swap = false;
						}
					}
				}
			}
			SwapCheck = false;
			if (ScoreTotal >= 850)
			{
				ScoreCheck = true;
			}
		}
		// Crushing the Values
		if (CrushCheck == true)
		{
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						//for wrapped candy
						//Tshape T
						if (GridArr[x0][y0] == 7)
						{
							for (int i = 0; i < 9; i++)
							{
								for (int j = 0; j < 9; j++)
								{
									if (GridArr[x1][y1] == 1)
									{
										if (GridArr[i][j] == 1)
										{
											GridArr[i][j] = 0;
										}
									}
									if (GridArr[x1][y1] == 2)
									{
										if (GridArr[i][j] == 2)
										{
											GridArr[i][j] = 0;
										}
									}
									if (GridArr[x1][y1] == 3)
									{
										if (GridArr[i][j] == 3)
										{
											GridArr[i][j] = 0;
										}
									}
									if (GridArr[x1][y1] == 4)
									{
										if (GridArr[i][j] == 4)
										{
											GridArr[i][j] = 0;
										}
									}
									if (GridArr[x1][y1] == 5)
									{
										if (GridArr[i][j] == 5)
										{
											GridArr[i][j] = 0;
										}
									}
								}
							}
						}
						if (GridArr[i][j + 1] == GridArr[i][j] && GridArr[i][j + 2] == GridArr[i][j] &&
							GridArr[i + 1][j + 1] == GridArr[i][j] && GridArr[i + 2][j + 1] == GridArr[i][j])
						{
							GridArr[i][j] = 0;
							GridArr[i][j + 1] = 0;
							GridArr[i][j + 2] = 0;
							GridArr[i + 1][j + 1] = 0;
							GridArr[i + 2][j + 1] = 9;
							wrapCandies = true;

						}
						//Tshape |-
						if (GridArr[i + 1][j] == GridArr[i][j] && GridArr[i + 2][j] == GridArr[i][j] &&
							GridArr[i + 1][j + 1] == GridArr[i][j] && GridArr[i + 1][j + 2] == GridArr[i][j])
						{
							GridArr[i][j] = 0;
							GridArr[i][j + 1] = 0;
							GridArr[i][j + 2] = 0;
							GridArr[i + 1][j + 1] = 0;
							GridArr[i + 1][j + 2] = 9;
							wrapCandies = true;

						}
						//Lshape |`
						if (GridArr[i][j + 1] == GridArr[i][j] && GridArr[i][j + 2] == GridArr[i][j] &&
							GridArr[i + 1][j] == GridArr[i][j] && GridArr[i + 2][j] == GridArr[i][j])
						{
							GridArr[i][j] = 0;
							GridArr[i][j + 1] = 0;
							GridArr[i][j + 2] = 0;
							GridArr[i + 1][j] = 0;
							GridArr[i + 2][j] = 9;
							wrapCandies = true;

						}
						//Lshape `|
						if (GridArr[i][j + 1] == GridArr[i][j] && GridArr[i][j + 2] == GridArr[i][j] &&
							GridArr[i + 1][j + 2] == GridArr[i][j] && GridArr[i + 2][j + 2] == GridArr[i][j])
						{
							GridArr[i][j] = 0;
							GridArr[i][j + 1] = 0;
							GridArr[i][j + 2] = 0;
							GridArr[i + 1][j + 2] = 0;
							GridArr[i + 2][j + 2] = 9;
							wrapCandies = true;

						}
						//Lshape |_
						if (GridArr[i + 1][j] == GridArr[i][j] && GridArr[i + 2][j] == GridArr[i][j]
							&& GridArr[i + 2][j + 1] == GridArr[i][j] && GridArr[i + 2][j + 2] == GridArr[i][j])

						{
							GridArr[i][j] = 0;
							GridArr[i + 1][j] = 0;
							GridArr[i + 2][j] = 0;
							GridArr[i + 2][j + 1] = 0;
							GridArr[i + 2][j + 2] = 9;
							wrapCandies = true;

						}
						//Lshape _|
						if (GridArr[i][j + 1] == GridArr[i][j] && GridArr[i][j + 2] == GridArr[i][j] &&
							GridArr[i - 1][j + 2] == GridArr[i][j] && GridArr[i - 2][j + 2] == GridArr[i][j])
						{
							GridArr[i - 2][j + 2] = 0;
							GridArr[i][j + 1] = 0;
							GridArr[i][j + 2] = 0;
							GridArr[i - 1][j + 2] = 0;
							GridArr[i][j] = 9;
							wrapCandies = true;

						}
						//for colorBomb
						if (GridArr[i][j] == GridArr[i][j + 1] && GridArr[i][j] == GridArr[i][j + 2] &&
							GridArr[i][j] == GridArr[i][j + 3] && GridArr[i][j] == GridArr[i][j + 4])
						{
							GridArr[i][j] = 0;
							GridArr[i][j + 1] = 0;
							GridArr[i][j + 2] = 0;
							GridArr[i][j + 3] = 0;
							GridArr[i][j + 4] = 7;
						}
						else if (GridArr[i][j] == GridArr[i + 1][j] && GridArr[i][j] == GridArr[i + 2][j] &&
							GridArr[i][j] == GridArr[i + 3][j] && GridArr[i][j] == GridArr[i + 4][j])
						{
							GridArr[i][j] = 0;
							GridArr[i + 1][j] = 0;
							GridArr[i + 2][j] = 0;
							GridArr[i + 3][j] = 0;
							GridArr[i + 4][j] = 7;
						}

						// for Stripped Candies
						else if (GridArr[j + 1][i] == GridArr[j][i] && GridArr[j + 2][i] == GridArr[j][i] && GridArr[j + 3][i] == GridArr[j][i])
						{
							GridArr[j][i] = 0;
							GridArr[j + 1][i] = 0;
							GridArr[j + 2][i] = 0;
							GridArr[j + 3][i] = 6;
							stripCandies = true;
						}
						else if (GridArr[i][j + 1] == GridArr[i][j] && GridArr[i][j + 2] == GridArr[i][j] && GridArr[i][j + 3] == GridArr[i][j])
						{
							GridArr[i][j] = 0;
							GridArr[i][j + 1] = 0;
							GridArr[i][j + 2] = 0;
							GridArr[i][j + 3] = 6;
							stripCandies = true;
						}

						// for simple crushing
						else if (GridArr[i][j + 1] == GridArr[i][j] && GridArr[i][j + 2] == GridArr[i][j])
						{
							GridArr[i][j] = 0;
							GridArr[i][j + 1] = 0;
							GridArr[i][j + 2] = 0;

						}
						else if (GridArr[i + 1][j] == GridArr[i][j] && GridArr[i + 2][j] == GridArr[i][j])
						{
							GridArr[i][j] = 0;
							GridArr[i + 1][j] = 0;
							GridArr[i + 2][j] = 0;
						}
					}
				}


				// Updating the Sprites
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (stripCandies == true)
						{
							if (GridArr[i][j] == 6)
							{
								if (GridArr[x0][y0] == 1)
								{
									Candy[i][j].setTexture(candyStrip1);
								}
								else if (GridArr[x0][y0] == 2)
								{
									Candy[i][j].setTexture(candyStrip2);
								}
								else if (GridArr[x0][y0] == 3)
								{
									Candy[i][j].setTexture(candyStrip3);
								}
								else if (GridArr[x0][y0] == 4)
								{
									Candy[i][j].setTexture(candyStrip4);
								}
								else if (GridArr[x0][y0] == 5)
								{
									Candy[i][j].setTexture(candyStrip5);
								}
							}
						}
						if (wrapCandies = true)
						{
							if (GridArr[i][j] == 9)
							{
								if (GridArr[x0][y0] == 1)
								{
									Candy[i][j].setTexture(SpecialCandy1);
								}
								else if (GridArr[x0][y0] == 2)
								{
									Candy[i][j].setTexture(SpecialCandy2);
								}
								else if (GridArr[x0][y0] == 3)
								{
									Candy[i][j].setTexture(SpecialCandy3);
								}
								else if (GridArr[x0][y0] == 4)
								{
									Candy[i][j].setTexture(SpecialCandy4);
								}
								else if (GridArr[x0][y0] == 5)
								{
									Candy[i][j].setTexture(SpecialCandy5);
								}
							}
						}
						if (GridArr[i][j] == 7)
						{
							Candy[i][j].setTexture(colorBomb);
						}
						if (GridArr[i][j] == 0)
						{
							GridArr[i][j] = 1 + rand() % ((5 - 1) + 1);
							if (GridArr[i][j] == GridArr[x0][y0])
							{
								GridArr[i][j] = 1 + rand() % ((5 - 1) + 1);
							}
							if (GridArr[i][j] == 1)
							{
								Candy[i][j].setTexture(candyPng1);
							}
							else if (GridArr[i][j] == 2)
							{
								Candy[i][j].setTexture(candyPng2);
							}
							else if (GridArr[i][j] == 3)
							{
								Candy[i][j].setTexture(candyPng3);
							}
							else if (GridArr[i][j] == 4)
							{
								Candy[i][j].setTexture(candyPng4);
							}
							else if (GridArr[i][j] == 5)
							{
								Candy[i][j].setTexture(candyPng5);
							}
						}
					}
				}
		}
		//Check to remove duplicates on first print
		for (int a = 0; a < 10; a++)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (GridArr[i][j + 1] == GridArr[i][j] && GridArr[i][j + 2] == GridArr[i][j])
					{
						GridArr[i][j] = 1 + rand() % ((5 + 1) - 1);
						GridArr[i][j + 1] = 1 + rand() % ((5 + 1) - 1);
						GridArr[i][j + 2] = 1 + rand() % ((5 + 1) - 1);
					}
					else if (GridArr[j + 1][i] == GridArr[j][i] && GridArr[j + 2][i] == GridArr[j][i])
					{
						GridArr[j][i] = 1 + rand() % ((5 + 1) - 1);
						GridArr[j + 1][i] = 1 + rand() % ((5 + 1) - 1);
						GridArr[j + 2][i] = 1 + rand() % ((5 + 1) - 1);
					}
				}
			}


			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (GridArr[i][j] == 0)
					{
						GridArr[i][j] = 1 + rand() % ((5 - 1) + 1);

					}

				}

			}
		}
		if (PrintArray == true)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					cout << GridArr[i][j] << " ";
				}
				cout << endl;
			}
		}
		window.clear();
		window.draw(sprite);
		window.draw(ScoreCard);
		window.draw(score);
		window.draw(Moves);
		window.draw(moves);
		window.draw(Grid);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (targetFocus[i][j].getGlobalBounds().contains(static_cast<Vector2f> (CursorPos)))
				{
					window.draw(targetFocus[i][j]);
				}
			}
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				window.draw(Candy[i][j]);
			}
		}

		if (ScoreCheck == true)
		{
			window.close();
			Winner();
		}
		else if (MovesCheck == true)
		{
			window.close();
			Loser();
		}
		if (flag == 1)
		{
			if (SaveCursor.x >= 100 && SaveCursor.x <= 250 && SaveCursor.y >= 500 && SaveCursor.y <= 560)
			{
				SaveGameData(GridArr, movesCount, ScoreTotal);
				cout << " Data Saved \n";
			}
		}
		window.draw(ScoreProjected);
		window.draw(MovesCountBoard);
		window.draw(projScore);
		window.draw(projScoreHead);
		window.draw(TotalScr);
		window.draw(Save);
		window.draw(SaveGame);
		window.display();
	}
}
int main()
{
	// Main Screen
	Main();
	return 0;
}