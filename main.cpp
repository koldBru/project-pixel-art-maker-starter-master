//
//  main.cpp
//  DeathByTrivia
//
//  Created by Jason Leslie on 4/25/22.
//
#include "Drunkness.h"
#include "Player.h"
#include <unistd.h>
#include <iostream>
#include <fstream>
using namespace std;
void intro(string& play);
void selectPlayer(int& avatar);
void selectGenre(int& genre);
void LoadQs(int& genre, string* Qs, string* As);
void playGame(string* Qs, string* As, string& play);
void typewriter(string x);


int main() {
    int avatar, genre;
    string play;
    string* Qs= new string[5];
    string* As= new string[5];
    
    do{
    intro(play);
        if(play !="yes"){
            cout<<"Okay chill out."<<endl;
            break;}
    selectPlayer(avatar);
    Player player1(avatar);
    selectGenre(genre);
    LoadQs(genre, Qs, As);
    player1.playGame(Qs, As, play);
    }while(play=="yes");
    
    return 0;
}

//prints greeting and rules. Can also break loop here and quit game.
void intro(string& play){
    typewriter("Welcome to Death by Trivia! I am your host, Seth Rogan. The object of the game is quite simple, survive through five questions. Sounds easy right? Spelling counts, and do not use upper case letters. If you get a question wrong, you will be forced to drink an absurd amount of beers. Don't worry, your corpse will be fed to the stray dogs in the back alley. Wanna give it a go?");
    cout<< endl<<endl;
    typewriter("Enter yes or no: ");
    cout<<endl;
    cin >> play;
    
    
}
//choose your player
void selectPlayer(int& avatar){
    
        cout << endl<<endl;
        typewriter("Dope. Select your Avatar: ");
        cout<<endl<<endl;
        typewriter("1. Wolverine");
        cout<<endl;
        cout << "------------"<<endl;
        typewriter("Special Abilities: steroids, backscratching");
        cout<<endl<<endl;
        typewriter("2. Joe Biden");
        cout<<endl;
        cout << "------------"<<endl;
        typewriter("Special Abilities: stuttering, narcolepsy");
        cout<<endl<<endl;
        typewriter("3. Jimi Hendrix");
        cout<<endl;
        cout << "----------------"<<endl;
        typewriter("Special Abilities: dropping acid, shredding guitar");
        cout<<endl<<endl;
        typewriter("Enter number: ");
        cin >> avatar;
        
    
       }
//choose genre
void selectGenre(int& genre){
    
    cout <<endl<<endl;
    typewriter("Select Trivia Genre");
    cout<<endl;
    cout << "-------------------"<< endl;
    typewriter("1. X-Men");
    cout<< endl;
    typewriter("2. Harry Potter");
    cout<< endl;
    typewriter("3. Lord of the Rings");
    cout<< endl<<endl;
    cout << "Enter number: ";
    cin >> genre;
    cout<< endl<<endl;
    }
//load questions/answers based on genre chosen
void LoadQs(int& genre, string* Qs, string* As){
    if(genre==1){
        ifstream inData;
        inData.open("XmenQ.h");
        for (int i =0; i<5;i++){
            getline(inData,Qs[i]);
        }inData.close();
        inData.open("XmenA.h");
        for (int i =0; i<5;i++){
            getline(inData,As[i]);
        }inData.close();
        cin.ignore();
    
    }
    if(genre==2){
        ifstream inData;
        inData.open("HPQ.h");
        for (int i =0; i<5;i++){
            getline(inData,Qs[i]);
        }inData.close();
        inData.open("HPA.h");
        for (int i =0; i<5;i++){
            getline(inData,As[i]);
        }inData.close();
        cin.ignore();
    }
    if(genre==3){
        ifstream inData;
        inData.open("LOTRQ.h");
        for (int i =0; i<5;i++){
            getline(inData,Qs[i]);
        }inData.close();
        inData.open("LOTRA.h");
        for (int i =0; i<5;i++){
            getline(inData,As[i]);
        }inData.close();
        cin.ignore();
    }
}
void typewriter(string x){
    for(int i=0; i<x.length();i++){
        cout << x[i];
        usleep(100000);
        
        
    }
}
