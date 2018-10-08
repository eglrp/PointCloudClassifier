#pragma once



class UnionFind{

private:
	// rank[i]表示以i为根的集合所表示的树的层数
	// 在后续的代码中, 我们并不会维护rank的语意, 也就是rank的值在路径压缩的过程中, 有可能不在是树的层数值
	// 这也是我们的rank不叫height或者depth的原因, 他只是作为比较的一个标准
	// 关于这个问题，可以参考问答区：http://coding.imooc.com/learn/questiondetail/7287.html
	int* rank;
	int* parent; // parent[i]表示第i个元素所指向的父节点
	int count;   // 数据个数
	int* isolated;  //是否是根

public:

	UnionFind(int count);
	~UnionFind();

	// 查找过程, 查找元素p所对应的集合编号
	int find(int p);

	// 查看元素p和元素q是否所属一个集合
	bool isConnected(int p, int q);

	// 合并元素p和元素q所属的集合
	void unionElements(int p, int q);

	//判断是否已找到根
	bool isRoot(int p);

};


