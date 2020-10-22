//Author: Rauls Bergs
//Student ID: 21/10/2020

//Headers
#include "main.h"

int main()
{
	srand( time ( NULL ) );

	//Different Game States for interactive Menus;
	enum gameState{OptionMenuState , scanForShipsState , displayLaunchCodeState ,
				   launchAttackState , selectMissileTypeState}; 

	//variable to control whats displayed to the user
	m_currentGameState = OptionMenuState;

	//Displays all the different option menus for the control panel while user is on the menu screen;
	while (playerOnline == true)
	{
		if (m_currentGameState == OptionMenuState)
		{
			m_menuProcessing();
		}
		if (m_currentGameState == scanForShipsState)
		{
			m_scanForShips();
		}
		if (m_currentGameState == displayLaunchCodeState)
		{
			m_displayLaunchCode();
		}
		if (m_currentGameState == launchAttackState)
		{
			launchAttack();
		}
		if (m_currentGameState == selectMissileTypeState)
		{
			selectMissileType();
		}
	}
	return 1;
}

void m_scanForShips::getShipLocation(int t_amountOfShipPositions)
{
	std::cout << "---Scanning For Ships---" << std::endl << std::endl;

	for (int i = 0; i < t_amountOfShipPositions; i ++)
	{
		x_coOrdinate = rand() % 100 + 1;
		y_coOrdinate = rand() % 100 + 1;

		m_shipXLocations[i] = x_coOrdinate;
		m_shipYLocations[i] = y_coOrdinate;

		std::cout << "ship position: " << std::to_string(m_shipXLocations[i]) << " , " << std::to_string(m_shipYLocations[i]) << std::endl;
		std::cout << "________________________________________" << std::endl;
	}
	std::cout << "Back to Menu (1):  ";

	std::cin >> m_changeMenuState;
	while (m_changeMenuState != 1)
	{
		std::cout << "Please enter (1) to return to the option screen:  " << std::endl;
		std::cin >> m_changeMenuState;
	}
	std::cout << std::endl;
	m_currentGameState = m_changeMenuState - 1;
	
}

void launchAttack::inputLaunchCode()
{
	std::cout << "Please enter the launch code:  ";
	std::cin >> launchCodeInput; //User inputs the code they recived from the system

	std::cout << std::endl;

	if (launchCodeInput != m_launchCode)
	{
		m_currentGameState = 0;
	}
	else if (launchCodeInput == m_launchCode)
	{
		processAttack();
	}
}

void launchAttack::processAttack()
{
	int missileLaunchLocation[2];

	std::cout << "please enter the x co-ordinates you want to launch your missile at:   ";
	std::cin >> missileLaunchLocation[0];
	std::cout << std::endl;

	std::cout << "please enter the y co-ordinates you want to launch your missile at:   ";
	std::cin >> missileLaunchLocation[1];
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		if (m_shipXLocations[i] == missileLaunchLocation[0] && m_shipYLocations[i] == missileLaunchLocation[1])
		{
			std::cout << "A ship has been Destroyed!" << std::endl;
			m_amountOfEnemyShips -= 1;
			std::cout << "Remaining Enemy Ships:   " << std::to_string(m_amountOfEnemyShips) << std::endl;
		}
	}

	if (m_amountOfEnemyShips == 0)
	{
		std::cout << "The enemy has been defeated!" << std::endl;
		playerOnline = false;
	}

	m_currentGameState = 0;
}

void selectMissileType::selectMissileProcessing()
{
	std::cout << "---Select Missile Type Menu---" << std::endl << std::endl;

	std::string missileTypeNames[3];

	missileTypeNames[0] = "SS_N_2_Styx";
	missileTypeNames[1] = "Exocet_AShM";
	missileTypeNames[2] = "P_700_Granit";

	std::cout << "  --  SS_N_2_Styx  " << "--  Exocet_AShM  --" << "  P_700_Granit  --" << std::endl;
	std::cout << "Please choose a Missile by Inputting a number between (1 - 3):      ";
	std::cin >> chosenMissile;
	std::cout << std::endl;

	while (chosenMissile > 3 || chosenMissile < 1)
	{
		std::cout << "Please enter a Number between 1 and 3:     " << std::endl;
		std::cin >> chosenMissile;
		std::cout << std::endl;
	}

	std::cout << "You have selected the:  " << missileTypeNames[chosenMissile - 1] << std:: endl;

	m_currentGameState = 0;
}

void m_displayLaunchCode::generateLaunchCode()
{
	std::cout << "---Launch Missile Code Menu---" << std::endl << std::endl;

	int randomNumber = rand() % 9000 + 1000;
	std::cout << "Launch Missile Code { " << randomNumber << " }" << std::endl;

	m_launchCode = randomNumber;

	std::cout << "Back to Menu (1):  ";

	std::cin >> m_changeMenuState;
	while (m_changeMenuState != 1)
	{
		std::cout << "Please enter (1) to return to the option screen:  ";
		std::cin >> m_changeMenuState;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	m_currentGameState = m_changeMenuState - 1;
}

void m_menuProcessing::setUpMenuScreen()
{
	std::cout << "---Option Screen---" << std::endl << std::endl;;

	std::cout << "Option Menu (1)" << std::endl;
	std::cout << "________________________________________" << std::endl;
	std::cout << "Scan for Ship Locations (2)" << std::endl;
	std::cout << "________________________________________" << std::endl;
	std::cout << "Display Current Launch Code (3)" << std::endl;
	std::cout << "________________________________________" << std::endl;
	std::cout << "Launch Attack (4)" << std::endl;
	std::cout << "________________________________________" << std::endl;
	std::cout << "Select Missile (5)" << std::endl;
	std::cout << "________________________________________" << std::endl;

	std::cout << "Please Choose a menu via the number (1 - 5):  ";

	std::cin >> m_changeMenuState;

	while (m_changeMenuState > 5 || m_changeMenuState < 1)
	{
		std::cout << "Please Input a number Between 1 and 5:         ";

		std::cin >> m_changeMenuState;
	}

	std::cout << std::endl;
	m_currentGameState = m_changeMenuState - 1;
}

void m_menuProcessing::processMenuSwitching()
{

}
