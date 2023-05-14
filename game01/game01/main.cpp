#include<SFML/Window.hpp>
#include<SFML/graphics.hpp>
#include<SFML/audio.hpp>
#include<iostream>
#include<sstream>
using namespace std;
using namespace sf;

const int WindowWidth{ 800 }, WindowHeight{ 800 };
float ballspeedx = 7, ballspeedy = 9;
float paddlespeed = 10;
const float brickWidth{ 70 }, brickHeight{ 25 };
const int numbrickx{ 11 }, numbricky{ 7 };   //error

int main() {

	RenderWindow window(VideoMode(WindowWidth, WindowHeight), "brick breaker");


	window.setFramerateLimit(60); //error
	int lose = 3;
	//ball paddle crash sound start
	SoundBuffer bballpaddlecrash;
	bballpaddlecrash.loadFromFile("C:/Users/youssef/Desktop/files/paddle ball crash sound.wav");
	Sound ballpaddlecrash;
	ballpaddlecrash.setBuffer(bballpaddlecrash);
	//ball paddle crash sound end
	//ball start
	Texture tball;
	tball.loadFromFile("C:/Users/youssef/Desktop/files/ball.png");
	Sprite ball;
	ball.setTexture(tball);
	ball.setPosition(WindowWidth / 2, WindowHeight / 2);
	ball.setOrigin(10, 10); //error
	//ball end
	// game over start 
	Texture tgameover;
	tgameover.loadFromFile("C:/Users/youssef/Desktop/files/game over.png");
	Sprite gameover1;
	gameover1.setTexture(tgameover);
	gameover1.setPosition(100, 200);

	//game over end
	//you win 
	Texture tyouwin;
	tyouwin.loadFromFile("C:/Users/youssef/Desktop/files/you win.png");
	Sprite youwin;
	youwin.setTexture(tyouwin);
	youwin.setPosition(100, 100);
	//you win end
	// 	   back ground
	Texture tback;
	tback.loadFromFile("C:/Users/youssef/Desktop/files/background.png");
	Sprite back;
	back.setTexture(tback);
	//paddle start
	Texture tpaddle;
	tpaddle.loadFromFile("C:/Users/youssef/Desktop/files/paddle.png");
	Sprite paddle;
	paddle.setTexture(tpaddle);
	paddle.setPosition(WindowWidth / 2, 720);
	paddle.setOrigin(50, 20);
	//paddle end
	//brick start
	Texture tbrick1;
	tbrick1.loadFromFile("C:/Users/youssef/Desktop/files/brick1.png");
	Sprite brick1[7];
	Texture tbrick2;
	tbrick2.loadFromFile("C:/Users/youssef/Desktop/files/brick2.png");
	Sprite brick2[7];
	Texture tbrick3;
	tbrick3.loadFromFile("C:/Users/youssef/Desktop/files/brick3.png");
	Sprite brick3[7];
	Texture tbrick4;
	tbrick4.loadFromFile("C:/Users/youssef/Desktop/files/brick4.png");
	Sprite brick4[7];
	Texture tbrick5;
	tbrick5.loadFromFile("C:/Users/youssef/Desktop/files/brick5.png");
	Sprite brick5[7];
	//scorebord
	int count = 0;// the score
	Text tscore;
	tscore.setCharacterSize(50);
	tscore.setPosition(0, 0);
	Font fscore;
	fscore.loadFromFile("C:/Users/youssef/Desktop/files/COOPBL.ttf");
	tscore.setFont(fscore);
	ostringstream score;//error
	score << "lives : " << count;
	tscore.setString(score.str());
	//live
	Text tlive;
	tlive.setCharacterSize(50);
	tlive.setPosition(WindowHeight - 250, 0);
	Font flive;
	flive.loadFromFile("C:/Users/youssef/Desktop/files/COOPBL.ttf");
	tlive.setFont(flive);
	ostringstream live;
	live << "lives : " << lose;
	tlive.setString(live.str());
	// brick 1
	for (int i = 0; i < 7; i++) {
		brick1[i].setTexture(tbrick1);
		brick1[i].setPosition(i * 110, 0 * 45);
	}
	// brick 2
	for (int i = 0; i < 7; i++) {
		brick2[i].setTexture(tbrick2);
		brick2[i].setPosition(i * 110, 0 * 45 + 50);
	}
	//brick 3
	for (int i = 0; i < 7; i++) {
		brick3[i].setTexture(tbrick3);
		brick3[i].setPosition(i * 110, 0 * 45 + 100);
	}
	// brick 4
	for (int i = 0; i < 7; i++) {
		brick4[i].setTexture(tbrick4);
		brick4[i].setPosition(i * 110, 0 * 45 + 150);
	}
	// brick 5 
	for (int i = 0; i < 7; i++) {
		brick5[i].setTexture(tbrick5);
		brick5[i].setPosition(i * 110, 0 * 45 + 200);
	}

	//brick end
	while (window.isOpen())

	{   //close (x)
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		//ball movement start
		if (ball.getPosition().x <= 0 || ball.getPosition().x >= 800) {
			ballspeedx = -ballspeedx;
		}
		else if (ball.getPosition().y <= 0 || ball.getPosition().y >= 800) {
			ballspeedy = -ballspeedy;
		}
		//ball movement end
		//paddle movement start
		// baddle whidth = 100px
		if (paddle.getPosition().x >= 50 && paddle.getPosition().x <= 750) {
			if (Keyboard::isKeyPressed(Keyboard::Left))
				paddle.move(-paddlespeed, 0);
			else if (Keyboard::isKeyPressed(Keyboard::Right))
				paddle.move(paddlespeed, 0);
		}
		else if (paddle.getPosition().x <= 50) {
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				paddle.move(paddlespeed, 0);
			}
		}
		else if (paddle.getPosition().x >= 750) {
			if (Keyboard::isKeyPressed(Keyboard::Left))
				paddle.move(-paddlespeed, 0);
		}
		//paddle movement end
		// // get global for collide 
		// paddle ball collide start
		if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds())) {
			ballpaddlecrash.play();
			ballspeedy = -ballspeedy;
		}

		//paddle ball collide end
		//brick ball collide start
		for (int j = 0; j < 7; j++) {
			if (ball.getGlobalBounds().intersects(brick5[j].getGlobalBounds())) {
				ballpaddlecrash.play();
				ballspeedy = -ballspeedy;
				brick5[j].setPosition(-1000, -1000);
				count++;
				score.str("");
				score << "score :" << count;
				tscore.setString(score.str());
			}
		}
		for (int j = 0; j < 7; j++) {
			if (ball.getGlobalBounds().intersects(brick4[j].getGlobalBounds())) {
				ballpaddlecrash.play();
				ballspeedy = -ballspeedy;
				brick4[j].setPosition(-1000, -1000);
				count++;
				score.str("");
				score << "score :" << count;
				tscore.setString(score.str());
			}
		}
		for (int j = 0; j < 7; j++) {
			if (ball.getGlobalBounds().intersects(brick3[j].getGlobalBounds())) {
				ballpaddlecrash.play();
				ballspeedy = -ballspeedy;
				brick3[j].setPosition(-1000, -1000);
				count++;
				score.str("");
				score << "score :" << count;
				tscore.setString(score.str());
			}
		}
		for (int j = 0; j < 7; j++) {
			if (ball.getGlobalBounds().intersects(brick2[j].getGlobalBounds())) {
				ballpaddlecrash.play();
				ballspeedy = -ballspeedy;
				brick2[j].setPosition(-1000, -1000);
				count++;
				score.str("");
				score << "score :" << count;
				tscore.setString(score.str());
			}
		}
		for (int j = 0; j < 7; j++) {
			if (ball.getGlobalBounds().intersects(brick1[j].getGlobalBounds())) {
				ballpaddlecrash.play();
				ballspeedy = -ballspeedy;
				brick1[j].setPosition(-1000, -1000);
				count++;
				score.str("");
				score << "score :" << count;
				tscore.setString(score.str());
			}
		}
		//brick ball collide end
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) { break; }

		ball.move(-ballspeedx, -ballspeedy);
		window.clear();
		window.draw(back);
		if (ball.getPosition().y > 740) {
			lose--;
			ball.setPosition(WindowWidth / 2, WindowHeight / 2);
			ballspeedy = 0; ballspeedx = 0;
			paddle.setPosition(WindowWidth / 2, WindowHeight - 80);
			live.str("");
			live << "lives :" << lose;
			tlive.setString(live.str());
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
			ballspeedx = 7; ballspeedy = 9;
		}


		else if (lose == 0) {
			ballspeedy = 0; ballspeedx = 0;
			paddlespeed = 0;
			window.draw(gameover1);
			if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) { break; }
		}

		if (count == 35) {
			paddlespeed = 0;
			ballspeedx = 0;
			ballspeedy = 0;
			window.draw(youwin);
			if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) { break; }

		}
		for (int i = 0; i < 7; i++)
			window.draw(brick1[i]);
		for (int i = 0; i < 7; i++)
			window.draw(brick2[i]);
		for (int i = 0; i < 7; i++)
			window.draw(brick3[i]);
		for (int i = 0; i < 7; i++)
			window.draw(brick4[i]);
		for (int i = 0; i < 7; i++)
			window.draw(brick5[i]);
		window.draw(tscore);
		window.draw(tlive);
		window.draw(paddle);
		window.draw(ball);
		window.display();
	}

	return 0;
}