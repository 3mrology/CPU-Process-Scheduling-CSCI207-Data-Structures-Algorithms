#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class CPUProcess{
private:
    int processID;
    string processName;
    double timeNeeded;
public:
    CPUProcess(int id = 0, string name = "\0", double time = 0.0){
        processID = id;
        processName = name;
        timeNeeded = time;
    }
    void setID(int id){
        processID = id;
    }
    void setName(string name){
        processName = name;
    }
    void setTime(double time){
        timeNeeded = time;
    }
    int getID(){
        return processID;
    }
    string getName(){
        return processName;
    }
    double getTime(){
        return timeNeeded;
    }
    void printInfo(){
        cout<<"Process id: "<<getID()<<endl;
        cout<<"Process name: "<<getName()<<endl;
        cout<<"Time needed: "<<getTime()<<endl;
    }
};
template <class T>
class ProcessNode{
private:
    T Data;
    ProcessNode<T> * Next;
public:
    ProcessNode(T data = NULL, ProcessNode<T> * next = NULL){
        Data = data;
        Next = next;
    }
    T getData(){
        return Data;
    }
    ProcessNode<T> * getNext(){
        return Next;
    }
    void setData(T data){
        Data = data;
    }
    void setNext(ProcessNode<T>* next){
        Next = next;
    }
};
template <class T>
class StackLL{
    ProcessNode<T>* head;
public:
    StackLL(){
        head = NULL;
    }
    bool isEmpty(){
        return (head == NULL);
    }
    ProcessNode<T> * getHead(){
        return head;
    }
    ProcessNode<T> * setHead(ProcessNode<T> * h){
        head = h;
    }
    bool pushProcess(T process){
        ProcessNode<T> * newNode = new ProcessNode<T>(process);
        ProcessNode<T> * here = head;
        //not head
        if(head == NULL){
            head = newNode;
            cout<<"Head inserted"<<endl;
            return true;
        }
        else{
            while(here->getNext()!=NULL){
                here = here->getNext();
            }
            here->setNext(newNode);
            cout<<"Process insterted"<<endl;
            return true;
        }
        return 0;
    }
    bool stackOfProcesses(){
        ProcessNode<T>*here = head;
        while (here!=NULL){
            here->getData().printInfo();
            here = here->getNext();
        }
        return true;
    }
    CPUProcess lateProcess(){
        if(!isEmpty()){
            ProcessNode<T> * here = head;
            while(here->getNext()!=NULL){
                here = here->getNext();
            }
            return here->getData();
        }
    }

};
template <class T>
class QueueLL{
    ProcessNode<T>* front;
    ProcessNode<T>* rear;
    double capacity;
public:
    QueueLL(int c = 3){
        front = NULL;
        rear = NULL;
        capacity = 3;
    }
    void setCapacity(int c){
        capacity = c;
    }
    bool execute(T process){
        ProcessNode<T>* newNode = new ProcessNode<T>(process);//1
        ProcessNode<T>* here = front;//1
        while(here!=NULL){//N
            if(here->getData().getID()==process.getID()){
                cout<<"Member already exists"<<endl;
                return 0;
            } else{//1
                here = here->getNext();
            }
        }
        if(rear == NULL){//1
            front = rear = newNode;//2
            cout<<"Head instered"<<endl;
        }
        else{//1
            rear->setNext(newNode);//1
            cout<<"Passed"<<endl;//2
            rear = rear->getNext();//2
        }
    }
    CPUProcess runProcess(){
        if(front->getData().getTime() <= capacity){
            if(front == rear){
                ProcessNode<T> * empty = new ProcessNode<T>(NULL,NULL);
                front->setNext(empty);
                front = front->getNext();
                cout<<"Process Execution is Completed, List is now empty"<<endl;
                return front->getData();
            }
            else {
                ProcessNode<T> * temp = front;
                front = front->getNext();
                cout<<"Process Execution is Completed"<<endl;
                return temp->getData();
            }
        }
        else{
            //
        }
    }
    void cpuSchedule() {
        ProcessNode<T> *here = front;
        while (here != NULL) {
            here->getData().printInfo();
            here = here->getNext();
        }
    }
    bool isEmpty() {
        return (front == NULL) && (rear == NULL);
    }
    bool killProcess(StackLL<CPUProcess> * sll) {
        ProcessNode<T> * temp = front;
    if(front==NULL){
        cout<<"List is empty"<<endl;
        return false;
    }
    else{
        while (temp != NULL){
            if(temp->getData().getTime()>capacity){
                if(temp==front){
                    front = temp->getNext();
                }
                sll->pushProcess(temp->getData());
                temp = temp->getNext();
            }
            else{
                temp = temp->getNext();
            }
        }
    }
    }
};
//Bonus Part
class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(int newV)
{
    TreeNode *node = new TreeNode;
    node->value = newV;
    node->left = node->right = nullptr;

    return node;
}
void AddtoTree(TreeNode* &root, int value){

    if (root == nullptr)
    {
        root = newNode(value);
        return;
    }
    if (value > root->value) {
        AddtoTree(root->right, value);
    } else{
        AddtoTree(root->left, value);
    }

}
void printInorder(TreeNode * node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    cout << node->value << " ";

    printInorder(node->right);
}
//Complexity Analysis
//O(N)
int main() {
    CPUProcess p1(1,"p1",10);
    CPUProcess p2(2,"p2",4);
    CPUProcess p3(3,"p3",1);
    CPUProcess p4(4,"p4",5);
    CPUProcess p5(5,"p5",15);
    QueueLL<CPUProcess> qll;
    qll.execute(p1);
    qll.execute(p2);
    qll.execute(p3);
    qll.execute(p4);
    qll.execute(p5);
    qll.cpuSchedule();
    StackLL<CPUProcess> sll;
    qll.killProcess(&sll);
    sll.stackOfProcesses();
    sll.lateProcess().printInfo();
    TreeNode* root = NULL;
    AddtoTree(root, 5);
    AddtoTree(root, 3);
    AddtoTree(root, 7);
    AddtoTree(root, 4);
    AddtoTree(root, 2);
    AddtoTree(root, 1);
    AddtoTree(root, 9);
    AddtoTree(root, 8);
    AddtoTree(root, 10);
    printInorder(root);
    return 0;
}
