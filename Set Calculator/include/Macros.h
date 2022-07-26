#pragma once
// Macros of the program.
const char* listLine = "List of available set operations:\n";
const char* enterLine = "Enter command ('help' for the list of available commands): ";
const int numofCmds = 10;
const char* cmds[numofCmds] = { "The available commands are:",
							    "* eval(uate) num set1 set2 ... - Computes the result of function #num on the following set(s); each set is prefixed with the count of numbers to read.",
								"* uni(on) num1 num2 - Creates an operation that is the Uni of operation #num1 and operation #num2.",
								"* inter(section) num1 num2 - Creates an operation that is the intersection of operation #num1 and operation #num2.",
								"* diff(erence) num1 num2 - Creates an operation that is the difference of operation #num1 and operation #num2.",
								"* prod(uct) num1 num2 - Creates an operation that returns the product of the items from the results of operation #num1 and operation #num2.",
								"* comp(osite) num1 num2 - Creates an operation that is the composition of operation #num1 and operation #num2.",
								"* del(ete) num - Deletes operation #num from the operation list.",
								"* help - Prints this commands list.",
								"* exit - Exits the program."};