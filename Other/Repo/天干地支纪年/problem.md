## 题目描述

最近 zrzring 学长对天干地支纪年法很有兴趣。

首先介绍一下十天干和十二地支。

十天干

![](https://cdn.luogu.com.cn/upload/image_hosting/najxpknc.png)

十二地支

![](https://cdn.luogu.com.cn/upload/image_hosting/edj4ig3d.png)

天干地支纪年法就是用天干和地支搭配使用进行纪年，每60年是一个轮回。这是所有的天干地支纪年的表示

![](https://cdn.luogu.com.cn/upload/image_hosting/68pd5nfl.png)

zrzring 每次想要知道某年用天干地支纪年法怎么表示都需要自己去查表计算，zrzring 学长想请你帮忙写个程序，输入年份之后就可以得出其天干地支纪年的表示方法。但是 zrzring 学长觉得单输出这一个程序有点简单，所以他又要求你增加一个判断闰年的程序。

现在已经知道 2023 年是 癸卯 年也就是对应的 `Jd`。

因为平台评测问题，我们将汉字的对应关系简化为上表对应的大小写字母。

## 输入格式

输入 $year(1 \leq year \leq 3000)$ 代表年份。

## 输出格式

输出有一行，包含两个字符串，第一个字符串是天干地支纪年法的表示，第二个字符串是 `Yes` 和 `No` ，如果是闰年输出 `Yes`，否则输出 `No`。

## 样例 #1

### 样例输入 #1

```
2023
```

### 样例输出 #1

```
Jd No
```

## 提示

出题人：Hunter