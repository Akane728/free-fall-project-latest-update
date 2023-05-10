#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <conio.h>

typedef struct {
    char* value;
    int xPos;
    int yPos;
    bool isCorrectAnswer;
} obstacle;

typedef struct {
    char profile;
    int xPos;
    int yPos;
} player;

int BOARDHEIGHT = 25;
int BOARDWIDTH = 50;
int BOARDXPOS = 20;
int BOARDYPOS = 0;

int playerScore = 0;
int playerLives = 3;
int gameLevel = 1; // initialize the starting level of the game

char* questions[100];
char* question;
char* answer;
obstacle obstacles[5];
player play;

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/**
 * Function for rendering/printing borders of the game
*/
void renderBorders()
{
    int i;
    for (i = 0; i < BOARDHEIGHT; i++)
    {
        gotoxy(BOARDXPOS, i);
        printf("|");
        gotoxy((BOARDXPOS + BOARDWIDTH), i);
        printf("|");
    }
}

/**
 * render player score on the screen
*/
void renderGameScore()
{
    gotoxy(2, 2);
    printf("Score: %d", playerScore);
}

/**
 * render game question on the screen
*/
void renderGameQuestion()
{
    gotoxy(2, 4);
    printf("QUESTION: %s", question);
}

void renderObstacles()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        gotoxy(obstacles[i].xPos, obstacles[i].yPos);
        printf("%s", obstacles[i].value);
    }
}

void renderPlayer()
{
    gotoxy(play.xPos, play.yPos);
    printf("%c", play.profile);
}
void renderPlayerLives()
{
    gotoxy(2, 3);
    printf("Lives: %d", playerLives);
}

void renderScreen()
{
    renderBorders();
    renderGameQuestion();
    renderGameScore();
    renderObstacles();
    renderPlayerLives();
    renderPlayer();
}

#define MAX_LINES 100
#define MAX_LENGTH 100
char* questions[MAX_LINES];
int lineCount = 0; // MAX NUMBER OF LINES IN THE TEXT FILE

/**
 * Grab questions from a csv file or can be a text file
*/
void fetchGameQuestions()
{
    FILE* questionFile;
    char buffer[MAX_LENGTH];

    questionFile = fopen("./game_qa/game_questions.csv", "r");
    if (questionFile == NULL)
    {
        printf("Error: could not open file. \n");
        return;
    }

    while (fgets(buffer, MAX_LENGTH, questionFile) != NULL && lineCount < MAX_LINES)
    {
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0'; // remove newline character
        }
        questions[lineCount] = (char*)malloc(sizeof(char) * (len + 1));
        strcpy(questions[lineCount], buffer);
        lineCount++;
    }

    fclose(questionFile);
}

/**
 * fetches random numbers from a txt file and stores them in an array
*/
int randomNumberCount = 0;
char* randomNumbers[MAX_LINES];

void fetchRandomNumbers()
{
    FILE* file;
    char buffer[MAX_LENGTH];
    file = fopen("./game_qa/random_numbers.txt", "r");

    if (file == NULL)
    {
        printf("Error: could not open random numbers file\n");
        return;
    }

    while (fgets(buffer, MAX_LENGTH, file) != NULL && randomNumberCount < MAX_LINES)
    {
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0'; // remove newline character
        }
        randomNumbers[randomNumberCount] = (char*)malloc(sizeof(char) * (len + 1));
        strcpy(randomNumbers[randomNumberCount], buffer);
        randomNumberCount++;
    }
    fclose(file);
}

void generateRandomQuestion()
{
    int randomIndex = rand() % lineCount;
    question = strtok(questions[randomIndex], ",");
    answer = strtok(NULL, ",");
}

char* generateRandomNumber()
{
    int randomIndex = rand() % randomNumberCount;
    return randomNumbers[randomIndex];
}

void updatePlayerPos()
{
    while (kbhit())
    {
        char key = getch();
        if (key == 'a')
        {
            play.xPos -= 1;
        }
        if (key == 'd')
        {
            play.xPos += 1;
        }
    }
}

bool checkCollision(int xPos, int yPos)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if ((obstacles[i].xPos <= xPos && xPos < (obstacles[i].xPos + strlen(obstacles[i].value))) && (obstacles[i].yPos == yPos))
        {
            return true;
        }
    }
    return false;
}

void generateObstacles()
{
    int i;
    for (i = 0; i < 4; i++)
    {
        obstacles[i].value = generateRandomNumber();
        obstacles[i].xPos = rand() % 50 + 21;
        obstacles[i].yPos = rand() % 21 + 5;
        obstacles[i].isCorrectAnswer = false;
    }

    obstacles[4].value = answer;
    obstacles[4].xPos = rand() % 50 + 21;
    obstacles[4].yPos = rand() % 21 + 5;
    obstacles[4].isCorrectAnswer = true;
}

bool checkWin(int xPos, int yPos)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if ((obstacles[i].xPos <= xPos && xPos < (obstacles[i].xPos + strlen(obstacles[i].value))) && (obstacles[i].yPos == yPos))
        {
            return obstacles[i].isCorrectAnswer;
        }
    }
    return false;
}

void renderObstacleStats()
{
    int i;
    for (i = 0; i < 5; i++) 
    {
        gotoxy(2, (5 + i));
        printf("x: %d y: %d", obstacles[i].xPos, obstacles[i].yPos);
    }
}


int main(int argc, char* argv[])
{
    srand(time(NULL));
    fetchGameQuestions();
    fetchRandomNumbers();
    printf("\e[?25l"); // Makes cursor invisible
    play.profile = '#';

    bool gameOn = true;
    int i;
    while (gameOn)
    {
        play.xPos = 45;
        play.yPos = 0;
        generateRandomQuestion();
        generateObstacles();
        for (i = 0; i < 25; i++)
        {
            system("cls");
            play.yPos = i;
            renderScreen();
            updatePlayerPos();
            if (checkCollision(play.xPos, play.yPos))
            {
                break;
            }
            Sleep(700);
        }
        if (checkWin(play.xPos, play.yPos))
        {
            system("cls");
            playerScore++;
        }
        else
        {
            system("cls");
            playerLives--;
            if (playerLives < 0)
            {
                gameOn = false;
            }
        }
    }
    system("cls");
    printf("GAME OVER!\n");
	


    // Free dynamically allocated memory
    for (i = 0; i < lineCount; i++)
    {
        free(questions[i]);
    }
    for (i = 0; i < randomNumberCount; i++)
    {
        free(randomNumbers[i]);
    }

    printf("\e[?25h"); // Makes cursor visible
    gotoxy(25, 50);
    return 0;
}



