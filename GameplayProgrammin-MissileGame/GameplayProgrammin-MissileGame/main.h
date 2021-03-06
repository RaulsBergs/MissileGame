#pragma once

//Headers
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <string>

int m_changeMenuState; //User inputs the number to game state
int m_currentGameState; //Variable that keeps track of the games current state
int m_launchCode; //The launch code
int m_shipXLocations[5]; //stores the enemy ship x locations
int m_shipYLocations[5]; //stores the enemy ship y locations
int m_amountOfEnemyShips = 5; //helps Keep track of ships destroyed
bool playerOnline = true; //bool to exit the game / keep running the game

//Generates & "finds" the ship locations for the user
struct m_scanForShips {
public:
	//Variables
	int x_coOrdinate;
	int y_coOrdinate;

	//Methods
	m_scanForShips() 
	{
		getShipLocation(m_amountOfEnemyShips);
	}
	void getShipLocation(int t_amountOfShips);
};

//This will let the user input the launch code -> then choose location to shoot
struct launchAttack {
public:
	//Variables
	int launchCodeInput;
	int systemLaunchCode;
	int x_coOrdinate;
	int y_coOrdinate;
	int missileLaunchLocation[2];

	//Methods
	launchAttack() 
	{
		inputLaunchCode();
	}
	void inputLaunchCode();
	void processAttack();
};

//Allows user to choose between 3 different missiles to launch at the ships
struct selectMissileType {
public:
	//Variables
	enum missileTypes{ SS_N_2_Styx, Exocet_AShM, P_700_Granit};
	int chosenMissile;

	//Methods
	selectMissileType()
	{
		selectMissileProcessing();
	}
	void selectMissileProcessing();
};

//Generates random 4 digit code for the user to input at the launch attack mode
struct m_displayLaunchCode {
public:
	//Variables

	//Methods
	m_displayLaunchCode()
	{
		generateLaunchCode();
	}

	void generateLaunchCode();
};

struct m_menuProcessing {
	//variables


	//Methods
	m_menuProcessing()//Constructor
	{ 
		setUpMenuScreen();
	}

	void setUpMenuScreen(); //contains everything for the constructor
	void processMenuSwitching(); //Method contains code for switching in and out of different game states
};

