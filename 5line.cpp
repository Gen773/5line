#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int Line = 15; //縦横のマスの定義
    vector<vector<char>> Field(Line, vector<char>(Line, '-')); //フィールドの宣言&初期化

    bool win = 0; //勝利フラグ
    bool Player = 1; //誰の番か
    int Player_o_point = 0, Player_x_point = 0; //同時に揃った場合のポイント

    while(!win){
        if(Player){
            cout << "Next player is " << Player << " (o) " << endl;
        }
        else{
            cout << "Next player is " << Player << " (x) " << endl;
        }
        cout << "1: Put a token" << endl; //自分の駒を置く
        cout << "2: Turn Clocklwise" << endl; //時計回りに回転
        cout << "3: Turn Counterclocklwise" << endl; //反時計回りに回転

        //アクションの選択
        int Entry;
        cin >> Entry;


        if(Entry == 1){ //駒を置く場合
            cout << "Select a line" << endl;
            int line;
            cin >> line; //駒を置く列の決定

            if(Field[0][line - 1] != '-'){ //選択した列が全て埋まっているときの処理
                cout << "Select another line or way(occupied)" << endl;
                continue;
            }
            else if(line < 0 || Line < line){ //存在しない列を選択したときの処理
                cout << "Select another line or way(out of range)" << endl;
                continue;
            }

            //選択した列に駒を置く
            for(int i = Line - 1; 0 <= i; i--){
                if(Field[i][line - 1] == '-'){
                    if(Player){
                        Field[i][line - 1] = 'o';
                    }
                    else{
                        Field[i][line - 1] = 'x';
                    }
                    break;
                }
            }

            //フィールドの表示
            for(int i = 0; i < Line; i++){
                for(int j = 0; j < Line; j++){
                    cout << Field[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if(Entry == 2){ //時計回りに回転
            vector<vector<char>> Tmp_Field(Line, vector<char>(Line, '-')); //回転後のフィールドを宣言&初期化

            for(int i = Line - 1; 0 <= i; i--){
                for(int j = Line - 1; 0 <= j ; j--){
                    if(Field[i][j] != '-'){ //もし、現在のフィールドで駒が置かれている場合
                        for(int ii = Line - 1; 0 <= ii; ii--){
                            if(Tmp_Field[ii][Line - i - 1] == '-'){ //現在のj列が大きい所にある駒を、移動先のフィールドでiiが大きいところから優先に置く
                                Tmp_Field[ii][Line - i - 1] = Field[i][j];
                                break;
                            }
                        }
                    }
                }
            }

            //Tmp_fieldからFieldに移す
            for(int i = 0; i < Line; i++){
                for(int j = 0; j < Line; j++){
                    Field[i][j] = Tmp_Field[i][j];
                }
            }
            //フィールドの表示
            for(int i = 0; i < Line; i++){
                for(int j = 0; j < Line; j++){
                    cout << Field[i][j] << " ";
                }
                cout << endl;
            }

        }
        else if(Entry == 3){
            vector<vector<char>> Tmp_Field(Line, vector<char>(Line, '-')); //回転後のフィールドを宣言&初期化

            for(int i = Line - 1; 0 <= i; i--){
                for(int j = 0; j < Line ; j++){
                    if(Field[i][j] != '-'){ //もし、現在のフィールドで駒が置かれている場合
                        for(int ii = Line - 1; 0 <= ii; ii--){
                            if(Tmp_Field[ii][i] == '-'){ //現在のj列が大きい所にある駒を、移動先のフィールドでiiが大きいところから優先に置く
                                Tmp_Field[ii][i] = Field[i][j];
                                break;
                            }
                        }
                    }
                }
            }

            //Tmp_fieldからFieldに移す
            for(int i = 0; i < Line; i++){
                for(int j = 0; j < Line; j++){
                    Field[i][j] = Tmp_Field[i][j];
                }
            }
            //フィールドの表示
            for(int i = 0; i < Line; i++){
                for(int j = 0; j < Line; j++){
                    cout << Field[i][j] << " ";
                }
                cout << endl;
            }
        }
        else{
            cout << "Select a number from 1 to 3" << endl;
            continue;
        }

        //5個繋がっているかの判定
        for(int i = 0; i < Line - 4; i++){ //縦の判定
            for(int j = 0; j < Line; j++){
                if(Field[i][j] == '-'){
                    continue;;
                }
                else if(Field[i][j] == Field[i + 1][j] && Field[i][j] == Field[i + 2][j] && Field[i][j] == Field[i + 3][j] && Field[i][j] == Field[i + 4][j]){
                    win = 1;
                    if(Field[i][j] == 'o'){
                        Player_o_point++;
                    }
                    else{
                        Player_x_point++;
                    }
                }
            }
        }
        for(int j = 0; j < Line - 4; j++){ //横の判定
            for(int i = 0; i < Line; i++){
                if(Field[i][j] == '-'){
                    continue;
                }
                else if(Field[i][j] == Field[i][j + 1] && Field[i][j] == Field[i][j + 2] && Field[i][j] == Field[i][j + 3] && Field[i][j] == Field[i][j + 4]){
                    win = 1;
                    if(Field[i][j] == 'o'){
                        Player_o_point++;
                    }
                    else{
                        Player_x_point++;
                    }
                }
            }
        }
        for(int i = 0; i < Line - 4; i++){ //斜めの判定(左上から右下方向)
            for(int j = 0; j < Line - 4; j++){
                if(Field[i][j] == '-'){
                    continue;;
                }
                else if(Field[i][j] == Field[i + 1][j + 1] && Field[i][j] == Field[i + 2][j + 2] && Field[i][j] == Field[i + 3][j + 3] && Field[i][j] == Field[i + 4][j + 4]){
                    win = 1;
                    if(Field[i][j] == 'o'){
                        Player_o_point++;
                    }
                    else{
                        Player_x_point++;
                    }
                }
            }
        }
        for(int i = 4; i < Line; i++){ //斜めの判定(左下から右上方向)
            for(int j = 0; j < Line - 4; j++){
                if(Field[i][j] == '-'){
                    continue;;
                }
                else if(Field[i][j] == Field[i - 1][j - 1] && Field[i][j] == Field[i - 2][j - 2] && Field[i][j] == Field[i - 3][j - 3] && Field[i][j] == Field[i - 4][j - 4]){
                    win = 1;
                    if(Field[i][j] == 'o'){
                        Player_o_point++;
                    }
                    else{
                        Player_x_point++;
                    }
                }
            }
        }

        if(win){
            if(Player_o_point < Player_x_point){
                cout << "Player 0 wins!!" << endl;
            }
            else if(Player_x_point < Player_o_point){
                cout << "Player 1 wins!!" << endl;
            }
            else{
                cout << "Draw!!, You guys are best friends!!" << endl;
            }
        }


        //相手の番にする
        if(Player){
            Player = 0;
        }
        else{
            Player = 1;
        }
    }
}