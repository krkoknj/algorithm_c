#include <iostream>
using namespace std;

// ⭕️ 1) 노드 구조 정의
struct Node {
    int data;    // 저장할 값
    Node* next;  // 다음 노드를 가리키는 포인터

    Node(int val) : data(val), next(nullptr) {}
};

// ⭕️ 2) 연결 리스트 클래스
class LinkedList {
private:
    Node* head;  // 리스트의 첫 번째 노드를 가리키는 포인터

public:
    // 생성자: 빈 리스트이므로 head 를 nullptr 로 초기화
    LinkedList() : head(nullptr) {}

    // 소멸자: 남은 모든 노드 메모리 해제
    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* toDelete = cur;
            cur = cur->next;
            delete toDelete;
        }
    }

    // ⭕️ 2-1) 맨 앞에 노드 추가
    void push_front(int val) {
        Node* node = new Node(val);
        node->next = head;  // 새 노드의 next 를 기존 head 로
        head = node;        // head 를 새 노드로 갱신
    }

    // ⭕️ 2-2) 맨 뒤에 노드 추가
    void push_back(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }

    // ⭕️ 2-3) 특정 값(val) 위치 뒤에 삽입
    // prev 가 nullptr 이면 맨 앞에 삽입
    void insert_after(Node* prev, int val) {
        if (!prev) {
            push_front(val);
            return;
        }
        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;
    }

    // ⭕️ 2-4) 특정 값 삭제 (첫 번째 만남만)
    void delete_value(int val) {
        if (!head) return;
        // head 가 삭제 대상일 때
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        // 그 외 중간/끝 삭제
        Node* cur = head;
        while (cur->next && cur->next->data != val)
            cur = cur->next;
        if (cur->next) {
            Node* toDelete = cur->next;
            cur->next = cur->next->next;
            delete toDelete;
        }
    }

    // ⭕️ 2-5) 값으로 노드 찾기 (없으면 nullptr)
    Node* find(int val) const {
        Node* cur = head;
        while (cur) {
            if (cur->data == val)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    // ⭕️ 2-6) 리스트 출력
    void print() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << endl;
    }
};

// ⭕️ 3) 간단한 사용 예
int main() {
    LinkedList list;

    // 맨 앞/뒤 삽입
    list.push_front(10);    // 10
    list.push_front(20);    // 20 -> 10
    list.push_back(30);     // 20 -> 10 -> 30
    list.print();

    // 값 10 뒤에 15 삽입
    Node* node10 = list.find(10);
    list.insert_after(node10, 15);  // 20 -> 10 -> 15 -> 30
    list.print();

    // 값 20 삭제
    list.delete_value(20);  // 10 -> 15 -> 30
    list.print();

    return 0;
}
