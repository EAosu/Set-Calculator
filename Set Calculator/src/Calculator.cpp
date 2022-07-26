#include "Calculator.h"
#include "Macros.h"

// C-tor.
Calculator::Calculator()
{
	initCalc();
}

// Initiates the calculator with the 3 base operations.
void Calculator::initCalc()
{
	this->m_operations.push_back(std::make_shared<Uni>(std::make_shared<Identity>(), std::make_shared<Identity>(), UNION));
	this->m_operations.push_back(std::make_shared<Inter>(std::make_shared<Identity>(), std::make_shared<Identity>(), INTER));
	this->m_operations.push_back(std::make_shared<Diff>(std::make_shared<Identity>(), std::make_shared<Identity>(), DIFF));
}

// Main function of the program - runs the calculator.
void Calculator::run()
{
	string command = "start"; // Set for visuals only.
	
	// Inf loop
	while (true)
	{
		// Menu
		printMenu();
				
		// Command section
		std::cin.clear();
		std::cin >> command;
		this->handleCmd(command);
	}
}

// Exits the program.
void Calculator::exitCalc() const
{
	std::cout << "Goodbye!";
	exit(EXIT_SUCCESS);
}

// Prints the menu.
void Calculator::printMenu() const
{
	std::cout << listLine;
	int counter = -1;

	// Prints the list of operations.
	while (++counter < this->m_operations.size())
	{
		std::cout << (counter) << ".      ";
		int printCounter = 0; // Print index counter
		this->m_operations[counter].get()->print(printCounter);
		std::cout << "\n";
	}

	std::cout << "\n" << enterLine;
}

// Receives a command as a string and handles it.
void Calculator::handleCmd(const string cmd)
{
	if (cmd == "exit")
		this->exitCalc();

	else if (cmd == "help")
		this->displayHelp();

	else if (cmd == "eval")
		this->evaluate();

	else if (cmd == "del")
		this->deleteOp();

	else // Other commands are used to add new operations.
		this->addNewOp(cmd);
}

// Reads the calculator's input required.
vector<Set> Calculator::initialRead(const int& numofOp) const
{
	vector<Set> readInfo = vector<Set>();

	// Reads sets
	for (int i = 0; i < this->m_operations[numofOp].get()->getNumofSets(); i++)
	{
		int sizeofSet;
		std::cin >> sizeofSet;

		if (sizeofSet < 0)
			std::cout << "Invalid size, set to empty.\n";

		readInfo.push_back(Set(sizeofSet));
	}

	return readInfo;
}

// Displays the list of commands.
void Calculator::displayHelp() const
{
	std::cout << "\n" << "//------------------------------" << "\n";

	for (int i = 0; i < numofCmds; i++)
		std::cout << cmds[i] << "\n";

	std::cout << "//------------------------------" << "\n" << "\n";
}

// Handles the "eval" command.
void Calculator::evaluate() const
{
	int numofOp;
	std::cin >> numofOp;

	vector<Set> sets = initialRead(numofOp);

	if (this->inLim(numofOp))
	{
		Set result = this->m_operations[(size_t)numofOp].get()->calculate(sets);
		std::cout << " = " << result << "\n";
	}
	else
		this->inputErr();
}

// Message for input error.
void Calculator::inputErr() const
{
	std::cout << "Invalid input.\n";
}

// Checks if an input from the user is in the limits.
bool Calculator::inLim(const int num) const
{
	return (num < this->m_operations.size() && num >= 0);
}

// Checks if the inserted command is a valid command in the program.
bool Calculator::isACmd(const string cmd) const
{
	return (cmd == "uni" ||
			cmd == "inter" ||
			cmd == "diff" ||
			cmd == "prod" ||
			cmd == "comp");
}

// Adds a new operation as described by the user.
void Calculator::addNewOp(const string cmd)
{
	if (!this->isACmd(cmd))
	{
		this->inputErr();
		return;
	}

	// Reads two numbers of operations from the user.
	int numofOp1, numofOp2;
	std::cin >> numofOp1;
	std::cin >> numofOp2;
	
	// Makes sure the numbers are valid.
	if (this->inLim(numofOp1) && this->inLim(numofOp2))
	{
		if (cmd == "uni")
			this->m_operations.push_back(std::make_shared<Uni>(this->m_operations[(size_t)numofOp1], this->m_operations[(size_t)numofOp2], UNION));

		else if (cmd == "inter")
			this->m_operations.push_back(std::make_shared<Inter>(this->m_operations[(size_t)numofOp1], this->m_operations[(size_t)numofOp2], INTER));

		else if (cmd == "diff")
			this->m_operations.push_back(std::make_shared<Diff>(this->m_operations[(size_t)numofOp1], this->m_operations[(size_t)numofOp2], DIFF));

		else if (cmd == "prod")
			this->m_operations.push_back(std::make_shared<Prod>(this->m_operations[(size_t)numofOp1], this->m_operations[(size_t)numofOp2], PROD));

		else if (cmd == "comp")
			this->m_operations.push_back(std::make_shared<Comp>(this->m_operations[(size_t)numofOp1], this->m_operations[(size_t)numofOp2], COMP));
	}
	else
		this->inputErr(); 
}

// Deletes an existing operation.
void Calculator::deleteOp()
{
	int opToDelete;
	std::cin >> opToDelete;

	if (this->inLim(opToDelete))
	{
		this->m_operations[opToDelete].reset();
		this->m_operations.erase(this->m_operations.begin() + opToDelete);
	}
}
