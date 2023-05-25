#include<stdio.h>

int main(){
    int number;
    srand(time(NULL));
    number = (rand() %(65 - 0 + 1)) + 0;
    int guess = 10;
    int counter = 1;
    int user;
    printf("OPEN THE CMD(COMMAND PROMPT IN FULL SCREEN OR WHATEVER TERMINAL(IF LINUX)\n KEEP IT IN FULL SCREEN THROUGH OUT THE GAME FOR PROPER FUNCTIONING OF SOURCE CODE.\n There are Some instructions for this game\n 1. First of all if u have already read the code so just stop wasting time if u have little knowledge then u already know the answer But i THINK either u haven't read the code or u are not that genius.\n 2. Ha. so This Game is that it will generate random number from 0 to 65 don't know can be any number so just put your guesses.\n 3. Now Good things: There are HINTS for u at specific place of time so KEEP PATIENCE You WIll Loose.\n 4. Although i have Tried my best to Give u the Wining Reward it cost me a lot of time to make so Try if u Fail First Time Its Part of the Game and LIFE. \n 5. If u LOOSSE(i.e U WILL) still REWARD is FAIR don't CRY and ENJOY!\n ");
    printf("6. I have Tried my BEST to Make u WIN\n 7. Last BUT not Least You have specific no. of Attempts so Think Wisely and Thats all Enjoy.\n :)\n");
    for(int i =0; i<guess; i++){
        printf("Guess the random number: ");
        scanf("%d", &user);
        if(user == number){
            printf("Congratulations u WON in %d Attempts\n", counter);
            Draw(1);
            break;}
        else{
            printf("Wrong Guess Try Again\n");
        }
        counter++;
        for(int j =3;j == counter;j++){
            if(number >= 0 && number <= 15){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 0 BUT LESS than 20\n:)\n");
        }
        if(number >= 16 && number <= 25){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 15 BUT LESS than 30\n:)\n");
        }if(number >= 26 && number <= 35){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 25 BUT LESS than 40\n:)\n");
        }if(number >= 36 && number <= 45){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 35 BUT LESS than 50\n:)\n");
        }if(number >= 46 && number <= 55){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 45 BUT LESS than 60\n:)\n");
        }if(number >= 56 && number <= 65){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 45 BUT LESS than 60\n:)\n");
        }}for(int j =6;j == counter;j++){
            if(number >= 0 && number <= 10){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 0 BUT LESS than 11\n:)\n");
        }
        if(number >= 11 && number <= 20){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 10 BUT LESS than 21\n:)\n");
        }if(number >= 21 && number <= 30){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 20 BUT LESS than 31\n:)\n");
        }if(number >= 31 && number <= 40){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 30 BUT LESS than 41\n:)\n");
        }if(number >= 41 && number <= 50){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 40 BUT LESS than 51\n:)\n");
        }if(number >= 51 && number <= 60){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 50 BUT LESS than 61\n:)\n");
        }
        }for(int j =8;j == counter;j++){
            if(number >= 0 && number <= 5){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 0 BUT LESS than 5 \n:)\n");
        }if(number >= 6 && number <= 10){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 6 BUT LESS than 10\n:)\n");
        }
        if(number >= 11 && number <= 16){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 11 BUT LESS than 16\n:)\n");
        }if(number >= 17 && number <= 22){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 17 BUT LESS than 22\n:)\n");
        }if(number >= 23 && number <= 28){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 23 BUT LESS than 28\n:)\n");
        }if(number >= 29 && number <= 34){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 29 BUT LESS than 34\n:)\n");
        }if(number >= 35 && number <= 40){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 35 BUT LESS than 40\n:)\n");
        }if(number >= 41 && number <= 46){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 41 BUT LESS than 46\n:)\n");
        }if(number >= 47 && number <= 52){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 47 BUT LESS than 52\n:)\n");
        }if(number >= 53 && number <= 58){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 53 BUT LESS than 58\n:)\n");
        }if(number >= 59 && number <= 65){
            printf("HINT!!!!!!!!!!!!: the Number is GREATER than 59 BUT LESS than 65\n:)\n");
        }
        }
        if(counter == 2){
            printf("It DOSEN'T Start with Your Phone Number DUMB\n");
        }if(counter == 4){
            printf("Think THE HECK YOU DOing\n");
        }if(counter == 5){
            printf("O MAI GOD Why are YOU EVEN Playing\n");
        }if(counter == 7){
            printf("Okay CALM DOWN\n You Can DO THIS\n GO _______ Just a Random Shot\n");
        }if(counter == 9){
            printf("UGH\n");
        }if(counter == 9){
            printf("HAHAHAHAHAHHAH\n");
        }if(counter == 10){
            printf("LAST CHANCE\n Don't You Wanna WIN?\n LEt Me think the Probability You Will Win is Quite High GO On\n I Have FAith in my GAME\n HAHAHAHA \n Nah Try\n:))))))))))))\n");
        }
        if(i == 9){
            printf("YOU are OUT of GUESSES\n I m Afraid i cant HELP u anymore \n This is a disgrace to MINUTESSSSSSSSSSS of typing i have done to write this code \n Well i have NO WORDS that would be ethical enough so just VANISH from face of Earth and don't let me know\n");
            Draw(2);
        }
    }


    return 0;

}

int Draw(int n){
    if(n == 1){
    printf("****   ******  **       *  ******  ******  ******  *******  *    *  *         *******  ******** *******  ******  **       *\n");
    printf("*  *   *    *  * *      *  *    *  *    *  *    *     *     *    *  *         *     *      *       *     *    *  * *      *\n");
    printf("*      *    *  *  *     *  *       *    *  *    *     *     *    *  *         *     *      *       *     *    *  *  *     *\n");
    printf("*      *    *  *   *    *  *       ******  ******     *     *    *  *         *******      *       *     *    *  *   *    *\n");
    printf("*      *    *  *    *   *  *       **      *    *     *     *    *  *         *     *      *       *     *    *  *    *   *\n");
    printf("*      *    *  *     *  *  *  ***  * *     *    *     *     *    *  *         *     *      *       *     *    *  *     *  *\n");
    printf("*  *   *    *  *      * *  *    *  *  *    *    *     *     *    *  *         *     *      *       *     *    *  *      * *\n");
    printf("****   ******  *       **  ******  *   *   *    *     *     ******  *******   *     *      *    *******  ******  *       **\n");}
if(n==2){
    printf("******   **    **  ***    ***  ********\n");
    printf("**  **   **    **  ** **  ***  **    **\n");
    printf("**  **   **    **  **  *** **  **    **\n");
    printf("**  **   **    **  **      **  ********\n" );
    printf("**  **   **    **  **      **  ********\n");
    printf("**  **   **    **  **      **  **    **\n");
    printf("**  **   **    **  **      **  **    **\n");
    printf("******   ********  **      **  ********\n");
}
return 0;
}
