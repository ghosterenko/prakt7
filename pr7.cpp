#include <iostream>

struct Node {
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
        if (head == nullptr)
            head = newN;

        head->next = newN;
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


    void draw() {
        srand(time(NULL));
        Node* node = snake.node();
        snake.add('0');
        snake.add('0');
        snake.add('0');
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
            field[height / 2][width / 2] = node->value;
            if (node->next != nullptr)
                node = node->next;
        }
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
    Snake snake = Snake();
    Field f = Field();
    f.snake = snake;
    f.draw();

}
