## gdb调试技巧

- 格式化打印结构体
```
(gdb) set print pretty on
```

- gdb带参数调试

```
//方式1
gdb --args /usr/local/sbin/glusterfs --process-name fuse --volfile-server=10.211.55.9 --volfile-id=rep_vol --subdir-mount=/public/2020 /mnt/public/2020

//方式2
gdb /usr/local/sbin/glusterfs
set args  --process-name fuse --volfile-server=10.211.55.9 --volfile-id=rep_vol --subdir-mount=/public/2020 /mnt/public/2020

```
- 打印宏定义的
```
//展开宏定义 如： macro  expand min(a, b)
(gdb) macro expand  {macroname} 
 // 列出所有用macro define 
(gdb) macro  list  {macroname}  
//撤销macroname宏定义       
(gdb) macro undef {macroname}   
//显示宏定义     
(gdb) info macro {macroname}  
```