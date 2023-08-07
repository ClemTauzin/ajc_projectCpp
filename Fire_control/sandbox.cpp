#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int main(){
// string text = "######\n######\n*#####\n######\n######\n######";
ifstream stream("text.txt", std::ios::in);
string text2;

char tableau[6][6];
char tableau2[6][6];
int fireNb=0;

for (int y =0; y < 6; y++){
getline(stream, text2);

    int x = 0;
    for(char c : text2){
        tableau2[y][x]= c;

        if (c == '*'){
            fireNb++;
            // AOE of fire -> f
            for(int a = -2; a<=2; a++){
                if(0<=(y+a) && (y+a)<=5){
                    for(int b = -2; b<=2; b++){
                        if(0<=(x+b) && (x+b)<=5 && tableau[y+a][x+b]!= '*'){
                            tableau[y+a][x+b] = 'f';
                        }
                    }
                }
            }            
        }
        x++;
    }
}

int cuttingTree = 0;
int stayingTree;
for(int y=0; y<6; y++){
    for(int x=0; x<6; x++){
        if(tableau2[y][x]=='#'){stayingTree++;}
        if(tableau2[y][x]=='#' && tableau[y][x]=='f'){
            cuttingTree++;
        }
    }
}

if(fireNb==0){
    cout<<"RELAX"<<endl;
}else if(cuttingTree==stayingTree){
    cout<<"JUST RUN"<<endl;
}else{
    cout<<cuttingTree<<endl;
}

return 0;
}