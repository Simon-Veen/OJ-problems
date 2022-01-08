/*
	类型：简单模拟
	时间：2020年3月5日 
*/ 

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

// 一些变量或结构体定义 
struct Trans{
	map<int, int> inKey;	//  存放输入中每个Place序号与之相应的token需求个数 
	vector<int> inList;		//	存放输入中每个Place序号
	map<int, int> outKey;	//  存放输出中每个Place序号与之相应的token需求个数 
	vector<int> outList;	//	存放输出中每个Place序号
};
int NP, NT, NF;
int npList[110];
Trans ntList[110];

// 一些函数声明 
void fun(int id);					// 主要函数 
void initTrans(Trans &T);			// 初始化一个Trans 
void outToken();					// 输出所有Place中的token状态 
bool run();							// 尝试运转一次 

// Main 
// #define debug
int main(){
	#ifdef debug
	//freopen("input.txt", "r",stdin);
	#endif
	int id = 0;
	cin >> NP;
	while(NP){
		id++;
		// 处理输入
		for(int i = 1; i <= NP; i++)
			cin >> npList[i];
		cin >> NT;
		for(int i = 1; i <= NT; i++){
			initTrans(ntList[i]);
			int tmp;
			cin >> tmp;
			while(tmp){
				if(tmp>0){	// 输出 
					if(ntList[i].outKey.count(tmp) != 1)
						ntList[i].outList.push_back(tmp);	// 如果之前没有过这个输出，则在序列里面添加一下这个Place的序号 
					ntList[i].outKey[tmp]++;
				}
				else{		// 输入 
					if(ntList[i].inKey.count(-tmp) != 1)
						ntList[i].inList.push_back(-tmp);	// 如果之前没有过这个输入，则在序列里面添加一下这个Place的序号
					ntList[i].inKey[-tmp]++;
				}
				cin >> tmp; 
			} 
		}
		cin >> NF;
		
		// 测试Petri网
		fun(id);
		
		// 新的Petri网开始输入 
		cin >> NP;
	}
	return 0;
}

// 一些函数定义 
void initTrans(Trans &T){
	T.outKey.clear();
	T.inKey.clear();
	vector<int>().swap(T.inList);
	vector<int>().swap(T.outList);
}

void fun(int id){
	int count = 0;
	while(count!=NF && run()){
		count++;
	}
	if(count==NF)
		cout << "Case "<<id<<": still live after "<<count<<" transitions"<<endl;
	else
		cout << "Case "<<id<<": dead after "<<count<<" transitions"<<endl;
	outToken();
}

bool run(){
	for(int i = 1; i <= NT; i++){							// 遍历所有的Trans，查看是否有可以运转的Trans 
		int tmp[110];										// 开一个临时的数组，用于暂存npList(各个Place的数据) 
		memcpy(tmp, npList, sizeof(int)*110);
		bool success = true;
		for(int x = 0; x < ntList[i].inList.size(); x++){
			int tag = ntList[i].inList[x];
			int num = ntList[i].inKey[tag];
			if(num > tmp[tag]){								// 如果有一个Place中的token低于这个Trans的输入要求，则无法运转 
				success = false;
				break;
			}
			tmp[tag]-=num;
		}
		if(success){
			for(int x = 0; x < ntList[i].outList.size(); x++){
				int tag = ntList[i].outList[x];			// 为Trans所输出的Place增加相应的token 
				int num = ntList[i].outKey[tag];
				tmp[tag]+=num;
			}
			memcpy(npList, tmp, sizeof(int)*110);;		// 更新状态
			/*for(int x = 1; x <= NP; x++){
				cout << npList[x] << " ";
			}
			cout << endl;*/
			return true;								// 这个Trans运转成功，返回真 
		}
	} 
	return false;										// 所有的Trans都无法正常运转，返回假 
}

void outToken(){
	cout << "Places with tokens:";
	for(int i = 1; i <= NP; i++){
		if(npList[i]>0){
			cout <<" "<<i<<" ("<<npList[i]<<")";
		}
	}
	cout << endl << endl;	// 注意是两个换行！ 
}