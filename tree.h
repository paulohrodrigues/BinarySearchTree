#include <iostream>
#include <string.h>
using namespace std;

struct node {
	State *state;
	struct node *left;
	struct node *right;
};
class Tree {
private:
	struct node *root;
	struct node* insert(State *value, struct node *temp){
		if(temp == NULL) {
			temp = new node;
			temp->state = value;
			temp->left = NULL;
			temp->right = NULL;
		} else if(strcmp(value->getName(),temp->state->getName())<0) {
			temp->left = insert(value, temp->left);
		} else if(strcmp(value->getName(), temp->state->getName())>0) {
			temp->right = insert(value, temp->right);
		}
		return temp;
	}
	struct node* search(string value, struct node *temp){
		if(temp == NULL) {
			return NULL;
		} else if(strcmp(value.c_str(), temp->state->getName())<0) {
			return search(value, temp->left);
		} else if(strcmp(value.c_str(), temp->state->getName())>0) {
			return search(value, temp->right);
		} else {
			return temp;
		}
	}
	struct node* searchMin(struct node *temp) {
		if(temp == NULL) {
			return NULL;
		} else if(temp->left == NULL) {
			return temp;
		} else {
			return searchMin(temp->left);
		}
	}
	struct node* searchMax(struct node *temp) {
		if(temp == NULL) {
			return NULL;
		} else if(temp->right == NULL) {
			return temp;
		} else {
			return searchMax(temp->right);
		}
	}
	struct node* remove(string value, struct node *temp) {
		struct node* aux;
		if(temp == NULL) {
			return NULL;
		} else if(strcmp(value.c_str(), temp->state->getName())<0) {
			temp->left = remove(value, temp->left);
		} else if(strcmp(value.c_str(), temp->state->getName())>0) {
			temp->right = remove(value, temp->right);
		} else if(temp->left != NULL && temp->right != NULL) {
			aux = searchMin(temp->right);
			temp->state = aux->state;
			temp->right = remove(temp->state->getName(), temp->right);
		} else {
			aux = temp;
			if(temp->left == NULL) {
				temp = temp->right;
			} else if(temp->right == NULL) {
				temp = temp->left;
			}
			delete aux;
		}
		return temp;
	}
public:
	Tree() {
		root = NULL;
	}
	~Tree() {
		root = NULL;
	}
	void insert(State *value) {
		root = insert(value, root);
	}
	State* search(string value) {
		return search(value, root)->state;
	}
	struct node* remove(string value) {
		struct node* temp = remove(value, root);
		return temp;
	}
	// void inorder(struct node* temp) {
	// 	if(temp != NULL) {
	// 		inorder(temp->left);
	// 		cout << temp->state->getName() << " ";
	// 		inorder(temp->right);
	// 	}
	// }
	// void preorder(struct node* temp) { }
	// void postorder(struct node* temp) { }
	// void display() {
	// 	inorder(root);
	// }
};
// int main(){
// 	Tree *bst = new Tree();
// 	bst->insert(new State("AL"));
// 	State *retorno = bst->search("AL");
// 	return 0;
// }