#include <iostream>
#include <list>
struct Node{
        int value;
        Node* next;
};
class linkedList{
    private:
        Node* head;
    public:
        linkedList(){
            head = nullptr;
        }
        void creteNewNode(int value){
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next = nullptr;
            if(head == nullptr){
                head = newNode;
            }
            else{
                Node* currentNode = head;
                while(currentNode->next != nullptr){
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
        }
        Node* findNodeByIndex(int index){
            if(index < 0 or index >= findSize()){
                std::cout << "Index out of range:(" << std::endl;
                Node* node = nullptr;
                return node;
            }
            Node* result = head;
            while(index--){
                result = result->next;
            }
            return result;
        }
        Node* findNodeByValue(int value){
            Node* result = head;
            while(result != nullptr){
                if(result->value == value){
                    return result;
                }
                
                result = result->next;
            }
            std::cout << "Not such a value:(" << std::endl;
            return nullptr;
        }
        int findSize(){
            int size = 0;
            Node* currentNode = head;
            while(currentNode != nullptr){
                size++;
                currentNode = currentNode->next;
            }
            return size;
        }
        void deleteNodeByValue(int value){
            if(head == nullptr){
                std::cout << "Nothing to delete:(" << std::endl;
                return;
            }
            if(head->value == value){
                Node* currentNode = head;
                head = head->next;
                delete currentNode;
                return;
            }
            Node* currentNode = head;
            Node* beforeCurrent = nullptr;
            while(currentNode != nullptr){
            if(currentNode->value == value){
                beforeCurrent->next = currentNode->next;
                delete currentNode;
                return;
            }
            beforeCurrent = currentNode;
            currentNode = currentNode->next;
            }
            std::cout << "Not such a value to delete:(" << std::endl;
        }
        void deleteNodeByIndex(int index){
            if(index < 0 or index >= findSize()){
                std::cout << "Index out of range:(" << std::endl;
                return;
            }
            if(index == 0){
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            Node* result = head;
            Node* beforeResult = nullptr;
            while(index--){
                beforeResult = result;
                result = result->next;
            }
            beforeResult->next = result->next;
            delete result;
        }
        Node* findMiddleNode(){
            if(head == nullptr){
                std::cout << "No element in list:(" << std::endl;
                return head;
            }
            Node* first = head->next;
            Node* second = head->next->next;
            while(second != nullptr and second->next != nullptr){
                first = first->next;
                second = second->next->next;
            }
            return first;
        }
        void sort(){
            for(Node* i = head; i != nullptr; i = i->next){
                for(Node* j = head; j->next != nullptr; j = j->next){
                    if(j->value > j->next->value){
                        int temp = j->value;
                        j->value = j->next->value;
                        j->next->value = temp;
                    }
                }
            }
        }
        void merge(linkedList &newList1){
            Node* list1 = this->head;
            Node* list2 = newList1.head;
            Node* first = nullptr;
            Node* last = nullptr;
            while(list1 != nullptr and list2 != nullptr){
                Node* temp = nullptr;
                if(list1->value < list2->value){
                    temp = list1;
                    Node* next = list1->next;
                    list1 = next;
                }
                else{
                    temp = list2;
                    Node* next = list2->next;
                    list2 = next;
                }
                if(first == nullptr){
                    first = temp;
                    last = temp;
                }
                else{
                    last->next = temp;
                    last = temp;
                }
            }
            while(list1 != nullptr){
                Node* next = list1->next;
                if(first == nullptr){
                    first = list1;
                    last = list1;
                }
                else{
                    last->next = list1;
                    last = list1;
                }
                list1 = next;
            }
            while(list2 != nullptr){
                Node* next = list2->next;
                if(first == nullptr){
                    first = list2;
                    last = list2;
                }
                else{
                    last->next = list2;
                    last = list2;
                }
                list2 = next;
            }
            if(last != nullptr){
                last->next = nullptr;
            }
            this->head = first;
        }
        void showAllNode(){
            Node* current = head;
            std::cout << "The elements: ";
            while(current != nullptr){
                std::cout << current->value << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
};
linkedList newList1;
linkedList newList2;
void doOperation(linkedList &newList){
    std::cout << "If you want to stop, please enter -1" << std::endl;
    while(true){
        std::string input;
        int value;
        std::cout << "Please enter what do you want to do?" << std::endl;
        std::cout << "*Note* you can ` add, delete by index, delete by value, search by index, search by value, find size, find middle, sort, merge, show: ";
        getline(std::cin, input);
        input[0] = toupper(input[0]);
        if(input == "-1"){
            return;
        }
        else if(input == "Add"){
            std::cout << "Please enter the value of new element (num): ";
            std::cin >> value;
            std::cin.ignore();
            newList.creteNewNode(value);
        }
        else if(input == "Delete by index"){
            std::cout << "Please enter the index: ";
            std::cin >> value;
            std::cin.ignore();
            newList.deleteNodeByIndex(value);
        }
        else if(input == "Delete by value"){
            std::cout << "Please enter the value: ";
            std::cin >> value;
            std::cin.ignore();
            newList.deleteNodeByValue(value);
        }
        else if(input == "Search by index"){
            std::cout << "Please enter the index: ";
            std::cin >> value;
            std::cin.ignore();
            Node* node = newList.findNodeByIndex(value);
            if(node != nullptr){
                std::cout << "The value is: " << node->value << std::endl;
            }
        }
        else if(input == "Search by value"){ //In this case finding the value by value it's sounds crazy, but it's because the node has only this information but if it has more, then finding that information with value will make sense
            std::cout << "Please enter the value: ";
            std::cin >> value;
            std::cin.ignore();
            Node* node = newList.findNodeByValue(value);
            if(node != nullptr){
                std::cout << "The value is: " << node->value << std::endl;
            }
        }
        else if(input == "Find size"){
            int size = newList.findSize();
            std::cout << "The size: " << size << std::endl;
        }
        else if(input == "Find middle"){
            Node* node = newList.findMiddleNode();
            if(node != nullptr){
                std::cout << "The value is: " << node->value << std::endl;
            }
        }
        else if(input == "Sort"){
            newList.sort();
        }
        else if(input == "Merge"){
            newList.merge(newList1);
        }
        else if(input == "Show"){
            newList.showAllNode();
        }
        else{
            std::cout << "No suct a operation, please try again:(" << std::endl;
        }
        std::cout << std::endl;
    }
}
int main(){
    std::cout << "Work with first list" << std::endl;
    std::cout << std::endl;
    doOperation(newList1);
    std::cout << std::endl;
    std::cout << "Work with second list" << std::endl;
    std::cout << std::endl;
    doOperation(newList2);
    std::cout << std::endl;
    
}
