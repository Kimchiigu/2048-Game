#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define GRID_SIZE_4X4 4
#define GRID_SIZE_6X6 6

// Declaration
char userId[100][5];
char username[100][16];
char score[100][100000];

// Menu
void menu() {
    printf("    ______             __            __    __   \n"
           "   /      \\           /  |          /  |  /  | \n"
           "  /$$$$$$  |  ______  $$ | __    __ $$ |  $$ |  \n"
           "  $$ |  $$/  /      \\ $$ |/  |  /  |$$  \\/$$/   \n"
           "  $$ |       $$$$$$  |$$ |$$ |  $$ | $$  $$<    \n"
           "  $$ |   __  /    $$ |$$ |$$ |  $$ |  $$$$  \\   \n"
           "  $$ \\__/  |/$$$$$$$ |$$ |$$ \\__$$ | $$ /$$  |  \n"
           "  $$    $$/ $$    $$ |$$ |$$    $$ |$$ |  $$ |  \n"
           "   $$$$$$/   $$$$$$$/ $$/  $$$$$$$ |$$/   $$/   \n"
           "                          /  \\__$$ |            \n"
           "                          $$    $$/             \n"
           "                           $$$$$$/              \n"
           "  1. New Game\n"
           "  2. Highscore\n"
           "  3. Exit\n"
           "  >> ");
}

void exit(){
	printf("                            .:^:.. ..^^:..\n");
    printf("                          ...   ...:.     .......    .\n");
    printf("                            .   . ^.   :..:~~77~~~::..::.. ..\n");
    printf("                          ::::..~..:..:~7~.: :^ ~^:~..:....:^~^:^~^\n");
    printf("                        ..      .. .^!777^~~!?~^~7:^::.  .5BGB##&#7.\n");
    printf("                             .:~!!. .:~^.77?P57P7!^::~::?5B&&#GGG5.\n");
    printf("                          .:^~~^^: YJJGBGP5YY7J7!^^^?7YG##P7^7#&B~:\n");
    printf("                        .^~~:  ~J55PJ~:.       ..~JPBBBY^. .:.JG!:!!^..\n");
    printf("                     ..^7~  .::???.         .~!JG&&#J:       .7!:.^77?!^..\n");
    printf("                   .:~7!:. ^Y^.  ..      .!JPB&&#Y:          .  :7!: ~G5?!:.\n");
    printf("                 .:~7?7..~!!       .:..^?YP&&&G7         .        ~J: .BP7J!:.\n");
    printf("               .:^777~^::7^          :JB&&#BG^ .                   .J! !YYYJ?^.\n");
    printf("              .:!JJJJ: :7G.         ?#&&&&B~                         ?5..^!~~!!:.\n");
    printf("             .:!YYY5~ .J&Y      . .5BBBBBG^                           YP  :?J!~!^.\n");
    printf("             .:!J?YJ^..P&!        P&&&&&#!             ..              #7 .^55?^~:.\n");
    printf("              .^7!??^..P#? .  .   ~#&&&&&J:..   ...  .   ..  ...     . 5#..:J57~!:.\n");
    printf("              .:!J~~^.?G#5      .:.^JGBBBP5Y!^75GBGP5PJYPGPP5YYJ?!^    !&:.:??~?~:.\n");
    printf("               .^?5^:.JPBP!       .:::.. .!YYY&&&###&&&&YG##&&&&#B5:   !&:.^~!5J~.\n");
    printf("                .^??:.^^?77..                 ^:.  ..P&G:^&&&&&&&&7    PG ~7:JP7:.\n");
    printf("                .:^7? .~~J?7!                 .      7#^ P&&&&&&G^    :&^ 7?5?!:.\n");
    printf("                  .^J5.:!JPBBY            .:.       ^5^ 7###&#P^      G7..7G5!:.  \n");
    printf("                   .^?5~^~:~PBP~.?!~: ^^7~^!^     .7: ~#&&#5~        ~~:.:PY~:.\n");
    printf("                    .^!5J7..~!B&PJY?J^J?YGY?7!:..^^:?#@&G7.        .~.::^Y!^.\n");
    printf("                     .:^??J!77JY57 .: :?#BYGG!7~:7G&#5~.           ... ^?Y57:.\n");
    printf("                       .:~?JY~..... :.^!J^^!7~7PGPJ~.          ... ^?Y57:.\n");
    printf("                          :~75P~:.  ^^!!^~!JYJ57:..^^....:^!:  ...5GP7^.\n");
    printf("                          ::.:~^7.JY^?77Y5Y7^..::~??5J???5J: :?Y!J5!:.  \n");
    printf("                           .  .^.7G&###B5!^:.:.::......~?J?YB#BY7^:.\n");
    printf("                              .^^YJ5###BG5J7!7JYPPGYJ??YPPPY?7~:.\n");
    printf("                              ..:^~^^........^~!~!!!!~^^::...\n");
    printf("\n\n\n");
    
    printf("\t\t\to---------------------------------------------o\n");
    printf("\t\t\t|      Breaking and Overcoming Challenges     |\n");
    printf("\t\t\t|    Through Courage Hardwork and Persistence |\n");
    printf("\t\t\t|           ~~ Bluejackets 23-1 ~~            |\n");
    printf("\t\t\to---------------------------------------------o\n");
}

// Data
struct Player{
	char playerID[100];
	char username[100];
	int score;
	Player *next;
	Player *prev;
} *head = NULL, *tail = NULL;

struct Player *createNewScoreboard(char ID[], char name[], int score) {
	Player *temp = (Player*)malloc(sizeof(Player));
	strcpy(temp->playerID, ID);
	strcpy(temp->username, name);
	temp->score = score;
	temp->next = temp->prev = NULL;
	return temp;
}

void pushHead(Player *newData) {
    if (head == NULL) {
        head = tail = newData;
    } else {
        newData->next = head;
        head->prev = newData;
        head = newData;
    }
}

void pushTail(Player *newData) {
    if (head == NULL) {
        head = tail = newData;
    } else {
        newData->prev = tail;
        tail->next = newData;
        tail = newData;
    }
}

void pushMid(Player *newData) {
    if (head == NULL) {
        head = tail = newData;
    } else if (head->score >= newData->score) {
        pushHead(newData);
    } else if (tail->score < newData->score) {
        pushTail(newData);
    } else {
        struct Player *curr = head;
        while (curr->next && curr->next->score > newData->score) {
            curr = curr->next;
        }
        // Link the right side
        newData->next = curr->next;
        if (curr->next) {
            curr->next->prev = newData;
        }
        // Link the left side
        newData->prev = curr;
        curr->next = newData;
    }
}

// Sorting
void swapPlayers(struct Player* player1, struct Player* player2) {
    char tempID[100];
    strcpy(tempID, player1->playerID);
    strcpy(player1->playerID, player2->playerID);
    strcpy(player2->playerID, tempID);

    char tempName[100];
    strcpy(tempName, player1->username);
    strcpy(player1->username, player2->username);
    strcpy(player2->username, tempName);

    int tempScore = player1->score;
    player1->score = player2->score;
    player2->score = tempScore;
}

void bubbleSort(struct Player** head) {
    int swapped, i;
    struct Player *ptr1;
    struct Player *lptr = NULL;

    if (*head == NULL)
        return;
        
    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->score < ptr1->next->score) {
                swapPlayers(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void clearHighscoreList() {
    struct Player *current = head;
    while (current != NULL) {
        struct Player *next = current->next;
        free(current);
        current = next;
    }
    head = tail = NULL;
}

void readHighscore() {
    FILE *f = fopen("highscore.txt","r");
	if(f == NULL){
		puts("No recent players...");
		printf("Press enter to go back...");
		char out = _getch();
		return;
	} else {
		clearHighscoreList();
		
		char ID[100], nama[100];
		int skor;
		while (fscanf(f, "%[^#]#%[^#]#%d\n", ID, nama, &skor) != EOF) {
            Player *newPlayer = createNewScoreboard(ID, nama, skor);
			pushMid(newPlayer);
        }
        fclose(f);
        
        puts("========================================");
        puts("No. |ID         |Username         |Score");
        puts("========================================");
        
        bubbleSort(&head);
        struct Player *curr = head;
        int count = 1;
        while (curr != NULL) {
            printf("%-3d |%-10s |%-16s |%d \n", count, curr->playerID, curr->username, curr->score);            
            curr = curr->next;
            count++;
        }
        puts("========================================");
		puts("");
        printf("Press enter to go back...");
        return;
	}
}

// Game Display
char* generateUserID(char username[]) {
    char* userID = (char*)malloc(7 * sizeof(char)); 
    srand(time(NULL));
    
    userID[0] = toupper(username[0]);
    userID[1] = toupper(username[1]);
    
    int randomDigits = rand() % 1000;
    sprintf(userID + 2, "%03d", randomDigits);
    
    return userID;
}

void saveHighscore(int skor) {
    char username[16];

    printf("Enter your name (3-15 characters): ");
    while (1) {
        scanf("%s", username);
        if (strlen(username) >= 3 && strlen(username) <= 15) {
            break;
        } else {
            printf("Invalid input. Enter your name (3-15 characters): ");
        }
    }

    char* userID = generateUserID(username);

    Player* newPlayer = createNewScoreboard(userID, username, skor);
    pushMid(newPlayer);

    FILE* f = fopen("highscore.txt", "a");
    if (f == NULL) {
        printf("Error opening file!\n");
    } else {
        fprintf(f, "%s#%s#%d\n", userID, username, skor);
        fclose(f);
        printf("Highscore saved successfully!\n");
    }

    free(userID);
}

void gridMenu() {
    int grid; 
    do {
        printf("  Input Grid Size [4 or 6]: ");
        scanf("%d", &grid); 
    } while (grid != 4 && grid != 6); 
}

int grid[GRID_SIZE_4X4][GRID_SIZE_4X4];
int skor = 0;
int skorTemp = 0;  

int calculateMergedValue(int tempGrid[GRID_SIZE_4X4][GRID_SIZE_4X4]) {
    int mergedValue = 0;

    for (int i = 0; i < GRID_SIZE_4X4; i++) {
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            if (grid[i][j] != tempGrid[i][j] && grid[i][j] != 0) {
                mergedValue += grid[i][j];
            }
        }
    }

    return mergedValue;
}

void initializeGrid() {
    for (int i = 0; i < GRID_SIZE_4X4; i++) {
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            grid[i][j] = 0;
        }
    }
}

void printGrid() {
    const char* YELLOW = "\033[43m";
    const char* RED = "\033[41m";
    const char* BLUE = "\033[44m";
    const char* GREEN = "\033[42m";
    const char* WHITE = "\033[47m";
    const char* PURPLE = "\033[45m";
    const char* CYAN = "\033[46m";
    const char* RESET = "\x1b[0m"; 

    const int rowSpacing = 1;
    const int colSpacing = 1;
    const int tileWidth = 5;
    const int tileHeight = 3; 

    for (int i = 0; i < GRID_SIZE_4X4; i++) {
        for (int rowSpace = 0; rowSpace < rowSpacing; rowSpace++) {
            for (int rowWithinTile = 0; rowWithinTile < tileHeight; rowWithinTile++) {
                for (int j = 0; j < GRID_SIZE_4X4; j++) {
                    int value = grid[i][j];
                    const char* backgroundColor = WHITE; 

                    if (value == 2) {
                        backgroundColor = YELLOW;
                    } else if (value == 0) {
                        backgroundColor = WHITE;
                    } else if (value == 4) {
                        backgroundColor = RED;
                    } else if (value == 8) {
                        backgroundColor = GREEN;
                    } else if (value == 16) {
                        backgroundColor = BLUE;
                    } else if (value == 32) {
                        backgroundColor = PURPLE;
                    } else if (value == 64) {
                        backgroundColor = CYAN;
                    } else if (value == 128) {
                        backgroundColor = PURPLE;
                    } else if (value == 256) {
                        backgroundColor = BLUE;
                    } else if (value == 512) {
                        backgroundColor = GREEN;
                    } else if (value == 1024) {
                        backgroundColor = RED;
                    } else if (value == 2048) {
                        backgroundColor = YELLOW;
                    } else if (value == 4096) {
                        backgroundColor = RED;
                    } else if (value >= 8192) {
						backgroundColor = GREEN;
                    } else {
                    	backgroundColor = PURPLE;
					}

                    int valueWidth = snprintf(NULL, 0, "%d", value);
                    int padding = (tileWidth - valueWidth) / 2;

                    printf("%s", backgroundColor);
                    for (int colWithinTile = 0; colWithinTile < tileWidth; colWithinTile++) {
					    if (rowWithinTile == tileHeight / 2 && colWithinTile >= padding && colWithinTile < padding + valueWidth) {
					        printf("%d", value);
					        colWithinTile += valueWidth - 1; 
					    } else {
					        printf(" ");
					    }
					}
                    printf("%s", RESET);

                    if (j < GRID_SIZE_4X4 - 1) {
                        for (int colSpaceWithinTile = 0; colSpaceWithinTile < colSpacing; colSpaceWithinTile++) {
                            printf(" ");
                        }
                    }
                }
                printf("\n");
            }
        }


        if (i < GRID_SIZE_4X4 - 1) {
            for (int rowSpace = 0; rowSpace < rowSpacing; rowSpace++) {
                for (int j = 0; j < tileHeight; j++) {
                    for (int colSpace = 0; colSpace < tileWidth * GRID_SIZE_4X4; colSpace++) {
                        printf(" ");
                    }
                    printf("\n");
                }
            }
        }
    }
}

void addRandomTile() {
    int emptyCells = 0;

    for (int i = 0; i < GRID_SIZE_4X4; i++) {
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            if (grid[i][j] == 0) {
                emptyCells++;
            }
        }
    }

    if (emptyCells == 0) {
        printf("Game over!\n");
        exit(0);
    }

    int r = rand() % emptyCells;
    int tileValue = (rand() % 10) < 7 ? 2 : 4;

    for (int i = 0; i < GRID_SIZE_4X4; i++) {
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            if (grid[i][j] == 0) {
                if (r == 0) {
                    grid[i][j] = tileValue;
                    return;
                }
                r--;
            }
        }
    }
}


void mergeTiles(int row, int col, int direction) {
    int nextRow, nextCol;
    
    if (direction == 1) { 
        nextRow = row - 1;
        nextCol = col;
    } else if (direction == 2) {
        nextRow = row;
        nextCol = col - 1;
    } else if (direction == 3) { 
        nextRow = row + 1;
        nextCol = col;
    } else if (direction == 4) { 
        nextRow = row;
        nextCol = col + 1;
    }

    if (nextRow >= 0 && nextRow < GRID_SIZE_4X4 && nextCol >= 0 && nextCol < GRID_SIZE_4X4) {
        if (grid[nextRow][nextCol] == grid[row][col]) {
            if (grid[nextRow][nextCol] != 0) {
                grid[row][col] *= 2;
                grid[nextRow][nextCol] = 0;
                skor += grid[row][col];
            }
        }
    }
}


void moveGrid(int direction) {
    int tempGrid[GRID_SIZE_4X4][GRID_SIZE_4X4];
    int merged[GRID_SIZE_4X4][GRID_SIZE_4X4] = {0};
    int emptyCellsBeforeMove = 0;
    int skorTemp = 0; 

    for (int i = 0; i < GRID_SIZE_4X4; i++) {
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            tempGrid[i][j] = grid[i][j];
            if (grid[i][j] == 0) {
                emptyCellsBeforeMove++;
            }
        }
    }

    if (direction == 1) {
        // Move up
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            for (int i = 1; i < GRID_SIZE_4X4; i++) {
                if (grid[i][j] != 0) {
                    int row = i;
                    while (row > 0) {
                        if (grid[row - 1][j] == 0) {
                            grid[row - 1][j] = grid[row][j];
                            grid[row][j] = 0;
                        } else if (grid[row - 1][j] == grid[row][j] && merged[row][j] == 0) {
                            grid[row - 1][j] *= 2;
                            grid[row][j] = 0;
                            merged[row - 1][j] = 1;  
                            skorTemp += grid[row - 1][j]; 
                            break;
                        } else {
                            break; 
                        }
                        row--;
                    }
                }
            }
        }
    } else if (direction == 2) {
        for (int i = 0; i < GRID_SIZE_4X4; i++) {
            for (int j = 1; j < GRID_SIZE_4X4; j++) {
                if (grid[i][j] != 0) {
                    int col = j;
                    while (col > 0) {
                        if (grid[i][col - 1] == 0) {
                            grid[i][col - 1] = grid[i][col];
                            grid[i][col] = 0;
                        } else if (grid[i][col - 1] == grid[i][col] && merged[i][col] == 0) {
                            grid[i][col - 1] *= 2;
                            grid[i][col] = 0;
                            merged[i][col - 1] = 1; 
                            skorTemp += grid[i][col - 1]; 
                            break;
                        } else {
                            break;  
                        }
                        col--;
                    }
                }
            }
        }
    } else if (direction == 3) {
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            for (int i = GRID_SIZE_4X4 - 2; i >= 0; i--) {
                if (grid[i][j] != 0) {
                    int row = i;
                    while (row < GRID_SIZE_4X4 - 1) {
                        if (grid[row + 1][j] == 0) {
                            grid[row + 1][j] = grid[row][j];
                            grid[row][j] = 0;
                        } else if (grid[row + 1][j] == grid[row][j] && merged[row][j] == 0) {
                            grid[row + 1][j] *= 2;
                            grid[row][j] = 0;
                            merged[row + 1][j] = 1;  
                            skorTemp += grid[row + 1][j]; 
                            break;
                        } else {
                            break;  
                        }
                        row++;
                    }
                }
            }
        }
    } else if (direction == 4) {
        for (int i = 0; i < GRID_SIZE_4X4; i++) {
            for (int j = GRID_SIZE_4X4 - 2; j >= 0; j--) {
                if (grid[i][j] != 0) {
                    int col = j;
                    while (col < GRID_SIZE_4X4 - 1) {
                        if (grid[i][col + 1] == 0) {
                            grid[i][col + 1] = grid[i][col];
                            grid[i][col] = 0;
                        } else if (grid[i][col + 1] == grid[i][col] && merged[i][col] == 0) {
                            grid[i][col + 1] *= 2;
                            grid[i][col] = 0;
                            merged[i][col + 1] = 1; 
                            skorTemp += grid[i][col + 1]; 
                            break;
                        } else {
                            break;  
                        }
                        col++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < GRID_SIZE_4X4; i++) {
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            merged[i][j] = 0;
        }
    }

    int gridChanged = 0;

    for (int i = 0; i < GRID_SIZE_4X4; i++) {
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            if (grid[i][j] != tempGrid[i][j]) {
                gridChanged = 1;
                break;
            }
        }
    }

	if (gridChanged) {
	    addRandomTile();
	    skor += skorTemp;
	    printf("Score : %d\n", skor);
	}
}

int isGameOver() {
    for (int i = 0; i < GRID_SIZE_4X4; i++) {
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            if (grid[i][j] == 0) {
                return 0; 
            }
        }
    }

    for (int i = 0; i < GRID_SIZE_4X4; i++) {
        for (int j = 0; j < GRID_SIZE_4X4; j++) {
            int tileValue = grid[i][j];

            if (i > 0 && grid[i - 1][j] == tileValue) {
                return 0; 
            }

            if (i < GRID_SIZE_4X4 - 1 && grid[i + 1][j] == tileValue) {
                return 0;  
            }

            if (j > 0 && grid[i][j - 1] == tileValue) {
                return 0;  
            }

            if (j < GRID_SIZE_4X4 - 1 && grid[i][j + 1] == tileValue) {
                return 0;  
            }
        }
    }
    return 1;
}

void gameDisplay(){
    initializeGrid();

    addRandomTile();
    addRandomTile();
    
	skor = 0;

    while (1) {
        system("cls");  
		
        printGrid();
        puts("");
        puts("");
        printf("Score : %d\n", skor);
        puts("");
        puts("[Press Enter to Exit]");

        char move = _getch();

        if (move == 'w' || move == 'W') {
            moveGrid(1); 
        } else if (move == 'a' || move == 'A') {
            moveGrid(2);  
        } else if (move == 's' || move == 'S') {
            moveGrid(3);  
        } else if (move == 'd' || move == 'D') {
            moveGrid(4);
        } else if (move == 13){
        	puts("Thank you for playing!");
        	saveHighscore(skor);
        	return;
		}
		if (isGameOver()) {
		    printf("Game over!\n");
		    system("pause");
		    break;
		}

    }
}

int main() {
    srand(time(NULL));
    int run = 1;
    char input;
	
	while(run){
		input = '0';
		while(input != '1' && input != '2' && input != '3'){
			system("cls");
			menu();
			scanf("%c", &input);
		}
		
	    switch(input){
	    	case '1':{
	    		gridMenu();
	    		gameDisplay();
	    		_getch();
				break;
			}
			case '2':{
				system("cls");
				readHighscore();
				_getch();
				break;
			}
			case '3':{
				system("cls");
				exit();
				char exit = _getch();
				run = 0;
				break;
			}
		}	
	}
    return 0;
}
