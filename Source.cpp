#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <sstream>
#include <stack>

bool isValidBracketSequence(const std::string& sequence) {
    std::stack<char> brackets;

    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            brackets.push(bracket);
        }
        else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (brackets.empty()) {
                return false;
            }

            char top = brackets.top();
            brackets.pop();

            if ((top == '(' && bracket != ')') || (top == '[' && bracket != ']') || (top == '{' && bracket != '}')) {
                return false;
            }
        }
    }

    return brackets.empty();
}
bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*";
}


int main() {

    /* Task A. Different */
    std::cout << " Task A. Different" << std::endl;
    int n;
    std::cin >> n;

    std::set<int> numbers;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        numbers.insert(num);
    }

    std::cout << numbers.size() << std::endl;

    /* Task B. Lists by class */
    std::map<int, std::vector<std::string>> studentsByClass;

    int classNum;
    std::string name;

    while (std::cin >> classNum >> name && name != "0") {
        studentsByClass[classNum].push_back(name);
    }

    for (int i = 9; i <= 11; ++i) {
        for (const auto& name : studentsByClass[i]) {
            std::cout << i << " " << name << std::endl;
        }
    }

    /* Task D. The correct bracket sequence */
    std::cout << "Task D. The correct bracket sequence" << std::endl;
    std::string sequence;
    std::cin >> sequence;

    if (isValidBracketSequence(sequence)) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }

    /* Task G. Hashing with deletion */
    std::cout << "Task G. Hashing with deletion" << std::endl;
    std::set<std::string> stringSet;
    std::string operation, word;

    while (std::cin >> operation >> word) {
        if (operation == "+") {
            stringSet.insert(word);
        }
        else if (operation == "-") {
            stringSet.erase(word);
        }
        else if (operation == "?") {
            if (stringSet.find(word) != stringSet.end()) {
                std::cout << "YES" << std::endl;
            }
            else {
                std::cout << "NO" << std::endl;
            }
        }
        else if (operation == "#") {
            break;
        }
    }

    return 0;
}

