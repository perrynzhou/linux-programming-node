
## lua语言介绍

### lua是交互式的脚本语言

- 基本入门函数

```
-- this first fucntion  //这里相当于是结构
function fact (n) //哈数定义
    if n==0 then //if语句开发，else语句结束结束使用end
        return 1
    else 
        return n*fact(n-1)
    end
end //表示函数的结束

print(fact(2)) //这里相当于main方法
```

- lua中全局变量无须申明极客使用，使用未经初始化的区安监局吧变量也不会导致错误，因为未经初始化的全局变量的默认值都是nil


