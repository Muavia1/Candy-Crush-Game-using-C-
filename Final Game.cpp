#include <stdio.h>
#include<conio.h>
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <fstream>
#include <Windows.h>
#include <MMsystem.h>
using namespace std;
char board[9][9], tempBoard[9][9];
char movement,direction,d;
int row=4, col=4, menu,menu2,menuaddress,move = 20, timer=0, points, menu3, random, count=0,num,num1,a,b,c;
string playername, line;
static bool match=false, save1=false;
fstream scoreeasy, load, array;
void printBoard();
void left();
void right();
void up();
void down();
void crush3();
void crush4();
void crush5();
void wrap();
void doubleBomb(char swap1, char swap2);
void striBomb(char swap1, char swap2);
void wrapBomb(char swap1, char swap2);
void stripWrap(char swap1, char swap2);
void wrapWrap(char swap1, char swap2);
void boardSelector();
int main()
{
	while (1) {
		//PlaySound(TEXT("candy.mp3"), NULL, SND_ASYNC);
    	system("cls");
        cout << "\n\t                            -> Play" << endl;
        cout << "\n\t                              Credits" << endl;
        cout << "\n\t                              Rules" << endl;
        cout << "\n\t                              Scores" << endl;
        cout << "\n\t                              Exit" << endl;
        menu = 1;

        do {
            menuaddress = _getch();
            if (menuaddress == 224 && menu == 1) {
                switch (_getch()) {
                case 72:
                    system("cls");
                    cout << "\n\t                              Play" << endl;
                    cout << "\n\t                              Credits" << endl;
                    cout << "\n\t                              Rules" << endl;
                    cout << "\n\t                              Scores" << endl;
                    cout << "\n\t                            -> Exit" << endl;
                    menu = 5;
                    break;
                case 80:
                    system("cls");
                    cout << "\n\t                              Play" << endl;
                    cout << "\n\t                            -> Credits" << endl;
                    cout << "\n\t                              Rules" << endl;
                    cout << "\n\t                              Scores" << endl;
                    cout << "\n\t                              Exit" << endl;
                    menu = 2;
                    break;
                }
            }
            else if (menuaddress == 224 && menu == 2) {
                switch (_getch()) {
                case 72:
                    system("cls");
                    cout << "\n\t                            -> Play" << endl;
                    cout << "\n\t                              Credits" << endl;
                    cout << "\n\t                              Rules" << endl;
                    cout << "\n\t                              Scores" << endl;
                    cout << "\n\t                              Exit" << endl;
                    menu = 1;
                    break;
                case 80:
                    system("cls");
                    cout << "\n\t                              Play" << endl;
                    cout << "\n\t                              Credits" << endl;
                    cout << "\n\t                            -> Rules" << endl;
                    cout << "\n\t                              Scores" << endl;
                    cout << "\n\t                              Exit" << endl;
                    menu = 3;
                    break;
                }
            }
            else if (menuaddress == 224 && menu == 3) {
                switch (_getch()) {
                case 72:
                    system("cls");
                    cout << "\n\t                              Play" << endl;
                    cout << "\n\t                            -> Credits" << endl;
                    cout << "\n\t                              Rules" << endl;
                    cout << "\n\t                              Scores" << endl;
                    cout << "\n\t                              Exit" << endl;
                    menu = 2;
                    break;
                case 80:
                    system("cls");
                    cout << "\n\t                              Play" << endl;
                    cout << "\n\t                              Credits" << endl;
                    cout << "\n\t                              Rules" << endl;
                    cout << "\n\t                            -> Scores" << endl;
                    cout << "\n\t                              Exit" << endl;
                    menu = 4;
                    break;
                }
            }
            else if (menuaddress == 224 && menu == 4) {
                switch (_getch()) {
                case 72:
                    system("cls");
                    cout << "\n\t                              Play" << endl;
                    cout << "\n\t                              Credits" << endl;
                    cout << "\n\t                             -> Rules" << endl;
                    cout << "\n\t                              Scores" << endl;
                    cout << "\n\t                              Exit" << endl;
                    menu = 3;
                    break;
                case 80:
                    system("cls");
                    cout << "\n\t                             Play" << endl;
                    cout << "\n\t                             Credits" << endl;
                    cout << "\n\t                             Rules" << endl;
                    cout << "\n\t                             Scores" << endl;
                    cout << "\n\t                           -> Exit" << endl;
                    menu = 5;
                    break;
                }
            }
            else if (menuaddress == 224 && menu == 5) {
                switch (_getch()) {
                case 72:
                    system("cls");
                    cout << "\n\t                              Play" << endl;
                    cout << "\n\t                              Credits" << endl;
                    cout << "\n\t                              Rules" << endl;
                    cout << "\n\t                            -> Scores" << endl;
                    cout << "\n\t                              Exit" << endl;
                    menu = 4;
                    break;
                case 80:
                    system("cls");
                    cout << "\n\t                             -> Play" << endl;
                    cout << "\n\t                              Credits" << endl;
                    cout << "\n\t                              Rules" << endl;
                    cout << "\n\t                              Scores" << endl;
                    cout << "\n\t                              Exit" << endl;
                    menu = 1;
                    break;
                }
            }
        } while (menuaddress != 13);
        switch (menu) {
            //This switch will be applied on the selected option
        case 1:
            system("cls");
            menu2 = 1;
            switch (menu2) {
            case 1:
                //Asking the player to enter the name
                srand(time(0));
                cout << "\n\tEnter Player name: ";
                getline(cin, playername);
                system ("cls");
                cout<<"\n\n\n";
				cout<<"\t\t\t\t\t\t\t\t\t\t\tDo You want to play saved game?";
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\tPress 1 for YES";
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\tPress 0 for NO";
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\tANSWER : ";
				cin>>num1;
				if(num1==0)
				{
                //5 second contdown timer for before the game starts
                for (int k = 10; k > 0; k--) 
				{
                    system("cls");
                    cout << "\n\tGame starts in: " << k << endl << endl;
                    cout<<"\tWelcome to Number Crush Game.\n\n"<<"\tYou have total 20 moves.";
                    cout<<"\n\n\tIt is recommended to play game in full screen.";
                    Sleep(1000);
                    
                    
                }
                printBoard();
            	}
            	else
            	{
            		system("cls");
            		load.open("saved.txt");
            		load>>a;
            		load>>b;
            		load>>c;
            		move=a;
            		row=b;
            		col=c;
            		load.close();
            		array.open("board.txt");
            		for(int i=0;i<10;i++)
					{
						for(int j=0;j<10;j++)
						{
							array>>d;
						    board[i][j]=d;
						}
					}
					array.close();
            		
				}
                system("cls"); 
                //crush4();
                 //crush3();
	            char swap;
	            	do
	{
		
		boardSelector();
		//crush4();
		//rush3();
		movement = getch();
		match=false;
		if (movement == 72&&row!=0)
		{
			row--;
		}
		else if (movement == 75&&col!=0)
		{
			col--;
		} 
		else if (movement == 77&&col!=8)
		{
			col++;
		}
		else if (movement == 80&&row!=8)
		{
			row++;
		}
		else if(movement=='U'||movement=='u')
		{
            if ((board[row - 1][col] == 'S' && board[row+1][col]==board[row][col]) || (board[row][col]=='S' && board[row+1][col]==board[row - 1][col])
			|| (board[row - 1][col] == 'S' && board[row-2][col]==board[row][col]) ||(board[row][col]=='S' && board[row-2][col]==board[row - 1][col])) 
			{
                for (int i = 0; i < 9; i++) 
			  {
                    board[i][col] = static_cast<char>(177);
                }
                for (int j = 0; j < 9; j++) 
				{
                    board[row - 1][j] = static_cast<char>(177);
                }
                boardSelector();
                cout << "\t\tDivine";
                Sleep(1500);
                for (int i = 0; i < 9; i++) 
				{
                    num= rand()%6 + 49;
                    board[i][col] = num;
                }
                for (int j = 0; j < 9; j++) 
				{
                    num= rand()%6 + 49;
                    board[row - 1][j] = num;
                }
                points = points + 30;
            }        
			if(row!=0)
			{
				up();
			}
			if(match==false)
			{
				move++;
				up();
				move++;
			}
		
    
		}
		else if(movement=='D'||movement=='d')
		{
			if ((board[row + 1][col] == 'S' && board[row-1][col]==board[row][col]) || (board[row][col]=='S' && board[row-1][col]==board[row + 1][col])) 
			{
                for (int i = 0; i < 9; i++) 
				{
                    board[i][col] = static_cast<char>(177);
                }
                for (int j = 0; j < 9; j++) 
				{
                    board[row + 1][j] = static_cast<char>(177);
                }
                boardSelector();
                cout << "\t\tDivine";
                Sleep(1500);
                for (int i = 0; i < 9; i++) 
				{
                    num= rand()%6 + 49;
                    board[i][col] = num;
                }
                for (int j = 0; j < 9; j++) 
				{
                    num= rand()%6 + 49;
                    board[row + 1][j] = num;
                }
                points = points + 30;
            }
      
		if(row!=8)
			{
				down();
			}
			if(match==false)
			{
				move++;
				down();
				move++;
			}
		
		}
		
		else if(movement=='r'||movement=='R')
		{
			 if ((board[row][col + 1] == 'S' && board[row][col]==board[row][col-1]) || (board[row][col] == 'S' && board[row][col+1]==board[row][col-1])
			 || (board[row][col + 1] == 'S' && board[row][col]==board[row][col+2]) || (board[row][col] == 'S' && board[row][col+1]==board[row][col+2]) ) 
			 {
                for (int i = 0; i < 9; i++) 
				{
                    board[i][col + 1] = static_cast<char>(177);
                }
                for (int j = 0; j < 9; j++) 
				{
                    board[row][j] = static_cast<char>(177);
                }
                boardSelector();
            	cout << "\t\tDivine";
                Sleep(1500);
                for (int i = 0; i < 8; i++) 
				{
                    num= rand()%6 + 49;
                    board[i][col + 1] = num;
                }
                for (int j = 0; j < 8; j++) 
				{
                    num= rand()%6 + 49;
                    board[row][j] = num;
                }
                points = points + 30;
            }
			if(col!=9)
			{
				right();
			}
			if(match==false)
			{
				move++;
				right();
				move++;
			}
		
		}
		else if(movement == 'l'||movement=='L')
		{
			if ((board[row][col - 1] == 'S' && board[row][col]==board[row][col-2]) || (board[row][col]=='S' && board[row][col-1]==board[row][col - 1])
			|| (board[row][col - 1] == 'S' && board[row][col]==board[row][col+1]) || (board[row][col]=='S' && board[row][col-1]==board[row][col+1])) 
			{
                for (int i = 0; i < 8; i++) 
				{
                    board[i][col - 1] = static_cast<char>(177);
                }
                for (int j = 0; j < 8; j++) 
				{
                    board[row][j] = static_cast<char>(177);
                }
                boardSelector();
                cout << "\t\tDivine";
                Sleep(1500);
                for (int i = 0; i < 8; i++) 
				{
                    num= rand()%6 + 49;
                    board[i][col - 1] = num;
                }
                for (int j = 0; j < 8; j++) 
				{
                    num= rand()%6 + 49;
                    board[row][j] = num;
                }
                points = points + 30;
            }
			if(col!=0)
			{
				left();
			}
			if(match==false)
			{
				move++;
				left();
				move++;
			}
			
			
			
		}
		else if(movement=='Q'||movement=='q')
		{
			system("cls");
			save1=true;
			break;
		}
		
	}
	while (move!=0);

                //Condition to print if moves run out first
                if (move <= 0 ) {
                    system("cls");
                    cout << "\n\tPlayer name : " << playername;
                    cout << "\n\n\tTotal Points : " << points;
                    cout << "\n\n\tPress any key to return to the main page\n";
                    system("pause>nul");
                }
                //printing the score in file
                scoreeasy.open("points_easy.txt", fstream::app);
                if (scoreeasy.is_open() == true) {
                    scoreeasy << "\tName: " << playername << "\tScore: " << points << endl;
                    scoreeasy.close();
                }
                if(save1=true)
                {
                	cout<<"\n\n\n";
					cout<<"\t\t\t\t\t\t\t\t\t\t\tDo You want to save your game?";
					cout<<"\n\t\t\t\t\t\t\t\t\t\t\tPress 1 for YES";
					cout<<"\n\t\t\t\t\t\t\t\t\t\t\tPress 0 for NO";
					cout<<"\n\t\t\t\t\t\t\t\t\t\t\tANSWER : ";
					cin>>num1;
					if(num1==1)
					{
						a=move;
						b=row;
						c=col;
						load.open("saved.txt");
						load<<a<<endl;
						load<<b<<endl;
						load<<c;
						load.close();
						array.open("board.txt");
						for(int i=0;i<10;i++)
						{
							for(int j=0;j<10;j++)
							{
								array<<board[i][j]<<endl;
							}		
						}
						array.close();
					}
			
				}
                
            }
            break;
        case 2: 
		        //credits go here
            system("cls");
            cout<<endl<<endl;
            cout<<"\tThis game is made by Muavia Abdul Moiz and Hafsa Irfan.\n\n";
            cout << "\tPress any key to return to the main page...";
            system("pause>nul");
            break;   
        case 3:
            //rules go here
            system("cls");
            cout<<endl<<endl;
            cout<<" Rules are: \n\n"<<"-> You will have total 20 moves.\n\n";
            cout<<"-> The game will automatically exit when moves becomes zero.\n\n";
            cout<<"-> To win the game you'll have to score 600 points.\n\n";
            cout << "\tPress any key to return to the main page...";
            system("pause>nul");
            break;
        case 4:
            //scores go here
            system("cls");
            menu3 = 1;
            switch (menu3) {
            case 1:
                system("cls");

                cout << endl << endl << endl;
                {ifstream scoreeasy("points_easy.txt", ios::in);
                while (getline(scoreeasy, line)) {
                    cout << "\t" << line << endl;
                    cout << endl << endl << endl;
                }
                }
                scoreeasy.close();
                cout << endl << endl << endl;
                cout << "Press any key to go back to the main page...\n";
                system("pause>nul");

                break;
            }
            break;
        case 5:
            //exit
            system("cls");
            cout << "\n\n\n\t\t\tAre you sure you want to exit?" << endl;
            cout << "\n\t\t\t                --> Yes" << endl;
            cout << "\n\t\t\t                   No" << endl;
            menu = 1;
            do {
                menuaddress = _getch();
                if (menuaddress == 224 && menu == 1) {
                    switch (_getch()) {
                    case 80:
                        system("cls");
                        cout << "\n\n\n\t\t\tAre you sure you want to exit?" << endl;
                        cout << "\n\t\t\t                  Yes" << endl;
                        cout << "\n\t\t\t               --> No" << endl;
                        menu = 2;
                        break;
                    case 72:
                        system("cls");
                        cout << "\n\n\n\t\t\tAre you sure you want to exit?" << endl;
                        cout << "\n\t\t\t                  Yes" << endl;
                        cout << "\n\t\t\t               --> No" << endl;
                        menu = 2;
                    }
                }
                else if (menuaddress == 224 && menu == 2) {
                    switch (_getch()) {
                    case 80:
                        system("cls");
                        cout << "\n\n\n\t\t\tAre you sure you want to exit?" << endl;
                        cout << "\n\t\t\t                --> Yes" << endl;
                        cout << "\n\t\t\t                   No" << endl;
                        menu = 1;
                        break;
                    case 72:
                        system("cls");
                        cout << "\n\n\n\t\t\tAre you sure you want to exit?" << endl;
                        cout << "\n\t\t\t                --> Yes" << endl;
                        cout << "\n\t\t\t                   No" << endl;
                        menu = 1;
                    }
                }
            } while (menuaddress != 13);
            if (menu == 1) {
                return 0;
            }
            else {
                break;
            }
            
            
        }
    }
	
	
}
void printBoard()
{
	char temp1, temp2, temp3;
    int num;
	srand(time (0));
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			num = rand()%6+49;
			board[i][j] = num;
		}
	}
	for (int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			 if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j])) {
                temp1 = board[i][j];
                temp2 = board[i + 1][j];
                temp3 = board[i + 2][j];
                                srand(time (0));
                num = rand()%6+49;
                board[i][j] = num;
                srand(time (0));
                num = rand()%6+49;
                board[i + 1][j] = num;
                do {
                	srand(time (0));
                    num = rand()%6+49;
                    board[i + 2][j] = num;
                } while ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]));
     }
      else {
                if (j < 7) {
                    if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2])) {
                        temp1 = board[i][j];
                        temp2 = board[i][j + 1];
                        temp3 = board[i][j + 2];
                             srand(time (0));
                       num = rand()%6+49;
                board[i][j] = num;
                srand(time (0));
                num = rand()%6+49;
                board[i + 1][j] = num;
                do {
                	srand(time (0));
                    num = rand()%6+49;
                    board[i + 2][j] = num;
                } while ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]));
                points = points + 10;
                i = 0; j = 0;
                    }
		}
	}
}
}
}
void boardSelector()
{
	system("cls");
	cout<<"\t  S = Stripped Candy   W = Wrapped Candy   B = Color Bomb "<<endl<<endl;
	for(int i=0;i<9;i++)
	{
		for(int k=0;k<9;k++)
		{
			if (i==row && k==col)
				cout<<" |" <<board[i][k] <<"| ";
			else
				cout<<"  "<<board[i][k]<<"  ";
		}
		cout<<"\n\n";
	}
	cout<<"*Use arrow keys for operation of game\n";
	cout<<"*Press U or u to swap up\n";
	cout<<"*Press L or l to swap left\n";
	cout<<"*Press D or d to swap down\n";
	cout<<"*Press R or r to swap right\n";
	cout<<"*Press S or s to save your game\n";
	cout<<"*Press Q or q to swap right\n";
	cout<<"*You have "<<move<<" left.\n";
	fflush(stdin);
}
void  left(){
	char swap1;
	char swap2;
	swap1=board[row][col];
	swap2=board[row][col-1];
	board[row][col]=swap2;
	board[row][col-1]=swap1;
	doubleBomb(swap1, swap2);
	wrap();
	crush5();
	crush4();
	crush3();
	move--;
}
void  right(){
	char swap1;
	char swap2;
	swap1=board[row][col];
	swap2=board[row][col+1];
	board[row][col]=swap2;
	board[row][col+1]=swap1;
	doubleBomb(swap1, swap2);
	wrap();
	crush5();
	crush4();
	crush3();
	move--;
}
void  up(){
	char swap1;
	char swap2;
	swap1=board[row][col];
	swap2=board[row-1][col];
	board[row][col]=swap2;
	board[row-1][col]=swap1;
	doubleBomb(swap1, swap2);
	wrap();
	crush5();
	crush4();
	crush3();
	move--;
	
}
void  down(){
	char swap1;
	char swap2;
	swap1=board[row][col];
	swap2=board[row+1][col];
	board[row][col]=swap2;
	board[row+1][col]=swap1;
	doubleBomb(swap1, swap2);
	wrap();
	crush5();
	crush4();
    crush3();
    move--;
}
void crush3()
{
	int num;
    int i, j;
    char temp1, temp2, temp3;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
        	
        
		
            if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j])) {
                temp1 = board[i][j];
                temp2 = board[i + 1][j];
                temp3 = board[i + 2][j];
                  for (int k = 2; k > 0; k--) {
                    board[i][j] = static_cast<char>(219);
                    board[i + 1][j] = static_cast<char>(219);
                    board[i + 2][j] = static_cast<char>(219);
                   boardSelector();
                    cout << "\t\tSweet\n";
                    Sleep(600);
                    board[i][j] = temp1;
                    board[i + 1][j] = temp2;
                    board[i + 2][j] = temp3;
                    boardSelector();
                    cout << "\t\tSweet\n";
                    Sleep(600);
                }
                srand(time (0));
                num = rand()%6+49;
                board[i][j] = num;
                srand(time (0));
                num = rand()%6+49;
                board[i + 1][j] = num;
                do {
                	srand(time (0));
                    num = rand()%6+49;
                    board[i + 2][j] = num;
                } while ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]));
                match = true;

                points = points + 10;
                i = 0; j = 0;
            }
        
            else {
                if (j < 7) {
                    if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2])) {
                        temp1 = board[i][j];
                        temp2 = board[i][j + 1];
                        temp3 = board[i][j + 2];
                    for (int k = 2; k > 0; k--) {
                            board[i][j] = static_cast<char>(219);
                            board[i][j + 1] = static_cast<char>(219);
                            board[i][j + 2] = static_cast<char>(219);
                            boardSelector();
                            cout << "\t\tSweet\n";
                            Sleep(600);
                            board[i][j] = temp1;
                            board[i][j + 1] = temp2;
                            board[i][j + 2] = temp3;
                            boardSelector();
                            cout << "\t\tSweet\n";
                            Sleep(600);
                        }
                        srand(time (0));
                       num = rand()%6+49;
                board[i][j] = num;
                srand(time (0));
                num = rand()%6+49;
                board[i + 1][j] = num;
                do {
                	srand(time (0));
                    num = rand()%6+49;
                    board[i + 2][j] = num;
                } while ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]));
                match = true;
                
                points = points + 10;
                i = 0; j = 0;
                    }
                }
            }
            
        }
    }
}
void crush4()
{
	{
	int num;
    int i, j;
    char temp1, temp2, temp3,temp4;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
        	
            if  ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]) && (board[i][j] ==board[i + 3][j])) {
                temp1 = board[i][j];
                temp2 = board[i + 1][j];
                temp3 = board[i + 2][j];
                temp4 = board[i + 3][j];
                  for (int k = 2; k > 0; k--) {
                    board[i][j] = static_cast<char>(219);
                    board[i + 1][j] = static_cast<char>(219);
                    board[i + 2][j] = static_cast<char>(219);
                    board[i + 3][j] = static_cast<char>(219);
                   boardSelector();
                    cout << "\t\tDelicious\n";
                    Sleep(600);
                    board[i][j] = temp1;
                    board[i + 1][j] = temp2;
                    board[i + 2][j] = temp3;
                    board[i + 3][j] = temp4;
                    boardSelector();
                    cout << "\t\tDelicious\n";
                    Sleep(600);
                }
                num = rand()%6 + 49;
                board[i][j] = num;
                num = rand()%6 + 49;
                board[i + 1][j] = num;
                do {
                    num = rand()%6 + 49;
                    board[i + 2][j] = num;
                } while ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]));
                do {
                    num = rand()%6 + 49;
                    board[i + 3][j] = num;
                } while ((board[i + 1][j] == board[i + 2][j]) && (board[i + 1][j] == board[i + 3][j]));
                board[row][col] = 'S';
                match = true;
                points = points + 20;

                i = 0; j = 0;
            }
        
            else {
                if (j < 6) {
                    if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2]) && (board[i][j] == board[i][j + 3])) {
                        temp1 = board[i][j];
                        temp2 = board[i][j + 1];
                        temp3 = board[i][j + 2];
                        temp4 = board[i][j + 3];
                    for (int k = 2; k > 0; k--) {
                            board[i][j] = static_cast<char>(219);
                            board[i][j + 1] = static_cast<char>(219);
                            board[i][j + 2] = static_cast<char>(219);
                             board[i][j + 3] = static_cast<char>(219);
                            boardSelector();
                            cout << "\t\tDelicious\n";
                            Sleep(600);
                            board[i][j] = temp1;
                            board[i][j + 1] = temp2;
                            board[i][j + 2] = temp3;
                            board[i][j + 3] = temp4;
                            boardSelector();
                            cout << "\t\tDelicious\n";
                            Sleep(600);
                        }
                        srand(time (0));
                       num = rand()%6 + 49;
                        board[i][j] = num;
                        num = rand()%6 + 49;
                        board[i][j + 1] = num;
                        do {
                            num = rand()%6 + 49;
                            board[i][j + 2] = num;
                        } while ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2]));
                        do {
                            num = rand()%6 + 49;
                            board[i][j + 2] = num;
                        } while ((board[i][j + 1] == board[i][j + 2]) && (board[i][j + 1] == board[i][j + 3]));
                        board[row][col] = 'S';
                        match = true;
                        points = points + 20;
                        i = 0; j = 0;
                    }
                }
            }
        }
    }
}
}
void crush5()
{
	{
	int num;
    int i, j;
    char temp1, temp2, temp3,temp4, temp5;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
        	
            if  ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]) && (board[i][j] ==board[i + 3][j]) && (board[i][j] == board[i + 4][j])) {
                temp1 = board[i][j];
                temp2 = board[i + 1][j];
                temp3 = board[i + 2][j];
                temp4 = board[i + 3][j];
                temp5=  board[i + 4][j];
                  for (int k = 2; k > 0; k--) {
                    board[i][j] = static_cast<char>(219);
                    board[i + 1][j] = static_cast<char>(219);
                    board[i + 2][j] = static_cast<char>(219);
                    board[i + 3][j] = static_cast<char>(219);
                    board[i + 4][j] = static_cast<char>(219);
                   boardSelector();
                    cout << "\t\tDelicious\n";
                    Sleep(600);
                    board[i][j] = temp1;
                    board[i + 1][j] = temp2;
                    board[i + 2][j] = temp3;
                    board[i + 3][j] = temp4;
                    board[i + 4][j] = temp5;
                    boardSelector();
                    cout << "\t\tDelicious\n";
                    Sleep(600);
                }
                num = rand()%6 + 49;
                board[i][j] = num;
                num = rand()%6 + 49;
                board[i + 1][j] = num;
                do {
                    num = rand()%6 + 49;
                    board[i + 2][j] = num;
                } while ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]));
                do {
                    num = rand()%6 + 49;
                    board[i + 3][j] = num;
                } while ((board[i + 1][j] == board[i + 2][j]) && (board[i + 1][j] == board[i + 3][j]));
                 do {
                    num = rand()%6 + 49;
                    board[i + 4][j] = num;
                } while ((board[i + 1][j] == board[i + 2][j]) && (board[i + 1][j] == board[i + 3][j]) && (board[i + 1][j] == board[i + 4][j]));
                board[row][col] = 'B';
                match = true;
                points = points + 20;

                i = 0; j = 0;
            }
        
            else {
                if (j < 5) {
                    if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2]) && (board[i][j] == board[i][j + 3]) && (board[i][j] == board[i][j + 4])) {
                        temp1 = board[i][j];
                        temp2 = board[i][j + 1];
                        temp3 = board[i][j + 2];
                        temp4 = board[i][j + 3];
                        temp5 = board[i][j + 4];
                    for (int k = 2; k > 0; k--) {
                            board[i][j] = static_cast<char>(219);
                            board[i][j + 1] = static_cast<char>(219);
                            board[i][j + 2] = static_cast<char>(219);
                            board[i][j + 3] = static_cast<char>(219);
                            board[i][j + 4] = static_cast<char>(219);
                            boardSelector();
                            cout << "\t\tDelicious\n";
                            Sleep(600);
                            board[i][j] = temp1;
                            board[i][j + 1] = temp2;
                            board[i][j + 2] = temp3;
                            board[i][j + 3] = temp4;
                            board[i][j + 4] = temp5;
                            boardSelector();
                            cout << "\t\tDelicious\n";
                            Sleep(600);
                        }
                        srand(time (0));
                       num = rand()%6 + 49;
                        board[i][j] = num;
                        num = rand()%6 + 49;
                        board[i][j + 1] = num;
                        do {
                            num = rand()%6 + 49;
                            board[i][j + 2] = num;
                        } while ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2]));
                        do {
                            num = rand()%6 + 49;
                            board[i][j + 3] = num;
                        } while ((board[i][j + 1] == board[i][j + 2]) && (board[i][j + 1] == board[i][j + 3]));
                        do {
                            num = rand()%6 + 49;
                            board[i][j + 4] = num;
                        } while ((board[i][j + 1] == board[i][j + 2]) && (board[i][j + 1] == board[i][j + 3]) && (board[i][j + 1] == board[i][j + 4]));
                        board[row][col] = 'B';
                        match = true;
                        points = points + 20;
                        i = 0; j = 0;
                    }
                }
            }
        }
    }
}
}
void wrap()
{
	int num;
    int i, j;
    char temp1, temp2, temp3,temp4, temp5;
    for(int i=0;i<9;i++)
    {
    	for(int j=0;j<9;j++)
    	{
    		if(i<7 && j<8)
    		{
			
    		if( board[i][j]==board[i][j+1] && board[i][j]==board[i][j-1] && board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j])
    		{
			
    			temp1=board[i][j];
    			temp2=board[i+1][j];
    			temp3=board[i+2][j];
    			temp4=board[i][j-1];
    			temp5=board[i][j+1];
    			for (int k = 2; k > 0; k--) 
				{
                	board[i][j] = static_cast<char>(219);
                	board[i+1][j] = static_cast<char>(219);
                	board[i+2][j] = static_cast<char>(219);
                	board[i][j-1] = static_cast<char>(219);
                	board[i][j+1] = static_cast<char>(219);
                	boardSelector();
                	cout << "\t\tDivine\n";
                	Sleep(600);
                	board[i][j] = temp1;
                	board[i+1][j] = temp2;
                	board[i+2][j] = temp3;
                	board[i][j-1] = temp4;
                	board[i][j+1] = temp5;
                	boardSelector();
                	cout << "\t\tDivine\n";
                	Sleep(600);
            	}
            	srand(time (0));
            	num = rand()%6 + 49;
                board[i][j] = num;
                num = rand()%6 + 49;
                board[i][j+1]=num;
                do{
                	num = rand()%6 + 49;
                	board[i][j-1]=num;
				}while((board[i][j]==board[i][j+1] && board[i][j]==board[i][j-1]));
				do{
					num = rand()%6 + 49;
					board[i+1][j];
				}while((board[i][j]==board[i][j]==board[i][j+1] && board[i][j]==board[i][j-1] && board[i][j]==board[i+1][j]));
				num = rand()%6 + 49;
				board[i+2][j]=num;
				board[row][col]='W';
				points+=30;
				i=0;
				j=0;
        	}
        }
        else
        {
        	if(i<8 && j<7)
        	{
        		if(board[i][j]==board[i-1][j] &&  board[i][j]==board[i+1][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2])
        		{
        			temp1=board[i][j];
        			temp2=board[i-1][j];
        			temp3=board[i+1][j];
        			temp4=board[i][j+1];
        			temp5=board[i][j+2];
        			for(int k=0;k<2;k++)
        			{
        				board[i][j] = static_cast<char>(219);
                		board[i-1][j] = static_cast<char>(219);
                		board[i+1][j] = static_cast<char>(219);
                		board[i][j+1] = static_cast<char>(219);
                		board[i][j+2] = static_cast<char>(219);
                		boardSelector();
                		cout << "\t\tDivine\n";
                		Sleep(600);
                		board[i][j] = temp1;
                		board[i-1][j] = temp2;
                		board[i+1][j] = temp3;
                		board[i][j+1] = temp4;
                		board[i][j+2] = temp5;
                		boardSelector();
                		cout << "\t\tDivine\n";
                		Sleep(600);
					}
					srand(time (0));
					num = rand()%6 + 49;
					board[i][j] = num;
					num = rand()%6 + 49;
                	board[i-1][j]=num;
                	do{
                		num = rand()%6 + 49;
                		board[i+1][j]=num;
					}while((board[i][j]==board[i-1][j] &&  board[i][j]==board[i+1][j]));
					do{
						num = rand()%6 + 49;
						board[i][j+1]=num;
					}while((board[i][j]==board[i-1][j] &&  board[i][j]==board[i+1][j] && board[i][j]==board[i][j+1]));
					num = rand()%6 + 49;
					board[i][j+2]=num;
					board[row][col]='W';
					points+=30;
					i=0;
					j=0;
				}
			}
		}
		}
	}
    
}
void doubleBomb(char swap1, char swap2)
{
	if(swap1=='B' && swap2=='B')
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if((board[i][j]=='B' && board[i+1][j]=='B') || (board[i][j]=='B' && board[i-1][j]=='B') || (board[i][j]=='B' && board[i][j+1]=='B')
				|| (board[i][j]=='B' && board[i][j-1]=='B'))
				{
					for(int i=0;i<9;i++)
					{
						for(int j=0;j<9;j++)
						{
							board[i][j]=static_cast<char>(177);
						}
					}
					printBoard();
				}
			}
		}
	}
}
void stripBomb(char swap1, char swap2)
{
	char can;
	if((swap1=='S' && swap2=='B') || (swap1=='B' && swap2=='S') )
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if((board[i][j]=='B' && board[i+1][j]=='S') || (board[i][j]=='B' && board[i-1][j]=='S') || (board[i][j]=='B' && board[i][j+1]=='S')
				|| (board[i][j]=='B' && board[i][j-1]=='S'))
				{
					can=rand()%6+49;
					for(int i=0;i<9;i++)
					{
						for(int j=0;j<9;j++)
						{
							if(board[i][j]==can)
							board[i][j]='S';
						}
					}
				}
			}
		}
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(board[i][j]='S')
				{
					for(int k=0;k<9;k++)
					{
						board[i][k]=static_cast<char>(219);
						
					}
					Sleep(3000);
					for(int k=0;k<9;k++)
					{
						srand(time(0));
						can=rand()%6+49;
						board[i][k]=can;
						
					}
					for(int k=0;k<9;k++)
					{
						board[j][k]=static_cast<char>(219);
						
					}
					Sleep(3000);
					for(int k=0;k<9;k++)
					{
						srand(time(0));
						can=rand()%6+49;
						board[j][k]=can;
						
					}
				}
			}
		}
	}
}
void wrapBomb(char swap1, char swap2)
{
	char can;
	if((swap1=='W' && swap2=='B') || (swap1=='B' && swap2=='W') )
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if((board[i][j]=='B' && board[i+1][j]=='W') || (board[i][j]=='B' && board[i-1][j]=='W') || (board[i][j]=='B' && board[i][j+1]=='W')
				|| (board[i][j]=='B' && board[i][j-1]=='W'))
				{
					can=rand()%6+49;
					for(int i=0;i<9;i++)
					{
						for(int j=0;j<9;j++)
						{
							if(board[i][j]==can)
							board[i][j]='B';
						}
					}
				}
			}
		}
	}
}
void stripWrap(char swap1, char swap2)
{
	char can;
	if((swap1=='W' && swap2=='S') || (swap1=='S' && swap2=='W') )
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if((board[i][j]=='S' && board[i+1][j]=='W') || (board[i][j]=='S' && board[i-1][j]=='W') || (board[i][j]=='S' && board[i][j+1]=='W')
				|| (board[i][j]=='S' && board[i][j-1]=='W'))
				{
					can=rand()%6+49;
					for(int i=0;i<9;i++)
					{
						for(int j=0;j<9;j++)
						{
							if(board[i][j]==can)
							board[i][j]=can;
						}
					}
				}
			}
		}
	}
}
void wrapWrap(char swap1, char swap2)
{
	char can;
	if((swap1=='W' && swap2=='W') || (swap1=='W' && swap2=='W') )
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if((board[i][j]=='W' && board[i+1][j]=='W') || (board[i][j]=='W' && board[i-1][j]=='W') || (board[i][j]=='W' && board[i][j+1]=='W')
				|| (board[i][j]=='W' && board[i][j-1]=='W'))
				{
					can=rand()%6+49;
					for(int i=0;i<9;i++)
					{
						for(int j=0;j<9;j++)
						{
							if(board[i][j]==can)
							board[i][j]=can;
						}
					}
				}
			}
		}
	}
}

