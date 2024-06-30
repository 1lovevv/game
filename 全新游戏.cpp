#include<bits/stdc++.h>
#include <conio.h> 
using namespace std;



const int h=29;
const int w=40;


int playX=1;
int playY=1;

int eX=1;
int eY=7;

char Map[h][w]={
    "------------------------------------|",
    "|                                   |",
    "|  ---  ---  ---  ---  ---  --- --- |",
    "|  |                                |",
    "|  |  --- ----     | ----  -  -  -  |",
    "|  |         |  |  |       -  -  -  |",
    "|  |  ------ |  |  | ----  -  -  -  —",
    "|                                   —",
    "-------------------------------------"};
    
void rendmap()
{
	system("cls"); 
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(i==playY&&j==playX)
			{
				cout<<"我";
			}
			else if(i==eY&&j==eX)
			{
				cout<<"鬼";
			}
			else {
				cout<<Map[i][j];
			}
		}
		cout<<endl;
	}
	
}

void handleInput() {
    char input = _getch(); 

    switch (input) {
        case 'w':
            if (Map[playY - 1][playX] != '-'&&Map[playY - 1][playX] != '|') {
                playY--;
            }
            break;
        case 's':
            if (Map[playY + 1][playX] != '-'&&Map[playY + 1][playX] != '|') {
                playY++;
            }
            break;
        case 'a':
            if (Map[playY][playX - 1] != '-'&&Map[playY][playX - 1] != '|') {
                playX--;
            }
            break;
        case 'd':
            if (Map[playY][playX + 1] != '-'&&Map[playY][playX + 1] != '|') {
                playX++;
            }
            break;
        case 'q':
        	 cout<<"欢迎下次再来";
            exit(0); 
           
            break;
    }
}

int aa=playX;
int bb=playY;

double Distance(int x1, int y1, int x2, int y2) 
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


void bfs()
{
	int distance1=Distance(eX+1, eY, playX, playY) ;
	int distance2=Distance(eX-1, eY, playX, playY) ;
	int distance3=Distance(eX, eY+1, playX, playY) ;
    int distance4=Distance(eX, eY-1, playX, playY) ;
	int arr[4]={distance1,distance3,distance3,distance4};
	sort(arr,arr+3);
	for(double i=4;i>0;i--)
	{
		if(i==distance1&&Map[eY][eX+1]!='|'&&Map[eY][eX+1]!='-')
		{
			eX+1;
			break;
		}
		if(i==distance2&&Map[eY][eX-1]!='|'&&Map[eY][eX+1]!='-')
		{
			eX-1;
			break;
		}
		if(i==distance3&&Map[eY][eX+1]!='|'&&Map[eY+1][eX]!='-')
		{
			eY+1;
			break;
		}
		if(i==distance4&&Map[eY][eX+1]!='|'&&Map[eY-1][eX]!='-')
		{
			eY-1;
			break;
		}
	}
	
}





int main()
{
	cout<<"你干嘛" ;
	while(true)
	{
		rendmap();
		handleInput();
		bfs();
	
	}
	
	return 0;
}
