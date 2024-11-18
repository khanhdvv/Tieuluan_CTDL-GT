#include <bits/stdc++.h>

using namespace std;
struct node{
	int data;
	struct node*next;
};

typedef struct node node;
node *makeNode(int x){
	node *newNode = new node();
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}
void duyet(node *head){
	while(head != NULL){
		cout << head->data <<' ';
		head = head->next;
	}
}
// Them mot nut vao dau danh sach
void pushfront(node **head, int x){
	node *newNode = makeNode(x);
	//Buoc 1: Phan next cua newNode=>head
	newNode->next = *head; //*head=> dia chi cua node head trong DSLK
	//Buoc 2: Cap nhat node head=>newNode
	(*head) = newNode;
}
// Them mot nut vao cuoi danh sach
void pushback(node **head, int x){
	node *temp = *head;
	node *newNode = makeNode(x);
	if(*head == NULL){
		*head = newNode; return;
	}
	while (temp->next != NULL){
		temp = temp->next;
	}
	//Cho phan tu next cua node temp -> newNode
	temp->next = newNode;
}
// Xoa 1 nut o dau danh sach
void popfront(node **head){
	if(*head == NULL) return;
	node *temp = *head; //giai phong
	*head = (*head)->next;
	delete temp;
}
//Xoa 1 nut o cuoi danh sach
void popback(node **head){
	if(*head == NULL) return;
	node *temp = *head;
	if(temp->next == NULL){
		*head = NULL; 
		delete temp;
		return;
	}
	while(temp->next->next !=NULL){
		temp = temp->next;
	}
	node* last = temp->next; //node cuoi
	temp->next = NULL;
	delete last;
}
void delete_X(node** head, int x) {
    if (*head == NULL) {
        cout << "Danh sach rong!\n";
        return;
    }
    if ((*head)->data == x) {  // Nếu nút đầu có giá trị x
        node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }
    node* temp = *head;
    node* prev = NULL;
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {  // Không tìm thấy giá trị x
        cout << "Gia tri " << x << " khong ton tai trong danh sach!\n";
        return;
    }
    // Xóa nút chứa giá trị x
    prev->next = temp->next;
    delete temp;
}
int main(){
	node *head = NULL;
	while(1){
		cout << "\n....................MENU...................";
		cout <<"\n1. Them mot nut vao dau danh sach";
		cout <<"\n2. Them mot nut vao cuoi danh sach";
		cout <<"\n3. Xoa mot nut o dau danh sach";
		cout <<"\n4. Xoa mot nut o cuoi danh sach";
		cout <<"\n5. Xoa nut dau tien co gia tri X";
		cout <<"\n6. Duyet";
		cout <<"\n0. Thoat!";
		cout <<"\n............................................";
		cout <<"\nNhap lua chon :";
		int luachon; cin >> luachon;
		if (luachon == 1){
			int x; cout <<"Nhap gia tri x :"; cin >> x;
			pushfront(&head, x);
		}
		else if(luachon == 2){
			int x; cout <<"Nhap gia tri x :"; cin >> x;
			pushback(&head, x);
		}
		else if(luachon == 3){
			popfront(&head);
		}
		else if(luachon == 4){
			popback(&head);
		}
		else if (luachon == 5) {
            int x;
            cout << "Nhap gia tri X can xoa: ";
            cin >> x;
            delete_X(&head, x);
        }
		else if(luachon == 6){
			duyet(head);
			cout << endl;
		}
		else{
			break;
		}
	}
	return 0;
}