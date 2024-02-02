/*Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number .*/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class game{
    public:
    int random_number;
    int user_input;
    int attempts;

    public:
    game(){
        srand(static_cast<unsigned int>(time(0)));
        random_number=rand() % 100+1;
        attempts=0;
    }

    void play(){
        cout<<"\nWelcome to number gussing game....!";
        cout<<"\nI have chosen a number between 1 and 100.\nCan you guess it?";

        while(true){
            cout<<"\nEnter the number that you guess:";
            cin>>user_input;
            attempts++;
            if(user_input==random_number){
                cout<<"\nCongratulations! You guessed correct number "<<random_number<<" in "<<attempts<<" attempts.";
                break;
            }
            else if(user_input < random_number){
                cout<<"Low than my number, Try again.";
            }
            else{
                cout<<"High than my number, Try again.";
            }
        }
    }
};

int main(){
    game obj;
    obj.play();
    return 0;
}
