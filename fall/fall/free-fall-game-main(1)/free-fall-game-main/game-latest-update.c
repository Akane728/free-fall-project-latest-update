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

int obstaclesPerLevel[3] = { 5, 7, 8 }; // Number of obstacles per level

char* questions[100];
char* question;
char* answer;
obstacle obstacles[10]; // Increased the size to accommodate maximum obstacles in a level
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
    for (i = 0; i < obstaclesPerLevel[gameLevel - 1]; i++)
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

void renderLevel()
{
    gotoxy(2, 5);
    printf("Level: %d", gameLevel);
}

void renderScreen()
{
    renderBorders();
    renderPlayer();
    renderLevel();
    renderGameQuestion();
    renderPlayerLives();
    renderGameScore();
    renderObstacles();
}

#define MAX_LINES 100
#define MAX_LENGTH 100
char* questions[MAX_LINES];
int lineCount = 0; // MAX NUMBER OF LINES IN THE TEXT FILE

int randomNumberCount = 0;
char* randomNumbers[MAX_LINES];

/**
 * Grab questions from a csv file or can be a text file
*/

void fetchGameQuestions(int level)
{
    char filenames[3][MAX_LENGTH] = { {"./game_qa/game_questions.csv"},
                                      {"./game_qa/game_questions2.csv"},
                                      {"./game_qa/game_questions3.csv"} };
    char buffer[MAX_LENGTH];
    FILE* questionFile;

    level = (level > 3) ? 3 : level;

    questionFile = fopen(filenames[level-1], "r");
    if (questionFile == NULL)
    {
        printf("Error: could not open file. \n");
        return;
    }

    lineCount = 0; // Update global variable

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

/*
void fetchRandomNumbers()
{
    FILE* file;
    char buffer[MAX_LENGTH];
    
    char filenamesrandom[3][MAX_LENGTH] = { {"./game_qa/game_questions.csv"},
                                      {"./game_qa/game_questions2.csv"},
                                      {"./game_qa/game_questions3.csv"} };
    file = fopen("./game_qa/random_numbers.txt", "r");

    if (file == NULL)
    {
        printf("Error: could not open random numbers file\n");
        return;
    }

    randomNumberCount = 0; // Update global variable

    // Read the entire line containing the random numbers
    if (fgets(buffer, MAX_LENGTH, file) != NULL)
    {
        // Tokenize the line using space as the delimiter
        char* token = strtok(buffer, " ");
        while (token != NULL && randomNumberCount < MAX_LINES)
        {
            int len = strlen(token);
            if (len > 0 && token[len - 1] == '\n')
            {
                token[len - 1] = '\0'; // remove newline character
            }
            randomNumbers[randomNumberCount] = (char*)malloc(sizeof(char) * (len + 1));
            strcpy(randomNumbers[randomNumberCount], token);
            randomNumberCount++;
            token = strtok(NULL, " ");
        }
    }

    fclose(file);
}

*/

void fetchRandomNumbers(int level)
{
    char filenames[3][MAX_LENGTH] = {
        {"./game_qa/random_numbers.txt"},
        {"./game_qa/random_numbers2.txt"},
        {"./game_qa/random_numbers3.txt"}
    };

    FILE* file;
    char buffer[MAX_LENGTH];
    
    level = (level > 3) ? 3 : level;

    file = fopen(filenames[level - 1], "r");
	
	if (file == NULL)
    {
        printf("Error: could not open random numbers file\n");
        return;
    }

    randomNumberCount = 0; // Update global variable

    // Read the entire line containing the random numbers
    if (fgets(buffer, MAX_LENGTH, file) != NULL)
    {
        // Tokenize the line using space as the delimiter
        char* token = strtok(buffer, " ");
        while (token != NULL && randomNumberCount < MAX_LINES)
        {
            int len = strlen(token);
            if (len > 0 && token[len - 1] == '\n')
            {
                token[len - 1] = '\0'; // remove newline character
            }
            randomNumbers[randomNumberCount] = (char*)malloc(sizeof(char) * (len + 1));
            strcpy(randomNumbers[randomNumberCount], token);
            randomNumberCount++;
            token = strtok(NULL, " ");
        }
    }
//    if (file == NULL)
//    {
//        printf("Error: could not open random numbers file\n");
//        return;
//    }
//
//    randomNumberCount = 0; // Update global variable

//    while (fgets(buffer, MAX_LENGTH, file) != NULL && randomNumberCount < MAX_LINES)
//    {
//        int len = strlen(buffer);
//        if (len > 0 && buffer[len - 1] == '\n')
//        {
//            buffer[len - 1] = '\0'; // remove newline character
//        }
//        randomNumbers[randomNumberCount] = (char*)malloc(sizeof(char) * (len + 1));
//        strcpy(randomNumbers[randomNumberCount], buffer);
//        randomNumberCount++;
//    }

    fclose(file);
}




void generateRandomQuestion()
{
    int randomIndex = rand() % lineCount;
    char *questionStr = strtok(questions[randomIndex], ",");
    char *answerStr = strtok(NULL, ",");
    if (question != NULL)
    {
        free(question);
    } 
    question = malloc(sizeof(char) * (strlen(questionStr) + 1));
    strcpy(question, questionStr);
    if (answer != NULL)
    {
        free(answer);
    } 
    answer = malloc(sizeof(char) * (strlen(answerStr) + 1));
    strcpy(answer, answerStr);
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
    for (i = 0; i < obstaclesPerLevel[gameLevel - 1]; i++)
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
    for (i = 0; i < obstaclesPerLevel[gameLevel - 1] - 1; i++)
    {
        obstacles[i].value = generateRandomNumber();
        obstacles[i].xPos = rand() % (BOARDWIDTH - strlen(obstacles[i].value) - BOARDXPOS) + BOARDXPOS;
        obstacles[i].yPos = rand() % (BOARDHEIGHT - BOARDYPOS) + BOARDYPOS;
        obstacles[i].isCorrectAnswer = false;
    }

    obstacles[obstaclesPerLevel[gameLevel - 1] - 1].value = answer;
    obstacles[obstaclesPerLevel[gameLevel - 1] - 1].xPos = rand() % (BOARDWIDTH - strlen(obstacles[obstaclesPerLevel[gameLevel - 1] - 1].value) - BOARDXPOS) + BOARDXPOS;
    obstacles[obstaclesPerLevel[gameLevel - 1] - 1].yPos = rand() % (BOARDHEIGHT - BOARDYPOS) + BOARDYPOS;
    obstacles[obstaclesPerLevel[gameLevel - 1] - 1].isCorrectAnswer = true;
}

bool checkWin(int xPos, int yPos)
{
    int i;
    for (i = 0; i < obstaclesPerLevel[gameLevel - 1]; i++)
    {
        if ((obstacles[i].xPos <= xPos && xPos < (obstacles[i].xPos + strlen(obstacles[i].value))) && (obstacles[i].yPos == yPos))
        {
            return obstacles[i].isCorrectAnswer;
        }
    }
    return false;
}

void increaseGameSpeed()
{
    if (gameLevel == 2)
    {
        Sleep(500);
    }
    else if (gameLevel == 3)
    {
        Sleep(300);
    }
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    
    // Call fetchGameQuestions for each CSV file
    fetchGameQuestions(1); // for level 1
	//fetchGameQuestions(2); // for level 2
	//fetchGameQuestions(3); // for level 3

    fetchRandomNumbers(1);
    
    //printf("\e[?25l"); // Makes cursor invisible
    play.profile = '#';
    bool gameOn = true;
    int i;
    while (gameOn)
    {
        play.xPos = 45;
        play.yPos = 0;
        generateRandomQuestion();
        generateObstacles();

        if (gameLevel == 2) 
        {
            for (i = 0; i < obstaclesPerLevel[gameLevel - 1] - 1; i++) 
            {
                obstacles[i].value = strdup(generateRandomNumber());
            }
        }

        for (i = 0; i < 25; i++)
        {
            system("cls");
            play.yPos = i;
            renderScreen();
            renderLevel();
            updatePlayerPos();
            if (checkCollision(play.xPos, play.yPos))
            {
                break;
            }
            Sleep(700);
            increaseGameSpeed();
        }

        if (checkWin(play.xPos, play.yPos))
        {
            system("cls");
            playerScore++;
            gameLevel++;
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
    if (playerLives < 0)
    {
        printf("GAME OVER!\n");
    }
    else
    {
        printf("Level completed!\n");
        printf("Press any key to continue to the next level...");
        getch();
    }

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
