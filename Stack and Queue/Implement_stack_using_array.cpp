class Stack
{
    int *arr;
    int size;
    int topelem;

public:
    Stack(int capacity)
    {
        // Write your code here.
        this->arr = new int[capacity];
        this->size = capacity;
        this->topelem = -1;
    }

    void push(int num)
    {
        // Write your code here.
        if (this->topelem < this->size)
        {
            this->topelem++;
            this->arr[topelem] = num;
        }
    }

    int pop()
    {
        // Write your code here.
        if (this->topelem == -1)
        {
            return -1;
        }
        else
        {
            int val = this->arr[this->topelem--];
            return val;
        }
    }

    int top()
    {
        // Write your code here.
        if (this->topelem == -1)
        {
            return -1;
        }
        else
        {
            return this->arr[this->topelem];
        }
    }

    int isEmpty()
    {
        // Write your code here.
        if (this->topelem == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isFull()
    {
        // Write your code here.
        if (this->topelem == this->size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};