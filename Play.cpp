#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Team.h"
#include "Parser.h"
using namespace std;


int main() {
	
	string command; 
	bool flag=false;
	bool flag2=true;
	bool flag3=false;
	int flag4=-1;
	bool flag5=false;
	int flag6 = -1;
	string other;
	
	Player *freeAgents;
	Team *league;
	freeAgents = new Player[10];
	league = new Team[10];
	int numTeams=0;
	int maxTeams = 10;
	int numFreeAgents = 0;
	int maxFreeAgents = 10;

   cout << endl <<"Enter a command:" << endl;
   cout << "Choose from" << endl;
   cout << "   Team <Location> <team-nickname>"<<endl;
   cout << "   Player <firstname> <lastname> <number> [<team-nickname>]" << endl;
   cout << "   League" << endl;
   cout << "   Roster [<team-nickname>]" << endl;
   cout << "   Release <lastname> <team-nickname>" << endl;
   cout << "   Sign <lastname> <team-nickname>" << endl;
   cout << "   Career <lastname>" << endl;
   cout << "   Trade" << endl;
   cout << "   Quit" << endl << ": ";
   getline(cin,command,'\n');
   
   while (command.substr(0,4) != "Quit"){
   	Parser line(command);
   	if (numTeams ==maxTeams){
   		maxTeams +=10;
   		Team *temp = new Team[maxTeams];
   		for (int i =0; i<maxTeams-10; i++){
				temp[i] = league[i];   		
   		}
   		delete []league;
   		league = temp;
   		temp = NULL;
   		//delete temp;
   	}
   	if (numFreeAgents == maxFreeAgents){
   		maxFreeAgents +=10;
   		Player *temp = new Player[maxFreeAgents];
   		for(int i=0; i<maxFreeAgents-10; i++){
				temp[i] = freeAgents[i];   		
   		}
   		delete []freeAgents;
   		freeAgents = temp;
   		temp = NULL;
   		//delete temp;
   	}
   	
		if (line.getOperation() == "Team"){
			if (line.getArg3() !=""){
				cout << endl << "Ignoring unexpected arguments" << endl;	
			}
			if (line.getArg2() ==""){
				cout << endl << "Can't operate with missing arguments" << endl;	

			}
			else{
				flag2=true;
			
				for (int i = 0; i<numTeams; i++){
					if (league[i].getName()==line.getArg2()){flag2=false;}			
				}
				if (line.getArg2()==""){flag2=false;}
			
				if (flag2==true){
					Team team(line.getArg1(), line.getArg2());
					league[numTeams]=team;
					numTeams++;
				}
				else{
					cout << "Duplicate team nickname " << line.getArg2() << " not included" << endl;	
				}
			
			}
			
		}
		else if (line.getOperation() == "Player"){
			if (line.getArg3() ==""){
				cout << endl << "Can't operate with missing arguments" << endl;	

			}
			else if (line.getArg4()==""){
				Player player(line.getArg1(), line.getArg2(), "", line.getArg4());
				player.setDesiredNumber(line.getArg3());
				freeAgents[numFreeAgents] = player; numFreeAgents++;
			}
			//else if (line.getArg3() == int)
			//Error: arg3 (<number>): r is not an integer
			else{		
			//around here
				flag=false;
				for (int i=0; i< numTeams; i++){
					if (league[i].getName()==line.getArg4()){
						if(league[i].getNumOfPlayers()<12){
							if (league[i].numTaken(line.getArg3())){
								other =	league[i].getLowest();	
							}
							else{
								other = line.getArg3();
							}
							Player player(line.getArg1(), line.getArg2(), other, line.getArg4());
							player.update(other, line.getArg4());
							player.setDesiredNumber(line.getArg3());
							league[i].addPlayer(player);	
							flag=true;
							cout << endl;		
						}				
					}			
				}
				if (flag==false){
					Player player(line.getArg1(), line.getArg2(), "","");
					freeAgents[numFreeAgents] = player;
					numFreeAgents++;
					cout <<	"Team " << line.getArg4() << " does not exist."<< endl;
					cout << "Adding player " << line.getArg1() << " to free agents." <<endl << endl;
				}
				
			}
		}
		else if (line.getOperation() == "League"){
			if (line.getArg1() !=""){
				cout << endl << "Ignoring unexpected arguments" << endl;	

			}
			cout << "Teams: " << numTeams << endl;
			for (int i =0;i < numTeams; i++){
				league[i].show();
				cout << endl;
			}
			//cout << endl<<endl;
		}
		else if (line.getOperation() == "Roster"){
			if (line.getArg2() !=""){
				cout << endl << "Ignoring unexpected arguments" << endl;	

			}
			if (line.getArg1() ==""){
				cout << "Free agents:" << endl;
				for (int i=0; i<numFreeAgents; i++){
					freeAgents[i].freeShow();				
				} 
				cout << endl;

			}
			else{
				flag3=false;
				for (int i=0; i< numTeams; i++){
					if (league[i].getName()==line.getArg1()){
						league[i].show();
						cout << endl;	
						cout << "   Players:"<< endl;
						league[i].printRoster();
						flag3 = true;
					
					}			
				}
				if (flag3==false){
					cout << "Could not find team with nickname of " << line.getArg1() << endl;
				} 
				cout << endl;
			}	
		}	
		else if (line.getOperation() == "Release"){
			if (line.getArg3() !=""){
				cout << endl << "Ignoring unexpected arguments" << endl;	

			}
			if (line.getArg2() ==""){
				cout << endl << "Can't operate with missing arguments" << endl;	

			}
			else{
				flag4 =-1;
				for (int i=0; i<numTeams; i++){
					if (league[i].getName() == line.getArg2()){flag4=i;}				
				}
				if (flag4!=-1){
					if (league[flag4].isInTeam(line.getArg1())){
						freeAgents[numFreeAgents] = league[flag4].removePlayer(line.getArg1());
						numFreeAgents++;					
					}	
					else{
						cout << "Player " << line.getArg1() << " is not currently on team " << line.getArg2() << endl << endl;					
					}		
				}
				else{
					cout << "Team " << line.getArg2() << " does not exist." << endl << endl;		
				}
			}
		
		}	
		else if (line.getOperation() == "Sign"){
			if (line.getArg3() !=""){
				cout << endl << "Ignoring unexpected arguments" << endl;	

			}
			if (line.getArg2() ==""){
				cout << endl << "Can't operate with missing arguments" << endl;	

			}
			else{
				flag6 =-1;
				flag4 =-1;
				for (int i=0; i<numTeams; i++){
					if (league[i].getName() == line.getArg2()){flag4=i;}				
				}
				for (int i=0; i<numFreeAgents; i++){
					if (freeAgents[i].getName()==line.getArg1()){
						flag6 =i;					
					}				
				}
				if (flag4!=-1){
					if (flag6!=-1){
						if (league[flag4].numTaken(freeAgents[flag6].getPreferred())){
							other =	league[flag4].getLowest();	
						}
						else{
							other = freeAgents[flag6].getPreferred();
							}
						freeAgents[flag6].update(other, league[flag4].getName());
						league[flag4].addPlayer(freeAgents[flag6]);
						freeAgents[flag6].reset();
						numFreeAgents--;
						for (int j = flag6; j < numFreeAgents-1; ++j){
						freeAgents[j] = freeAgents[j + 1];
						}			
						
					}	
					else{
						cout << "Player " << line.getArg1() << " is not a free agent." << endl << endl;					
					}		
				}
				else{
					cout << "Team " << line.getArg2() << " does not exist." << endl << endl;		
				}
				
			}
		
		}
		else if (line.getOperation()== "Career"){
			if (line.getArg2() !=""){
				cout << endl << "Ignoring unexpected arguments" << endl;	

			}
			if (line.getArg1() ==""){
				cout << endl << "Can't operate with missing arguments" << endl;	

			}
			else{
				flag5=false;
				for (int i=0; i<numFreeAgents; i++){
					if (freeAgents[i].getName() == line.getArg1()){
						freeAgents[i].showCareer();
						flag5=true;					
					}
				}
				for (int i=0; i<numTeams; i++){
					if(league[i].isInTeam(line.getArg1())){
						league[i].showCareer(line.getArg1());
						flag5=true;
					}
										
				}
				if (flag5==false){
					cout << "Could not find player with last name of f" << endl << endl;
				}
			}
		
		}

		else {
			cout <<endl <<	"Command not recognized. Please try again." << endl;
		}
		
		cout << endl <<"Enter a command:" << endl;
   	cout << "Choose from" << endl;
   	cout << "   Team <Location> <team-nickname>"<<endl;
   	cout << "   Player <firstname> <lastname> <number> [<team-nickname>]" << endl;
   	cout << "   League" << endl;
   	cout << "   Roster [<team-nickname>]" << endl;
   	cout << "   Release <lastname> <team-nickname>" << endl;
   	cout << "   Sign <lastname> <team-nickname>" << endl;
   	cout << "   Career <lastname>" << endl;
   	cout << "   Trade" << endl;
   	cout << "   Quit" << endl << ": ";
   	getline(cin,command,'\n');
   }
  
   delete []freeAgents;
   for (int i=0; i<numTeams; i++){
		league[i].deletePlayers();	
   }
   delete []league;
}
