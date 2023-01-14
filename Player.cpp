#include "Player.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

      Player::Player(string fName, string lName, string num, string newTeam) {
         playerFName = fName;
         playerLName = lName;
	 		jerseyNumber = num;
	 		team = newTeam;
	 		desiredNumber = num;
	 		career = "";
	 		//active = newActive;
      }

      Player::Player() {
         playerFName = "";
         playerLName = "";
         jerseyNumber = "";
         team = "";
         desiredNumber = "";
         career = "";
         //active = false;
      }
      void Player::show() {
      	string x;
      	//if(active == true){x="[active]";}
      	//else{x="[not active]";}
         cout << playerLName << ", " << playerFName << " (#" << jerseyNumber << ")  "<< x << endl;
      }
      void Player::setDesiredNumber(string x) {
      	desiredNumber =x;
      }
      void Player::reset(){
			playerFName = "";
         playerLName = "";
         jerseyNumber = "";
         team = "";
         desiredNumber = "";
      }
      void Player::showCareer(){
      	cout << "Career of " << playerLName << endl;
      	cout << career << endl;
      }
      void Player::update(string num, string newTeam){
			jerseyNumber = num;
			team = newTeam;
			career += newTeam + " (#" + num +")\n";
      }
      void Player::released(){
      	jerseyNumber ="";
      	team = "";
      }
      void Player::freeShow(){
      	cout << playerLName << ", " << playerFName << endl;
      }
