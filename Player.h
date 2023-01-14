#include <iostream>
#include <stdlib.h>
using namespace std;
class Player {
   public:
      Player(string fName, string lName, string num, string newTeam);
         

      Player();
         

      void show();
      void setDesiredNumber(string x);
      string getNum(){return jerseyNumber;}
      string getName(){return playerLName;}
      void reset();
      void showCareer();
      string getPreferred(){return desiredNumber;}
      void update(string num, string newTeam);
      void released();
      void freeShow();

   private:
      string playerFName = "";
      string playerLName = "";
      string jerseyNumber = "";
      string desiredNumber = "";
      string team= "";
      string career="";
      //bool active = false;
};
