#include "Team.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

	Team::Team(string newLocation, string newName) {
		name=newName;
		location=newLocation;
		numOfPlayers=0;
		players = new Player[12];
	}

	Team::Team() {
		name="";
		location="";
		numOfPlayers=0;
		//Player players[12];
	}
	void Team::show() {
		cout << location << " " << name << " (" << numOfPlayers << " players)";
	}
	
	string Team::getName(){
		return name;	
	}
	
	string Team::getFullName(){
		return location + " " + name;	
	}
	
	void Team::addPlayer(Player player){
		players[numOfPlayers]=player;
		numOfPlayers++;
	}
	int Team::getNumOfPlayers(){
		return numOfPlayers;	
	}
	
	void Team::printRoster(){
		for(int i =0; i<numOfPlayers; i++){
			players[i].show();	
		}
	}
	bool Team::numTaken(string x){
		for (int i=0; i<numOfPlayers; i++){
			if(players[i].getNum()==x){return true;}		
		}
		return false;
	}
	string Team::getLowest(){
		for(int i=1; i<100; i++){
			if(!numTaken(to_string(i))){return to_string(i);}	
		}
		return "100";
	}
	void Team::deletePlayers(){
		delete []players;	
	}
	bool Team::isInTeam(string x){
		for (int i=0; i<numOfPlayers; i++){
			if (players[i].getName()==x){return true;}		
		}	
		return false;
	}
	Player Team::removePlayer(string x){
		Player ans;
		for (int i=0; i<numOfPlayers; i++){
			if (players[i].getName()==x){
				players[i].released();
				ans = players[i];
				players[i].reset();
				numOfPlayers--;
				for (int j = i; j < numOfPlayers-1; ++j){
					players[j] = players[j + 1];
				}
    			
			}		
		}	
		return ans;
	}
	void Team::showCareer(string x){
		for (int i=0; i<numOfPlayers; i++){
			if (players[i].getName() == x){
				players[i].showCareer();			
			}		
		}	
	}
	
