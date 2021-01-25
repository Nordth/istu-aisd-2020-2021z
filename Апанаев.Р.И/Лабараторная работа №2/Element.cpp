#include <iostream>
using namespace std;

class Element {
public:
    int val;
    Element* nextElement; Element* prevElement;
};
class biList {
private:
    int length = 0;
    Element* FirstElement; Element* LastElement;
public:
    ~biList() { DelElements(); }
    void DelElements() {
        while (length != 0) {
            DelElement(1);
        }
    }
    void InsertElement(int pos, int n) {
        if (pos < 1 || pos > length + 1) {
            cout << "Элемент с этой позицией не существует";
            return;
        }
        if (pos == length + 1) {
            AddLastElement(n);
            return;
        }
        else if (pos == 1) {
            AddFirstElement(n);
            return;
        }
        int i = 1;
        Element* Insert = FirstElement;

        while (i < pos) {
            Insert = Insert->nextElement;
            i++;
        }
        Element* PrevInsert = Insert->prevElement;
        Element* temp = new Element;
        temp->val = n;

        if (PrevInsert != 0 && length != 1) {
            PrevInsert->nextElement = temp;
        }
        temp->nextElement = Insert;
        temp->prevElement = PrevInsert;
        Insert->prevElement = temp;
        length++;
    }
    void AddFirstElement(int n) {
        Element* temp = new Element;
        temp->prevElement = 0;
        temp->val = n;
        temp->nextElement = FirstElement;
        if (FirstElement != 0) {
            FirstElement->prevElement = temp;
        }
        if (length == 0) {
            FirstElement = LastElement = temp;
        }
        else {
            FirstElement = temp;
        }
        length++;
    }
    void AddLastElement(int n) {
        Element* temp = new Element;
        temp->nextElement = 0;
        temp->val = n;
        temp->prevElement = LastElement;
        if (LastElement != 0) {
            LastElement->nextElement = temp;
        }
        if (length == 0) {
            FirstElement = LastElement = temp;
        }
        else {
            LastElement = temp;
        }
        length++;
    }
        void DelElement(int pos) {
        if (pos < 1 || pos > length) {
            cout << "Элемент с этой позицией не существует";
            return;
        }
        int i = 1;
        Element* DelElement = FirstElement;
        while (i < pos) {
            DelElement = DelElement->nextElement;
            i++;
        }
        Element* PrevDel = DelElement->prevElement;
        Element* AfterDel = DelElement->nextElement;

        if (PrevDel != 0 && length != 1) {
            PrevDel->nextElement = AfterDel;
        }
        if (AfterDel != 0 && length != 1) {
            AfterDel->prevElement = PrevDel;
        }
        if (pos == 1)
            FirstElement = AfterDel;
        if (pos == length)
            LastElement = PrevDel;
        delete DelElement;
        length--;
    }
    void PrintElements() {
        if (length != 0) {
            Element* temp = FirstElement;
            while (temp->nextElement != 0) {
                cout << temp->val << " ";
                temp = temp->nextElement;
            }
            cout << temp->val << endl;
        }
    }
    void PrintElement(int pos) {
        if (pos < 1 || pos > length) {
            cout << "Элемент с этой позицией не существует";
            return;
        }
        Element* temp;

        if (pos <= length / 2) {
            temp = FirstElement;
            int i = 1;
            while (i < pos) {
                temp = temp->nextElement;
                i++;
            }
        }
        else {
            temp = LastElement;
            int i = 1;
            while (i <= length - pos) {
                temp = temp->prevElement;
                i++;
            }
        }
        cout << temp->val << endl;
    }
};

int main(void)
{
    setlocale(LC_ALL, "rus");
    biList mylist;
    cout << "Добавляем элементы '3, 7, 8, 4, 5' в конец списка"<<endl;
    mylist.AddLastElement(3); 
    mylist.AddLastElement(7); 
    mylist.AddLastElement(8);
    mylist.AddLastElement(4);
    mylist.AddLastElement(5); 
    cout << "Выводим все элементы списка"<<endl;
    mylist.PrintElements();
    cout << "Добавляем вторым элементом списка значение '4'"<<endl;
    mylist.InsertElement(2, 4);
    cout << "Выводим все элементы списка"<<endl;
    mylist.PrintElements();
    cout << "Удаляем 3 элемент"<<endl;
    mylist.DelElement(3);
    cout << "Выводим все элементы списка"<<endl;
    mylist.PrintElements();
    cout << "Выводим третий элемент списка"<<endl;
    mylist.PrintElement(3);
    cout << "пытаемся вывести 6 элемент списка"<<endl;
    mylist.PrintElement(6);
    
}