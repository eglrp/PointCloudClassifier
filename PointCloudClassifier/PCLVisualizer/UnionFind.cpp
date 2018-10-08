#include "UnionFind.h"

#include <cassert>

// 构造函数
UnionFind::UnionFind(int count){
	parent = new int[count];
	rank = new int[count];
	isolated = new int[count];
	this->count = count;
	for (int i = 0; i < count; i++){
		parent[i] = i;
		rank[i] = 1;
		isolated[i] = 1;  //1 代表是孤立点 ， 0 代表已经找到组织
	}
}

// 析构函数
UnionFind::~UnionFind(){
	delete[] parent;
	delete[] rank;
	delete[] isolated;
}

// 查找过程, 查找元素p所对应的集合编号
// O(h)复杂度, h为树的高度
int UnionFind::find(int p){
	assert(p >= 0 && p < count);
	while (p != parent[p]){
		parent[p] = parent[parent[p]];
		p = parent[p];
	}
	return p;
}

// 查看元素p和元素q是否所属一个集合
// O(h)复杂度, h为树的高度
bool UnionFind::isConnected(int p, int q){
	return find(p) == find(q);
}

// 合并元素p和元素q所属的集合
// O(h)复杂度, h为树的高度
void UnionFind::unionElements(int p, int q){

	int pRoot = find(p);
	int qRoot = find(q);

	if (pRoot == qRoot)
		return;

	// 根据两个元素所在树的元素个数不同判断合并方向
	// 将元素个数少的集合合并到元素个数多的集合上
	if (rank[pRoot] < rank[qRoot]){
		parent[pRoot] = qRoot;
		isolated[pRoot] = 0;
	}
	else if (rank[qRoot] < rank[pRoot]){
		parent[qRoot] = pRoot;
		isolated[qRoot] = 0;
	}
	else{ // rank[pRoot] == rank[qRoot]
		parent[qRoot] = pRoot;  ///这个暂且定义为左向连接
		isolated[qRoot] = 0;
		rank[qRoot] += 1;   // 此时, 我维护rank的值
	}

}

bool UnionFind::isRoot(int p){
	if (isolated[p] == 1) //如果还是自循环点的话
		return true;
	return false;
}

