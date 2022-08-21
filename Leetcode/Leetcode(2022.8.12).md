# Leetcode(2022.8.12)

## 图森未来2022编程练习

### Day1  746.原子的数量

#### 题面

给你一个字符串化学式 formula ，返回 每种原子的数量 。

原子总是以一个大写字母开始，接着跟随 0 个或任意个小写字母，表示原子的名字。

如果数量大于 1，原子后会跟着数字表示原子的数量。如果数量等于 1 则不会跟数字。

例如，"H2O" 和 "H2O2" 是可行的，但 "H1O2" 这个表达是不可行的。
两个化学式连在一起可以构成新的化学式。

例如 "H2O2He3Mg4" 也是化学式。
由括号括起的化学式并佐以数字（可选择性添加）也是化学式。

例如 "(H2O2)" 和 "(H2O2)3" 是化学式。
返回所有原子的数量，格式为：第一个（按字典序）原子的名字，跟着它的数量（如果数量大于 1），然后是第二个原子的名字（按字典序），跟着它的数量（如果数量大于 1），以此类推。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-atoms、

#### 题解

考察栈与字符串，观察到受括号影响的是原子数量，并且是乘积关系。同时数字是在字母后边，从前往后不太好搞，从后往前还行。

一.遇到数字，用一个字符串b保存起来。

二.遇到  '  ）'，将b中的字符串转化为10进制数字，压入栈中，需注意从外向里倍数不断相乘。

三.遇到字母，分两种，小写就保存，大写就反转，添加到映射，并计算原子数量。

四.遇到  ' （'，累计倍数除栈首元素，令栈首元素pop出。

#### 技巧

一.字符串加到头部，b=i+b

二.字符串转数字，stoi(字符串，进制)

三.数字转字符串to_string(数字)

四.访问map元素

#### 代码

```c++
class Solution {
public:
    string countOfAtoms(string formula) {
        int len=formula.length();
        string num="",time="",s="";
        int cnt=1;
        stack<int> h;
        map<string,int> m;
        for(int i=len-1;i>=0;i--){
           // cout<<i<<endl;
            if(isdigit(formula[i])){
                num+=formula[i];
            }
            else if(formula[i]==')'){
                reverse(num.begin(),num.end());
                int k=num==""?1:stoi(num);
                num="";
                h.push(k);
                cnt*=k;
            }
            else if(formula[i]=='('){
                cnt/=h.top();
                h.pop();
            }
            else{
                s+=formula[i];
                if(formula[i]>='A'&&formula[i]<='Z'){
                    reverse(s.begin(),s.end());
                    reverse(num.begin(),num.end());
                    m[s]+=cnt*(num==""?1:stoi(num));
                    num="";
                    s="";
                }
            }
        }
        string ans="";
        for(auto it:m){
            ans+=it.first;
            if(it.second>1){
                ans+=to_string(it.second);
            }
        }
        return ans;
    }
};
```

### Day2  [522. 最长特殊序列 II](https://leetcode.cn/problems/longest-uncommon-subsequence-ii/)

#### 题面

给定字符串列表 strs ，返回其中 最长的特殊序列 的长度。如果最长特殊序列不存在，返回 -1 。

特殊序列 定义如下：该序列为某字符串 独有的子序列（即不能是其他字符串的子序列）。

 s 的 子序列可以通过删去字符串 s 中的某些字符实现。

例如，"abc" 是 "aebdc" 的子序列，因为您可以删除"aebdc"中的下划线字符来得到 "abc" 。"aebdc"的子序列还包括"aebdc"、 "aeb" 和 "" (空字符串)。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-uncommon-subsequence-ii

#### 题解

该题贪心，考虑某一整个字符串是否是其他字符串的子集，若是，则答案为0，若不是，则答案为该字符串的长度（此时最长）。

### Day3 [tusimple-004. 可视化](https://leetcode.cn/problems/NMTYve/)

#### 题面

作为即将成为自动驾驶工程师的 TuTu 自然需要掌握对一些内容进行可视化的技能。

为了训练自己，现在 TuTu 决定画一条线代表他在 n 天时间内的净资产变化。

对于 n 天中的每一天，他的净资产会增加 1 单位（以 + 表示）、减少 1 单位（以 - 表示）或保持不变（以 = 表示）。其中，在第一天之前，TuTu 的净资产等于零。

TuTu 将以一个无限大的字符矩阵来画线。矩阵行的索引向上增长，并且列的索引向右增长。

在第 i 天，他将在第 i 列中绘制一些字符。该行的字符和索引由以下规则决定：

如果净资产在第 i 天增加，则他将在某行中绘制 / ，其行索引等于当日开始时的净资产。
如果净资产在第 i 天减少，则他将在某行中绘制 \ ，其行索引等于当日结束时的净资产。
如果第 i 天的净值未发生变化，则他将在某行中绘制 - ，其行索引等于该天的净资产 。
所有其他单元格都用 . 填充。
TuTu 的任务是输出该无限大矩阵中一个包含所有有效信息的整行的最小矩阵，即包含所有字符 / 、 \ 和 - 的矩阵。

输入描述:

第一行包含整数 n (1 <= n <= 100) ，表示天数。

第二行包含 n 个字符的字符串 + ，- 和 =，代表净资产在指定时间内发生了变化。

输出描述:

输出无限大矩阵中一个包含所有有效信息的整行的最小矩阵。

样例1

输入
7
++---==

输出
./\\....
/..\\...
....\\--

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/NMTYve

#### 题解

该题题意不容易读，其次坑比较多。不过基本就是模拟找规律。