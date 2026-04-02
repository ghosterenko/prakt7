#include <iostream>

struct Node {
public:
    char value;
    Node* next;

    Node(char Value) : value(Value), next(nullptr) {}
};
class Snake {
public:
    Node* head = nullptr;
    int size = 0;
    
    void add(char value) {
        Node* newN = new Node(value);
        if (head == nullptr) {
            head = newN;
        }
        else {
            head->next = newN;
        }
        size++;
    }

    void display() {
        Node* node = head;
        while (node != nullptr)
        {
            node->value;
            node = node->next;
        }
    }
    Node* node() {
        if (head != nullptr)
            return head;
    }

};

class Field {
public:
    Snake snake;
    int width = 20;
    int height = 10;
    char field[255][255];


    void StartGame() {
        srand(time(NULL));
        Node* node = snake.node();
        snake.add('o');
        snake.add('o');
        snake.add('o');
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                field[i][j] = '-';
            }
            field[i][0] = '\n';
        }
        for (int i = 0; i < snake.size; i++)
        {
            field[(height / 2) - i][width / 2] = node->value;
            node = node->next;
        }
    }
    void display() {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                std::cout << field[i][j];
            }
        }
    }
    
};

int main()
{
    setlocale(LC_ALL, "ru");
    Snake snake = Snake();
    Field f = Field();
    f.snake = snake;
    f.StartGame();
    f.display();

    return 0;
}
