#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double gravity_const;
double launch_angle;
double projectile_vel;
double target_x;
double target_y;

int calculateLaunchAngle()
{
	double target_dist;
	
	target_dist = sqrt(pow(target_x, 2) + pow(target_y, 2));

	launch_angle = 180*asin((-gravity_const*target_dist)/(pow(projectile_vel,2)))/(2*M_PI);

	cout << endl << "Target distance: " << target_dist << endl << "Launch angle: " << launch_angle << endl << endl;

	return 1;
}

int calculateProjectileVel()
{
	double target_dist;
	
	target_dist = sqrt(pow(target_x, 2) + pow(target_y, 2));

	projectile_vel = sqrt((-gravity_const*target_dist)/sin((2*M_PI*launch_angle)/180));

	cout << endl << "Target distance: " << target_dist << endl << "Projectile velocity: " << projectile_vel << endl << endl;

	return 1;
}

int main()
{
	string input = "";	

	while (true)
	{
		cout << "Please enter a gravitational constant: ";
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> gravity_const)
			break;
		cout << "Invalid gravitational constant, please try again" << endl;
	}

	while (true)
	{
		cout << "Please enter the target X coordinate: ";
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> target_x)
			break;
		cout << "Invalid target X coordinate, please try again" << endl;
	}

	while (true)
	{
		cout << "Please enter the target Y coordinate: ";
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> target_y)
			break;
		cout << "Invalid target Y coordinate, please try again" << endl;
	}

	cout << endl << "Please enter zero for the value you want to calculate." << endl << endl;

	while (true)
	{
		cout << "Please enter a launch angle: ";
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> launch_angle)
			break;
		cout << "Invalid launch angle, please try again" << endl;
	}

	while (true)
	{
		cout << "Please enter a projectile velocity: ";
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> projectile_vel)
			break;
		cout << "Invalid projectile velocity, please try again" << endl;
	}

	if(launch_angle == 0)
		return calculateLaunchAngle();

	if(projectile_vel == 0)
		return calculateProjectileVel();

	cout << endl << "Nothing to calculate" << endl << endl;

	return 1;
}
