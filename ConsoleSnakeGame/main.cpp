#include "Game.h"
#include "StartMenu.h"

int main(){
    StartMenu startMenu;
    int choice = startMenu.ShowMenu();
    switch (choice) {
        case 1:{      
            Game game;
            game.Run();
            break;
        }
        case 2:{
            std::pair<int, int> dimensions = startMenu.GetWidthAndHeight();
            Game customGame(dimensions.first, dimensions.second);
            customGame.Run();
            break;
        }
        case 3:
            std::cout << "Test" << std::endl;
            break;

        default:
            std::cout << "Invalid choise.";
    }
    
    return 0;
}
