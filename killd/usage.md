
- 使用方法

```
然后执行make命令进行编译；

make

插入模块的时候提供D状态的进程号，就可以将其转换为t状态，使用普通kill就可以杀死。

insmod ./killd.ko pid=1234,11134

卸载模块：

rmmod killd

```