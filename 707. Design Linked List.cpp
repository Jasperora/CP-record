class Node {
public:
    int val;
    Node* next;
    Node* back;
    Node(int val) {
        this->val = val;
        next = nullptr;
        back = nullptr;
    }
};
class MyLinkedList {
public:
    int len;
    Node* head;
    Node* tail;
    MyLinkedList() {
        len = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int index) {
        if(index > len-1) return -1;
        Node* cur = head;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if(len==0){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->back = newNode;
            head = newNode;
        }
        ++len;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(len==0){
            head = tail = newNode;
        }else{
            newNode->back = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++len;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0) addAtHead(val);
        else if(index==len) addAtTail(val);
        else if(index < len){
            Node* cur = head;
            for(int i = 0; i < index-1; ++i){
                cur = cur->next;
            }
            Node* newNode = new Node(val);
            newNode->next = cur->next;
            newNode->back = cur;
            cur->next->back = newNode;
            cur->next = newNode;
            ++len;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>=len) return;
        if(index==0){
            head = head->next;
            if(head)
                head->back = nullptr;
        }else if(index==len-1){
            tail = tail->back;
            if(tail)
                tail->next = nullptr;
        }else{
            Node* cur = head;
            while(--index){
                cur = cur->next;
            }
            Node* next_node = cur->next->next;
            cur->next = next_node;
            next_node = cur;
        }
        --len;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */