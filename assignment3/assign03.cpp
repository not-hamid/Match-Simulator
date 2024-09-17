#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip> // this library to align (scores/balls played) with setw and left in summary

using namespace std;

class Player{
private:
    string playerName;
    int totalScore;
    int ballsPlayed;

public:

    void setName(string name){
        playerName = name;
    }
    string getName(){
        return playerName;
    }
    void setScore(int score){
        totalScore = score;
    }
    int getScore(){
        return totalScore;
    }
    void setBalls(int balls){
        ballsPlayed = balls;
    }
    int getBalls(){
        return ballsPlayed;
    }

    Player(){
        playerName = "";
        totalScore = 0;
        ballsPlayed = 0;
    }
};

int main(){

    string playerNames[] = {
        "Babar Azam", "Naseem Shah", "Agha Salman", "Mohammad Amir",
        "Shaheen Afridi", "Shadab Khan", "Imad Waseem", "Fakhar Zaman",
        "Haris Rauf", "Muhammad Rizwan", "Iftikhar Ahmed"
    };

    Player players[11];

    srand(time(0));   //randomly assigning 

    int maxScore;
    string manOfTheMatch;

    for(int i = 0; i < 11; i++){
        players[i].setName(playerNames[i]);
        int totalScore = 0;
        int ballsPlayed = 0;

        cout << i + 1 << ". " << players[i].getName() <<endl;
        cout << "Scores per Ball: ";

        while (true){
            int score = (rand() % 7) - 1; 
            if (score == 5) continue; 

            if (score == -1){
                cout << "OUT";
                ballsPlayed++;
                break;

            } 
            
            else{
                cout << score;
                totalScore += score;
                ballsPlayed++;
                if (ballsPlayed < 10) cout << ", ";
            }

            if (ballsPlayed >= 10) break; 
        }

        players[i].setScore(totalScore);
        players[i].setBalls(ballsPlayed);

        cout <<endl;
        cout << "Total Score: " << players[i].getScore() << "            Balls played: " << players[i].getBalls() <<endl;

        cout << endl;


        // man of match
        if (totalScore > maxScore) {
            maxScore = totalScore;
            manOfTheMatch = players[i].getName();
        }
    }

    // summary of match
    cout << "<<<<<<< Match Summary >>>>>>>>" <<endl;

    cout << left << setw(20) << "Player Name" <<setw(15) << "Score" << "Balls played" <<endl;

    for(int i = 0; i < 11; i++){
        cout << left << setw(20) << players[i].getName() << setw(15) << players[i].getScore() << players[i].getBalls() <<endl;

    }
    cout << endl;

    cout << "Man of the match: " << manOfTheMatch <<endl <<endl;

    cout << "___________________________________" <<endl <<endl;

    system("pause");

    return 0;
}
