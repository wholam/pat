# pat

#### q1005

大整数运算（该题为10^100），可以先用字符数组输入然后再做处理，每一位减去‘0’得到该位对应数值。

```C++
strlen(字符数组名)//求字符串长度
string 字符串对象
```



#### q1011

```C++
#include<iomamip>//控制输入输入格式
cout<<setprecision(4);//输入四位有效数字
```



#### q1015

```C++
#include<vector>
vector<int> a;//定义向量，相当于边长数组
a.push_back(temp);//添加一个值
```

本题先将一个素数转为D进制，然后反转，在转为10进制判断是否位素数。若是，则是reversible primes。

如：23 二进制10111 反转为11101，十进制是29，为素数，所以23是reversible primes。



#### q1009

```C++
#include<iomanip>
cout<<setiosflags(ios::fixed)<<setprecision(1);
//保留一位小数
如果是加法，次数是0-1000，可以用数组来保存对应系数。
本题是两个多项式相乘，次数最多可以是1000000，无法用数组来保存对应系数，可以采用链表来表示一个多项式。
系数相乘相加后若为0，则应该删去。
```

#### q1025



#### q1084

```c++
#include<algorithm>

transform(s.begin(),s.end(),s.begin(),::toupper);
//将string类字符串转换为大写 ::tolower

#include<string>
getline(cin,str);//获取带有空格的字符串
```



#### q1024

大整数运算

1. 用string运算
2. 用vector运算

#### q1100

string转整数：

```
string s;
int n;
n = atoi(s.c_str());
```



## 算法初步

### 排序 P87

1. 冒泡排序
2. 选择排序：分有序区和无序区，每趟从无序区中选出最小的放到有序区后面。算法复杂度O(n^2)。
3. 插入排序：将无序区第一个元素在有序区中找到一个合适的位置插入

C++中sort函数实现排序功能。

```C++
#include<algorithm>
sort(首元素地址，尾元素地址的下一个地址，[比较函数]);
//不写比较函数，默认递增

bool cmp(int a,int b){
    return a>b;//从大到小排序
}

bool cmp(node a, node b){
    return a.x>b.x;//node为结构体
}

bool cmp(node a, node b){
    if(a.x!=b.x) return a.x>b.x;
    else return a.y<b.y;//先按x从大到小，再按y从小到大
}

```

对于容器，sort函数只能用于vector、string、deque的排序。

```C++
sort(vi.begin(),vi.end(),cmp);
```

对应题目：

![image-20201126182054450](https://i.loli.net/2020/11/26/m64BPciLpkUtTIC.png)

**q1012:**

注意：总分相同排名相同，但之后的排名应该算上相同排名的考生数。

如1 2 2 2 5 而不是 1 2 2 2 3

**q1016:**

注意：

1. 不是每个人都有配对的通话记录，对于没有有效记录的人不输出
2. 计算费用时，开始和结束时间在同一小时内要特别计算。

**q1080:**

**q1095:**

### 散列（hash）P128

hash:将一个元素通过一个函数转化为整数，使该整数可以尽量唯一地代表该元素。

```c++
//key为整数
除留余数法：H(key) = key % mod，mod最好为素数。

避免冲突：
1. 线性探查法
2. 平方探查法
3. 链地址法：将所有hash值相同地key连接成一条链表
前两种方法都要寻找新的hash值。
```

```
//key为字符串
将A-Z视为0-25，每个字符串可以转换为1个整数作为它的hash值。
```

```C++
//map用法
#include<map>
map<typename1,typename2> mp;
map<char,int> mp;
//通过下标访问
mp['c']=20;
mp['c']=30;
//通过迭代器访问
map<typename1,typename2>::iterator it;
it->first;//访问key
it->second;//访问值
//map自动按照key从小到大的顺序排序。

常用函数：
1、find(key);//返回对应迭代器
2、mp.erase(it or key);//删除单个元素
   mp.erase(first,last);//last为末尾迭代器的下一个地址
3、size()
4、clear()
```



对应题目：

![image-20201126184636406](https://i.loli.net/2020/11/26/DxeFJd4pgXUIkwV.png)



### 贪心 P148

求解最优化问题的一种方法，总是考虑在当前状态下局部最优（较优）策略，来使全局的结果达到最优（较优）。

对应题目：

![image-20201126184716940](https://i.loli.net/2020/11/26/3yNE2HPASkrndDW.png)



### 二分 P165

对应题目：

![image-20201127185222244](https://i.loli.net/2020/11/27/93pzsANe6DlIog8.png)

q1085

大量数据的传递，使用全局变量。作为参数传递要花费很多时间。

```c++
lower_bound(begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

upper_bound(begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
```



### two pointers P176

![image-20210118174153478](C:\Users\luo15\AppData\Roaming\Typora\typora-user-images\image-20210118174153478.png)

#### 归并排序

采用“分而治之”的思想。将待排序的数组逐步划分，排序后在归并。

时间复杂度是O(nlogn)

1. 递归写法
2. 非递归写法

#### 快速排序

为第一个元素在整个待排序序列中找到一个位置，使得它左边的元素都不大于它，它右边的元素都小于它。然后递归处理左右子序列，这就是快速排序的原理。

时间复杂度时O(nlogn)

当序列接近有序时会达到最坏时间复杂度O(n2).解决的办法时随机选择主元。

也就是在划分时随机选择一个数与第一个数交换。

```c++
//产生随机数
#include<stdlib.h>
#include<time.h>
srand((unsigned)time(NULL));//初始化随机数种子
rand();//产生随机数
rand()%(b-a+1)+a;//产生[a,b]范围的随机数
```



### 其它高级技巧与算法 P184

![image-20210118174223250](C:\Users\luo15\AppData\Roaming\Typora\typora-user-images\image-20210118174223250.png)



## 数学问题



## 树 P286

### 二叉树的遍历

* 先序
* 中序
* 后序
* 层序

前三种遍历方法可用递归和栈来实现。层序遍历利用队列实现。

中序序列+先序/后序/层序 可以还原一颗二叉树。

反转二叉树：左右子树交换。

对应题目：

![image-20201128225722896](https://i.loli.net/2020/11/28/hZg4WYbSOcXQ7kH.png)



### 树



![image-20201204112907931](https://i.loli.net/2020/12/04/4WYSJogrp9beukR.png)

q1053:

```c++
#include<sstream>
std::stringstream ss;
ss<<int,char类型的数据;
ss.str();//转化为字符串

ss.str("");//清空字符串
```



### 二叉查找树（BST）



对应题目：

![image-20201129233947663](https://i.loli.net/2020/11/29/KpuRLaUcj7BJ9A8.png)



q1043:按照BST先序序列的顺序建立的BST，它的先序序列与之前的先序序列相等。

q1064:BST的中序序列为非递减的序列，所以首先将题目中的序列从小到大排序。又因为是完全二叉树，可以根据总结点个数算出左右子树的结点个数，然后递归实现树的建立。

q1099:BST的结构已经知道了，要将数据放到树里面。将数据从小到大排序，最小的放到最右边的结点，然后是前一个结点的父结点，然后左结点。用递归实现。

### 平衡二叉树（AVL树）

AVL树：BST的左子树和右子树的高度差小于等于1.左子树和右子树都是AVL树。



发现结点A：平衡因子绝对值大于等于2.

1. 插入结点在发现结点左子树的左子树，LL

   对A做一次右旋

2. 插入结点在发现结点左子树的左子树，RR

   对A做一次左旋

3. 插入结点在发现结点左子树的右子树上，LR

   先对A->Left做一次左旋，然后对A做一次右旋。

4. 插入结点在发现结点右子树的左子树上，RL

   先对A->Right做一次右旋，然后对A做一次左旋。

   ![image-20201201210049994](https://i.loli.net/2020/12/01/ECqndzmic9Vy5Sf.png)



### 并查集

```c++
对集合 合并、查找
用数组存储
farther[i]表示元素i的父节点
farther[i] == i表示i为根节点，每一集合只有一个根节点。
```

q1107:

```c++
//对set的一些操作
#include<algorithm>
set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.begin()));//求A交B给C
set_union();//并集
set_difference();//差集
set_symmetric_differenct();//对称差集
```



### 堆

堆是一棵完全二叉树。有两种调整方法。

```c++
//1.downAdjust
//适用于已有一棵完全二叉树，要将它调整为堆，从最后一个非叶子结点开始。

//2.upAdjust
//适用于从头开始建一个堆，每插入一个结点就调整一次。

//删除堆顶元素，将最后一个元素覆盖堆顶，然后进行一次downAdjust
//HeapSort，将堆顶和最后一个元素交换，然后downAdjust.
```

对于完全二叉树，n/2为第一个非叶子结点的序号，从1开始。



### 哈夫曼树



## 搜索

### DFS

q1103:

```c++
//开多次根
#include<math.h>
pow(N,1.0/p);
//向上取整
ceil();
```

因为要输出最大的解，可以先从最大的数开始选择，这样得到的第一个解一定是最大的。

### BFS



## 图 p338

图的存储：

* 邻接表
* 邻接矩阵

图的遍历：

* DFS
* BFS

![image-20201207111727679](https://i.loli.net/2020/12/07/P623dUfAS9gymKu.png)

### 最短路径 P364

![image-20201210113531712](https://i.loli.net/2020/12/10/U5MCtHJigDm2PXe.png)

<img src="https://i.loli.net/2020/12/13/xwydTLgpK3HQ42z.png" alt="image-20201213232126079" style="zoom:80%;" />

#### Dijkstra算法

适用于求一个顶点v到其他顶点之间的最短路径，且每条边上的权值都<strong>大于0</strong>.

将所有结点分为两个集合U和V。

U：该集合中所有结点都已经求出最短路径

V：该集合结点尚未求得最短路径

dist数组：存放源点v到到每一结点的路径长度，INF表示无法到达

paths数组：存放最短路径，-1表示无路径

步骤：

1. dist、paths数组初始化
2. 从集合V中挑选一个路径最短的结点u加入U
3. 调整与u相邻的结点的路径，修改对应的dist和paths
4. 重复2-3直到V中没有结点



q1003:

可能有多条最短路径，可以用一个vector存放每个结点的前一个结点，再利用递归可以求得所有最短路径。

q1018:

注意：调整时只能够去的时候调整每个站点自行车数量，回来时不能调整，在计算携带和带回的自行车数量时要注意。要在DFS时动态改变backnum和sendnum。

Dijkstra+DFS

#### Floyd算法

解决全源最短路径问题，可以求解任意两点之间的最短路径。

![image-20201215233246720](https://i.loli.net/2020/12/19/5tZAgj8fMJEcwSk.png)

算法复杂度为O(n^3)



### 最小生成树（MST）



最小生成树：给定一个无向图G（V，E），求一棵树T，使得这棵树有G中所有顶点，且所有边都来自图G，且整棵树边权之和最小。

性质：

1. T的边数等于顶点数减1，没有环
2. 最小生成树可以不唯一，但边权值和一定是唯一的
3. 树的根节点可以是这棵树上任意一个点



#### prim算法

集合S和V，S存放已经访问过的结点，V存放未访问的结点，数组dist存放所有结点到集合S的最短距离。

步骤：

1. 每次从V中选择一个到S距离最短的结点并访问
2. 优化与V相邻的、未被访问的结点到集合S的最短距离
3. 重复1-2直到所有结点都被加入集合S中

伪代码如下：

![image-20201220205532023](https://i.loli.net/2020/12/22/iwM6QkYHjJoRNFv.png)

#### kruskal算法

每次选择最小边权的边，如果边两端的顶点在不同的连通块中，就把这条边加入最小生成树中。

![image-20201220210350700](https://i.loli.net/2020/12/22/nyv3CZMeKk8sS9Q.png)

可以使用<strong>并查集</strong>来判断两个结点是否在同一个连通块中。



## 链表

![image-20201221182918589](https://i.loli.net/2020/12/22/rMbJfYTcNsQ8pLa.png)

q1074（反转链表）:

注意点：

1. 最多有100000个结点，可以以空间换时间，开一个很大的数组。
2. 可以利用map，stack来完成，所需空间少，但要耗费更多时间
3. 输入的结点中可能有的不在待处理链表中，这点要注意。

```c++
#include<iomanip>
//输出指定宽度，高位补零的数字
cout<<setw(5)<<setfill('0');
printf("%05d",a);
```





