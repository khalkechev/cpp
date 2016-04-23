#include <iostream>
#include <string>

struct TBasketballPlayer {
    std::string Name;
    double Height;
    double Weight;
    TBasketballPlayer();
    TBasketballPlayer(const TBasketballPlayer& anotherPlayer);
    TBasketballPlayer(std::string name, double height, double weight);
};
TBasketballPlayer::TBasketballPlayer() {
    Name = "Noname";
    Height = 150;
    Weight = 100;
}
TBasketballPlayer::TBasketballPlayer(const TBasketballPlayer& anotherPlayer)
    : Name(anotherPlayer.Name)
    , Height(anotherPlayer.Height)
    , Weight(anotherPlayer.Weight) {}

TBasketballPlayer::TBasketballPlayer(std::string n, double h, double w) 
    : Name(n), Height(h), Weight(w) {}

void PrintPlayerInfo(const TBasketballPlayer& player) {
    std::cout << player.Name << "\t" << player.Height << "\t" 
              << player.Weight << std::endl;
}

int main(int argc, char const *argv[]) {

    TBasketballPlayer player2;
    TBasketballPlayer player3("Roman", 173, 103);
    PrintPlayerInfo(player2);
    PrintPlayerInfo(player3);
    TBasketballPlayer player4(player3);
    PrintPlayerInfo(player4);

    return 0;
}
