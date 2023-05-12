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
void adminCustomization();
void logIn();
void customize();

void fetchFilePath(char* filePath, int level);
void fetchGameQuestions(char* filePath);
void fetchAnswers(char* filePath);
void fetchRandomNumbers(char* filePath);


//Technicals
int newlineENtab();
void press();
void con();
int selectOPTION();


void gotoxy(int eex, int eey){
	COORD h;
	h.X = eex;
	h.Y = eey;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), h);
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
		//startGame();	
	}else if(y==2){
		showHighScore();
	}else if(y==3){
		showInstructions();	 
	}else if(y==4){
		showAuthors();		
	}else if(y==5){
		showCustomization();
	}else if(y==6){
		con();
	}
}
void startGame(int argc, char* argv[]){
	system("cls");
		
	//playGame(argc, argv);	
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
	adminCustomization();
	press();
	showMainMenu();
}

void logIn()
{
    char name[256];
    char password[256];

    char inputName[256];
    char inputPassword[256];
    
    system("cls");

    newlineENtab(5, 5);		printf("Please enter your username: ");
    						scanf("%s", inputName);
    
    FILE *adminNamesChecker = fopen("./admin_credentials/admin_credential.csv", "r");
    if (!adminNamesChecker)
    {
        newlineENtab(2, 5);		printf("Error opening file.\n");
        return;
    }

    int found = 0;
    while (fscanf(adminNamesChecker, "%255[^,],%255[^\n]", name, password) == 2)
    {
        if (strcmp(inputName, name) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(adminNamesChecker);

    if (found == 0)
    {
        newlineENtab(3, 5);		printf("Incorrect username.");
        return;
    }

    newlineENtab(2, 5);		printf("Please enter your password: ");
    						scanf("%s", inputPassword);

    FILE *adminPassChecker = fopen("./admin_credentials/admin_credential.csv", "r");
    if (!adminPassChecker)
    {
        newlineENtab(2, 5);		printf("Error opening file.\n");
        return;
    }

    found = 0;
    while (fscanf(adminPassChecker, "%255[^,],%255[^\n]", name, password) == 2)
    {
        if (strcmp(inputName, name) == 0 && strcmp(inputPassword, password) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(adminPassChecker);

    if (found == 0)
    {
        newlineENtab(2, 5);		printf("Incorrect password.");
        return;
    }

    newlineENtab(2, 5);		printf("Correct username and password!");

    newlineENtab(2, 5);		printf("ACCOUNT LOGGED IN!");

    newlineENtab(2, 5);		printf("Press any key to continue...");

    getchar();

    customize();

//    getchar();
    adminCustomization();	
}

void customize()
{
	system("cls");
	FILE *levelOne;
	FILE *levelTwo;
	FILE *levelThree;
	
	char question[256];
	char answer[256];
	char randomNumber[256];
	int count = 0;

	int y=1;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1)
	{
		system("cls");
		newlineENtab(3, 5);		selectOPTION(1,y); printf(" LEVEL 1"); //system("COLOR F4");
		newlineENtab(2, 4);		selectOPTION(2,y); printf("	LEVEL 2"); 
		newlineENtab(2, 5);		selectOPTION(3,y); printf(" LEVEL 3");
		newlineENtab(2, 5);		selectOPTION(4,y); printf(" EXIT");
		
		newlineENtab(2, 4);		SetConsoleTextAttribute(h,240); printf("      Use "); 
		SetConsoleTextAttribute(h,243); printf("[W] "); 
		SetConsoleTextAttribute(h,240); printf("& "); 
		SetConsoleTextAttribute(h,243);printf("[S] "); 
		SetConsoleTextAttribute(h,240); printf("buttons to navigate");  
		fflush(stdin);
		    int pressbutton = getch();
			
			if (pressbutton == 's' || pressbutton == 80){	// down button or down arrow
			    y = (y == 4) ? 1 : y + 1;	// teleport from last button to the first
			} else if (pressbutton == 'w' || pressbutton == 72){	// up button or up arrow
			    y = (y == 1) ? 4 : y - 1;	// teleport from first button to the last
			}
				
			if (pressbutton == 13){	// Return Carriage Button or Enter Button
			    break;	// terminates for loop;
			}	
	}
	if(y == 1)
	{
		
		while (1)
		{
			system("cls");
			newlineENtab(3, 5);		selectOPTION(1,y); printf(" ADD QUESTIONS WITH ANSWER AND RANDOM NUMBERS"); //system("COLOR F4");
			newlineENtab(2, 5);		selectOPTION(2,y); printf("	EXIT");
			
			newlineENtab(2, 5);		SetConsoleTextAttribute(h,240); printf("      Use "); 
			SetConsoleTextAttribute(h,243); printf("[W] "); 
			SetConsoleTextAttribute(h,240); printf("& "); 
			SetConsoleTextAttribute(h,243);printf("[S] "); 
			SetConsoleTextAttribute(h,240); printf("buttons to navigate");  
		    fflush(stdin);
		    int pressbutton = getch();
			
			if (pressbutton == 's' || pressbutton == 80){	// down button or down arrow
			    y = (y == 2) ? 1 : y + 1;	// teleport from last button to the first
			} else if (pressbutton == 'w' || pressbutton == 72){	// up button or up arrow
			    y = (y == 1) ? 2 : y - 1;	// teleport from first button to the last
			}
				
			if (pressbutton == 13){	// Return Carriage Button or Enter Button
			    break;	// terminates for loop;
			}	
		}
		if ( y == 1)
		{
			levelOne = fopen("./csv_files/qar_level_one - Sheet1 (2).csv", "a");
			if (levelOne == NULL) {
				printf("Error opening file.\n");
				return;
			}

			// Get question and answer from user
			printf("\nEnter a question (up to 255 characters): ");
			fgets(question, sizeof(question), stdin);
			question[strcspn(question, "\n")] = '\0'; // remove the newline character
			fprintf(levelOne, "%s,", question);
			printf("\nThe question is added!\n");

			printf("\nEnter the answer (up to 255 characters): ");
			fgets(answer, sizeof(answer), stdin);
			answer[strcspn(answer, "\n")] = '\0'; // remove the newline character
			fprintf(levelOne, "%s,", answer);
			printf("\nThe answer is added!\n");

			printf("Enter 6 random numbers separated by spaces: ");
		    fgets(randomNumber, sizeof(randomNumber), stdin);
		    randomNumber[strcspn(randomNumber, "\n")] = '\0'; // remove the newline character
		    
		    char *token = strtok(randomNumber, " "); // split the input string into tokens
		
		    while (token != NULL && count < 6) {
		        fprintf(levelOne, "%s;", token); // write each token (random number) followed by a semicolon
				token = strtok(NULL, " ");
		        count++;
		    }
		    fprintf(levelOne, "\n"); // add a newline character at the end of the line
		
		    printf("Random numbers added to the CSV file.\n");
		    
			fclose(levelOne);

			getch();
			customize();
		}
		if ( y == 2)
		{
			customize();
			getch();
		}
	}
		
	if( y == 2)
	{
		
		while (1)
		{
			system("cls");
			newlineENtab(3, 5);		selectOPTION(1,y); printf(" ADD QUESTIONS WITH ANSWER AND RANDOM NUMBERS"); //system("COLOR F4");
			newlineENtab(2, 5);		selectOPTION(2,y); printf("	EXIT");
			
			newlineENtab(2, 5);		SetConsoleTextAttribute(h,240); printf("      Use "); 
			SetConsoleTextAttribute(h,243); printf("[W] "); 
			SetConsoleTextAttribute(h,240); printf("& "); 
			SetConsoleTextAttribute(h,243);printf("[S] "); 
			SetConsoleTextAttribute(h,240); printf("buttons to navigate");  
		    fflush(stdin);
		    int pressbutton = getch();
			
			if (pressbutton == 's' || pressbutton == 80){	// down button or down arrow
			    y = (y == 2) ? 1 : y + 1;	// teleport from last button to the first
			} else if (pressbutton == 'w' || pressbutton == 72){	// up button or up arrow
			    y = (y == 1) ? 2 : y - 1;	// teleport from first button to the last
			}
				
			if (pressbutton == 13){	// Return Carriage Button or Enter Button
			    break;	// terminates for loop;
			}	
		}
		if ( y == 1)
		{
			levelTwo = fopen("./csv_files/qar_level_two - Sheet1.csv", "a");
			if (levelTwo == NULL) {
				printf("Error opening file.\n");
				return;
			}

			// Get question and answer from user
			printf("\nEnter a question (up to 255 characters): ");
			fgets(question, sizeof(question), stdin);
			question[strcspn(question, "\n")] = '\0'; // remove the newline character
			fprintf(levelTwo, "%s,", question);
			printf("\nThe question is added!\n");

			printf("\nEnter the answer (up to 255 characters): ");
			fgets(answer, sizeof(answer), stdin);
			answer[strcspn(answer, "\n")] = '\0'; // remove the newline character
			fprintf(levelTwo, "%s,", answer);
			printf("\nThe answer is added!\n");

			printf("Enter 6 random numbers separated by spaces: ");
		    fgets(randomNumber, sizeof(randomNumber), stdin);
		    randomNumber[strcspn(randomNumber, "\n")] = '\0'; // remove the newline character
		    
		    char *token = strtok(randomNumber, " "); // split the input string into tokens
		
		    while (token != NULL && count < 6) {
		        fprintf(levelTwo, "%s;", token); // write each token (random number) followed by a semicolon
				token = strtok(NULL, " ");
		        count++;
		    }
		    fprintf(levelTwo, "\n"); // add a newline character at the end of the line
		
		    printf("Random numbers added to the CSV file.\n");
		    
			fclose(levelTwo);

			getch();
			customize();
		}
		if ( y == 2)
		{
			customize();
			getch();
		}
	}
	if(y==3)
	{
		while (1)
		{
			system("cls");
			newlineENtab(3, 5);		selectOPTION(1,y); printf(" ADD QUESTIONS WITH ANSWER AND RANDOM NUMBERS"); //system("COLOR F4");
			newlineENtab(2, 5);		selectOPTION(2,y); printf("	EXIT");
			
			newlineENtab(2, 5);		SetConsoleTextAttribute(h,240); printf("      Use "); 
			SetConsoleTextAttribute(h,243); printf("[W] "); 
			SetConsoleTextAttribute(h,240); printf("& "); 
			SetConsoleTextAttribute(h,243);printf("[S] "); 
			SetConsoleTextAttribute(h,240); printf("buttons to navigate");  
		    fflush(stdin);
		    int pressbutton = getch();
			
			if (pressbutton == 's' || pressbutton == 80){	// down button or down arrow
			    y = (y == 2) ? 1 : y + 1;	// teleport from last button to the first
			} else if (pressbutton == 'w' || pressbutton == 72){	// up button or up arrow
			    y = (y == 1) ? 2 : y - 1;	// teleport from first button to the last
			}
				
			if (pressbutton == 13){	// Return Carriage Button or Enter Button
			    break;	// terminates for loop;
			}	
		}
		if ( y == 1)
		{
			levelThree = fopen("./csv_files/qar_level_two - Sheet1.csv", "a");
			if (levelThree == NULL) {
				printf("Error opening file.\n");
				return;
			}

			// Get question and answer from user
			printf("\nEnter a question (up to 255 characters): ");
			fgets(question, sizeof(question), stdin);
			question[strcspn(question, "\n")] = '\0'; // remove the newline character
			fprintf(levelThree, "%s,", question);
			printf("\nThe question is added!\n");

			printf("\nEnter the answer (up to 255 characters): ");
			fgets(answer, sizeof(answer), stdin);
			answer[strcspn(answer, "\n")] = '\0'; // remove the newline character
			fprintf(levelThree, "%s,", answer);
			printf("\nThe answer is added!\n");

			printf("Enter 6 random numbers separated by spaces: ");
		    fgets(randomNumber, sizeof(randomNumber), stdin);
		    randomNumber[strcspn(randomNumber, "\n")] = '\0'; // remove the newline character
		    
		    char *token = strtok(randomNumber, " "); // split the input string into tokens
		
		    while (token != NULL && count < 6) {
		        fprintf(levelThree, "%s;", token); // write each token (random number) followed by a semicolon
				token = strtok(NULL, " ");
		        count++;
		    }
		    fprintf(levelThree, "\n"); // add a newline character at the end of the line
		
		    printf("Random numbers added to the CSV file.\n");
		    
			fclose(levelThree);

			getch();
			customize();
		}
		if ( y == 2)
		{
			customize();
			getch();
		}
	}
	if ( y == 4)
	{
		adminCustomization();
		getch();
	}
}


void adminCustomization()
{
	int y=1;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	while (1)
	{
		system ("cls");
		
		newlineENtab(7, 7);		selectOPTION(1,y); printf("   LOG IN");
		newlineENtab(2, 7);		selectOPTION(2,y); printf("   EXIT");
		newlineENtab(4, 5);		SetConsoleTextAttribute(h,240); printf("      Use ");
		SetConsoleTextAttribute(h,243); printf("[W] "); 
		SetConsoleTextAttribute(h,240); printf("& "); 
		SetConsoleTextAttribute(h,243);printf("[S] "); 
		SetConsoleTextAttribute(h,240); printf("buttons to navigate");
		
		fflush(stdin);
	    int pressbutton = getch();
		
		if (pressbutton == 's' || pressbutton == 80){	// down button or down arrow
		    y = ( y == 2) ? 1 : y + 1;	// teleport from last button to the first
		} else if (pressbutton == 'w' || pressbutton == 72){	// up button or up arrow
		    y = ( y == 1) ? 2 : y - 1;	// teleport from first button to the last
		}
			
		if (pressbutton == 13){	// Return Carriage Button or Enter Button
		    break;	// terminates for loop;
		}
		
	}
	
	if ( y == 1)
	{
		logIn();
		getch();
	}
	if ( y == 2)
	{
		showMainMenu();
		getch();
	}
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
int BOARDYPOS = 5;

int playerScore = 0;
int playerLives = 3;

int MAX_LINES = 0;
char* table[100][3];

char* questions[MAX_LINES];
char* question;
char* answer;

#define MAX_ROW 256
#define MAX_COL 3
#define BUFFER_SIZE 1024
char* gameQuestionTable[MAX_ROW][MAX_COL];

int totalLines = 0;

level levels[3];

obstacle obstacles[10]; // Increased the size to accommodate maximum obstacles in a level
player play;

char* questions[MAX_LINES];
int lineCount = 0; // MAX NUMBER OF LINES IN THE TEXT FILE
//
int randomNumberCount = 0;
char* randomNumbers[MAX_LINES];

void fetchFilePath(char* filePath, int level)
{
    char questionPath[MAX_LENGTH];
    char answerPath[MAX_LENGTH];
    char randomNumberPath[MAX_LENGTH];

    snprintf(questionPath, sizeof(questionPath), "%s%d%s", filePath, level, "_questions.csv");
    snprintf(answerPath, sizeof(answerPath), "%s%d%s", filePath, level, "_answers.csv");
    snprintf(randomNumberPath, sizeof(randomNumberPath), "%s%d%s", filePath, level, "_random_numbers.csv");

    fetchGameQuestions(questionPath);
    fetchAnswers(answerPath);
    fetchRandomNumbers(randomNumberPath);
}

void fetchGameQuestions(char* filePath)
{
    FILE* questionFile;
    char buffer[MAX_LENGTH];

    questionFile = fopen(filePath, "r");
    if (questionFile == NULL)
    {
        printf("Error: could not open file %s\n", filePath);
        exit(1);
    }

    totalLines = 0;
    while (fgets(buffer, MAX_LENGTH, questionFile) != NULL && totalLines < MAX_LINES)
    {
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0'; // remove newline character
        }
        questions[totalLines] = malloc(sizeof(char) * (len + 1));
        strcpy(questions[totalLines], buffer);
        totalLines++;
    }

    fclose(questionFile);
}

void fetchAnswers(char* filePath)
{
    FILE* answerFile;
    char buffer[MAX_LENGTH];

    answerFile = fopen(filePath, "r");
    if (answerFile == NULL)
    {
        printf("Error: could not open file %s\n", filePath);
        exit(1);
    }

    totalLines = 0;
    while (fgets(buffer, MAX_LENGTH, answerFile) != NULL && totalLines < MAX_LINES)
    {
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0'; // remove newline character
        }
        table[totalLines][0] = malloc(sizeof(char) * (len + 1));
        strcpy(table[totalLines][0], buffer);
        totalLines++;
    }

    fclose(answerFile);
}

void fetchRandomNumbers(char* filePath)
{
    FILE* randomNumberFile;
    char buffer[MAX_LENGTH];

    randomNumberFile =     fopen(filePath, "r");
    if (randomNumberFile == NULL)
    {
        printf("Error: could not open file %s\n", filePath);
        exit(1);
    }

    totalLines = 0;
    while (fgets(buffer, MAX_LENGTH, randomNumberFile) != NULL && totalLines < MAX_LINES)
    {
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0'; // remove newline character
        }
        table[totalLines][1] = malloc(sizeof(char) * (len + 1));
        strcpy(table[totalLines][1], buffer);
        totalLines++;
    }

    fclose(randomNumberFile);
}

void freeTable()
{
    int i, j;
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 3; j++)
        {
            free(gameQuestionTable[i][j]);
        }
    }
}


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

/**
 * Grab questions from a csv file or can be a text file
*/


void freeGameQuestions()
{
	int i;
	for (i = 0; i < MAX_LINES; i++)
	{
		free(questions[i]);
	}
}

void generateRandomQuestion() {
    int randomIndex = rand() % MAX_LINES;
    char *questionStr = strtok(questions[randomIndex], ",");
    char *answerStr = strtok(NULL, ",");
    if (question != NULL) {
        free(question);
        question = NULL;
    }
    if (answer != NULL) {
        free(answer);
        answer = NULL;
    }
    question = malloc(sizeof(char) * (strlen(questionStr) + 1));
    strcpy(question, questionStr);
    answer = malloc(sizeof(char) * (strlen(answerStr) + 1));
    strcpy(answer, answerStr);
}

void generateObstacles(int n) {
    int i;
    for (i = 0; i < n; i++) {
        obstacles[i].value = fetchRandomNumbers(levels[gameLevel].level); // Assuming this function fetches the random numbers
        obstacles[i].xPos = rand() % (79 - strlen(obstacles[i].value) - 31) + 31;
        obstacles[i].yPos = rand() % (BOARDHEIGHT - BOARDYPOS) + BOARDYPOS;
        obstacles[i].isCorrectAnswer = (i == n - 1); // Set the last obstacle as the correct answer
    }
}

void freeRandomNumbers()
{
	int i;
	for (i = 0; i < MAX_LINES; i++)
	{
		free(randomNumbers[i]);
	}
}

void createLevels()
{
	levels[0].level = 1;
	levels[0].numberOfQuestions = 7;
	levels[0].obstacleCount = 7;
	
	levels[1].level = 2;
	levels[1].numberOfQuestions = 10;
	levels[1].obstacleCount = 10;
	
	levels[2].level = 3;
	levels[2].numberOfQuestions = 15;
	levels[2].obstacleCount = 15;	
}


void updatePlayerPos()
{
    while (kbhit())
    {
        char key = getch();
        if (key == 'a' || key == 75 )
        {
            play.xPos -= 1;
        }
        if (key == 'd' || key == 77)
        {
            play.xPos += 1;
        }
    }
    
	if(play.xPos <= 30) 
	{
		play.xPos = 31;
	}
	if(play.xPos >= 80) 
	{
		play.xPos = 79;
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

int gameSpeed(int level)
{
	
	if ( level == 1)
	{
		return 500;
	}
	if ( level == 2)
	{
		return 300;
	}
	if ( level == 3)
	{
		return 100;
	}
}

/*
int playGame(int argc, char* argv[])
{
    srand(time(NULL));

    //printf("\e[?25l"); // Makes cursor invisible
    play.profile = '#';
    bool gameOn = true;
    int i;
   
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
			        Sleep(gameSpeed(levels[gameLevel].level));
			        
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
	                gameOn = false;
	                break;
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
			playerLives+=3;
	        getch();
		      
	    }
    }

  

    // Remaining code...

    return 0;
}
*/

int playGame(int argc, char* argv[]) {
    srand(time(NULL));

    play.profile = '#';
    bool gameOn = true;
    int i;

    playerLives = 3; // Initialize game level

    while (gameOn) {
        play.xPos = 45;
        play.yPos = 0;

        for (int gameLevel = 0; gameLevel < 3; gameLevel++) {
            createLevels();
            for (int j = 0; j < levels[gameLevel].numberOfQuestions; j++) {
                fetchFilePath(argv[1], levels[gameLevel].level); // Assuming the file path is passed as a command line argument
                fetchGameQuestions(levels[gameLevel].level);
                fetchRandomNumbers(levels[gameLevel].level);

                generateRandomQuestion();
                generateObstacles(levels[gameLevel].obstacleCount);

                for (i = 0; i < 29; i++) {
                    system("cls");
                    play.yPos = i;
                    renderScreen(levels[gameLevel].obstacleCount, levels[gameLevel].level);
                    renderLevel(levels[gameLevel].level);
                    updatePlayerPos();
                    if (checkCollision(play.xPos, play.yPos, levels[gameLevel].obstacleCount)) {
                        break;
                    }
                    Sleep(gameSpeed(levels[gameLevel].level));
                }

                if (checkWin(play.xPos, play.yPos, levels[gameLevel].obstacleCount)) {
                    system("cls");
                    playerScore++;
                } else {
                    system("cls");
                    playerLives--;
                }

                if (playerLives <= 0) {
                    printf("GAME OVER!\n");
                    gameOn = false;
                    break;
                }

                system("cls");
                freeGameQuestions();
                freeRandomNumbers();

                gotoxy(25, 50);
            }

                        if (playerLives <= 0) {
                break;
            }

            printf("Level completed!\n");
            printf("Press any key to continue to the next level...");
            getch();
            playerLives += 3;
        }

        if (playerLives <= 0) {
            break;
        }
    }

    // Remaining code...

    return 0;
}


