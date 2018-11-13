#include<SFML\Graphics.hpp>
int screen_width, screen_length;
//float background1_x = 0, background1_y = 0;
//float background2.x = 0, background2_y = -729;
//int background1_flag = 0, background2_flag = 0;
int index;
int  click_flag = 0, exit_flag = 0, enemy_flag = 0;
float spaceshipPos_x = 620, spaceshipPos_y = 580, enemy1Pos_x = 1000, enemy1Pos_y = -170;
float bullet1Pos_x, bullet1Pos_y;
float bullet2Pos_x, bullet2Pos_y;
float bullet3Pos_x, bullet3Pos_y;
float bullet4Pos_x, bullet4Pos_y;
float bullet5Pos_x, bullet5Pos_y;
float bullet6Pos_x, bullet6Pos_y;
float bullet7Pos_x, bullet7Pos_y;
float bullet8Pos_x, bullet8Pos_y;
float bullet9Pos_x, bullet9Pos_y;
float bullet10Pos_x, bullet10Pos_y;
int bullet1counter = 0, bullet2counter = 0;
int bullet3counter = 0, bullet4counter = 0;
int bullet5counter = 0, bullet6counter = 0;
int bullet7counter = 0, bullet8counter = 0;
int bullet9counter = 0, bullet10counter = 0;
bool bullet1_Flag = 0, bullet2_Flag = 0, bullet3_Flag = 0, bullet4_Flag = 0;
bool bullet5_Flag = 0, bullet6_Flag = 0, bullet7_Flag = 0, bullet8_Flag = 0;
bool bullet9_Flag = 0, bullet10_Flag = 0;
bool clock1 = 0, pause_flag = 0;
bool texture_flag = 0, music_flag = 0;
bool smallEnemy1_Flag = 0;
bool smallEnemy2_Flag = 0;
bool smallEnemy3_Flag = 0;
bool smallEnemy4_Flag = 0;
bool smallEnemy5_Flag = 0;
bool ulkaPindo1_Flag = 0;
bool ulkaPindo2_Flag = 0;
bool ulkaPindo3_Flag = 0;
bool ulkaPindo4_Flag = 0;
bool ulkaPindo5_Flag = 0;

float enemybullet1Pos_x, enemybullet1Pos_y;
float enemybullet2Pos_x, enemybullet2Pos_y;
float enemybullet3Pos_x, enemybullet3Pos_y;
float enemybullet4Pos_x, enemybullet4Pos_y;
float enemybullet5Pos_x, enemybullet5Pos_y;
int enemybullet1counter = 0, enemybullet2counter = 0;
int enemybullet3counter = 0, enemybullet4counter = 0;
int enemybullet5counter = 0;
bool enemybullet1_Flag = 0, enemybullet2_Flag = 0;
bool enemybullet3_Flag = 0, enemybullet4_Flag = 0;
bool enemybullet5_Flag = 0;
bool life_flag = 0;
bool smallEnemyBullet1_Flag = 0;
bool smallEnemyBullet2_Flag = 0;
bool smallEnemyBullet3_Flag = 0;
bool smallEnemyBullet4_Flag = 0;
bool smallEnemyBullet5_Flag = 0;

bool smallEnemy2_1_Flag = 0;
bool smallEnemy2_2_Flag = 0;
bool smallEnemy2_3_Flag = 0;
bool smallEnemy2_4_Flag = 0;
bool smallEnemy2_5_Flag = 0;
bool passulka_flag = 0;
//char spaceship[100], boss1[100];

sf::Vector2i mousePos;

int life1 = 100, enemylife = 100, point1 = 0;


float smallEnemy1Pos_x = 30, smallEnemy1Pos_y = -30;
float smallEnemy2Pos_x = -30, smallEnemy2Pos_y = 30;
float smallEnemy3Pos_x = 1330, smallEnemy3Pos_y = 30;
float smallEnemy4Pos_x = 1350, smallEnemy4Pos_y = 30;
float smallEnemy5Pos_x = 620, smallEnemy5Pos_y = -30;
float smallEnemyBullet1Pos_x = 55, smallEnemyBullet1Pos_y = 70;
float smallEnemyBullet2Pos_x = 305, smallEnemyBullet2Pos_y = 70;
float smallEnemyBullet3Pos_x = 1235, smallEnemyBullet3Pos_y = 70;
float smallEnemyBullet4Pos_x = 1005, smallEnemyBullet4Pos_y = 70;
float smallEnemyBullet5Pos_x = 645, smallEnemyBullet5Pos_y = 70;
int smallEnemyCounter1 = 0, smallEnemyCounter2 = 0, smallEnemyCounter3 = 0, smallEnemyCounter4 = 0;
float ulkaPindo1Pos_x = 30, ulkaPindo1Pos_y = -100;
float ulkaPindo2Pos_x = 300, ulkaPindo2Pos_y = -80;
float ulkaPindo3Pos_x = 570, ulkaPindo3Pos_y = -30;
float ulkaPindo4Pos_x = 840, ulkaPindo4Pos_y = -80;
float ulkaPindo5Pos_x = 1100, ulkaPindo5Pos_y = -100;

float smallEnemy2_1Pos_x = -200, smallEnemy2_1Pos_y = 200;
float smallEnemy2_2Pos_x = -200, smallEnemy2_2Pos_y = 300;
float smallEnemy2_3Pos_x = 1500, smallEnemy2_3Pos_y = 200;
float smallEnemy2_4Pos_x = 1500, smallEnemy2_4Pos_y = 300;
float smallEnemy2_5Pos_x = 620, smallEnemy2_5Pos_y = -100;


float smallEnemy2Bullet1Pos_x = 66, smallEnemy2Bullet1Pos_y = 80;
float smallEnemy2Bullet2Pos_x = 340, smallEnemy2Bullet2Pos_y = 150;
float smallEnemy2Bullet3Pos_x = 1230, smallEnemy2Bullet3Pos_y = 80;
float smallEnemy2Bullet4Pos_x = 1016, smallEnemy2Bullet4Pos_y = 150;
float smallEnemy2Bullet5Pos_x = 656, smallEnemy2Bullet5Pos_y = 80;

float rocket1_1Pos_x = 40, rocket1_1Pos_y = -40;
float rocket1_2Pos_x = 380, rocket1_2Pos_y = -40;
float rocket1_3Pos_x = 780, rocket1_3Pos_y = -40;

int rocket1_1_Flag = 0;
int rocket1_2_Flag = 0;
int rocket1_3_Flag = 0;



//rocket launcher speedy

float rocketlauncher1Pos_x = 30, rocketlauncher1Pos_y = -30;
float rocketlauncher2Pos_x = 150, rocketlauncher2Pos_y = -60;
float rocketlauncher3Pos_x = 450, rocketlauncher3Pos_y = -90;
float rocketlauncher4Pos_x = 650, rocketlauncher4Pos_y = -90;
float rocketlauncher5Pos_x = 850, rocketlauncher5Pos_y = -60;
float rocketlauncher6Pos_x = 1030, rocketlauncher6Pos_y = -30;

int rocketLauncher1Flag = 0;
int rocketLauncher2Flag = 0;
int rocketLauncher3Flag = 0;
int rocketLauncher4Flag = 0;
int rocketLauncher5Flag = 0;
int rocketLauncher6Flag = 0;

/*
//fireball 

float fireball1Pos_x = 30, fireball1Pos_y = -30;
float fireball2Pos_x = -30, fireball2Pos_y = -60;
float fireball3Pos_x = -30, fireball3Pos_y = -90;
float fireball4Pos_x = -30, fireball4Pos_y = -90;
float fireball5Pos_x = -30, fireball5Pos_y = -60;
float fireball6Pos_x = -30, fireball6Pos_y = -30;
*/

