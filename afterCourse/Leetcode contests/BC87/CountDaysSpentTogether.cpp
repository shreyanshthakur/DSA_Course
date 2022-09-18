#include<iostream>
#include<string>
using namespace std;
int convertDateToDays (string s, int monthToDays[]) {
        int month = (s[0]-'0') * 10 + (s[1]-'0');
        int monthDaysSum = 0;
        for (int i = 0; i < month; i++) {
            monthDaysSum += monthToDays[i];
        }
        //cout << monthDaysSum << endl;
        return monthDaysSum + (s[3]-'0') * 10 + (s[4]-'0');
}
int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int monthToDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aa = convertDateToDays(arriveAlice, monthToDays);
        int la = convertDateToDays(leaveAlice, monthToDays);
        int ab = convertDateToDays(arriveBob, monthToDays);
        int lb = convertDateToDays(leaveBob, monthToDays);
        int count = 0;
        for (int i = 1; i <= 365; i++) {
            if (aa <= i && la >= i && ab <= i && lb >= i) {
                count++;
            }
        }
        return count;
    }
int main() {
    int monthToDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string s = "12-31";
    cout << convertDateToDays(s, monthToDays);
    return 0;
}