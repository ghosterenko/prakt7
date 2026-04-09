#include <iostream>
#include <conio.h>
#include <windows.h>

struct Node {
    int x, y;
    Node* next;
};

int main() {

    setlocale(LC_ALL, "ru");

    const int W = 20, H = 20;
    int fx, fy, d = 3, res = 0;
    bool game = false;

    Node* head = new Node{ 10, 10, nullptr };
    head->next = new Node{ 9, 10, nullptr };
    head->next->next = new Node{ 8, 10, nullptr };
    int length = 3;

    srand(time(NULL));
    fx = rand() % W;
    fy = rand() % H;

    while (!game) {
        system("cls");
        for (int i = 0; i < W + 2; i++)
            std::cout << "#";
        std::cout << std::endl;

        for (int y = 0; y < H; y++) {
            std::cout << "#";
            for (int x = 0; x < W; x++) {
                bool isSnake = false;
                Node* temp = head;
                while (temp) {
                    if (temp->x == x && temp->y == y) {
                        std::cout << "-";
                        isSnake = true;
                        break;
                    }
                    temp = temp->next;
                }
                if (!isSnake && fx == x && fy == y)
                    std::cout << "e";
                else if (!isSnake)
                    std::cout << " ";
            }
            std::cout << "#" << std::endl;
        }

        for (int i = 0; i < W + 2; i++)
            std::cout << "#";

        if (_kbhit()) {
            char key = _getch();
            switch (key) {
            case 'w':
                if (d != 1) d = 0; break;
            case 's':
                if (d != 0) d = 1; break;
            case 'a':
                if (d != 3) d = 2; break;
            case 'd':
                if (d != 2) d = 3; break;
            }

            int dx = 0, dy = 0;
            if (d == 0)
                dy = -1;
            if (d == 1)
                dy = 1;
            if (d == 2)
                dx = -1;
            if (d == 3)
                dx = 1;

            Node* newHead = new Node{ head->x + dx, head->y + dy, head };
            head = newHead;

            Node* temp = head;
            for (int i = 0; i < length - 1; i++)
                temp = temp->next;
            delete temp->next;
            temp->next = nullptr;

            if (head->x == fx && head->y == fy) {
                length++;
                res++;
                fx = rand() % W;
                fy = rand() % H;
                temp->next = new Node{ temp->x, temp->y, nullptr };
            }

            if (head->x < 0 || head->x >= W || head->y < 0 || head->y >= H) game = true;

            temp = head->next;
            while (temp) {
                if (temp->x == head->x && temp->y == head->y) game = true;
                temp = temp->next;
            }
        }

        Sleep(50);
    }

    system("cls");
    std::cout << "Игра окончена! результат: " << res << std::endl;

    return 0;
}
