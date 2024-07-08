#include <iostream>
#include <cstring>
using namespace std;

static int p = 0;

class Room {
    char roomn[5];
    char host[10];
    char start[5];
    char send[5];
    char from[10];
    char to[10];
    char chair[8][4][10];

public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
};

Room room[10];

void vline(char ch) {
    for (int i = 80; i > 0; i--)
        cout << ch;
}

void Room::install() {
    cout << "Enter Room no: ";
    cin >> room[p].roomn;
    cout << "\nEnter Host's name: ";
    cin >> room[p].host;
    cout << "\nStart time: ";
    cin >> room[p].start;
    cout << "\nSession Ends at: ";
    cin >> room[p].send;
    cout << "\nFrom: \t\t\t";
    cin >> room[p].from;
    cout << "\nTo: \t\t\t";
    cin >> room[p].to;
    room[p].empty();
    p++;
}

void Room::allotment() {
    int chair;
    char number[5];
top:
    cout << "Room no: ";
    cin >> number;
    int n;
    for (n = 0; n <= p; n++) {
        if (strcmp(room[n].roomn, number) == 0)
            break;
    }
    while (n <= p) {
        cout << "\nChair Number: ";
        cin >> chair;
        if (chair > 32) {
            cout << "\nThere are only 32 Chairs available in this Room.";
        } else {
            if (strcmp(room[n].chair[chair / 4][(chair % 4) - 1], "Empty") == 0) {
                cout << "Enter traveler's name: ";
                cin >> room[n].chair[chair / 4][(chair % 4) - 1];
                break;
            } else {
                cout << "The Chair no. is already reserved.\n";
            }
        }
    }
    if (n > p) {
        cout << "Enter correct Room no.\n";
        goto top;
    }
}

void Room::empty() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(room[p].chair[i][j], "Empty");
        }
    }
}

void Room::show() {
    int n;
    char number[5];
    cout << "Enter Room no: ";
    cin >> number;
    for (n = 0; n <= p; n++) {
        if (strcmp(room[n].roomn, number) == 0)
            break;
    }
    while (n <= p) {
        vline('*');
        cout << "Room no: \t" << room[n].roomn << "\nHost: \t" << room[n].host
             << "\t\tStart time: \t" << room[n].start << "\t End time:" << room[n].send
             << "\nFrom: \t\t" << room[n].from << "\t\tTo: \t\t" << room[n].to << "\n";
        vline('*');
        room[0].position(n);
        int a = 1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 4; j++) {
                a++;
                if (strcmp(room[n].chair[i][j], "Empty") != 0)
                    cout << "\nThe Chair no " << (a - 1) << " is reserved for " << room[n].chair[i][j] << ".";
            }
        }
        break;
    }
    if (n > p)
        cout << "Enter correct Room no: ";
}

void Room::position(int l) {
    int s = 0;
    p = 0;
    for (int i = 0; i < 8; i++) {
        cout << "\n";
        for (int j = 0; j < 4; j++) {
            s++;
            if (strcmp(room[l].chair[i][j], "Empty") == 0) {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
                p++;
            } else {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
            }
        }
    }
    cout << "\n\nThere are " << p << " Chairs empty in Room No: " << room[l].roomn;
}

void Room::avail() {
    for (int n = 0; n < p; n++) {
        vline('*');
        cout << "Room no: \t" << room[n].roomn << "\nHost: \t" << room[n].host
             << "\t\tStart time: \t" << room[n].start << "\tEnd  Time: \t"
             << room[n].send << "\nFrom: \t\t" << room[n].from << "\t\tTo: \t\t\t"
             << room[n].to << "\n";
        vline('*');
        vline('_');
    }
}

int main() {
    int w;
    while (true) {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t1.Install\n\t\t\t"
             << "2.Reservation\n\t\t\t"
             << "3.Show\n\t\t\t"
             << "4.Rooms Available. \n\t\t\t"
             << "5.Exit";
        cout << "\n\t\t\tEnter your choice:-> ";
        cin >> w;
        switch (w) {
            case 1:
                room[p].install();
                break;
            case 2:
                room[p].allotment();
                break;
            case 3:
                room[0].show();
                break;
            case 4:
                room[0].avail();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
