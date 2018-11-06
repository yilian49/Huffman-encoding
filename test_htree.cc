#include<iostream>
#include "htree.cc"

int main()
{
//	HTree::tree_ptr_t root = std::make_shared<HTree>(1, 1, nullptr, nullptr);

	HTree::Direction rightD = HTree::Direction::RIGHT;
	HTree::Direction leftD  = HTree::Direction::LEFT;

	HTree::tree_ptr_t root = std::make_shared<HTree>(6, 0, 
			std::make_shared<HTree>(7, 0, nullptr, nullptr), 
			std::make_shared<HTree>(2, 0, 
				std::make_shared<HTree>(4, 0, 
					std::make_shared<HTree>(8, 0, nullptr, nullptr), 
					std::make_shared<HTree>(1, 0, nullptr, nullptr)), 
				std::make_shared<HTree>(7, 0, 
					std::make_shared<HTree>(5, 0, nullptr, nullptr), 
					nullptr)));
	
	std::cout<<root->get_key()<<"\n";
	std::cout<<root->get_value()<<"\n";
	std::cout<<root->get_child(rightD)->get_key()<<"\n";
	std::cout<<root->get_child(leftD)->get_key()<<"\n";
//should return 6, 0, 8, 7


	std::cout<<"\n";	
	
	// test to see if path_to gives the right path
	

	HTree::path_t path = root->path_to(5);
	for (auto v: path)
	{
		if( v == rightD)
			std::cout<<"Right"<<"\n";
		if( v == leftD)
			std::cout<<"Left"<<"\n";
	}



/*		HTree::tree_ptr_t tree1 = root;
		HTree::tree_ptr_t tree2 = root->get_child(leftD);
		HTree::tree_ptr_t tree3 = 
			root->get_child(rightD)
				->get_child(leftD);
	std::cout<<tree3->get_key();
*/
	root->~HTree();
/*	std::cout<<"\n";
	
	std::cout<<tree1->get_key();
*/
}

		

