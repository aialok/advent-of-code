#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> list1, list2;

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
        list2.push_back(right);
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    long long total_distance = 0;
    for (size_t i = 0; i < list1.size(); ++i)
    {
        total_distance += llabs(list1[i] - list2[i]);
    }

    cout << total_distance << endl;
    return 0;
}
