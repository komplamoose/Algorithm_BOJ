#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Player{
    int price = 0;
    string name = "";
};

bool comparePrice(const Player& x, const Player& y){
    return (x.price < y.price);
}

void solve(int n)
{
    for (int i = 0 ; i < n ; i++){
        int c;
        cin >> c;
        vector<Player> players;
        Player player;
        for (int j = 0 ; j < c ; j++){
            cin >> player.price >> player.name;
            players.push_back(player);
        }
        sort(players.begin(), players.end(), comparePrice);
        cout << players.back().name << endl;
    }
}

int main()
{
    int n;

    cin >> n;

    solve(n);
}