#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fetchFile(char* filepath);
void printTable();

int main(int argc, char const *argv[])
{
//    if (argc != 2)
//    {
//        printf("Usage: readCSV <csv_file>\n");
//        exit(1);
//    }

    fetchFile("./qar_level_one - Sheet1 (2).csv");
    printTable();
    return 0;
}

void levelFilePath()
{
	
	char *filepath[3] = {"./csv_files/qar_level_one - Sheet1 (2).csv",
					  "./csv_files/qar_level_two - Sheet1.csv",
					  "./csv_files\qar_level_three - Sheet1.csv",					
						}
						
						
	
	
}


#define BUFFER_SIZE 1024
// typedef struct {
//     char *question;
//     char *answer;
//     char *randomNumbers[];
// } question;

// question questions[100];

int MAX_LINES = 0;
char *table[100][3];

void fetchFile(char* filepath)
{
    FILE *pFile;
    char buffer[BUFFER_SIZE];

    pFile = fopen(filepath, "r");

    if (pFile == NULL)
    {
        printf("Error: opening file %s\n", filepath);
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, pFile))
    {
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
        char *token;
        token = strtok(buffer, ",");
        int i = 0;
        while (token != NULL)
        {
            table[MAX_LINES][i] = malloc((sizeof(char) * strlen(token))); 
            strcpy(table[MAX_LINES][i], token);
            token = strtok(NULL, ",");
            i++;
        }
        MAX_LINES++;
    }
    fclose(pFile);
}

void freeTable()
{
    int i, j;
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 3; j++)
        {
            free(table[i][j]);
        }
    }
}


void printTable()
{
    int i, j;
    // char *labels[3] = {"Question", "Answer", "Random Numbers"};

    // printf("%-15s %-15s %-15s\n", labels[0], labels[1], labels[2]);
    for (i = 0; i < MAX_LINES; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%-15s ", table[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < MAX_LINES; i++)
    {
        for (j = 0; j < 3; j++)
        {
            free(table[i][j]);
        }
    }
}
