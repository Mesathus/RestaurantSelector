// RestaurantSelector.cpp : Defines the entry point for the console application.
//
/*

	Author: John O'Brien
	Version: 1.0
	Origin Date: 6/6/2018
	Last Update: 6/6/2018

	Program goals:

	You have a group of friends coming to visit for your high school reunion and you want to 
	take them out to eat at a local restaurant. You aren't sure if any of them have dietary 
	restrictions, but your restaurant choices are as follows:
	Joe's Gourmet Burgers- Vegetarian: No, Vegan: No, Gluten-free: No
	Main street Pizza Company - Vegetarian: Yes, Vegan: No, Gluten-free: Yes
	Corner Café - Vegetarian: Yes, Vegan: Yes, Gluten-free: Yes
	Mama's fine Italian - Vegetarian: Yes, Vegan: No, Gluten-free: No
	The Chef's Kitchen - Vegetarian: Yes, Vegan: Yes, Gluten-free: Yes
	Write a program that asks whether any members of your party are vegetarian, vegan or 
	gluten-free, then display only the restaurants that you may take the group to. 
	Here is an example of the program's output:
	Is anyone in your party a vegetarian? yes->enter
	Is anyone in your party a vegan? no->enter
	Is anyone in your party gluten-free? yes->enter
	Here are your restaurant choices:
	 Main Street Pizza Company
	 Corner Café
	 The Chef's Kitchen
	Here is another example of the program's output
	Is anyone in your party a vegetarian? yes->enter
	Is anyone in your party a vegan? yes->enter
	Is anyone in your party gluten-free? yes->enter
	Here are your restaurant choices:
	 Corner Café
	 The Chef's Kitchen
*/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


bool CheckString(string checking)	//module to check if the user has enter an affirmative
{
	if (checking == "Yes") { return true; }
	else if (checking == "yes") { return true; }
	else if (checking == "y") { return true; }
	else if (checking == "Y") { return true; }
	else { return false; }
}

bool CheckNo(string checking)	//module to check if the user has entered a negative response
{
	if (checking == "No") { return true; }
	else if (checking == "no") { return true; }
	else if (checking == "n") { return true; }
	else if (checking == "N") { return true; }
	else { return false; }
}

int main()
{
	bool veg = false, vegan = false, gluten = false;	//flags for dietary restrictions
	string hasAllergy;	//string to hold user yer/no input
	bool results = false;	//control to set validated input
	while (!results)	//input validation for the first dietary restriction question
	{
		cout << "Is anyone in your party a vegetarian?  ";
		getline(cin, hasAllergy);	//assign user input to a string
		if (CheckString(hasAllergy))	//check if the user input yes to dietary restriction
		{
			veg = true;	//set vegetarian flag
			results = true;
			break;	//exit loop
		}
		else if (CheckNo(hasAllergy))	//check to see if user entered no
		{
			break;	//exit loop
		}
		else		//directions for user if they entered invalid input
		{
			cout << "Please enter your response in the form of Yes/yes/Y/y or No/no/N/n." << endl;
		}
	}
	results = false;	//reset the loop control
	while (!results)	//repeat the first loop logic for the vegan flag
	{
		cout << "Is anyone in your party a vegan?  ";
		getline(cin, hasAllergy);
		if (CheckString(hasAllergy))
		{
			vegan = true;
			results = true;
			break;
		}
		else if (CheckNo(hasAllergy))
		{
			break;
		}
		else
		{
			cout << "Please enter your response in the form of Yes/yes/Y/y or No/no/N/n." << endl;
		}
	}
	results = false;
	while (!results)	//repeat the first/second loop logic for the celiac flag
	{
		cout << "Does anyone in your party have Celiac deisease?  ";
		getline(cin, hasAllergy);
		if (CheckString(hasAllergy))
		{
			gluten = true;
			results = true;
			break;
		}
		else if (CheckNo(hasAllergy))
		{
			break;
		}
		else
		{
			cout << "Please enter your response in the form of Yes/yes/Y/y or No/no/N/n." << endl;
		}
	}
	/*
		Joe's Gourmet Burgers- Vegetarian: No,		Vegan: No,		Gluten-free: No			NNN
		Main street Pizza Company - Vegetarian: Yes, Vegan : No,	Gluten - free : Yes		YNY
		Corner Café - Vegetarian : Yes,				Vegan : Yes,	Gluten - free : Yes		YYY
		Mama's fine Italian - Vegetarian: Yes,		Vegan: No,		Gluten-free: No			YNN
		The Chef's Kitchen - Vegetarian: Yes,		Vegan: Yes,		Gluten-free: Yes		YYY
	*/
	cout << "Your restaurant options are: " << endl;
	if (veg && vegan && gluten)		//decision structure to select restaurant outputs
	{
		cout << "Corner Cafe" << endl << "The Chef's Kitchen" << endl;
	}
	else if (veg && gluten)
	{
		cout << "Corner Cafe" << endl << "The Chef's Kitchen" << endl <<
			"Main street Pizza Company" << endl;
	}
	else if (veg)
	{
		cout << "Corner Cafe" << endl << "The Chef's Kitchen" << endl <<
			"Main street Pizza Company" << endl << "Mama's fine Italian" << endl;
	}
	if(!veg && !vegan && !gluten)
	{
		cout << "Joe's Gourmet Burgers" << endl << "Main street Pizza Company" << endl
			<< "Corner Cafe" << endl << "Mama's fine Italian" << endl << "The Chef's Kitchen" << endl;
	}	
	cin.get();	//pause the console for the user
    return 0;
}

