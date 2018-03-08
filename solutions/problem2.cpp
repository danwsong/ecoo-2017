/*
 This problem, like the last one, is also fairly straightforward. Inputting the
 datasets might be a little bit tricky considering the number of judges isn't
 specified, but it can be done. In order to actually solve the problem, run 
 through multiple rounds of comparing the various scores of the chocolates,
 eliminating the chocolates that do not have or are not tied for the highest score.
 Then, simply output the names of the chocolates that remain, inserting commas if 
 there are chocolates still tied after the multiple rounds.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int highest(vector<int> list) {
    int maxList = 0;
    for (int i = 0; i < list.size(); i++) {
        maxList = max(maxList, list[i]);
    }
    return maxList;
}

vector<int> winners(vector<int> list) {
    int maxList = highest(list);
    vector<int> winnerList;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == maxList) {
            winnerList.push_back(i);
        }
    }
    return winnerList;
}

int main(int argc, const char * argv[]) {
    freopen("DATA21.txt", "r", stdin);
    
    int N;
    while (cin >> N) {
        vector<string> chocolate(N);
        vector<int> factors1(N), factors2(N), factors3(N), total(N);
        string name;
        for (int i = 0; i < N; i++) {
            if (i == 0)
                cin >> name;
            chocolate[i] = name;
            cin >> name;
            while (name == "J") {
                int temp;
                cin >> temp;
                factors1[i] += temp;
                cin >> temp;
                factors2[i] += temp;
                cin >> temp;
                factors3[i] += temp;
                cin >> name;
            }
            total[i] = factors1[i] + factors2[i] + factors3[i];
        }
        
        vector<int> totalWinners = winners(total);
        vector<int> eliminationFactors3(N);
        for (int i = 0; i < totalWinners.size(); i++) {
            eliminationFactors3[totalWinners[i]] = factors3[totalWinners[i]];
        }
        vector<int> factors3Winners = winners(eliminationFactors3);
        vector<int> eliminationFactors2(N);
        for (int i = 0; i < factors3Winners.size(); i++) {
            eliminationFactors2[factors3Winners[i]] = factors2[factors3Winners[i]];
        }
        vector<int> factors2Winners = winners(eliminationFactors2);
        vector<int> eliminationFactors1(N);
        for (int i = 0; i < factors2Winners.size(); i++) {
            eliminationFactors1[factors2Winners[i]] = factors1[factors2Winners[i]];
        }
        vector<int> factors1Winners = winners(eliminationFactors1);
        for (int i = 0; i < factors1Winners.size(); i++) {
            cout << chocolate[factors1Winners[i]];
            if (i != factors1Winners.size() - 1)
                cout << ", ";
        }
        cout << endl;
    }
    
    return 0;
}
