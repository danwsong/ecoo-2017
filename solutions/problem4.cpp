/*
 An O(n log n) solution exists to determine the number of swaps required to
 sort a list. Thus, by iterating through each name in the list and removing
 it, and determining the number of swaps required to sort each of the lists
 with one omitted name, a solution to the problem can be determined.
 
 To sort the list in the minimum number of swaps, a name is put in its 
 correct index, the name already at that index is put into its correct 
 index and so on. This process is repeated until the list is sorted. This 
 shows the cycles that form with this sorting process, with the number of 
 swaps in a cycle equal to the length of the cycle minus 1. Thus, the total 
 number of swaps is equal to the sums of the lengths of the cycles required 
 to sort the list, each minus 1.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int swaps(vector<string> list) {
    // A map that stores the correct position of a certain indexed name
    vector< pair<string, int> > key(list.size());
    for (int i = 0; i < list.size(); i++) {
        key[i].first = list[i];
        key[i].second = i;
    }
    sort(key.begin(), key.end());
    
    // List to store names in the list are already at the correct index
    vector<bool> sorted(list.size(), false);
    int swaps = 0;
    for (int i = 0; i < list.size(); i++) {
        // No need to swap if a name is at the correct index or has been swapped
        if (sorted[i] || key[i].second == i)
            continue;
        int cycle = 0, start = i;
        // Continue swapping until the beginnning of the cycle is reached
        while (!sorted[start]) {
            sorted[start] = true;
            // Follow the cycle to the next name to be swapped
            start = key[start].second;
            // Added one to the cycle length
            cycle++;
        }
        // Add the cycle length minus 1 to the swaps
        swaps += cycle - 1;
    }
    return swaps;
}

int main(int argc, const char * argv[]) {
    freopen("DATA41.txt", "r", stdin);
    int N;
    while (cin >> N) {
        vector<string> names(N);
        for (int i = 0; i < N; i++) {
            cin >> names[i];
        }
        int minSwaps = 0x7FFFFFFF;
        for (int i = 0; i < N; i++) {
            vector<string> omit = names;
            omit.erase(omit.begin() + i);
            minSwaps = min(minSwaps, swaps(omit));
        }
        cout << minSwaps << endl;
    }
    
    return 0;
}
