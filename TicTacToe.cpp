#include <iostream>

struct gridPosition
{
    char icon = ' ';
    bool taken = false;
}; //gridPosition struct

struct player
{
    char name[20] = "playerName";
    char icon = 0;
    bool won = false;
}; //player struct

void printCharArray(char arr[])
{
    std::cout << arr;
} //printCharArray

void main()
{
    player player1;
    player1.icon = 'X';

    player player2;
    player2.icon = 'O';

    bool cat = false;

    std::cout << "Player 1, what is your name?" << std::endl;
    std::cin >> player1.name;
    system("cls");

    std::cout << "Player 2, what is your name?" << std::endl;
    std::cin >> player2.name;
    system("cls");

    std::cout << player1.name << std::endl;
    std::cout << player2.name << std::endl;

    system("pause");
    system("cls");

    gridPosition grid[3][3];

    do
    {
        //Player 1
        bool placedIcon = false;
        do
        { //While Player 1 hasn't placed an icon
            char position = ' ';
            do
            {
                std::cout << player1.name << " choose a position (Press a key on the numpad)" << std::endl;

                std::cout << grid[0][0].icon << " | " << grid[1][0].icon << " | " << grid[2][0].icon << std::endl;
                std::cout << "-   -   -" << std::endl;
                std::cout << grid[0][1].icon << " | " << grid[1][1].icon << " | " << grid[2][1].icon << std::endl;
                std::cout << "-   -   -" << std::endl;
                std::cout << grid[0][2].icon << " | " << grid[1][2].icon << " | " << grid[2][2].icon << std::endl;

                std::cin >> position;
            } while (position != '7' && position != '8' && position != '9' &&
                position != '4' && position != '5' && position != '6' &&
                position != '1' && position != '2' && position != '3');

            switch (position)
            {
            case '9':
                if (grid[2][0].taken == false)
                {
                    grid[2][0].icon = player1.icon;
                    placedIcon = true;
                    grid[2][0].taken = true;
                }
                break;

            case '8':
                if (grid[1][0].taken == false)
                {
                    grid[1][0].icon = player1.icon;
                    placedIcon = true;
                    grid[1][0].taken = true;
                }
                break;

            case '7':
                if (grid[0][0].taken == false)
                {
                    grid[0][0].icon = player1.icon;
                    placedIcon = true;
                    grid[0][0].taken = true;
                }
                break;

            case '6':
                if (grid[2][1].taken == false)
                {
                    grid[2][1].icon = player1.icon;
                    placedIcon = true;
                    grid[2][1].taken = true;
                }
                break;

            case '5':
                if (grid[1][1].taken == false)
                {
                    grid[1][1].icon = player1.icon;
                    placedIcon = true;
                    grid[1][1].taken = true;
                }
                break;

            case '4':
                if (grid[0][1].taken == false)
                {
                    grid[0][1].icon = player1.icon;
                    placedIcon = true;
                    grid[0][1].taken = true;
                }
                break;

            case '3':
                if (grid[2][2].taken == false)
                {
                    grid[2][2].icon = player1.icon;
                    placedIcon = true;
                    grid[2][2].taken = true;
                }
                break;

            case '2':
                if (grid[1][2].taken == false)
                {
                    grid[1][2].icon = player1.icon;
                    placedIcon = true;
                    grid[1][2].taken = true;
                }
                break;

            case '1':
                if (grid[0][2].taken == false)
                {
                    grid[0][2].icon = player1.icon;
                    placedIcon = true;
                    grid[0][2].taken = true;
                }
                break;
            } //position switch
        } while (!placedIcon);

        system("cls");

        //Player 1 win conditions
        if (grid[0][0].icon == player1.icon && grid[0][1].icon == player1.icon && grid[0][2].icon == player1.icon) //Vertical Left
            player1.won = true;
        else if (grid[1][0].icon == player1.icon && grid[1][1].icon == player1.icon && grid[1][2].icon == player1.icon) //Vertical Center
            player1.won = true;
        else if (grid[2][0].icon == player1.icon && grid[2][1].icon == player1.icon && grid[2][2].icon == player1.icon) //Vertical Right
            player1.won = true;
        else if (grid[0][0].icon == player1.icon && grid[1][1].icon == player1.icon && grid[2][2].icon == player1.icon) //Diagonal rtl
            player1.won = true;
        else if (grid[2][0].icon == player1.icon && grid[1][1].icon == player1.icon && grid[0][2].icon == player1.icon) //Diagonal ltr
            player1.won = true;
        else if (grid[2][0].icon == player1.icon && grid[1][0].icon == player1.icon && grid[0][0].icon == player1.icon) //Horizontal Top
            player1.won = true;
        else if (grid[2][0].icon == player1.icon && grid[1][1].icon == player1.icon && grid[0][1].icon == player1.icon) //Horizontal Middle
            player1.won = true;
        else if (grid[2][0].icon == player1.icon && grid[1][2].icon == player1.icon && grid[0][2].icon == player1.icon) //Horizontal Bottom
            player1.won = true;
        else if (grid[0][0].taken == true && grid[0][1].taken == true && grid[0][2].taken == true &&
                 grid[1][0].taken == true && grid[1][1].taken == true && grid[1][2].taken == true &&
                 grid[2][0].taken == true && grid[2][1].taken == true && grid[2][2].taken == true)
            cat = true;

        if (!player1.won && !cat)
        {
            //Player 2
            placedIcon = false;
            do
            { //While Player 2 hasn't placed an icon
                char position = ' ';
                do
                {
                    std::cout << player2.name << " choose a position (Press a key on the numpad)" << std::endl;

                    std::cout << grid[0][0].icon << " | " << grid[1][0].icon << " | " << grid[2][0].icon << std::endl;
                    std::cout << "-   -   -" << std::endl;
                    std::cout << grid[0][1].icon << " | " << grid[1][1].icon << " | " << grid[2][1].icon << std::endl;
                    std::cout << "-   -   -" << std::endl;
                    std::cout << grid[0][2].icon << " | " << grid[1][2].icon << " | " << grid[2][2].icon << std::endl;

                    std::cin >> position;
                } while (position != '7' && position != '8' && position != '9' &&
                    position != '4' && position != '5' && position != '6' &&
                    position != '1' && position != '2' && position != '3');


                switch (position)
                {
                case '9':
                    if (grid[2][0].taken == false)
                    {
                        grid[2][0].icon = player2.icon;
                        placedIcon = true;
                        grid[2][0].taken = true;
                    }
                    break;

                case '8':
                    if (grid[1][0].taken == false)
                    {
                        grid[1][0].icon = player2.icon;
                        placedIcon = true;
                        grid[1][0].taken = true;
                    }
                    break;

                case '7':
                    if (grid[0][0].taken == false)
                    {
                        grid[0][0].icon = player2.icon;
                        placedIcon = true;
                        grid[0][0].taken = true;
                    }
                    break;

                case '6':
                    if (grid[2][1].taken == false)
                    {
                        grid[2][1].icon = player2.icon;
                        placedIcon = true;
                        grid[2][1].taken = true;
                    }
                    break;

                case '5':
                    if (grid[1][1].taken == false)
                    {
                        grid[1][1].icon = player2.icon;
                        placedIcon = true;
                        grid[1][1].taken = true;
                    }
                    break;

                case '4':
                    if (grid[0][1].taken == false)
                    {
                        grid[0][1].icon = player2.icon;
                        placedIcon = true;
                        grid[0][1].taken = true;
                    }
                    break;

                case '3':
                    if (grid[2][2].taken == false)
                    {
                        grid[2][2].icon = player2.icon;
                        placedIcon = true;
                        grid[2][2].taken = true;
                    }
                    break;

                case '2':
                    if (grid[1][2].taken == false)
                    {
                        grid[1][2].icon = player2.icon;
                        placedIcon = true;
                        grid[1][2].taken = true;
                    }
                    break;

                case '1':
                    if (grid[0][2].taken == false)
                    {
                        grid[0][2].icon = player2.icon;
                        placedIcon = true;
                        grid[0][2].taken = true;
                    }
                    break;
                } //position switch
            } while (!placedIcon);
            system("cls");
        } //If Player1 didn't win

          //Player 2 win conditions
        else if (grid[0][0].icon == player2.icon && grid[0][1].icon == player2.icon && grid[0][2].icon == player2.icon) //Vertical Left
            player2.won = true;
        else if (grid[1][0].icon == player2.icon && grid[1][1].icon == player2.icon && grid[1][2].icon == player2.icon) //Vertical Center
            player2.won = true;
        else if (grid[2][0].icon == player2.icon && grid[2][1].icon == player2.icon && grid[2][2].icon == player2.icon) //Vertical Right
            player2.won = true;
        else if (grid[0][0].icon == player2.icon && grid[1][1].icon == player2.icon && grid[2][2].icon == player2.icon) //Diagonal rtl
            player2.won = true;
        else if (grid[2][0].icon == player2.icon && grid[1][1].icon == player2.icon && grid[0][2].icon == player2.icon) //Diagonal ltr
            player2.won = true;
        else if (grid[2][0].icon == player2.icon && grid[1][0].icon == player2.icon && grid[0][0].icon == player2.icon) //Horizontal Top
            player2.won = true;
        else if (grid[2][0].icon == player2.icon && grid[1][1].icon == player2.icon && grid[0][1].icon == player2.icon) //Horizontal Middle
            player2.won = true;
        else if (grid[2][0].icon == player2.icon && grid[1][2].icon == player2.icon && grid[0][2].icon == player2.icon) //Horizontal Bottom
            player2.won = true;
        else if (grid[0][0].taken == true && grid[0][1].taken == true && grid[0][2].taken == true && 
                 grid[1][0].taken == true && grid[1][1].taken == true && grid[1][2].taken == true && 
                 grid[2][0].taken == true && grid[2][1].taken == true && grid[2][2].taken == true)
            cat = true;
    } while (!player1.won && !player2.won && !cat);

    if (player1.won)
        std::cout << player1.name << " wins!";

    else if (player2.won)
        std::cout << player2.name << " wins!";

    else
        std::cout << "Cat!";

    std::cout << std::endl;

    system("pause");
    system("cls");
} //main