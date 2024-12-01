#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> list1;
    unordered_map<int, int> count_similarity;

    ifstream inputFile("inputf.in");
    if (!inputFile)
    {
        cerr << "Error: Unable to open input.txt" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
    {
        istringstream linstream(line);
        long long left, right;

        if (!(linstream >> left >> right))
        {
            cerr << "Error: Malformed line: " << line << endl;
            continue;
        }
        list1.push_back(left);
        count_similarity[right]++;
    }

    long long similarity_score = 0;
    for (size_t i = 0; i < list1.size(); ++i)
    {
        if (count_similarity[list1[i]] >= 1)
        {
            similarity_score += list1[i] * count_similarity[list1[i]];
        }
    }

    cout << similarity_score << endl;
    return 0;
}
