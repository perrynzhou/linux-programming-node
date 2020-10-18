## gcc8源码安装


- 安装依赖包
```
yum install -y gcc gcc-c++ gcc-gnat libgcc libgcc.i686 glibc-devel bison flex texinfo build-essential zlib-devel
```
- 下载gcc源码
```
wget https://github.com/gcc-mirror/gcc/archive/releases/gcc-8.4.0.tar.gz
tar zxvf gcc-8.4.0.tar.gz && cd gcc-releases-gcc-8.4.0 && ./contrib/download_prerequisites
```

- 编译安装
```
mkdir build && cd build
../configure --prefix=/usr/local/gcc-8.4.0 --enable-checking=release --enable-languages=c,c++ --disable-multilib
make && make install
```