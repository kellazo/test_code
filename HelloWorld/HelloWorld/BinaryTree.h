#ifndef __BINARYTREE_LIST__
#define __BINARYTREE_LIST__
#include "p2List.h"
#include "Stack.h"
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
	//constructor que retorna un valor
	Tree(type valor){
		node<type>* nou = new node<type>;
		nou->data = valor;

	}

	//constructor buit
	Tree(){ root = NULL; }



	node<type>* Add(const type& valor){

		node<type>* nou = new node<type>(valor);

		rootNode->son.add(nou);

		nou->dad = rootNode;

		return nou;

	}

	node<type>* Add(const type& valor, node* parent){

		node<type>* nou = new node<type>(valor);

		parent->son.add(nou);

		nou->dad = parent;

		return nou;

	}

	//iteratiu en ordre que rep un punter a llista per poder modificarla
	void InOrderIterative( p2List* valor){

		//creem punter que apunta a nodes
		//el primer apunta al root
		node<type>* pointer = rootNode;
		//creem una pila

		Stack pila;
		
		while (pointer != NULL)
		{
			if (pointer->son->count() != 0 );
				//
			int total = pointer->son->count();
			int meitat_fills = total / 2;

			pila.push(pointer->son->end);
			pila.push(pointer);

			//hem de fer un bucle des de lultimf ins la meitat amb un for

			
			for (int total; n < total / 2; n--);

			pila.push(pointer->son->);






		}


		

	}








};











#endif // __BINARYTREE_LIST__