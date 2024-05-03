#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


void readList(const string& input, char& assignment, vector<int>& problems) {
    istringstream iss(input);
    iss >> assignment; // Read the assignment letter

    
    int num;
    char comma;
    while (iss >> num) {
        problems.push_back(num);
        if (!(iss >> comma)) // Check for comma 
            break;
    }
}


void printProblems(char assignment, const vector<int>& problems) {
    cout << "Do problems ";
    for (size_t i = 0; i < problems.size(); ++i) {
        cout << problems[i];
        if (i < problems.size() - 1)
            cout << ", ";
    }
    cout << " of " << assignment << "." << endl;
}

// generate the list of problems 
vector<int> ProblemList(const vector<int>& problems) {
    vector<int> problemList;
    for (size_t i = 0; i < problems.size(); ++i) {
        if (i < problems.size() - 1 && problems[i] < problems[i + 1]) {
            
            for (int j = problems[i]; j <= problems[i + 1]; ++j)
                problemList.push_back(j);
            ++i; 
        } else {
            // if single problem
            problemList.push_back(problems[i]);
        }
    }
    // Remove duplicates and sort
    sort(problemList.begin(), problemList.end());
    problemList.erase(unique(problemList.begin(), problemList.end()), problemList.end());
    return problemList;
}

int main() {
    string input;
    cout << "Please enter the assignment: ";
    getline(cin, input);

    char assignment;
    vector<int> problems;
    readList(input, assignment, problems);

    vector<int> problemList = ProblemList(problems);
    printProblems(assignment, problemList);

    return 0;
}

