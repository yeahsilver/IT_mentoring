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
    
    link.InsertData(10);
    link.InsertData(20);
    link.InsertData(30);

    link.PrintData();
    
    link.GetData(1);

    
    link.DeleteData(1);

    link.PrintSize();

    link.PrintData();

    link.DeleteData(0);

    link.PrintData();
}

void Link:: InitNode(){
    head = new Node();
}

void Link:: InitSize() {
    size = 0;
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

     cout << "데이터 " << data << " 입력 완료\n\n";
}

void Link:: GetData(int index) {
    Node* tempNode = head;

    for(int i = 0; i < size; i++) {
        if(index == i) {
            cout << "인덱스" << index << " 의 값 :" << tempNode -> data << '\n';
        } else {
            tempNode = tempNode -> next;
        }
    }
}

const void Link:: PrintData() {
    Node* tempNode = head;

    if(size == 0) {
        cout << "데이터가 없습니다. \n";
    } else {
        cout << "데이터 출력 \n";
        
        for(int i = 0; i < size; i++) {
            cout << tempNode -> data << '\t';
            tempNode = tempNode -> next;
        }
        cout << "\n\n";
    }
}

const void Link:: PrintSize() {
  cout << "데이터 개수: " << size << "\n\n";
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

    delete deleteNode;
    size -= 1;
    cout << "데이터 인덱스 " << index << " 삭제 완료 \n\n";
}
