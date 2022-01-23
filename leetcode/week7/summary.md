# 贪婪算法
这周除刷LeetCode以外，主要学习了导论中贪婪算法的有关知识


* 贪婪算法是指，在对问题求解时，总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，他所做出的仅是在某种意义上的局部最优解。贪心算法不是对所有问题都能得到整体最优解，但对范围相当广泛的许多问题他能产生整体最优解或者是整体最优解的近似解。


## 基本思路
⒈ 建立数学模型来描述问题。

⒉ 把求解的问题分成若干个子问题。

⒊ 对每一子问题求解，得到子问题的局部最优解。

⒋ 把子问题的解局部最优解合成原来解问题的一个解。
## 存在的问题
 1. 不能保证求得的最后解是最佳的；

 2. 不能用来求最大或最小解问题；

 3. 只能求满足某些约束条件的可行解的范围。

## 最优子结构性质
当一个问题的最优解包含其子问题的最优解时，称此问题具有最优子结构性质。问题的最优子结构性质是该问题可用贪婪算法求解的关键特征
### 一般流程
```
Greedy(C)  //C是问题的输入集合即候选集合
{
    S={ };  //初始解集合为空集
    while (not solution(S))  //集合S没有构成问题的一个解
    {
       x=select(C);    //在候选集合C中做贪心选择
       if feasible(S, x)  //判断集合S中加入x后的解是否可行
          S=S+{x};
          C=C-{x};
    }
   return S;
```

贪心算法所作的选择可以依赖于以往所作过的选择，但决不依赖于将来的选择，也不依赖于子问题的解，因此贪心算法与其他算法相比具有一定的速度优势。如果一个问题可以同时用几种方法解决，贪心算法应该是最好的选择之一。
