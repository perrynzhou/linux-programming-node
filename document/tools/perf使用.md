

## perf的使用

### 查看占用CPU的情况

```
// 列举出当前可以采集的指标集合
perf list

//采集进程112547 CPU 时间消耗分析
perf record -e cpu-clock -g -p 112547

//分析采集到的数据
perf report -i perf.data
```