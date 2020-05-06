#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

//global variable
int row, column, mine_num, discovered;
bool will_runing = true;

enum ForendState {
    OPENED, UNOPEND
};
enum BackendState {
    MINE, FLAG, QUESMARK, NUMBER
};


class Zone {
    int xThisZone, yThisZone, numberToShow;

    ForendState forendState = UNOPEND;
    BackendState backendState = NUMBER;
public:


    ForendState getForendState() const {
        return forendState;
    }

    void setForendState(ForendState forendState) {
        Zone::forendState = forendState;
    }

    BackendState getBackendState() const {
        return backendState;
    }

    void setBackendState(BackendState backendState) {
        Zone::backendState = backendState;
    }

    void setNumber() {
        numberToShow = 0;
    }

    int getNumber() const {
        return numberToShow;
    }

    void plusNumber() {
        numberToShow++;
    }

    void setX(int x) {
        this->xThisZone = x;
    }

    void setY(int y) {
        this->yThisZone = y;
    }

    int getX() {
        return xThisZone;
    }

    int getY() {
        return yThisZone;
    }
};


class TableZone {
public:
    Zone **pZone;


    Zone **init() {
        pZone = new Zone *[row];
        pZone = new Zone *[row];
        for (int l = 0; l < row; ++l) {
            pZone[l] = new Zone[column];
            for (int i = 0; i < column; ++i) {
                pZone[l][i].setX(l);
                pZone[l][i].setY(i);
                pZone[l][i].setNumber();
            }
        }
        return pZone;
    }


    void zone_number(Zone zone) {
        int x = zone.getX();
        int y = zone.getY();
        int i_start, i_finish, j_start, j_finish;
        if (x == 0)
            i_start = 0;
        else
            i_start = x - 1;
        if (y == 0)
            j_start = 0;
        else
            j_start = y - 1;
        if (x == row - 1)
            i_finish = x;
        else
            i_finish = x + 1;
        if (y == column - 1)
            j_finish = y;
        else
            j_finish = y + 1;

        for (int i = i_start; i <= i_finish; i++) {
            for (int j = j_start; j <= j_finish; j++) {
                pZone[i][j].plusNumber();
            }
        }

    }

    void zone_init(int firstx, int firsty) {
        //generate bombs
        srand(time(0));
        int *equal_arr = new int[mine_num];

        for (int k = 0; k < mine_num; ++k) {
            int x;
            int y;
            while (true) {
                bool is_equal = false;
                x = rand() % row;
                y = rand() % column;
                for (int i = 0; i < mine_num; ++i) {
                    if (x * 10 + y == equal_arr[i] || (x == firstx && y == firsty)) {
                        is_equal = true;
                        break;
                    }
                }
                if (!is_equal)
                    break;
            }
            equal_arr[k] = x * 10 + y;
            pZone[x][y].setBackendState(MINE);
            zone_number(pZone[x][y]);

        }
        delete[] equal_arr;

    }


};


class TableConsule {
public:
    char **table;
    Zone **pZone;

    TableConsule(Zone **pZone) {
        TableConsule::pZone = pZone;
    }

    void init() {
        table = new char *[row];
        for (int i = 0; i < row; i++) {
            table[i] = new char[column];
            for (int j = 0; j < column; j++) {
                table[i][j] = '*';
            }
        }
    }

    void show() {
        cout << "   ";
        for (int k = 0; k < column; k++)
            cout << k + 1 << "  ";
        cout << endl;
        for (int i = 0; i < row; i++) {
            cout << i + 1 << "  ";
            for (int j = 0; j < column; j++) {
                cout << table[i][j] << "  ";
            }
            cout << endl;
        }
    }

    bool isFinished() {
        bool is_finished = true;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (table[i][j] == '*' || table[i][j] == '?') {
                    is_finished = false;
                    break;
                }
            }
        }
        if (is_finished)
            return true;
        return false;
    }

    void change_table() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (pZone[i][j].getBackendState() == FLAG && pZone[i][j].getForendState() == UNOPEND) {
                    table[i][j] = '>';
                } else if (pZone[i][j].getBackendState() == MINE && pZone[i][j].getForendState() == OPENED)
                    table[i][j] = 'B';
                else if (pZone[i][j].getBackendState() == QUESMARK && pZone[i][j].getForendState() == UNOPEND)
                    table[i][j] = '?';
                else if (pZone[i][j].getBackendState() == NUMBER && pZone[i][j].getForendState() == OPENED) {
                    table[i][j] = pZone[i][j].getNumber() + 48;
                } else {
                    table[i][j] = '*';
                }
            }
        }
    }


};


class Player {
    char name[30];
public:
    Zone **pZone;

    Player(Zone **pZone) {
        Player::pZone = pZone;
    }

    const char *getName() const {
        return name;
    }


    void spread(int zoneX, int zoneY) {
        if (zoneX >= 0 && zoneX < row && zoneY >= 0 && zoneY < column &&
            pZone[zoneX][zoneY].getBackendState() == NUMBER &&
            pZone[zoneX][zoneY].getForendState() == UNOPEND) {
            pZone[zoneX][zoneY].setForendState(OPENED);
            if (pZone[zoneX][zoneY].getNumber() == 0) {
                spread(zoneX - 1, zoneY - 1);
                spread(zoneX - 1, zoneY);
                spread(zoneX - 1, zoneY + 1);
                spread(zoneX, zoneY - 1);
                spread(zoneX, zoneY + 1);
                spread(zoneX + 1, zoneY - 1);
                spread(zoneX + 1, zoneY);
                spread(zoneX + 1, zoneY + 1);
            }
        }
    }

    bool open_zone(int line, int col) {
        if (pZone[line][col].getBackendState() == FLAG)
            return false;
        if (pZone[line][col].getBackendState() == QUESMARK) {
            pZone[line][col].setBackendState(NUMBER);
        } else if (pZone[line][col].getBackendState() == NUMBER) {
            if (pZone[line][col].getNumber() == 0)
                spread(line, col);
            pZone[line][col].setForendState(OPENED);
        } else if (pZone[line][col].getBackendState() == MINE) {
            cout << "GAME OVER!";
            will_runing = false;
        }
        return true;
    }


    void put_flag(int l, int c) {
        if (pZone[l][c].getBackendState() == FLAG) {
            discovered--;
            pZone[l][c].setBackendState(NUMBER);
        } else if(pZone[l][c].getForendState() !=OPENED) {
            pZone[l][c].setBackendState(FLAG);
            discovered++;
        }
    }

    void put_quesMark(int line, int col) {
        if (pZone[line][col].getForendState() == UNOPEND && pZone[line][col].getBackendState()!=FLAG &&pZone[line][col].getBackendState()!=QUESMARK)
            pZone[line][col].setBackendState(QUESMARK);
        else if(pZone[line][col].getBackendState()==QUESMARK){
            pZone[line][col].setBackendState(NUMBER);
        }
    }


};


int main() {


    cout << "enter column,row and amount of mine!" << endl;
    cin >> column >> row >> mine_num;
    if (mine_num >= row * column) {
        cout << "mine amount must fewer than square ,please enter again!" << endl;
        cin >> mine_num;
    }

    auto start = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();

    TableZone tableZone = {};//jadvali az Zone
    Zone **pZone = tableZone.init();


    TableConsule tableConsule(pZone);//jadval neshan dade shode dar consule
    tableConsule.init();
    tableConsule.change_table();//emal akharin taeghirat
    tableConsule.show();

    Player player(pZone);

    bool is_first_input = true;
    while (will_runing) {
        cout
                << "1)print 2)open 3)put/pickup flag 4)put/pickup ? 5)mine amount 6)discovered mine amount 7)time 8)10top player"
                << endl;
        int input;
        cin >> input;

        switch (input) {
            case 1:
                tableConsule.show();
                break;
            case 2:
                //open
                while (true) {
                    cout << "line:";
                    int line;
                    cin >> line;
                    cout << "column:";
                    int col;
                    cin >> col;
                    if (is_first_input) {
                        tableZone.zone_init(line - 1, col - 1);//put mine in zone
                        is_first_input = false;
                    }
                    if (player.open_zone(line - 1, col - 1)) {
                        tableConsule.change_table();//emal akharin taeghirat
                        break;
                    } else
                        cout << "zone had flag!enter again";
                }
                break;
            case 3:
                //put flag
                if (discovered > mine_num)
                    cout << "discovered mine >  mine amount" << endl;
                cout << "line: ";
                int line;
                cin >> line;
                cout << "column: ";
                int col;
                cin >> col;
                player.put_flag(line - 1, col - 1);
                tableConsule.change_table();//emal akharin taeghirat
                break;
            case 4:
                cout << "line: ";
                int l;
                cin >> l;
                cout << "column: ";
                int c;
                cin >> c;
                player.put_quesMark(l - 1, c - 1);
                tableConsule.change_table();//emal akharin taeghirat
                break;
            case 5:
                cout << "mine amount: " << mine_num << endl;
                break;
            case 6:
                cout << "discovered mine amount: " << mine_num - discovered << endl;
                break;
            case 7:
                end = chrono::steady_clock::now();
                cout << "Elapsed time: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " sec"
                     << endl;
                break;
            case 8:
                fstream topPlayers_int("topPlayers_int.txt");
                int time_int;

                fstream topPlayers_str;
                topPlayers_str.open("topPlayers_str.txt");
                string time_str;

                for (int i = 0; i < 10; ++i) {
                    topPlayers_int >> time_int;
                    topPlayers_str >> time_str;
                    cout << time_str << ":" << time_int << "sec    ";
                }
                cout << endl;
                topPlayers_int.close();
                topPlayers_str.close();

                break;
        }
        if (tableConsule.isFinished()) {
            will_runing = false;
            cout << "congratulations,you win! :)" << endl;
            end = chrono::steady_clock::now();
            int my_time=chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "Elapsed time: " << my_time << " sec" << endl;
            tableConsule.change_table();//emal akharin taeghirat
            tableConsule.show();
            int temp = 0;
            ifstream mine("mine.txt");
            mine >> temp;
            mine.close();
            ofstream mine1("mine.txt");
            if (temp > my_time) {
                mine1 << my_time << "\n";

                //10 top best record
                ifstream top("topPlayers_int.txt");
                int arr[10];
                for (int j = 0; j < 10; ++j) {
                    top >> arr[j];
                }
                top.close();
                int index=-1;
                for (int i = 0; i < 10; ++i) {
                    if(arr[i]>my_time){
                        index=i;
                        break;
                    }
                }
                if(index!=-1){
                    ifstream top_str("topPlayers_str.txt");
                    char arr_str[10][20];
                    for (int j = 0; j < 10; ++j) {
                        top_str >> arr_str[j];

                    }
                    top_str.close();


                    ofstream top("topPlayers_int.txt");
                    ofstream top_s("topPlayers_str.txt");
                    char name[20];
                    cout<<"enter your name!"<<endl;
                    cin>>name;
                    for (int i = 0; i < 9; ++i) {
                        if(i==index){
                            top<<my_time<<"\n";
                            top_s<<name<<"\n";
                            index=-1;
                            i--;
                        } else{
                            top<<arr[i]<<"\n";
                            top_s<<arr_str[i]<<"\n";
                        }
                    }
                    top.close();
                    top_s.close();
                }

            } else {
                mine1 << temp;
            }
            mine1.close();
        }

    }
    return 0;
}