#include <iostream>
#include <new>
#include <utility>


using namespace std;


template <typename T> class Queue;

template <typename T> bool operator==(const Queue<T> & obj, const Queue<T> & obj2); //Сравнение объектов очереди.
template <typename T> bool operator!=(const Queue<T> & obj, const Queue<T> & obj2); //Сравнение объектов очереди.
template <typename T> bool operator<(const Queue<T> & obj, const Queue<T> & obj2); //Сравнение объектов очереди.
template <typename T> bool operator>(const Queue<T> & obj, const Queue<T> & obj2); //Сравнение объектов очереди.
template <typename T> ostream& operator<<(ostream & os, const Queue<T> & obj);
template <typename T> istream& operator>>(istream & os, Queue<T>& obj);

template <typename T> class Queue {

private:
    T* queue; //Указатель на первый элемент массива.
    int count; //Кол-во элементов в массиве.

public:

    Queue(){count = 0;} // Конструктор по умолчанию.

    Queue(const Queue& obj) // Конструктор копирования.
    {   
        *this = obj;
    }

    void push(T item) // Добавляет элемент в очередь
    {
        T* queue2; 
        queue2 = queue; 

        try {
            
            queue = new T[count + 1];

            for (int i = 0; i < count; i++)
                queue[i] = queue2[i];

            queue[count] = item;

            count++;

            if (count > 1)
                delete[] queue2;
        }
        catch (bad_alloc ex) {

            cout << ex.what() << endl;

           queue = queue2;
        }
    }

    T pop() //Вытаскивает первый элемент из очереди и возвращает его.
    {
        if (count == 0)
            return 0;

        T item;

        item = queue[0];

        try {
            T* queue2;

           queue2 = new T[count - 1];

            count--; 

            for (int i = 0; i < count; i++)
                queue2[i] = queue[i + 1]; 

            if (count > 0)
                delete[] queue;

           queue = queue2;

            return item;
        }
        catch (bad_alloc ex) {
            cout << ex.what() << endl;
            return 0;
        }
    }

    Queue& operator=(const Queue& obj) //Присваивание объектов очереди.
    {

        try {
           queue = new T[obj.count];
           count = obj.count;

            for (int i = 0; i < count; i++)
                queue[i] = obj.queue[i];
        }
        catch (bad_alloc ex)
        {
            cout << ex.what() << endl;
        }
        return *this;
    }

    Queue operator+(const Queue& obj) //Присваивание объектов очереди.
    {
        Queue<T> queue2;
        queue2.count = (count > obj.count ? count : obj.count);
        queue2.queue = new T[queue2.count];
        for (int i = 0; i < queue2.count; i++)
            queue2.queue[i] = queue[i] + obj.queue[i];
       
        return queue2;
    }

    friend bool operator== <>(const Queue<T> & obj, const Queue<T> & obj2); //Сравнение объектов очереди.
    friend bool operator!= <>(const Queue<T> & obj, const Queue<T> & obj2); //Сравнение объектов очереди.
    friend bool operator< <>(const Queue<T> & obj, const Queue<T> & obj2); //Сравнение объектов очереди.
    friend bool operator> <>(const Queue<T> & obj, const Queue<T> & obj2); //Сравнение объектов очереди.
    friend ostream& operator<< <>(ostream & os, const Queue<T> & obj);
    friend istream& operator>> <>(istream & os, Queue<T> & obj);

    ~Queue() //Деструктор.
    {
        if (count > 0)
            delete[] queue;
    }

    T start() //Возвращает первый элемент очереди.
    {
        if (count > 0)
            return queue[0];
        else
            return 0;
    }

    // очистка очереди
    void clear()
    {
        if (count > 0)
        {
            delete[] queue;
            count = 0;
        }
    }

    
    bool empty() // Проверяет если в очереди есть элементы.
    {
        return count == 0;
    }

    
    int getCounted() // Возвращает количество элементов в очереди.
    {
        return count;
    }

};

template <typename T> bool operator==(const Queue<T> & obj, const Queue<T> & obj2) //Перегрузка оператора сравнения.
{
    int maxCout = (obj.count > obj2.count ? obj.count : obj2.count);
    bool check = true;
    for (int i = 0; i < maxCout; i++)
        if (obj.queue[i] != obj2.queue[i])
            check = false;
    return check;
}

template <typename T> bool operator!=(const Queue<T> & obj, const Queue<T> & obj2) //Перегрузка оператора не равно.
{
    int maxCout = (obj.count > obj2.count ? obj.count : obj2.count);
    bool check = true;
    for (int i = 0; i < maxCout; i++)
        if (obj.queue[i] != obj2.queue[i])
            check = false;
    return !check;
}

template <typename T> bool operator<(const Queue<T> & obj, const Queue<T> & obj2) //Перегрузка оператора меньше.
{
    if (obj.count < obj2.count)
        return true;
    else
        return false;
}

template <typename T> bool operator>(const Queue<T> & obj, const Queue<T> & obj2) //Перегрузка оператора больше.
{
    if (obj.count > obj2.count)
        return true;
    else
        return false;
}

template <typename T> ostream& operator<<(ostream& os, const Queue<T> & obj) { //Перегрузка потокового оператора вывода

    T* queue2;
    queue2 = obj.queue;

    for (int i = 0; i < obj.count; i++)
        os << queue2[i] << " ";
    return os;
}

template <typename T> istream &  operator>>(istream & in, Queue<T> & obj) { //Перегрузка потокового оператора ввода

    T sth;
    in >> sth;
    obj.push(sth);
    return in;

}

template <typename T> void operator>>(Queue<T> & obj, T & sth) { //Перегрузка потокового оператора вывода в переменную

    sth = obj.pop();

}

template <typename T> void operator<<(Queue<T> & obj, T sth) { //Перегрузка потокового оператора ввода из переменной

    obj.push(sth);

}

int main()
{
    setlocale(0, "");

    Queue<int> Q1;
    Q1.push(5);
    Q1.push(8);
    Q1.push(11);
    Q1.push(17);

    Queue<int> Q2;
    Q2.push(5);
    Q2.push(8);
    Q2.push(1);
    Q2.push(17);

    Queue<int> Q3 = Q1;

    bool q = Q1 < Q2;
    cout << q;

    int asd;
    Q3 >> asd;
    cout << asd << "\n";
    cout << Q3 << "\n";
    int eee = 5;
    Q3 << 5;
    cout << Q3;
    
    
}