#include <iostream>

void printCharArray(char arr[])
{
    std::cout << arr;
} //printCharArray

void main()
{
    char player1Name[20];
    char player1Icon = 'X';
    bool player1Won = false;

    char player2Name[20];
    char player2Icon = 'O';
    bool player2Won = false;

    std::cout << "Player 1, what is your name?" << std::endl;
    std::cin >> player1Name;
    system("cls");

    std::cout << "Player 2, what is your name?" << std::endl;
    std::cin >> player2Name;
    system("cls");

    std::cout << player1Name << std::endl;
    std::cout << player2Name << std::endl;

    system("pause");
    system("cls");

    char grid[3][3] = { {'0','0','0'}, {'0','0','0'}, {'0','0','0'} };

    do
    {
        //Player 1
        bool placedIcon = false;
        do
        { //While Player 1 hasn't placed an icon
            char position = ' ';
            do
            {
                std::cout << player1Name << " choose a position (Press a key on the numpad)" << std::endl;

                std::cout << grid[0][0] << "   " << grid[1][0] << "   " << grid[2][0] << std::endl << std::endl;
                std::cout << grid[0][1] << "   " << grid[1][1] << "   " << grid[2][1] << std::endl << std::endl;
                std::cout << grid[0][2] << "   " << grid[1][2] << "   " << grid[2][2] << std::endl;

                std::cin >> position;
            } while (position != '7' && position != '8' && position != '9' &&
                position != '4' && position != '5' && position != '6' &&
                position != '1' && position != '2' && position != '3');

            switch (position)
            {
            case '9':
                if (grid[2][0] != player1Icon && grid[2][0] != player2Icon)
                {
                    grid[2][0] = player1Icon;
                    placedIcon = true;
                }
                break;

            case '8':
                if (grid[1][0] != player1Icon && grid[1][0] != player2Icon)
                {
                    grid[1][0] = player1Icon;
                    placedIcon = true;
                }
                break;

            case '7':
                if (grid[0][0] != player1Icon && grid[0][0] != player2Icon)
                {
                    grid[0][0] = player1Icon;
                    placedIcon = true;
                }
                break;

            case '6':
                if (grid[2][1] != player1Icon && grid[2][1] != player2Icon)
                {
                    grid[2][1] = player1Icon;
                    placedIcon = true;
                }
                break;

            case '5':
                if (grid[1][1] != player1Icon && grid[1][1] != player2Icon)
                {
                    grid[1][1] = player1Icon;
                    placedIcon = true;
                }
                break;

            case '4':
                if (grid[0][1] != player1Icon && grid[0][1] != player2Icon)
                {
                    grid[0][1] = player1Icon;
                    placedIcon = true;
                }
                break;

            case '3':
                if (grid[2][2] != player1Icon && grid[2][2] != player2Icon)
                {
                    grid[2][2] = player1Icon;
                    placedIcon = true;
                }
                break;

            case '2':
                if (grid[1][2] != player1Icon && grid[1][2] != player2Icon)
                {
                    grid[1][2] = player1Icon;
                    placedIcon = true;
                }
                break;

            case '1':
                if (grid[0][2] != player1Icon && grid[0][2] != player2Icon)
                {
                    grid[0][2] = player1Icon;
                    placedIcon = true;
                }
                break;
            } //position switch
        } while (!placedIcon);

        system("cls");

        //Player 1 win conditions
        if (grid[0][0] == player1Icon && grid[0][1] == player1Icon && grid[0][2] == player1Icon) //Vertical Left
            player1Won = true;
        else if (grid[1][0] == player1Icon && grid[1][1] == player1Icon && grid[1][2] == player1Icon) //Vertical Center
            player1Won = true;
        else if (grid[2][0] == player1Icon && grid[2][1] == player1Icon && grid[2][2] == player1Icon) //Vertical Right
            player1Won = true;
        else if (grid[0][0] == player1Icon && grid[1][1] == player1Icon && grid[2][2] == player1Icon) //Diagonal rtl
            player1Won = true;
        else if (grid[2][0] == player1Icon && grid[1][1] == player1Icon && grid[0][2] == player1Icon) //Diagonal ltr
            player1Won = true;
        else if (grid[2][0] == player1Icon && grid[1][0] == player1Icon && grid[0][0] == player1Icon) //Horizontal Top
            player1Won = true;
        else if (grid[2][0] == player1Icon && grid[1][1] == player1Icon && grid[0][1] == player1Icon) //Horizontal Middle
            player1Won = true;
        else if (grid[2][0] == player1Icon && grid[1][2] == player1Icon && grid[0][2] == player1Icon) //Horizontal Bottom
            player1Won = true;

        if (!player1Won)
        {
            //Player 2
            placedIcon = false;
            do
            { //While Player 2 hasn't placed an icon
                char position = ' ';
                do
                {
                    std::cout << player2Name << " choose a position (Press a key on the numpad)" << std::endl;

                    std::cout << grid[0][0] << "   " << grid[1][0] << "   " << grid[2][0] << std::endl << std::endl;
                    std::cout << grid[0][1] << "   " << grid[1][1] << "   " << grid[2][1] << std::endl << std::endl;
                    std::cout << grid[0][2] << "   " << grid[1][2] << "   " << grid[2][2] << std::endl;

                    std::cin >> position;
                } while (position != '7' && position != '8' && position != '9' &&
                    position != '4' && position != '5' && position != '6' &&
                    position != '1' && position != '2' && position != '3');


                switch (position)
                {
                case '9':
                    if (grid[2][0] != player1Icon && grid[2][0] != player2Icon)
                    {
                        grid[2][0] = player2Icon;
                        placedIcon = true;
                    }
                    break;

                case '8':
                    if (grid[1][0] != player1Icon && grid[1][0] != player2Icon)
                    {
                        grid[1][0] = player2Icon;
                        placedIcon = true;
                    }
                    break;

                case '7':
                    if (grid[0][0] != player1Icon && grid[0][0] != player2Icon)
                    {
                        grid[0][0] = player2Icon;
                        placedIcon = true;
                    }
                    break;

                case '6':
                    if (grid[2][1] != player1Icon && grid[2][1] != player2Icon)
                    {
                        grid[2][1] = player2Icon;
                        placedIcon = true;
                    }
                    break;

                case '5':
                    if (grid[1][1] != player1Icon && grid[1][1] != player2Icon)
                    {
                        grid[1][1] = player2Icon;
                        placedIcon = true;
                    }
                    break;

                case '4':
                    if (grid[0][1] != player1Icon && grid[0][1] != player2Icon)
                    {
                        grid[0][1] = player2Icon;
                        placedIcon = true;
                    }
                    break;

                case '3':
                    if (grid[2][2] != player1Icon && grid[2][2] != player2Icon)
                    {
                        grid[2][2] = player2Icon;
                        placedIcon = true;
                    }
                    break;

                case '2':
                    if (grid[1][2] != player1Icon && grid[1][2] != player2Icon)
                    {
                        grid[1][2] = player2Icon;
                        placedIcon = true;
                    }
                    break;

                case '1':
                    if (grid[0][2] != player1Icon && grid[0][2] != player2Icon)
                    {
                        grid[0][2] = player2Icon;
                        placedIcon = true;
                    }
                    break;
                } //position switch
            } while (!placedIcon);
            system("cls");
        } //If Player1 didn't win

          //Player 2 win conditions
        else if (grid[0][0] == player2Icon && grid[0][1] == player2Icon && grid[0][2] == player2Icon) //Vertical Left
            player2Won = true;
        else if (grid[1][0] == player2Icon && grid[1][1] == player2Icon && grid[1][2] == player2Icon) //Vertical Center
            player2Won = true;
        else if (grid[2][0] == player2Icon && grid[2][1] == player2Icon && grid[2][2] == player2Icon) //Vertical Right
            player2Won = true;
        else if (grid[0][0] == player2Icon && grid[1][1] == player2Icon && grid[2][2] == player2Icon) //Diagonal rtl
            player2Won = true;
        else if (grid[2][0] == player2Icon && grid[1][1] == player2Icon && grid[0][2] == player2Icon) //Diagonal ltr
            player2Won = true;
        else if (grid[2][0] == player2Icon && grid[1][0] == player2Icon && grid[0][0] == player2Icon) //Horizontal Top
            player2Won = true;
        else if (grid[2][0] == player2Icon && grid[1][1] == player2Icon && grid[0][1] == player2Icon) //Horizontal Middle
            player2Won = true;
        else if (grid[2][0] == player2Icon && grid[1][2] == player2Icon && grid[0][2] == player2Icon) //Horizontal Bottom
            player2Won = true;
    } while (!player1Won && !player2Won);

    if (player1Won)
        std::cout << player1Name << " wins!";

    else if (player2Won)
        std::cout << player2Name << " wins!";

    system("pause");
    system("cls");
} //main