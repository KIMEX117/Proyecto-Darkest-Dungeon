#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}
void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos.X = x;
    dwpos.Y = y;
    SetConsoleCursorPosition(hcon, dwpos);
}
int main()
{
    cout<<"|======================================|"<<endl;
    cout<<"|*~-.|DISENOS PARA DARKEST DUNGEON|.-~*|"<<endl;
    cout<<"|======================================|"<<endl;
    gotoxy(0,4);
    cout<<"---------------------------------------"<<endl;
    cout<<"             ~CRUSADER~"<<endl;
    cout<<endl;
    //ESPADA DISEÑO 1
    cout<<"ESPADA 1"<<endl;
    cout<<endl;
    cout<<"  /|"<<char(92)<<" "<<endl;
    cout<<" | | | "<<endl;
    cout<<" | | | "<<endl;
    cout<<" | | | "<<endl;
    cout<<"[/////]"<<endl;
    cout<<"  |_|  "<<endl;
    cout<<" (~~~) "<<endl;
    //ESPADA DISEÑO 2
    gotoxy(14,7);
    cout<<"ESPADA 2"<<endl;
    cout<<endl;
    gotoxy(14,9);
    cout<<"   /|"<<char(92)<<"   "<<endl;
    gotoxy(14,10);
    cout<<"  | | |  "<<endl;
    gotoxy(14,11);
    cout<<"  | | |  "<<endl;
    gotoxy(14,12);
    cout<<"  | | |  "<<endl;
    gotoxy(14,13);
    cout<<"<[:::::]>"<<endl;
    gotoxy(14,14);
    cout<<"   |_|   "<<endl;
    gotoxy(14,15);
    cout<<"   (~)   "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"             ~HIGHWAYMAN~"<<endl;
    cout<<endl;
    cout<<"PISTOLA 1"<<endl;
    cout<<endl;
    cout<<"  __,____ "<<endl;
    cout<<" /__.==--"<<char(34)<<endl;
    cout<<"/#(-'     "<<endl;
    cout<<"`-'		 "<<endl;
    gotoxy(14,20);
    cout<<"PISTOLA 2"<<endl;
    gotoxy(14,22);
    cout<<"   _,________"<<endl;
    gotoxy(14,23);
    cout<<"	_T _==____()"<<endl;
    gotoxy(14,24);
    cout<<" /##(_)-'     "<<endl;
    gotoxy(14,25);
    cout<<"/##/          "<<endl;
    gotoxy(14,26);
    cout<<char(34)<<char(34)<<char(34)<<"          "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"             ~VESTAL~"<<endl;
    cout<<endl;
    cout<<"LIBRO"<<endl;
    cout<<endl;
    cout<<"    _______ "<<endl;
    cout<<"   /      /,"<<endl;
    cout<<"  /      // "<<endl;
    cout<<" /______//  "<<endl;
    cout<<"(______(/   "<<endl;
    gotoxy(14,31);
    cout<<"MAZO"<<endl;
    gotoxy(14,33);
    cout<<"  ___  "<<endl;
    gotoxy(14,34);
    cout<<"<|"<<char(34)<<"^"<<char(34)<<"|>"<<endl;
    gotoxy(14,35);
    cout<<"<|^"<<char(34)<<"^|>"<<endl;
    gotoxy(14,36);
    cout<<"<|"<<char(34)<<"^"<<char(34)<<"|>"<<endl;
    gotoxy(14,37);
    cout<<"  "<<char(92)<<" /"<<endl;
    gotoxy(14,38);
    cout<<"  | |"<<endl;
    gotoxy(14,39);
    cout<<"  |_|"<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"             ~HELLION~"<<endl;
    cout<<endl;
    cout<<"DISENO 1-A"<<endl;
    cout<<endl;
    cout<<",^_,-,"<<endl;
    cout<<"|_   |"<<endl;
    cout<<"||`--'"<<endl;
    cout<<"||    "<<endl;
    cout<<"||    "<<endl;
    cout<<"||    "<<endl;
    cout<<"~~    "<<endl;
    gotoxy(14,44);
    cout<<"DISENO 1-B"<<endl;
    gotoxy(14,46);
    cout<<" _,-,"<<endl;
    gotoxy(14,47);
    cout<<"T_  |"<<endl;
    gotoxy(14,48);
    cout<<"||`-'"<<endl;
    gotoxy(14,49);
    cout<<"||   "<<endl;
    gotoxy(14,50);
    cout<<"||   "<<endl;
    gotoxy(14,51);
    cout<<"||   "<<endl;
    gotoxy(14,52);
    cout<<"~~   "<<endl;
    gotoxy(28,44);
    cout<<"DISENO 2-A"<<endl;
    gotoxy(28,46);
    cout<<"[]_/"<<char(92)<<" "<<endl;
    gotoxy(28,47);
    cout<<"||_ [|"<<endl;
    gotoxy(28,48);
    cout<<"|| "<<char(92)<<"/ "<<endl;
    gotoxy(28,49);
    cout<<"||    "<<endl;
    gotoxy(28,50);
    cout<<"||    "<<endl;
    gotoxy(28,51);
    cout<<"||    "<<endl;
    gotoxy(28,52);
    cout<<"||    "<<endl;
    gotoxy(28,53);
    cout<<"||    "<<endl;
    gotoxy(42,44);
    cout<<"DISENO 2-B"<<endl;
    gotoxy(42,46);
    cout<<",^,_/"<<char(92)<<" "<<endl;
    gotoxy(42,47);
    cout<<"||__ [|"<<endl;
    gotoxy(42,48);
    cout<<"||  "<<char(92)<<"/ "<<endl;
    gotoxy(42,49);
    cout<<"||     "<<endl;
    gotoxy(42,50);
    cout<<"||     "<<endl;
    gotoxy(42,51);
    cout<<"||     "<<endl;
    gotoxy(42,52);
    cout<<"||     "<<endl;
    gotoxy(42,53);
    cout<<"||     "<<endl;
    gotoxy(56,44);
    cout<<"DISENO 3-A"<<endl;
    gotoxy(56,46);
    cout<<"/"<<char(92)<<"  .  "<<endl;
    gotoxy(56,47);
    cout<<"||-'"<<char(92)<<char(92)<<" "<<endl;
    gotoxy(56,48);
    cout<<"||=- |)"<<endl;
    gotoxy(56,49);
    cout<<"||-.// "<<endl;
    gotoxy(56,50);
    cout<<"||  '  "<<endl;
    gotoxy(56,51);
    cout<<"||     "<<endl;
    gotoxy(56,52);
    cout<<"||     "<<endl;
    gotoxy(56,53);
    cout<<"||     "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"            ~PLAGUE DOCTOR~"<<endl;
    cout<<endl;
    cout<<"DISENO 1-A"<<endl;
    cout<<endl;
    cout<<"   _.~~	"<<endl;
    cout<<"  (__)  "<<endl;
    cout<<"  <  >  "<<endl;
    cout<<"   )(   "<<endl;
    cout<<"  /~~"<<char(92)<<"  "<<endl;
    cout<<" /~~~~"<<char(92)<<" "<<endl;
    cout<<"(______)"<<endl;
    gotoxy(14,58);
    cout<<"DISENO 1-B"<<endl;
    gotoxy(14,61);
    cout<<"   _.~~  "<<endl;
    gotoxy(14,62);
    cout<<"  (__)   "<<endl;
    gotoxy(14,63);
    cout<<"   ||  	"<<endl;
    gotoxy(14,64);
    cout<<"  /~~"<<char(92)<<" 	"<<endl;
    gotoxy(14,65);
    cout<<" /~~~~"<<char(92)<<" "<<endl;
    gotoxy(14,66);
    cout<<"(______)"<<endl;
    gotoxy(28,58);
    cout<<"DISENO 2-A"<<endl;
    gotoxy(28,62);
    cout<<"   .~~"<<endl;
    gotoxy(28,63);
    cout<<" |~|  "<<endl;
    gotoxy(28,64);
    cout<<" | |  "<<endl;
    gotoxy(28,65);
    cout<<".' `. "<<endl;
    gotoxy(28,66);
    cout<<"`._.' "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"            ~BOUNTY HUNTER~"<<endl;
    cout<<endl;
    cout<<"DISENO 1"<<endl;
    cout<<endl;
    cout<<"   ___	"<<endl;
    cout<<" __) `"<<char(92)<<"	"<<endl;
    cout<<"< __=- |"<<endl;
    cout<<" "<<char(92)<<char(92)<<" `)/	"<<endl;
    cout<<"  "<<char(92)<<char(92)<<" (	"<<endl;
    cout<<"   "<<char(92)<<char(92)<<"	"<<endl;
    cout<<"    "<<char(92)<<char(92)<<"	"<<endl;
    cout<<"    <_>"<<endl;
    gotoxy(14,71);
    cout<<"DISENO 2"<<endl;
    gotoxy(14,73);
    cout<<"     __  "<<endl;
    gotoxy(14,74);
    cout<<"  /"<<char(92)<<" ) "<<char(92)<<" "<<endl;
    gotoxy(14,75);
    cout<<"<=()=>  )"<<endl;
    gotoxy(14,76);
    cout<<"  || )_/ "<<endl;
    gotoxy(14,77);
    cout<<"  ||     "<<endl;
    gotoxy(14,78);
    cout<<"  ||     "<<endl;
    gotoxy(14,79);
    cout<<"  ||     "<<endl;
    gotoxy(14,80);
    cout<<"  ||     "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"            ~GRAVE ROBBER~"<<endl;
    cout<<endl;
    cout<<"DISENO 1"<<endl;
    cout<<endl;
    cout<<" /|"<<char(92)<<"   o  "<<endl;
    cout<<" |||   |  "<<endl;
    cout<<" ||| <===>"<<endl;
    cout<<"<===> ||| "<<endl;
    cout<<"  |   ||| "<<endl;
    cout<<"  o   "<<char(92)<<"|/ "<<endl;
    gotoxy(14,85);
    cout<<"DISENO 2"<<endl;
    gotoxy(14,88);
    cout<<" O   | "<<endl;
    gotoxy(14,89);
    cout<<" |   | "<<endl;
    gotoxy(14,90);
    cout<<"/="<<char(92)<<" "<<char(92)<<"|/"<<endl;
    gotoxy(14,91);
    cout<<" |   | "<<endl;
    gotoxy(14,92);
    cout<<" |   O "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"              ~JESTER~"<<endl;
    cout<<endl;
    cout<<"DISENO 1"<<endl;
    cout<<endl;
    cout<<" *****"<<endl;
    cout<<"**   **"<<endl;
    cout<<"*   ***"<<endl;
    cout<<"   *** "<<endl;
    cout<<"   **  "<<endl;
    cout<<"   ||  "<<endl;
    cout<<"  (__) "<<endl;
    gotoxy(14,97);
    cout<<"DISENO 2"<<endl;
    gotoxy(14,99);
    cout<<"  ___  "<<endl;
    gotoxy(14,100);
    cout<<" / _ "<<char(92)<<" "<<endl;
    gotoxy(14,101);
    cout<<"/ / "<<char(92)<<" "<<char(92)<<endl;
    gotoxy(14,102);
    cout<<char(92)<<"_> / /"<<endl;
    gotoxy(14,103);
    cout<<"   / / "<<endl;
    gotoxy(14,104);
    cout<<"   ||  "<<endl;
    gotoxy(14,105);
    cout<<"   ||  "<<endl;
    gotoxy(14,106);
    cout<<"  [--] "<<endl;
    gotoxy(28,97);
    cout<<"DISENO 3"<<endl;
    gotoxy(28,99);
    cout<<" ___   "<<endl;
    gotoxy(28,100);
    cout<<"/ __ "<<char(92)<<" "<<endl;
    gotoxy(28,101);
    cout<<char(92)<<"/  "<<char(92)<<" "<<char(92)<<endl;
    gotoxy(28,102);
    cout<<"    / /"<<endl;
    gotoxy(28,103);
    cout<<"   / / "<<endl;
    gotoxy(28,104);
    cout<<"  [==] "<<endl;
    gotoxy(28,105);
    cout<<"   ||  "<<endl;
    gotoxy(28,106);
    cout<<"  (##) "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<endl;
    cout<<"       ==== [E N E M I E S] ===="<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"              ~SPIDER~"<<endl;
    cout<<endl;
    cout<<"DISENO 1"<<endl;
    cout<<endl;
    cout<<"  / _ "<<char(92)<<"	"<<endl;
    cout<<char(92)<<"_"<<char(92)<<"(_)/_/"<<endl;
    cout<<" _//"<<char(34)<<char(92)<<char(92)<<"_ "<<endl;
    cout<<"  /   "<<char(92)<<"	"<<endl;
    gotoxy(14,115);
    cout<<"DISENO 2"<<endl;
    gotoxy(14,117);
    cout<<"  / _ "<<char(92)<<"	"<<endl;
    gotoxy(14,118);
    cout<<char(92)<<"_"<<char(92)<<"(_)/_/"<<endl;
    gotoxy(14,119);
    cout<<" _//O"<<char(92)<<char(92)<<"_ "<<endl;
    gotoxy(14,120);
    cout<<"  /   "<<char(92)<<"	"<<endl;
    gotoxy(28,115);
    cout<<"DISENO 3"<<endl;
    gotoxy(28,117);
    cout<<"  //  "<<char(92)<<char(92)<<"  "<<endl;
    gotoxy(28,118);
    cout<<" _"<<char(92)<<char(92)<<"()//_"<<endl;
    gotoxy(28,119);
    cout<<"/ //  "<<char(92)<<char(92)<<" "<<char(92)<<endl;
    gotoxy(28,120);
    cout<<" | "<<char(92)<<"__/ |"<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"              ~SKELETON~"<<endl;
    cout<<endl;
    cout<<"DISENO 1"<<endl;
    cout<<endl;
    cout<<" _____ "<<endl;
    cout<<"/     "<<char(92)<<endl;
    cout<<"|() ()|"<<endl;
    cout<<char(92)<<"  ^  /"<<endl;
    cout<<" ||||| "<<endl;
    cout<<" ''''' "<<endl;
    gotoxy(14,125);
    cout<<"DISENO 2"<<endl;
    gotoxy(14,127);
    cout<<" .----. "<<endl;
    gotoxy(14,128);
    cout<<"/      "<<char(92)<<endl;
    gotoxy(14,129);
    cout<<"|()  ()|"<<endl;
    gotoxy(14,130);
    cout<<char(92)<<"  /"<<char(92)<<"  /"<<endl;
    gotoxy(14,131);
    cout<<" | "<<char(34)<<char(34)<<" | "<<endl;
    gotoxy(14,132);
    cout<<" |####| "<<endl;
    gotoxy(14,133);
    cout<<" |----| "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"          ~ENEMICO CON PISTOLA~"<<endl;
    cout<<endl;
    cout<<"NORMAL"<<endl;
    cout<<endl;
    cout<<"  ,________."<<endl;
    cout<<" >`(==(----'"<<endl;
    cout<<"(__/~~`     "<<endl;
    gotoxy(14,138);
    cout<<"INVERTIDO"<<endl;
    gotoxy(14,140);
    cout<<".________,"<<endl;
    gotoxy(14,141);
    cout<<"'----)==)`<"<<endl;
    gotoxy(14,142);
    cout<<"     `~~"<<char(92)<<"__)"<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"                ~SNAKE~"<<endl;
    cout<<endl;
    cout<<"DISENO 1"<<endl,
    cout<<endl;
    cout<<"   _____   "<<endl;
    cout<<"  /.   ."<<char(92)<<"  "<<endl;
    cout<<" /--)W(--"<<char(92)<<" "<<endl;
    cout<<"(---| |---)"<<endl;
    cout<<" "<<char(92)<<"--| |--/ "<<endl;
    cout<<"  "<<char(92)<<"_| |_/  "<<endl;
    cout<<" ___| |___ "<<endl;
    cout<<"('-_|_|_-')"<<endl;
    cout<<" '._____.' "<<endl;
    gotoxy(14,147);
    cout<<"DISENO 2"<<endl;
    gotoxy(14,149);
    cout<<"  _    _  "<<endl;
    gotoxy(14,150);
    cout<<",(|)--(|)."<<endl;
    gotoxy(14,151);
    cout<<char(92)<<"   ..   /"<<endl;
    gotoxy(14,152);
    cout<<" "<<char(92)<<"______/ "<<endl;
    gotoxy(14,153);
    cout<<"   V  V   "<<endl;
    gotoxy(14,154);
    cout<<"  `.^^`.  "<<endl;
    gotoxy(14,155);
    cout<<"   "<<char(92)<<"^^^"<<char(92)<<"  "<<endl;
    gotoxy(14,156);
    cout<<"   |^^^|  "<<endl;
    gotoxy(14,157);
    cout<<"   |^^^|  "<<endl;
    gotoxy(28,147);
    cout<<"DISENO 3"<<endl;
    gotoxy(28,149);
    cout<<"   ___  "<<endl;
    gotoxy(28,150);
    cout<<"  /   "<<char(92)<<" "<<endl;
    gotoxy(28,151);
    cout<<" |     "<<char(92)<<" "<<endl;
    gotoxy(28,152);
    cout<<" |  /"<<char(92)<<"  |"<<endl;
    gotoxy(28,153);
    cout<<" | | |  |"<<endl;
    gotoxy(28,154);
    cout<<"(o o)|  |"<<endl;
    gotoxy(28,155);
    cout<<" "<<char(92)<<"_/ |  |"<<endl;
    gotoxy(28,156);
    cout<<"  |  |  |"<<endl;
    gotoxy(28,157);
    cout<<"  ^      "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"              ~SYCOPHANT~"<<endl;
    cout<<endl;
    cout<<"DISENO 1"<<endl,
    cout<<endl;
    cout<<"  '__'	"<<endl;
    cout<<" "<<char(92)<<"O__O/	"<<endl;
    cout<<"==x||x=="<<endl;
    cout<<" /^||^"<<char(92)<<"	"<<endl;
    cout<<"/^^||^^"<<char(92)<<endl;
    cout<<char(92)<<"^^||^^/"<<endl;
    cout<<" '-''-'"<<endl;
    gotoxy(14,162);
    cout<<"DISENO 2"<<endl;
    gotoxy(14,165);
    cout<<"    _  _      "<<endl;
    gotoxy(14,166);
    cout<<"   | )/ )     "<<endl;
    gotoxy(14,167);
    cout<<char(92)<<char(92)<<" |//,' __   "<<endl;
    gotoxy(14,168);
    cout<<"("<<char(34)<<")(_)-"<<char(34)<<"()))=-"<<endl;
    gotoxy(14,169);
    cout<<"   ("<<char(92)<<char(92)<<"        "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"              ~SHRIEKER~"<<endl;
    cout<<endl;
    cout<<"DISENO 1"<<endl,
    cout<<endl;
    cout<<"  _.-.   "<<endl;
    cout<<"  `) | 	"<<endl;
    cout<<" //   "<<char(92)<<char(92)<<" "<<endl;
    cout<<"/ :   ; "<<char(92)<<endl;
    cout<<"  "<<char(92)<<"  /   "<<endl;
    cout<<"  /||"<<char(92)<<"   "<<endl;
    cout<<" / ^^ "<<char(92)<<"  "<<endl;
    cout<<" `'``'`  "<<endl;
    gotoxy(14,174);
    cout<<"DISENO 2"<<endl;
    gotoxy(14,179);
    cout<<" ,_  "<<endl;
    gotoxy(14,180);
    cout<<">' ) "<<endl;
    gotoxy(14,181);
    cout<<"( ( "<<char(92)<<endl;
    gotoxy(14,182);
    cout<<" ''|"<<char(92)<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"             ~BONE ARBALEST~"<<endl;
    cout<<endl;
    cout<<"NORMAL"<<endl,
    cout<<endl;
    cout<<"   /"<<char(92)<<"   "<<endl;
    cout<<"  /--|  "<<endl;
    cout<<"~====+->"<<endl;
    cout<<"  "<<char(92)<<"--|  "<<endl;
    cout<<"   "<<char(92)<<"/   "<<endl;
    gotoxy(14,187);
    cout<<"INVERTIDO"<<endl;
    gotoxy(14,189);
    cout<<"    /"<<char(92)<<"   "<<endl;
    gotoxy(14,190);
    cout<<"   |--"<<char(92)<<"  "<<endl;
    gotoxy(14,191);
    cout<<"<--+====~"<<endl;
    gotoxy(14,192);
    cout<<"   |--/  "<<endl;
    gotoxy(14,193);
    cout<<"    "<<char(92)<<"/   "<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"               ~SHIELD~"<<endl;
    cout<<endl;
    cout<<"DISENO 1"<<endl,
    cout<<endl;
    cout<<" _.-^-._ "<<endl;
    cout<<"|   :   |"<<endl;
    cout<<"|  .:.  |"<<endl;
    cout<<"|.:::::.|"<<endl;
    cout<<"| ::::: |"<<endl;
    cout<<"|  ':'  |"<<endl;
    cout<<char(92)<<"   :   /"<<endl;
    cout<<" `-.:.-` "<<endl;
    gotoxy(14,198);
    cout<<"DISENO 2"<<endl;
    gotoxy(14,202);
    cout<<"  ___  "<<endl;
    gotoxy(14,203);
    cout<<" / : "<<char(92)<<" "<<endl;
    gotoxy(14,204);
    cout<<"|::o::|"<<endl;
    gotoxy(14,205);
    cout<<" "<<char(92)<<"_:_/ "<<endl;
    gotoxy(14,198);
    cout<<"DISENO 3"<<endl;
    gotoxy(28,200);
    cout<<"|"<<char(92)<<"__/"<<char(92)<<"__/|"<<endl;
    gotoxy(28,201);
    cout<<"|   ||   |"<<endl;
    gotoxy(28,202);
    cout<<"|__o()o__|"<<endl;
    gotoxy(28,203);
    cout<<"|_((<>))_|"<<endl;
    gotoxy(28,204);
    cout<<char(92)<<"  o"<<char(92)<<"/o  /"<<endl;
    gotoxy(28,205);
    cout<<" "<<char(92)<<"  ||  /"<<endl;
    gotoxy(28,206);
    cout<<"  "<<char(92)<<" || /"<<endl;
    gotoxy(28,207);
    cout<<"   '--'"<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    return 0;
}
/*
---------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////

                    DISEÑOS EN FORMATO CODIGO SIN GOTOXY

/////////////////////////////////////////////////////////////////////////////////
--------------------------------------------------------------------------------

============== H E R O E S ==============

-----------------------------------------
               ~CRUSADER~
ESPADA 1

cout<<"  /|"<<char(92)<<" "<<endl;
cout<<" | | | "<<endl;
cout<<" | | | "<<endl;
cout<<" | | | "<<endl;
cout<<"[/////]"<<endl;
cout<<"  |_|  "<<endl;
cout<<" (~~~) "<<endl;

ESPADA 2

cout<<"   /|"<<char(92)<<"   "<<endl;
cout<<"  | | |  "<<endl;
cout<<"  | | |  "<<endl;
cout<<"  | | |  "<<endl;
cout<<"<[:::::]>"<<endl;
cout<<"   |_|   "<<endl;
cout<<"   (~)   "<<endl;
cout<<endl;

-----------------------------------------
               ~HIGHWAYMAN~

PISTOLA 1

cout<<"  __,____ "<<endl;
cout<<" /__.==--"<<char(34)<<endl;
cout<<"/#(-'     "<<endl;
cout<<"`-'		 "<<endl;

PISTOLA 2

cout<<"   _,________"<<endl;
cout<<"	_T _==____()"<<endl;
cout<<" /##(_)-'     "<<endl;
cout<<"/##/          "<<endl;
cout<<char(34)<<char(34)<<char(34)<<"          "<<endl;

-----------------------------------------
               ~VESTAL~
LIBRO

cout<<"    _______ "<<endl;
cout<<"   /      /,"<<endl;
cout<<"  /      // "<<endl;
cout<<" /______//  "<<endl;
cout<<"(______(/   "<<endl;

MAZO

cout<<"  ___  "<<endl;
cout<<"<|"<<char(34)<<"^"<<char(34)<<"|>"<<endl;
cout<<"<|^"<<char(34)<<"^|>"<<endl;
cout<<"<|"<<char(34)<<"^"<<char(34)<<"|>"<<endl;
cout<<"  "<<char(92)<<" /"<<endl;
cout<<"  | |"<<endl;
cout<<"  |_|"<<endl;

-----------------------------------------
               ~HELLION~
DISEÑO 1-A

cout<<",^_,-,"<<endl;
cout<<"|_   |"<<endl;
cout<<"||`--'"<<endl;
cout<<"||    "<<endl;
cout<<"||    "<<endl;
cout<<"||    "<<endl;
cout<<"~~    "<<endl;

DISEÑO 1-B

cout<<" _,-,"<<endl;
cout<<"T_  |"<<endl;
cout<<"||`-'"<<endl;
cout<<"||   "<<endl;
cout<<"||   "<<endl;
cout<<"||   "<<endl;
cout<<"~~   "<<endl;

DISEÑO 2-A

cout<<"[]_/"<<char(92)<<" "<<endl;
cout<<"||_ [|"<<endl;
cout<<"|| "<<char(92)<<"/ "<<endl;
cout<<"||    "<<endl;
cout<<"||    "<<endl;
cout<<"||    "<<endl;
cout<<"||    "<<endl;
cout<<"||    "<<endl;

DISEÑO 2-B

cout<<",^,_/"<<char(92)<<" "<<endl;
cout<<"||__ [|"<<endl;
cout<<"||  "<<char(92)<<"/ "<<endl;
cout<<"||     "<<endl;
cout<<"||     "<<endl;
cout<<"||     "<<endl;
cout<<"||     "<<endl;
cout<<"||     "<<endl;

DISEÑO 3-A

cout<<"/"<<char(92)<<"  .  "<<endl;
cout<<"||-'"<<char(92)<<char(92)<<" "<<endl;
cout<<"||=- |)"<<endl;
cout<<"||-.// "<<endl;
cout<<"||  '  "<<endl;
cout<<"||     "<<endl;
cout<<"||     "<<endl;
cout<<"||     "<<endl;

-----------------------------------------
             ~PLAGUE DOCTOR~

DISEÑO 1-A

cout<<"   _.~~	"<<endl;
cout<<"  (__)  "<<endl;
cout<<"  <  >  "<<endl;
cout<<"   )(   "<<endl;
cout<<"  /~~\  "<<endl;
cout<<" /~~~~\ "<<endl;
cout<<"(______)"<<endl;

DISEÑO 1-B

cout<<"   _.~~  "<<endl;
cout<<"  (__)   "<<endl;
cout<<"   ||  	"<<endl;
cout<<"  /~~\ 	"<<endl;
cout<<" /~~~~\ "<<endl;
cout<<"(______)"<<endl;

DISEÑO 2-A

cout<<"   .~~"<<endl;
cout<<" |~|  "<<endl;
cout<<" | |  "<<endl;
cout<<".' `. "<<endl;
cout<<"`._.' "<<endl;

-----------------------------------------
             ~BOUNTY HUNTER~

DISEÑO 1

cout<<"   ___	"<<endl;
cout<<" __) `"<<char(92)<<"	"<<endl;
cout<<"< __=- |"<<endl;
cout<<" "<<char(92)<<char(92)<<" `)/	"<<endl;
cout<<"  "<<char(92)<<char(92)<<" (	"<<endl;
cout<<"   "<<char(92)<<char(92)<<"	"<<endl;
cout<<"    "<<char(92)<<char(92)<<"	"<<endl;
cout<<"    <_>"<<endl;

DISEÑO 2

cout<<"     __  "<<endl;
cout<<"  /"<<char(92)<<" ) "<<char(92)<<" "<<endl;
cout<<"<=()=>  )"<<endl;
cout<<"  || )_/ "<<endl;
cout<<"  ||     "<<endl;
cout<<"  ||     "<<endl;
cout<<"  ||     "<<endl;
cout<<"  ||     "<<endl;

-----------------------------------------
             ~GRAVE ROBBER~

DISEÑO 1

cout<<" /|"<<char(92)<<"   o  "<<endl;
cout<<" |||   |  "<<endl;
cout<<" ||| <===>"<<endl;
cout<<"<===> ||| "<<endl;
cout<<"  |   ||| "<<endl;
cout<<"  o   "<<char(92)<<"|/ "<<endl;

DISEÑO 2

cout<<" O   | "<<endl;
cout<<" |   | "<<endl;
cout<<"/="<<char(92)<<" "<<char(92)<<"|/"<<endl;
cout<<" |   | "<<endl;
cout<<" |   O "<<endl;

-----------------------------------------
                ~JESTER~

DISEÑO 1

cout<<" *****"<<endl;
cout<<"**   **"<<endl;
cout<<"*   ***"<<endl;
cout<<"   *** "<<endl;
cout<<"   **  "<<endl;
cout<<"   ||  "<<endl;
cout<<"  (__) "<<endl;

DISEÑO 2

cout<<"  ___  "<<endl;
cout<<" / _ "<<char(92)<<" "<<endl;
cout<<"/ / "<<char(92)<<" "<<char(92)<<endl;
cout<<char(92)<<"_> / /"<<endl;
cout<<"   / / "<<endl;
cout<<"   ||  "<<endl;
cout<<"   ||  "<<endl;
cout<<"  [--] "<<endl;

DISEÑO 3

cout<<" ___   "<<endl;
cout<<"/ __ "<<char(92)<<" "<<endl;
cout<<char(92)<<"/  "<<char(92)<<" "<<char(92)<<endl;
cout<<"    / /"<<endl;
cout<<"   / / "<<endl;
cout<<"  [==] "<<endl;
cout<<"   ||  "<<endl;
cout<<"  (##) "<<endl;

-----------------------------------------

============= E N E M I E S =============

-----------------------------------------
                ~SPIDER~
DISEÑO 1

cout<<"  / _ "<<char(92)<<"	"<<endl;
cout<<char(92)<<"_"<<char(92)<<"(_)/_/"<<endl;
cout<<" _//"<<char(34)<<char(92)<<char(92)<<"_ "<<endl;
cout<<"  /   "<<char(92)<<"	"<<endl;

DISEÑO 2

cout<<"  / _ "<<char(92)<<"	"<<endl;
cout<<char(92)<<"_"<<char(92)<<"(_)/_/"<<endl;
cout<<" _//O"<<char(92)<<char(92)<<"_ "<<endl;
cout<<"  /   "<<char(92)<<"	"<<endl;

DISEÑO 3

cout<<"  //  "<<char(92)<<char(92)<<"  "<<endl;
cout<<" _"<<char(92)<<char(92)<<"()//_"<<endl;
cout<<"/ //  "<<char(92)<<char(92)<<" "<<char(92)<<endl;
cout<<" | "<<char(92)<<"__/ |"<<endl;

-----------------------------------------
                ~SKELETON~

DISEÑO 1

cout<<" _____ "<<endl;
cout<<"/     "<<char(92)<<endl;
cout<<"|() ()|"<<endl;
cout<<char(92)<<"  ^  /"<<endl;
cout<<" ||||| "<<endl;
cout<<" ''''' "<<endl;

DISEÑO 2

cout<<" .----. "<<endl;
cout<<"/      "<<char(92)<<endl;
cout<<"|()  ()|"<<endl;
cout<<char(92)<<"  /"<<char(92)<<"  /"<<endl;
cout<<" | "<<char(34)<<char(34)<<" | "<<endl;
cout<<" |####| "<<endl;
cout<<" |----| "<<endl;

-----------------------------------------
           ~ENEMIGO CON PISTOLA~

DISEÑO NORMAL

cout<<"  ,________."<<endl;
cout<<" >`(==(----'"<<endl;
cout<<"(__/~~`     "<<endl;

DISEÑO INVERTIDO
cout<<".________,"<<endl;
cout<<"'----)==)`<"<<endl;
cout<<"     `~~"<<char(92)<<"__)"<<endl;

-----------------------------------------
                ~SNAKE~

DISEÑO 1

cout<<"   _____   "<<endl;
cout<<"  /.   ."<<char(92)<<"  "<<endl;
cout<<" /--)W(--"<<char(92)<<" "<<endl;
cout<<"(---| |---)"<<endl;
cout<<" "<<char(92)<<"--| |--/ "<<endl;
cout<<"  "<<char(92)<<"_| |_/  "<<endl;
cout<<" ___| |___ "<<endl;
cout<<"('-_|_|_-')"<<endl;
cout<<" '._____.' "<<endl;

DISEÑO 2

cout<<"  _    _  "<<endl;
cout<<",(|)--(|)."<<endl;
cout<<char(92)<<"   ..   /"<<endl;
cout<<" "<<char(92)<<"______/ "<<endl;
cout<<"   V  V   "<<endl;
cout<<"  `.^^`.  "<<endl;
cout<<"   "<<char(92)<<"^^^"<<char(92)<<"  "<<endl;
cout<<"   |^^^|  "<<endl;
cout<<"   |^^^|  "<<endl;

DISEÑO 3

cout<<"   ___  "<<endl;
cout<<"  /   "<<char(92)<<" "<<endl;
cout<<" |     "<<char(92)<<" "<<endl;
cout<<" |  /"<<char(92)<<"  |"<<endl;
cout<<" | | |  |"<<endl;
cout<<"(o o)|  |"<<endl;
cout<<" "<<char(92)<<"_/ |  |"<<endl;
cout<<"  |  |  |"<<endl;
cout<<"  ^      "<<endl;

-----------------------------------------
               ~SYCOPHANT~

DISEÑO 1

cout<<"  '__'	"<<endl;
cout<<" "<<char(92)<<"O__O/	"<<endl;
cout<<"==x||x=="<<endl;
cout<<" /^||^"<<char(92)<<"	"<<endl;
cout<<"/^^||^^"<<char(92)<<endl;
cout<<char(92)<<"^^||^^/"<<endl;
cout<<" '-''-'"<<endl;

DISEÑO 2

cout<<"    _  _      "<<endl;
cout<<"   | )/ )     "<<endl;
cout<<char(92)<<char(92)<<" |//,' __   "<<endl;
cout<<"("<<char(34)<<")(_)-"<<char(34)<<"()))=-"<<endl;
cout<<"   ("<<char(92)<<char(92)<<"        "<<endl;

-----------------------------------------
               ~SHRIEKER~

DISEÑO 1

cout<<"  _.-.   "<<endl;
cout<<"  `) | 	"<<endl;
cout<<" //   "<<char(92)<<char(92)<<" "<<endl;
cout<<"/ :   ; "<<char(92)<<endl;
cout<<"  "<<char(92)<<"  /   "<<endl;
cout<<"  /||"<<char(92)<<"   "<<endl;
cout<<" / ^^ "<<char(92)<<"  "<<endl;
cout<<" `'``'`  "<<endl;

DISEÑO 2

cout<<" ,_  "<<endl;
cout<<">' ) "<<endl;
cout<<"( ( "<<char(92)<<endl;
cout<<" ''|"<<char(92)<<endl;

-----------------------------------------
             ~BONE ARBALEST~

DISEÑO NORMAL

cout<<"   /"<<char(92)<<"   "<<endl;
cout<<"  /--|  "<<endl;
cout<<"~====+->"<<endl;
cout<<"  "<<char(92)<<"--|  "<<endl;
cout<<"   "<<char(92)<<"/   "<<endl;

DISEÑO INVERTIDO

cout<<"    /"<<char(92)<<"   "<<endl;
cout<<"   |--"<<char(92)<<"  "<<endl;
cout<<"<--+====~"<<endl;
cout<<"   |--/  "<<endl;
cout<<"    "<<char(92)<<"/   "<<endl;

-----------------------------------------
               ~SHIELD~

DISEÑO 1

cout<<" _.-^-._ "<<endl;
cout<<"|   :   |"<<endl;
cout<<"|  .:.  |"<<endl;
cout<<"|.:::::.|"<<endl;
cout<<"| ::::: |"<<endl;
cout<<"|  ':'  |"<<endl;
cout<<char(92)<<"   :   /"<<endl;
cout<<" `-.:.-` "<<endl;

DISEÑO 2

cout<<"  ___  "<<endl;
cout<<" / : "<<char(92)<<" "<<endl;
cout<<"|::o::|"<<endl;
cout<<" "<<char(92)<<"_:_/ "<<endl;

DISEÑO 3

cout<<"|"<<char(92)<<"__/"<<char(92)<<"__/|"<<endl;
cout<<"|   ||   |"<<endl;
cout<<"|__o()o__|"<<endl;
cout<<"|_((<>))_|"<<endl;
cout<<char(92)<<"  o"<<char(92)<<"/o  /"<<endl;
cout<<" "<<char(92)<<"  ||  /"<<endl;
cout<<"  "<<char(92)<<" || /"<<endl;
cout<<"   '--'"<<endl;

-----------------------------------------
*/
