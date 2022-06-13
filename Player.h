//
//  Player.h
//  DeathByTrivia
//
//  Created by Jason Leslie on 4/25/22.
//
#include <string>
#include "Drunkness.h"
#include <unistd.h>
#ifndef Player_h
#define Player_h
#include <iostream>
#include <fstream>
using namespace std;

class Player{
public:
    //Constructors
    Player();
    Player(int& avatar);
    
    //Getters
    int getScore();
    drunkness getBac();
    string getName();
    
    //Setters
    void setScore(int x);
    void incBac();
    
    //Play
    void playGame(string* Qs, string* As, string& play);
    void typewriter(string x);
private:
    int score;
    string name;
    drunkness bac;
};
Player :: Player(){
    score = 0;
    name = "Wolverine";
    bac = sober;
}
Player :: Player(int& avatar){
    score = 0;
    if(avatar ==1)name = "Wolverine";
    if(avatar ==2)name = "Joe Biden";
    if(avatar ==3)name = "Jimi Hendrix";
    bac = sober;
}
int Player :: getScore(){
    return score;
}
drunkness Player :: getBac(){
    return bac;
}
string Player :: getName(){
    return name;
}
void Player :: setScore(int x){
    score = score + x;
    cout<<"You now have "<< score<<" points!"<<endl;
}
//increase BAC by increasing enum
void Player :: incBac(){
    if(bac == sober) {
        bac = tipsy;
        cout <<name;
        typewriter(" shotguns all of the beers like a boss!");
        cout<<endl<<endl;
    }
    else if(bac == tipsy){
        bac = hammered;
        cout <<name;
        typewriter(" sloppily chugs and is totally hammered. Slurring speech and drooling a little bit.");
        cout<<endl<<endl;
    }
    else if(bac == hammered){
        bac = sloshed;
        cout <<name;
        typewriter(" finishes the remaining beers like a walk in the park and is fading in and out of consciousness. Appears to be blind. Knees weak, palms sweaty, mom's spaghetti. ");
        cout<<name;
        typewriter(" just collapsed and probably died. Seth Rogan puts his joint down and chuckles as he starts dragging the body down the hallway towards the back alley.");
        cout<<endl<<endl;
        cout<<"I guess you lost since you're dead and can't play anymore...";
        cout<<endl<<endl<<endl;
        
        
        
    }
}
//loops through questions and matches answers. increments beers/points.
void Player :: playGame(string* Qs, string* As, string& play){
    int beers = 6;
    int points = 10;
    typewriter("Leggo!");
    cout<< endl<<endl;
    for(int i=0; i<=5; i++){
        if(i==5&&bac!=sloshed){
            cout<<"Congrats you won!"<<endl;
            cout<<"Your survival certificate is printed.";
            cout<<endl<<endl;
            ofstream outData;
            outData.open("SurvivalCert.txt");
            outData << "This is your certificate of survival of Death by Trivia!"<<endl;
            outData << "Your final score is: "<< score <<" points.";
            
            break;
        }
        string answer;
        if(getBac()==sloshed)break;
        cout<<"Question "<< i+1<<" is worth " << points <<" points."<< " The penalty is chugging "<< beers <<" beers."<<endl<<endl;
        typewriter(Qs[i]);
        cout<<endl;
        cout<<"Enter answer: ";
        getline(cin, answer);
        cout<< endl;
        
        if(answer == As[i]){
            typewriter("Woah, you actually got it right. How unsatisfying...");
            cout <<endl<<endl;
            setScore(points);
        }
        else {
            typewriter("Ha, way off. Get chuggin!");
            cout<< endl<<endl;
            incBac();
            
        }
        points += 10;
        beers += 6;
    }
}
//slowly prints by single characters to simulate typing.
void Player::typewriter(string x){
    for(int i=0; i<x.length();i++){
        cout << x[i];
        usleep(100000);
    }
}


#endif /* Player_h */
