#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <conio.h>

void showMainMenu();
void startGame();
void showHighScore();
void showInstructions();
void showAuthors();
void showCustomization();

//Technicals
int newlineENtab();
void press();
void con();
int selectOPTION();
int playGame(int argc, char* argv[]); 

void gotoxy(int eex, int eey){
	COORD h;
	h.X = eex;
	h.Y = eey;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), h);
}

int main(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	system("COLOR F0");
	showMainMenu();
}

void showMainMenu(){
	int b, y=1;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for(;;){
	    system("cls");
		system("COLOR F0");
		for(b=0;b<30;b++){
			gotoxy(20,b);
			SetConsoleTextAttribute(h,240);	printf("Û");
			gotoxy(100,b);
			SetConsoleTextAttribute(h,240);	printf("Û");
		}
		for(b=0;b<5;b++){
			gotoxy(58,b);
			SetConsoleTextAttribute(h,240);	printf("Ü");
			gotoxy(62,b);
			SetConsoleTextAttribute(h,240);	printf("Ü");
		}
		for(b=3;b<8;b++){
			gotoxy(55,b);
			SetConsoleTextAttribute(h,240);	printf("Ü");
			gotoxy(65,b);
			SetConsoleTextAttribute(h,240);	printf("Ü");
		}
		newlineENtab(3, 3);  SetConsoleTextAttribute(h,240);	printf(" ÜÜÜÜÜÜ  ÜÜÜÜÜÜÜ   ÜÜÜÜÜÜÜ  ÜÜÜÜÜÜÜ      ÜÜÜÜÜÜ  ÜÜÜÜÜÜÜ  ÜÜÜ      ÜÜÜ");
		newlineENtab(1, 3);	 SetConsoleTextAttribute(h,240);	printf(" ÛÛÛÜÜÜ  ÛÛ   ÛÛ   ÛÛÛÜÜÜÜ  ÛÛÛÜÜÜÜ      ÛÛÛÜÜÜ  ÛÛ   ÛÛ  ÛÛÛ      ÛÛÛ");
		newlineENtab(1, 3);	 SetConsoleTextAttribute(h,240);	printf(" ÛÛÛ     ÛÛÛÜÛßß   ÛÛÛ      ÛÛÛ          ÛÛÛ     ÛÛÛÛÛÛÛ  ÛÛÛ      ÛÛÛ");
		newlineENtab(1, 3);	 SetConsoleTextAttribute(h,240);	printf(" ßßß     ßßß  ßß   ßßßßßßß  ßßßßßßß      ßßß     ßßß  ßß  ßßßßßßß  ßßßßßßß");
		
		newlineENtab(3, 7);		selectOPTION(1,y); printf("   PLAY"); //system("COLOR F4");
		newlineENtab(2, 7);		selectOPTION(2,y); printf("HIGH SCORE"); 
		newlineENtab(2, 6);		selectOPTION(3,y); printf("       INSTRUCTIONS"); //system("COLOR F0"); 
	    newlineENtab(2, 7);		selectOPTION(4,y); printf("  AUTHORS");
	    newlineENtab(2, 6);		selectOPTION(5,y); printf("    USER CUSTOMIZATION");
	    newlineENtab(2, 7);		selectOPTION(6,y); printf(" Exit Game");
	    newlineENtab(2, 5);		SetConsoleTextAttribute(h,240); printf("      Use "); SetConsoleTextAttribute(h,243); printf("[W] "); SetConsoleTextAttribute(h,240); printf("& "); SetConsoleTextAttribute(h,243);printf("[S] "); SetConsoleTextAttribute(h,240); printf("buttons to navigate");  
	    fflush(stdin);
	    int pressbutton = getch();
		
		if (pressbutton == 's' || pressbutton == 80){	// down button or down arrow
		    y = (y == 6) ? 1 : y + 1;	// teleport from last button to the first
		} else if (pressbutton == 'w' || pressbutton == 72){	// up button or up arrow
		    y = (y == 1) ? 6 : y - 1;	// teleport from first button to the last
		}
			
		if (pressbutton == 13){	// Return Carriage Button or Enter Button
		    break;	// terminates for loop;
		}
	}
	if(y==1){
		startGame();	
	}else if(y==2){
		showHighScore();
	}else if(y==3){
		showInstructions();	 
	}else if(y==4){
		showAuthors();		
	}else if(y==5){
		con();
	}else if(y==6){
		con();
	}
}
void startGame(int argc, char* argv[]){
	system("cls");
		
	playGame(argc, argv);	
	press();
	showMainMenu();
}
void showHighScore(){
	system("cls");
	press();
	showMainMenu();
}
void showInstructions(){
	system("cls");
	newlineENtab(3, 2); printf("LIVES"); 
	newlineENtab(1, 2); printf("   The player is initially given three lives to play with.");
	newlineENtab(1, 2); printf("       - When the player makes a mistake in solving a mathematical problem, they lose a life"); 
	newlineENtab(1, 2); printf("       - If the player runs out of lives, the game ends and they have to restart from the beginning"); 
	newlineENtab(1, 2); printf("     * Lives are a limited resource that the player must manage carefully throughout the game");
	
	newlineENtab(2, 2); printf("However, as the player progresses to higher difficulty levels, the number of lives they "); 
	newlineENtab(1, 2); printf("have also increases. This means that as the challenges become harder, the player is given ");
	newlineENtab(1, 2); printf("more chances to overcome them. Having more lives increases the player's chances of success,");
	newlineENtab(1, 2); printf("as they can afford to make mistakes without having to restart the game from the beginning. ");
	
	newlineENtab(3, 2); printf("DIFFICULTY"); 
	newlineENtab(1, 2); printf("   The player must navigate through a virtual environment while solving mathematical problems.");
	newlineENtab(1, 2); printf("       - As the difficulty level increases, the player must overcome more obstacles");
	newlineENtab(1, 2); printf("       - The speed of the freefalling object in the game increases as the player ");
	newlineENtab(1, 2); printf("         progresses to higher levels of difficulty");
	
	newlineENtab(3, 2); printf("POWERUPS"); 
	newlineENtab(1, 2); printf("   \"Reveal\" power-up: When the player collects this power-up, the correct answer to the ");
	newlineENtab(1, 2); printf("                        mathematical problem they are currently solving will be revealed to them.");
	newlineENtab(1, 2); printf("       - can be useful if the player is struggling to find the correct");
	newlineENtab(1, 2); printf("         answer or if they are running out of time");
	newlineENtab(1, 2); printf("   \"Slow down\" power-up: When the player collects this power-up, the speed of");
	newlineENtab(1, 2); printf("                           the game's object (free falling ob) will slow down");
	newlineENtab(1, 2); printf("       - allows the player to have more time to avoid obstacles or solve mathematical problems,");
	newlineENtab(1, 2); printf("         making iteasier to progress through the game");
	
	newlineENtab(3, 2); printf("NAVIGATION"); 
	newlineENtab(1, 2); printf("   The player must avoid obstacles (wrong answers) and collect items (correct");
	newlineENtab(1, 2); printf("   answers) while navigating through the virtual environment");
	newlineENtab(1, 2); printf("       - If the player collides with an obstacle, they will lose a life");
	newlineENtab(1, 2); printf("       - If the player successfully collects an item, their score will increase");
	newlineENtab(1, 2); printf("     * The player must also keep the object from hitting the wall or other objects in the game");
	
	newlineENtab(3, 2); printf("CONTROLS"); 
	newlineENtab(1, 2); printf("   Arrow keys - the player can maneuver the object to the left or right");
	newlineENtab(1, 2); printf("     Spacebar - used to pause the game and the escape key can be used to exit the game");
	
	press();
	showMainMenu();
}
void showAuthors(){
	system("cls");
	press();
	showMainMenu();
}

void showCustomization(){
	system("cls");
	press();
	showMainMenu();
}

//technicals
int newlineENtab(int x, int y){	
	int newline,tab;
		for (newline=0;newline<=x-1;newline++)
				printf("\n");
		for (tab=0;tab<=y-1;tab++)
				printf("\t");
}

void press(){
	newlineENtab(4, 6);		printf("Press any key to continue..");
							getch();
}

void con(){
	char cont;
	system("cls");
	newlineENtab(4, 5);		printf("   Are you sure you want to exit?");
	newlineENtab(2, 5);		printf("   [Y] Yes");
	newlineENtab(0, 2);		printf("   [N] No");
	newlineENtab(1, 7);		cont=getche();
  	
	switch(toupper(cont)){
  		case 'Y':
  			system("cls");
			newlineENtab(5, 5);	  	printf("Thank you");
  									exit(0);
  		case 'N':			
  			showMainMenu();
  		default:
  			system("cls");
  			newlineENtab(2, 2);		printf("Wrong key. Try again.");
  									con();
   	}
}

int selectOPTION(int x, int y){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if(x==y){
		SetConsoleTextAttribute(h,243); 
	}else{
		SetConsoleTextAttribute(h,240); 
	}
	return 0;
}
#define MAX_LINES 100
#define MAX_LENGTH 100
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

typedef struct {
	int level;
	int numberOfQuestions;
	int obstacleCount;
} level;

int BOARDHEIGHT = 29;
int BOARDWIDTH = 50;
int BOARDXPOS = 30;
int BOARDYPOS = 0;

int playerScore = 0;
int playerLives = 3;
// initialize the starting level of the game

int obstaclesPerLevel[3] = { 5, 7, 10 }; // Number of obstacles per level

char* questions[100];
char* question;
char* answer;

level levels[3];



obstacle obstacles[10]; // Increased the size to accommodate maximum obstacles in a level
player play;

/**
 * Function for rendering/printing borders of the game
*/
void renderBorders()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int i;
    for (i = 0; i < BOARDHEIGHT; i++)
    {
    	SetConsoleTextAttribute(h,240);
        printf("Û");
        gotoxy(BOARDXPOS, i);
        SetConsoleTextAttribute(h,240);
        printf("Û");
        gotoxy((BOARDXPOS + BOARDWIDTH), i);
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

void renderObstacles(int x)
{
    int i;
    for (i = 0; i < x; i++)
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

void renderLevel(int level)
{
    gotoxy(2, 5);
    printf("Level: %d", level);
}

void renderScreen(int obstacleCount, int level)
{
    renderBorders();
    renderPlayer();
    renderLevel(level);
    renderGameQuestion();
    renderPlayerLives();
    renderGameScore();
    renderObstacles(obstacleCount);
}


char* questions[MAX_LINES];
int lineCount = 0; // MAX NUMBER OF LINES IN THE TEXT FILE

int randomNumberCount = 0;
char* randomNumbers[MAX_LINES];
/**
 * Grab questions from a csv file or can be a text file
*/

void fetchGameQuestions(int level)
{
    char *filenames[3] = {"./game_qa/game_questions.csv",
                        "./game_qa/game_questions2.csv",
                        "./game_qa/game_questions3.csv"};
    char buffer[MAX_LENGTH];
    FILE* questionFile;

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
        questions[lineCount] = malloc(sizeof(char) * (len + 1));
        strcpy(questions[lineCount], buffer);
        lineCount++;
    }

    fclose(questionFile);
}


void freeGameQuestions()
{
	int i;
	for (i = 0; i < MAX_LINES; i++)
	{
		free(questions[i]);
	}
}
/**
 * fetches random numbers from a txt file and stores them in an array
*/

void fetchRandomNumbers(int level)
{
    char filenames[3][MAX_LENGTH] = {
        "./game_qa/random_numbers.txt",
        "./game_qa/random_numbers2.txt",
        "./game_qa/random_numbers3.txt"
    };

    FILE* file;
    char buffer[MAX_LENGTH];
    
//    level = (level > 3) ? 3 : level;

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
            randomNumbers[randomNumberCount] = malloc(sizeof(char) * (len + 1));
            strcpy(randomNumbers[randomNumberCount], token);
            randomNumberCount++;
            token = strtok(NULL, " ");
        }
    }

    fclose(file);
}

void freeRandomNumbers()
{
	int i;
	for (i = 0; i < MAX_LINES; i++)
	{
		free(randomNumbers[i]);
	}
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

void createLevels()
{
	levels[0].level = 1;
	levels[0].numberOfQuestions = 5;
	levels[0].obstacleCount = 5;
	
	levels[1].level = 2;
	levels[1].numberOfQuestions = 7;
	levels[1].obstacleCount = 7;
	
	levels[2].level = 3;
	levels[2].numberOfQuestions = 10;
	levels[2].obstacleCount = 10;	
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


bool checkCollision(int xPos, int yPos, int obstacleCount)
{
    int i;
    for (i = 0; i < obstacleCount; i++)
    {
        if ((obstacles[i].xPos <= xPos && xPos < (obstacles[i].xPos + strlen(obstacles[i].value))) && (obstacles[i].yPos == yPos))
        {
            return true;
        }
    }
    return false;
}

void generateObstacles(int n)
{
    int i;
    for (i = 0; i < (n - 1); i++)
    {
        obstacles[i].value = generateRandomNumber();
        obstacles[i].xPos = rand() % (BOARDWIDTH - strlen(obstacles[i].value) - BOARDXPOS) + BOARDXPOS;
        obstacles[i].yPos = rand() % (BOARDHEIGHT - BOARDYPOS) + BOARDYPOS;
        obstacles[i].isCorrectAnswer = false;
    }

    obstacles[n - 1].value = answer;
    obstacles[n - 1].xPos = rand() % (BOARDWIDTH - strlen(obstacles[n - 1].value) - BOARDXPOS) + BOARDXPOS;
    obstacles[n - 1].yPos = rand() % (BOARDHEIGHT - BOARDYPOS) + BOARDYPOS;
    obstacles[n - 1].isCorrectAnswer = true;
}

bool checkWin(int xPos, int yPos, int obstacleCount)
{
    int i;
    for (i = 0; i < obstacleCount; i++)
    {
        if ((obstacles[i].xPos <= xPos && xPos < (obstacles[i].xPos + strlen(obstacles[i].value))) && (obstacles[i].yPos == yPos))
        {
            return obstacles[i].isCorrectAnswer;
        }
    }
    return false;
}

void increaseGameSpeed(int level)
{
	
    if (level == 2)
    {
        Sleep(500);
    }
    else if (level == 3)
    {
        Sleep(300);
    }
}

/*
int playGame(int argc, char* argv[])
{
    srand(time(NULL));
	
	fetchGameQuestions(1);
	fetchRandomNumbers(1);
	fetchGameQuestions(2);
	fetchRandomNumbers(2);	
	fetchGameQuestions(3);
	fetchRandomNumbers(3);

    printf("\e[?25l"); // Makes cursor invisible
    play.profile = '#';
    bool gameOn = true;
    int i;
    while (gameOn)
    {
    
        play.xPos = 45;
        play.yPos = 0;
        int GRA = generateRandomQuestion();
        int GO = generateObstacles();
        
        int countRandomQA = 0;
        int countObstacles = 0;
        
        for ()
		
	
		
        if (gameLevel == 2) 
        {
            for (i = 0; i < obstaclesPerLevel[gameLevel - 1] - 1; i++) 
            {
                obstacles[i].value = strdup(generateRandomNumber());
            }
        }
        
//        if (gameLevel == 3) 
//        {
//            for (i = 0; i < obstaclesPerLevel[gameLevel - 1] - 1; i++) 
//            {
//                obstacles[i].value = strdup(generateRandomNumber());
//            }
//        }

        for (i = 0; i < 29; i++)
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
//            gameLevel++;
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
*/


int playGame(int argc, char* argv[])
{
    srand(time(NULL));

    //printf("\e[?25l"); // Makes cursor invisible
    play.profile = '#';
    bool gameOn = true;
    int i;
    int gameLevel; 
	playerLives = 3; // Initialize game level

	int questionCount;
    int obstacleCount;
    
	
    
    while (gameOn)
    {
		play.xPos = 45;
	    play.yPos = 0;
	    	
		for ( gameLevel = 0; gameLevel < 3; gameLevel++)
		{
			printf("HELLO\n");
			int j;
			createLevels();
			for (j = 0; j < levels[gameLevel].numberOfQuestions; j++)
			{
				fetchGameQuestions(levels[gameLevel].level);
				fetchRandomNumbers(levels[gameLevel].level);
				generateRandomQuestion();
				generateObstacles(levels[gameLevel].obstacleCount);
			    for (i = 0; i < 29; i++)
			    {
			        system("cls");
			        play.yPos = i;
			        renderScreen(levels[gameLevel].obstacleCount, levels[gameLevel].level);
			        renderLevel(levels[gameLevel].level);
			        updatePlayerPos();
			        if (checkCollision(play.xPos, play.yPos, levels[gameLevel].obstacleCount))
			        {
			            break;
			        }
			        Sleep(700);
			        increaseGameSpeed(levels[gameLevel].level);
			    }
		
		        if (checkWin(play.xPos, play.yPos, levels[gameLevel].obstacleCount))
		        {
		            system("cls");
		            playerScore++;
		        }
		        else
		        {
		            system("cls");
		            playerLives--;
		            
		    	}
				if (playerLives <= 0)
	            {
	            	printf("GAME OVER!\n");
	            	break;
	                gameOn = false;
	            }
				    
				        
		        
			    system("cls");
			    // Free dynamically allocated memory
			    freeGameQuestions();
			    freeRandomNumbers();
			
			    gotoxy(25, 50);	
			}
			if (playerLives <= 0)
			{
				break;
			}
			printf("Level completed!\n");
	        printf("Press any key to continue to the next level...");
	        getch();
		      
	    }
    }

  

    // Remaining code...

    return 0;
}

