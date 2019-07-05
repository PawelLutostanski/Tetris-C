#include "file.h"

void savingScore(char newPlayerName[15], int newScore)
{
	char namesCopy[TOP_PLAYERS][15];
	 int scoresCopy[TOP_PLAYERS];
	FILE* input = fopen("leaderboard.txt", "r"); // read only
	if (!input){
		FILE* write = fopen("leaderboard.txt", "w");
		fprintf(write, "%d\n%s", newScore, newPlayerName);
		fclose(write);
		return;
	}
	char scoreLine[LINE_SIZE];
	char nameLine[LINE_SIZE];
	int i,j;
	for (i = 0; i < TOP_PLAYERS; i++){//setting arrays
		scoresCopy[i] = -1;
		for (j = 0; j < 15; j++){
			if (j == 14) namesCopy[i][j] = '\0';
			else namesCopy[i][j] = ' ';
		}
	}
	for (i = 0; i < TOP_PLAYERS; i++){//copy file to array
		char* line1ptr = fgets(scoreLine, LINE_SIZE, input);
		char* line2ptr = fgets( nameLine, LINE_SIZE, input);
		if (input==0||line1ptr==NULL||line2ptr==NULL) {
			namesCopy[i][0] = '-';
			scoresCopy[i]=-1;//information to not put it to file
		}
		else {
			scoreLine[14] = '\0';
			scoresCopy[i] = atoi(scoreLine, '\n');
			nameLine[14] = '\0';
			strcpy(namesCopy[i], nameLine);
		}
	}
	fclose(input);
	FILE* output = fopen("leaderboard.txt", "w");
	int newScorePut = 0;
	for (i=0; i<TOP_PLAYERS; i++){	
		if ( ( newScorePut== 0) && (newScore > scoresCopy[i])){
			fprintf(output,"%d\n%s",newScore,newPlayerName);
			newScorePut = 1;
		}
		else{
			if (scoresCopy[i - newScorePut] != -1) {
				fprintf(output, "%d\n%s", scoresCopy[i - newScorePut], namesCopy[i - newScorePut]);
			}
		}
	}
	fclose(output);
}

void displayBlank(int i, int j,int k)
{
	char c = '-';
	int number = 0;
	printf("%d .   %15c", k, c);
	gotoxy(i + 29, j - 1);
	printf("%12d\n", number);
}

void showLeaderboard(int i, int j)
{
	system("cls");
	gotoxy(i + 5, j - 5);
	printf("LEADERBOARD   Top %d", TOP_PLAYERS);
	int k;
	FILE * input = fopen("leaderboard.txt", "r");
	if (!input) {
		for(k=1;k<TOP_PLAYERS+1;k++)
		{
			gotoxy(i, j++);
			displayBlank(i, j, k);
		}
		return;
	}
	char scoreLine[LINE_SIZE];
	char nameLine[LINE_SIZE];
	
	for (k = 1; k < TOP_PLAYERS + 1; k++)
	{
		char*line1ptr = fgets(scoreLine, LINE_SIZE, input);
		char*line2ptr = fgets(nameLine, LINE_SIZE, input);
		if (input == 0 || line1ptr == NULL || line2ptr == NULL) 
		{
			gotoxy(i, j++);
			displayBlank(i, j, k);
		}
		else {
			gotoxy(i, j++);
				int score = atoi(scoreLine, NULL);
				char* name = nameLine;
				printf("%d .   %15s", k, name);
				gotoxy(i + 29, j - 1);
				printf("%12d\n", score);
		}
	}
	gotoxy(i - 3, j + 2);
	Sleep(2500);
	printf("Press ENTER, SPACE or ESCAPE in order to return to menu  ");
	fclose(input);
}
