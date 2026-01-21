#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int calculateBetween(pair<string, string>preRelationPair, pair<string, string>relationPair)
{
    map<string, int> ZODIAZ;
    ZODIAZ["Ox"] = 1; ZODIAZ["Tiger"] = 2; ZODIAZ["Rabbit"] = 3; ZODIAZ["Dragon"] = 4; ZODIAZ["Snake"] = 5; ZODIAZ["Horse"] = 6; ZODIAZ["Goat"] = 7; ZODIAZ["Monkey"] = 8; ZODIAZ["Rooster"] = 9; ZODIAZ["Dog"] = 10; ZODIAZ["Pig"] = 11; ZODIAZ["Rat"] = 12;
    if (relationPair.first == "previous")
    {
        return abs(ZODIAZ[preRelationPair.second]-ZODIAZ[relationPair.second])-12;
    } else
    {
        return abs(ZODIAZ[preRelationPair.second]-ZODIAZ[relationPair.second]);
    }
}

int main()
{
    cout << calculateBetween(pair<string, string> ("pre", "Ox"), pair<string, string>("previous", "Dragon")) << endl;
}