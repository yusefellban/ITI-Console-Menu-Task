#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
using namespace std;

void gotoxy(int x, int y);
bool isExtended(char ch);
int getCharASCII();
int moveDown(int column,int row);
int moveUp(int column,int row);
int movEend(int column,int row);
int movHome(int column,int row);
void pressEnter(int row);
void colorText(int row);
void clearColorText(int row);
void moveMassage();
int main()
{

    gotoxy(42,1);
    cout << "\033[33mWelcom in our menu \033[0m";
    cout << "\033[41m ITI \033[0m\n";
  int row=3,col=52;
  ///Draw menu
  gotoxy(col,row);
  cout<<"File";
  row++;//4
  gotoxy(col,row);
  cout<<"Edit";
  row++;//5
  gotoxy(col,row);
  cout<<"Save";
  row++;//6
  gotoxy(col,row);
  cout<<"Exit";

  row=3;col=50;//new start
  gotoxy(col,row);
  cout<<"\033[32m->\033[0m"; /// ->
 thread t(moveMassage);
//////////////
while(true){
        int charNumber=getCharASCII();
        switch(charNumber){
        case 80:
            row=moveDown(col,row);
            break;
        case 79:
            row=movEend(col,row);
            break;
        case 72:
            row=moveUp(col,row);
            break;
        case 71:
            row=movHome(col,row);
            break;
        case 13:
            pressEnter(row);
        }


}

 t.join();
    return 0;
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
bool isExtended(char ch){
    if(ch == -32){
        return 1;
    }
    else{
        return 0;
    }
}
int getCharASCII(){
    char ch;
    ch=getch();
    if(isExtended(ch)){
        ch=getch();
        return (int)ch;
    }
    else{
        //return -1;
         return (int)ch;
    }
}

int moveDown(int column,int row){
        gotoxy(column,row);
        cout<<"  ";
        clearColorText(row);
        if(row==6){
            row=3;
        }
        else{
            row++;
        }
          gotoxy(column,row);
          cout<<"\033[32m->\033[0m"; /// ->
          colorText(row);
        return row;
}
int moveUp(int column,int row){
        gotoxy(column,row);
        cout<<"  ";
        clearColorText(row);
        if(row==3){
            row=6;
        }
        else{
            row--;
        }
        gotoxy(column,row);
        cout<<"\033[32m->\033[0m"; // ->
         colorText(row);
        return row;
}

int movEend(int column,int row){
        gotoxy(column,row);
        cout<<"  ";
        clearColorText(row);
        gotoxy(column,6);
        cout<<"\033[32m->\033[0m"; /// ->
        colorText(6);
         return 6;//new row
}
int movHome(int column,int row){
        gotoxy(column,row);
        cout<<"  ";
        clearColorText(row);
        gotoxy(column,3);
        cout<<"\033[32m->\033[0m"; /// ->
         colorText(3);
         return 3;//new row
}

void pressEnter(int row){
     gotoxy(48,8);
    switch(row){
    case 3:
        cout << "\033[35mFile Entered\033[0m";
        break;
    case 4:
         cout << "\033[33mEdit Entered\033[0m" ;
        break;
    case 5:
         cout << "\033[32mSave Entered\033[0m" ;
        break;
    case 6:
          cout << "\033[31mExit Entered\033[0m" ;
        break;
    }
}

void colorText(int row){
    switch(row){
    case 3:
          cout << "\033[35mFile\033[0m";
        break;
    case 4:
         cout << "\033[33mEdit\033[0m" ;
        break;
    case 5:
         cout << "\033[32mSave\033[0m" ;
        break;
    case 6:
         cout << "\033[31mExit\033[0m" ;
        break;
    }
}
void clearColorText(int row){
    switch(row){
    case 3:
          cout << "File";
        break;
    case 4:
         cout << "Edit";
        break;
    case 5:
         cout << "Save";
        break;
    case 6:
         cout << "Exit";
        break;
    }
}

void moveMassage() {
    int x = 0;
    int y = 18;
    int direction = 1;
    const int width = 60;

    while (true) {
        gotoxy(x, y);
        cout << "\033[31mPeople Develop Countries, So We Develop P.E.O.P.L.E\033[0m";
        Sleep(160);
        gotoxy(x, y);
        cout << "                                                     ";
        x += direction;
        if (x >= width || x <= 0)
            direction *= -1;
    }
}
