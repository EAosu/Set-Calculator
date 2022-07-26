#pragma once

// Includes
#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>

// Usings
using std::string;
using std::vector;

// Other classes' includes and mentions
class Operation;
#include "Uni.h"
#include "Inter.h"
#include "Diff.h"
#include "Identity.h"
#include "Prod.h"
#include "Comp.h"

// Class Calculator oversees the functionality of the calculator.
class Calculator
{
public:
	Calculator(); // C-tor
	~Calculator() = default; // D-tor
	void run(); // Main function of the program
	void printMenu() const;
	void handleCmd(const string cmd);
	void exitCalc() const; // Exit
	void displayHelp() const; // List of cmds
	void evaluate() const;
	void inputErr() const; // Invalid input
	bool inLim(const int num) const; // Limit of the operations
	bool isACmd(const string cmd) const; // A cmd we offer
	vector<Set> initialRead(const int& numofOp) const; // Calculator input

private:
	vector<std::shared_ptr<Operation>> m_operations; // Holds the current operations

	// Private functions
	void initCalc();
	void addNewOp(const string cmd);
	void deleteOp();
};