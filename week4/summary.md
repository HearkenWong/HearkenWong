# 散列
## 定义
* 散列表（Hash table，也叫哈希表），是根据键（Key）而直接访问在内存存储位置的数据结构。也就是说，它通过计算一个关于键值的函数，将所需查询的数据映射到表中一个位置来访问记录，这加快了查找速度。这个映射函数称做散列函数，存放记录的数组称做散列表。
* 散列函数能使对一个数据序列的访问过程更加迅速有效，通过散列函数，数据元素将被更快定位。
## 散列函数
### 直接定址法
    h(K) = K + C
  * 这种方法关键字分配不连续，存储空间严重浪费

### 除留余数法

   * 除留余数法是用关键字K除以散列表长度m所得余数作为散列地址的方法。对应的散列函数h(K)为：

    h(K) = K % m
   这种方法计算简单，适用范围广

### 数字分析法

  * 数字分析法是取关键字中某些取值较分散的数字位做为散列地址的方法。

### 平方取中法

  * 平方取中法是取关键字平方的中间几位作为散列地址的方法，具体取多少位视实际要求而定。

### 折叠法

  * 折叠法是首先将关键字部分分割成位数相同的几段（最后一段的位数若不足应补0），段的位数取决于散列地址的位数，由实际需要而定，然后将他们的叠加和（舍去最高位进位）作为散列地址的方法。

