#include <iostream>
#include "htree.hh"
#include <cassert>
#pragma once


HTree::HTree(int key, uint64_t value, 
		tree_ptr_t left, tree_ptr_t right)
{
	key_ = key;
	value_ = value;
	left_ = left;
	right_ = right;
}	

int HTree::get_key() const
{
	return key_;
}

uint64_t HTree::get_value() const
{
	return value_;
}

HTree::~HTree()
{	
	if (left_)
		left_->~HTree();
	if (right_)
		right_->~HTree();
}

HTree::tree_ptr_t HTree::get_child(Direction dir) const
{
	if (left_ && dir == Direction::LEFT)
	{
		return left_;
	}
	if (right_ && dir == Direction::RIGHT)
	{
		return right_;
	}
	return nullptr;
}

bool HTree::find(key_t key) const
{
	if (key_ == key) return true;
	if (left_ && left_->find(key)) return true;
       	if (right_ && right_->find(key)) return true;
	return false;
}	

HTree::path_t HTree::path_to(int key) const
{
	path_t path;
	if (left_ && left_->find(key))
	{
		path = left_->path_to(key);
		path.push_front(Direction::LEFT);
		return path;
	}
	else if(key_ == key)
	{
		return path;
	}
	else if(right_ && right_->find(key))
	{
		path = right_->path_to(key);
		path.push_front(Direction::RIGHT);
		return path;
	}

	return path;

	}

	/*
	assert(find(key));
	path_t path;
	path_t::iterator it=path.begin();
	tree_ptr_t node = this;
	while(node->get_child(Direction::LEFT) or node->get_child(Direction::RIGHT) or node)
	{
		if(node->get_child(Direction::LEFT) && node->get_child(Direction::LEFT)->find(key))
		{
			path.insert(it, Direction::LEFT);
			it++;
			node = node->get_child(Direction::LEFT);
		}
		else if(node && node->get_key == key)
		{
			return path;
		}
		else if(node->get_child(Direction::RIGHT) && node->get_child(Direction::RIGHT)->find(key))
		{
			path.insert(it, Direction::RIGHT);
			it++;
			node = node->get_child(Direction::RIGHT);
		}
		exit(1);
	}
	return path;
}
	
		assert(find(key));
	path_t path;
	if (left_ && left_->find(key))
	{
		path
		return
	}
	if (key_ == key)
	{
		return;
	}
	if (right_ && right_->find(key))
	{
		path.insert(path.begin(), Direction::RIGHT);

		return path.insert(path.begin(), right_->path_to(key));
	}
	exit(1);


*/


