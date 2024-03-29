#pragma once
#include <string>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>
#include <set>

namespace ariel
{
	template <typename T>
	class BinaryTree
	{
		// inner class Node
		struct Node
		{
			T value;
			Node *right_son;
			Node *left_son;
			Node(const T &val)
				: value(val){};
			Node()
			{
			}
		};

		public:

		// pre_order_iterator inner class:
		class pre_order_iterator
		{
		private:
			Node *curr_node_ptr;
			Node *recursive_traversal_ptr;

		public:
			pre_order_iterator(Node *ptr = nullptr): curr_node_ptr(ptr){};

			T &operator*() const
			{
				return curr_node_ptr->value;
			}

			T *operator->() const
			{
				return &(curr_node_ptr->value);
			}

			// ++i;
			pre_order_iterator &operator++()
			{
				if (curr_node_ptr->left_son != nullptr)
				{
					recursive_traversal_ptr = curr_node_ptr;
					curr_node_ptr = curr_node_ptr->left_son;
				}
				else
				{
					curr_node_ptr = recursive_traversal_ptr->right_son;
				}
				return *this;
			}

			// i++;
			const pre_order_iterator operator++(int)
			{
				pre_order_iterator tmp = *this;
				if (curr_node_ptr->left_son != nullptr)
				{
					recursive_traversal_ptr = curr_node_ptr;
					curr_node_ptr = curr_node_ptr->left_son;
				}
				else
				{
					curr_node_ptr = recursive_traversal_ptr->right_son;
				}
				return tmp;
			}

			bool operator==(const pre_order_iterator &rhs) const
			{
				return curr_node_ptr == rhs.curr_node_ptr;
			}

			bool operator!=(const pre_order_iterator &rhs) const
			{
				return curr_node_ptr != rhs.curr_node_ptr;
			}
		}; // END OF CLASS pre_order_iterator

		class in_order_iterator
		{
		private:
			Node *curr_node_ptr;
			Node *recursive_traversal_ptr;

		public:

			in_order_iterator(Node *ptr = nullptr): curr_node_ptr(ptr){};

			T &operator*() const
			{
				return curr_node_ptr->value;
			}

			T *operator->() const
			{
				return &(curr_node_ptr->value);
			}

			// ++i;
			 in_order_iterator &operator++()
			{
				if (curr_node_ptr->left_son != nullptr)
				{
					recursive_traversal_ptr = curr_node_ptr;
					curr_node_ptr = curr_node_ptr->left_son;
				}
				else
				{
					curr_node_ptr = recursive_traversal_ptr->right_son;
				}
				return *this;
				//iterate to the next^ check
				return *this;
			}

			// i++;
			const in_order_iterator operator++(int)
			{
				in_order_iterator tmp = *this;
				if (curr_node_ptr->left_son != nullptr)
				{
					recursive_traversal_ptr = curr_node_ptr;
					curr_node_ptr = curr_node_ptr->left_son;
				}
				else
				{
					curr_node_ptr = recursive_traversal_ptr->right_son;
				}
				return tmp;
			}

			bool operator==(const in_order_iterator &rhs) const
			{
				return curr_node_ptr == rhs.curr_node_ptr;
			}

			bool operator!=(const in_order_iterator &rhs) const
			{
				return curr_node_ptr != rhs.curr_node_ptr;
			}
		}; // END OF CLASS in_order_iterator


class post_order_iterator
		{
		private:
			Node *curr_node_ptr;
			Node *recursive_traversal_ptr;
		public:

			post_order_iterator(Node *ptr = nullptr): curr_node_ptr(ptr){};

			T &operator*() const
			{
				return curr_node_ptr->value;
			}

			T *operator->() const
			{
				return &(curr_node_ptr->value);
			}

			// ++i;
			post_order_iterator &operator++()
			{
				//iterate to the next
				return *this;
			}

			// i++;
			const post_order_iterator operator++(int)
			{
				post_order_iterator tmp = *this;
				//iterate to the next
				return tmp;
			}

			bool operator==(const post_order_iterator &rhs) const
			{
				return curr_node_ptr == rhs.curr_node_ptr;
			}

			bool operator!=(const post_order_iterator &rhs) const
			{
				return curr_node_ptr != rhs.curr_node_ptr;
			}
		}; // END OF CLASS post_order_iterator


		int a = 0;
		Node *root;
		//Node rootNode();

	public:
		BinaryTree() : root(nullptr){

		};
		friend std::ostream &operator<<(std::ostream &outStream, BinaryTree &bTree){
			return outStream;
		}
		std::map<int, int> example;
		BinaryTree add_root(T root)
		{
			return *this;
		}; //- מקבלת קלט אחד ושמה אותו בשורש של העץ. אם כבר יש משהו בשורש, הוא מוחלף.
		BinaryTree &add_left(T exist, T toAddLeft)
		{
			return *this;
		}; //- מקבלת שני קלטים: הקלט הראשון מציין דבר שכבר קיים בעץ. הקלט השני מציין דבר חדש שיש להוסיף בתור הילד השמאלי שלו (אם כבר יש לו ילד שמאלי - יש להחליף את התוכן שלו).
		BinaryTree add_right(T exist, T toAddRight)
		{
			return *this;
		}; //- כנ"ל, רק שהתוספת היא בתור הילד הימני.
		pre_order_iterator begin_preorder()
		{
			return pre_order_iterator(root);
		};
		pre_order_iterator begin()
		{
			return pre_order_iterator(root);
		};
		pre_order_iterator end()
		{
			return pre_order_iterator(nullptr);
		}
		pre_order_iterator end_preorder()
		{
			return pre_order_iterator(nullptr);
		}; // - מחזירות איטרטורים לצורך מעבר בסדר preorder (אב - שמאל - ימין).
		in_order_iterator begin_inorder()
		{
			return in_order_iterator(root);
		};
		in_order_iterator end_inorder()
		{
			return in_order_iterator(root);
		}; //- מחזירות איטרטורים לצורך מעבר בסדר inorder (שמאל - אב - ימין).
		post_order_iterator begin_postorder()
		{
			return post_order_iterator(root);
		};
		post_order_iterator end_postorder()
		{
			return post_order_iterator(root);
		}; //- מחזירות איטרטורים לצורך מעבר בסדר postorder (שמאל - ימין - אב).

	

	}; //END OF CLASS BinaryTree


}; //END OF NAMESPACE ariel





//Reference: https://github.com/erelsgl-at-ariel/cpp-5781/tree/master/08-templates-iterators