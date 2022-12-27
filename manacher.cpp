#include <bits/stdc++.h>

using namespace std;

int lps(string input)
{
    // Preprocess the input to convert it into type abc -> $a$b$c$ to handle even length case.
    // Total size will be 2*n + 1 of this new array.
    string newInput(2 * input.size() + 1, '$');
    for (int i = 0; i < input.size(); i++) newInput[2 * i + 1] = input[i];

    // Create a temporary array for holding the largest palindrome at every point. There are 2*n + 1 such points.
    vector<int> T(newInput.size());
    int start = 0;
    int end = 0;
    // Here i is the center.
    for (int i = 0; i < newInput.size();)
    {
        // Expand around i. See how far we can go.
        while (start > 0 && end < newInput.size() - 1 && newInput[start - 1] == newInput[end + 1])
        {
            start--;
            end++;
        }
        // Set the longest value of palindrome around center i at T[i]
        T[i] = end - start + 1;

        // This is case 2. Current palindrome is proper suffix of input. No need to proceed. Just break out of loop.
        if (end == T.size() - 1)
        {
            break;
        }
        // Mark newCenter to be either end or end + 1 depending on if we're dealing with even or odd number input.
        int newCenter = end + (i % 2 == 0 ? 1 : 0);

        for (int j = i + 1; j <= end; j++)
        {
            //i - (j - i) is left mirror. Its possible left mirror might go beyond current center palindrome. So take minimum
            //of either left side palindrome or distance of j to end.
            T[j] = min(T[i - (j - i)], 2 * (end - j) + 1);
            //Only proceed if we get case 3. This check is to make sure we do not pick j as new center for case 1 or case 4
            //As soon as we find a center lets break out of this inner while loop.
            if (j + T[i - (j - i)] / 2 == end)
            {
                newCenter = j;
                break;
            }
        }
        //make i as newCenter. Set right and left to atleast the value we already know should be matching based of left side palindrome.
        i = newCenter;
        end = i + T[i] / 2;
        start = i - T[i] / 2;
    }
    return *max_element(T.begin(),T.end());
}

int main() {
  cout << lps("abba") << endl;
  cout << lps("abbababba") << endl;
  cout << lps("babcbaabcbaccba") << endl;
  cout << lps("cdbabcbabdab") << endl;
  return 0;
}
