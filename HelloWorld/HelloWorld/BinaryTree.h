#ifndef __BINARYTREE_LIST__
#define __BINARYTREE_LIST__
#include "p2List.h"
template <class type>
struct node
{
	type data;
	node* dad;
	p2List son;




};


template <class type>

class Tree{

private:
	node* rootNode;
public:
	Tree(type valor){
		node<type>* nou = new node<type>;
		nou->data = valor;

	}




	void Add(const type& valor){

		node<type>* nou = new node<type>(valor);

		rootNode->son.add(nou);

		nou->dad = rootNode;

	}

	void Add(const type& valor, node* parent){

		node<type>* nou = new node<type>(valor);

		parent->son.add(nou);

		nou->dad = parent;
		


	}




};











#endif // __BINARYTREE_LIST__