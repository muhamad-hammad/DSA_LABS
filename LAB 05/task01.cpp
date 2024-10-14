#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

    int randonNum(int low, int high){
        return rand()%(high-low+1)+low;
    }        
    int random(){
        int low = 1;
        int high = 100;
        int num = randonNum(low, high);
        return num;
    }

    int enterNum(int p){
        cout<< "For Player"  << p << "Enter your guess: "<<endl;
        int guess;
        cin>>guess;
        return guess;
    }
    
    void playgame(int num,int player, int numPlayers){
        int number = enterNum(player);
        if(num == number){
            cout<<"You win!"<<endl;
            return;
        } else if(num < number){
            cout<<"The number you entered was high!" << endl;
            player = (player % numPlayers ) +1;
            playgame(num, player,numPlayers);
        } else if (num > number){
            cout << "The number you entered was  low!" << endl;
            player = (player % numPlayers ) +1;
            playgame(num, player,numPlayers);
        }

    }



int main(){
    srand(time(0));
    cout<<"Enter the number of players: "<<endl;
    int n;
    cin>>n;
    cout << "Game started play your turns: " << endl;
    playgame(random(),1, n);
    
    return 0;
}