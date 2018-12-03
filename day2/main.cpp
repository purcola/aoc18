#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>

int main() {

    std::string line;
    std::vector<std::string> original;
    
    while (std::getline(std::cin, line)) {
        original.push_back(line);
    }

    auto two = 0;
    auto three = 0;
    for (const auto s: original)
    {
        std::map<char, int> counter;
        for (auto c: s)
            if (counter.count(c) == 0)
                counter[c] = 1;
            else
                counter[c]++;

        int this_two = 0,
            this_three = 0;
        for (auto x: counter)
        {
            if (x.second == 2)
                this_two = 1;
            else if (x.second == 3)
                this_three = 1;
        }

        two += this_two;
        three += this_three;
    }
    
    std::cout << "Checksum: " << two*three << '\n'; 

    for (int i = 0; i < original.size(); ++i)
    {
        const auto si = original[i]; 
        for (int j = 0; j < i; ++j)
        {
            const auto sj = original[j];
            if (si.size() == sj.size())
            {
                int diff = -1; 
                for (int k = 0; k < si.size(); k++)
                {
                    if (si[k] != sj[k])
                    {
                        if (diff == -1)
                            diff = k;
                        else if (diff >= 0)
                            diff = -2; 
                    }
                }

                if (diff > 0)
                {
                    for (auto k = 0; k < si.size(); ++k)
                        if (k != diff)
                            std::cout << si[k];
                    std::cout << '\n';
                    return 0;
                }
            }
        }   
    }

    
    return 0;
}