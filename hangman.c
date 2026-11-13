
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define WORDS 30

char words[WORDS][25] = {
    "apple", "tiger", "computer", "keyboard",
    "programming", "technology", "internet",
    "elephant", "football", "developer",
    "security", "database", "algorithm",
    "engineering", "artificial", "intelligence",
    "network", "science", "adventure",
    "diamond", "treasure", "encryption",
    "software", "hardware", "innovation",
    "microprocessor", "application", "robot",
    "mathematics", "cryptography", "terminal"
};

void hangman(int lives)
{
    printf("\n");

    printf("  +---+\n");
    printf("  |   %c\n", lives <= 5 ? 'O' : ' ');
    printf("  |  %c%c%c\n",
           lives <= 3 ? '/' : ' ',
           lives <= 4 ? '|' : ' ',
           lives <= 2 ? '\\' : ' ');
    printf("  |  %c %c\n",
           lives <= 1 ? '/' : ' ',
           lives <= 0 ? '\\' : ' ');
    printf("  |\n");
    printf("__|________\n");
}

int main()
{
    int choice, lives, score = 0;
    int best = 0, rounds = 0;
    int i, found, win;
    char word[25], hidden[25];
    char used[26];
    char letter, again;

    srand((unsigned int)time(NULL));

    do
    {
        system(CLEAR);

        printf("\n");
        printf("========================================\n");
        printf("             HANGMAN PRO\n");
        printf("           TERMINAL EDITION\n");
        printf("========================================\n");
        printf("             MADE BY SANKET\n");
        printf("----------------------------------------\n");
        printf("  1. START GAME\n");
        printf("  2. HOW TO PLAY\n");
        printf("  3. STATISTICS\n");
        printf("  4. EXIT\n");
        printf("----------------------------------------\n");
        printf("  SELECT OPTION: ");

        if(scanf("%d", &choice) != 1)
            return 0;

        if(choice == 1)
        {
            system(CLEAR);

            printf("\nSELECT DIFFICULTY\n");
            printf("1. EASY\n");
            printf("2. MEDIUM\n");
            printf("3. HARD\n");

            printf("\nChoose: ");

            if(scanf("%d", &choice) != 1)
                return 0;

            if(choice == 1)
                lives = 8;
            else if(choice == 2)
                lives = 6;
            else if(choice == 3)
                lives = 5;
            else
            {
                printf("Invalid difficulty!\n");
                getchar();
                getchar();
                continue;
            }

            strcpy(word, words[rand() % WORDS]);

            for(i = 0; word[i] != '\0'; i++)
                hidden[i] = '_';

            hidden[i] = '\0';

            memset(used, 0, sizeof(used));
            win = 0;

            while(lives > 0)
            {
                system(CLEAR);

                printf("\n========================================\n");
                printf("              HANGMAN PRO\n");
                printf("========================================\n");

                hangman(lives);

                printf("\nWORD: ");

                for(i = 0; hidden[i] != '\0'; i++)
                    printf("%c ", hidden[i]);

                printf("\n\nLIVES: %d", lives);
                printf("\nSCORE: %d", score);

                printf("\nUSED LETTERS: ");

                for(i = 0; i < 26; i++)
                    if(used[i])
                        printf("%c ", 'A' + i);

                printf("\n\nENTER LETTER: ");

                if(scanf(" %c", &letter) != 1)
                    return 0;

                letter = (char)tolower((unsigned char)letter);

                if(letter < 'a' || letter > 'z')
                {
                    printf("Enter a valid alphabet!");
                    getchar();
                    getchar();
                    continue;
                }

                if(used[letter - 'a'])
                {
                    printf("Already used!");
                    getchar();
                    getchar();
                    continue;
                }

                used[letter - 'a'] = 1;
                found = 0;

                for(i = 0; word[i] != '\0'; i++)
                {
                    if(word[i] == letter)
                    {
                        hidden[i] = letter;
                        found = 1;
                    }
                }

                if(found)
                {
                    printf("\nCORRECT!");
                    score += 10;
                }
                else
                {
                    printf("\nWRONG!");
                    lives--;
                }

                if(strcmp(word, hidden) == 0)
                {
                    win = 1;
                    score += lives * 20;
                    break;
                }

                printf("\n\nPress ENTER to continue...");
                getchar();
                getchar();
            }

            system(CLEAR);

            printf("\n========================================\n");

            if(win)
                printf("              YOU WON!\n");
            else
                printf("              GAME OVER!\n");

            printf("========================================\n");
            printf("WORD: %s\n", word);
            printf("SCORE: %d\n", score);

            rounds++;

            if(score > best)
                best = score;

            printf("\nPLAY AGAIN? (Y/N): ");
            scanf(" %c", &again);
        }
        else if(choice == 2)
        {
            system(CLEAR);
            printf("\n========== HOW TO PLAY ==========\n");
            printf("Guess the hidden word letter by letter.\n");
            printf("Correct guesses reveal letters.\n");
            printf("Wrong guesses reduce your lives.\n");
            printf("Guess the word before lives run out!\n");
            printf("=================================\n");

            printf("\nPress ENTER...");
            getchar();
            getchar();
            again = 'Y';
        }
        else if(choice == 3)
        {
            system(CLEAR);
            printf("\n========== STATISTICS ==========\n");
            printf("Rounds Played: %d\n", rounds);
            printf("Total Score: %d\n", score);
            printf("Best Score: %d\n", best);
            printf("================================\n");

            printf("\nPress ENTER...");
            getchar();
            getchar();
            again = 'Y';
        }
        else if(choice == 4)
        {
            printf("\nTHANKS FOR PLAYING!\n");
            printf("GAME DEVELOPED BY SANKET\n");
            return 0;
        }
        else
        {
            printf("\nInvalid option!\n");
            again = 'Y';
            getchar();
            getchar();
        }

    } while(again == 'Y' || again == 'y');

    printf("\nTHANKS FOR PLAYING!\n");
    return 0;
}
