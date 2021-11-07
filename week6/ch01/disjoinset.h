#ifndef __DIS_JOIN_SET_H__
#define __DIS_JOIN_SET_H__
 
#include <map>
#include <vector>
 
class disjoinset
{
public:
	// 构造函数
	explicit disjoinset(int n);
	
	// find操作
	int find(int x) const;
	
	// union操作
	void union_set(int r1, int r2);
	
	// 返回集合元素个数>=max_num_thresh 的集合元素，
	std::vector< std::vector<int> > get_sets(size_t max_num_thresh = 1) const;
 
	// 打印当前并查集信息，调试用
	void print() const;
private:
	vector<int> s;
};
 
#endif
