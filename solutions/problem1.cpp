/*
 This problem is fairly straightforward. By simply coding in the instructions
 given by the problem on how to determine the amount of funds available for
 the trip the school has and comparing that value to the cost of the trip,
 whether further fundraising is necessary can be determined.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    freopen("DATA11.txt", "r", stdin);
    
    double cost, student;
    while (cin >> cost) {
        vector<double> percentages(4);
        for (int i = 0; i < 4; i++) {
            cin >> percentages[i];
        }
        cin >> student;
        vector<double> students(4);
        int maxIndex = 0, maxStudent = 0, sum = 0;
        for (int i = 0; i < 4; i++) {
            students[i] = floor(percentages[i] * student);
            if (students[i] > maxStudent) {
                maxStudent = students[i];
                maxIndex = i;
            }
            sum += students[i];
        }
        students[maxIndex] += student - sum;
        int funds = students[0] * 12 + students[1] * 10 + students[2] * 7 + students[3] + 5;
        cout << ((funds / 2 < cost) ? "YES" : "NO") << endl;
    }
    
    return 0;
}
