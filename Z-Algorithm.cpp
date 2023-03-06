#include <bits/stdc++.h>

using namespace std;

// Calculates the Z array for the specified input string
vector<int> calculateZ(string input)
{
    vector<int> Z(input.size());
    int left = 0;
    int right = 0;
    for (int k = 1; k < input.size(); k++)
    {
        if (k > right)
        {
            left = right = k;
            while (right < input.size() && input[right] == input[right - left])
            {
                right++;
            }
            Z[k] = right - left;
            right--;
        }
        else
        {
            // We are operating inside the box
            int k1 = k - left;
            // If the value does not stretch till the right bound, just copy it
            if (Z[k1] < right - k + 1)
            {
                Z[k] = Z[k1];
            }
            else
            {
                // Otherwise, try to see if there are more matches
                left = k;
                while (right < input.size() && input[right] == input[right - left])
                {
                    right++;
                }
                Z[k] = right - left;
                right--;
            }
        }
    }
    return Z;
}

// Returns a list of all indices where the pattern is found in the text
vector<int> matchPattern(string text, string pattern)
{
    string newString = pattern + "$" + text;
    vector<int> Z = calculateZ(newString);
    vector<int> result;
    for (int i = 0; i < Z.size(); i++)
    {
        if (Z[i] == pattern.size())
        {
            result.push_back(i - pattern.size() - 1);
        }
    }
    return result;
}

int main()
{
    string text = "aaabcxyzaaaabczaaczabbaaaaaabc";
    string pattern = "aaabc";

    vector<int> result = matchPattern(text, pattern);
    for (int index : result)
    {
        cout << index << endl;
    }

    return 0;
}
