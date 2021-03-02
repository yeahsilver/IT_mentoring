#include <iostream>

using namespace std;

class Node {
    public: 
        int data;
        Node * next;
};

class Link {
    public: 
        Node* head;

        void InitNode();
        void InitSize();

        void Menu(Link link);

        void InsertData(int data); // 데이터 입력
        void DeleteData(int nodeIndex); // 데이터 삭제
        void GetData(int nodeIndex); // 데이터 값 찾기
    
        const void PrintData(); // 모든 데이터 출력 
        const void PrintSize(); // 데이터 크기(개수) 확인

    private: 
        int size;
};

int main(void) {
    Link link;

    link.InitNode();
    link.InitSize();

    link.Menu(link);
}

void Link:: InitNode(){
    head = new Node();
}

void Link:: InitSize() {
    size = 0;
}

void Link:: Menu(Link link) {    
    while(1) {
        cout << "----- 링크드 리스트 프로그램 -----\n\n";
        cout << "1. 데이터 입력\n";
        cout << "2. 데이터 삭제\n";
        cout << "3. 데이터 값 찾기\n";
        cout << "4. 모든 데이터 출력\n";
        cout << "5. 데이터 크기 확인 \n";
        cout << "6. 종료 \n";
        cout << "\n----------------------------------\n";

        char num;
        cin >> num;

        switch(num) {
            int value;
            int index;

            case '1':
                cout << "넣고 싶은 데이터를 입력하세요: ";
                
                cin >> value;
                link.InsertData(value);

                break;

            case '2':  
                cout << "삭제하고 싶은 데이터 인덱스를 입력하세요: ";

                cin >> index;
                link.DeleteData(index);

                break;
            
            case '3':
                cout << "찾고 싶은 데이터의 인덱스를 입력하세요: ";
                
                cin >> index;
                link.GetData(index);

                break;

            case '4':
                link.PrintData();
                break;

            case '5': 
                link.PrintSize();
                cout << "출력을 완료했습니다.\n\n";
                break;

            default:
                cout << "프로그램을 종료합니다."; 
                exit(0);
        }
    }
}

void Link:: InsertData(int data) {
    if(size == 0) {
        head -> data = data;
    } else {
        Node *currentNode = new Node();

        currentNode -> data = data;

        Node *tempNode = head;

        while(tempNode -> next != nullptr) {
            tempNode = tempNode -> next;
        }

        tempNode -> next = currentNode;
     }
     size++;

     cout << "입력이 완료되었습니다.\n\n";
}

void Link:: GetData(int index) {
    Node* tempNode = head;

    for(int i = 0; i < size; i++) {
        if(index == i) {
            cout << "인덱스" << index << "의 값: " << tempNode -> data << '\n';
            cout << "탐색을 완료했습니다.\n\n";
            continue;
        } else {
            tempNode = tempNode -> next;
        }
    }
}

const void Link:: PrintData() {
    Node* tempNode = head;

    if(size == 0) {
        cout << "데이터가 없습니다. \n\n";
    } else {
        for(int i = 0; i < size; i++) {
            cout << tempNode -> data << '\t';
            tempNode = tempNode -> next;
        }
        cout << "\n출력을 완료했습니다.\n\n";
    }
}

const void Link:: PrintSize() {
  cout << "Linked List 사이즈 : " << size << "\n\n";
}

void Link:: DeleteData(int index) {
    Node *tempNode = head;
    Node* deleteNode;
    Node* swapNode;

    if(index > 0) {
        for(int i = 0; i < index-1; i++) {
            tempNode = tempNode -> next;
        }

        deleteNode = tempNode -> next;  
        swapNode = deleteNode -> next;
        tempNode -> next = swapNode;

    } else {
        head = tempNode -> next;
        deleteNode = tempNode;
    }

    cout << "삭제가 완료되었습니다. \n\n";

    delete deleteNode;
    size -= 1;
}

