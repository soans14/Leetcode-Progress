class BrowserHistory {
public:
    struct Node{
        string s;
        Node* prev;
        Node* next;
        Node(string url):s(url),prev(NULL),next(NULL) {}
    };
    Node* head;
    Node* temp;
    BrowserHistory(string homepage) {
        head= new Node(homepage);
        temp=head;
    }
    
    void visit(string url) {
        Node* deleteNode=temp->next;
        while(deleteNode!=NULL){
            Node* temp1=deleteNode->next;
            delete(deleteNode);
            deleteNode=temp1;
        }
        Node* visit=new Node(url);
        temp->next=visit;
        visit->prev=temp;
        temp=temp->next;
    }
    
    string back(int steps) {
        while(steps--&&temp->prev!=NULL){
            temp=temp->prev;
        }
        return temp->s;
    }
    
    string forward(int steps) {
        while(steps--&&temp->next!=NULL){
            temp=temp->next;
        }
        return temp->s;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */