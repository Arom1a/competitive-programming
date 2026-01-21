#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

struct playerInfo {
    int id;
    int score;
    int numOfToss;
};

bool cmpPlayerInfo(const playerInfo &a, const playerInfo &b) {
    if (a.score == b.score) return a.numOfToss < b.numOfToss;
    return a.score > b.score;
}

string scoreTosses(int numPlayers, vector<string> tosses) {
    vector<playerInfo> scoreBoard(numPlayers);
    for (int i = 0; i < numPlayers; i++) {
        scoreBoard[i].id = i + 1;
    }

    for (int i = 0; i < numPlayers; i++) {
        stringstream ss(tosses[i]);
        string word;
        int score = 0;
        int numOfToss = 0;
        while (ss >> word) {
            int t = 0;
            numOfToss++;
            if (word.back() == '+') {
                score += 2;
                word = word.substr(0, word.length() - 1);
            }
            if (word.length() == 1) {
                if (word[0] == 'A' || word[0] == 'R') t += 1;
                if (word[0] == 'O' || word[0] == 'G') t += 3;
                if (word[0] == 'B') t += 6;
            } else {
                t += 1;

                if (word[0] == 'A' || word[0] == 'R') t += 1;
                if (word[0] == 'O' || word[0] == 'G') t += 3;
                if (word[0] == 'B') t += 6;

                if (word[1] == 'A' || word[1] == 'R') t += 1;
                if (word[1] == 'O' || word[1] == 'G') t += 3;
                if (word[1] == 'B') t += 6;
            }
            score += t;
        }
        scoreBoard[i].score = score;
        scoreBoard[i].numOfToss = numOfToss;
    }

    sort(scoreBoard.begin(), scoreBoard.end(), cmpPlayerInfo);

    string rtn = "";
    for (playerInfo i : scoreBoard) {
        rtn += to_string(i.id) + "-" + to_string(i.score) + ' ';
    }

    return rtrim(rtn);
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string numPlayers_temp;
    getline(cin, numPlayers_temp);

    int numPlayers = stoi(ltrim(rtrim(numPlayers_temp)));
    string tosses_count_temp;
    getline(cin, tosses_count_temp);

    int tosses_count = stoi(ltrim(rtrim(tosses_count_temp)));

    vector<string> tosses(tosses_count);
    for (int i = 0; i < tosses_count; i++) {
        string tosses_item;
        getline(cin, tosses_item);

        tosses[i] = tosses_item;
    }

    string result = scoreTosses(numPlayers, tosses);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());

    return s;
}
