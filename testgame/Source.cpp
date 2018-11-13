#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <sstream>
#include <stdlib.h>
#include"Header.h"
#include<sstream>
using namespace std;
using namespace sf;
int x = 0;
char nam[100];
#define screen_width 1300
#define screen_length 729
#define wlcm 1000
#define bullettime 1000
#define s1ts1 8000
#define s1ts2 17000
#define uts1 8000
#define uts2 30000
#define s2ts1 30000
#define s2ts2 40000
#define rlc1 60000
#define rlc2 80000
sf::RenderWindow window(sf::VideoMode(screen_width, screen_length), "SpaceImpact!");

struct background1
{
	float x;
	float y;
} background1;

struct background2
{
	float x;
	float y;
} background2;

struct playerscore
{
	int scr;

}playerscore;

int welcome()
{
	sf::Clock welcome_clock;
	sf::Time time1 = sf::milliseconds(wlcm);
	background1.x = 0, background1.y = 0;
	background2.x = 0, background2.y = -729;
	sf::Texture welcomePage;
	welcomePage.loadFromFile("welcome_page.png");
	sf::Sprite sprite_welcomePage(welcomePage);
	window.draw(sprite_welcomePage);
	window.display();
	welcome_clock.restart();
	while (1)
	{
		if (welcome_clock.getElapsedTime() > time1)
		{
			click_flag = 1;
			break;
		}
	}
	return click_flag;
}
int instruction()
{
	sf::Texture instruct;
	instruct.loadFromFile("instruction.jpg");
	sf::Sprite sprite_instruct(instruct);
	window.draw(sprite_instruct);
	if (mousePos.x >= 82 && mousePos.x <= 292 && mousePos.y >= 50 && mousePos.y <= 93)
	{
		click_flag = 1;
	}
	return click_flag;
}

int highscore()
{
	struct playerscore arr_player[100];
	sf::Texture high_score;
	high_score.loadFromFile("Capture3.jpg");
	sf::Sprite sprite_high_score(high_score);
	window.draw(sprite_high_score);
	if (mousePos.x >= 82 && mousePos.x <= 208 && mousePos.y >= 24 && mousePos.y <= 45)
	{
		click_flag = 1;
	}
	sf::Font font;
	font.loadFromFile("Font/TIMES.ttf");
	sf::Text bestscore;
	char bests[100];
	bestscore.setFont(font);
	bestscore.setFillColor(sf::Color::Yellow);
	bestscore.setCharacterSize(36);
	bestscore.setPosition(550, 270);
	FILE *file;
	file = fopen("highscore.txt", "r");
	fscanf(file, "%d", &arr_player[0].scr);
	sprintf(bests, "%d", arr_player[0]);
	bestscore.setString(bests);
	window.draw(bestscore);
	return click_flag;
}

int pause()
{
	sf::Texture pausebutton;
	pausebutton.loadFromFile("pausebutton.png");
	sf::Sprite sprite_pause(pausebutton);
	sprite_pause.setPosition(sf::Vector2f(400, 200));
	window.draw(sprite_pause);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) click_flag = 2;
	return click_flag;
}
void spaceship1move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && spaceshipPos_x >= -15)
	{
		spaceshipPos_x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && spaceshipPos_x <= 1160)
	{
		spaceshipPos_x += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && spaceshipPos_y >= 450)
	{
		spaceshipPos_y -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && spaceshipPos_y <= 580)
	{
		spaceshipPos_y += 1;
	}
	//This is for nitro
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && spaceshipPos_x >= -15 && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		spaceshipPos_x -= 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && spaceshipPos_x <= 1120 && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		spaceshipPos_x += 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && spaceshipPos_y >= 450 && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		spaceshipPos_y -= 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && spaceshipPos_y <= 540 && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		spaceshipPos_y += 2;
	}
}
void addscore()
{
	struct playerscore arr_player[100];


	FILE *file;
	file = fopen("highscore.txt", "r");
	arr_player[0].scr = point1;
	fscanf(file, "%d", &arr_player[1].scr);

	fclose(file);
	if (arr_player[1].scr > arr_player[0].scr)
	{
		int tm = arr_player[0].scr;
		arr_player[0] = arr_player[1];
		arr_player[1] = arr_player[0];
	}

	file = fopen("highscore.txt", "w");
	fprintf(file, "%d\n", arr_player[0].scr);
	fclose(file);
}

int levelup(int point11)
{
	struct playerscore arr_player[100];
	sf::Font font;
	font.loadFromFile("Font/TIMES.ttf");
	sf::Text bestscore;
	char bests[100];
	bestscore.setFont(font);
	bestscore.setFillColor(sf::Color::Black);
	bestscore.setCharacterSize(36);
	bestscore.setPosition(495, 528);
	FILE *file;
	file = fopen("highscore.txt", "r");
	fscanf(file, "%d", &arr_player[0].scr);
	sprintf(bests, "%d", arr_player[0]);
	bestscore.setString(bests);

	sf::Texture levelup;
	levelup.loadFromFile("ending.jpg");
	sf::Sprite sprite_levelup(levelup);
	window.draw(sprite_levelup);
	sf::Text point1111;
	char pointshow[100];

	point1111.setFont(font);
	point1111.setFillColor(sf::Color::Black);
	point1111.setPosition(sf::Vector2f(445, 475));
	point1111.setCharacterSize(40);
	sprintf(pointshow, "%d", point11);
	point1111.setString(pointshow);
	window.draw(point1111);
	window.draw(bestscore);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		click_flag = 1;
	}
	//addscore();
	return click_flag;
}
int gameover(int point11)
{
	struct playerscore arr_player[100];
	sf::Font font;
	font.loadFromFile("Font/TIMES.ttf");
	sf::Text bestscore;
	char bests[100];
	bestscore.setFont(font);
	bestscore.setFillColor(sf::Color::Yellow);
	bestscore.setCharacterSize(36);
	bestscore.setPosition(690, 420);
	FILE *file;
	file = fopen("highscore.txt", "r");
	fscanf(file, "%d", &arr_player[0].scr);
	sprintf(bests, "%d", arr_player[0]);
	bestscore.setString(bests);

	sf::Texture gameover;
	gameover.loadFromFile("game_over.png");
	sf::Sprite sprite_gameover(gameover);
	//sprite_gameover.setPosition(sf::Vector2f(200, 200));
	window.draw(sprite_gameover);
	window.draw(bestscore);

	sf::Text point111;
	char pointshow[100];

	point111.setFont(font);
	point111.setFillColor(sf::Color::Yellow);
	point111.setPosition(sf::Vector2f(690, 345));
	point111.setCharacterSize(50);
	sprintf(pointshow, "%d", point11);
	point111.setString(pointshow);
	window.draw(point111);
	//window.display();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		click_flag = 1;
	}
	return click_flag;
}

void exit()
{
	exit_flag = 1;
	sf::Texture exit;
	exit.loadFromFile("exit.png");
	sf::Sprite sprite_exit(exit);
	sprite_exit.setPosition(sf::Vector2f(450, 50));
	window.draw(sprite_exit);
	if (mousePos.x >= 475 && mousePos.x <= 630 && mousePos.y >= 180 && mousePos.y <= 210)
	{
		window.close();
	}
	if (mousePos.x >= 650 && mousePos.x <= 820 && mousePos.y >= 180 && mousePos.y <= 210)
	{
		click_flag = 1;
		exit_flag = 0;
	}
}
int main()
{

	sf::Texture mainmenu;
	sf::Texture startgame1;
	sf::Texture startgame2;
	sf::Texture spaceship1;
	sf::Texture boss1;

	sf::Texture bullet1;
	bullet1.loadFromFile("bullet1.png");
	sf::Sprite sprite_bullet1(bullet1);

	sf::Texture bullet2;
	bullet2.loadFromFile("bullet1.png");
	sf::Sprite sprite_bullet2(bullet2);

	sf::Texture bullet3;
	bullet3.loadFromFile("bullet1.png");
	sf::Sprite sprite_bullet3(bullet3);

	sf::Texture bullet4;
	bullet4.loadFromFile("bullet1.png");
	sf::Sprite sprite_bullet4(bullet4);

	sf::Texture bullet5;
	bullet5.loadFromFile("bullet1.png");
	sf::Sprite sprite_bullet5(bullet5);

	sf::Texture bullet6;
	bullet6.loadFromFile("bullet1.png");
	sf::Sprite sprite_bullet6(bullet6);

	sf::Texture bullet7;
	bullet7.loadFromFile("bullet1.png");
	sf::Sprite sprite_bullet7(bullet7);

	sf::Texture bullet8;
	bullet8.loadFromFile("bullet1.png");
	sf::Sprite sprite_bullet8(bullet8);

	sf::Texture bullet9;
	bullet9.loadFromFile("bullet1.png");
	sf::Sprite sprite_bullet9(bullet9);

	sf::Texture bullet10;
	bullet10.loadFromFile("bullet1.png");
	sf::Sprite sprite_bullet10(bullet10);

	//new addition start

	sf::Texture rocket1_1;
	sf::Texture rocket1_2;
	sf::Texture rocket1_3;

	rocket1_1.loadFromFile("rocket1.png");
	rocket1_2.loadFromFile("rocket1.png");
	rocket1_3.loadFromFile("rocket1.png");

	sf::Sprite sprite_rocket1_1(rocket1_1);
	sf::Sprite sprite_rocket1_2(rocket1_2);
	sf::Sprite sprite_rocket1_3(rocket1_3);

	sf::Texture fireball1_1;
	sf::Texture fireball1_2;
	sf::Texture fireball1_3;

	//new edition end

	sf::Texture enemybullet1;
	sf::Texture enemybullet2;
	sf::Texture enemybullet3;
	sf::Texture enemybullet4;
	sf::Texture enemybullet5;

	sf::Texture spaceship1Effect;
	spaceship1Effect.loadFromFile("spaceship1effect.png");
	sf::Sprite sprite_spaceship1Effect(spaceship1Effect);

	sf::Texture smallEnemy1;
	sf::Texture smallEnemy2;
	sf::Texture smallEnemy3;
	sf::Texture smallEnemy4;
	sf::Texture smallEnemy5;
	sf::Texture smallEnemyBullet1;
	sf::Texture smallEnemyBullet2;
	sf::Texture smallEnemyBullet3;
	sf::Texture smallEnemyBullet4;
	sf::Texture smallEnemyBullet5;

	sf::Texture ulkaPindo1;
	sf::Texture ulkaPindo2;
	sf::Texture ulkaPindo3;
	sf::Texture ulkaPindo4;
	sf::Texture ulkaPindo5;
	sf::Texture ulkaPindo6;

	smallEnemy1.loadFromFile("enemyship1.png");
	smallEnemy2.loadFromFile("enemyship1.png");
	smallEnemy3.loadFromFile("enemyship1.png");
	smallEnemy4.loadFromFile("enemyship1.png");
	smallEnemy5.loadFromFile("enemyship1.png");

	sf::Sprite sprite_smallEnemy1(smallEnemy1);
	sf::Sprite sprite_smallEnemy2(smallEnemy1);
	sf::Sprite sprite_smallEnemy3(smallEnemy1);
	sf::Sprite sprite_smallEnemy4(smallEnemy1);
	sf::Sprite sprite_smallEnemy5(smallEnemy1);

	mainmenu.loadFromFile("main_menu.png");
	startgame1.loadFromFile("background1.jpeg");
	startgame2.loadFromFile("background1.jpeg");
	spaceship1.loadFromFile("spaceship1.png");
	boss1.loadFromFile("boss1.png");

	enemybullet1.loadFromFile("bullet2.png");
	enemybullet2.loadFromFile("bullet2.png");
	enemybullet3.loadFromFile("bullet2.png");
	enemybullet4.loadFromFile("bullet2.png");
	enemybullet5.loadFromFile("bullet2.png");

	smallEnemyBullet1.loadFromFile("bullet3.png");
	smallEnemyBullet2.loadFromFile("bullet3.png");
	smallEnemyBullet3.loadFromFile("bullet3.png");
	smallEnemyBullet4.loadFromFile("bullet3.png");
	smallEnemyBullet5.loadFromFile("bullet3.png");

	ulkaPindo1.loadFromFile("ulkapindo.png");
	ulkaPindo2.loadFromFile("ulkapindo.png");
	ulkaPindo3.loadFromFile("ulkapindo.png");
	ulkaPindo4.loadFromFile("ulkapindo.png");
	ulkaPindo5.loadFromFile("ulkapindo.png");
	ulkaPindo6.loadFromFile("ulkapindo.png");

	sf::Music music;
	music.openFromFile("sound/back_sound.wav");
	music.setVolume(70);

	sf::Sprite sprite_mainmenu(mainmenu);
	sf::Sprite sprite_startgame1(startgame1);
	sf::Sprite sprite_startgame2(startgame2);
	sf::Sprite sprite_spaceship1(spaceship1);
	sf::Sprite sprite_boss1(boss1);

	sf::Sprite sprite_enemybullet1(enemybullet1);
	sf::Sprite sprite_enemybullet2(enemybullet2);
	sf::Sprite sprite_enemybullet3(enemybullet3);
	sf::Sprite sprite_enemybullet4(enemybullet4);
	sf::Sprite sprite_enemybullet5(enemybullet5);

	sf::Sprite sprite_smallEnemyBullet1(smallEnemyBullet1);
	sf::Sprite sprite_smallEnemyBullet2(smallEnemyBullet2);
	sf::Sprite sprite_smallEnemyBullet3(smallEnemyBullet3);
	sf::Sprite sprite_smallEnemyBullet4(smallEnemyBullet4);
	sf::Sprite sprite_smallEnemyBullet5(smallEnemyBullet5);

	sf::Texture smallEnemy2_1;
	sf::Texture smallEnemy2_2;
	sf::Texture smallEnemy2_3;
	sf::Texture smallEnemy2_4;
	sf::Texture smallEnemy2_5;

	sf::Texture smallEnemy2Bullet1;
	sf::Texture smallEnemy2Bullet2;
	sf::Texture smallEnemy2Bullet3;
	sf::Texture smallEnemy2Bullet4;
	sf::Texture smallEnemy2Bullet5;

	sf::Texture rocketlauncher1;
	sf::Texture rocketlauncher2;
	sf::Texture rocketlauncher3;
	sf::Texture rocketlauncher4;
	sf::Texture rocketlauncher5;
	sf::Texture rocketlauncher6;

	rocketlauncher1.loadFromFile("rocketlauncher.png");
	rocketlauncher2.loadFromFile("rocketlauncher.png");
	rocketlauncher3.loadFromFile("rocketlauncher.png");
	rocketlauncher4.loadFromFile("rocketlauncher.png");
	rocketlauncher5.loadFromFile("rocketlauncher.png");
	rocketlauncher6.loadFromFile("rocketlauncher.png");

	sf::Sprite sprite_rocketlauncher1(rocketlauncher1);
	sf::Sprite sprite_rocketlauncher2(rocketlauncher2);
	sf::Sprite sprite_rocketlauncher3(rocketlauncher3);
	sf::Sprite sprite_rocketlauncher4(rocketlauncher4);
	sf::Sprite sprite_rocketlauncher5(rocketlauncher5);
	sf::Sprite sprite_rocketlauncher6(rocketlauncher6);

	smallEnemy2_1.loadFromFile("enemyship2.png");
	smallEnemy2_2.loadFromFile("enemyship2.png");
	smallEnemy2_3.loadFromFile("enemyship2.png");
	smallEnemy2_4.loadFromFile("enemyship2.png");
	smallEnemy2_5.loadFromFile("enemyship2.png");

	smallEnemy2Bullet1.loadFromFile("bullet4.jpg");
	smallEnemy2Bullet2.loadFromFile("bullet4.jpg");
	smallEnemy2Bullet3.loadFromFile("bullet4.jpg");
	smallEnemy2Bullet4.loadFromFile("bullet4.jpg");
	smallEnemy2Bullet5.loadFromFile("bullet4.jpg");

	sf::Sprite sprite_smallEnemy2_1(smallEnemy2_1);
	sf::Sprite sprite_smallEnemy2_2(smallEnemy2_2);
	sf::Sprite sprite_smallEnemy2_3(smallEnemy2_3);
	sf::Sprite sprite_smallEnemy2_4(smallEnemy2_4);
	sf::Sprite sprite_smallEnemy2_5(smallEnemy2_5);

	sf::Sprite sprite_smallEnemy2Bullet1(smallEnemy2Bullet1);
	sf::Sprite sprite_smallEnemy2Bullet2(smallEnemy2Bullet2);
	sf::Sprite sprite_smallEnemy2Bullet3(smallEnemy2Bullet3);
	sf::Sprite sprite_smallEnemy2Bullet4(smallEnemy2Bullet4);
	sf::Sprite sprite_smallEnemy2Bullet5(smallEnemy2Bullet5);

	sf::Sprite sprite_ulkaPindo1(ulkaPindo1);
	sf::Sprite sprite_ulkaPindo2(ulkaPindo2);
	sf::Sprite sprite_ulkaPindo3(ulkaPindo3);
	sf::Sprite sprite_ulkaPindo4(ulkaPindo4);
	sf::Sprite sprite_ulkaPindo5(ulkaPindo5);
	sf::Sprite sprite_ulkaPindo6(ulkaPindo6);
	sf::Clock enemy1_clock;
	sf::Time enemy1_time = sf::milliseconds(50000);
	sf::Clock smallenemy1_clock;
	sf::Clock ulkapindo_clock;
	sf::Clock smallenemy2_clock;
	sf::Clock rocketLauncher_clock;
	sf::Time rocketLauncher_time_stage1 = sf::milliseconds(rlc1);
	sf::Time rocketLauncher_time_stage2 = sf::milliseconds(rlc2);
	sf::Time smallenemy1_time_stage1 = sf::milliseconds(s1ts1);
	sf::Time smallenemy1_time_stage2 = sf::milliseconds(s1ts2);
	sf::Time ulkapindo_time_stage1 = sf::milliseconds(uts1);
	sf::Time ulkapindo_time_stage2 = sf::milliseconds(uts2);
	sf::Time smallenemy2_time_stage1 = sf::milliseconds(s2ts1);
	sf::Time smallenemy2_time_stage2 = sf::milliseconds(s2ts2);
	sf::Clock bullet1_clock;
	sf::Time bullet1_time = sf::seconds(2);

	sf::Clock bullet2_clock;
	sf::Time bullet2_time = sf::milliseconds(bullettime);
	sf::Clock bullet4_clock;
	sf::Time bullet4_time = sf::milliseconds(bullettime);
	sf::Clock bullet3_clock;
	sf::Time bullet3_time = sf::milliseconds(bullettime);
	sf::Clock bullet5_clock;
	sf::Time bullet5_time = sf::milliseconds(bullettime);
	sf::Clock bullet6_clock;
	sf::Time bullet6_time = sf::milliseconds(bullettime);
	sf::Clock bullet7_clock;
	sf::Time bullet7_time = sf::milliseconds(bullettime);
	sf::Clock bullet8_clock;
	sf::Time bullet8_time = sf::milliseconds(bullettime);
	sf::Clock bullet9_clock;
	sf::Time bullet9_time = sf::milliseconds(bullettime);
	sf::Clock bullet10_clock;
	sf::Time bullet10_time = sf::milliseconds(bullettime);

	sf::Font font;
	font.loadFromFile("Font/TIMES.ttf");

	sf::Text life;
	char lifeshow[100];

	life.setFont(font);
	life.setFillColor(sf::Color::Yellow);
	life.setPosition(sf::Vector2f(10, 3));

	sf::Text point;
	char points[100];
	point.setFont(font);
	point.setFillColor(sf::Color::Yellow);
	point.setPosition(sf::Vector2f(500, 3));
	sf::Text bosslife;
	char enemylif[100];
	bosslife.setFont(font);
	bosslife.setFillColor(sf::Color::Yellow);
	bosslife.setPosition(sf::Vector2f(1000, 3));
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		//window.clear();
		if (music_flag == 0)
		{
			music.play();
			music_flag = 1;
			music.setLoop(true);
		}
		// Draw the sprite
		if (click_flag == 0)
		{
			welcome();
			//printf("asdf");
		}
		//ssScore << "Life: " << life1;
		if (click_flag == 1)

			window.draw(sprite_mainmenu);


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mousePos = sf::Mouse::getPosition(window);
			if (mousePos.x >= 340 && mousePos.x <= 750 && mousePos.y >= 220 && mousePos.y <= 270)
			{
				click_flag = 2;
			}
			else if (mousePos.x >= 340 && mousePos.x <= 470 && mousePos.y >= 500 && mousePos.y <= 540)
			{
				click_flag = 3;
			}
			if (mousePos.x >= 340 && mousePos.x <= 760 && mousePos.y >= 400 && mousePos.y <= 450)
			{
				click_flag = 4;
			}
			if (mousePos.x >= 340 && mousePos.x <= 750 && mousePos.y >= 300 && mousePos.y <= 350)
			{
				click_flag = 5;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) click_flag = 1;
		if (click_flag == 2 && exit_flag == 0)
		{
			//ssScore << "Life: " << life1;
			//life.setString(ssScore.str());
			//window.draw(mylevel);

			if (clock1 == 0)
			{
				enemy1_clock.restart();
				smallenemy1_clock.restart();
				ulkapindo_clock.restart();
				smallenemy2_clock.restart();
				clock1 = 1;
			}
			window.clear();
			sprite_startgame1.setPosition(sf::Vector2f(background1.x, background1.y));
			background1.y += .3;
			if (background1.y >= 729)
			{
				background1.y = -729;
				//window.clear();
			}
			window.draw(sprite_startgame1);
			sprite_startgame2.setPosition(sf::Vector2f(background2.x, background2.y));
			background2.y += .3;
			if (background2.y >= 729)
			{
				background2.y = -729;
				//window.clear();
			}
			window.draw(sprite_startgame2);
			window.draw(sprite_spaceship1);
			//window.draw(life);
			//window.draw(point);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				click_flag = 6;
			}
			//window.draw(boss);

			spaceship1move();
			sprite_spaceship1.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
			//this is for enemy
			/*window.draw(sprite_smallEnemy1);
			if (smallEnemy1Pos_y < 30)
			{
			smallEnemy1Pos_y += 1;


			}
			sprite_smallEnemy1.setPosition(sf::Vector2f(smallEnemy1Pos_x, smallEnemy1Pos_y));

			window.draw(sprite_smallEnemy2);
			if (smallEnemy2Pos_x < 280)
			{
			smallEnemy2Pos_x += 1;

			}
			if (smallEnemy1Pos_y == 30 && smallEnemyBullet1Pos_x < 1300 && smallEnemyBullet1Pos_y < 732)
			{
			smallEnemyBullet1Pos_y += .25;
			smallEnemyCounter1++;

			if (smallEnemyBullet1Pos_y >= spaceshipPos_y && smallEnemyBullet1Pos_y <= spaceshipPos_y + 20 && smallEnemyBullet1Pos_x >= spaceshipPos_x + 20 && smallEnemyBullet1Pos_x <= spaceshipPos_x + 140)
			{
			smallEnemyBullet1Pos_y = 731;
			//life1 = life1 - 10;
			sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
			window.draw(sprite_spaceship1Effect);
			}
			}
			sprite_smallEnemy2.setPosition(sf::Vector2f(smallEnemy2Pos_x, smallEnemy2Pos_y));
			window.draw(sprite_smallEnemy3);
			if (smallEnemy3Pos_x > 1210)
			{
			smallEnemy3Pos_x -= 1;

			}
			sprite_smallEnemy3.setPosition(sf::Vector2f(smallEnemy3Pos_x, smallEnemy3Pos_y));
			window.draw(sprite_smallEnemy4);
			if (smallEnemy4Pos_x > 980)
			{
			smallEnemy4Pos_x -= 1;

			}
			sprite_smallEnemy4.setPosition(sf::Vector2f(smallEnemy4Pos_x, smallEnemy4Pos_y));
			window.draw(sprite_smallEnemy5);
			if (smallEnemy5Pos_y < 30)
			{
			smallEnemy5Pos_y += 1;

			}
			sprite_smallEnemy5.setPosition(sf::Vector2f(smallEnemy5Pos_x, smallEnemy5Pos_y));*/
			if (smallenemy1_clock.getElapsedTime() < smallenemy1_time_stage1)
			{

				if (smallEnemy1Pos_y < 30)
				{
					smallEnemy1Pos_y += 1;

				}
				//smallenemyship-1 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy1Pos_x && bullet1Pos_x <= smallEnemy1Pos_x + 64 && bullet1Pos_y == smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -11200;
					point1 += 10;
					//smallEnemy1VanishFlag1 = 1;

				}
				else if (bullet2Pos_x >= smallEnemy1Pos_x && bullet2Pos_x <= smallEnemy1Pos_x + 64 && bullet2Pos_y == smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -11200;
					//smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy1Pos_x && bullet3Pos_x <= smallEnemy1Pos_x + 64 && bullet3Pos_y == smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -11200;
					//smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}
				else if (bullet4Pos_x >= smallEnemy1Pos_x && bullet4Pos_x <= smallEnemy1Pos_x + 64 && bullet4Pos_y == smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -11200;
					//smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy1Pos_x && bullet5Pos_x <= smallEnemy1Pos_x + 64 && bullet5Pos_y == smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy1Pos_x && bullet6Pos_x <= smallEnemy1Pos_x + 64 && bullet6Pos_y == smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy1Pos_x && bullet7Pos_x <= smallEnemy1Pos_x + 64 && bullet7Pos_y == smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy1Pos_x && bullet8Pos_x <= smallEnemy1Pos_x + 64 && bullet8Pos_y == smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy1Pos_x && bullet9Pos_x <= smallEnemy1Pos_x + 64 && bullet9Pos_y == smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy1Pos_x && bullet10Pos_x <= smallEnemy1Pos_x + 64 && bullet10Pos_y == smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -11200;
					point1 += 10;
				}
				//smallenemy-1 vanish hobar code ekhane sesh

				sprite_smallEnemy1.setPosition(sf::Vector2f(smallEnemy1Pos_x, smallEnemy1Pos_y));
				window.draw(sprite_smallEnemy1);
				//printf("%d\n", smallEnemy1VanishFlag1);
				// smallenemy bullet no-1 er code

				if (smallEnemy1Pos_y == 30 && smallEnemyBullet1Pos_x < 1300 && smallEnemyBullet1Pos_y < 732)
				{
					smallEnemyBullet1Pos_y += .25;
					smallEnemyCounter1++;

					if (smallEnemyBullet1Pos_y >= spaceshipPos_y && smallEnemyBullet1Pos_y <= spaceshipPos_y + 20 && smallEnemyBullet1Pos_x >= spaceshipPos_x + 20 && smallEnemyBullet1Pos_x <= spaceshipPos_x + 140)
					{
						smallEnemyBullet1Pos_y = 731;
						life1 = life1 - 5;
						sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
						window.draw(sprite_spaceship1Effect);
					}


				}

				//enemybullet-1 vanish hobar code

				//	printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemyBullet1Pos_x + 5 && bullet1Pos_x <= smallEnemyBullet1Pos_x + 15 && bullet1Pos_y >= smallEnemyBullet1Pos_y + 10)
				{
					smallEnemyBullet1Pos_x = -200;


				}
				else if (bullet2Pos_x >= smallEnemyBullet1Pos_x + 5 && bullet2Pos_x <= smallEnemyBullet1Pos_x + 15 && bullet2Pos_y == smallEnemyBullet1Pos_y + 10)
				{
					smallEnemyBullet1Pos_x = -200;


				}
				else if (bullet3Pos_x >= smallEnemyBullet1Pos_x + 5 && bullet3Pos_x <= smallEnemyBullet1Pos_x + 15 && bullet3Pos_y == smallEnemyBullet1Pos_y + 10)
				{
					smallEnemyBullet1Pos_x = -200;


				}
				else if (bullet4Pos_x >= smallEnemyBullet1Pos_x + 5 && bullet4Pos_x <= smallEnemyBullet1Pos_x + 15 && bullet4Pos_y == smallEnemyBullet1Pos_y + 10)
				{
					smallEnemyBullet1Pos_x = -200;


				}
				else if (bullet5Pos_x >= smallEnemyBullet1Pos_x + 5 && bullet5Pos_x <= smallEnemyBullet1Pos_x + 15 && bullet5Pos_y == smallEnemyBullet1Pos_y + 10)
				{
					smallEnemyBullet1Pos_x = -200;


				}
				else if (bullet6Pos_x >= smallEnemyBullet1Pos_x + 5 && bullet6Pos_x <= smallEnemyBullet1Pos_x + 15 && bullet6Pos_y == smallEnemyBullet1Pos_y + 10)
				{
					smallEnemyBullet1Pos_x = -200;


				}
				else if (bullet7Pos_x >= smallEnemyBullet1Pos_x + 5 && bullet7Pos_x <= smallEnemyBullet1Pos_x + 15 && bullet7Pos_y == smallEnemyBullet1Pos_y + 10)
				{
					smallEnemyBullet1Pos_x = -200;


				}
				else if (bullet8Pos_x >= smallEnemyBullet1Pos_x + 5 && bullet8Pos_x <= smallEnemyBullet1Pos_x + 15 && bullet8Pos_y == smallEnemyBullet1Pos_y + 10)
				{
					smallEnemyBullet1Pos_x = -200;


				}
				else if (bullet9Pos_x >= smallEnemyBullet1Pos_x + 5 && bullet9Pos_x <= smallEnemyBullet1Pos_x + 15 && bullet9Pos_y == smallEnemyBullet1Pos_y + 10)
				{
					smallEnemyBullet1Pos_x = -200;

				}
				else if (bullet10Pos_x >= smallEnemyBullet1Pos_x + 5 && bullet10Pos_x <= smallEnemyBullet1Pos_x + 15 && bullet10Pos_y == smallEnemyBullet1Pos_y + 10)
				{
					smallEnemyBullet1Pos_x = -200;


				}

				//small enemy-1 bullet-2 er vamish hobaar code

				sprite_smallEnemyBullet1.setPosition(sf::Vector2f(smallEnemyBullet1Pos_x, smallEnemyBullet1Pos_y));
				if (smallEnemy1Pos_y == 30) window.draw(sprite_smallEnemyBullet1);

				//smallenemy 2 er code
				if (smallEnemy2Pos_x < 280)
				{
					smallEnemy2Pos_x += 1;

				}

				//smallenemyship-2 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2Pos_x && bullet1Pos_x <= smallEnemy2Pos_x + 64 && bullet1Pos_y == smallEnemy2Pos_y + 64)
				{
					smallEnemy1Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2Pos_x && bullet2Pos_x <= smallEnemy2Pos_x + 64 && bullet2Pos_y == smallEnemy2Pos_y + 64)
				{
					smallEnemy1Pos_x = -12000;
					point1 += 10;

				}
				else if (bullet3Pos_x >= smallEnemy2Pos_x && bullet3Pos_x <= smallEnemy2Pos_x + 64 && bullet3Pos_y == smallEnemy2Pos_y + 64)
				{
					smallEnemy1Pos_x = -12000;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2Pos_x && bullet4Pos_x <= smallEnemy2Pos_x + 64 && bullet4Pos_y == smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2Pos_x && bullet5Pos_x <= smallEnemy2Pos_x + 64 && bullet5Pos_y == smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2Pos_x && bullet6Pos_x <= smallEnemy2Pos_x + 64 && bullet6Pos_y == smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12800;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2Pos_x && bullet7Pos_x <= smallEnemy2Pos_x + 64 && bullet7Pos_y == smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2Pos_x && bullet8Pos_x <= smallEnemy2Pos_x + 64 && bullet8Pos_y == smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy2Pos_x && bullet9Pos_x <= smallEnemy2Pos_x + 64 && bullet9Pos_y == smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy2Pos_x && bullet10Pos_x <= smallEnemy2Pos_x + 64 && bullet10Pos_y == smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				//smallenemy-2 vanish hobar code ekhane sesh

				sprite_smallEnemy2.setPosition(sf::Vector2f(smallEnemy2Pos_x, smallEnemy2Pos_y));
				window.draw(sprite_smallEnemy2);

				//smallenemy bullet no-2 er code
				if (smallEnemy2Pos_x == 280 && smallEnemyCounter1 > 300 && smallEnemyBullet2Pos_x < 1300 && smallEnemyBullet2Pos_y < 740)

				{
					smallEnemyBullet2Pos_y += .25;

					if (smallEnemyBullet2Pos_y >= spaceshipPos_y && smallEnemyBullet2Pos_y <= spaceshipPos_y + 20 && smallEnemyBullet2Pos_x >= spaceshipPos_x + 20 && smallEnemyBullet2Pos_x <= spaceshipPos_x + 140)
					{
						smallEnemyBullet2Pos_y = 731;
						life1 = life1 - 5;
						sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
						window.draw(sprite_spaceship1Effect);
					}

				}

				sprite_smallEnemyBullet2.setPosition(sf::Vector2f(smallEnemyBullet2Pos_x, smallEnemyBullet2Pos_y));
				if (smallEnemy2Pos_x == 280 && smallEnemyCounter1 > 300) window.draw(sprite_smallEnemyBullet2);

				//smallenemy 3 er code

				if (smallEnemy3Pos_x > 1210)
				{
					smallEnemy3Pos_x -= .25;


				}
				smallEnemyCounter2++;

				//smallenemyship-3 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy3Pos_x && bullet1Pos_x <= smallEnemy3Pos_x + 64 && bullet1Pos_y == smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy3Pos_x && bullet2Pos_x <= smallEnemy3Pos_x + 64 && bullet2Pos_y == smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;

				}
				else if (bullet3Pos_x >= smallEnemy3Pos_x && bullet3Pos_x <= smallEnemy3Pos_x + 64 && bullet3Pos_y == smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet4Pos_x >= smallEnemy3Pos_x && bullet4Pos_x <= smallEnemy3Pos_x + 64 && bullet4Pos_y == smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy3Pos_x && bullet5Pos_x <= smallEnemy3Pos_x + 64 && bullet5Pos_y == smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy3Pos_x && bullet6Pos_x <= smallEnemy3Pos_x + 64 && bullet6Pos_y == smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12800;

				}
				else if (bullet7Pos_x >= smallEnemy3Pos_x && bullet7Pos_x <= smallEnemy3Pos_x + 64 && bullet7Pos_y == smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy3Pos_x && bullet8Pos_x <= smallEnemy3Pos_x + 64 && bullet8Pos_y == smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;

				}
				else if (bullet9Pos_x >= smallEnemy3Pos_x && bullet9Pos_x <= smallEnemy3Pos_x + 64 && bullet9Pos_y == smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy3Pos_x && bullet10Pos_x <= smallEnemy3Pos_x + 64 && bullet10Pos_y == smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				//smallenemy-3 vanish hobar code ekhane sesh

				sprite_smallEnemy3.setPosition(sf::Vector2f(smallEnemy3Pos_x, smallEnemy3Pos_y));
				window.draw(sprite_smallEnemy3);

				//smallenemy bullet no-3 er code

				if (smallEnemy3Pos_x == 1210 && smallEnemyCounter2 > 480 && smallEnemyBullet3Pos_x < 1300 && smallEnemyBullet3Pos_y < 740)

				{
					smallEnemyBullet3Pos_y += .25;

					if (smallEnemyBullet3Pos_y >= spaceshipPos_y && smallEnemyBullet3Pos_y <= spaceshipPos_y + 20 && smallEnemyBullet3Pos_x >= spaceshipPos_x + 20 && smallEnemyBullet3Pos_x <= spaceshipPos_x + 140)
					{
						smallEnemyBullet3Pos_y = 731;
						life1 = life1 - 5;
						sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
						window.draw(sprite_spaceship1Effect);
					}

				}

				sprite_smallEnemyBullet3.setPosition(sf::Vector2f(smallEnemyBullet3Pos_x, smallEnemyBullet3Pos_y));
				if (smallEnemy3Pos_x == 1210 && smallEnemyCounter2 > 480) window.draw(sprite_smallEnemyBullet3);

				//smallenemy 4 er code

				if (smallEnemy4Pos_x > 980)
				{
					smallEnemy4Pos_x -= .25;
				}
				smallEnemyCounter3++;

				//smallenemyship-4 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy4Pos_x && bullet1Pos_x <= smallEnemy4Pos_x + 64 && bullet1Pos_y == smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy4Pos_x && bullet2Pos_x <= smallEnemy4Pos_x + 64 && bullet2Pos_y == smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;

				}
				else if (bullet3Pos_x >= smallEnemy4Pos_x && bullet3Pos_x <= smallEnemy4Pos_x + 64 && bullet3Pos_y == smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet4Pos_x >= smallEnemy4Pos_x && bullet4Pos_x <= smallEnemy4Pos_x + 64 && bullet4Pos_y == smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy4Pos_x && bullet5Pos_x <= smallEnemy4Pos_x + 64 && bullet5Pos_y == smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy4Pos_x && bullet6Pos_x <= smallEnemy4Pos_x + 64 && bullet6Pos_y == smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12800;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy4Pos_x && bullet7Pos_x <= smallEnemy4Pos_x + 64 && bullet7Pos_y == smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy4Pos_x && bullet8Pos_x <= smallEnemy4Pos_x + 64 && bullet8Pos_y == smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy4Pos_x && bullet9Pos_x <= smallEnemy4Pos_x + 64 && bullet9Pos_y == smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy4Pos_x && bullet10Pos_x <= smallEnemy4Pos_x + 64 && bullet10Pos_y == smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				//smallenemy-4 vanish hobar code ekhane sesh

				//printf("%f\n", smallEnemy4Pos_x);
				sprite_smallEnemy4.setPosition(sf::Vector2f(smallEnemy4Pos_x, smallEnemy4Pos_y));
				if (smallEnemy4Pos_x >= 980) window.draw(sprite_smallEnemy4);

				//smallenemy bullet no-4 er code

				if (smallEnemy4Pos_x <= 980 && smallEnemyCounter3 > 1000 && smallEnemyBullet4Pos_x < 1300 && smallEnemyBullet4Pos_y < 740)

				{
					smallEnemyBullet4Pos_y += .25;

					if (smallEnemyBullet4Pos_y >= spaceshipPos_y && smallEnemyBullet4Pos_y <= spaceshipPos_y + 20 && smallEnemyBullet4Pos_x >= spaceshipPos_x + 20 && smallEnemyBullet4Pos_x <= spaceshipPos_x + 140)
					{
						smallEnemyBullet4Pos_y = 731;
						life1 = life1 - 5;
						sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
						window.draw(sprite_spaceship1Effect);
					}

				}

				sprite_smallEnemyBullet4.setPosition(sf::Vector2f(smallEnemyBullet4Pos_x, smallEnemyBullet4Pos_y));
				if (smallEnemy4Pos_x == 980 && smallEnemyCounter3 > 1000) window.draw(sprite_smallEnemyBullet4);

				//smallenemy 5 er code

				if (smallEnemy5Pos_y < 30)
				{
					smallEnemy5Pos_y += .25;
				}
				smallEnemyCounter4++;

				//smallenemyship-5 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy5Pos_x && bullet1Pos_x <= smallEnemy5Pos_x + 64 && bullet1Pos_y == smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy5Pos_x && bullet2Pos_x <= smallEnemy5Pos_x + 64 && bullet2Pos_y == smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;

				}
				else if (bullet3Pos_x >= smallEnemy5Pos_x && bullet3Pos_x <= smallEnemy5Pos_x + 64 && bullet3Pos_y == smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet4Pos_x >= smallEnemy5Pos_x && bullet4Pos_x <= smallEnemy5Pos_x + 64 && bullet4Pos_y == smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy5Pos_x && bullet5Pos_x <= smallEnemy5Pos_x + 64 && bullet5Pos_y == smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy5Pos_x && bullet6Pos_x <= smallEnemy5Pos_x + 64 && bullet6Pos_y == smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12800;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy5Pos_x && bullet7Pos_x <= smallEnemy5Pos_x + 64 && bullet7Pos_y == smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy5Pos_x && bullet8Pos_x <= smallEnemy5Pos_x + 64 && bullet8Pos_y == smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy5Pos_x && bullet9Pos_x <= smallEnemy5Pos_x + 64 && bullet9Pos_y == smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy5Pos_x && bullet10Pos_x <= smallEnemy5Pos_x + 64 && bullet10Pos_y == smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				//smallenemy-5 vanish hobar code ekhane sesh

				sprite_smallEnemy5.setPosition(sf::Vector2f(smallEnemy5Pos_x, smallEnemy5Pos_y));
				window.draw(sprite_smallEnemy5);

				//smallenemy bullet no-5 er code

				if (smallEnemy5Pos_y == 30 && smallEnemyCounter4 > 1300 && smallEnemyBullet5Pos_x < 1300 && smallEnemyBullet5Pos_y < 740)

				{
					smallEnemyBullet5Pos_y += .25;

					if (smallEnemyBullet5Pos_y >= spaceshipPos_y && smallEnemyBullet5Pos_y <= spaceshipPos_y + 20 && smallEnemyBullet5Pos_x >= spaceshipPos_x + 20 && smallEnemyBullet5Pos_x <= spaceshipPos_x + 140)
					{
						smallEnemyBullet5Pos_y = 731;
						life1 = life1 - 5;
						sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
						window.draw(sprite_spaceship1Effect);
					}

				}

				sprite_smallEnemyBullet5.setPosition(sf::Vector2f(smallEnemyBullet5Pos_x, smallEnemyBullet5Pos_y));
				if (smallEnemy5Pos_y == 30 && smallEnemyCounter4 > 1300) window.draw(sprite_smallEnemyBullet5);
			}
			//smallenemy screen theke remove hobaar code
			else
			{
				smallEnemy1Pos_x += .25;
				smallEnemy1Pos_y += .25;

				//smallenemyship-1 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy1Pos_x && bullet1Pos_x <= smallEnemy1Pos_x + 64 && bullet1Pos_y >= smallEnemy1Pos_y + 63 && bullet1Pos_y <= smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -1200;
					//smallEnemy1VanishFlag1 = 1;

				}
				else if (bullet2Pos_x >= smallEnemy1Pos_x && bullet2Pos_x <= smallEnemy1Pos_x + 64 && bullet2Pos_y >= smallEnemy1Pos_y + 63 && bullet2Pos_y <= smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -1200;
					//smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy1Pos_x && bullet3Pos_x <= smallEnemy1Pos_x + 64 && bullet3Pos_y >= smallEnemy1Pos_y + 63 && bullet3Pos_y <= smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -1200;
					//smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}
				else if (bullet4Pos_x >= smallEnemy1Pos_x && bullet4Pos_x <= smallEnemy1Pos_x + 64 && bullet4Pos_y >= smallEnemy1Pos_y + 63 && bullet4Pos_y <= smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -1200;
					//smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy1Pos_x && bullet5Pos_x <= smallEnemy1Pos_x + 64 && bullet5Pos_y >= smallEnemy1Pos_y + 63 && bullet5Pos_y <= smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -1200;
					//smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy1Pos_x && bullet6Pos_x <= smallEnemy1Pos_x + 64 && bullet6Pos_y >= smallEnemy1Pos_y + 63 && bullet6Pos_y <= smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -12800;
					//smallEnemy1VanishFlag1 = 1;
				}
				else if (bullet7Pos_x >= smallEnemy1Pos_x && bullet7Pos_x <= smallEnemy1Pos_x + 64 && bullet7Pos_y >= smallEnemy1Pos_y + 63 && bullet7Pos_y <= smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -1200;
					//smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy1Pos_x && bullet8Pos_x <= smallEnemy1Pos_x + 64 && bullet8Pos_y >= smallEnemy1Pos_y + 63 && bullet8Pos_y <= smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -1200;
					///smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy1Pos_x && bullet9Pos_x <= smallEnemy1Pos_x + 64 && bullet9Pos_y >= smallEnemy1Pos_y + 63 && bullet9Pos_y <= smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -1200;
					//smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy1Pos_x && bullet10Pos_x <= smallEnemy1Pos_x + 64 && bullet10Pos_y >= smallEnemy1Pos_y + 63 && bullet10Pos_y <= smallEnemy1Pos_y + 64)
				{
					smallEnemy1Pos_x = -1200;
					//smallEnemy1VanishFlag1 = 1;
					point1 += 10;
				}

				//smallenemy-1 vanish hobar code ekhane sesh


				sprite_smallEnemy1.setPosition(sf::Vector2f(smallEnemy1Pos_x, smallEnemy1Pos_y));
				window.draw(sprite_smallEnemy1);

				if (smallEnemy1Pos_x >= spaceshipPos_x && smallEnemy1Pos_x <= spaceshipPos_x + 150 && smallEnemy1Pos_y >= spaceshipPos_y && smallEnemy1Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					//printf("%d\n", life1);
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (smallEnemy1Pos_x >= spaceshipPos_x && smallEnemy1Pos_x <= spaceshipPos_x + 150 && smallEnemy1Pos_y >= spaceshipPos_y && smallEnemy1Pos_y <= spaceshipPos_y + 150 && smallEnemy1_Flag == 0)
				{
					life1 -= 5;
					smallEnemy1_Flag = 1;
					//printf("%d\n", life1);
				}
				smallEnemy2Pos_x += .25;
				smallEnemy2Pos_y += .25;

				//smallenemyship-2 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2Pos_x && bullet1Pos_x <= smallEnemy2Pos_x + 64 && bullet1Pos_y >= smallEnemy2Pos_y + 63 && bullet1Pos_y <= smallEnemy2Pos_y + 64)
				{
					smallEnemy1Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2Pos_x && bullet2Pos_x <= smallEnemy2Pos_x + 64 && bullet2Pos_y >= smallEnemy2Pos_y + 63 && bullet2Pos_y <= smallEnemy2Pos_y + 64)
				{
					smallEnemy1Pos_x = -12000;
					point1 += 10;

				}
				else if (bullet3Pos_x >= smallEnemy2Pos_x && bullet3Pos_x <= smallEnemy2Pos_x + 64 && bullet3Pos_y >= smallEnemy2Pos_y + 63 && bullet3Pos_y <= smallEnemy2Pos_y + 64)
				{
					smallEnemy1Pos_x = -12000;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2Pos_x && bullet4Pos_x <= smallEnemy2Pos_x + 64 && bullet4Pos_y >= smallEnemy2Pos_y + 63 && bullet4Pos_y <= smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2Pos_x && bullet5Pos_x <= smallEnemy2Pos_x + 64 && bullet5Pos_y >= smallEnemy2Pos_y + 63 && bullet5Pos_y <= smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2Pos_x && bullet6Pos_x <= smallEnemy2Pos_x + 64 && bullet6Pos_y >= smallEnemy2Pos_y + 63 && bullet6Pos_y <= smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12800;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2Pos_x && bullet7Pos_x <= smallEnemy2Pos_x + 64 && bullet7Pos_y >= smallEnemy2Pos_y + 63 && bullet7Pos_y <= smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2Pos_x && bullet8Pos_x <= smallEnemy2Pos_x + 64 && bullet8Pos_y >= smallEnemy2Pos_y + 63 && bullet8Pos_y <= smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy2Pos_x && bullet9Pos_x <= smallEnemy2Pos_x + 64 && bullet9Pos_y >= smallEnemy2Pos_y + 63 && bullet9Pos_y <= smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy2Pos_x && bullet10Pos_x <= smallEnemy2Pos_x + 64 && bullet10Pos_y >= smallEnemy2Pos_y + 63 && bullet10Pos_y <= smallEnemy2Pos_y + 64)
				{
					smallEnemy2Pos_x = -12000;
					point1 += 10;
				}
				//smallenemy-2 vanish hobar code ekhane sesh

				sprite_smallEnemy2.setPosition(sf::Vector2f(smallEnemy2Pos_x, smallEnemy2Pos_y));

				if (smallEnemy2Pos_x >= spaceshipPos_x && smallEnemy2Pos_x <= spaceshipPos_x + 150 && smallEnemy2Pos_y >= spaceshipPos_y && smallEnemy2Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					//printf("%d\n", life1);
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (smallEnemy2Pos_x >= spaceshipPos_x && smallEnemy2Pos_x <= spaceshipPos_x + 150 && smallEnemy2Pos_y >= spaceshipPos_y && smallEnemy2Pos_y <= spaceshipPos_y + 150 && smallEnemy2_Flag == 0)
				{
					life1 -= 5;
					smallEnemy2_Flag = 1;
				}
				window.draw(sprite_smallEnemy2);
				smallEnemy3Pos_x -= .25;
				smallEnemy3Pos_y += .250;

				//smallenemyship-3 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy3Pos_x && bullet1Pos_x <= smallEnemy3Pos_x + 64 && bullet1Pos_y >= smallEnemy3Pos_y + 63 && bullet1Pos_y <= smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy3Pos_x && bullet2Pos_x <= smallEnemy3Pos_x + 64 && bullet2Pos_y >= smallEnemy3Pos_y + 63 && bullet2Pos_y <= smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;

				}
				else if (bullet3Pos_x >= smallEnemy3Pos_x && bullet3Pos_x <= smallEnemy3Pos_x + 64 && bullet3Pos_y >= smallEnemy3Pos_y + 63 && bullet3Pos_y <= smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet4Pos_x >= smallEnemy3Pos_x && bullet4Pos_x <= smallEnemy3Pos_x + 64 && bullet4Pos_y >= smallEnemy3Pos_y + 63 && bullet4Pos_y <= smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy3Pos_x && bullet5Pos_x <= smallEnemy3Pos_x + 64 && bullet5Pos_y >= smallEnemy3Pos_y + 63 && bullet5Pos_y <= smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy3Pos_x && bullet6Pos_x <= smallEnemy3Pos_x + 64 && bullet6Pos_y >= smallEnemy3Pos_y + 63 && bullet6Pos_y <= smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12800;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy3Pos_x && bullet7Pos_x <= smallEnemy3Pos_x + 64 && bullet7Pos_y >= smallEnemy3Pos_y + 63 && bullet7Pos_y <= smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy3Pos_x && bullet8Pos_x <= smallEnemy3Pos_x + 64 && bullet8Pos_y >= smallEnemy3Pos_y + 63 && bullet8Pos_y <= smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy3Pos_x && bullet9Pos_x <= smallEnemy3Pos_x + 64 && bullet9Pos_y >= smallEnemy3Pos_y + 63 && bullet9Pos_y <= smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy3Pos_x && bullet10Pos_x <= smallEnemy3Pos_x + 64 && bullet10Pos_y >= smallEnemy3Pos_y + 63 && bullet10Pos_y <= smallEnemy3Pos_y + 64)
				{
					smallEnemy3Pos_x = -12000;
					point1 += 10;
				}
				//smallenemy-3 vanish hobar code ekhane sesh

				sprite_smallEnemy3.setPosition(sf::Vector2f(smallEnemy3Pos_x, smallEnemy3Pos_y));
				window.draw(sprite_smallEnemy3);

				if (smallEnemy3Pos_x >= spaceshipPos_x && smallEnemy3Pos_x <= spaceshipPos_x + 150 && smallEnemy3Pos_y >= spaceshipPos_y && smallEnemy3Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 5;
					//printf("%d\n", life1);
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (smallEnemy3Pos_x >= spaceshipPos_x && smallEnemy3Pos_x <= spaceshipPos_x + 150 && smallEnemy3Pos_y >= spaceshipPos_y && smallEnemy3Pos_y <= spaceshipPos_y + 150 && smallEnemy3_Flag == 0)
				{
					life1 -= 5;
					smallEnemy3_Flag = 1;
				}
				window.draw(sprite_smallEnemy4);
				smallEnemy4Pos_x -= .25;
				smallEnemy4Pos_y += .250;
				sprite_smallEnemy4.setPosition(sf::Vector2f(smallEnemy4Pos_x, smallEnemy4Pos_y));

				//smallenemyship-4 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy4Pos_x && bullet1Pos_x <= smallEnemy4Pos_x + 64 && bullet1Pos_y >= smallEnemy4Pos_y + 63 && bullet1Pos_y <= smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy4Pos_x && bullet2Pos_x <= smallEnemy4Pos_x + 64 && bullet2Pos_y >= smallEnemy4Pos_y + 63 && bullet2Pos_y <= smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;

				}
				else if (bullet3Pos_x >= smallEnemy4Pos_x && bullet3Pos_x <= smallEnemy4Pos_x + 64 && bullet3Pos_y >= smallEnemy4Pos_y + 63 && bullet3Pos_y <= smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet4Pos_x >= smallEnemy4Pos_x && bullet4Pos_x <= smallEnemy4Pos_x + 64 && bullet4Pos_y >= smallEnemy4Pos_y + 63 && bullet4Pos_y <= smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy4Pos_x && bullet5Pos_x <= smallEnemy4Pos_x + 64 && bullet5Pos_y >= smallEnemy4Pos_y + 63 && bullet5Pos_y <= smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy4Pos_x && bullet6Pos_x <= smallEnemy4Pos_x + 64 && bullet6Pos_y >= smallEnemy4Pos_y + 63 && bullet6Pos_y <= smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12800;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy4Pos_x && bullet7Pos_x <= smallEnemy4Pos_x + 64 && bullet7Pos_y >= smallEnemy4Pos_y + 63 && bullet7Pos_y <= smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy4Pos_x && bullet8Pos_x <= smallEnemy4Pos_x + 64 && bullet8Pos_y >= smallEnemy4Pos_y + 63 && bullet8Pos_y <= smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy4Pos_x && bullet9Pos_x <= smallEnemy4Pos_x + 64 && bullet9Pos_y >= smallEnemy4Pos_y + 63 && bullet9Pos_y <= smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy4Pos_x && bullet10Pos_x <= smallEnemy4Pos_x + 64 && bullet10Pos_y >= smallEnemy4Pos_y + 63 && bullet10Pos_y <= smallEnemy4Pos_y + 64)
				{
					smallEnemy4Pos_x = -12000;
					point1 += 10;
				}
				//smallenemy-4 vanish hobar code ekhane sesh



				if (smallEnemy4Pos_x >= spaceshipPos_x && smallEnemy4Pos_x <= spaceshipPos_x + 150 && smallEnemy4Pos_y >= spaceshipPos_y && smallEnemy4Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 5;
					//printf("%d\n", life1);
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (smallEnemy4Pos_x >= spaceshipPos_x && smallEnemy4Pos_x <= spaceshipPos_x + 150 && smallEnemy4Pos_y >= spaceshipPos_y && smallEnemy4Pos_y <= spaceshipPos_y + 150 && smallEnemy4_Flag == 0)
				{
					life1 -= 5;
					smallEnemy4_Flag = 1;
				}
				smallEnemy5Pos_y += .25;

				//smallenemyship-5 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy5Pos_x && bullet1Pos_x <= smallEnemy5Pos_x + 64 && bullet1Pos_y >= smallEnemy5Pos_y + 63 && bullet1Pos_y <= smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy5Pos_x && bullet2Pos_x <= smallEnemy5Pos_x + 64 && bullet2Pos_y >= smallEnemy5Pos_y + 63 && bullet2Pos_y <= smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;

				}
				else if (bullet3Pos_x >= smallEnemy5Pos_x && bullet3Pos_x <= smallEnemy5Pos_x + 64 && bullet3Pos_y >= smallEnemy5Pos_y + 63 && bullet3Pos_y <= smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet4Pos_x >= smallEnemy5Pos_x && bullet4Pos_x <= smallEnemy5Pos_x + 64 && bullet4Pos_y >= smallEnemy5Pos_y + 63 && bullet4Pos_y <= smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;

				}
				else if (bullet5Pos_x >= smallEnemy5Pos_x && bullet5Pos_x <= smallEnemy5Pos_x + 64 && bullet5Pos_y >= smallEnemy5Pos_y + 63 && bullet5Pos_y <= smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy5Pos_x && bullet6Pos_x <= smallEnemy5Pos_x + 64 && bullet6Pos_y >= smallEnemy5Pos_y + 63 && bullet6Pos_y <= smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12800;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy5Pos_x && bullet7Pos_x <= smallEnemy5Pos_x + 64 && bullet7Pos_y >= smallEnemy5Pos_y + 63 && bullet7Pos_y <= smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy5Pos_x && bullet8Pos_x <= smallEnemy5Pos_x + 64 && bullet8Pos_y >= smallEnemy5Pos_y + 63 && bullet8Pos_y <= smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy5Pos_x && bullet9Pos_x <= smallEnemy5Pos_x + 64 && bullet9Pos_y >= smallEnemy5Pos_y + 63 && bullet9Pos_y <= smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy5Pos_x && bullet10Pos_x <= smallEnemy5Pos_x + 64 && bullet10Pos_y >= smallEnemy5Pos_y + 63 && bullet10Pos_y <= smallEnemy5Pos_y + 64)
				{
					smallEnemy5Pos_x = -12000;
					point1 += 10;
				}
				//smallenemy-5 vanish hobar code ekhane sesh


				sprite_smallEnemy5.setPosition(sf::Vector2f(smallEnemy5Pos_x, smallEnemy5Pos_y));
				window.draw(sprite_smallEnemy5);

				if (smallEnemy5Pos_x >= spaceshipPos_x && smallEnemy5Pos_x <= spaceshipPos_x + 150 && smallEnemy5Pos_y >= spaceshipPos_y && smallEnemy5Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					//printf("%d\n", life1);
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (smallEnemy5Pos_x >= spaceshipPos_x && smallEnemy5Pos_x <= spaceshipPos_x + 150 && smallEnemy5Pos_y >= spaceshipPos_y && smallEnemy5Pos_y <= spaceshipPos_y + 150 && smallEnemy5_Flag == 0)
				{
					life1 -= 5;
					smallEnemy5_Flag = 1;
				}
			}

			//ulkapindo er code
			if (ulkapindo_clock.getElapsedTime() > smallenemy1_time_stage2)
			{
				//ulkapindo - 1
				ulkaPindo1Pos_y += .2;

				//start coding of collision between ulka-1 and bullet and bullet get vanished

				if (bullet1Pos_x >= ulkaPindo1Pos_x && bullet1Pos_x <= ulkaPindo1Pos_x + 64 && bullet1Pos_y >= ulkaPindo1Pos_y + 32 && bullet1Pos_y <= ulkaPindo1Pos_y + 64)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= ulkaPindo1Pos_x && bullet2Pos_x <= ulkaPindo1Pos_x + 64 && bullet2Pos_y >= ulkaPindo1Pos_y + 32 && bullet2Pos_y <= ulkaPindo1Pos_y + 64)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= ulkaPindo1Pos_x && bullet3Pos_x <= ulkaPindo1Pos_x + 64 && bullet3Pos_y >= ulkaPindo1Pos_y + 63 && bullet3Pos_y <= ulkaPindo1Pos_y + 64)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= ulkaPindo1Pos_x && bullet4Pos_x <= ulkaPindo1Pos_x + 64 && bullet4Pos_y >= ulkaPindo1Pos_y + 32 && bullet4Pos_y <= ulkaPindo1Pos_y + 64)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= ulkaPindo1Pos_x && bullet5Pos_x <= ulkaPindo1Pos_x + 64 && bullet5Pos_y >= ulkaPindo1Pos_y + 32 && bullet5Pos_y <= ulkaPindo1Pos_y + 64)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= ulkaPindo1Pos_x && bullet6Pos_x <= ulkaPindo1Pos_x + 64 && bullet6Pos_y >= ulkaPindo1Pos_y + 32 && bullet6Pos_y <= ulkaPindo1Pos_y + 64)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= ulkaPindo1Pos_x && bullet7Pos_x <= ulkaPindo1Pos_x + 64 && bullet7Pos_y >= ulkaPindo1Pos_y + 32 && bullet7Pos_y <= ulkaPindo1Pos_y + 64)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= ulkaPindo1Pos_x && bullet8Pos_x <= ulkaPindo1Pos_x + 64 && bullet8Pos_y >= ulkaPindo1Pos_y + 32 && bullet8Pos_y <= ulkaPindo1Pos_y + 64)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= ulkaPindo1Pos_x && bullet9Pos_x <= ulkaPindo1Pos_x + 64 && bullet9Pos_y >= ulkaPindo1Pos_y + 32 && bullet9Pos_y <= ulkaPindo1Pos_y + 64)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= ulkaPindo1Pos_x && bullet10Pos_x <= ulkaPindo1Pos_x + 64 && bullet10Pos_y >= ulkaPindo1Pos_y + 32 && bullet10Pos_y <= ulkaPindo1Pos_y + 64)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between ulka-1 and bullet and bullet get vanished

				sprite_ulkaPindo1.setPosition(sf::Vector2f(ulkaPindo1Pos_x, ulkaPindo1Pos_y));
				window.draw(sprite_ulkaPindo1);
				if (ulkaPindo1Pos_x >= spaceshipPos_x && ulkaPindo1Pos_x <= spaceshipPos_x + 150 && ulkaPindo1Pos_y >= spaceshipPos_y && ulkaPindo1Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					//printf("%d\n", life1);
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (ulkaPindo1Pos_x >= spaceshipPos_x && ulkaPindo1Pos_x <= spaceshipPos_x + 150 && ulkaPindo1Pos_y >= spaceshipPos_y && ulkaPindo1Pos_y <= spaceshipPos_y + 150 && ulkaPindo1_Flag == 0)
				{

					life1 = life1 - 10;
					ulkaPindo1_Flag = 1;
				}

				//ulkapindo - 2

				ulkaPindo2Pos_y += .2;

				//start coding of collision between ulka-2 and bullet and bullet get vanished

				if (bullet1Pos_x >= ulkaPindo2Pos_x && bullet1Pos_x <= ulkaPindo2Pos_x + 64 && bullet1Pos_y >= ulkaPindo2Pos_y + 32 && bullet1Pos_y <= ulkaPindo2Pos_y + 64)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= ulkaPindo2Pos_x && bullet2Pos_x <= ulkaPindo2Pos_x + 64 && bullet2Pos_y >= ulkaPindo2Pos_y + 32 && bullet2Pos_y <= ulkaPindo2Pos_y + 64)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= ulkaPindo2Pos_x && bullet3Pos_x <= ulkaPindo2Pos_x + 64 && bullet3Pos_y >= ulkaPindo2Pos_y + 63 && bullet3Pos_y <= ulkaPindo2Pos_y + 64)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= ulkaPindo2Pos_x && bullet4Pos_x <= ulkaPindo2Pos_x + 64 && bullet4Pos_y >= ulkaPindo2Pos_y + 32 && bullet4Pos_y <= ulkaPindo2Pos_y + 64)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= ulkaPindo2Pos_x && bullet5Pos_x <= ulkaPindo2Pos_x + 64 && bullet5Pos_y >= ulkaPindo2Pos_y + 32 && bullet5Pos_y <= ulkaPindo2Pos_y + 64)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= ulkaPindo2Pos_x && bullet6Pos_x <= ulkaPindo2Pos_x + 64 && bullet6Pos_y >= ulkaPindo2Pos_y + 32 && bullet6Pos_y <= ulkaPindo2Pos_y + 64)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= ulkaPindo2Pos_x && bullet7Pos_x <= ulkaPindo2Pos_x + 64 && bullet7Pos_y >= ulkaPindo2Pos_y + 32 && bullet7Pos_y <= ulkaPindo2Pos_y + 64)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= ulkaPindo2Pos_x && bullet8Pos_x <= ulkaPindo2Pos_x + 64 && bullet8Pos_y >= ulkaPindo2Pos_y + 32 && bullet8Pos_y <= ulkaPindo2Pos_y + 64)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= ulkaPindo2Pos_x && bullet9Pos_x <= ulkaPindo2Pos_x + 64 && bullet9Pos_y >= ulkaPindo2Pos_y + 32 && bullet9Pos_y <= ulkaPindo2Pos_y + 64)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= ulkaPindo2Pos_x && bullet10Pos_x <= ulkaPindo2Pos_x + 64 && bullet10Pos_y >= ulkaPindo2Pos_y + 32 && bullet10Pos_y <= ulkaPindo2Pos_y + 64)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between ulka-2 and bullet and bullet get vanished

				sprite_ulkaPindo2.setPosition(sf::Vector2f(ulkaPindo2Pos_x, ulkaPindo2Pos_y));
				window.draw(sprite_ulkaPindo2);

				if (ulkaPindo2Pos_x >= spaceshipPos_x && ulkaPindo2Pos_x <= spaceshipPos_x + 150 && ulkaPindo2Pos_y >= spaceshipPos_y && ulkaPindo2Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					//printf("%d\n", life1);
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (ulkaPindo2Pos_x >= spaceshipPos_x && ulkaPindo2Pos_x <= spaceshipPos_x + 150 && ulkaPindo2Pos_y >= spaceshipPos_y && ulkaPindo2Pos_y <= spaceshipPos_y + 150 && ulkaPindo2_Flag == 0)
				{

					life1 = life1 - 10;
					ulkaPindo2_Flag = 1;
				}

				//ulka - 3

				ulkaPindo3Pos_y += .2;

				//start coding of collision between ulka-3 and bullet and bullet get vanished

				if (bullet1Pos_x >= ulkaPindo3Pos_x && bullet1Pos_x <= ulkaPindo3Pos_x + 64 && bullet1Pos_y >= ulkaPindo3Pos_y + 32 && bullet1Pos_y <= ulkaPindo3Pos_y + 64)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= ulkaPindo3Pos_x && bullet2Pos_x <= ulkaPindo3Pos_x + 64 && bullet2Pos_y >= ulkaPindo3Pos_y + 32 && bullet2Pos_y <= ulkaPindo3Pos_y + 64)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= ulkaPindo3Pos_x && bullet3Pos_x <= ulkaPindo3Pos_x + 64 && bullet3Pos_y >= ulkaPindo3Pos_y + 63 && bullet3Pos_y <= ulkaPindo3Pos_y + 64)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= ulkaPindo3Pos_x && bullet4Pos_x <= ulkaPindo3Pos_x + 64 && bullet4Pos_y >= ulkaPindo3Pos_y + 32 && bullet4Pos_y <= ulkaPindo3Pos_y + 64)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= ulkaPindo3Pos_x && bullet5Pos_x <= ulkaPindo3Pos_x + 64 && bullet5Pos_y >= ulkaPindo3Pos_y + 32 && bullet5Pos_y <= ulkaPindo3Pos_y + 64)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= ulkaPindo3Pos_x && bullet6Pos_x <= ulkaPindo3Pos_x + 64 && bullet6Pos_y >= ulkaPindo3Pos_y + 32 && bullet6Pos_y <= ulkaPindo3Pos_y + 64)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= ulkaPindo3Pos_x && bullet7Pos_x <= ulkaPindo3Pos_x + 64 && bullet7Pos_y >= ulkaPindo3Pos_y + 32 && bullet7Pos_y <= ulkaPindo3Pos_y + 64)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= ulkaPindo3Pos_x && bullet8Pos_x <= ulkaPindo3Pos_x + 64 && bullet8Pos_y >= ulkaPindo3Pos_y + 32 && bullet8Pos_y <= ulkaPindo3Pos_y + 64)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= ulkaPindo3Pos_x && bullet9Pos_x <= ulkaPindo3Pos_x + 64 && bullet9Pos_y >= ulkaPindo3Pos_y + 32 && bullet9Pos_y <= ulkaPindo3Pos_y + 64)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= ulkaPindo3Pos_x && bullet10Pos_x <= ulkaPindo3Pos_x + 64 && bullet10Pos_y >= ulkaPindo3Pos_y + 32 && bullet10Pos_y <= ulkaPindo3Pos_y + 64)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between ulka-3 and bullet and bullet get vanished

				sprite_ulkaPindo3.setPosition(sf::Vector2f(ulkaPindo3Pos_x, ulkaPindo3Pos_y));
				window.draw(sprite_ulkaPindo3);

				if (ulkaPindo3Pos_x >= spaceshipPos_x && ulkaPindo3Pos_x <= spaceshipPos_x + 150 && ulkaPindo3Pos_y >= spaceshipPos_y && ulkaPindo3Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (ulkaPindo3Pos_x >= spaceshipPos_x && ulkaPindo3Pos_x <= spaceshipPos_x + 150 && ulkaPindo3Pos_y >= spaceshipPos_y && ulkaPindo3Pos_y <= spaceshipPos_y + 150 && ulkaPindo3_Flag == 0)
				{

					life1 = life1 - 10;
					ulkaPindo3_Flag = 1;
				}

				//ulka - 4

				ulkaPindo4Pos_y += .2;

				//start coding of collision between ulka-4 and bullet and bullet get vanished

				if (bullet1Pos_x >= ulkaPindo4Pos_x && bullet1Pos_x <= ulkaPindo4Pos_x + 64 && bullet1Pos_y >= ulkaPindo4Pos_y + 32 && bullet1Pos_y <= ulkaPindo4Pos_y + 64)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= ulkaPindo4Pos_x && bullet2Pos_x <= ulkaPindo4Pos_x + 64 && bullet2Pos_y >= ulkaPindo4Pos_y + 32 && bullet2Pos_y <= ulkaPindo4Pos_y + 64)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= ulkaPindo4Pos_x && bullet3Pos_x <= ulkaPindo4Pos_x + 64 && bullet3Pos_y >= ulkaPindo4Pos_y + 63 && bullet3Pos_y <= ulkaPindo4Pos_y + 64)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= ulkaPindo4Pos_x && bullet4Pos_x <= ulkaPindo4Pos_x + 64 && bullet4Pos_y >= ulkaPindo4Pos_y + 32 && bullet4Pos_y <= ulkaPindo4Pos_y + 64)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= ulkaPindo4Pos_x && bullet5Pos_x <= ulkaPindo4Pos_x + 64 && bullet5Pos_y >= ulkaPindo4Pos_y + 32 && bullet5Pos_y <= ulkaPindo4Pos_y + 64)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= ulkaPindo4Pos_x && bullet6Pos_x <= ulkaPindo4Pos_x + 64 && bullet6Pos_y >= ulkaPindo4Pos_y + 32 && bullet6Pos_y <= ulkaPindo4Pos_y + 64)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= ulkaPindo4Pos_x && bullet7Pos_x <= ulkaPindo4Pos_x + 64 && bullet7Pos_y >= ulkaPindo4Pos_y + 32 && bullet7Pos_y <= ulkaPindo4Pos_y + 64)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= ulkaPindo4Pos_x && bullet8Pos_x <= ulkaPindo4Pos_x + 64 && bullet8Pos_y >= ulkaPindo4Pos_y + 32 && bullet8Pos_y <= ulkaPindo4Pos_y + 64)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= ulkaPindo4Pos_x && bullet9Pos_x <= ulkaPindo4Pos_x + 64 && bullet9Pos_y >= ulkaPindo4Pos_y + 32 && bullet9Pos_y <= ulkaPindo4Pos_y + 64)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= ulkaPindo4Pos_x && bullet10Pos_x <= ulkaPindo4Pos_x + 64 && bullet10Pos_y >= ulkaPindo4Pos_y + 32 && bullet10Pos_y <= ulkaPindo4Pos_y + 64)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between ulka-4 and bullet and bullet get vanished

				sprite_ulkaPindo4.setPosition(sf::Vector2f(ulkaPindo4Pos_x, ulkaPindo4Pos_y));
				window.draw(sprite_ulkaPindo4);

				if (ulkaPindo4Pos_x >= spaceshipPos_x && ulkaPindo4Pos_x <= spaceshipPos_x + 150 && ulkaPindo4Pos_y >= spaceshipPos_y && ulkaPindo4Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (ulkaPindo4Pos_x >= spaceshipPos_x && ulkaPindo4Pos_x <= spaceshipPos_x + 150 && ulkaPindo4Pos_y >= spaceshipPos_y && ulkaPindo4Pos_y <= spaceshipPos_y + 150 && ulkaPindo4_Flag == 0)
				{

					life1 = life1 - 10;
					ulkaPindo4_Flag = 1;
				}

				//ulka - 5

				ulkaPindo5Pos_y += .2;

				//start coding of collision between ulka-5 and bullet and bullet get vanished

				if (bullet1Pos_x >= ulkaPindo5Pos_x && bullet1Pos_x <= ulkaPindo5Pos_x + 64 && bullet1Pos_y >= ulkaPindo5Pos_y + 32 && bullet1Pos_y <= ulkaPindo5Pos_y + 64)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= ulkaPindo5Pos_x && bullet2Pos_x <= ulkaPindo5Pos_x + 64 && bullet2Pos_y >= ulkaPindo5Pos_y + 32 && bullet2Pos_y <= ulkaPindo5Pos_y + 64)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= ulkaPindo5Pos_x && bullet3Pos_x <= ulkaPindo5Pos_x + 64 && bullet3Pos_y >= ulkaPindo5Pos_y + 63 && bullet3Pos_y <= ulkaPindo5Pos_y + 64)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= ulkaPindo5Pos_x && bullet4Pos_x <= ulkaPindo5Pos_x + 64 && bullet4Pos_y >= ulkaPindo5Pos_y + 32 && bullet4Pos_y <= ulkaPindo5Pos_y + 64)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= ulkaPindo5Pos_x && bullet5Pos_x <= ulkaPindo5Pos_x + 64 && bullet5Pos_y >= ulkaPindo5Pos_y + 32 && bullet5Pos_y <= ulkaPindo5Pos_y + 64)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= ulkaPindo5Pos_x && bullet6Pos_x <= ulkaPindo5Pos_x + 64 && bullet6Pos_y >= ulkaPindo5Pos_y + 32 && bullet6Pos_y <= ulkaPindo5Pos_y + 64)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= ulkaPindo5Pos_x && bullet7Pos_x <= ulkaPindo5Pos_x + 64 && bullet7Pos_y >= ulkaPindo5Pos_y + 32 && bullet7Pos_y <= ulkaPindo5Pos_y + 64)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= ulkaPindo5Pos_x && bullet8Pos_x <= ulkaPindo5Pos_x + 64 && bullet8Pos_y >= ulkaPindo5Pos_y + 32 && bullet8Pos_y <= ulkaPindo5Pos_y + 64)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= ulkaPindo5Pos_x && bullet9Pos_x <= ulkaPindo5Pos_x + 64 && bullet9Pos_y >= ulkaPindo5Pos_y + 32 && bullet9Pos_y <= ulkaPindo5Pos_y + 64)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= ulkaPindo5Pos_x && bullet10Pos_x <= ulkaPindo5Pos_x + 64 && bullet10Pos_y >= ulkaPindo5Pos_y + 32 && bullet10Pos_y <= ulkaPindo5Pos_y + 64)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between ulka-5 and bullet and bullet get vanished

				sprite_ulkaPindo5.setPosition(sf::Vector2f(ulkaPindo5Pos_x, ulkaPindo5Pos_y));
				window.draw(sprite_ulkaPindo5);

				if (ulkaPindo5Pos_x >= spaceshipPos_x && ulkaPindo5Pos_x <= spaceshipPos_x + 150 && ulkaPindo5Pos_y >= spaceshipPos_y && ulkaPindo5Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (ulkaPindo5Pos_x >= spaceshipPos_x && ulkaPindo5Pos_x <= spaceshipPos_x + 150 && ulkaPindo5Pos_y >= spaceshipPos_y && ulkaPindo5Pos_y <= spaceshipPos_y + 150 && ulkaPindo5_Flag == 0)
				{
					life1 -= 10;
					ulkaPindo5_Flag = 1;
				}

			}

			//enemy step 2

			if (smallenemy2_clock.getElapsedTime() > ulkapindo_time_stage2 && smallenemy2_clock.getElapsedTime() < smallenemy2_time_stage2)
			{
				
				if (smallEnemy2_1Pos_x < 30)
				{
					smallEnemy2_1Pos_x += .5;

				}
				else if (smallEnemy2_1Pos_y > 30)
				{
					smallEnemy2_1Pos_y -= .5;
				}

				//smallenemyship-2_1 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2_1Pos_x && bullet1Pos_x <= smallEnemy2_1Pos_x + 85 && bullet1Pos_y == smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2_1Pos_x && bullet2Pos_x <= smallEnemy2_1Pos_x + 85 && bullet2Pos_y == smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy2_1Pos_x && bullet3Pos_x <= smallEnemy2_1Pos_x + 85 && bullet3Pos_y == smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2_1Pos_x && bullet4Pos_x <= smallEnemy2_1Pos_x + 85 && bullet4Pos_y == smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2_1Pos_x && bullet5Pos_x <= smallEnemy2_1Pos_x + 85 && bullet5Pos_y == smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2_1Pos_x && bullet6Pos_x <= smallEnemy2_1Pos_x + 85 && bullet6Pos_y == smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2_1Pos_x && bullet7Pos_x <= smallEnemy2_1Pos_x + 85 && bullet7Pos_y == smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2_1Pos_x && bullet8Pos_x <= smallEnemy2_1Pos_x + 85 && bullet8Pos_y == smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy2_1Pos_x && bullet9Pos_x <= smallEnemy2_1Pos_x + 85 && bullet9Pos_y == smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy2_1Pos_x && bullet10Pos_x <= smallEnemy2_1Pos_x + 85 && bullet10Pos_y == smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					point1 += 10;
				}
				//smallenemy-2_1 vanish hobar code ekhane sesh

				sprite_smallEnemy2_1.setPosition(sf::Vector2f(smallEnemy2_1Pos_x, smallEnemy2_1Pos_y));
				window.draw(sprite_smallEnemy2_1);

				// smallenemy1 citeria-2 bullet no-1 er code

				if (smallEnemy2_1Pos_x == 30 && smallEnemy2_1Pos_y == 30 && smallEnemy2Bullet1Pos_x < 1300 && smallEnemy2Bullet1Pos_y < 732)
				{
					smallEnemy2Bullet1Pos_y += .5;

					if (smallEnemy2Bullet1Pos_y >= spaceshipPos_y && smallEnemy2Bullet1Pos_y <= spaceshipPos_y + 20 && smallEnemy2Bullet1Pos_x >= spaceshipPos_x + 20 && smallEnemy2Bullet1Pos_x <= spaceshipPos_x + 140)
					{
						smallEnemy2Bullet1Pos_y = 731;
						life1 = life1 - 10;
						sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
						window.draw(sprite_spaceship1Effect);
					}
				}

				sprite_smallEnemy2Bullet1.setPosition(sf::Vector2f(smallEnemy2Bullet1Pos_x, smallEnemy2Bullet1Pos_y));
				if (smallEnemy2_1Pos_x == 30 && smallEnemy2_1Pos_y == 30) window.draw(sprite_smallEnemy2Bullet1);

				//smallenemy2 citeria-2 er code
				if (smallEnemy2_2Pos_x < 304)
				{
					smallEnemy2_2Pos_x += .5;

				}
				else if (smallEnemy2_2Pos_y > 95)
				{
					smallEnemy2_2Pos_y -= .5;
				}

				//smallenemyship-2_2 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2_2Pos_x && bullet1Pos_x <= smallEnemy2_2Pos_x + 85 && bullet1Pos_y == smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2_2Pos_x && bullet2Pos_x <= smallEnemy2_2Pos_x + 85 && bullet2Pos_y == smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy2_2Pos_x && bullet3Pos_x <= smallEnemy2_2Pos_x + 85 && bullet3Pos_y == smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2_2Pos_x && bullet4Pos_x <= smallEnemy2_2Pos_x + 85 && bullet4Pos_y == smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2_2Pos_x && bullet5Pos_x <= smallEnemy2_2Pos_x + 85 && bullet5Pos_y == smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2_2Pos_x && bullet6Pos_x <= smallEnemy2_2Pos_x + 85 && bullet6Pos_y == smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2_2Pos_x && bullet7Pos_x <= smallEnemy2_2Pos_x + 85 && bullet7Pos_y == smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2_2Pos_x && bullet8Pos_x <= smallEnemy2_2Pos_x + 85 && bullet8Pos_y == smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy2_2Pos_x && bullet9Pos_x <= smallEnemy2_2Pos_x + 85 && bullet9Pos_y == smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy2_2Pos_x && bullet10Pos_x <= smallEnemy2_2Pos_x + 85 && bullet10Pos_y == smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					point1 += 10;
				}
				//smallenemy-2_2 vanish hobar code ekhane sesh

				sprite_smallEnemy2_2.setPosition(sf::Vector2f(smallEnemy2_2Pos_x, smallEnemy2_2Pos_y));
				window.draw(sprite_smallEnemy2_2);

				// smallenemy2 citeria-2 bullet no-2 er code

				//printf("%f %f\n", smallEnemy2_2Pos_x, smallEnemy2_2Pos_y);
				if (smallEnemy2_2Pos_x == 304 && smallEnemy2_2Pos_y == 95 && smallEnemy2Bullet2Pos_x < 1300 && smallEnemy2Bullet2Pos_y < 732)
				{
					smallEnemy2Bullet2Pos_y += .5;
					//printf("%f\n", smallEnemy2Bullet2Pos_y);

					if (smallEnemy2Bullet2Pos_y >= spaceshipPos_y && smallEnemy2Bullet2Pos_y <= spaceshipPos_y + 20 && smallEnemy2Bullet2Pos_x >= spaceshipPos_x + 20 && smallEnemy2Bullet2Pos_x <= spaceshipPos_x + 140)
					{
						smallEnemy2Bullet2Pos_y = 731;
						life1 = life1 - 10;
						sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
						window.draw(sprite_spaceship1Effect);
					}
				}

				sprite_smallEnemy2Bullet2.setPosition(sf::Vector2f(smallEnemy2Bullet2Pos_x, smallEnemy2Bullet2Pos_y));
				if (smallEnemy2_2Pos_x == 304 && smallEnemy2_2Pos_y == 95) window.draw(sprite_smallEnemy2Bullet2);

				//smallenemy 3 er code

				if (smallEnemy2_3Pos_x > 1190)
				{
					smallEnemy2_3Pos_x -= .5;

				}
				else if (smallEnemy2_3Pos_y > 30)
				{
					smallEnemy2_3Pos_y -= .5;
				}

				//smallenemyship-2_3 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2_3Pos_x && bullet1Pos_x <= smallEnemy2_3Pos_x + 85 && bullet1Pos_y == smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2_3Pos_x && bullet2Pos_x <= smallEnemy2_3Pos_x + 85 && bullet2Pos_y == smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy2_3Pos_x && bullet3Pos_x <= smallEnemy2_3Pos_x + 85 && bullet3Pos_y == smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2_3Pos_x && bullet4Pos_x <= smallEnemy2_3Pos_x + 85 && bullet4Pos_y == smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2_3Pos_x && bullet5Pos_x <= smallEnemy2_3Pos_x + 85 && bullet5Pos_y == smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2_3Pos_x && bullet6Pos_x <= smallEnemy2_3Pos_x + 85 && bullet6Pos_y == smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2_3Pos_x && bullet7Pos_x <= smallEnemy2_3Pos_x + 85 && bullet7Pos_y == smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2_3Pos_x && bullet8Pos_x <= smallEnemy2_3Pos_x + 85 && bullet8Pos_y == smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy2_3Pos_x && bullet9Pos_x <= smallEnemy2_3Pos_x + 85 && bullet9Pos_y == smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy2_3Pos_x && bullet10Pos_x <= smallEnemy2_3Pos_x + 85 && bullet10Pos_y == smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				//smallenemy-2_3 vanish hobar code ekhane sesh

				sprite_smallEnemy2_3.setPosition(sf::Vector2f(smallEnemy2_3Pos_x, smallEnemy2_3Pos_y));
				window.draw(sprite_smallEnemy2_3);
				// smallenemy3 citeria-2 bullet no-3 er code

				//printf("%f %f\n", smallEnemy2_3Pos_x, smallEnemy2_3Pos_y);
				if (smallEnemy2_3Pos_x == 1190 && smallEnemy2_3Pos_y == 30 && smallEnemy2Bullet3Pos_x < 1300 && smallEnemy2Bullet3Pos_y < 732)
				{
					smallEnemy2Bullet3Pos_y += .5;
					//printf("%f\n", smallEnemy2Bullet2Pos_y);

					if (smallEnemy2Bullet3Pos_y >= spaceshipPos_y && smallEnemy2Bullet3Pos_y <= spaceshipPos_y + 20 && smallEnemy2Bullet3Pos_x >= spaceshipPos_x + 20 && smallEnemy2Bullet3Pos_x <= spaceshipPos_x + 140)
					{
						smallEnemy2Bullet3Pos_y = 731;
						life1 = life1 - 10;
						sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
						window.draw(sprite_spaceship1Effect);
					}
				}

				sprite_smallEnemy2Bullet3.setPosition(sf::Vector2f(smallEnemy2Bullet3Pos_x, smallEnemy2Bullet3Pos_y));
				if (smallEnemy2_3Pos_x == 1190 && smallEnemy2_3Pos_y == 30) window.draw(sprite_smallEnemy2Bullet3);


				//smallenemy 4 er code

				if (smallEnemy2_4Pos_x > 980)
				{
					smallEnemy2_4Pos_x -= .5;

				}
				else if (smallEnemy2_4Pos_y > 95)
				{
					smallEnemy2_4Pos_y -= .5;
				}
				sprite_smallEnemy2_4.setPosition(sf::Vector2f(smallEnemy2_4Pos_x, smallEnemy2_4Pos_y));
				window.draw(sprite_smallEnemy2_4);

				//smallenemyship-2_4 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2_4Pos_x && bullet1Pos_x <= smallEnemy2_4Pos_x + 85 && bullet1Pos_y == smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2_4Pos_x && bullet2Pos_x <= smallEnemy2_4Pos_x + 85 && bullet2Pos_y == smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy2_4Pos_x && bullet3Pos_x <= smallEnemy2_4Pos_x + 85 && bullet3Pos_y == smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2_4Pos_x && bullet4Pos_x <= smallEnemy2_4Pos_x + 85 && bullet4Pos_y == smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2_4Pos_x && bullet5Pos_x <= smallEnemy2_4Pos_x + 85 && bullet5Pos_y == smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2_4Pos_x && bullet6Pos_x <= smallEnemy2_4Pos_x + 85 && bullet6Pos_y == smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2_4Pos_x && bullet7Pos_x <= smallEnemy2_4Pos_x + 85 && bullet7Pos_y == smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2_4Pos_x && bullet8Pos_x <= smallEnemy2_4Pos_x + 85 && bullet8Pos_y == smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet9Pos_x >= smallEnemy2_4Pos_x && bullet9Pos_x <= smallEnemy2_4Pos_x + 85 && bullet9Pos_y == smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet10Pos_x >= smallEnemy2_4Pos_x && bullet10Pos_x <= smallEnemy2_4Pos_x + 85 && bullet10Pos_y == smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				//smallenemy-2_4 vanish hobar code ekhane sesh


				// smallenemy4 citeria-2 bullet no-4 er code

				//printf("%f %f\n", smallEnemy2_3Pos_x, smallEnemy2_3Pos_y);
				if (smallEnemy2_4Pos_x == 980 && smallEnemy2_4Pos_y == 95 && smallEnemy2Bullet4Pos_x < 1300 && smallEnemy2Bullet4Pos_y < 732)
				{
					smallEnemy2Bullet4Pos_y += .5;

					if (smallEnemy2Bullet4Pos_y >= spaceshipPos_y && smallEnemy2Bullet4Pos_y <= spaceshipPos_y + 20 && smallEnemy2Bullet4Pos_x >= spaceshipPos_x + 20 && smallEnemy2Bullet4Pos_x <= spaceshipPos_x + 140)
					{
						smallEnemy2Bullet4Pos_y = 731;
						life1 = life1 - 10;
						sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
						window.draw(sprite_spaceship1Effect);
					}
				}

				sprite_smallEnemy2Bullet4.setPosition(sf::Vector2f(smallEnemy2Bullet4Pos_x, smallEnemy2Bullet4Pos_y));
				if (smallEnemy2_4Pos_x == 980 && smallEnemy2_4Pos_y == 95) window.draw(sprite_smallEnemy2Bullet4);


				//smallenemy 5 er code

				if (smallEnemy2_5Pos_y < 30)
				{
					smallEnemy2_5Pos_y += .5;
				}

				//smallenemyship-2_5 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2_5Pos_x && bullet1Pos_x <= smallEnemy2_5Pos_x + 85 && bullet1Pos_y == smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2_5Pos_x && bullet2Pos_x <= smallEnemy2_5Pos_x + 85 && bullet2Pos_y == smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy2_5Pos_x && bullet3Pos_x <= smallEnemy2_5Pos_x + 85 && bullet3Pos_y == smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2_5Pos_x && bullet4Pos_x <= smallEnemy2_5Pos_x + 85 && bullet4Pos_y == smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2_5Pos_x && bullet5Pos_x <= smallEnemy2_5Pos_x + 85 && bullet5Pos_y == smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2_5Pos_x && bullet6Pos_x <= smallEnemy2_5Pos_x + 85 && bullet6Pos_y == smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2_5Pos_x && bullet7Pos_x <= smallEnemy2_5Pos_x + 85 && bullet7Pos_y == smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2_5Pos_x && bullet8Pos_x <= smallEnemy2_5Pos_x + 85 && bullet8Pos_y == smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet9Pos_x >= smallEnemy2_5Pos_x && bullet9Pos_x <= smallEnemy2_5Pos_x + 85 && bullet9Pos_y == smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet10Pos_x >= smallEnemy2_5Pos_x && bullet10Pos_x <= smallEnemy2_5Pos_x + 85 && bullet10Pos_y == smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;

				}
				//smallenemy-2_5 vanish hobar code ekhane sesh

				sprite_smallEnemy2_5.setPosition(sf::Vector2f(smallEnemy2_5Pos_x, smallEnemy2_5Pos_y));
				window.draw(sprite_smallEnemy2_5);

				// smallenemy5 citeria-2 bullet no-5 er code

				//printf("%f %f\n", smallEnemy2_3Pos_x, smallEnemy2_3Pos_y);
				if (smallEnemy2_5Pos_y == 30 && smallEnemy2Bullet5Pos_x < 1300 && smallEnemy2Bullet5Pos_y < 732)
				{
					smallEnemy2Bullet5Pos_y += .5;
					//printf("%f\n", smallEnemy2Bullet2Pos_y);

					if (smallEnemy2Bullet5Pos_y >= spaceshipPos_y && smallEnemy2Bullet5Pos_y <= spaceshipPos_y + 20 && smallEnemy2Bullet5Pos_x >= spaceshipPos_x + 20 && smallEnemy2Bullet5Pos_x <= spaceshipPos_x + 140)
					{
						smallEnemy2Bullet5Pos_y = 731;
						life1 = life1 - 10;
						sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
						window.draw(sprite_spaceship1Effect);
					}
				}

				sprite_smallEnemy2Bullet5.setPosition(sf::Vector2f(smallEnemy2Bullet5Pos_x, smallEnemy2Bullet5Pos_y));
				if (smallEnemy2_5Pos_y == 30) window.draw(sprite_smallEnemy2Bullet5);

			}
			//smallenemy citeria-2 screen theke remove hobaar code
			else if (smallenemy2_clock.getElapsedTime() > smallenemy2_time_stage2 && smallenemy2_clock.getElapsedTime()< rocketLauncher_time_stage1)
			{
				//smallEnemy2_1Pos_x -= .25;
				smallEnemy2_1Pos_y += .25;

				//smallenemyship-2_1 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2_1Pos_x && bullet1Pos_x <= smallEnemy2_1Pos_x + 85 && bullet1Pos_y >= smallEnemy2_1Pos_y + 80 && bullet1Pos_y <= smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					bullet1Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2_1Pos_x && bullet2Pos_x <= smallEnemy2_1Pos_x + 85 && bullet2Pos_y >= smallEnemy2_1Pos_y + 80 && bullet2Pos_y <= smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					bullet2Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy2_1Pos_x && bullet3Pos_x <= smallEnemy2_1Pos_x + 85 && bullet3Pos_y >= smallEnemy2_1Pos_y + 80 && bullet3Pos_y <= smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					bullet3Pos_x = 1200;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2_1Pos_x && bullet4Pos_x <= smallEnemy2_1Pos_x + 85 && bullet4Pos_y >= smallEnemy2_1Pos_y + 80 && bullet4Pos_y <= smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					bullet4Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2_1Pos_x && bullet5Pos_x <= smallEnemy2_1Pos_x + 85 && bullet5Pos_y >= smallEnemy2_1Pos_y + 80 && bullet5Pos_y <= smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					bullet5Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2_1Pos_x && bullet6Pos_x <= smallEnemy2_1Pos_x + 85 && bullet6Pos_y >= smallEnemy2_1Pos_y + 80 && bullet6Pos_y <= smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					bullet6Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2_1Pos_x && bullet7Pos_x <= smallEnemy2_1Pos_x + 85 && bullet7Pos_y >= smallEnemy2_1Pos_y + 80 && bullet7Pos_y <= smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					bullet7Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2_1Pos_x && bullet8Pos_x <= smallEnemy2_1Pos_x + 85 && bullet8Pos_y >= smallEnemy2_1Pos_y + 80 && bullet8Pos_y <= smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					bullet8Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy2_1Pos_x && bullet9Pos_x <= smallEnemy2_1Pos_x + 85 && bullet9Pos_y >= smallEnemy2_1Pos_y + 80 && bullet9Pos_y <= smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					bullet9Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy2_1Pos_x && bullet10Pos_x <= smallEnemy2_1Pos_x + 85 && bullet10Pos_y >= smallEnemy2_1Pos_y + 80 && bullet10Pos_y <= smallEnemy2_1Pos_y + 85)
				{
					smallEnemy2_1Pos_x = -11200;
					bullet10Pos_x = 1200;
					point1 += 10;
				}
				//smallenemy-2_1 vanish hobar code ekhane sesh

				sprite_smallEnemy2_1.setPosition(sf::Vector2f(smallEnemy2_1Pos_x, smallEnemy2_1Pos_y));
				window.draw(sprite_smallEnemy2_1);

				if (smallEnemy2_1Pos_x >= spaceshipPos_x && smallEnemy2_1Pos_x <= spaceshipPos_x + 150 && smallEnemy2_1Pos_y >= spaceshipPos_y && smallEnemy2_1Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (smallEnemy2_1Pos_x >= spaceshipPos_x && smallEnemy2_1Pos_x <= spaceshipPos_x + 150 && smallEnemy2_1Pos_y >= spaceshipPos_y && smallEnemy2_1Pos_y <= spaceshipPos_y + 150 && smallEnemy2_1_Flag == 0)
				{
					life1 -= 10;
					smallEnemy2_1_Flag = 1;
				}

				//mallEnemy2_2Pos_x -= .25;
				smallEnemy2_2Pos_y += .25;

				//smallenemyship-2_2 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2_2Pos_x && bullet1Pos_x <= smallEnemy2_2Pos_x + 85 && bullet1Pos_y >= smallEnemy2_2Pos_y + 80 && bullet1Pos_y <= smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					bullet1Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2_2Pos_x && bullet2Pos_x <= smallEnemy2_2Pos_x + 85 && bullet2Pos_y >= smallEnemy2_2Pos_y + 80 && bullet2Pos_y <= smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					bullet2Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy2_2Pos_x && bullet3Pos_x <= smallEnemy2_2Pos_x + 85 && bullet3Pos_y >= smallEnemy2_2Pos_y + 80 && bullet3Pos_y <= smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					bullet3Pos_x = 1200;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2_2Pos_x && bullet4Pos_x <= smallEnemy2_2Pos_x + 85 && bullet4Pos_y >= smallEnemy2_2Pos_y + 80 && bullet4Pos_y <= smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					bullet4Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2_2Pos_x && bullet5Pos_x <= smallEnemy2_2Pos_x + 85 && bullet5Pos_y >= smallEnemy2_2Pos_y + 80 && bullet5Pos_y <= smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					bullet5Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2_2Pos_x && bullet6Pos_x <= smallEnemy2_2Pos_x + 85 && bullet6Pos_y >= smallEnemy2_2Pos_y + 80 && bullet6Pos_y <= smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					bullet6Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2_2Pos_x && bullet7Pos_x <= smallEnemy2_2Pos_x + 85 && bullet7Pos_y >= smallEnemy2_2Pos_y + 80 && bullet7Pos_y <= smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					bullet7Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2_2Pos_x && bullet8Pos_x <= smallEnemy2_2Pos_x + 85 && bullet8Pos_y >= smallEnemy2_2Pos_y + 80 && bullet8Pos_y <= smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					bullet8Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy2_2Pos_x && bullet9Pos_x <= smallEnemy2_2Pos_x + 85 && bullet9Pos_y >= smallEnemy2_2Pos_y + 80 && bullet9Pos_y <= smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					bullet9Pos_x = 1200;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy2_2Pos_x && bullet10Pos_x <= smallEnemy2_2Pos_x + 85 && bullet10Pos_y >= smallEnemy2_2Pos_y + 80 && bullet10Pos_y <= smallEnemy2_2Pos_y + 85)
				{
					smallEnemy2_2Pos_x = -11200;
					bullet10Pos_x = 1200;
					point1 += 10;
				}
				//smallenemy-2_2 vanish hobar code ekhane sesh

				sprite_smallEnemy2_2.setPosition(sf::Vector2f(smallEnemy2_2Pos_x, smallEnemy2_2Pos_y));
				window.draw(sprite_smallEnemy2_2);

				if (smallEnemy2_2Pos_x >= spaceshipPos_x && smallEnemy2_2Pos_x <= spaceshipPos_x + 150 && smallEnemy2_2Pos_y >= spaceshipPos_y && smallEnemy2_2Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}

				if (smallEnemy2_2Pos_x >= spaceshipPos_x && smallEnemy2_2Pos_x <= spaceshipPos_x + 150 && smallEnemy2_2Pos_y >= spaceshipPos_y && smallEnemy2_2Pos_y <= spaceshipPos_y + 150 && smallEnemy2_2_Flag == 0)
				{

					life1 -= 10;
					smallEnemy2_2_Flag = 1;
				}
				//smallEnemy2_3Pos_x += .25;
				smallEnemy2_3Pos_y += .25;

				//smallenemyship-2_3 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2_3Pos_x && bullet1Pos_x <= smallEnemy2_3Pos_x + 85 && bullet1Pos_y >= smallEnemy2_3Pos_y + 80 && bullet1Pos_y <= smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2_3Pos_x && bullet2Pos_x <= smallEnemy2_3Pos_x + 85 && bullet2Pos_y >= smallEnemy2_3Pos_y + 80 && bullet2Pos_y <= smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy2_3Pos_x && bullet3Pos_x <= smallEnemy2_3Pos_x + 85 && bullet3Pos_y >= smallEnemy2_3Pos_y + 80 && bullet3Pos_y <= smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2_3Pos_x && bullet4Pos_x <= smallEnemy2_3Pos_x + 85 && bullet4Pos_y >= smallEnemy2_3Pos_y + 80 && bullet4Pos_y <= smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2_3Pos_x && bullet5Pos_x <= smallEnemy2_3Pos_x + 85 && bullet5Pos_y >= smallEnemy2_3Pos_y + 80 && bullet5Pos_y <= smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2_3Pos_x && bullet6Pos_x <= smallEnemy2_3Pos_x + 85 && bullet6Pos_y >= smallEnemy2_3Pos_y + 80 && bullet6Pos_y <= smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2_3Pos_x && bullet7Pos_x <= smallEnemy2_3Pos_x + 85 && bullet7Pos_y >= smallEnemy2_3Pos_y + 80 && bullet7Pos_y <= smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2_3Pos_x && bullet8Pos_x <= smallEnemy2_3Pos_x + 85 && bullet8Pos_y >= smallEnemy2_3Pos_y + 80 && bullet8Pos_y <= smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy2_3Pos_x && bullet9Pos_x <= smallEnemy2_3Pos_x + 85 && bullet9Pos_y >= smallEnemy2_3Pos_y + 80 && bullet9Pos_y <= smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy2_3Pos_x && bullet10Pos_x <= smallEnemy2_3Pos_x + 85 && bullet10Pos_y >= smallEnemy2_3Pos_y + 80 && bullet10Pos_y <= smallEnemy2_3Pos_y + 85)
				{
					smallEnemy2_3Pos_x = -11200;
					point1 += 10;
				}
				//smallenemy-2_3 vanish hobar code ekhane sesh

				sprite_smallEnemy2_3.setPosition(sf::Vector2f(smallEnemy2_3Pos_x, smallEnemy2_3Pos_y));
				window.draw(sprite_smallEnemy2_3);

				if (smallEnemy2_3Pos_x >= spaceshipPos_x && smallEnemy2_3Pos_x <= spaceshipPos_x + 150 && smallEnemy2_3Pos_y >= spaceshipPos_y && smallEnemy2_3Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (smallEnemy2_3Pos_x >= spaceshipPos_x && smallEnemy2_3Pos_x <= spaceshipPos_x + 150 && smallEnemy2_3Pos_y >= spaceshipPos_y && smallEnemy2_3Pos_y <= spaceshipPos_y + 150 && smallEnemy2_3_Flag == 0)
				{

					life1 = life1 - 10;
					smallEnemy2_3_Flag = 1;
				}
				//smallEnemy2_4Pos_x += .25;
				smallEnemy2_4Pos_y += .250;

				//smallenemyship-2_4 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2_4Pos_x && bullet1Pos_x <= smallEnemy2_4Pos_x + 85 && bullet1Pos_y >= smallEnemy2_4Pos_y + 80 && bullet1Pos_y <= smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2_4Pos_x && bullet2Pos_x <= smallEnemy2_4Pos_x + 85 && bullet2Pos_y >= smallEnemy2_4Pos_y + 80 && bullet2Pos_y <= smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy2_4Pos_x && bullet3Pos_x <= smallEnemy2_4Pos_x + 85 && bullet3Pos_y >= smallEnemy2_4Pos_y + 80 && bullet3Pos_y <= smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2_4Pos_x && bullet4Pos_x <= smallEnemy2_4Pos_x + 85 && bullet4Pos_y >= smallEnemy2_4Pos_y + 80 && bullet4Pos_y <= smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2_4Pos_x && bullet5Pos_x <= smallEnemy2_4Pos_x + 85 && bullet5Pos_y >= smallEnemy2_4Pos_y + 80 && bullet5Pos_y <= smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2_4Pos_x && bullet6Pos_x <= smallEnemy2_4Pos_x + 85 && bullet6Pos_y >= smallEnemy2_4Pos_y + 80 && bullet6Pos_y <= smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2_4Pos_x && bullet7Pos_x <= smallEnemy2_4Pos_x + 85 && bullet7Pos_y >= smallEnemy2_4Pos_y + 80 && bullet7Pos_y <= smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2_4Pos_x && bullet8Pos_x <= smallEnemy2_4Pos_x + 85 && bullet8Pos_y >= smallEnemy2_4Pos_y + 80 && bullet8Pos_y <= smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet9Pos_x >= smallEnemy2_4Pos_x && bullet9Pos_x <= smallEnemy2_4Pos_x + 85 && bullet9Pos_y >= smallEnemy2_4Pos_y + 80 && bullet9Pos_y <= smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy2_4Pos_x && bullet10Pos_x <= smallEnemy2_4Pos_x + 85 && bullet10Pos_y >= smallEnemy2_4Pos_y + 80 && bullet10Pos_y <= smallEnemy2_4Pos_y + 85)
				{
					smallEnemy2_4Pos_x = -11200;
					point1 += 10;
				}
				//smallenemy-2_4 vanish hobar code ekhane sesh

				sprite_smallEnemy2_4.setPosition(sf::Vector2f(smallEnemy2_4Pos_x, smallEnemy2_4Pos_y));
				window.draw(sprite_smallEnemy2_4);

				if (smallEnemy2_4Pos_x >= spaceshipPos_x && smallEnemy2_4Pos_x <= spaceshipPos_x + 150 && smallEnemy2_4Pos_y >= spaceshipPos_y && smallEnemy2_4Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (smallEnemy2_4Pos_x >= spaceshipPos_x && smallEnemy2_4Pos_x <= spaceshipPos_x + 150 && smallEnemy2_4Pos_y >= spaceshipPos_y && smallEnemy2_4Pos_y <= spaceshipPos_y + 150 && smallEnemy2_4_Flag == 0)
				{

					life1 = life1 - 10;
					smallEnemy2_4_Flag = 1;
				}
				smallEnemy2_5Pos_y += .25;

				//smallenemyship-2_5 vanish hobar code

				//printf("%f\n", bullet1Pos_x);
				if (bullet1Pos_x >= smallEnemy2_5Pos_x && bullet1Pos_x <= smallEnemy2_5Pos_x + 85 && bullet1Pos_y >= smallEnemy2_5Pos_y + 80 && bullet1Pos_y <= smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet2Pos_x >= smallEnemy2_5Pos_x && bullet2Pos_x <= smallEnemy2_5Pos_x + 85 && bullet2Pos_y >= smallEnemy2_5Pos_y + 80 && bullet2Pos_y <= smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet3Pos_x >= smallEnemy2_5Pos_x && bullet3Pos_x <= smallEnemy2_5Pos_x + 85 && bullet3Pos_y >= smallEnemy2_5Pos_y + 80 && bullet3Pos_y <= smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet4Pos_x >= smallEnemy2_5Pos_x && bullet4Pos_x <= smallEnemy2_5Pos_x + 85 && bullet4Pos_y >= smallEnemy2_5Pos_y + 80 && bullet4Pos_y <= smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet5Pos_x >= smallEnemy2_5Pos_x && bullet5Pos_x <= smallEnemy2_5Pos_x + 85 && bullet5Pos_y >= smallEnemy2_5Pos_y + 80 && bullet5Pos_y <= smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet6Pos_x >= smallEnemy2_5Pos_x && bullet6Pos_x <= smallEnemy2_5Pos_x + 85 && bullet6Pos_y >= smallEnemy2_5Pos_y + 80 && bullet6Pos_y <= smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet7Pos_x >= smallEnemy2_5Pos_x && bullet7Pos_x <= smallEnemy2_5Pos_x + 85 && bullet7Pos_y >= smallEnemy2_5Pos_y + 80 && bullet7Pos_y <= smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet8Pos_x >= smallEnemy2_5Pos_x && bullet8Pos_x <= smallEnemy2_5Pos_x + 85 && bullet8Pos_y >= smallEnemy2_5Pos_y + 80 && bullet8Pos_y <= smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;

				}
				else if (bullet9Pos_x >= smallEnemy2_5Pos_x && bullet9Pos_x <= smallEnemy2_5Pos_x + 85 && bullet9Pos_y >= smallEnemy2_5Pos_y + 80 && bullet9Pos_y <= smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				else if (bullet10Pos_x >= smallEnemy2_5Pos_x && bullet10Pos_x <= smallEnemy2_5Pos_x + 85 && bullet10Pos_y >= smallEnemy2_5Pos_y + 80 && bullet10Pos_y <= smallEnemy2_5Pos_y + 85)
				{
					smallEnemy2_5Pos_x = -11200;
					point1 += 10;
				}
				//smallenemy-2_5 vanish hobar code ekhane sesh

				sprite_smallEnemy2_5.setPosition(sf::Vector2f(smallEnemy2_5Pos_x, smallEnemy2_5Pos_y));
				window.draw(sprite_smallEnemy2_5);

				if (smallEnemy2_5Pos_x >= spaceshipPos_x && smallEnemy2_5Pos_x <= spaceshipPos_x + 150 && smallEnemy2_5Pos_y >= spaceshipPos_y && smallEnemy2_5Pos_y <= spaceshipPos_y + 150)
				{

					//life1 = life1 - 10;
					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (smallEnemy2_5Pos_x >= spaceshipPos_x && smallEnemy2_5Pos_x <= spaceshipPos_x + 150 && smallEnemy2_5Pos_y >= spaceshipPos_y && smallEnemy2_5Pos_y <= spaceshipPos_y + 150 && smallEnemy2_5_Flag == 0)
				{

					life1 = life1 - 10;
					smallEnemy2_5_Flag = 1;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////rocketlauncher/////////////////////////
			//rocketlaucher er code
			if (rocketLauncher_clock.getElapsedTime() > rocketLauncher_time_stage1 && rocketLauncher_clock.getElapsedTime() < rocketLauncher_time_stage2)
			{
				//rocketlauncher - 1
				rocketlauncher1Pos_y += .5;

				//start coding of collision between rocketlauncher-1 and bullet and bullet get vanished

				if (bullet1Pos_x >= rocketlauncher1Pos_x && bullet1Pos_x <= rocketlauncher1Pos_x + 95 && bullet1Pos_y >= rocketlauncher1Pos_y + 140 && bullet1Pos_y <= rocketlauncher1Pos_y + 151)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= rocketlauncher1Pos_x && bullet2Pos_x <= rocketlauncher1Pos_x + 95 && bullet2Pos_y >= rocketlauncher1Pos_y + 140 && bullet2Pos_y <= rocketlauncher1Pos_y + 151)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= rocketlauncher1Pos_x && bullet3Pos_x <= rocketlauncher1Pos_x + 95 && bullet3Pos_y >= rocketlauncher1Pos_y + 140 && bullet3Pos_y <= rocketlauncher1Pos_y + 151)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= rocketlauncher1Pos_x && bullet4Pos_x <= rocketlauncher1Pos_x + 95 && bullet4Pos_y >= rocketlauncher1Pos_y + 140 && bullet4Pos_y <= rocketlauncher1Pos_y + 151)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= rocketlauncher1Pos_x && bullet5Pos_x <= rocketlauncher1Pos_x + 95 && bullet5Pos_y >= rocketlauncher1Pos_y + 140 && bullet5Pos_y <= rocketlauncher1Pos_y + 151)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= rocketlauncher1Pos_x && bullet6Pos_x <= rocketlauncher1Pos_x + 95 && bullet6Pos_y >= rocketlauncher1Pos_y + 140 && bullet6Pos_y <= rocketlauncher1Pos_y + 151)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= rocketlauncher1Pos_x && bullet7Pos_x <= rocketlauncher1Pos_x + 95 && bullet7Pos_y >= rocketlauncher1Pos_y + 140 && bullet7Pos_y <= rocketlauncher1Pos_y + 151)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= rocketlauncher1Pos_x && bullet8Pos_x <= rocketlauncher1Pos_x + 95 && bullet8Pos_y >= rocketlauncher1Pos_y + 140 && bullet8Pos_y <= rocketlauncher1Pos_y + 151)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= rocketlauncher1Pos_x && bullet9Pos_x <= rocketlauncher1Pos_x + 95 && bullet9Pos_y >= rocketlauncher1Pos_y + 140 && bullet9Pos_y <= rocketlauncher1Pos_y + 151)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= rocketlauncher1Pos_x && bullet10Pos_x <= rocketlauncher1Pos_x + 95 && bullet10Pos_y >= rocketlauncher1Pos_y + 140 && bullet10Pos_y <= rocketlauncher1Pos_y + 151)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between rocketlauncher-1 and bullet and bullet get vanished

				sprite_rocketlauncher1.setPosition(sf::Vector2f(rocketlauncher1Pos_x, rocketlauncher1Pos_y));
				window.draw(sprite_rocketlauncher1);

				if (rocketlauncher1Pos_x >= spaceshipPos_x && rocketlauncher1Pos_x <= spaceshipPos_x + 150 && rocketlauncher1Pos_y >= spaceshipPos_y && rocketlauncher1Pos_y <= spaceshipPos_y + 150)
				{

					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (rocketlauncher1Pos_x >= spaceshipPos_x && rocketlauncher1Pos_x <= spaceshipPos_x + 150 && rocketlauncher1Pos_y >= spaceshipPos_y && rocketlauncher1Pos_y <= spaceshipPos_y + 150 && rocketLauncher1Flag == 0)
				{

					life1 = life1 - 10;
					rocketLauncher1Flag = 1;
				}

				//rocketlauncher - 2

				rocketlauncher2Pos_y += .5;

				//start coding of collision between rocketlauncher-2 and bullet and bullet get vanished

				if (bullet1Pos_x >= rocketlauncher2Pos_x && bullet1Pos_x <= rocketlauncher2Pos_x + 95 && bullet1Pos_y >= rocketlauncher2Pos_y + 140 && bullet1Pos_y <= rocketlauncher2Pos_y + 151)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= rocketlauncher2Pos_x && bullet2Pos_x <= rocketlauncher2Pos_x + 95 && bullet2Pos_y >= rocketlauncher2Pos_y + 140 && bullet2Pos_y <= rocketlauncher2Pos_y + 151)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= rocketlauncher2Pos_x && bullet3Pos_x <= rocketlauncher2Pos_x + 95 && bullet3Pos_y >= rocketlauncher2Pos_y + 140 && bullet3Pos_y <= rocketlauncher2Pos_y + 151)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= rocketlauncher2Pos_x && bullet4Pos_x <= rocketlauncher2Pos_x + 95 && bullet4Pos_y >= rocketlauncher2Pos_y + 140 && bullet4Pos_y <= rocketlauncher2Pos_y + 151)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= rocketlauncher2Pos_x && bullet5Pos_x <= rocketlauncher2Pos_x + 95 && bullet5Pos_y >= rocketlauncher2Pos_y + 140 && bullet5Pos_y <= rocketlauncher2Pos_y + 151)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= rocketlauncher2Pos_x && bullet6Pos_x <= rocketlauncher2Pos_x + 95 && bullet6Pos_y >= rocketlauncher2Pos_y + 140 && bullet6Pos_y <= rocketlauncher2Pos_y + 151)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= rocketlauncher2Pos_x && bullet7Pos_x <= rocketlauncher2Pos_x + 95 && bullet7Pos_y >= rocketlauncher2Pos_y + 140 && bullet7Pos_y <= rocketlauncher2Pos_y + 151)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= rocketlauncher2Pos_x && bullet8Pos_x <= rocketlauncher2Pos_x + 95 && bullet8Pos_y >= rocketlauncher2Pos_y + 140 && bullet8Pos_y <= rocketlauncher2Pos_y + 151)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= rocketlauncher2Pos_x && bullet9Pos_x <= rocketlauncher2Pos_x + 95 && bullet9Pos_y >= rocketlauncher2Pos_y + 140 && bullet9Pos_y <= rocketlauncher2Pos_y + 151)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= rocketlauncher2Pos_x && bullet10Pos_x <= rocketlauncher2Pos_x + 95 && bullet10Pos_y >= rocketlauncher2Pos_y + 140 && bullet10Pos_y <= rocketlauncher2Pos_y + 151)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between rocketlauncher-2 and bullet and bullet get vanished

				sprite_rocketlauncher2.setPosition(sf::Vector2f(rocketlauncher2Pos_x, rocketlauncher2Pos_y));
				window.draw(sprite_rocketlauncher2);

				if (rocketlauncher2Pos_x >= spaceshipPos_x && rocketlauncher2Pos_x <= spaceshipPos_x + 150 && rocketlauncher2Pos_y >= spaceshipPos_y && rocketlauncher2Pos_y <= spaceshipPos_y + 150)
				{

					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (rocketlauncher2Pos_x >= spaceshipPos_x && rocketlauncher2Pos_x <= spaceshipPos_x + 150 && rocketlauncher2Pos_y >= spaceshipPos_y && rocketlauncher2Pos_y <= spaceshipPos_y + 150 && rocketLauncher2Flag == 0)
				{

					life1 = life1 - 10;
					rocketLauncher2Flag = 1;
				}

				//rocketlauncher - 3

				rocketlauncher3Pos_y += .5;

				//start coding of collision between rocketlauncher-3 and bullet and bullet get vanished

				if (bullet1Pos_x >= rocketlauncher3Pos_x && bullet1Pos_x <= rocketlauncher3Pos_x + 95 && bullet1Pos_y >= rocketlauncher3Pos_y + 140 && bullet1Pos_y <= rocketlauncher3Pos_y + 151)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= rocketlauncher3Pos_x && bullet2Pos_x <= rocketlauncher3Pos_x + 95 && bullet2Pos_y >= rocketlauncher3Pos_y + 140 && bullet2Pos_y <= rocketlauncher3Pos_y + 151)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= rocketlauncher3Pos_x && bullet3Pos_x <= rocketlauncher3Pos_x + 95 && bullet3Pos_y >= rocketlauncher3Pos_y + 140 && bullet3Pos_y <= rocketlauncher3Pos_y + 151)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= rocketlauncher3Pos_x && bullet4Pos_x <= rocketlauncher3Pos_x + 95 && bullet4Pos_y >= rocketlauncher3Pos_y + 140 && bullet4Pos_y <= rocketlauncher3Pos_y + 151)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= rocketlauncher3Pos_x && bullet5Pos_x <= rocketlauncher3Pos_x + 95 && bullet5Pos_y >= rocketlauncher3Pos_y + 140 && bullet5Pos_y <= rocketlauncher3Pos_y + 151)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= rocketlauncher3Pos_x && bullet6Pos_x <= rocketlauncher3Pos_x + 95 && bullet6Pos_y >= rocketlauncher3Pos_y + 140 && bullet6Pos_y <= rocketlauncher3Pos_y + 151)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= rocketlauncher3Pos_x && bullet7Pos_x <= rocketlauncher3Pos_x + 95 && bullet7Pos_y >= rocketlauncher3Pos_y + 140 && bullet7Pos_y <= rocketlauncher3Pos_y + 151)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= rocketlauncher3Pos_x && bullet8Pos_x <= rocketlauncher3Pos_x + 95 && bullet8Pos_y >= rocketlauncher3Pos_y + 140 && bullet8Pos_y <= rocketlauncher3Pos_y + 151)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= rocketlauncher3Pos_x && bullet9Pos_x <= rocketlauncher3Pos_x + 95 && bullet9Pos_y >= rocketlauncher3Pos_y + 140 && bullet9Pos_y <= rocketlauncher3Pos_y + 151)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= rocketlauncher3Pos_x && bullet10Pos_x <= rocketlauncher3Pos_x + 95 && bullet10Pos_y >= rocketlauncher3Pos_y + 140 && bullet10Pos_y <= rocketlauncher3Pos_y + 151)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between rocketlauncher-2 and bullet and bullet get vanished

				sprite_rocketlauncher3.setPosition(sf::Vector2f(rocketlauncher3Pos_x, rocketlauncher3Pos_y));
				window.draw(sprite_rocketlauncher3);

				if (rocketlauncher3Pos_x >= spaceshipPos_x && rocketlauncher3Pos_x <= spaceshipPos_x + 150 && rocketlauncher3Pos_y >= spaceshipPos_y && rocketlauncher3Pos_y <= spaceshipPos_y + 150)
				{

					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (rocketlauncher3Pos_x >= spaceshipPos_x && rocketlauncher3Pos_x <= spaceshipPos_x + 150 && rocketlauncher3Pos_y >= spaceshipPos_y && rocketlauncher3Pos_y <= spaceshipPos_y + 150 && rocketLauncher3Flag == 0)
				{

					life1 = life1 - 10;
					rocketLauncher3Flag = 1;
				}

				//rocketlauncher - 4

				rocketlauncher4Pos_y += .5;

				//start coding of collision between rocketlauncher-3 and bullet and bullet get vanished

				if (bullet1Pos_x >= rocketlauncher4Pos_x && bullet1Pos_x <= rocketlauncher4Pos_x + 95 && bullet1Pos_y >= rocketlauncher4Pos_y + 140 && bullet1Pos_y <= rocketlauncher4Pos_y + 151)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= rocketlauncher4Pos_x && bullet2Pos_x <= rocketlauncher4Pos_x + 95 && bullet2Pos_y >= rocketlauncher4Pos_y + 140 && bullet2Pos_y <= rocketlauncher4Pos_y + 151)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= rocketlauncher4Pos_x && bullet3Pos_x <= rocketlauncher4Pos_x + 95 && bullet3Pos_y >= rocketlauncher4Pos_y + 140 && bullet3Pos_y <= rocketlauncher4Pos_y + 151)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= rocketlauncher4Pos_x && bullet4Pos_x <= rocketlauncher4Pos_x + 95 && bullet4Pos_y >= rocketlauncher4Pos_y + 140 && bullet4Pos_y <= rocketlauncher4Pos_y + 151)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= rocketlauncher4Pos_x && bullet5Pos_x <= rocketlauncher4Pos_x + 95 && bullet5Pos_y >= rocketlauncher4Pos_y + 140 && bullet5Pos_y <= rocketlauncher4Pos_y + 151)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= rocketlauncher4Pos_x && bullet6Pos_x <= rocketlauncher4Pos_x + 95 && bullet6Pos_y >= rocketlauncher4Pos_y + 140 && bullet6Pos_y <= rocketlauncher4Pos_y + 151)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= rocketlauncher4Pos_x && bullet7Pos_x <= rocketlauncher4Pos_x + 95 && bullet7Pos_y >= rocketlauncher4Pos_y + 140 && bullet7Pos_y <= rocketlauncher4Pos_y + 151)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= rocketlauncher4Pos_x && bullet8Pos_x <= rocketlauncher4Pos_x + 95 && bullet8Pos_y >= rocketlauncher4Pos_y + 140 && bullet8Pos_y <= rocketlauncher4Pos_y + 151)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= rocketlauncher4Pos_x && bullet9Pos_x <= rocketlauncher4Pos_x + 95 && bullet9Pos_y >= rocketlauncher4Pos_y + 140 && bullet9Pos_y <= rocketlauncher4Pos_y + 151)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= rocketlauncher4Pos_x && bullet10Pos_x <= rocketlauncher4Pos_x + 95 && bullet10Pos_y >= rocketlauncher4Pos_y + 140 && bullet10Pos_y <= rocketlauncher4Pos_y + 151)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between rocketlauncher-2 and bullet and bullet get vanished

				sprite_rocketlauncher4.setPosition(sf::Vector2f(rocketlauncher4Pos_x, rocketlauncher4Pos_y));
				window.draw(sprite_rocketlauncher4);

				if (rocketlauncher4Pos_x >= spaceshipPos_x && rocketlauncher4Pos_x <= spaceshipPos_x + 150 && rocketlauncher4Pos_y >= spaceshipPos_y && rocketlauncher4Pos_y <= spaceshipPos_y + 150)
				{

					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (rocketlauncher4Pos_x >= spaceshipPos_x && rocketlauncher4Pos_x <= spaceshipPos_x + 150 && rocketlauncher4Pos_y >= spaceshipPos_y && rocketlauncher4Pos_y <= spaceshipPos_y + 150 && rocketLauncher4Flag == 0)
				{

					life1 = life1 - 10;
					rocketLauncher4Flag = 1;
				}

				//rocketlauncher - 5

				rocketlauncher5Pos_y += .5;

				//start coding of collision between rocketlauncher-3 and bullet and bullet get vanished

				if (bullet1Pos_x >= rocketlauncher5Pos_x && bullet1Pos_x <= rocketlauncher5Pos_x + 95 && bullet1Pos_y >= rocketlauncher5Pos_y + 140 && bullet1Pos_y <= rocketlauncher5Pos_y + 151)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= rocketlauncher5Pos_x && bullet2Pos_x <= rocketlauncher5Pos_x + 95 && bullet2Pos_y >= rocketlauncher5Pos_y + 140 && bullet2Pos_y <= rocketlauncher5Pos_y + 151)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= rocketlauncher5Pos_x && bullet3Pos_x <= rocketlauncher5Pos_x + 95 && bullet3Pos_y >= rocketlauncher5Pos_y + 140 && bullet3Pos_y <= rocketlauncher5Pos_y + 151)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= rocketlauncher5Pos_x && bullet4Pos_x <= rocketlauncher5Pos_x + 95 && bullet4Pos_y >= rocketlauncher5Pos_y + 140 && bullet4Pos_y <= rocketlauncher5Pos_y + 151)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= rocketlauncher5Pos_x && bullet5Pos_x <= rocketlauncher5Pos_x + 95 && bullet5Pos_y >= rocketlauncher5Pos_y + 140 && bullet5Pos_y <= rocketlauncher5Pos_y + 151)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= rocketlauncher5Pos_x && bullet6Pos_x <= rocketlauncher5Pos_x + 95 && bullet6Pos_y >= rocketlauncher5Pos_y + 140 && bullet6Pos_y <= rocketlauncher5Pos_y + 151)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= rocketlauncher5Pos_x && bullet7Pos_x <= rocketlauncher5Pos_x + 95 && bullet7Pos_y >= rocketlauncher5Pos_y + 140 && bullet7Pos_y <= rocketlauncher5Pos_y + 151)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= rocketlauncher5Pos_x && bullet8Pos_x <= rocketlauncher5Pos_x + 95 && bullet8Pos_y >= rocketlauncher5Pos_y + 140 && bullet8Pos_y <= rocketlauncher5Pos_y + 151)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= rocketlauncher5Pos_x && bullet9Pos_x <= rocketlauncher5Pos_x + 95 && bullet9Pos_y >= rocketlauncher5Pos_y + 140 && bullet9Pos_y <= rocketlauncher5Pos_y + 151)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= rocketlauncher5Pos_x && bullet10Pos_x <= rocketlauncher5Pos_x + 95 && bullet10Pos_y >= rocketlauncher5Pos_y + 140 && bullet10Pos_y <= rocketlauncher5Pos_y + 151)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between rocketlauncher-2 and bullet and bullet get vanished

				sprite_rocketlauncher5.setPosition(sf::Vector2f(rocketlauncher5Pos_x, rocketlauncher5Pos_y));
				window.draw(sprite_rocketlauncher5);

				if (rocketlauncher5Pos_x >= spaceshipPos_x && rocketlauncher5Pos_x <= spaceshipPos_x + 150 && rocketlauncher5Pos_y >= spaceshipPos_y && rocketlauncher5Pos_y <= spaceshipPos_y + 150)
				{

					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (rocketlauncher5Pos_x >= spaceshipPos_x && rocketlauncher5Pos_x <= spaceshipPos_x + 150 && rocketlauncher5Pos_y >= spaceshipPos_y && rocketlauncher5Pos_y <= spaceshipPos_y + 150 && rocketLauncher5Flag == 0)
				{

					life1 = life1 - 10;
					rocketLauncher5Flag = 1;
				}

				//rocketlauncher - 6

				rocketlauncher6Pos_y += .5;

				//start coding of collision between rocketlauncher-3 and bullet and bullet get vanished

				if (bullet1Pos_x >= rocketlauncher6Pos_x && bullet1Pos_x <= rocketlauncher6Pos_x + 95 && bullet1Pos_y >= rocketlauncher6Pos_y + 140 && bullet1Pos_y <= rocketlauncher6Pos_y + 151)
				{
					bullet1Pos_x = -1200;

				}
				else if (bullet2Pos_x >= rocketlauncher6Pos_x && bullet2Pos_x <= rocketlauncher6Pos_x + 95 && bullet2Pos_y >= rocketlauncher6Pos_y + 140 && bullet2Pos_y <= rocketlauncher6Pos_y + 151)
				{
					bullet2Pos_x = -1200;

				}
				else if (bullet3Pos_x >= rocketlauncher6Pos_x && bullet3Pos_x <= rocketlauncher6Pos_x + 95 && bullet3Pos_y >= rocketlauncher6Pos_y + 140 && bullet3Pos_y <= rocketlauncher6Pos_y + 151)
				{
					bullet3Pos_x = -1200;

				}
				else if (bullet4Pos_x >= rocketlauncher6Pos_x && bullet4Pos_x <= rocketlauncher6Pos_x + 95 && bullet4Pos_y >= rocketlauncher6Pos_y + 140 && bullet4Pos_y <= rocketlauncher6Pos_y + 151)
				{
					bullet4Pos_x = -1200;

				}
				else if (bullet5Pos_x >= rocketlauncher6Pos_x && bullet5Pos_x <= rocketlauncher6Pos_x + 95 && bullet5Pos_y >= rocketlauncher6Pos_y + 140 && bullet5Pos_y <= rocketlauncher6Pos_y + 151)
				{
					bullet5Pos_x = -1200;

				}
				else if (bullet6Pos_x >= rocketlauncher6Pos_x && bullet6Pos_x <= rocketlauncher6Pos_x + 95 && bullet6Pos_y >= rocketlauncher6Pos_y + 140 && bullet6Pos_y <= rocketlauncher6Pos_y + 151)
				{
					bullet6Pos_x = -1200;

				}
				else if (bullet7Pos_x >= rocketlauncher6Pos_x && bullet7Pos_x <= rocketlauncher6Pos_x + 95 && bullet7Pos_y >= rocketlauncher6Pos_y + 140 && bullet7Pos_y <= rocketlauncher6Pos_y + 151)
				{
					bullet7Pos_x = -1200;

				}
				else if (bullet8Pos_x >= rocketlauncher6Pos_x && bullet8Pos_x <= rocketlauncher6Pos_x + 95 && bullet8Pos_y >= rocketlauncher6Pos_y + 140 && bullet8Pos_y <= rocketlauncher6Pos_y + 151)
				{
					bullet8Pos_x = -1200;

				}
				else if (bullet9Pos_x >= rocketlauncher6Pos_x && bullet9Pos_x <= rocketlauncher6Pos_x + 95 && bullet9Pos_y >= rocketlauncher6Pos_y + 140 && bullet9Pos_y <= rocketlauncher6Pos_y + 151)
				{
					bullet9Pos_x = -1200;

				}
				else if (bullet10Pos_x >= rocketlauncher6Pos_x && bullet10Pos_x <= rocketlauncher6Pos_x + 95 && bullet10Pos_y >= rocketlauncher6Pos_y + 140 && bullet10Pos_y <= rocketlauncher6Pos_y + 151)
				{
					bullet10Pos_x = -1200;

				}

				//end coding of collision between rocketlauncher-2 and bullet and bullet get vanished

				sprite_rocketlauncher6.setPosition(sf::Vector2f(rocketlauncher6Pos_x, rocketlauncher6Pos_y));
				window.draw(sprite_rocketlauncher6);

				if (rocketlauncher6Pos_x >= spaceshipPos_x && rocketlauncher6Pos_x <= spaceshipPos_x + 150 && rocketlauncher6Pos_y >= spaceshipPos_y && rocketlauncher6Pos_y <= spaceshipPos_y + 150)
				{

					sprite_spaceship1Effect.setPosition(sf::Vector2f(spaceshipPos_x, spaceshipPos_y));
					window.draw(sprite_spaceship1Effect);
				}
				if (rocketlauncher6Pos_x >= spaceshipPos_x && rocketlauncher6Pos_x <= spaceshipPos_x + 150 && rocketlauncher6Pos_y >= spaceshipPos_y && rocketlauncher6Pos_y <= spaceshipPos_y + 150 && rocketLauncher6Flag == 0)
				{

					life1 = life1 - 10;
					rocketLauncher6Flag = 1;
				}
			}
			/////////////////////////////////////////////////////////////////rocketlauncher sesh//////////////////////////////////////////////
			

			if (enemy1_clock.getElapsedTime() > rocketLauncher_time_stage2){
				if (enemy1Pos_y <= 30)
				{
					enemy1Pos_y += .1;
					//this is for rocket attack
					rocket1_1Pos_y += 1;
					rocket1_2Pos_y += 2;
					rocket1_3Pos_y += 1;

					if (rocket1_1Pos_x >= spaceshipPos_x && rocket1_1Pos_x <= spaceshipPos_x + 150 && rocket1_1Pos_y >= spaceshipPos_y && rocket1_1Pos_y <= spaceshipPos_y + 150 && rocket1_1_Flag == 0)
					{
						life1 -= 10;
						rocket1_1_Flag = 1;
					}
					if (rocket1_2Pos_x >= spaceshipPos_x && rocket1_2Pos_x <= spaceshipPos_x + 150 && rocket1_2Pos_y >= spaceshipPos_y && rocket1_2Pos_y <= spaceshipPos_y + 150 && rocket1_2_Flag == 0)
					{
						life1 -= 10;
						rocket1_2_Flag = 1;
					}

					if (rocket1_3Pos_x >= spaceshipPos_x && rocket1_3Pos_x <= spaceshipPos_x + 150 && rocket1_3Pos_y >= spaceshipPos_y && rocket1_3Pos_y <= spaceshipPos_y + 150 && rocket1_3_Flag == 0)
					{
						life1 -= 10;
						rocket1_3_Flag = 1;
					}

					sprite_rocket1_1.setPosition(sf::Vector2f(rocket1_1Pos_x, rocket1_1Pos_y));
					window.draw(sprite_rocket1_1);

					sprite_rocket1_2.setPosition(sf::Vector2f(rocket1_2Pos_x, rocket1_2Pos_y));
					window.draw(sprite_rocket1_2);

					sprite_rocket1_3.setPosition(sf::Vector2f(rocket1_3Pos_x, rocket1_3Pos_y));
					window.draw(sprite_rocket1_3);
					//enemy1_clock.restart();
				}
				if (enemy1Pos_x >= 0 && enemy_flag == 0)
				{
					enemy1Pos_x -= 1;
					//enemy1_clock.restart();
				}
				if (enemy1Pos_x <= 5) enemy_flag = 1;
				if (enemy1Pos_x <= 1300 && enemy_flag == 1)
				{
					enemy1Pos_x += 1;
					//enemy1_clock.restart();
				}
				if (enemy1Pos_x >= 1200) enemy_flag = 0;
				sprite_boss1.setPosition(sf::Vector2f(enemy1Pos_x, enemy1Pos_y));
				window.draw(sprite_boss1);
				//if (enemy1Pos_y == 30) enemybullet1counter++;
				if (enemybullet1_Flag == 0)
				{
					enemybullet1Pos_x = enemy1Pos_x + 53;
					enemybullet1Pos_y = enemy1Pos_y + 95;
					enemybullet1_Flag = 1;
				}
				if (enemybullet1Pos_y <= 740)
				{
					enemybullet1Pos_y += 1;
					enemybullet1counter++;
					if (enemybullet1Pos_y >= spaceshipPos_y && enemybullet1Pos_y <= spaceshipPos_y + 20 && enemybullet1Pos_x >= spaceshipPos_x + 20 && enemybullet1Pos_x <= spaceshipPos_x + 140)
					{
						enemybullet1Pos_y = 731;
						life1 = life1 - 10;
					}
				}
				else enemybullet1_Flag = 0;
				sprite_enemybullet1.setPosition(sf::Vector2f(enemybullet1Pos_x, enemybullet1Pos_y));
				window.draw(sprite_enemybullet1);
				if (enemybullet2_Flag == 0 && enemybullet1counter>50)
				{
					enemybullet2Pos_x = enemy1Pos_x + 53;
					enemybullet2Pos_y = enemy1Pos_y + 95;
					enemybullet2_Flag = 1;
				}
				if (enemybullet2Pos_y <= 740)
				{
					enemybullet2Pos_y += 1;
					enemybullet2counter++;
					if (enemybullet2Pos_y >= spaceshipPos_y && enemybullet2Pos_y <= spaceshipPos_y + 20 && enemybullet2Pos_x >= spaceshipPos_x + 20 && enemybullet2Pos_x <= spaceshipPos_x + 140)
					{
						enemybullet2Pos_y = 731;
						life1 = life1 - 10;
					}
				}
				else enemybullet2_Flag = 0;
				sprite_enemybullet2.setPosition(sf::Vector2f(enemybullet2Pos_x, enemybullet2Pos_y));
				window.draw(sprite_enemybullet2);
				if (enemybullet3_Flag == 0)
				{
					enemybullet3Pos_x = enemy1Pos_x + 53;
					enemybullet3Pos_y = enemy1Pos_y + 95;
					enemybullet3_Flag = 1;
				}
				if (enemybullet3Pos_y <= 740 && enemybullet2counter > 50)
				{
					enemybullet3Pos_y += 1;
					enemybullet3counter++;
					if (enemybullet3Pos_y >= spaceshipPos_y &&enemybullet3Pos_y <= spaceshipPos_y + 20 && enemybullet3Pos_x >= spaceshipPos_x + 20 && enemybullet3Pos_x <= spaceshipPos_x + 140)
					{
						enemybullet3Pos_y = 731;
						life1 = life1 - 10;
					}
				}
				else enemybullet3_Flag = 0;
				sprite_enemybullet3.setPosition(sf::Vector2f(enemybullet3Pos_x, enemybullet3Pos_y));
				window.draw(sprite_enemybullet3);
				if (enemybullet4_Flag == 0)
				{
					enemybullet4Pos_x = enemy1Pos_x + 53;
					enemybullet4Pos_y = enemy1Pos_y + 95;
					enemybullet4_Flag = 1;
				}
				if (enemybullet4Pos_y <= 740 && enemybullet3counter > 50)
				{
					enemybullet4Pos_y += 1;
					enemybullet4counter++;
					if (enemybullet4Pos_y >= spaceshipPos_y && enemybullet4Pos_y <= spaceshipPos_y + 20 && enemybullet4Pos_x >= spaceshipPos_x + 20 && enemybullet4Pos_x <= spaceshipPos_x + 140)
					{
						enemybullet4Pos_y = 731;
						life1 = life1 - 10;
					}
				}
				else enemybullet4_Flag = 0;
				sprite_enemybullet4.setPosition(sf::Vector2f(enemybullet4Pos_x, enemybullet4Pos_y));
				window.draw(sprite_enemybullet4);
				if (enemybullet5_Flag == 0)
				{
					enemybullet5Pos_x = enemy1Pos_x + 53;
					enemybullet5Pos_y = enemy1Pos_y + 95;
					enemybullet5_Flag = 1;
				}
				if (enemybullet5Pos_y <= 740 && enemybullet4counter > 50)
				{
					enemybullet5Pos_y += 1;
					enemybullet5counter++;
					if (enemybullet5Pos_y >= spaceshipPos_y  && enemybullet5Pos_y <= spaceshipPos_y + 20 && enemybullet5Pos_x >= spaceshipPos_x + 20 && enemybullet5Pos_x <= spaceshipPos_x + 140)
					{
						enemybullet5Pos_y = 731;
						life1 = life1 - 10;
					}
				}
				else enemybullet5_Flag = 0;
				sprite_enemybullet5.setPosition(sf::Vector2f(enemybullet5Pos_x, enemybullet5Pos_y));
				window.draw(sprite_enemybullet5);


				sprintf(enemylif, "Enemy: %d", enemylife);
				bosslife.setString(enemylif);
				window.draw(bosslife);


			}
			if (life1 <= 0)
			{
				click_flag = 10;
			}

			if (bullet1_Flag == 0)
			{
				bullet1Pos_x = spaceshipPos_x + 68;
				bullet1Pos_y = spaceshipPos_y + 2;
				bullet1_Flag = 1;

			}
			if (bullet1Pos_y >= -55)
			{
				bullet1_clock.restart();
				bullet1Pos_y -= 1;
				if (bullet1Pos_x >= enemy1Pos_x && bullet1Pos_x <= enemy1Pos_x + 100 && bullet1Pos_y <= enemy1Pos_y + 100 && bullet1Pos_y >= enemy1Pos_y + 90)
				{
					enemylife -= 5;
					bullet1Pos_y = -100;
					point1 += 10;
				}
				bullet1counter++;
			}
			if (bullet1_clock.getElapsedTime() > bullet1_time)
			{
				bullet1_Flag = 0;
			}
			sprite_bullet1.setPosition(sf::Vector2f(bullet1Pos_x, bullet1Pos_y));
			window.draw(sprite_bullet1);
			if (bullet2_Flag == 0)
			{
				bullet2Pos_x = spaceshipPos_x + 68;
				bullet2Pos_y = spaceshipPos_y + 2;
				bullet2_Flag = 1;

			}
			if (bullet2Pos_y >= -55 && bullet1counter > 62)
			{
				bullet2_clock.restart();
				bullet2Pos_y -= 1;
				if (bullet2Pos_x >= enemy1Pos_x && bullet2Pos_x <= enemy1Pos_x + 100 && bullet2Pos_y <= enemy1Pos_y + 100 && bullet2Pos_y >= enemy1Pos_y + 90)
				{
					enemylife -= 5;
					bullet2Pos_y = -100;
					point1 += 10;
				}
				bullet2counter++;
			}
			if (bullet2_clock.getElapsedTime() > bullet2_time)
			{
				bullet2_Flag = 0;
			}
			sprite_bullet2.setPosition(sf::Vector2f(bullet2Pos_x, bullet2Pos_y));
			window.draw(sprite_bullet2);
			if (bullet3_Flag == 0)
			{
				bullet3Pos_x = spaceshipPos_x + 68;
				bullet3Pos_y = spaceshipPos_y + 2;
				bullet3_Flag = 1;

			}
			if (bullet3Pos_y >= -55 && bullet2counter > 62)
			{
				bullet3Pos_y -= 1;
				bullet3_clock.restart();
				if (bullet3Pos_x >= enemy1Pos_x && bullet3Pos_x <= enemy1Pos_x + 100 && bullet3Pos_y <= enemy1Pos_y + 100 && bullet3Pos_y >= enemy1Pos_y + 90)
				{
					enemylife -= 5;
					bullet3Pos_y = -100;
					point1 += 10;
				}
				bullet3counter++;
			}
			if (bullet3_clock.getElapsedTime() > bullet3_time)
			{
				bullet3_Flag = 0;
			}
			sprite_bullet3.setPosition(sf::Vector2f(bullet3Pos_x, bullet3Pos_y));
			window.draw(sprite_bullet3);
			if (bullet4_Flag == 0)
			{
				bullet4Pos_x = spaceshipPos_x + 68;
				bullet4Pos_y = spaceshipPos_y + 2;
				bullet4_Flag = 1;
			}
			if (bullet4Pos_y >= -55 && bullet3counter > 62)
			{
				bullet4_clock.restart();
				bullet4Pos_y -= 1;
				if (bullet4Pos_x >= enemy1Pos_x && bullet4Pos_x <= enemy1Pos_x + 100 && bullet4Pos_y <= enemy1Pos_y + 100 && bullet4Pos_y >= enemy1Pos_y + 90)
				{
					enemylife -= 5;
					bullet4Pos_y = -100;
					point1 += 10;
				}
				bullet4counter++;
			}
			if (bullet4_clock.getElapsedTime() > bullet4_time)
			{
				bullet4_Flag = 0;
			}
			//else bullet4_Flag = 0;
			sprite_bullet4.setPosition(sf::Vector2f(bullet4Pos_x, bullet4Pos_y));
			window.draw(sprite_bullet4);
			if (bullet5_Flag == 0)
			{
				bullet5Pos_x = spaceshipPos_x + 68;
				bullet5Pos_y = spaceshipPos_y + 2;
				bullet5_Flag = 1;
			}
			if (bullet5Pos_y >= -55 && bullet4counter > 62)
			{
				bullet5_clock.restart();
				bullet5Pos_y -= 1;
				if (bullet5Pos_x >= enemy1Pos_x && bullet5Pos_x <= enemy1Pos_x + 100 && bullet5Pos_y <= enemy1Pos_y + 100 && bullet5Pos_y >= enemy1Pos_y + 90)
				{
					enemylife -= 5;
					bullet5Pos_y = -100;
					point1 += 10;
				}
				bullet5counter++;
			}
			if (bullet5_clock.getElapsedTime() > bullet5_time)
			{
				bullet5_Flag = 0;
			}
			sprite_bullet5.setPosition(sf::Vector2f(bullet5Pos_x, bullet5Pos_y));
			window.draw(sprite_bullet5);
			if (bullet6_Flag == 0)
			{
				bullet6Pos_x = spaceshipPos_x + 68;
				bullet6Pos_y = spaceshipPos_y + 2;
				bullet6_Flag = 1;
			}
			if (bullet6Pos_y >= -55 && bullet5counter > 62)
			{
				bullet6_clock.restart();
				bullet6Pos_y -= 1;
				if (bullet6Pos_x >= enemy1Pos_x && bullet6Pos_x <= enemy1Pos_x + 100 && bullet6Pos_y <= enemy1Pos_y + 100 && bullet6Pos_y >= enemy1Pos_y + 90)
				{
					enemylife -= 5;
					bullet6Pos_y = -100;
					point1 += 10;
				}
				bullet6counter++;
			}
			if (bullet6_clock.getElapsedTime() > bullet6_time)
			{
				bullet6_Flag = 0;
			}
			sprite_bullet6.setPosition(sf::Vector2f(bullet6Pos_x, bullet6Pos_y));
			window.draw(sprite_bullet6);
			if (bullet7_Flag == 0)
			{
				bullet7Pos_x = spaceshipPos_x + 68;
				bullet7Pos_y = spaceshipPos_y + 2;
				bullet7_Flag = 1;
			}
			if (bullet7Pos_y >= -55 && bullet6counter > 62)
			{
				bullet7_clock.restart();
				bullet7Pos_y -= 1;
				if (bullet7Pos_x >= enemy1Pos_x && bullet7Pos_x <= enemy1Pos_x + 100 && bullet7Pos_y <= enemy1Pos_y + 100 && bullet7Pos_y >= enemy1Pos_y + 90)
				{
					enemylife -= 5;
					bullet7Pos_y = -100;
					point1 += 10;
				}
				bullet7counter++;
			}
			if (bullet7_clock.getElapsedTime() > bullet7_time)
			{
				bullet7_Flag = 0;
			}
			sprite_bullet7.setPosition(sf::Vector2f(bullet7Pos_x, bullet7Pos_y));
			window.draw(sprite_bullet7);
			if (bullet8_Flag == 0)
			{
				bullet8Pos_x = spaceshipPos_x + 68;
				bullet8Pos_y = spaceshipPos_y + 2;
				bullet8_Flag = 1;
			}
			if (bullet8Pos_y >= -55 && bullet7counter > 62)
			{
				bullet8_clock.restart();
				bullet8Pos_y -= 1;
				if (bullet8Pos_x >= enemy1Pos_x && bullet8Pos_x <= enemy1Pos_x + 100 && bullet8Pos_y <= enemy1Pos_y + 100 && bullet8Pos_y >= enemy1Pos_y + 90)
				{
					enemylife -= 5;
					bullet8Pos_y = -100;
					point1 += 10;
				}
				bullet8counter++;
			}
			if (bullet8_clock.getElapsedTime() > bullet8_time)
			{
				bullet8_Flag = 0;
			}
			sprite_bullet8.setPosition(sf::Vector2f(bullet8Pos_x, bullet8Pos_y));
			window.draw(sprite_bullet8);
			if (bullet9_Flag == 0)
			{
				bullet9Pos_x = spaceshipPos_x + 68;
				bullet9Pos_y = spaceshipPos_y + 2;
				bullet9_Flag = 1;
			}
			if (bullet9Pos_y >= -55 && bullet8counter > 62)
			{
				bullet9_clock.restart();
				bullet9Pos_y -= 1;
				if (bullet9Pos_x >= enemy1Pos_x && bullet9Pos_x <= enemy1Pos_x + 100 && bullet9Pos_y <= enemy1Pos_y + 100 && bullet9Pos_y >= enemy1Pos_y + 90)
				{
					enemylife -= 5;
					bullet9Pos_y = -100;
					point1 += 10;
				}
				bullet9counter++;
			}
			if (bullet9_clock.getElapsedTime() > bullet9_time)
			{
				bullet9_Flag = 0;
			}
			sprite_bullet9.setPosition(sf::Vector2f(bullet9Pos_x, bullet9Pos_y));
			window.draw(sprite_bullet9);
			if (bullet10_Flag == 0)
			{
				bullet10Pos_x = spaceshipPos_x + 68;
				bullet10Pos_y = spaceshipPos_y + 2;
				bullet10_Flag = 1;
			}
			if (bullet10Pos_y >= -55 && bullet9counter > 62)
			{
				bullet10_clock.restart();
				bullet10Pos_y -= 1;
				if (bullet10Pos_x >= enemy1Pos_x && bullet10Pos_x <= enemy1Pos_x + 100 && bullet10Pos_y <= enemy1Pos_y + 100 && bullet10Pos_y >= enemy1Pos_y + 90)
				{
					enemylife -= 5;
					bullet10Pos_y = -100;
					point1 += 10;
				}
				bullet10counter++;
			}
			if (bullet10_clock.getElapsedTime() > bullet10_time)
			{
				bullet10_Flag = 0;
			}
			sprite_bullet10.setPosition(sf::Vector2f(bullet10Pos_x, bullet10Pos_y));
			window.draw(sprite_bullet10);
			if (enemylife <= 0) click_flag = 11;
			sprintf(lifeshow, "Life: %d", life1);
			life.setString(lifeshow);
			window.draw(life);
			sprintf(points, "Point: %d", point1);
			point.setString(points);
			window.draw(point);




		}
		if (click_flag == 3)
		{
			exit();
		}
		if (click_flag == 4)
		{
			instruction();
		}
		if (click_flag == 5)
		{
			highscore();
		}
		if (click_flag == 6)
		{
			pause();
		}
		if (click_flag == 10)
		{
			gameover(point1);
			addscore();
		}
		if (click_flag == 11)
		{
			levelup(point1);
			addscore();
		}
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}
