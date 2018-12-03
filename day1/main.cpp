#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <set>

int main() {

    std::string line;
    std::vector<int> original;
    
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int input = 0;
        iss >> input;

        original.push_back(input);
    }

    std::cout << "frequency: " << std::accumulate(original.begin(), original.end(), 0) << '\n';

    bool found = false;
    int repeated;
    std::set<int> accumulated;
    int acc = 0;
    accumulated.insert(acc);
    while (!found)
    {
        for (int i = 0; i < original.size() && !found; ++i)
        {
            acc += original[i];
            auto result = accumulated.insert(acc);
            if (!result.second)
            {
                found = true;
                repeated = acc;
                break;
            }
            
        }
    }

    if (found)
    {
        std::cout << "Repeated: " << repeated << '\n'; 
    }

    return 0;
}