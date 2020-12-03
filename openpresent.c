#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


//CHANGE THIS TO NUM OF QUESTIONS IN YOUR QUIZ
#define NUM_QUES 0

//Generates random num in range [lower, upper] 
int randomInt(int lower, int upper) 
{ 
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num;
}

int main (void) {
  
    //PUT INTRODUCTION CODE/PRINTING HERE
    


    char* ques[NUM_QUES] = {
    };

    char* ans[NUM_QUES] = {
    };

    char* snark[5] = {"Have I stumped you yet?",
    "Awwwww. Not quite, I'm afraid!",
    "SOOOO CLOSEE, try again!",
    "Darn. Unfortunately that's incorrect :(",
    "One day you'll get it, dont worry."};

    int ctr = 0;
    int faults = 0;
    int streak = 0;

    //I set the max input length to 100 chars, but you can change this
    char in[100];

    //for all questions in the quiz
    while (ctr < NUM_QUES) {
        //print out annoying messages every so often (change 'ctr==x' to what's appropriate)
        if (ctr == 20 && faults==0) {
            printf("I mean, how many questions could there be???\n");
            sleep(3);
        }
        else if (ctr == 57 && faults==0) {
            printf("You're getting there...or are you???\n");
            sleep(4);
        }
        else if (ctr == 81 && faults==0) {
            printf("Please. Don't give up hope\n");
            sleep(5);
        }
        else if (ctr == 99 && faults==0) {
            printf("Do you think this is ever gonna end???\n");
            sleep(4);
        }

        //print the question and scan for input
        printf("%d. %s | ", ctr+1, ques[ctr]);
        scanf ("%[^\n]%*c", in);

        //convert input to all lowercase, skipping over spaces
        for (char* str = in; *str; ++str) if ((int)*str != 32) { *str = tolower(*str);} //make an alias ptr so we don't modify in

        if (strcmp(in, ans[ctr])==0) {
            //correct answer, so increment streak no matter what
            streak++;

            //if we don't have any incorrect tries for this question and this is third in a row, we have a streak
            if (faults == 0 && streak == 3) {
                printf("WOW! Three in a row on the first try! Keep up the good work!\n");

                //reset streak to 0
                streak = 0;

                sleep(4);
            }

            //otherwise we had some incorrect attempts for this question, but we're back on track. Reset everything.
            else if (faults != 0) {
                streak = 0;
                faults = 0;
            }

            //increment question ctr
            ctr++;
        }

        //incorrect input
        else {
            //add a fault
            faults++;

            //reached 3 incorrect inputs in a row, print message and reset faults
            if (faults == 3) {
                printf("%s\n", snark[randomInt(0, 4)]);
                sleep(3);

                //reset faults back to 0 to start counting again
                faults = 0;
            }

            //reset streak to 0. They'll need three correct answers in a row to get a streak
            streak = 0;
        }
    }

    //PUT END BEHAVIOR CODE HERE
}

