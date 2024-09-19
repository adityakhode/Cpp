#include <iostream>
#include <vector>


using namespace std;

// Global variables
vector<char> operationStack;
vector<float> numberStack = {0};
bool isfloating = false;
char inputChar;
int indexs = 0;
string num;

void displayOp(const vector<char>& stack) 
    {
        for (int i = 0; i<stack.size(); i++) 
            {
                cout << stack.at(i) << " ";
            }
            cout << "\n";
    }

void displayNum(const vector<float>& stack) 
    {
        for (int i = 0; i<stack.size(); i++) 
            {
                cout << stack.at(i) << " ";
            }
        cout << "\n";
    }

void processInput() 
    {
        cin >> inputChar; 

        if (inputChar == '/' || inputChar == '*' || inputChar == '+' || inputChar == '-')
            {
                operationStack.push_back(inputChar);
                //numberStack.at(indexs) = (stof(num));
                numberStack.pop_back();
                numberStack.push_back(stof(num));
                num = "0";
                indexs ++;
                numberStack.push_back(0);
            } 
        else if (inputChar == '.') 
            {
                isfloating = true;
                num += inputChar;
            } 
        else if (isdigit(inputChar)) 
            {
                num += inputChar;
                numberStack.at(indexs) = stof(num);
            }
        // Display current state of stacks
        cout << "NumberStack is: ";
        displayNum(numberStack);
        cout << "OperationStack is: ";
        displayOp(operationStack);
    }

void process()
    {
        vector<float> tempnumstack = numberStack;
        vector<char> tempopstack = operationStack; 
        float result = 0;

        while (!tempopstack.empty()) 
            {
                for (int i = 0; i<tempopstack.size(); i++) 
                    {
                        if (tempopstack.at(i) == '/')
                            {
                                result = tempnumstack.at(i) / tempnumstack.at(i + 1);
                                tempopstack.erase(tempopstack.begin() + i);             // Remove the operator
                                tempnumstack.erase(tempnumstack.begin() + i);           // Remove first number
                                tempnumstack.at(i) = result;                            // Replace first number with result
                                break;
                            }
                        else
                            {
                                continue;
                            }
                    }
                for (int i = 0; i<tempopstack.size(); i++) 
                    {
                        if (tempopstack.at(i) == '*')
                            {
                                result = tempnumstack.at(i) * tempnumstack.at(i + 1);
                                tempopstack.erase(tempopstack.begin() + i);             // Remove the operator
                                tempnumstack.erase(tempnumstack.begin() + i);           // Remove first number
                                tempnumstack.at(i) = result;                            // Replace first number with result
                                break;
                            }
                        else
                            {
                                continue;
                            }
                    }
                for (int i = 0; i<tempopstack.size(); i++) 
                    {
                        if (tempopstack.at(i) == '+')
                            {
                                result = tempnumstack.at(i) + tempnumstack.at(i + 1);
                                tempopstack.erase(tempopstack.begin() + i);             // Remove the operator
                                tempnumstack.erase(tempnumstack.begin() + i);           // Remove first number
                                tempnumstack.at(i) = result;                            // Replace first number with result
                                break;
                            }
                        else
                            {
                                continue;
                            }
                    }
                for (int i = 0; i<tempopstack.size(); i++) 
                    {
                        if (tempopstack.at(i) == '-')
                            {
                                result = tempnumstack.at(i) - tempnumstack.at(i + 1);
                                tempopstack.erase(tempopstack.begin() + i);             // Remove the operator
                                tempnumstack.erase(tempnumstack.begin() + i);           // Remove first number
                                tempnumstack.at(i) = result;                            // Replace first number with result
                                break;
                            }
                        else
                            {
                                continue;
                            }
                    }
            }
            cout << "Ans : " << tempnumstack.at(0) << "\n\n";
    }

int main() 
    {
        while (true)
            {
                cout << "Enter a number : ";
                processInput();  // Process user input in a loop
                process();       // Process realtime output
            }
        return 0;
    }