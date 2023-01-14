#include "Player.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
class Team {
   public:
      Team(string newLocation, string newName);
      Team();
      void show();
      void printRoster();
      string getName();
      string getFullName();
      void addPlayer(Player player);
      int getNumOfPlayers();
      bool numTaken(string x);
      string getLowest();
      void deletePlayers();
      bool isInTeam(string x);
      Player removePlayer(string x);
      void showCareer(string x);
   private:
      string name = "";
      string location = "";
      int numOfPlayers= 0;
      Player *players;//= new Player[12];
};
