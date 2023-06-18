#include <bits/stdc++.h>
#define LOCAL
#ifdef LOCAL
#include <conio.h>
#include <windows.h>
#endif // LOCAL
#define Up (72)
#define Down (80)
#define Left (75)
#define Right (77)
#define KeyDown(VK_NONAME) ((GetAsyncKeyState(VK_NONAME)&0x8000)?1:0)
#define CPP_11 false
#define CLS; clsAll();

using namespace std;
typedef HANDLE handle;
typedef clock_t tick;
const int TickPerSec=CLOCKS_PER_SEC;
const int Columns_x=80,Lines_y=25;

void clsAll();
void color(int =15);
void gotoxy(int,int);
void hideCursor();
void printWithDelay(string,int =50);
void printInCenter(string,int =0);

class RandNumGenerator
{
private:

public:
    bool test_();
    int getRandom(int,int);
    int getRandom(int =10);
    vector<int> getRandomArrayUnique(int =1,int =100,int =10);
    vector<int> getRandomArray(int =1,int =100,int =10,bool =false);
};
int RandNumGenerator::getRandom(int n)
{
    return rand()%(n+1);
}
int RandNumGenerator::getRandom(int l,int r)
{
    return rand()%(r-l+1)+l;
}
vector<int> RandNumGenerator::getRandomArray(int l,int r,int n,bool _unique)
{
    vector<int>q;
    if(!_unique)
    {
        for(int i=1;i<=n;i++)
        {
            q.push_back(getRandom(l,r));
        }
        return q;
    }
    else
    {
        return getRandomArrayUnique(l,r,n);
    }
//    vector<int>::iterator it;
//    for(it=q.begin();it!=q.end();it++)
//    {
//        cout<<*it<<" ";
//    }cout<<endl;
}
vector<int> RandNumGenerator::getRandomArrayUnique(int l,int r,int n)
{
    vector<int>q;
    for(int i=l;i<=r;i++)
    {
        q.push_back(i);
    }
    random_shuffle(q.begin(),q.end());
    vector<int>temp;
    n=min(n,r-l+1);
    for(int i=0;i<n;i++)
    {
        temp.push_back(q[i]);
    }
    return temp;
}
bool RandNumGenerator::test_()
{
    //srand(time(NULL));
    int _l=1,_r=10,_n=5;
    bool _unique=false;
    int _endline=5;
    vector<int>::iterator it;
    char c;
    CLS;
    while(1)
    {
        CLS;
        cout<<"RandNumGenerator__TEST-MODE"<<endl;
        cout<<"1.Single"<<endl
            <<"2.Array"<<endl
            <<"3.Set"<<endl;
        c=getch();
        if(c=='1')
        {
            cout<<getRandom(_l,_r)<<endl;
            c=getch();
            continue;
        }
        if(c=='2')
        {
            vector<int>ans=getRandomArray(_l,_r,_n,_unique);
            int _count=0;
            for(it=ans.begin();it!=ans.end();it++)
            {
                cout<<*it<<" ";
                if(++_count==_endline)
                {
                    cout<<endl;
                    _count-=_endline;
                }
            }cout<<endl;
            c=getch();
            continue;
        }
        if(c=='3')
        {
            while(1)
            {
                CLS;
                cout<<"1.Range= [ " <<_l<<" , "<<_r<<" ]"<<endl
                    <<"2.n= "<<_n<<endl
                    <<"3._unique= "<<_unique<<endl
                    <<"4.Exit"<<endl;
                c=getch();
                if(c=='1')
                {
                    cout<<"Cin:"<<endl;
                    cin>>_l>>_r;
                    continue;
                }
                if(c=='2')
                {
                    cout<<"Cin:"<<endl;
                    cin>>_n;
                    continue;
                }
                if(c=='3')
                {
                    cout<<"Exchange It"<<endl;
                    c=getch();
                    _unique=!_unique;
                    continue;
                }
                if(c=='4')
                {
                    break;
                }
            }
            continue;
        }
    }
//    int temp=getRandom(l,r);
//    int num[15];
//    int t=0;
//    memset(num,0,sizeof(num));
//    while(temp<=10 && temp>=1)
//    {
//        t++;
//        cout<<temp<<endl;
//        num[temp]++;
//        temp=getRandom(l,r);
//        //Sleep(50);
//        if(t>100)break;
//    }
//    cout<<"Wrong:"<<endl;
//    for(int i=1;i<=10;i++)
//    {
//        if(!num[i])
//        {
//            cout<<i<<endl;
//        }
//    }
}

class Item
{
public:
    string name;
    string describe;
    Item():name("NULL"),describe("NULL"){}
    Item(string _name,string _describe):name(_name),describe(_describe){}
    void disPlay(int =1);
};
void Item::disPlay(int style)
{
    if(style==1)
    {
        cout<<"『"<<name<<"』"<<endl;
    }
    else
    {
        cout<<"「"<<name<<"」"<<endl;
    }
}

class GameSourceManager
{
private:
    int round;
    int day;
    RandNumGenerator RDG;
public:
    GameSourceManager()
    {
        init();
    }
    vector<Item>arr;

    void init();
    int getRandom(int,int);
    int getRandom(int =10);
    void disPlayAll();
    void disPlaySingle(int);
    void startInterface();
    void mainInterface();
    void mainLoopVs();
    void gameLoopCs();
    friend void printWithDelay();
    friend void clsAll();
    friend void color();
    friend void gotoxy();
    friend void hideCursor();
};
void GameSourceManager::mainInterface()
{
    char ope;
    while(true)
    {
        cout<<"1. Start"<<endl
            <<"2. Option"<<endl
            <<"3. Exit"<<endl;
        ope=getch();
        if(ope=='1')
        {
            gameLoopCs();
        }
        if(ope=='2')
        {
            cout<<"NO"<<endl;
            Sleep(750);
        }
        if(ope=='3')
        {
            exit(0);
        }
        CLS;
    }

}
void GameSourceManager::startInterface()
{
    printInCenter("MineTale",50);
    for(int i=1;i<Lines_y-2;i++)
    {
        cout<<endl;
    }
    printInCenter("**press any key to continue**");
    char c=getch();
    CLS;
}
void GameSourceManager::init()
{
    SetConsoleTitle("MineTale");
    system("mode con cols=80 lines=25");
    srand(time(NULL));
    hideCursor();

    //arr.push_back(Item{"4k","outlook"});
}
int GameSourceManager::getRandom(int l,int r)
{
    return RDG.getRandom(l,r);
}
int GameSourceManager::getRandom(int n)
{
    return RDG.getRandom(n);
}
void GameSourceManager::mainLoopVs()
{

}
void GameSourceManager::gameLoopCs()
{
//    cout<<"DAY [1]"<<endl;
//    cout<<"Explore"<<endl;
    CLS;
    cout<<""<<endl
        <<""<<endl
        <<""<<endl
        <<""<<endl
        <<""<<endl
        <<" ________     ________    ____ "<<endl
        <<"|Explore|    |BackPack|  |Save|"<<endl
        <<""<<endl;
    system("Pause");


}
void GameSourceManager::disPlayAll()
{
    #if CPP_11
    for(auto it:arr)
    {
        it.disPlay();
    }
    #else
    vector<Item>::iterator it=arr.begin();
    for(it=arr.begin();it!=arr.end();it++)
    {
        it->disPlay();
    }

    #endif
}
void GameSourceManager::disPlaySingle(int pos)
{
    arr[pos].disPlay();
}

class Being
{
public:
    int hp;
    int ak;
    Being(){}
    Being(int _hp,int _ak):hp(_hp),ak(_ak){}
    //void attack(Being&);
};

class Player:public Being
{
public:
    string name;
    Player(int _hp,int _ak,string _name="NULL"):Being(_hp,_ak),name(_name){}
    void attack(Being&);
    friend ostream& operator<<(ostream&,Player&);
};
void Player::attack(Being& B)
{
    B.hp-=(ak*10);
}

class Beast:public Being
{
public:
    string race;
    void attack(Player&);
    Beast(int _hp,int _ak,string _race="Zombies"):Being(_hp,_ak),race(_race){}
    friend ostream& operator<<(ostream&,Beast&);
};
void Beast::attack(Player& B)
{
    B.hp-=ak;
}

class StringBase
{
public:
    string str;
    StringBase(string _str):str(_str){}
    friend ostream& operator<<(ostream&,StringBase&);
};

int main()
{
//    GameSourceManager Win;
//    Win.startInterface();
//    Win.mainInterface();

//    int tot=0;
//    while(1)
//    {
//        if(KeyDown(VK_UP))
//        {
//            tot++;
//            cout<<tot<<endl;
//            Sleep(500);
//        }
//    }

    StringBase s("123");
    cout<<s;

//    RandNumGenerator t;
//    t.test_();

    //t.test_();

//     switch(c)
//     {
//     case 72:
//         cout<<"Up"<<endl;
//         break;
//     case 75:
//         cout<<"Left"<<endl;
//         break;
//     case 80:
//         cout<<"Down"<<endl;
//         break;
//     case 77:
//         cout<<"Right"<<endl;
//         break;
//     }

///**Player Demo**
//    Player m(1,5);
//    Beast k(5,7);
//    cout<<m<<endl;
//    cout<<k<<endl;
//    m.attack(k);
//    k.attack(m);
//    cout<<m<<endl;
//    cout<<k<<endl;

    return 0;
}

void gotoxy(int x,int y)
{
    handle hout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos={x,y};
    SetConsoleCursorPosition(hout,pos);
    // x-->
    //y
    //begin with (0,0)
}
void hideCursor()
{
    handle hout=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(hout,&cursor_info);
}
void color(int tmp)
{
    handle hout=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hout,tmp);
    //SetConsoleTextAttribute(hout,FOREGROUND_BLUE|FOREGROUND_GREEN);
}
void clsAll()
{
    handle hout=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hout,&csbi);
    DWORD sizew = csbi.dwSize.X * csbi.dwSize.Y,num = 0;
    COORD pos={0,0};
    FillConsoleOutputCharacter(hout,' ',sizew,pos,&num);
    FillConsoleOutputAttribute(hout,csbi.wAttributes,sizew,pos,&num);
    SetConsoleCursorPosition(hout, pos);
}
void printInCenter(string str,int delay)
{
    int len=str.size();
    int left_size=(Columns_x-len)/2;
    for(int i=1;i<=left_size;i++)cout<<" ";
    printWithDelay(str,delay);
    cout<<endl;
}

void printWithDelay(string str,int delay)
{
    #if CPP_11
    for(auto it:str)
    {
        cout<<it<<" ";
    }
    #else
    for(int i=0;i<str.size();i++)
    {
        cout<<str[i];
        Sleep(delay);
    }
    #endif // CPP_11
}

//void Being::attack(Being& B)
//{
//    B.hp-=ak;
//    if(B.hp<0)B.hp=0;
//}

ostream& operator<<(ostream& out,Player& tmp)
{
    out<<"『"<<tmp.name<<"』"<<endl;
    out<<"HP:"<<tmp.hp;
    return out;
}
ostream& operator<<(ostream& out,Beast& tmp)
{
    out<<"『"<<tmp.race<<"』"<<endl;
    out<<"HP:"<<tmp.hp;
    return out;
}

ostream& operator<<(ostream& out,StringBase& str)
{
    out<<"┌────┐"<<endl
       <<"│ffu     │"<<endl
       <<"└────╯"<<endl;
    return out;
}
